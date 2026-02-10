#ifndef ETHERNET_TRANSPORT_HPP
#define ETHERNET_TRANSPORT_HPP
#include <cstdint>
#include <chrono>
#include "TransportTypes.hpp" // For TransportResult and TransportStatus

template <typename THAL>
class Ethernet_Transport {
private:
    uint16_t hardware_buffer;
protected:
    TransportResult<uint16_t> fetchRawData() {
        return THAL::read(); ;
    }
};

#endif