#include "crypto_impl.h"

#include <pulsar/cryptography.h>
#include <boost/filesystem.hpp>
#include <iostream>

namespace pulsar {

CryptographyScheme::CryptographyScheme() : m_cs(std::make_unique<CryptographySchemeImpl>()) {
}

void CryptographyScheme::LoadFromJsonFile(const std::string &keysPath) {
    using namespace boost::filesystem;
    std::string insolarSources = "/Users/bronin/go/src/github.com/insolar/insolar/"; // should be absolute path

    auto path = keysPath;
    if ( !boost::filesystem::exists(keysPath) )
    {
        path = insolarSources + keysPath;
    }

    std::cout << "Loading keys: " << path << std::endl;

    std::string keysStr;
    load_string_file(path, keysStr);
    LoadFromJsonString(keysStr);
}

void CryptographyScheme::LoadFromJsonString(const std::string &json) {

}

std::string CryptographyScheme::GetPublicKeyPEM() {
    return m_cs->GetPublicKeyPEM();
}

char* CryptographyScheme::Sign(char *buff) {
    return m_cs->Sign(buff);
}

} // namespace pulsar
