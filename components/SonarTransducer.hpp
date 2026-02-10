#ifndef SONAR_TRANSDUCER_HPP
#define SONAR_TRANSDUCER_HPP

#include <cstdint>

template <template<typename> class TTransport, typename THAL>
class SonarTransducer : private TTransport<THAL> {
public:
    TransportResult<float> getRangeMeters() {
        auto raw = this->fetchRawData();
        TransportResult<float> result;

        result.status = raw.status;
        result.timestamp_ms = raw.timestamp_ms;
        if (raw.status == TransportStatus::OK || raw.status == TransportStatus::STALE_DATA) {
            result.data = static_cast<float>(raw.data) * 0.05f;
        } else {
            result.data = -1.0f; // Sentinel value for "Invalid"
        }
        return result;
    }
};

#endif