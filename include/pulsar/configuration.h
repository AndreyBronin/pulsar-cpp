#pragma once

#include <string>
#include <list>

namespace pulsar {

struct Config {
    std::string keysPath;
    std::list<std::string> bootstrapHosts;
    uint32_t pulseTime;
    uint32_t numberDelta;
};

/**
* Configuration for pulsar service
*/
class Configuration {
public:
    static Config LoadFromYamlFile(const std::string& fileName);
    static Config LoadFromYaml(const std::string& yamlString);
};

} // namespace pulsar
