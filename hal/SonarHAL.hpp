#ifndef SONAR_HAL_HPP
#define SONAR_HAL_HPP
#include <cstdint>
#include "TransportTypes.hpp"

template <typename TVendorDriver>
class SonarHAL {
public:
    static TransportResult<uint16_t> read() { 
        static uint16_t latched_value = 0;
        static int ticks = 0;
        static bool initialized = false;

        TransportResult<uint16_t> res;

        if (!initialized || ticks % 4 == 0) {
            latched_value = TVendorDriver::readRegister(0x12);
            res.status = TransportStatus::OK;
            initialized = true;
        } else {
            res.status = TransportStatus::STALE_DATA;
        }
        res.data = latched_value;
        ticks++;
        return res;
    }
};
#endif