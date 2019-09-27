#pragma once

#include <string>

namespace pulsar {

class CryptographyScheme {
public:
    explicit CryptographyScheme(std::string keyspath);

    char *Sign(char *buff); // use span
};

} // namespace pulsar
