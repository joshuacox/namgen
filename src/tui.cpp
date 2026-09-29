#include "tui.h"
#include "generator_registry.h"

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

#ifdef __EMSCRIPTEN__

namespace namgen {
int runInteractiveTui(std::mt19937&) {
    std::cerr << "Error: Interactive TUI mode is not supported in WebAssembly.\n";
    return 1;
}
}

#elif defined(_WIN32) || defined(_WIN64)

namespace namgen {
int runInteractiveTui(std::mt19937&) {
    std::cerr << "Error: Interactive TUI mode is currently only supported on POSIX systems.\n";
    return 1;
}
}

#else

#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>

namespace {

struct TerminalRawMode {
    struct termios orig_termios;
    bool active = false;

    TerminalRawMode() {
        if (!isatty(STDIN_FILENO)) return;
        if (tcgetattr(STDIN_FILENO, &orig_termios) == -1) return;
        struct termios raw = orig_termios;
        raw.c_lflag &= ~(ECHO | ICANON | IEXTEN);
        raw.c_iflag &= ~(IXON | ICRNL);
        raw.c_cc[VMIN] = 1;
        raw.c_cc[VTIME] = 0;
        if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) != -1) {
            active = true;
            // Switch to alternate screen and hide cursor
            std::cout << "\033[?1049h\033[?25l" << std::flush;
        }
    }

    ~TerminalRawMode() {
        if (active) {
            // Restore cursor and main screen
            std::cout << "\033[?25h\033[?1049l" << std::flush;
            tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
        }
    }
};

std::string toLower(std::string_view s) {
    std::string out;
    out.reserve(s.size());
    for (char c : s) out.push_back(static_cast<char>(std::tolower(static_cast<unsigned char>(c))));
    return out;
}

std::string getCategory(std::string_view flag) {
    auto dash = flag.find('-');
    if (dash != std::string_view::npos) {
        return std::string(flag.substr(0, dash));
    }
    return "general";
}

void getTermSize(int& rows, int& cols) {
    struct winsize ws;
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == 0 && ws.ws_col > 0) {
        cols = ws.ws_col;
        rows = ws.ws_row;
    } else {
        cols = 80;
        rows = 24;
    }
}

} // namespace

