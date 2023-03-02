//
// Created by xyfuture on 2023/3/1.
//

#pragma once

#ifndef CONFIG_BUSCONFIG_H_
#define CONFIG_BUSCONFIG_H_

#include <string>
#include <vector>
#include "nlohmann/json.hpp"

class BusConfig {
public:

    std::string bus_topology = "shared";
    int bus_width = 15; // Bytes

    int latency = 1 ; // cycles/hop
    float energy = 1.0 ; // nJ/hop

    std::vector<int> layout = {0}; // mesh use this

    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(BusConfig,
                                       bus_topology,latency,energy,layout)
};

class MemoryConfig{
public:
    long long memory_size = 1024*1024 ; // Bytes
    int data_width = 16; // Bytes

    int write_latency = 10; // Cycles
    float write_energy =1.0; // nJ per data_width

    int read_latency = 1.0; // Cycles
    float read_energy = 1.0; // nJ

    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(MemoryConfig,
                                       memory_size,data_width,
                                       write_latency,write_energy,
                                       read_latency,read_energy)


};


class CoreConfig{

};

class ChipConfig{

};

class SimConfig{

};

#endif //CONFIG_BUSCONFIG_H_
