#ifndef PHYSICS_DRIVER_HPP
#define PHYSICS_DRIVER_HPP

#include <cmath>
#include <cstdint>

class PhysicsDriver {
private:
    // Shared state across all sensors
    static float sub_depth; 
    static float sub_range;
    static const float seabed_depth; 

public:
    // Register Map
    static const uint8_t REG_DEPTH = 0x01;
    static const uint8_t REG_SONAR = 0x12;

    // Called by the Scheduler/App Loop to move the sub
    static void updatePhysics(float dt) {
        static float vertical_velocity = 0.5f; // Diving at 0.5 m/s
        sub_depth += vertical_velocity * dt;
        static float horizontal_velocity = 0.2f; // Moving forward at 0.2 m/s
        sub_range -= horizontal_velocity * dt; // closing range to contact
    }

    // Called by the HALs
    static uint16_t readRegister(uint8_t reg) {
        if (reg == REG_DEPTH) {
            return static_cast<uint16_t>(sub_depth * 10); // dm
        }
        if (reg == REG_SONAR) {
            return static_cast<uint16_t>(sub_range * 10); // dm
        }
        return 0;
    }
};

// C++11 static initialization
float PhysicsDriver::sub_depth = 10.0f;
float PhysicsDriver::sub_range = 2000.0f; 
const float PhysicsDriver::seabed_depth = 150.0f;


#endif