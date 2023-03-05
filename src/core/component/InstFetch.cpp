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
    sensitive<<pc_out<<jump_pc;


}


void InstFetch::process() {

}
