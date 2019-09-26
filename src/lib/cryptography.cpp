#include <botan/ecdsa.h>
#include <cryptopp/sha3.h>

#include <botan/pkcs8.h>
#include <botan/auto_rng.h>
#include <botan/data_src.h>
#include <botan-2/botan/x509_key.h>
#include <pulsar/cryptography.h>


using namespace Botan;

namespace pulsar {
    CryptographyScheme::CryptographyScheme(std::string jsonKeys) {

    }

    char* CryptographyScheme::Sign(char *buff) {
        // implement me
        return nullptr;
    }

} // namespace pulsar

std::unique_ptr<Private_Key> ImportPrivateKey(const std::string& privateKey) {
    DataSource_Memory keyData(privateKey);
    return PKCS8::load_key(keyData);
}

Public_Key* ImportPublicKey(const std::string& publicKey) {
    DataSource_Memory keyData(publicKey);
    return X509::load_key(keyData);
}

void generate() {
    AutoSeeded_RNG rng;
    EC_Group dom_pars("secp160r1");
    ECDSA_PrivateKey key(rng, dom_pars);

    // 1. save key to PEM, attempt to load it with load_key()
    auto pem = Botan::PKCS8::PEM_encode( key );
    DataSource_Memory keyData2( pem );
    auto keyReloaded2 = Botan::PKCS8::load_key( keyData2, rng );

    // 2. save key to BER, attempt to load it with load_key()
    auto ber = Botan::PKCS8::BER_encode( key );
    DataSource_Memory keyData( ber );
    auto keyReloaded = Botan::PKCS8::load_key( keyData, rng );
}

