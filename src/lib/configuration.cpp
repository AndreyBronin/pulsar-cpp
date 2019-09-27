#include <pulsar/configuration.h>
#include <yaml-cpp/yaml.h>

namespace pulsar {

void Configuration::LoadFromFile(const std::string& filename) {
    YAML::Node config = YAML::LoadFile(filename);

    std::list<std::string> hosts;
    auto bootstraphosts = config["pulsar"]["pulsedistributor"]["bootstraphosts"];
    for(auto it=bootstraphosts.begin(); it!=bootstraphosts.end(); ++it) {
        hosts.emplace_back(it->as<std::string>());
    }
    std::swap(hosts, m_bootstrapHosts);

    m_keysPath = config["keyspath"].as<std::string>();
//    auto pulsetime1 = config["pulsetime"].as<int>();
//    numberdelta = config["numberdelta"].as<int>();
}

const std::list<std::string>& Configuration::GetBootstrapHosts() const {
    return m_bootstrapHosts;
}

std::string Configuration::GetKeysPath() const {
    return m_keysPath;
}

} // namespace pulsar

