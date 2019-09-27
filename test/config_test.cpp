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
    "private_key": "-----BEGIN PRIVATE KEY-----\nMIGHAgEAMBMGByqGSM49AgEGCCqGSM49AwEHBG0wawIBAQQgwYAFzRM5vgMr53wc\n9DzVFys6dNj3Z56J7XzLC62jK+ehRANCAASw4x080JGlYAfG+qLEHt8D2IMqPICm\nS1zuExXwEuJOv0kPY72kiqgwymJClryLC4pEw07rGKY9vPgKyEKX6dMj\n-----END PRIVATE KEY-----\n",
    "public_key": "-----BEGIN PUBLIC KEY-----\nMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEsOMdPNCRpWAHxvqixB7fA9iDKjyA\npktc7hMV8BLiTr9JD2O9pIqoMMpiQpa8iwuKRMNO6ximPbz4CshCl+nTIw==\n-----END PUBLIC KEY-----\n"
}
)"_json;

TEST(configuration, readConfig)
{
EXPECT_TRUE(1);
}
