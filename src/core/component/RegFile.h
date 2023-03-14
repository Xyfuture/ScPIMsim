//
// Created by xyfuture on 2023/3/6.
//



#ifndef CORE_COMPONENT_REGFILE_H_
#define CORE_COMPONENT_REGFILE_H_

#include <vector>
#include <systemc>

#include "config/Config.hpp"
#include "core/payloads/StagePayloads.hpp"
#include "utils/Register.hpp"

using namespace sc_core;


class RegFile: public sc_module{
    SC_HAS_PROCESS(RegFile);
public:
    RegFile(const sc_module_name& name,const CoreConfig& config);

    void readValue();
    void writeValue();
    void updateValue();


private:
    std::vector<int> reg_data;

    const CoreConfig& config;
private:
    RegNext<RegFileWrite> write_info_reg;

    sc_signal<RegFileWrite> reg_in;
    sc_signal<RegFileWrite> reg_out;

public:
    sc_in<RegFileReadAddr> reg_file_read_addr_port;
    sc_out<RegFileReadValue> reg_file_read_value_port;

    sc_in<RegFileWrite> reg_file_write_port;
};


#endif //CORE_COMPONENT_REGFILE_H_
