//
// Created by xyfuture on 2023/3/4.
//



#ifndef UTILS_REGISTER_H_
#define UTILS_REGISTER_H_

#include <systemc>

using namespace sc_core;


// 使用特殊的寄存器模拟时钟的效果


template<typename T>
class Register:public sc_module {
public:
    SC_HAS_PROCESS(Register);

    Register(const sc_module_name& name):sc_module(name){
        SC_METHOD(update);
        sensitive<<clk.posedge_event();
    }

    void update(){
        if(clk.posedge()){
            value = input.read();
            output.write(value);
        }
    }

private:
    T value ;

    sc_in<T> input;
    sc_in<bool> clk; // use buffer instead signal as channel !
    sc_out<T> output;
};




template<typename T>
class RegNext:public sc_module{
public:
    SC_HAS_PROCESS(RegNext);

    RegNext(const sc_module_name& name,double period)
    :sc_module(name),period(period){

        SC_METHOD(processInput);
        sensitive<<input;

        SC_METHOD(update);
        sensitive<<trigger;

    }

    void processInput(){
        next_value = input.read();

        if (next_value != value)
            trigger.notify(period,sc_core::SC_NS);
//        else
//            trigger.cancel();
    }

    void update(){
        if (next_value != value){
            value = next_value;
            output.write(value);
        }
    }
private:
    double period;

    T next_value;
    T value;
    sc_event trigger;

public:
    sc_in<T> input;
    sc_out<T> output;
};



template<typename T>
class RegEnable:public sc_module{
public:
    SC_HAS_PROCESS(RegEnable);

    RegEnable(const sc_module_name& name,double period )
    :sc_module(name),period(period){
        SC_METHOD(processInput);
        sensitive<<input;
        SC_METHOD(processEnable);
        sensitive<<enable;

        SC_METHOD(update);
        sensitive<<trigger;

    }

    void processInput(){
        next_value = input.read();
        if (next_value != value )
            trigger.notify(period,SC_NS);

    }

    void processEnable(){
        if (enable.read())
            trigger.notify(period,sc_core::SC_NS);
    }

    void update(){
        if (enable.read()){
            if (next_value != value){
                value = next_value;
                output.write(value);
            }
        }
    }

private:
    double period;

    T next_value;
    T value;

    sc_event trigger;

public:
    sc_in<T> input;
    sc_in<bool> enable;
    sc_out<T> output;
};





#endif //UTILS_REGISTER_H_
