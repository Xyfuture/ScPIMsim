//
// Created by xyfuture on 2023/3/6.
//



#ifndef CORE_COMPONENT_INSTDECODE_H_
#define CORE_COMPONENT_INSTDECODE_H_

#include <systemc>

#include "config/Config.hpp"
#include "isa/Instruction.h"
#include "utils/Register.hpp"
#include "core/payloads/StagePayloads.hpp"

using namespace sc_core;


class InstDecode: public sc_module{
    SC_HAS_PROCESS(InstDecode);
public:
    InstDecode(const sc_module_name& name,const CoreConfig& config);



public:
    sc_in<bool> id_enable;
    sc_out<bool> id_stall;

    sc_in<DecodeInfo> if_id_port;
    sc_out<JumpInfo> jump_port;


};


#endif //CORE_COMPONENT_INSTDECODE_H_
