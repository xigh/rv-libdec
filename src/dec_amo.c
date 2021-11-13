#include "dec.h"

void dec_amo(int flags,rv_uint32_t w, inst_t *ir)
{
   rv_uint8_t f3 = extr_f3(w);
    ir->rd = extr_rd(w);
    ir->rs1 = extr_rs1(w);
    ir->rs2 = extr_rs2(w);
    ir->mod = extr_f2(w);

   rv_uint8_t f5 = extr_f5(w);
    switch (f5)
    {
    case 0:
        switch (f3)
        {
        case 2:
            ir->op = RV_AMOADD_W;
            break;

        case 3:
            if (flags & EXT_64)
            {
                ir->op = RV_AMOADD_D;
                break;
            }
            break;
        }
        break;

    case 1:
        switch (f3)
        {
        case 2:
            ir->op = RV_AMOSWAP_W;
            break;

        case 3:
            if (flags & EXT_64)
            {
                ir->op = RV_AMOSWAP_D;
                break;
            }
            break;
        }
        break;

    case 2:
        if (ir->rs2 != 0)
        {
            break;
        }

        switch (f3)
        {
        case 2:
            ir->op = RV_LR_W;
            break;

        case 3:
            if (flags & EXT_64)
            {
                ir->op = RV_LR_D;
                break;
            }
            break;
        }
        break;

    case 3:
        switch (f3)
        {
        case 2:
            ir->op = RV_SC_W;
            break;

        case 3:
            if (flags & EXT_64)
            {
                ir->op = RV_SC_D;
                break;
            }
            break;
        }
        break;

    case 4:
        switch (f3)
        {
        case 2:
            ir->op = RV_AMOXOR_W;
            break;

        case 3:
            if (flags & EXT_64)
            {
                ir->op = RV_AMOXOR_D;
                break;
            }
            break;
        }
        break;

    case 8:
        switch (f3)
        {
        case 2:
            ir->op = RV_AMOOR_W;
            break;

        case 3:
            if (flags & EXT_64)
            {
                ir->op = RV_AMOOR_D;
                break;
            }
            break;
        }
        break;

    case 0x0c:
        switch (f3)
        {
        case 2:
            ir->op = RV_AMOAND_W;
            break;

        case 3:
            if (flags & EXT_64)
            {
                ir->op = RV_AMOAND_D;
                break;
            }
            break;
        }
        break;

    case 0x10:
        switch (f3)
        {
        case 2:
            ir->op = RV_AMOMIN_W;
            break;

        case 3:
            if (flags & EXT_64)
            {
                ir->op = RV_AMOMIN_D;
                break;
            }
            break;
        }
        break;

    case 0x14:
        switch (f3)
        {
        case 2:
            ir->op = RV_AMOMAX_W;
            break;

        case 3:
            if (flags & EXT_64)
            {
                ir->op = RV_AMOMAX_D;
                break;
            }
            break;
        }
        break;

    case 0x18:
        switch (f3)
        {
        case 2:
            ir->op = RV_AMOMINU_W;
            break;

        case 3:
            if (flags & EXT_64)
            {
                ir->op = RV_AMOMINU_D;
                break;
            }
            break;
        }
        break;

    case 0x1c:
        switch (f3)
        {
        case 2:
            ir->op = RV_AMOMAXU_W;
            break;

        case 3:
            if (flags & EXT_64)
            {
                ir->op = RV_AMOMAXU_D;
                break;
            }
            break;
        }
        break;
    }
}
