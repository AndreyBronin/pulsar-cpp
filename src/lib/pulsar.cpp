#include "pulsar.h"

#include <sstream>

namespace pulsar {

void Pulsar::StartDistribute(void* ctx, Config&& config, std::shared_ptr<ICryptographyScheme> crypto){
    //m_pulsar = std::make_unique<PulsarImpl>(config, crypto);
}

PulsarImpl::PulsarImpl(class Config&& config, CryptographyScheme&& cryptographyScheme):
        m_cfg(config), m_crypto(std::move(cryptographyScheme)){}


void PulsarImpl::DistributePulse(const Pulse& p) {
    Pulse pulse;
    pulse.set_pulsenumber(123);
    pulse.set_pulsetimestamp(std::time(nullptr));

    std::ostringstream stream;
    p.SerializeToOstream(&stream);

    std::string text = stream.str();
    // char* ctext = text.c_str();

    std::cout << p.DebugString() << std::endl;
}

} // namespace pulsar