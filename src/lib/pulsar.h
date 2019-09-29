#pragma once

#include <pulsar/pulsar.h>
#include <pulsar/configuration.h>
#include <pulsar/cryptography.h>
#include <pulse.pb.h>

namespace pulsar {

using Pulse = pulse::PulseProto;

// Pulsar interface
class PulsarImpl {
public:
    explicit PulsarImpl(Config&& config, CryptographyScheme&& cryptographyScheme);
    virtual ~PulsarImpl() = default;

    void DistributePulse(const Pulse& p);

private:
    const Config m_cfg;
    CryptographyScheme m_crypto;
};

} // namespace pulsar