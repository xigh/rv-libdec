#include "dec.h"

void dec_op(int flags,rv_uint32_t w, inst_t *ir)
{
    ir->rd = extr_rd(w);
    ir->rs1 = extr_rs1(w);
    ir->rs2 = extr_rs2(w);
   rv_uint8_t f7 = extr_f7(w);

   rv_uint8_t f3 = extr_f3(w);
    switch (f3)
    {
    case 0:
        switch (f7)
        {
        case 0:
            ir->op = RV_ADD;
            break;

        case 1:
            if (flags & EXT_M)
            {
                ir->op = RV_MUL;
                break;
            }
            break;

        case 32:
            ir->op = RV_SUB;
            break;
        }
        break;

    case 1:
        switch (f7)
        {
        case 0:
            ir->op = RV_SLL;
            break;

        case 1:
            if (flags & EXT_M)
            {
                ir->op = RV_MULH;
                break;
            }
            break;
        }
        break;

    case 2:
        switch (f7)
        {
        case 0:
            ir->op = RV_SLT;
            break;

        case 1:
            if (flags & EXT_M)
            {
                ir->op = RV_MULHSU;
                break;
            }
            break;
        }
        break;

    case 3:
        switch (f7)
        {
        case 0:
            ir->op = RV_SLTU;
            break;

        case 1:
            if (flags & EXT_M)
            {
                ir->op = RV_MULHU;
                break;
            }
            break;
        }
        break;

    case 4:
        switch (f7)
        {
        case 0:
            ir->op = RV_XOR;
            break;

        case 1:
            if (flags & EXT_M)
            {
                ir->op = RV_DIV;
                break;
            }
            break;
        }
        break;

    case 5:
        switch (f7)
        {
        case 0:
            ir->op = RV_SRL;
            break;

        case 1:
            if (flags & EXT_M)
            {
                ir->op = RV_DIVU;
                break;
            }
            break;

        case 32:
            ir->op = RV_SRA;
            break;
        }
        break;

    case 6:
        switch (f7)
        {
        case 0:
            ir->op = RV_OR;
            break;

        case 1:
            if (flags & EXT_M)
            {
                ir->op = RV_REM;
                break;
            }
            break;
        }
        break;

    case 7:
        switch (f7)
        {
        case 0:
            ir->op = RV_AND;
            break;

        case 1:
            if (flags & EXT_M)
            {
                ir->op = RV_REMU;
                break;
            }
            break;
        }
        break;
    }
}