namespace namgen {

int runInteractiveTui(std::mt19937& rng) {
    if (!isatty(STDIN_FILENO)) {
        std::cerr << "Error: Interactive mode requires an interactive TTY.\n";
        return 1;
    }

    TerminalRawMode rawMode;
    if (!rawMode.active) {
        std::cerr << "Error: Failed to initialize raw terminal mode.\n";
        return 1;
    }

    const auto& allGenerators = GeneratorRegistry::instance().getAll();
    std::string searchQuery;
    std::size_t selectedIdx = 0;
    std::size_t scrollOffset = 0;
    std::vector<std::string> currentSamples;
    const GeneratorInfo* lastSampleGen = nullptr;

    auto refreshSamples = [&](const GeneratorInfo* gen) {
        currentSamples.clear();
        if (gen) {
            for (int i = 0; i < 8; ++i) {
                currentSamples.push_back(gen->generate(rng));
            }
        }
        lastSampleGen = gen;
    };

    while (true) {
        int rows = 24;
        int cols = 80;
        getTermSize(rows, cols);

        // Filter generators
        std::string queryLower = toLower(searchQuery);
        std::vector<const GeneratorInfo*> matches;
        matches.reserve(allGenerators.size());
        for (const auto& gen : allGenerators) {
            if (queryLower.empty()) {
                matches.push_back(gen.get());
            } else {
                std::string flagLower = toLower(gen->flag);
                std::string descLower = toLower(gen->description);
                std::string catLower  = toLower(getCategory(gen->flag));
                if (flagLower.find(queryLower) != std::string::npos ||
                    descLower.find(queryLower) != std::string::npos ||
                    catLower.find(queryLower) != std::string::npos) {
                    matches.push_back(gen.get());
                }
            }
        }

        if (matches.empty()) {
            selectedIdx = 0;
            scrollOffset = 0;
        } else if (selectedIdx >= matches.size()) {
            selectedIdx = matches.size() - 1;
        }

        const GeneratorInfo* currentGen = matches.empty() ? nullptr : matches[selectedIdx];
        if (currentGen != lastSampleGen) {
            refreshSamples(currentGen);
        }

        // Adjust scroll offset
        const int listHeight = std::max(5, rows - 7);
        if (selectedIdx < scrollOffset) {
            scrollOffset = selectedIdx;
        } else if (selectedIdx >= scrollOffset + listHeight) {
            scrollOffset = selectedIdx - listHeight + 1;
        }

        // Render buffer
        std::string buf;
        buf += "\033[H\033[2J"; // Home and clear screen

        // Header
        buf += "\033[1;32mnamgen Interactive Explorer\033[0m — 907 Procedural Generators\n";
        buf += "\033[90mFilter: \033[0;1;37m" + (searchQuery.empty() ? "<type to filter>" : searchQuery) +
               "\033[0m \033[90m(" + std::to_string(matches.size()) + "/" +
               std::to_string(allGenerators.size()) + " matches)\033[0m\n";
        buf += "\033[90m" + std::string(cols > 1 ? cols - 1 : 40, '-') + "\033[0m\n";

        // Main body: Split left list & right preview
        int leftWidth = std::min(40, cols / 2);
        if (leftWidth < 25) leftWidth = 25;
        int rightWidth = cols - leftWidth - 3;
        if (rightWidth < 20) rightWidth = 20;

        for (int row = 0; row < listHeight; ++row) {
            std::size_t itemIdx = scrollOffset + row;
            std::string line;

            // Left column: list item
            if (itemIdx < matches.size()) {
                const auto* gen = matches[itemIdx];
                std::string flagStr = gen->flag;
                if (flagStr.length() > static_cast<size_t>(leftWidth - 4)) {
                    flagStr = flagStr.substr(0, leftWidth - 7) + "...";
                }
                while (flagStr.length() < static_cast<size_t>(leftWidth - 3)) {
                    flagStr.push_back(' ');
                }

                if (itemIdx == selectedIdx) {
                    line += "\033[1;30;42m > " + flagStr + "\033[0m";
                } else {
                    line += "   " + flagStr;
                }
            } else {
                line.append(leftWidth, ' ');
            }

            line += " \033[90m|\033[0m ";

            // Right column: preview and details
            if (row == 0 && currentGen) {
                line += "\033[1;36mCategory:\033[0m " + getCategory(currentGen->flag);
            } else if (row == 1 && currentGen) {
                std::string desc = currentGen->description;
                if (desc.length() > static_cast<size_t>(rightWidth - 2)) {
                    desc = desc.substr(0, rightWidth - 5) + "...";
                }
                line += "\033[90m" + desc + "\033[0m";
            } else if (row == 2) {
                line += "\033[1;33mLive Rolls [Press Space to reroll]:\033[0m";
            } else if (row >= 3 && row - 3 < static_cast<int>(currentSamples.size())) {
                line += "  \033[1;37m• " + currentSamples[row - 3] + "\033[0m";
            }

            buf += line + "\n";
        }

        // Footer
        buf += "\033[90m" + std::string(cols > 1 ? cols - 1 : 40, '-') + "\033[0m\n";
        buf += "\033[90m[↑/↓/PgUp/PgDn] Navigate  [Space] Roll  [Enter] Select  [Backspace] Edit  [q/Esc] Quit\033[0m\n";

        std::cout << buf << std::flush;

        // Read key input
        char c;
        if (read(STDIN_FILENO, &c, 1) != 1) break;

        if (c == '\033') { // Escape sequence
            char seq[3];
            if (read(STDIN_FILENO, &seq[0], 1) != 1) break; // Bare ESC quits
            if (read(STDIN_FILENO, &seq[1], 1) != 1) break;

            if (seq[0] == '[') {
                if (seq[1] == 'A') { // Up
                    if (selectedIdx > 0) --selectedIdx;
                } else if (seq[1] == 'B') { // Down
                    if (!matches.empty() && selectedIdx + 1 < matches.size()) ++selectedIdx;
                } else if (seq[1] == '5') { // Page Up
                    read(STDIN_FILENO, &seq[2], 1); // consume ~
                    if (selectedIdx > static_cast<size_t>(listHeight)) selectedIdx -= listHeight;
                    else selectedIdx = 0;
                } else if (seq[1] == '6') { // Page Down
                    read(STDIN_FILENO, &seq[2], 1); // consume ~
                    if (!matches.empty()) {
                        selectedIdx = std::min(matches.size() - 1, selectedIdx + listHeight);
                    }
                }
            }
        } else if (c == 127 || c == '\b') { // Backspace
            if (!searchQuery.empty()) {
                searchQuery.pop_back();
                selectedIdx = 0;
                scrollOffset = 0;
            }
        } else if (c == '\n' || c == '\r') { // Enter: select and exit
            if (currentGen) {
                // Drop out of raw mode
                return 0; // The RAII destructor restores terminal
            }
        } else if (c == ' ') { // Space: re-roll
            refreshSamples(currentGen);
        } else if (c == 'q' || c == 3) { // 'q' or Ctrl+C
            return 0;
        } else if (std::isprint(static_cast<unsigned char>(c))) {
            searchQuery.push_back(c);
            selectedIdx = 0;
            scrollOffset = 0;
        }
    }

    return 0;
}

} // namespace namgen

#endif
