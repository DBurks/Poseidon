#ifndef CAN_TRANSPORT_HPP
#define CAN_TRANSPORT_HPP
#include <cstdint>
#include "TransportTypes.hpp" // For TransportResult and TransportStatus

template <typename THAL>
class CAN_Transport {
protected:
    TransportResult<uint16_t> fetchRawData() {
        auto result = THAL::read();
        // Simulate 5% packet loss
        if ((std::rand() % 100) < 5) {
            result.status = TransportStatus::PACKET_LOSS;
        }
        
        return result;
    }
};
#endif