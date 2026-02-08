#ifndef DEPTH_TRANSDUCER_HPP
#define DEPTH_TRANSDUCER_HPP
#include <cstdint>

template <template<typename> class TTransport, typename THAL>
class DepthTransducer : private TTransport<THAL> {
public:
    float getDepthMeters() {
        // fetchRawData() is provided by CAN_Transport or Ethernet_Transport
        return static_cast<float>(this->fetchRawData()) * 0.1f;
    }
};
#endif