#pragma once

#include <string>

namespace pulsar {

struct ICryptographyScheme {
    virtual ~ICryptographyScheme() = default;

    virtual std::string GetPublicKeyPEM() = 0;
    virtual char *Sign(char *buff) = 0;
};

class CryptographyScheme: public ICryptographyScheme {
public:
    CryptographyScheme();

    void LoadFromJsonFile(const std::string& keysPath);
    void LoadFromJsonString(const std::string& json);

    std::string GetPublicKeyPEM() override;
    char *Sign(char *buff) override;

private:
    std::unique_ptr<ICryptographyScheme> m_cs;
};

} // namespace pulsar
