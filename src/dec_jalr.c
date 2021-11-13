#include "dec.h"

void dec_jalr(int flags,rv_uint32_t w, inst_t *ir)
{
    UNUSED(flags);

   rv_uint8_t f3 = extr_f3(w);
    switch (f3) {
    case 0:
        ir->rd = extr_rd(w);
        ir->rs1 = extr_rs1(w);
        ir->imm.u = extr_i_imm(w);
        ir->op = RV_JALR;
        return;
    }
}
