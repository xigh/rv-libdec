#include "dec.h"

void dec_store(int flags,rv_uint32_t w, inst_t *ir)
{
    ir->rs1 = extr_rs1(w);
    ir->rs2 = extr_rs2(w);
    ir->imm.u = extr_s_imm(w);

   rv_uint32_t f3 = extr_f3(w);
    switch (f3)
    {
    case 0:
        ir->op = RV_SB;
        break;

    case 1:
        ir->op = RV_SH;
        break;

    case 2:
        ir->op = RV_SW;
        break;

    case 3:
        if (flags & EXT_64)
        {
            ir->op = RV_SD;
            break;
        }
        break;

    case 4:
        break;

    case 5:
        break;

    case 6:
        break;

    case 7:
        break;
    }
}
