//
// Created by Andrey Bronin on 25/09/2019.
//

#pragma once

#include <pulsar/configuration.h>

namespace pulsar {

struct Pulse {
};

// Pulsar interface
struct Pulsar {
    explicit Pulsar(Configuration&& config);
    virtual ~Pulsar() = default;

    void DistributePulse(Pulse p);
};

} // namespace pulsar