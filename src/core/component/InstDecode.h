//
// Created by xyfuture on 2023/3/6.
//



#ifndef CORE_COMPONENT_INSTDECODE_H_
#define CORE_COMPONENT_INSTDECODE_H_

#include <systemc>

#include "config/Config.hpp"
#include "isa/Instruction.h"
#include "utils/Register.hpp"
#include "core/payloads/StagePayloads.hpp"

using namespace sc_core;


class InstDecode: public sc_module{
    SC_HAS_PROCESS(InstDecode);
public:
    InstDecode(const sc_module_name& name,const CoreConfig& config);

    void readRegFile();
    void decodeInst();
    void checkStall();

    void bitwidthUpdate();

private:
    const CoreConfig& config;

private:
    RegEnable<DecodeInfo> decode_reg;

    sc_signal<DecodeInfo> decode_reg_out;

private:
    RegNext<BitwidthInfo> bitwidth_reg;
    sc_signal<BitwidthInfo> bitwidth_reg_in;
    sc_signal<BitwidthInfo> bitwidth_reg_out;

public:
    sc_in<bool> id_enable;
    sc_out<bool> id_stall;

    sc_in<DecodeInfo> if_id_port;
    sc_out<JumpInfo> jump_port;

    sc_out<ScalarInfo> id_scalar_port;
    sc_out<MatrixInfo> id_matrix_port;
    sc_out<VectorInfo> id_vector_port;
    sc_out<TransferInfo> id_transfer_port;

    sc_out<RegFileReadAddr> reg_file_read_addr_port;
    sc_in<RegFileReadValue> reg_file_read_value_port;


    sc_in<bool> matrix_busy_port;
    sc_in<bool> vector_busy_port;
    sc_in<bool> transfer_busy_port;

    sc_out<BitwidthInfo> bitwidth_port;

};


#endif //CORE_COMPONENT_INSTDECODE_H_
