#ifndef CAN_TRANSPORT_HPP
#define CAN_TRANSPORT_HPP
#include <cstdint>

template <typename THAL>
class CAN_Transport {
protected:
    uint16_t fetchRawData() {
        return THAL::read(); // This now matches the HALs above perfectly
    }
};
#endif