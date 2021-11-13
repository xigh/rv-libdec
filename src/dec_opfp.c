#include "dec.h"

void dec_opfp(int flags,rv_uint32_t w, inst_t *ir)
{
    ir->rd = extr_rd(w);
    ir->rs1 = extr_rs1(w);
    ir->rs2 = extr_rs2(w);
    ir->mod = extr_f3(w);
   rv_uint8_t f7 = extr_f7(w);
    switch (f7)
    {
    case 0x00:
        if (flags & EXT_F)
        {
            ir->op = RV_FADD_S;
            break;
        }
        break;

    case 0x01:
        if (flags & EXT_D)
        {
            ir->op = RV_FADD_D;
            break;
        }
        break;

    case 0x02:
        if (flags & EXT_H)
        {
            ir->op = RV_FADD_H;
            break;
        }
        break;

    case 0x03:
        if (flags & EXT_Q)
        {
            ir->op = RV_FADD_Q;
            break;
        }
        break;

    case 0x04:
        if (flags & EXT_F)
        {
            ir->op = RV_FSUB_S;
            break;
        }
        break;

    case 0x05:
        if (flags & EXT_D)
        {
            ir->op = RV_FSUB_D;
            break;
        }
        break;

    case 0x06:
        if (flags & EXT_H)
        {
            ir->op = RV_FSUB_H;
            break;
        }
        break;

    case 0x07:
        if (flags & EXT_Q)
        {
            ir->op = RV_FSUB_Q;
            break;
        }
        break;

    case 0x08:
        if (flags & EXT_F)
        {
            ir->op = RV_FMUL_S;
            break;
        }
        break;

    case 0x09:
        if (flags & EXT_D)
        {
            ir->op = RV_FMUL_D;
            break;
        }
        break;

    case 0x0a:
        if (flags & EXT_H)
        {
            ir->op = RV_FMUL_H;
            break;
        }
        break;

    case 0x0b:
        if (flags & EXT_Q)
        {
            ir->op = RV_FMUL_Q;
            break;
        }
        break;

    case 0x0c:
        if (flags & EXT_F)
        {
            ir->op = RV_FDIV_S;
            break;
        }
        break;

    case 0x0d:
        if (flags & EXT_D)
        {
            ir->op = RV_FDIV_D;
            break;
        }
        break;

    case 0x0e:
        if (flags & EXT_H)
        {
            ir->op = RV_FDIV_H;
            break;
        }
        break;

    case 0x0f:
        if (flags & EXT_Q)
        {
            ir->op = RV_FDIV_Q;
            break;
        }
        break;

    case 0x10:
        switch (ir->mod)
        {
        case 0:
            if (flags & EXT_F)
            {
                ir->op = RV_FSGNJ_S;
                break;
            }
            break;

        case 1:
            if (flags & EXT_F)
            {
                ir->op = RV_FSGNJN_S;
                break;
            }
            break;

        case 2:
            if (flags & EXT_F)
            {
                ir->op = RV_FSGNJX_S;
                break;
            }
            break;
        }
        break;

    case 0x11:
        switch (ir->mod)
        {
        case 0:
            if (flags & EXT_D)
            {
                ir->op = RV_FSGNJ_D;
                break;
            }
            break;

        case 1:
            if (flags & EXT_D)
            {
                ir->op = RV_FSGNJN_D;
                break;
            }
            break;

        case 2:
            if (flags & EXT_D)
            {
                ir->op = RV_FSGNJX_D;
                break;
            }
            break;
        }
        break;

    case 0x12:
        switch (ir->mod)
        {
        case 0:
            if (flags & EXT_H)
            {
                ir->op = RV_FSGNJ_H;
                break;
            }
            break;

        case 1:
            if (flags & EXT_H)
            {
                ir->op = RV_FSGNJN_H;
                break;
            }
            break;

        case 2:
            if (flags & EXT_H)
            {
                ir->op = RV_FSGNJX_H;
                break;
            }
            break;
        }
        break;

    case 0x13:
        switch (ir->mod)
        {
        case 0:
            if (flags & EXT_Q)
            {
                ir->op = RV_FSGNJ_Q;
                break;
            }
            break;

        case 1:
            if (flags & EXT_Q)
            {
                ir->op = RV_FSGNJN_Q;
                break;
            }
            break;

        case 2:
            if (flags & EXT_Q)
            {
                ir->op = RV_FSGNJX_Q;
                break;
            }
            break;
        }
        break;

    case 0x14:
        switch (ir->mod)
        {
        case 0:
            if (flags & EXT_F)
            {
                ir->op = RV_FMIN_S;
                break;
            }
            break;

        case 1:
            if (flags & EXT_F)
            {
                ir->op = RV_FMAX_S;
                break;
            }
            break;
        }
        break;

    case 0x15:
        switch (ir->mod)
        {
        case 0:
            if (flags & EXT_D)
            {
                ir->op = RV_FMIN_D;
                break;
            }
            break;

        case 1:
            if (flags & EXT_D)
            {
                ir->op = RV_FMAX_D;
                break;
            }
            break;
        }
        break;

    case 0x16:
        switch (ir->mod)
        {
        case 0:
            if (flags & EXT_H)
            {
                ir->op = RV_FMIN_H;
                break;
            }
            break;

        case 1:
            if (flags & EXT_H)
            {
                ir->op = RV_FMAX_H;
                break;
            }
            break;
        }
        break;

    case 0x17:
        switch (ir->mod)
        {
        case 0:
            if (flags & EXT_Q)
            {
                ir->op = RV_FMIN_Q;
                break;
            }
            break;

        case 1:
            if (flags & EXT_Q)
            {
                ir->op = RV_FMAX_Q;
                break;
            }
            break;
        }
        break;

    case 0x20:
        if (flags & EXT_F)
        {
            switch (ir->rs2)
            {
            case 1:
                if (flags & EXT_D)
                {
                    ir->op = RV_FCVT_S_D;
                    break;
                }
                break;

            case 2:
                if (flags & EXT_H)
                {
                    ir->op = RV_FCVT_S_H;
                    break;
                }
                break;

            case 3:
                if (flags & EXT_Q)
                {
                    ir->op = RV_FCVT_S_Q;
                    break;
                }
                break;
            }
            break;
        }
        break;

    case 0x21:
        if (flags & EXT_D)
        {
            switch (ir->rs2)
            {
            case 0:
                if (flags & EXT_F)
                {
                    ir->op = RV_FCVT_D_S;
                    break;
                }
                break;

            case 2:
                if (flags & EXT_H)
                {
                    ir->op = RV_FCVT_D_H;
                    break;
                }
                break;

            case 3:
                if (flags & EXT_Q)
                {
                    ir->op = RV_FCVT_D_Q;
                    break;
                }
                break;
            }
            break;
        }
        break;

    case 0x22:
        if (flags & EXT_H)
        {
            switch (ir->rs2)
            {
            case 0:
                if (flags & EXT_F)
                {
                    ir->op = RV_FCVT_H_S;
                    break;
                }
                break;

            case 1:
                if (flags & EXT_D)
                {
                    ir->op = RV_FCVT_H_D;
                    break;
                }
                break;

            case 3:
                if (flags & EXT_Q)
                {
                    ir->op = RV_FCVT_H_Q;
                    break;
                }
                break;
            }
            break;
        }
        break;

    case 0x23:
        if (flags & EXT_Q)
        {
            switch (ir->rs2)
            {
            case 0:
                if (flags & EXT_F)
                {
                    ir->op = RV_FCVT_Q_S;
                    break;
                }
                break;

            case 1:
                if (flags & EXT_D)
                {
                    ir->op = RV_FCVT_Q_D;
                    break;
                }
                break;

            case 2:
                if (flags & EXT_H)
                {
                    ir->op = RV_FCVT_Q_H;
                    break;
                }
                break;
            }
            break;
        }
        break;

        // ----

    case 0x2c:
        if (flags & EXT_F)
        {
            ir->op = RV_FSQRT_S;
            break;
        }
        break;

    case 0x2d:
        if (flags & EXT_D)
        {
            ir->op = RV_FSQRT_D;
            break;
        }
        break;

    case 0x2e:
        if (flags & EXT_H)
        {
            ir->op = RV_FSQRT_H;
            break;
        }
        break;

    case 0x2f:
        if (flags & EXT_Q)
        {
            ir->op = RV_FSQRT_Q;
            break;
        }
        break;

        // ----

    case 0x50:
        switch (ir->mod)
        {
        case 0:
            if (flags & EXT_F)
            {
                ir->op = RV_FLE_S;
                break;
            }
            break;

        case 1:
            if (flags & EXT_F)
            {
                ir->op = RV_FLT_S;
                break;
            }
            break;

        case 2:
            if (flags & EXT_F)
            {
                ir->op = RV_FEQ_S;
                break;
            }
            break;
        }
        break;

    case 0x51:
        switch (ir->mod)
        {
        case 0:
            if (flags & EXT_D)
            {
                ir->op = RV_FLE_D;
                break;
            }
            break;

        case 1:
            if (flags & EXT_D)
            {
                ir->op = RV_FLT_D;
                break;
            }
            break;

        case 2:
            if (flags & EXT_D)
            {
                ir->op = RV_FEQ_D;
                break;
            }
            break;
        }
        break;

    case 0x52:
        switch (ir->mod)
        {
        case 0:
            if (flags & EXT_H)
            {
                ir->op = RV_FLE_H;
                break;
            }
            break;

        case 1:
            if (flags & EXT_H)
            {
                ir->op = RV_FLT_H;
                break;
            }
            break;

        case 2:
            if (flags & EXT_H)
            {
                ir->op = RV_FEQ_H;
                break;
            }
            break;
        }
        break;

    case 0x53:
        switch (ir->mod)
        {
        case 0:
            if (flags & EXT_Q)
            {
                ir->op = RV_FLE_Q;
                break;
            }
            break;

        case 1:
            if (flags & EXT_Q)
            {
                ir->op = RV_FLT_Q;
                break;
            }
            break;

        case 2:
            if (flags & EXT_Q)
            {
                ir->op = RV_FEQ_Q;
                break;
            }
            break;
        }
        break;

    case 0x60:
        if (flags & EXT_F)
        {
            switch (ir->rs2)
            {
            case 0:
                ir->op = RV_FCVT_W_S;
                break;

            case 1:
                ir->op = RV_FCVT_WU_S;
                break;

            case 2:
                if (flags & EXT_64)
                {
                    ir->op = RV_FCVT_L_S;
                    break;
                }
                break;

            case 3:
                if (flags & EXT_64)
                {
                    ir->op = RV_FCVT_LU_S;
                    break;
                }
                break;
            }
            break;
        }
        break;

    case 0x61:
        if (flags & EXT_D)
        {
            switch (ir->rs2)
            {
            case 0:
                ir->op = RV_FCVT_W_D;
                break;

            case 1:
                ir->op = RV_FCVT_WU_D;
                break;

            case 2:
                if (flags & EXT_64)
                {
                    ir->op = RV_FCVT_L_D;
                    break;
                }
                break;

            case 3:
                if (flags & EXT_64)
                {
                    ir->op = RV_FCVT_LU_D;
                    break;
                }
                break;
            }
            break;
        }
        break;

    case 0x62:
        if (flags & EXT_H)
        {
            switch (ir->rs2)
            {
            case 0:
                ir->op = RV_FCVT_W_H;
                break;

            case 1:
                ir->op = RV_FCVT_WU_H;
                break;

            case 2:
                if (flags & EXT_64)
                {
                    ir->op = RV_FCVT_L_H;
                    break;
                }
                break;

            case 3:
                if (flags & EXT_64)
                {
                    ir->op = RV_FCVT_LU_H;
                    break;
                }
                break;
            }
            break;
        }
        break;

    case 0x63:
        if (flags & EXT_Q)
        {
            switch (ir->rs2)
            {
            case 0:
                ir->op = RV_FCVT_W_Q;
                break;

            case 1:
                ir->op = RV_FCVT_WU_Q;
                break;

            case 2:
                if (flags & EXT_64)
                {
                    ir->op = RV_FCVT_L_Q;
                    break;
                }
                break;

            case 3:
                if (flags & EXT_64)
                {
                    ir->op = RV_FCVT_LU_Q;
                    break;
                }
                break;
            }
            break;
        }
        break;

        // TODO: FCVT

    case 0x68:
        if (flags & EXT_F)
        {
            switch (ir->rs2)
            {
            case 0:
                ir->op = RV_FCVT_S_W;
                break;

            case 1:
                ir->op = RV_FCVT_S_WU;
                break;

            case 2:
                if (flags & EXT_64)
                {
                    ir->op = RV_FCVT_S_L;
                    break;
                }
                break;

            case 3:
                if (flags & EXT_64)
                {
                    ir->op = RV_FCVT_S_LU;
                    break;
                }
                break;
            }
            break;
        }
        break;

    case 0x69:
        if (flags & EXT_D)
        {
            switch (ir->rs2)
            {
            case 0:
                ir->op = RV_FCVT_D_W;
                break;

            case 1:
                ir->op = RV_FCVT_D_WU;
                break;

            case 2:
                if (flags & EXT_64)
                {
                    ir->op = RV_FCVT_D_L;
                    break;
                }
                break;

            case 3:
                if (flags & EXT_64)
                {
                    ir->op = RV_FCVT_D_LU;
                    break;
                }
                break;
            }
            break;
        }
        break;

    case 0x6a:
        if (flags & EXT_H)
        {
            switch (ir->rs2)
            {
            case 0:
                ir->op = RV_FCVT_H_W;
                break;

            case 1:
                ir->op = RV_FCVT_H_WU;
                break;

            case 2:
                if (flags & EXT_64)
                {
                    ir->op = RV_FCVT_H_L;
                    break;
                }
                break;

            case 3:
                if (flags & EXT_64)
                {
                    ir->op = RV_FCVT_H_LU;
                    break;
                }
                break;
            }
            break;
        }
        break;

    case 0x6b:
        if (flags & EXT_Q)
        {
            switch (ir->rs2)
            {
            case 0:
                ir->op = RV_FCVT_Q_W;
                break;

            case 1:
                ir->op = RV_FCVT_Q_WU;
                break;

            case 2:
                if (flags & EXT_64)
                {
                    ir->op = RV_FCVT_Q_L;
                    break;
                }
                break;

            case 3:
                if (flags & EXT_64)
                {
                    ir->op = RV_FCVT_Q_LU;
                    break;
                }
                break;
            }
            break;
        }
        break;

    case 0x70:
        if (flags & EXT_F)
        {
            switch (ir->mod)
            {
            case 0:
                ir->op = RV_FMV_X_W; // FMV_X_S
                break;

            case 1:
                ir->op = RV_FCLASS_S;
                break;
            }
            break;
        }
        break;

    case 0x71:
        if (flags & EXT_D)
        {
            switch (ir->mod)
            {
            case 0:
                ir->op = RV_FMV_X_D;
                break;

            case 1:
                ir->op = RV_FCLASS_D;
                break;
            }
            break;
        }
        break;

    case 0x72:
        if (flags & EXT_H)
        {
            switch (ir->mod)
            {
            case 0:
                ir->op = RV_FMV_X_H;
                break;

            case 1:
                ir->op = RV_FCLASS_H;
                break;
            }
            break;
        }
        break;

    case 0x73:
        if (flags & EXT_Q)
        {
            switch (ir->mod)
            {
            case 1:
                ir->op = RV_FCLASS_Q;
                break;
            }
            break;
        }
        break;

    case 0x78:
        if (flags & EXT_F)
        {
            switch (ir->mod)
            {
            case 0:
                ir->op = RV_FMV_W_X; // FMV_S_X
                break;
            }
            break;
        }
        break;

    case 0x79:
        if (flags & EXT_D)
        {
            switch (ir->mod)
            {
            case 0:
                ir->op = RV_FMV_D_X;
                break;
            }
            break;
        }
        break;

    case 0x7a:
        if (flags & EXT_H)
        {
            switch (ir->mod)
            {
            case 0:
                ir->op = RV_FMV_H_X;
                break;
            }
            break;
        }
        break;
    }
}
