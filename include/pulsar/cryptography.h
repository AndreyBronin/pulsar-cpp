#pragma once

namespace pulsar {

class CryptographyScheme {
public:
    explicit CryptographyScheme(std::string jsonKeys);

    char *Sign(char *buff); // use span
};


} // namespace pulsar
