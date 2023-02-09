#pragma once

#include <stdint.h>
#include <stdbool.h>

#include "platform.h"

#define FLAGS_ZERO (1 << 7)
#define FLAGS_NEGATIVE (1 << 6)
#define FLAGS_HALFCARRY (1 << 5)
#define FLAGS_CARRY (1 << 4)

#define FLAGS_ISZERO (registers.f & FLAGS_ZERO)
#define FLAGS_ISNEGATIVE (registers.f & FLAGS_NEGATIVE)
#define FLAGS_ISCARRY (registers.f & FLAGS_CARRY)
#define FLAGS_ISHALFCARRY (registers.f & FLAGS_HALFCARRY)

#define FLAGS_ISSET(x) (registers.f & (x))
#define FLAGS_SET(x) (registers.f |= (x))
#define FLAGS_CLEAR(x) (registers.f &= ~(x))

#define CPU_CLOCKSPEED 4194304;

unsigned short cpu_get_combined_registers(unsigned char high, unsigned char low);
unsigned char cpu_compile_flag_register();
void cpu_set_combined_registers(unsigned char high, unsigned char low);
void cpu_emulate();
void cpu_reset();
void cpu_unimplemented_instruction();

struct cpu {
    bool stopped;
    float emulation_speed;
    int ticks;
    bool flag_zero;
    bool flag_subtract;
    bool flag_half_carry;
    bool flag_carry;
    unsigned short last_instruction;
} extern cpu;

struct cpu_instruction {
    char mnemonic[20];
    unsigned char length;
    int cycles;
    void *function;
};

void nop();

void ldd_hlp_a();

void ld_bc_nn(unsigned short operand);
void ld_de_nn(unsigned short operand);
void ld_hl_nn(unsigned short operand);

void ld_hlp_n(unsigned char operand);
void ld_nnp_a(unsigned short operand);
void ld_a_nnp(unsigned short operand);

void ld_sp_nn(unsigned short operand);

void ldi_a_hlp();
void ldi_hlp_a();

void ld_a_dep();

void ld_a_hlp();
void ld_b_hlp();
void ld_c_hlp();
void ld_d_hlp();
void ld_e_hlp();
void ld_h_hlp();
void ld_l_hlp();

void ld_a_b();
void ld_a_c();
void ld_a_d();
void ld_a_e();
void ld_a_h();
void ld_a_l();

void ld_b_a();
void ld_b_c();
void ld_b_d();
void ld_b_e();
void ld_b_h();
void ld_b_l();

void ld_c_a();
void ld_c_b();
void ld_c_d();
void ld_c_e();
void ld_c_h();
void ld_c_l();

void ld_d_a();
void ld_d_b();
void ld_d_c();
void ld_d_e();
void ld_d_h();
void ld_d_l();

void ld_e_a();
void ld_e_b();
void ld_e_c();
void ld_e_d();
void ld_e_h();
void ld_e_l();

void ld_h_a();
void ld_h_b();
void ld_h_c();
void ld_h_d();
void ld_h_e();
void ld_h_l();

void ld_l_a();
void ld_l_b();
void ld_l_c();
void ld_l_d();
void ld_l_e();
void ld_l_h();

void ld_bcp_a();
void ld_dep_a();
void ld_hlp_a();

void ld_a_n(unsigned char operand);
void ld_b_n(unsigned char operand);
void ld_c_n(unsigned char operand);
void ld_d_n(unsigned char operand);
void ld_e_n(unsigned char operand);
void ld_h_n(unsigned char operand);
void ld_l_n(unsigned char operand);

void ld_ff_ap_n(unsigned char operand);
void ld_ff_n_ap(unsigned char operand);
void ld_ff_c_a();

void jp_nn(unsigned short operand);
void jp_hl();
void jr_nz_n(unsigned char operand);
void jr_z_n(unsigned char operand);
void jp_z_nn(unsigned short operand);

void rst_1();
void rst_5();
void rst_7();

void inc_a();
void inc_b();
void inc_c();
void inc_d();
void inc_e();
void inc_h();
void inc_l();
void inc_bc();
void inc_de();
void inc_hl();
void inc_sp();
void inc_hlp();

void dec_a();
void dec_b();
void dec_c();
void dec_d();
void dec_e();
void dec_h();
void dec_l();

void dec_bc();
void dec_de();
void dec_hl();
void dec_sp();
void dec_hlp();

void call_nn(unsigned short operand);

void add_a_a();
void add_a_b();
void add_a_c();
void add_a_d();
void add_a_e();
void add_a_h();
void add_a_l();

void add_hl_de();
void sub_n(unsigned char operand);

void ccf();
void ret();
void ret_nz();
void ret_c();
void ret_nc();
void ret_z();

void xor_a();
void xor_b();
void xor_c();
void xor_d();
void xor_e();
void xor_h();
void xor_l();

void or_a();
void or_b();
void or_c();
void or_d();
void or_e();
void or_h();
void or_l();

void ei();
void di_inst();

void cp_n(unsigned char operand);

void push_af();
void push_bc();
void push_de();
void push_hl();

void pop_af();
void pop_bc();
void pop_de();
void pop_hl();

void and_a();
void and_b();
void and_c();
void and_d();
void and_e();
void and_h();
void and_l();
void and_n(unsigned char operand);

void cpl();
void scf();