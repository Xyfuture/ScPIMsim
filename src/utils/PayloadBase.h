//
// Created by xyfuture on 2023/3/1.
//



#ifndef UTILS_PAYLOADBASE_H_
#define UTILS_PAYLOADBASE_H_
#include <string>
#include <systemc>


struct PayloadBase {

    PayloadBase() ;
    ~PayloadBase() ;

    virtual std::string getContent() = 0;

    friend std::ostream& operator<<(std::ostream& ,PayloadBase&);

    // overload =,==,<< and sc_trace()
    // use default =,== is enough for most case
    // sc_trace() only when you use trace file
    inline friend void sc_trace(sc_core::sc_trace_file* f, const PayloadBase& payload, const std::string& name){

    }

};



#endif //UTILS_PAYLOADBASE_H_