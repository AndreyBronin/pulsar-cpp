#pragma once

#include <string>
#include <list>

namespace pulsar {

/**
* Configuration for pulsar service
*/
class Configuration {
public:
    Configuration() = default;

    virtual ~Configuration() = default;

    const std::list<std::string>& GetBootstrapHosts() const;
    std::string GetKeysPath() const;

    void LoadFromFile(const std::string& filename);

private:
    std::string m_keysPath;
    std::list<std::string> m_bootstrapHosts;
    int pulsetime;
    int numberdelta;
};

} // namespace pulsar
