#ifndef DEPTH_HAL_HPP
#define DEPTH_HAL_HPP
#include <cstdint>
#include "TransportTypes.hpp"

template <typename TVendorDriver>
class DepthHAL {
public:
    static TransportResult<uint16_t> read() { 
        static uint16_t latched_depth = 0;
        static int depth_ticks = 0;
        static bool initialized = false;

        TransportResult<uint16_t> res;

        // Simulate hardware sampling every 200ms
        if (!initialized || depth_ticks % 2 == 0) {
            latched_depth = TVendorDriver::readRegister(0x01);
            res.status = TransportStatus::OK;
            initialized = true;
        } else {
            res.status = TransportStatus::STALE_DATA;
        }
        
        res.data = latched_depth;
        depth_ticks++;
        return res;
    }
};
#endif