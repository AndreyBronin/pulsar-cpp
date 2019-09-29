#include <pulsar/cryptography.h>

#include <gtest/gtest.h>

#include <botan/ecdsa.h>
#include <botan/pkcs8.h>
#include <botan/x509_key.h>

#include <botan/auto_rng.h>
#include <botan/data_src.h>
#include <pulse.pb.h>

#include "../src/lib/crypto_impl.h"

using namespace Botan;

auto keys = R"(
{
    "private_key": "-----BEGIN PRIVATE KEY-----\nMIGHAgEAMBMGByqGSM49AgEGCCqGSM49AwEHBG0wawIBAQQgwYAFzRM5vgMr53wc\n9DzVFys6dNj3Z56J7XzLC62jK+ehRANCAASw4x080JGlYAfG+qLEHt8D2IMqPICm\nS1zuExXwEuJOv0kPY72kiqgwymJClryLC4pEw07rGKY9vPgKyEKX6dMj\n-----END PRIVATE KEY-----\n",
    "public_key": "-----BEGIN PUBLIC KEY-----\nMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEsOMdPNCRpWAHxvqixB7fA9iDKjyA\npktc7hMV8BLiTr9JD2O9pIqoMMpiQpa8iwuKRMNO6ximPbz4CshCl+nTIw==\n-----END PUBLIC KEY-----\n"
}
)";

const std::string pkPem =R"(-----BEGIN PUBLIC KEY-----
MFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEsOMdPNCRpWAHxvqixB7fA9iDKjyA
pktc7hMV8BLiTr9JD2O9pIqoMMpiQpa8iwuKRMNO6ximPbz4CshCl+nTIw==
-----END PUBLIC KEY-----
)";

const char *privatePem = R"(
-----BEGIN PRIVATE KEY-----
MIGHAgEAMBMGByqGSM49AgEGCCqGSM49AwEHBG0wawIBAQQgIim8RlCCD+mLqxBt
2cXgycQlFiD7sFCz9Qf962kL1w+hRANCAATYYOwbW09dA4jaJ8Z/c7TOehxLzvf8
VYdd+R+be8Yvy1AW8lhidLQxY6YM5aXE1jiJKqJKnUhrNNkDJRMvdDhG
-----END PRIVATE KEY-----
)";

TEST(cryptography, GetPublicKeyPEM) {
    pulsar::CryptographySchemeImpl cs;
    cs.LoadFromJsonString(keys);

    EXPECT_EQ(pkPem, cs.GetPublicKeyPEM());
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

//    DataSource_Memory keyData( privatePem );
//    auto key = PKCS8::load_key(keyData);
//    std::cout << key->algo_name()  << std::endl;
}


TEST(cryptography, proto) {
    pulse::PulseProto p;
    p.set_pulsenumber(1);

    p.set_entropy("lalala");
    //p.add_signs()

    ASSERT_TRUE(p.IsInitialized());
    std::cout << p.DebugString() << std::endl;
}
