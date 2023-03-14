//
// Created by xyfuture on 2023/3/6.
//

#include "RegFile.h"

RegFile::RegFile(const sc_module_name &name, const CoreConfig &config)
:sc_module(name),config(config),reg_data(32), write_info_reg("reg",config.period){
    write_info_reg.input.bind(reg_in);
    write_info_reg.output.bind(reg_out);

    SC_METHOD(readValue);
    sensitive << reg_out << reg_file_write_port << reg_file_read_addr_port; // 三个端口都需要
    SC_METHOD(writeValue);
    sensitive << reg_file_write_port;
    SC_METHOD(updateValue);
    sensitive<<reg_out;


}

void RegFile::readValue() {
    auto last_write= reg_out.read();
    auto cur_write = reg_file_write_port.read();

    auto read_info = reg_file_read_addr_port.read();

    int values[] = {0,0,0}; // rd rs1 rs2
    int addrs[] = {read_info.rd_addr,read_info.rs1_addr,read_info.rs2_addr};

    for(int i=0;i<3;i++){ // 注意优先级
        auto addr = addrs[i];
        if (addr == 0)
            values[i] = 0;
        else if (addr == cur_write.rd_addr)
            values[i] = cur_write.rd_value;
        else if (addr == last_write.rd_addr)
            values[i] = last_write.rd_value;
        else
            values[i] = reg_data[addr];
    }

    RegFileReadValue value_info {values[0],values[1],values[2]};

    reg_file_read_value_port.write(value_info);

}

void RegFile::writeValue() {
    auto cur_write = reg_file_write_port.read();
    reg_in.write(cur_write);
}

void RegFile::updateValue() {
    auto last_write = reg_out.read();
    if (last_write.rd_addr != 0)
        reg_data[last_write.rd_addr] = last_write.rd_value;
}
