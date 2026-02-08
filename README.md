# Project Poseidon: Submarine Control System

A decoupled, template-based C++11 simulation of a submarine sensor suite.

## Architecture: The "Static Bridge"
This project uses a decoupled approach to separate physical logic from communication protocols:
- **Components**: High-level sensor logic (Depth, Sonar).
- **Transports**: Communication protocols (CAN, Ethernet).
- **HAL**: Hardware Abstraction Layer mapping logic to registers.
- **Drivers**: Simulation engine (PhysicsDriver) providing the "Source of Truth."

## Current Progress
- **Sprint 1.1**: Implemented 10Hz cyclic executive with dual-sensor integration.
- **Physics**: Real-time depth and range simulation via Euler integration.
- **Build**: Modern CMake (Target-based) with GitHub Actions CI.

## How to Run
```bash
mkdir build && cd build
cmake ..
make
./PoseidonApp