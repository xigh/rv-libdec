#include "dec.h"

void dec_loadfp(int flags,rv_uint32_t w, inst_t *ir)
{
    ir->rd = extr_rd(w);
    ir->rs1 = extr_rs1(w);
    ir->imm.u = extr_i_imm(w);

   rv_uint8_t f3 = extr_f3(w);
    switch (f3)
    {
    case 1:
        if (flags & EXT_H)
        {
            ir->op = RV_FLH;
            break;
        }
        break;

    case 2:
        if (flags & EXT_F)
        {
            ir->op = RV_FLW;
            break;
        }
        break;

    case 3:
        if (flags & EXT_D)
        {
            ir->op = RV_FLD;
            break;
        }
        break;
    }
}
