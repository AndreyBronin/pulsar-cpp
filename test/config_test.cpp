#include <gtest/gtest.h>

#include <pulsar/configuration.h>
#include <yaml-cpp/yaml.h>

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

TEST(configuration, LoadFromYaml_Succesfully_Loaded) {
    auto cfg = pulsar::Configuration::LoadFromYaml(pulsarConfig);

    auto hosts = std::list<std::string>{"127.0.0.1:13831", "127.0.0.1:23832", "127.0.0.1:33833"};
    EXPECT_EQ(".artifacts/launchnet/configs/pulsar_keys.json", cfg.keysPath);
    EXPECT_EQ(10000, cfg.pulseTime);
    EXPECT_EQ(10, cfg.numberDelta);
    EXPECT_EQ(hosts, cfg.bootstrapHosts);
}
