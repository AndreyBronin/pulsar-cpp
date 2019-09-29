#include "cryptography.h"

namespace pulsar {

CryptographyScheme::CryptographyScheme(std::string keysPath)
    : m_cs(std::make_unique<CryptographySchemeImpl>(keysPath)) {
}

std::string CryptographyScheme::GetPublicKeyPEM() {
    return m_cs->GetPublicKeyPEM();
}

char* CryptographyScheme::Sign(char *buff) {
    return m_cs->Sign(buff);
}

} // namespace pulsar
