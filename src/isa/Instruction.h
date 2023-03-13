//
// Created by xyfuture on 2023/3/1.
//


#pragma once
#ifndef INST_INSTRUCTION_H_
#define INST_INSTRUCTION_H_

#include <memory>

#include "isa/ISA.h"

#define RD_SELECT 1
#define RS1_SELECT 2
#define RS2_SELECT 4


struct OffsetField{
    int offset_value = 0;
    int offset_select = 0;
    // select function

    int getRdOffset(){
        if (offset_select & RD_SELECT)
            return offset_value;
        return 0;
    }

    int getRs1Offset(){
        if (offset_value & RS1_SELECT)
            return offset_value;
        return 0;
    }

    int getRs2Offset(){
        if (offset_value & RS2_SELECT)
            return offset_value;
        return 0;
    }
};


struct VectorField{
    int len = 0;
    OffsetField offset = {0,0};
};

struct MatrixField{
    int mbiw = 0;
    int group = 0;

    int relu = 0;
};

struct ScalarField{
    int imm = 0;
    int offset_value = 0; // byte
};

struct TransferField{
    int size = 0;
    int imm = 0;
    int core = 0; // send/recv/sync
    OffsetField offset = {0,0}; // byte

    int wait_value = 0;
    int event_register = 0;
};

struct Instruction {
    // Common field
    Opcode op = Opcode::nop;
    int rs1_addr = 0;
    int rs2_addr = 0;
    int rd_addr = 0;

    // vector field
    std::shared_ptr<VectorField> vector = nullptr;
    // matrix field
    std::shared_ptr<MatrixField> matrix = nullptr;
    // scalar field
    std::shared_ptr<ScalarField> scalar = nullptr;
    // transfer field
    std::shared_ptr<TransferField> transfer = nullptr;
};


#endif //INST_INSTRUCTION_H_
