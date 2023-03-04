//
// Created by xyfuture on 2023/3/2.
//


#ifndef ISA_ISA_H_
#define ISA_ISA_H_

#include "better-enums/enum.h"

BETTER_ENUM(Opcode,int,
            sldi,sld,sadd,ssub,smul,saddi,smuli,
            setbw,
            mvmul,
            vvadd,vvsub,vvmul,vvdmul,
            vvmax,vvsll,vvsra,vavg,
            vrelu,vtanh,vsigm,
            vmv,
            vrsu,vrsl,
            ld,st,lldi,lmv,
            send,recv,wait,sync,
            nop); // add nop

auto to_op = Opcode::_from_string;

#endif //ISA_ISA_H_
