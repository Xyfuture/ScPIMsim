//
// Created by xyfuture on 2023/3/1.
//


#pragma once
#ifndef INST_INSTRUCTION_H_
#define INST_INSTRUCTION_H_

#include <memory>

#include "isa/ISA.h"

struct OffsetField{
    int offset_value ;
    int offset_select ;
    // select function
};


struct VectorField{

};


struct Instruction {
    // Common field

    int rs1_addr = 0;
    int rs2_addr = 0;
    int rd_addr = 0;

    // vector field
    std::unique_ptr<VectorField> vecl

};


#endif //INST_INSTRUCTION_H_
