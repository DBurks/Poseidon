#ifndef ETHERNET_TRANSPORT_HPP
#define ETHERNET_TRANSPORT_HPP

#include <cstdint>

template <typename THAL>
class Ethernet_Transport {
protected:
    uint16_t fetchRawData() {
        // Standardized handshake: Calls the static read() in the HAL
        return THAL::read(); 
    }
};

#endif