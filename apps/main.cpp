#include <iostream>
#include <cstdint>

// Components
#include "DepthTransducer.hpp"
#include "SonarTransducer.hpp"

// Transports
#include "CAN_Transport.hpp"           // Calls THAL::read()
#include "Ethernet_Transport.hpp"      // Calls THAL::read()

// HALs
#include "DepthHAL.hpp"                // Provides static read() -> addr 0x01
#include "SonarHAL.hpp"                // Provides static read() -> addr 0x12

struct DummyDriver {
    static void writeRegister(uint32_t reg, uint16_t val) {}
    static uint16_t readRegister(uint32_t reg) {
        if (reg == 0x01) return 500; // Depth
        if (reg == 0x12) return 200; // Sonar
        return 0;
    }
};

int main() {
    // Pipeline 1: Depth wired to CAN
    using DepthPipe = DepthTransducer<CAN_Transport, DepthHAL<DummyDriver>>;
    DepthPipe depthSensor;

    // Pipeline 2: Sonar wired to ETHERNET
    using SonarPipe = SonarTransducer<Ethernet_Transport, SonarHAL<DummyDriver>>;
    SonarPipe sonarSensor;

    std::cout << "--- Poseidon Multi-Transport Demo ---" << std::endl;
    std::cout << "Depth (CAN): " << depthSensor.getDepthMeters() << " m" << std::endl;
    std::cout << "Sonar (ETH): " << sonarSensor.getRangeMeters() << " m" << std::endl;

    return 0;
}