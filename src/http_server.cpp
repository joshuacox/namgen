#include "http_server.h"
#include "generator_registry.h"
#include "markov.h"
#include "linguistics.h"
#include "lore.h"

#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <string>
#include <random>
#include <regex>
#include <cstring>
#include <csignal>

#if !defined(_WIN32) && !defined(__EMSCRIPTEN__)
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <poll.h>

namespace namgen {

static volatile sig_atomic_t g_running = 1;

static void handleSignal(int) {
    g_running = 0;
}

static std::string escapeJson(const std::string& s) {
    std::string out;
    out.reserve(s.size() + 8);
    for (char c : s) {
        if (c == '"') out += "\\\"";
        else if (c == '\\') out += "\\\\";
        else if (c == '\b') out += "\\b";
        else if (c == '\f') out += "\\f";
        else if (c == '\n') out += "\\n";
        else if (c == '\r') out += "\\r";
        else if (c == '\t') out += "\\t";
        else out += c;
    }
    return out;
}

static std::string urlDecode(const std::string& in) {
    std::string out;
    out.reserve(in.size());
    for (size_t i = 0; i < in.size(); ++i) {
        if (in[i] == '%' && i + 2 < in.size()) {
            int value = 0;
            std::istringstream is(in.substr(i + 1, 2));
            if (is >> std::hex >> value) {
                out += static_cast<char>(value);
                i += 2;
            } else {
                out += in[i];
            }
        } else if (in[i] == '+') {
            out += ' ';
        } else {
            out += in[i];
        }
    }
    return out;
}

static std::unordered_map<std::string, std::string> parseQuery(const std::string& queryStr) {
    std::unordered_map<std::string, std::string> params;
    std::stringstream ss(queryStr);
    std::string pair;
    while (std::getline(ss, pair, '&')) {
        size_t eq = pair.find('=');
        if (eq != std::string::npos) {
            std::string key = urlDecode(pair.substr(0, eq));
            std::string val = urlDecode(pair.substr(eq + 1));
            params[key] = val;
        } else if (!pair.empty()) {
            params[urlDecode(pair)] = "";
        }
    }
    return params;
}

static void sendHttpResponse(int clientFd, int statusCode, const std::string& statusText,
                             const std::string& contentType, const std::string& body) {
    std::ostringstream oss;
    oss << "HTTP/1.1 " << statusCode << " " << statusText << "\r\n"
        << "Content-Type: " << contentType << "\r\n"
        << "Content-Length: " << body.size() << "\r\n"
        << "Access-Control-Allow-Origin: *\r\n"
        << "Access-Control-Allow-Methods: GET, OPTIONS\r\n"
        << "Access-Control-Allow-Headers: Content-Type\r\n"
        << "Connection: close\r\n\r\n"
        << body;
    std::string response = oss.str();
    write(clientFd, response.data(), response.size());
}

int runHttpServer(const std::string& bindAddress, int port) {
    signal(SIGINT, handleSignal);
    signal(SIGTERM, handleSignal);

    int serverFd = socket(AF_INET, SOCK_STREAM, 0);
    if (serverFd < 0) {
        std::cerr << "Error: failed to create socket\n";
        return 1;
    }

    int opt = 1;
    setsockopt(serverFd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(static_cast<uint16_t>(port));
    if (bindAddress.empty() || bindAddress == "0.0.0.0") {
        addr.sin_addr.s_addr = INADDR_ANY;
    } else {
        inet_pton(AF_INET, bindAddress.c_str(), &addr.sin_addr);
    }

    if (bind(serverFd, reinterpret_cast<sockaddr*>(&addr), sizeof(addr)) < 0) {
        std::cerr << "Error: failed to bind socket to " << bindAddress << ":" << port << "\n";
        close(serverFd);
        return 1;
    }

    if (listen(serverFd, 64) < 0) {
        std::cerr << "Error: failed to listen on socket\n";
        close(serverFd);
        return 1;
    }

    std::cout << "⚡ namgen HTTP daemon running at http://"
              << (bindAddress.empty() ? "127.0.0.1" : bindAddress) << ":" << port << "\n"
              << "   - Health Check : GET /healthz\n"
              << "   - List Gens    : GET /api/generators\n"
              << "   - Generate     : GET /api/generate?gen=<name>&count=<n>&seed=<s>\n"
              << "   - Markov       : GET /api/markov?gen=<name>&count=<n>\n"
              << "   Press Ctrl+C to stop.\n\n";

    std::mt19937 serverRng(std::random_device{}());

    while (g_running) {
        pollfd pfd{serverFd, POLLIN, 0};
        int pr = poll(&pfd, 1, 1000);
        if (pr <= 0) continue;

        sockaddr_in clientAddr{};
        socklen_t clientLen = sizeof(clientAddr);
        int clientFd = accept(serverFd, reinterpret_cast<sockaddr*>(&clientAddr), &clientLen);
        if (clientFd < 0) continue;

        char buffer[4096];
        ssize_t bytesRead = read(clientFd, buffer, sizeof(buffer) - 1);
        if (bytesRead <= 0) {
            close(clientFd);
            continue;
        }
        buffer[bytesRead] = '\0';

        std::string req(buffer);
        size_t firstLineEnd = req.find("\r\n");
        if (firstLineEnd == std::string::npos) {
            close(clientFd);
            continue;
        }

        std::string reqLine = req.substr(0, firstLineEnd);
        std::istringstream iss(reqLine);
        std::string method, fullPath, httpVer;
        iss >> method >> fullPath >> httpVer;

        if (method == "OPTIONS") {
            sendHttpResponse(clientFd, 204, "No Content", "text/plain", "");
            close(clientFd);
            continue;
        }

        if (method != "GET") {
            sendHttpResponse(clientFd, 405, "Method Not Allowed", "application/json", "{\"error\":\"Method not allowed\"}");
            close(clientFd);
            continue;
        }

        std::string path = fullPath;
        std::string queryStr;
        size_t qmark = fullPath.find('?');
        if (qmark != std::string::npos) {
            path = fullPath.substr(0, qmark);
            queryStr = fullPath.substr(qmark + 1);
        }

        auto params = parseQuery(queryStr);

        if (path == "/healthz") {
            sendHttpResponse(clientFd, 200, "OK", "application/json", "{\"status\":\"ok\",\"service\":\"namgen\"}\n");
        } else if (path == "/api/generators") {
            std::ostringstream json;
            json << "[\n";
            const auto& all = GeneratorRegistry::instance().getAll();
            for (size_t i = 0; i < all.size(); ++i) {
                json << "  {\"flag\":\"" << escapeJson(all[i]->flag) << "\",\"description\":\""
                     << escapeJson(all[i]->description) << "\"}"
                     << (i + 1 < all.size() ? "," : "") << "\n";
            }
            json << "]\n";
            sendHttpResponse(clientFd, 200, "OK", "application/json", json.str());
        } else if (path == "/api/generate") {
            std::string genName = params.count("gen") ? params["gen"] : "fantasy-elfs";
            size_t count = 1;
            if (params.count("count")) {
                try { count = std::stoul(params["count"]); } catch (...) {}
            }
            count = std::max(size_t{1}, std::min(count, size_t{1000}));

            std::mt19937 rng = serverRng;
            if (params.count("seed")) {
                try { rng.seed(static_cast<uint32_t>(std::stoul(params["seed"]))); } catch (...) {}
            }

            const GeneratorInfo* g = GeneratorRegistry::instance().find(genName);
            if (!g && genName.rfind("--", 0) != 0) {
                g = GeneratorRegistry::instance().find("--" + genName);
            }

            if (!g) {
                sendHttpResponse(clientFd, 404, "Not Found", "application/json", "{\"error\":\"Generator not found\"}\n");
                close(clientFd);
                continue;
            }

            bool withLore = (params.count("with_lore") && (params["with_lore"] == "true" || params["with_lore"] == "1"));
            bool alliterate = (params.count("alliterate") && (params["alliterate"] == "true" || params["alliterate"] == "1"));

            std::ostringstream json;
            json << "{\n  \"generator\":\"" << escapeJson(g->flag) << "\",\n  \"count\":" << count << ",\n  \"names\":[\n";
            std::vector<std::string> names;
            size_t attempts = 0;
            while (names.size() < count && attempts < count * 200 + 500) {
                ++attempts;
                std::string n = g->generate(rng);
                if (alliterate && !Linguistics::isAlliterative(n)) continue;
                if (withLore) n = Lore::formatWithLore(n, rng);
                names.push_back(n);
            }

            for (size_t i = 0; i < names.size(); ++i) {
                json << "    \"" << escapeJson(names[i]) << "\"" << (i + 1 < names.size() ? "," : "") << "\n";
            }
            json << "  ]\n}\n";
            sendHttpResponse(clientFd, 200, "OK", "application/json", json.str());
        } else if (path == "/api/markov") {
            std::string genName = params.count("gen") ? params["gen"] : "fantasy-elfs";
            size_t count = 1;
            if (params.count("count")) {
                try { count = std::stoul(params["count"]); } catch (...) {}
            }
            count = std::max(size_t{1}, std::min(count, size_t{1000}));
            int order = 3;
            if (params.count("order")) {
                try { order = std::stoi(params["order"]); } catch (...) {}
            }

            std::mt19937 rng = serverRng;
            if (params.count("seed")) {
                try { rng.seed(static_cast<uint32_t>(std::stoul(params["seed"]))); } catch (...) {}
            }

            const GeneratorInfo* g = GeneratorRegistry::instance().find(genName);
            if (!g && genName.rfind("--", 0) != 0) {
                g = GeneratorRegistry::instance().find("--" + genName);
            }
            if (!g) {
                g = GeneratorRegistry::instance().find("fantasy-elfs");
            }

            MarkovModel model(order);
            std::vector<std::string> samples;
            for (int s = 0; s < 100; ++s) {
                samples.push_back(g->generate(rng));
            }
            model.train(samples);

            std::ostringstream json;
            json << "{\n  \"model\":\"markov\",\n  \"generator\":\"" << escapeJson(g->flag)
                 << "\",\n  \"order\":" << order << ",\n  \"names\":[\n";
            for (size_t i = 0; i < count; ++i) {
                std::string n = model.generate(rng);
                json << "    \"" << escapeJson(n) << "\"" << (i + 1 < count ? "," : "") << "\n";
            }
            json << "  ]\n}\n";
            sendHttpResponse(clientFd, 200, "OK", "application/json", json.str());
        } else {
            sendHttpResponse(clientFd, 404, "Not Found", "application/json", "{\"error\":\"Route not found\"}\n");
        }

        close(clientFd);
    }

    close(serverFd);
    std::cout << "\n[namgen] HTTP daemon stopped cleanly.\n";
    return 0;
}

} // namespace namgen

#else

namespace namgen {
int runHttpServer(const std::string&, int) {
    std::cerr << "HTTP daemon is not supported on this platform.\n";
    return 1;
}
}

#endif
