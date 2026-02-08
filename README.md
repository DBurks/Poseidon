# Project Poseidon: Submarine Systems Simulator
**Milestone 0: Decoupled Transport Architecture**

## Overview
This project demonstrates a physically decoupled sensor architecture using C++ Template-Template parameters (The "Static Bridge" Pattern). It allows for high-level sensor logic to be developed independently of the communication protocol (CAN, Ethernet, I2C).

## Architecture Stack
1. **Application Layer**: `main.cpp` - Configures and wires the pipelines.
2. **Component Layer**: `Transducer` classes - Handles unit conversion and math.
3. **Transport Layer**: `Transport` classes - Manages protocol-specific data fetching.
4. **HAL Layer**: `HAL` classes - Maps logical requests to hardware registers.
5. **Driver Layer**: `Driver` structs - Low-level hardware/register access.

## Current Build Status
- [x] Depth Transducer over CAN Bus
- [x] Sonar Transducer over Ethernet
- [x] 100% Header-only Template implementation (Compile-time Polymorphism)

## Performance Note
By using templates instead of virtual functions (Runtime Polymorphism), this architecture provides zero-overhead abstraction, making it suitable for real-time embedded submarine control systems.