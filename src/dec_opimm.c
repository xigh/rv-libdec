#include "dec.h"

void dec_opimm(int flags,rv_uint32_t w, inst_t *ir)
{
    ir->rd = extr_rd(w);
    ir->rs1 = extr_rs1(w);
    ir->imm.u = extr_i_imm(w);

   rv_uint8_t f6 = extr_f6(w);
   rv_uint8_t f3 = extr_f3(w);
    switch (f3)
    {
    case 0:
        ir->op = RV_ADDI;
        break;

    case 1:
        switch (f6)
        {
        case 0:
            ir->op = RV_SLLI;
            ir->imm.u &= (flags & EXT_64) ? 0x3f : 0x1f;
            break;
        }
        break;

    case 2:
        ir->op = RV_SLTI;
        break;

    case 3:
        ir->op = RV_SLTIU;
        break;

    case 4:
        ir->op = RV_XORI;
        break;

    case 5:
        switch (f6)
        {
        case 0:
            ir->op = RV_SRLI;
            ir->imm.u &= (flags & EXT_64) ? 0x3f : 0x1f;
            break;

        case 16:
            ir->op = RV_SRAI;
            ir->imm.u &= (flags & EXT_64) ? 0x3f : 0x1f;
            break;
        }
        break;

    case 6:
        ir->op = RV_ORI;
        break;

    case 7:
        ir->op = RV_ANDI;
        break;
    }
}
