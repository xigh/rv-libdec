#include "dec.h"

void dec_opimm32(int flags,rv_uint32_t w, inst_t *ir)
{
    if ((flags & EXT_64) == 0)
        return;

    ir->rd = extr_rd(w);
    ir->rs1 = extr_rs1(w);
    ir->imm.u = extr_i_imm(w);

   rv_uint8_t f6 = extr_f6(w);
   rv_uint32_t f3 = extr_f3(w);
    switch (f3)
    {
    case 0:
        ir->op = RV_ADDIW;
        break;

    case 1:
        switch (f6)
        {
        case 0:
            ir->op = RV_SLLIW;
            ir->imm.u &= 0x1f;
            break;
        }
        break;

    case 2:
        break;

    case 3:
        break;

    case 4:
        break;

    case 5:
        switch (f6)
        {
        case 0:
            ir->op = RV_SRLIW;
            ir->imm.u &= 0x1f;
            break;

        case 16:
            ir->op = RV_SRAIW;
            ir->imm.u &= 0x1f;
            break;
        }
        break;

    case 6:
        break;

    case 7:
        break;
    }
}
