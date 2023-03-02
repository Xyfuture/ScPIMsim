//
// Created by xyfuture on 2023/3/1.
//



#ifndef INST_INSTRUCTION_H_
#define INST_INSTRUCTION_H_


class Instruction {
public:
    Instruction();
    ~Instruction();

    int rs1_addr = 0;
    int rs2_addr = 0;
    int rd_addr = 0;

};


#endif //INST_INSTRUCTION_H_
