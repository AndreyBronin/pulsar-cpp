#include <gtest/gtest.h>

#include <nlohmann/json.hpp>
#include <yaml-cpp/yaml.h>

using json = nlohmann::json;

const char *pulsarConfig = R"(
pulsar:
  connectiontype: tcp
  mainlisteneraddress: 127.0.0.1:58090
  storage:
    datadirectory: ".artifacts/launchnet/pulsar_data"
    datadirectorynewdb: ""
    txretriesonconflict: 0
  pulsetime: 10000
  receivingsigntimeout: 1000
  receivingnumbertimeout: 1000
  receivingvectortimeout: 1000
  receivingsignsforchosentimeout: 0
  neighbours: []
  numberdelta: 10
  distributiontransport:
    protocol: TCP
    address: 127.0.0.1:58091
    fixedpublicaddress: ""
  pulsedistributor:
    bootstraphosts:
      - 127.0.0.1:13831
      - 127.0.0.1:23832
      - 127.0.0.1:33833
      - 127.0.0.1:43834
      - 127.0.0.1:53835
    pingrequesttimeout: 1000
    randomhostsrequesttimeout: 1000
    pulserequesttimeout: 1000
    randomnodescount: 5
versionmanager:
  minalowedversion: v0.3.0
keyspath: ".artifacts/launchnet/configs/pulsar_keys.json"
tracer:
  jaeger:
    collectorendpoint: ""
    agentendpoint: ""
    probabilityrate: 1
metrics:
  listenaddress: 127.0.0.1:7999
  namespace: insolar
  zpagesenabled: false
  reportingperiod: 0s
log:
  level: debug

)";

auto keys = R"(
{
    "private_key": "-----BEGIN PRIVATE KEY-----\nMHcCAQEEIO5QuEnPdZOCCGmNzDghIkcv4oV8ne+n53izQ1lJWdMGoAoGCCqGSM49\nAwEHoUQDQgAE3pSnZadkHOUNqdjH9OuDNv0yMLrh27YpdwAdmjKq1XmcAuuqyHk7\nofk1WiWbZo8N9MkPewIOlkYiNFSb2aaSxw==\n-----END PRIVATE KEY-----\n",
    "public_key": "-----BEGIN PUBLIC KEY-----\nMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAE3pSnZadkHOUNqdjH9OuDNv0yMLrh\n27YpdwAdmjKq1XmcAuuqyHk7ofk1WiWbZo8N9MkPewIOlkYiNFSb2aaSxw==\n-----END PUBLIC KEY-----\n"
}
)"_json;

TEST(configuration, readConfig)
{
EXPECT_TRUE(1);
}
