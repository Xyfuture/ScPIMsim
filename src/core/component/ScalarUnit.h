//
// Created by xyfuture on 2023/3/6.
//



#ifndef CORE_COMPONENT_SCALARUNIT_H_
#define CORE_COMPONENT_SCALARUNIT_H_

#include <systemc>
#include "config/Config.hpp"


using namespace sc_core;

class ScalarUnit:public sc_module {
    SC_HAS_PROCESS(ScalarUnit);
public:
    ScalarUnit(const sc_module_name& name,const CoreConfig& config);


private:
    CoreConfig& config;

};


#endif //CORE_COMPONENT_SCALARUNIT_H_
