//
// Created by xyfuture on 2023/3/4.
//

#include "Controller.h"

Controller::Controller(const sc_module_name& name,const CoreConfig& config)
:sc_module(name),config(config) {

    SC_METHOD(updateControl);
    sensitive << if_stall << id_stall;

}


void Controller::updateControl() {

    auto if_status = if_stall.read();
    auto id_status = id_stall.read();

    if (id_status){
        if_enable.write(false);
        id_enable.write(false);
    }
    else if (if_status){
        if_enable.write(false);
        id_enable.write(true);
    }
    else{
        if_enable.write(true);
        id_enable.write(true);
    }

}