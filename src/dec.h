#include "rv-dec.h"

#define UNUSED(x) (void)(x)

extern rv_uint64_t extr(rv_uint32_t w,int shr,int msh);

extern rv_uint64_t extr_i_imm(rv_uint32_t w);
extern rv_uint64_t extr_u_imm(rv_uint32_t w);
extern rv_uint64_t extr_uj_imm(rv_uint32_t w);
extern rv_uint64_t extr_s_imm(rv_uint32_t w);
extern rv_uint64_t extr_sb_imm(rv_uint32_t w);

extern rv_uint8_t extr_f2(rv_uint32_t w);
extern rv_uint8_t extr_f3(rv_uint32_t w);
extern rv_uint8_t extr_f5(rv_uint32_t w);
extern rv_uint8_t extr_f6(rv_uint32_t w);
extern rv_uint8_t extr_f7(rv_uint32_t w);

extern rv_uint8_t extr_op(rv_uint32_t w);
extern rv_uint8_t extr_rd(rv_uint32_t w);
extern rv_uint8_t extr_rs1(rv_uint32_t w);
extern rv_uint8_t extr_rs2(rv_uint32_t w);
extern rv_uint8_t extr_rs3(rv_uint32_t w);

extern void dec_compr(int flags,rv_uint32_t w, inst_t *ir);

extern void dec_load(int flags,rv_uint32_t w, inst_t *ir);
extern void dec_loadfp(int flags,rv_uint32_t w, inst_t *ir);
extern void dec_cust0(int flags,rv_uint32_t w, inst_t *ir);
extern void dec_misc(int flags,rv_uint32_t w, inst_t *ir);
extern void dec_opimm(int flags,rv_uint32_t w, inst_t *ir);
extern void dec_auipc(int flags,rv_uint32_t w, inst_t *ir);
extern void dec_opimm32(int flags,rv_uint32_t w, inst_t *ir);
extern void dec_store(int flags,rv_uint32_t w, inst_t *ir);
extern void dec_storefp(int flags,rv_uint32_t w, inst_t *ir);
extern void dec_cust1(int flags,rv_uint32_t w, inst_t *ir);
extern void dec_amo(int flags,rv_uint32_t w, inst_t *ir);
extern void dec_op(int flags,rv_uint32_t w, inst_t *ir);
extern void dec_lui(int flags,rv_uint32_t w, inst_t *ir);
extern void dec_op32(int flags,rv_uint32_t w, inst_t *ir);
extern void dec_fmadd(int flags,rv_uint32_t w, inst_t *ir);
extern void dec_fmsub(int flags,rv_uint32_t w, inst_t *ir);
extern void dec_fnmsub(int flags,rv_uint32_t w, inst_t *ir);
extern void dec_fnmadd(int flags,rv_uint32_t w, inst_t *ir);
extern void dec_opfp(int flags,rv_uint32_t w, inst_t *ir);
extern void dec_rsvd0(int flags,rv_uint32_t w, inst_t *ir);
extern void dec_cust2(int flags,rv_uint32_t w, inst_t *ir); // or rv128
extern void dec_branch(int flags,rv_uint32_t w, inst_t *ir);
extern void dec_jalr(int flags,rv_uint32_t w, inst_t *ir);
extern void dec_rsvd1(int flags,rv_uint32_t w, inst_t *ir);
extern void dec_jal(int flags,rv_uint32_t w, inst_t *ir);
extern void dec_sys(int flags,rv_uint32_t w, inst_t *ir);
extern void dec_rsvd2(int flags,rv_uint32_t w, inst_t *ir);
extern void dec_cust3(int flags,rv_uint32_t w, inst_t *ir); // or rv128

extern void dec_ext48a(int flags,rv_uint32_t w0,rv_uint64_t w1, inst_t *ir);
extern void dec_ext48b(int flags,rv_uint32_t w0,rv_uint64_t w1, inst_t *ir);
extern void dec_ext64(int flags,rv_uint32_t w0,rv_uint64_t w1, inst_t *ir);
extern void dec_ext80(int flags,rv_uint32_t w0,rv_uint64_t w1, inst_t *ir);
