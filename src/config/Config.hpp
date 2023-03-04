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

    NLOHMANN_DEFINE_TYPE_INTRUSIVE_WITH_DEFAULT(BusConfig,
                                       bus_topology,latency,energy,layout)
};

struct MemoryConfig{

    long long memory_size = 1024*1024 ; // Bytes
    int data_width = 16; // Bytes

    int write_latency = 10; // Cycles
    float write_energy =1.0; // nJ per data_width

    int read_latency = 1.0; // Cycles
    float read_energy = 1.0; // nJ

    NLOHMANN_DEFINE_TYPE_INTRUSIVE_WITH_DEFAULT(MemoryConfig,
                                                memory_size,data_width,
                                                write_latency,write_energy,
                                                read_latency,read_energy)
};




struct CoreConfig{

//    double frequency = 1; //GHz
    double period = 1; // ns

    int input_precision = 8 ; // bits
    int weight_precision = 8; // bits

    // Matrix Unit
    int matrix_latency = 1000; // Cycles
    float matrix_energy_per_pe = 1.0; // nJ
    int device_precision = 2; // bits
    std::vector<int> xbar_size = {128,128};

    // Vector Unit
    int vector_width = 32 ;
    int vector_latency = 2 ; // Cycles per op
    float vector_energy = 1.0; // nJ


};

struct ChipConfig{

};

struct SimConfig{

};

#endif //CONFIG_BUSCONFIG_H_
