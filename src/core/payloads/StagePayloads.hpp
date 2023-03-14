//
// Created by xyfuture on 2023/3/1.
//

#pragma once

#include <string>
#include <systemc>
#include "isa/Instruction.h"
#include "isa/ISA.h"


#define MAKE_SIGNAL_TYPE_TRACE_STREAM(CLASS_NAME) \
friend std::ostream& operator<<(std::ostream& out,const CLASS_NAME & self ) { \
    out<<" "#CLASS_NAME" Type\n";             \
    return out;                           \
}                                         \
inline friend void sc_trace(sc_core::sc_trace_file* f, const CLASS_NAME& self,const std::string& name){}


struct JumpInfo{
    MAKE_SIGNAL_TYPE_TRACE_STREAM(JumpInfo)

    bool is_jump = false;
    int offset=0;

};

struct DecodeInfo{
    MAKE_SIGNAL_TYPE_TRACE_STREAM(DecodeInfo)

    int pc = -1;
    Instruction inst=Instruction();

    bool operator==(const DecodeInfo& ano) const{
        return ano.pc == pc;
    }

};


struct ScalarInfo {
    MAKE_SIGNAL_TYPE_TRACE_STREAM(ScalarInfo)

    int pc = -1 ;
    Opcode op = Opcode::nop ;

    int rs1_data = 0;
    int rs2_data = 0;
    int imm = 0;

    int rd_addr = 0;

    bool operator==(const ScalarInfo& ano) const{
        return ano.pc == pc;
    }
};


struct VectorInfo{
    MAKE_SIGNAL_TYPE_TRACE_STREAM(VectorInfo)

    int pc = -1;
    Opcode op = Opcode::nop;

    //


    bool operator==(const VectorInfo& ano) const{
        return ano.pc == pc;
    }

};

struct MatrixInfo{
    MAKE_SIGNAL_TYPE_TRACE_STREAM(MatrixInfo)
    int pc = -1;
    Opcode op = Opcode::nop;

    //

    bool operator==(const MatrixInfo& ano) const{
        return ano.pc == pc;
    }

};

struct TransferInfo{
    MAKE_SIGNAL_TYPE_TRACE_STREAM(TransferInfo)

    int pc = -1;
    Opcode op = Opcode::nop;
    //


    bool operator==(const TransferInfo& ano) const{
        return ano.pc == pc;
    }

};



struct RegFileReadAddr{
    MAKE_SIGNAL_TYPE_TRACE_STREAM(RegFileReadAddr)

    int rd_addr = 0;
    int rs1_addr = 0;
    int rs2_addr = 0;

    bool operator == (const RegFileReadAddr& ano) const{
        return rd_addr == ano.rd_addr &&
                rs1_addr == ano.rs1_addr &&
                rs2_addr == ano.rs2_addr ;
    }
};

struct RegFileReadValue{
    MAKE_SIGNAL_TYPE_TRACE_STREAM(RegFileReadValue)

    int rd_value = 0;
    int rs1_value = 0;
    int rs2_value = 0;

    bool operator == (const RegFileReadValue& ano) const{
        return rd_value == ano.rd_value &&
               rs1_value == ano.rs1_value &&
               rs2_value == ano.rs2_value ;
    }
};

struct RegFileWrite{
    MAKE_SIGNAL_TYPE_TRACE_STREAM(RegFileWrite)

    int rd_addr = 0;
    int rd_value = 0;

    bool operator == (const RegFileWrite& ano) const {
        return rd_addr == ano.rd_addr && rd_value == ano.rd_value;
    }
};


struct BitwidthInfo{
    MAKE_SIGNAL_TYPE_TRACE_STREAM(BitwidthInfo)

    int input_bitwidth = 8;
    int output_bitwidth = 8;

    bool operator == (const BitwidthInfo& ano) const{
        return input_bitwidth == ano.input_bitwidth && output_bitwidth==ano.output_bitwidth;
    }
};