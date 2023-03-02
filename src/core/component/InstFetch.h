//
// Created by xyfuture on 2023/2/28.
//



#ifndef CORE_COMPONENT_INSTFETCH_H_
#define CORE_COMPONENT_INSTFETCH_H_

#include <systemc>
#include <vector>

#include "config/Config.hpp"
#include "isa/Instruction.h"

using namespace sc_core;

class InstFetch: public sc_module  {
    SC_HAS_PROCESS(InstFetch);
public:
    InstFetch(sc_module_name name,const CoreConfig& config);


    void updatePC();


private:
    const CoreConfig &config;
    std::vector<Instruction> inst_buffer;

private:

    int pc = 0;


};



#endif //CORE_COMPONENT_INSTFETCH_H_
