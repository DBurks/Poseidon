# Project Poseidon: Submarine Control System

A decoupled, template-based C++11 simulation of a submarine sensor suite.

## Architecture: The "Static Bridge"
This project uses a decoupled approach to separate physical logic from communication protocols:
- **Components**: High-level sensor logic (Depth, Sonar). Handles unit conversion and data validation.
- **Transports**: Communication protocols (CAN, Ethernet). Manages packet integrity and injects "Bus Chaos" (Packet Loss).
- **HAL**: Hardware Abstraction Layer mapping logic to registers and simulating asynchronous hardware sampling rates.
- **Drivers**: Simulation engine (PhysicsDriver) providing the "Source of Truth."

## Current Progress
- **Sprint 1.1**: Implemented 10Hz cyclic executive with dual-sensor integration.
- **Sprint 1.2**: Implemented Transport Health & Multi-Rate Sampling.
    - **Status Awareness**: Support for `OK`, `STALE_DATA`, and `PACKET_LOSS` statuses.
    - **Data Coasting**: Logic to maintain last-known-good values during hardware refresh gaps.
    - **Physics**: Real-time depth and range simulation via Euler integration.
- **Build**: Modern CMake (Target-based) with GitHub Actions CI.



## Telemetry Legend
- **[OK]**: Fresh data sample from hardware.
- **[STALE]**: No new hardware update; system is coasting on cached data.
- **[LOSS]**: Communication failure; data redacted for safety.

## How to Run
```bash
mkdir build && cd build
cmake ..
make
./PoseidonApp