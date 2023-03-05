//
// Created by xyfuture on 2023/3/1.
//

#pragma once

#include "utils/PayloadBase.h"
#include "isa/Instruction.h"
#include "isa/ISA.h"

#define GET_CONTENT()


struct JumpInfo:public PayloadBase{
    bool is_jump = false;
    int offset=0;

};

struct DecodeInfo: PayloadBase{

    int pc = -1;
    Instruction inst=Instruction();

    bool operator==(const DecodeInfo& ano) const{
        return ano.pc == pc;
    }
};

struct test:PayloadBase{
    test() = default;
    int a,b;
};



struct ScalarInfo:public PayloadBase{


    int pc = -1 ;
    Opcode op ;

    int rs1_data = 0;
    int rs2_data = 0;

    int rd_addr = 0;


    bool operator==(const ScalarInfo& ano) const{
        return ano.pc == pc;
    }
};


struct VectorInfo:public PayloadBase{

    int pc = -1;
    Opcode op;

    //


    bool operator==(const VectorInfo& ano) const{
        return ano.pc == pc;
    }

};

struct MatrixInfo:public PayloadBase{

    int pc = -1;
    Opcode op;

    //

    bool operator==(const MatrixInfo& ano) const{
        return ano.pc == pc;
    }

};

struct TransferInfo:public PayloadBase{

    int pc = -1;
    //


    bool operator==(const TransferInfo& ano) const{
        return ano.pc == pc;
    }

};