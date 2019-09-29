#pragma once

#include <pulsar/configuration.h>
#include <pulsar/cryptography.h>

namespace pulsar {

// Pulsar interface
struct IPulsar {
    virtual ~IPulsar() = default;

    // ctx is context and cancellation token
    virtual void StartDistribute(void* ctx, Config&& config, std::shared_ptr<ICryptographyScheme> crypto) = 0;
};

class Pulsar: public IPulsar {
public:
    Pulsar() = default;

    void StartDistribute(void* ctx, Config&& config, std::shared_ptr<ICryptographyScheme> crypto) override;

private:
    std::unique_ptr<IPulsar> m_pulsar;
};

} // namespace pulsar