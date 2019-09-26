#include <nlohmann/json.hpp>
#include <yaml-cpp/yaml.h>
#include <iostream>
#include <fstream>

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
    "private_key": "-----BEGIN PRIVATE KEY-----\nMIGHAgEAMBMGByqGSM49AgEGCCqGSM49AwEHBG0wawIBAQQgIim8RlCCD+mLqxBt\n2cXgycQlFiD7sFCz9Qf962kL1w+hRANCAATYYOwbW09dA4jaJ8Z/c7TOehxLzvf8\nVYdd+R+be8Yvy1AW8lhidLQxY6YM5aXE1jiJKqJKnUhrNNkDJRMvdDhG\n-----END PRIVATE KEY-----\n",
    "public_key": "-----BEGIN PUBLIC KEY-----\nMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAE2GDsG1tPXQOI2ifGf3O0znocS873\n/FWHXfkfm3vGL8tQFvJYYnS0MWOmDOWlxNY4iSqiSp1IazTZAyUTL3Q4Rg==\n-----END PUBLIC KEY-----\n"
}
)"_json;

void readConfig()
{
    YAML::Node config = YAML::Load(pulsarConfig);
    auto bootstraphosts = config["pulsar"]["pulsedistributor"]["bootstraphosts"];
    for(auto it=bootstraphosts.begin(); it!=bootstraphosts.end(); ++it) {
        std::cout << "Playing at " << it->as<std::string>()  << std::endl;
    }

    auto keyspath = config["keyspath"].as<std::string>();
    keyspath = "/Users/bronin/go/src/github.com/insolar/insolar/" + keyspath;
    std::cout << keyspath << std::endl;

    // read a JSON file
    std::ifstream i(keyspath);
    json j;
    i >> j;

    std::cout << j.at("private_key") << std::endl;
    std::cout << j.at("public_key") << std::endl;

    std::cout << keys.at("private_key") << std::endl;
    std::cout << keys.at("public_key") << std::endl;
}
