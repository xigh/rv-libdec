#include "dec.h"

void dec_op32(int flags,rv_uint32_t w, inst_t *ir)
{
    if ((flags & EXT_64) == 0)
    {
        return;
    }

    ir->rd = extr_rd(w);
    ir->rs1 = extr_rs1(w);
    ir->imm.u = extr_i_imm(w);
   rv_uint8_t f7 = extr_f7(w);
   rv_uint8_t f3 = extr_f3(w);
    switch (f3)
    {
    case 0:
        switch (f7)
        {
        case 0:
            ir->op = RV_ADDW;
            break;

        case 1:
            if (flags & EXT_M)
            {
                ir->op = RV_MULW;
                break;
            }
            break;

        case 32:
            ir->op = RV_SUBW;
            break;
        }
        break;

    case 1:
        switch (f7)
        {
        case 0:
            ir->op = RV_SLLW;
            break;
        }
        break;

    case 2:
        break;

    case 3:
        break;

    case 4:
        switch (f7)
        {
        case 1:
            if (flags & EXT_M)
            {
                ir->op = RV_DIVW;
                break;
            }
            break;
        }
        break;

    case 5:
        switch (f7)
        {
        case 0:
            ir->op = RV_SRLW;
            break;

        case 1:
            if (flags & EXT_M)
            {
                ir->op = RV_DIVUW;
                break;
            }
            break;

        case 32:
            ir->op = RV_SRAW;
            break;
        }
        break;

    case 6:
        switch (f7)
        {
        case 1:
            if (flags & EXT_M)
            {
                ir->op = RV_REMW;
                break;
            }
            break;
        }
        break;

    case 7:
        switch (f7)
        {
        case 1:
            if (flags & EXT_M)
            {
                ir->op = RV_REMUW;
                break;
            }
            break;
        }
        break;
    }
}
