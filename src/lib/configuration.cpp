#include <pulsar/configuration.h>
#include <yaml-cpp/yaml.h>

namespace pulsar {

Config loadFromYaml(const YAML::Node& yml) {
    Config result;

    std::list<std::string> hosts;
    auto bootstraphosts = yml["pulsar"]["pulsedistributor"]["bootstraphosts"];
    for(auto it=bootstraphosts.begin(); it!=bootstraphosts.end(); ++it) {
        hosts.emplace_back(it->as<std::string>());
    }
    std::swap(hosts, result.bootstrapHosts);

    result.keysPath = yml["keyspath"].as<std::string>();
//    auto pulsetime1 = yml["pulsetime"].as<int>();
//    numberdelta = yml["numberdelta"].as<int>();
    return result;
}

Config Configuration::LoadFromYamlFile(const std::string& fileName) {
    YAML::Node yml = YAML::LoadFile(fileName);
    return loadFromYaml(yml);
}

Config Configuration::LoadFromYaml(const std::string &yamlString) {
    YAML::Node yml = YAML::Load(yamlString);
    return loadFromYaml(yml);
}

} // namespace pulsar
