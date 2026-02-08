#include <iostream>
#include <vector>
#include <unistd.h> // For usleep

// Infrastructure
#include "PhysicsDriver.hpp"
#include "DepthHAL.hpp"
#include "SonarHAL.hpp"
#include "CAN_Transport.hpp"
#include "Ethernet_Transport.hpp"

// Domain Logic
#include "DepthTransducer.hpp"
#include "SonarTransducer.hpp"

// Wiring the Static Bridge
using DepthPipe = DepthTransducer<CAN_Transport, DepthHAL<PhysicsDriver>>;
using SonarPipe = SonarTransducer<Ethernet_Transport, SonarHAL<PhysicsDriver>>;

int main() {
    DepthPipe depthSensor;
    SonarPipe sonarSensor;

    const int frequency_hz = 10;           // 10Hz updates
    const int duration_seconds = 10;       // Run for 10 seconds
    const int total_iterations = frequency_hz * duration_seconds;
    const int sleep_microsecond = 100000;  // 100ms

    std::cout << "--- Poseidon Submarine Simulation Start ---" << std::endl;
    std::cout << "Target: 10s at 100ms intervals" << std::endl;

    for (int i = 0; i < total_iterations; ++i) {
        // 1. Update the physical world (0.1s step)
        PhysicsDriver::updatePhysics(0.1f);

        // 2. Sample the sensors
        float d = depthSensor.getDepthMeters();
        float a = sonarSensor.getRangeMeters();

        // 3. Log data
        std::cout << "[" << (i + 1) * 0.1 << "s] "
                  << "Depth: " << d << "m | "
                  << "Range: " << a << "m" << std::endl;

        usleep(sleep_microsecond);
    }

    std::cout << "--- Simulation Complete ---" << std::endl;
    return 0;
}