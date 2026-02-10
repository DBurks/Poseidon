cmake_minimum_required(VERSION 3.10)
project(PoseidonProject)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 1. Components (Agnostic Logic)
add_library(poseidon_components INTERFACE)
target_include_directories(poseidon_components INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/components)

# 1.5 Transport Common (Transports)
add_library(transport_common INTERFACE)
target_include_directories(transport_common INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/transport)

# 2. Transports (Agnostic Communication)
add_library(transport_can INTERFACE)
target_include_directories(transport_can INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/transport/can)
target_compile_definitions(transport_can INTERFACE USE_CAN_BUS)

add_library(transport_ethernet INTERFACE)
target_include_directories(transport_ethernet INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/transport/ethernet)
target_compile_definitions(transport_ethernet INTERFACE USE_ETHERNET_BUS)

# 3. HALs (Hardware Abstraction)
add_library(poseidon_hal INTERFACE)
target_include_directories(poseidon_hal INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/hal)

# 3.5 Drivers (Implementation Details)
add_library(poseidon_drivers INTERFACE)
target_include_directories(poseidon_drivers INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/drivers)

# 4. The Application (The "Integrator")
add_executable(PoseidonApp apps/main.cpp)
target_link_libraries(PoseidonApp PRIVATE 
    poseidon_components 
    transport_can 
    transport_ethernet
    transport_common
    poseidon_hal
    poseidon_drivers    # <--- Add this here
)