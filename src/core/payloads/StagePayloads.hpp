//
// Created by xyfuture on 2023/3/1.
//

#pragma once

#include "utils/PayloadBase.h"
#include "isa/Instruction.h"
#include "isa/ISA.h"


struct DecodeInfo:public PayloadBase{

    int pc = -1;
    Instruction inst;

    std::string getContent(){
        return "";
    }
};

struct ScalarInfo:public PayloadBase{

    int pc = -1 ;
    Opcode op ;

    int rs1_data = 0;
    int rs2_data = 0;

    int rd_addr = 0;

    std::string getContent(){
        return "";
    }
};


struct VectorInfo:public PayloadBase{
    VectorInfo();
    ~VectorInfo();

    int pc = -1;
    Opcode op;

    //

    std::string getContent(){
        return "";
    }
};

struct MatrixInfo:public PayloadBase{
    MatrixInfo();
    ~MatrixInfo();

    int pc = -1;
    Opcode op;

    //


    std::string getContent(){
        return "";
    }
};

struct TransferInfo:public PayloadBase{
    TransferInfo();
    ~TransferInfo();

    int pc = -1;
    //

    std::string getContent(){
        return "";
    }
};