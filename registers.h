#include "systemc.h"

SC_MODULE(registers)
{
    //ports
    sc_in_clk ck;
    sc_in<sc_logic> reg_write;
    sc_in<sc_lv<5>> read_reg_1, read_reg_2, write_reg;
    sc_in<sc_lv<32>> write_data;
    sc_out<sc_lv<32>> read_data_1, read_data_2;

    //memory array
    sc_lv<32> reg_mem[32] = {  
                "00000000000000000000000000000000", // $zero
                "00000000000000000000000000000000", // mem 1
                "00000000000000000000000000000000",
                "00000000000000000000000000000000",
                "00000000000000000000000000000000",
                "00000000000000000000000000000000",
                "00000000000000000000000000000000",
                "00000000000000000000000000000000",
                "00000000000000000000000000000000", // test add
                "00000000000000000000000000000000", // test add
                "00000000000000000000000000000000", // mem 10 
                "00000000000000000000000000000000", 
                "00000000000000000000000000000000",
                "00000000000000000000000000000000",
                "00000000000000000000000000000000",
                "00000000000000000000000000000000",
                "00000000000000000000000000000000",
                "00000000000000000000000000000000",
                "00000000000000000000000000000000",
                "00000000000000000000000000000000",  
                "00000000000000000000000000000000", // mem 20
                "00000000000000000000000000000000",
                "00000000000000000000000000000000",
                "00000000000000000000000000000000",
                "00000000000000000000000000000000", 
                "00000000000000000000000000000000",
                "00000000000000000000000000000000",
                "00000000000000000000000000000000",
                "00000000000000000000000000000000",
                "00000000000000000000000000000000", 
                "00000000000000000000000000000000", // mem 30
                "00000000000000000000000000000000"
                };

    SC_CTOR(registers)
    {
        SC_METHOD(read);
        sensitive << read_reg_1 << read_reg_2;

        SC_METHOD(write);
        sensitive << ck.neg();
    }

    void read()
    {
        read_data_1.write(reg_mem[read_reg_1.read().to_uint()]);
        read_data_2.write(reg_mem[read_reg_2.read().to_uint()]);
    }

    void write()
    {
        reg_mem[write_reg.read().to_uint()] = write_data.read();
    }
};