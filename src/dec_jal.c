#include "dec.h"

void dec_jal(int flags,rv_uint32_t w, inst_t *ir)
{
    UNUSED(flags);

    ir->op = RV_JAL;
    ir->rd = extr_rd(w);
    ir->imm.u = extr_uj_imm(w);
}
