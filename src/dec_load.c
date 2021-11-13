#include "dec.h"

void dec_load(int flags,rv_uint32_t w, inst_t *ir)
{
    ir->rd = extr_rd(w);
    ir->rs1 = extr_rs1(w);
    ir->imm.u = extr_i_imm(w);

   rv_uint8_t f3 = extr_f3(w);
    switch (f3)
    {
    case 0:
        ir->op = RV_LB;
        break;

    case 1:
        ir->op = RV_LH;
        break;

    case 2:
        ir->op = RV_LW;
        break;

    case 3:
        if (flags & EXT_64)
        {
            ir->op = RV_LD;
            break;
        }
        break;

    case 4:
        ir->op = RV_LBU;
        break;

    case 5:
        ir->op = RV_LHU;
        break;

    case 6:
        if (flags & EXT_64)
        {
            ir->op = RV_LWU;
            break;
        }
        break;

    case 7:
        break;
    }
}
