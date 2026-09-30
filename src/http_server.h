#ifndef NAMGEN_HTTP_SERVER_H
#define NAMGEN_HTTP_SERVER_H

#include <string>

namespace namgen {

int runHttpServer(const std::string& bindAddress, int port);

} // namespace namgen

#endif // NAMGEN_HTTP_SERVER_H
