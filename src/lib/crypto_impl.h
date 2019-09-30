#pragma once

#include <pulsar/cryptography.h>
#include <botan/x509_key.h>

using namespace Botan;

namespace pulsar {

class CryptographySchemeImpl : public ICryptographyScheme {
public:
    CryptographySchemeImpl() = default;

    void LoadFromJsonString(const std::string& jsonStr);

    std::string GetPublicKeyPEM() override;
    char *Sign(char *buff) override;

private:
    std::unique_ptr <Private_Key> m_privateKey;
    std::shared_ptr <Public_Key> m_publicKey;
};

} // namespace pulsar