//
// Created by xyfuture on 2023/3/6.
//

#include "InstDecode.h"

InstDecode::InstDecode(const sc_module_name &name, const CoreConfig &config)
: sc_module(name),config(config), decode_reg("decode_reg",config.period) {
    decode_reg.input.bind(if_id_port);
    decode_reg.output.bind(decode_reg_out);
    decode_reg.enable.bind(id_enable);

    bitwidth_reg.input.bind(bitwidth_reg_in);
    bitwidth_reg.output.bind(bitwidth_reg_out);

}
