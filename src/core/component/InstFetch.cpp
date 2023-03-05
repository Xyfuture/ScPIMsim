//
// Created by xyfuture on 2023/2/28.
//

#include "InstFetch.h"

struct A{

};

struct B:A{
    int pc=0;
};


InstFetch::InstFetch(const sc_module_name& name, const CoreConfig &config)
:sc_module(name),config(config),pc_reg("pc_reg",config.period){
    pc_reg.input.bind(pc_in);
    pc_reg.output.bind(pc_out);
    pc_reg.enable.bind(if_enable);

    SC_METHOD(process);
    sensitive<<pc_out<<jump_pc;


}


void InstFetch::process() {
    auto cur_pc = pc_out.read();
    auto jump_info = jump_pc.read();


    if(jump_info.is_jump){ // jump to pc+offset
        auto next_pc = cur_pc+jump_info.offset;
//        DecodeInfo decode_info {.pc = 1,.inst = Instruction()};
//        B b {.pc=1};
    }
    else{

    }
}
