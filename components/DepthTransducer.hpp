#ifndef DEPTH_TRANSDUCER_HPP
#define DEPTH_TRANSDUCER_HPP
#include <cstdint>
#include "TransportTypes.hpp"

template <template<typename> class TTransport, typename THAL>
class DepthTransducer : private TTransport<THAL> {
public:
    TransportResult<float> getDepthMeters() {
        // fetchRawData() is provided by CAN_Transport or Ethernet_Transport
        auto raw = this->fetchRawData();
        TransportResult<float> result;

        result.status = raw.status;
        result.timestamp_ms = raw.timestamp_ms;

        if (raw.status == TransportStatus::OK || raw.status == TransportStatus::STALE_DATA) {
            result.data = static_cast<float>(raw.data) / 10.0f;
        } else {
            result.data = -1.0f; // Sentinel value for "Invalid"
        }

        return result;
    }
};
#endif