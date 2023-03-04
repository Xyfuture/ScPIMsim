//
// Created by xyfuture on 2023/3/4.
//



#ifndef CORE_COMPONENT_CONTROLLER_H_
#define CORE_COMPONENT_CONTROLLER_H_

#include <systemc>

#include "config/Config.hpp"

using namespace sc_core;

class Controller:public sc_module {
public:
    SC_HAS_PROCESS(Controller);

    Controller(const sc_module_name& name,const CoreConfig& config);


    void updateControl();


private:

    sc_in<bool> if_stall;
    sc_in<bool> id_stall;

    sc_out<bool> if_enable;
    sc_out<bool> id_enable;

    const CoreConfig& config;
};


#endif //CORE_COMPONENT_CONTROLLER_H_
