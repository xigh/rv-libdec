#include "dec.h"

void dec_storefp(int flags,rv_uint32_t w, inst_t *ir)
{
    ir->rs1 = extr_rs1(w);
    ir->rs2 = extr_rs2(w);
    ir->imm.u = extr_s_imm(w);

   rv_uint32_t f3 = extr_f3(w);
    switch (f3)
    {
    case 0:
        break;

    case 1:
        if (flags & EXT_H)
        {
            ir->op = RV_FSH;
            break;
        }
        break;

    case 2:
        if (flags & EXT_F)
        {
            ir->op = RV_FSW;
            break;
        }
        break;

    case 3:
        if (flags & EXT_D)
        {
            ir->op = RV_FSD;
            break;
        }
        break;

    case 4:
        if (flags & EXT_Q)
        {
            ir->op = RV_FSQ;
            break;
        }
        break;

    case 5:
        break;

    case 6:
        break;

    case 7:
        break;
    }
}
