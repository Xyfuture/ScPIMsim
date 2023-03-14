//
// Created by xyfuture on 2023/3/6.
//

#include "ScalarUnit.h"

ScalarUnit::ScalarUnit(const sc_module_name &name, const CoreConfig &config):
sc_module(name),config(config), scalar_reg("scalar reg",config.period){
    scalar_reg.input.bind(id_scalar_port);
    scalar_reg.output.bind(scalar_reg_out);

    SC_METHOD(process);
    sensitive<<scalar_reg_out;
}

void ScalarUnit::process() {
    auto scalar_info = scalar_reg_out.read();

    if (scalar_info.op == +Opcode::nop)
        return;

    RegFileWrite write_info ;

    switch (scalar_info.op) {
        case Opcode::sadd:
            write_info = {.rd_addr=scalar_info.rd_addr,
                          .rd_value=scalar_info.rs1_data+scalar_info.rs2_data};
            break;
        case Opcode::saddi:
            write_info = {.rd_addr=scalar_info.rd_addr,
                          .rd_value=scalar_info.rs1_data+scalar_info.imm};
            break;
        case Opcode::ssub:
            write_info = {.rd_addr=scalar_info.rd_addr,
                          .rd_value=scalar_info.rs1_data - scalar_info.rs2_data};
            break;
        case Opcode::smul:
            write_info = {.rd_addr=scalar_info.rd_addr,
                          .rd_value=scalar_info.rs1_data*scalar_info.rs2_data};
            break;
        case Opcode::smuli:
            write_info = {.rd_addr=scalar_info.rd_addr,
                          .rd_value=scalar_info.rs1_data*scalar_info.imm};
            break;
        case Opcode::sldi:
            write_info = {.rd_addr=scalar_info.rd_addr,
                          .rd_value=scalar_info.imm};
            break;
        case Opcode::sld:
            break;
        default:
            return;
    }

    reg_file_write_port.write(write_info);
}


