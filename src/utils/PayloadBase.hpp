//
// Created by xyfuture on 2023/3/1.
//


#pragma once

#ifndef UTILS_PAYLOADBASE_H_
#define UTILS_PAYLOADBASE_H_

#include <string>
#include <systemc>


struct PayloadBase {

    // overload =,==,<< and sc_trace()
    // default = operator in cxx11
    // provide << and sc_trace()
    // need to overload == for derived class

    friend std::ostream& operator<<(std::ostream& out,PayloadBase& self){
        out<<"PayloadBase Type\n";
        return out;
    }

    inline friend void sc_trace(sc_core::sc_trace_file* f, const PayloadBase& payload, const std::string& name){

    }

};



#endif //UTILS_PAYLOADBASE_H_