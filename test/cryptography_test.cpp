#include <gtest/gtest.h>

#include <botan/ecdsa.h>
#include <botan/pkcs8.h>
#include <botan/x509_key.h>

#include <botan/auto_rng.h>
#include <botan/data_src.h>
#include <pulse.pb.h>
//#include <cryptopp/sha3.h>

using namespace Botan;


const char *keyString = R"(
-----BEGIN PRIVATE KEY-----
MIGHAgEAMBMGByqGSM49AgEGCCqGSM49AwEHBG0wawIBAQQgIim8RlCCD+mLqxBt
2cXgycQlFiD7sFCz9Qf962kL1w+hRANCAATYYOwbW09dA4jaJ8Z/c7TOehxLzvf8
VYdd+R+be8Yvy1AW8lhidLQxY6YM5aXE1jiJKqJKnUhrNNkDJRMvdDhG
-----END PRIVATE KEY-----
)";

TEST(cryptography, wrong_letter_highlighted)
{
//    AutoSeeded_RNG rng;
//    EC_Group dom_pars("secp160r1");
//    ECDSA_PrivateKey key(rng, dom_pars);
//
//    // 1. save key to PEM, attempt to load it with load_key()
//    auto pem = PKCS8::PEM_encode( key );
//    DataSource_Memory keyData2( pem );
//    auto keyReloaded2 = PKCS8::load_key( keyData2, rng );
//
//    // 2. save key to BER, attempt to load it with load_key()
//    auto ber = PKCS8::BER_encode( key );
//    DataSource_Memory keyData( ber );
//    auto keyReloaded = PKCS8::load_key( keyData, rng );

    DataSource_Memory keyData( keyString );
    auto key = PKCS8::load_key(keyData);
    std::cout << key->algo_name()  << std::endl;
}


TEST(cryptography, proto) {
    pulse::PulseProto p;
    p.set_pulsenumber(1);

    p.set_entropy("lalala");
    //p.add_signs()

    ASSERT_TRUE(p.IsInitialized());
    std::cout << p.DebugString() << std::endl;
}
