#include "dec.h"

rv_uint8_t c_reg(rv_uint64_t rp)
{
    return (rv_uint8_t)(rp + 8);
}

void dec_compr(int flags, rv_uint32_t w, inst_t *ir)
{
    int q = w & 3;           // quadrant (2 bits)
    int o = (w >> 13) & 0x7; // opcode (3 bits)
    // int t = 0;
    rv_uint64_t r;

    switch (q)
    {
    case 0:
        switch (o)
        {
        case 0:
            if (w == 0)
            {
                ir->op = RV_C_UNIMP;
                return;
            }
            ir->op = RV_C_ADDI4SPN;
            ir->rd = c_reg(extr(w, 2, 3));
            ir->imm.u =
                extr(w, 6, 1) << 2 |
                extr(w, 5, 1) << 3 |
                extr(w, 7, 4) << 6 |
                extr(w, 11, 2) << 4;
            break;

        case 1:
            if ((flags & EXT_128) == EXT_128)
            {
                ir->op = RV_C_LQ;
                ir->rd = c_reg(extr(w, 2, 3));
                ir->rs1 = c_reg(extr(w, 7, 3));
                ir->imm.u =
                    extr(w, 5, 2) << 6 |
                    extr(w, 10, 1) << 8 |
                    extr(w, 11, 2) << 3;
                return;
            }
            ir->op = RV_C_FLD;
            ir->rd = c_reg(extr(w, 2, 3));
            ir->rs1 = c_reg(extr(w, 7, 3));
            ir->imm.u =
                extr(w, 5, 2) << 6 |
                extr(w, 10, 3) << 3;
            break;

        case 2:
            ir->op = RV_C_LW;
            ir->rd = c_reg(extr(w, 2, 3));
            ir->rs1 = c_reg(extr(w, 7, 3));
            ir->imm.u =
                extr(w, 5, 1) << 6 |
                extr(w, 6, 1) << 2 |
                extr(w, 10, 3) << 3;
            break;

        case 3:
            if (flags & (EXT_64 | EXT_128))
            {
                ir->op = RV_C_LD;
                ir->rd = c_reg(extr(w, 2, 3));
                ir->rs1 = c_reg(extr(w, 7, 3));
                ir->imm.u =
                    extr(w, 5, 2) << 6 |
                    extr(w, 10, 3) << 3;
                break;
            }
            ir->op = RV_C_FLW;
            ir->rd = c_reg(extr(w, 2, 3));
            ir->rs1 = c_reg(extr(w, 7, 3));
            ir->imm.u =
                extr(w, 5, 1) << 6 |
                extr(w, 6, 1) << 2 |
                extr(w, 10, 3) << 3;
            break;

        case 4:
            // reserved
            break;

        case 5:
            if ((flags & EXT_128) == EXT_128)
            {
                ir->op = RV_C_SQ;
                ir->rs2 = c_reg(extr(w, 2, 3));
                ir->rs1 = c_reg(extr(w, 7, 3));
                ir->imm.u =
                    extr(w, 5, 2) << 6 |
                    extr(w, 10, 1) << 8 |
                    extr(w, 11, 2) << 3;
                break;
            }
            ir->op = RV_C_FSD;
            ir->rs2 = c_reg(extr(w, 2, 3));
            ir->rs1 = c_reg(extr(w, 7, 3));
            ir->imm.u =
                extr(w, 5, 2) << 6 |
                extr(w, 10, 3) << 3;
            break;

        case 6:
            ir->op = RV_C_SW;
            ir->rd = c_reg(extr(w, 2, 3));
            ir->rs1 = c_reg(extr(w, 7, 3));
            ir->imm.u =
                extr(w, 5, 1) << 6 |
                extr(w, 6, 1) << 2 |
                extr(w, 10, 3) << 3;
            break;

        case 7:
            if (flags & (EXT_64 | EXT_128))
            {
                ir->op = RV_C_SD;
                ir->rs2 = c_reg(extr(w, 2, 3));
                ir->rs1 = c_reg(extr(w, 7, 3));
                ir->imm.u =
                    extr(w, 5, 2) << 6 |
                    extr(w, 10, 3) << 3;
                break;
            }
            ir->op = RV_C_FSW;
            ir->rs2 = c_reg(extr(w, 2, 3));
            ir->rs1 = c_reg(extr(w, 7, 3));
            ir->imm.u =
                extr(w, 5, 1) << 6 |
                extr(w, 6, 1) << 2 |
                extr(w, 10, 3) << 3;
            break;
        }
        break;

    case 1:
        switch (o)
        {
        case 0:
            ir->imm.u =
                extr(w, 2, 5) << 0 |
                (extr(w, 12, 1) ? ~0ull : 0) << 5;
            r = extr(w, 7, 5);
            if (r == 0)
            {
                ir->op = RV_C_NOP;
                break;
            }
            ir->op = RV_C_ADDI;
            ir->rd = (rv_uint8_t)r;
            ir->rs1 = (rv_uint8_t)r;
            break;

        case 1:
            if (flags & (EXT_64 | EXT_128))
            {
                ir->op = RV_C_ADDIW;
                break;
            }
            ir->op = RV_C_JAL;
            ir->imm.u = 
                extr(w, 2, 1) << 5 |
                extr(w, 3, 3) << 1 |
                extr(w, 6, 1) << 7 |
                extr(w, 7, 1) << 6 |
                extr(w, 8, 1) << 10 |
                extr(w, 9, 2) << 8 |
                extr(w, 11, 1) << 4 |
                (extr(w, 12, 1) ? ~0ull : 0) << 11;
            break;

        case 2:
            ir->op = RV_C_LI;
            ir->rd = (rv_uint8_t)extr(w, 7, 5);
            ir->imm.u = 
                extr(w, 2, 5) << 0 |
                (extr(w, 12, 1) ? ~0ull : 0) << 5;
            break;

        case 3:
            // C.ADDI16SP
            ir->op = RV_C_LUI;
            break;

        case 4:
            // C.SRLI
            // C.SRLI64
            // C.SRAI
            // C.SRAI64
            // C.ANDI
            // C.SUB
            // C.XOR
            // C.OR
            // C.AND
            // C.SUBW
            // C.ADDW
            // reserved
            // reserved
            break;

        case 5:
            ir->op = RV_C_J;
            break;

        case 6:
            ir->op = RV_C_BEQZ;
            break;

        case 7:
            ir->op = RV_C_BNEZ;
            break;
        }
        break;

    case 2:
        switch (o)
        {
        case 0:
            // C.SLLI
            ir->op = RV_C_SLLI64;
            break;

        case 1:
            // C.FLDSP
            ir->op = RV_C_LQSP;
            break;

        case 2:
            ir->op = RV_C_LWSP;
            break;

        case 3:
            // C.FLWSP
            ir->op = RV_C_LDSP;
            break;

        case 4:
            // C.JR
            // C.MV
            // C.EBREAK
            // C.JALR
            ir->op = RV_C_ADD;
            break;

        case 5:
            // C.FSDSP
            ir->op = RV_C_SQSP;
            break;

        case 6:
            ir->op = RV_C_SWSP;
            break;

        case 7:
            // C.FSWSP
            ir->op = RV_C_SDSP;
            break;
        }
        break;
    }
}
