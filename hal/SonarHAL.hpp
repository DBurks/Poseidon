#ifndef SONAR_HAL_HPP
#define SONAR_HAL_HPP
#include <cstdint>

template <typename TVendorDriver>
class SonarHAL {
public:
    static uint16_t read() { 
        return TVendorDriver::readRegister(0x12); // Sonar address
    }
};
#endif