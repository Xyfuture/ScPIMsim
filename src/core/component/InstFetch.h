//
// Created by xyfuture on 2023/2/28.
//



#ifndef CORE_COMPONENT_INSTFETCH_H_
#define CORE_COMPONENT_INSTFETCH_H_

#include <systemc>
#include <vector>

#include "config/Config.hpp"
#include "isa/Instruction.h"
#include "utils/Register.hpp"
#include "core/payloads/StagePayloads.hpp"


using namespace sc_core;

class InstFetch: public sc_module  {
    SC_HAS_PROCESS(InstFetch);
public:
    InstFetch(const sc_module_name& name,const CoreConfig& config);

    

    void process();


private:
    const CoreConfig &config;
    std::vector<Instruction> inst_buffer;

private:
    RegEnable<int> pc_reg;

    sc_signal<int> pc_in;
    sc_signal<int> pc_out;

public:

    sc_in<bool> if_enable;
    sc_out<bool> if_stall;

    sc_out<DecodeInfo> if_id_port;

    sc_in<JumpInfo> jump_pc ;

};



#endif //CORE_COMPONENT_INSTFETCH_H_
