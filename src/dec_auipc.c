#include "dec.h"

void dec_auipc(int flags,rv_uint32_t w, inst_t *ir)
{
    UNUSED(flags);

    ir->op = RV_AUIPC;
    ir->rd = extr_rd(w);
    ir->imm.u = (extr_u_imm(w) >> 12) & 0xfffff;
}
