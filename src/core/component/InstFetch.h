//
// Created by xyfuture on 2023/2/28.
//



#ifndef CORE_COMPONENT_INSTFETCH_H_
#define CORE_COMPONENT_INSTFETCH_H_

#include <systemc>

using namespace sc_core;

class InstFetch: public sc_module  {
    SC_HAS_PROCESS(InstFetch);
public:
    InstFetch(sc_module_name name);

};



#endif //CORE_COMPONENT_INSTFETCH_H_
