#ifndef DEPTH_HAL_HPP
#define DEPTH_HAL_HPP
#include <cstdint>

template <typename TVendorDriver>
class DepthHAL {
public:
    static uint16_t read() { 
        return TVendorDriver::readRegister(0x01); // Depth address
    }
};
#endif