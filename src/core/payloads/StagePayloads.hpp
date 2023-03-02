//
// Created by xyfuture on 2023/3/1.
//

#pragma once

#include "utils/PayloadBase.h"
#include "isa/Instruction.h"
#include "isa/ISA.h"


struct DecodeInfo:public PayloadBase{
    DecodeInfo();
    ~DecodeInfo();

    int pc = -1;
    Instruction inst;

};

struct ScalarInfo:public PayloadBase{

    ScalarInfo();
    ~ScalarInfo();

    int pc = -1 ;
    Opcode op ;

    int rs1_data = 0;
    int rs2_data = 0;

    int rd_addr = 0;
};


struct VectorInfo:public PayloadBase{
    VectorInfo();
    ~VectorInfo();

    int pc = -1;
    Opcode op;

    //
};

struct MatrixInfo:public PayloadBase{
    MatrixInfo();
    ~MatrixInfo();

    int pc = -1;
    Opcode op;

    //

};

struct TransferInfo:public PayloadBase{
    TransferInfo();
    ~TransferInfo();

    int pc = -1;
    //
};