#ifndef SONAR_TRANSDUCER_HPP
#define SONAR_TRANSDUCER_HPP

#include <cstdint>

template <template<typename> class TTransport, typename THAL>
class SonarTransducer : private TTransport<THAL> {
public:
    float getRangeMeters() {
        // Calls fetchRawData() from the parent Transport
        return static_cast<float>(this->fetchRawData()) * 0.05f;
    }
};

#endif