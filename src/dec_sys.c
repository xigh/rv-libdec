#include "dec.h"

void dec_sys(int flags,rv_uint32_t w, inst_t *ir)
{
    ir->rd = extr_rd(w);
    ir->rs1 = extr_rs1(w);
    ir->rs2 = extr_rs2(w);
    ir->imm.u = extr_i_imm(w);
   rv_uint8_t f7 = extr_f7(w);
   rv_uint8_t f3 = extr_f3(w);
    switch (f3)
    {
    case 0:
        switch (f7)
        {
        case 0x00:
            if (ir->rd != 0 || ir->rs1 != 0)
                break;

            switch (ir->rs2)
            {
            case 0:
                ir->op = RV_ECALL;
                break;

            case 1:
                ir->op = RV_EBREAK;
                break;

            case 2:
                ir->op = RV_URET;
                break;
            }
            break;

        case 0x08:
            if (ir->rd != 0 || ir->rs1 != 0)
                break;

            switch (ir->rs2)
            {
            case 2:
                ir->op = RV_SRET;
                break;

            case 5:
                ir->op = RV_WFI;
                break;
            }
            break;

        case 0x09:
            if (ir->rd != 0)
                break;
            ir->op = RV_SFENCE_VMA; // rs1, rs2
            break;

        case 0x18:
            if (ir->rd != 0 || ir->rs1 != 0)
                break;

            switch (ir->rs2)
            {
            case 2:
                ir->op = RV_MRET;
                break;
            }
            break;

        case 0x3d:
            if (ir->rs1 != 0)
                break;

            switch (ir->rs2)
            {
            case 2:
                if (flags & EXT_DEBUG)
                {
                    ir->op = RV_DRET;
                    break;
                }
                break;
            }
            break;
        }
        break;

    case 1:
        if (flags & EXT_CSR)
        {
            ir->op = RV_CSRRW;
            ir->imm.u &= 0xfff;
            break;
        }
        break;

    case 2:
        if (flags & EXT_CSR)
        {
            ir->op = RV_CSRRS;
            ir->imm.u &= 0xfff;
            break;
        }
        break;

    case 3:
        if (flags & EXT_CSR)
        {
            ir->op = RV_CSRRC;
            ir->imm.u &= 0xfff;
            break;
        }
        break;

    case 5:
        if (flags & EXT_CSR)
        {
            ir->op = RV_CSRRWI;
            ir->uimm = extr_rs1(w);
            ir->imm.u &= 0xfff;
            break;
        }
        break;

    case 6:
        if (flags & EXT_CSR)
        {
            ir->op = RV_CSRRSI;
            ir->uimm = extr_rs1(w);
            ir->imm.u &= 0xfff;
            break;
        }
        break;

    case 7:
        if (flags & EXT_CSR)
        {
            ir->op = RV_CSRRCI;
            ir->uimm = extr_rs1(w);
            ir->imm.u &= 0xfff;
            break;
        }
        break;
    }
}
