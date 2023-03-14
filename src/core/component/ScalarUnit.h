//
// Created by xyfuture on 2023/3/6.
//



#ifndef CORE_COMPONENT_SCALARUNIT_H_
#define CORE_COMPONENT_SCALARUNIT_H_

#include <systemc>
#include "config/Config.hpp"
#include "utils/Register.hpp"
#include "core/payloads/StagePayloads.hpp"


using namespace sc_core;

class ScalarUnit:public sc_module {
    SC_HAS_PROCESS(ScalarUnit);
public:
    ScalarUnit(const sc_module_name& name,const CoreConfig& config);

    void process();

private:
    const CoreConfig& config;

private:
    RegNext<ScalarInfo> scalar_reg;

    sc_signal<ScalarInfo> scalar_reg_out;

public:
    sc_in<ScalarInfo> id_scalar_port;
    sc_out<RegFileWrite> reg_file_write_port;

};


#endif //CORE_COMPONENT_SCALARUNIT_H_
