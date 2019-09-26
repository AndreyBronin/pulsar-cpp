//
// Created by Andrey Bronin on 25/09/2019.
//

#pragma once

#include <string_view>

namespace pulsar {

/**
 * Configuration for pulsar service
 */
    class PulsarConfiguration {
    public:
        PulsarConfiguration() = default;

        virtual ~PulsarConfiguration() = default;

        void LoadFromFile(std::string_view path);
    };



    struct Pulse {
    };

// Pulsar interface
    struct Pulsar {
        virtual ~Pulsar() = default;

        void DistributePulse(Pulse p);
    };

} // namespace pulsar