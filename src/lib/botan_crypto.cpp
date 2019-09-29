#include "cryptography.h"

#include <botan/ecdsa.h>

#include <botan/pkcs8.h>
#include <botan/auto_rng.h>
#include <botan/data_src.h>
#include <nlohmann/json.hpp>

#include <boost/filesystem.hpp>

#include <iostream>

using json = nlohmann::json;

namespace {
std::unique_ptr<Private_Key> ImportPrivateKey(const std::string &privateKey) {
    DataSource_Memory keyData(privateKey);
    return PKCS8::load_key(keyData);
}

Public_Key *ImportPublicKey(const std::string &publicKey) {
    DataSource_Memory keyData(publicKey);
    return X509::load_key(keyData);
}
} // namespace

namespace pulsar {

CryptographySchemeImpl::CryptographySchemeImpl(std::string keyspath) {
    using namespace boost::filesystem;
    std::string insolarSources = "/Users/bronin/go/src/github.com/insolar/insolar/"; // should be absolute path

    if ( !boost::filesystem::exists( keyspath ) )
    {
        keyspath = insolarSources + keyspath;
    }

    std::cout << "Loading keys: " << keyspath << std::endl;

    std::string keysStr;
    load_string_file(keyspath, keysStr);
    json keys = json::parse(keysStr);

    auto priv = ImportPrivateKey(keys.at("private_key"));
    m_privateKey = std::move(priv);

    auto pk = ImportPublicKey(keys.at("public_key"));
    m_publicKey = std::shared_ptr<Public_Key>(pk);
}

char* CryptographySchemeImpl::Sign(char *buff) {
    // implement me
    return nullptr;
}

std::string CryptographySchemeImpl::GetPublicKeyPEM() {
    return std::string();
}

} // namespace pulsar

//void generate() {
//    AutoSeeded_RNG rng;
//    EC_Group dom_pars("secp160r1");
//    ECDSA_PrivateKey key(rng, dom_pars);
//
//    // 1. save key to PEM, attempt to load it with load_key()
//    auto pem = Botan::PKCS8::PEM_encode( key );
//    DataSource_Memory keyData2( pem );
//    auto keyReloaded2 = Botan::PKCS8::load_key( keyData2, rng );
//
//    // 2. save key to BER, attempt to load it with load_key()
//    auto ber = Botan::PKCS8::BER_encode( key );
//    DataSource_Memory keyData( ber );
//    auto keyReloaded = Botan::PKCS8::load_key( keyData, rng );
//}
