#ifndef TRANSPORT_TYPES_HPP
#define TRANSPORT_TYPES_HPP

#include <cstdint>

enum class TransportStatus {
    OK,
    PACKET_LOSS,
    STALE_DATA,
    HARDWARE_ERROR
};

template <typename T>
struct TransportResult {
    T data;
    TransportStatus status;
    uint32_t timestamp_ms; // Useful for the "staleness" check later

    // Quick helper to see if the data is usable
    bool isValid() const {
        return status == TransportStatus::OK;
    }
};

#endif