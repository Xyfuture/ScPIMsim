//
// Created by xyfuture on 2023/2/28.
//

#include "InstFetch.h"


InstFetch::InstFetch(const sc_module_name& name, const CoreConfig &config)
:sc_module(name),config(config),pc_reg("pc_reg",config.period){
    pc_reg.input.bind(pc_in);
    pc_reg.output.bind(pc_out);
    pc_reg.enable.bind(if_enable);

    SC_METHOD(process);
    sensitive << pc_out << jump_port;


}


void InstFetch::process() {
    auto cur_pc = pc_out.read();
    auto jump_info = jump_port.read();


    if(jump_info.is_jump){ // jump to pc+offset
        auto next_pc = cur_pc+jump_info.offset;
        DecodeInfo decode_info {.pc = -1,.inst = Instruction()};

        pc_in.write(next_pc);
        if_id_port.write(decode_info);
    }
    else{
        auto next_pc = cur_pc + 1;
        DecodeInfo decode_info = {.pc=cur_pc,.inst=inst_buffer[cur_pc]};

        pc_in.write(next_pc);
        if_id_port.write(decode_info);
    }
}

void InstFetch::setInstBuffer(const std::vector<Instruction>& buffer) {
    inst_buffer = buffer;
}
