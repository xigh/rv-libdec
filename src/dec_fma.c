#include "dec.h"

void dec_fmadd(int flags,rv_uint32_t w, inst_t *ir)
{
    ir->rd = extr_rd(w);
    ir->rs1 = extr_rs1(w);
    ir->rs2 = extr_rs2(w);
    ir->rs3 = extr_rs3(w);

   rv_uint8_t f2 = extr_f2(w);
    switch (f2)
    {
    case 0:
        if (flags & EXT_F)
        {
            ir->op = RV_FMADD_S;
            break;
        }
        break;

    case 1:
        if (flags & EXT_D)
        {
            ir->op = RV_FMADD_D;
            break;
        }
        break;

    case 3:
        if (flags & EXT_Q)
        {
            ir->op = RV_FMADD_Q;
            break;
        }
        break;
    }
}

void dec_fmsub(int flags,rv_uint32_t w, inst_t *ir)
{
    ir->rd = extr_rd(w);
    ir->rs1 = extr_rs1(w);
    ir->rs2 = extr_rs2(w);
    ir->rs3 = extr_rs3(w);

   rv_uint8_t f2 = extr_f2(w);
    switch (f2)
    {
    case 0:
        if (flags & EXT_F)
        {
            ir->op = RV_FMSUB_S;
            break;
        }
        break;

    case 1:
        if (flags & EXT_D)
        {
            ir->op = RV_FMSUB_D;
            break;
        }
        break;

    case 3:
        if (flags & EXT_Q)
        {
            ir->op = RV_FMSUB_Q;
            break;
        }
        break;
    }
}

void dec_fnmadd(int flags,rv_uint32_t w, inst_t *ir)
{
    ir->rd = extr_rd(w);
    ir->rs1 = extr_rs1(w);
    ir->rs2 = extr_rs2(w);
    ir->rs3 = extr_rs3(w);

   rv_uint8_t f2 = extr_f2(w);
    switch (f2)
    {
    case 0:
        if (flags & EXT_F)
        {
            ir->op = RV_FNMADD_S;
            break;
        }
        break;

    case 1:
        if (flags & EXT_D)
        {
            ir->op = RV_FNMADD_D;
            break;
        }
        break;

    case 3:
        if (flags & EXT_Q)
        {
            ir->op = RV_FNMADD_Q;
            break;
        }
        break;
    }
}

void dec_fnmsub(int flags,rv_uint32_t w, inst_t *ir)
{
    ir->rd = extr_rd(w);
    ir->rs1 = extr_rs1(w);
    ir->rs2 = extr_rs2(w);
    ir->rs3 = extr_rs3(w);

   rv_uint8_t f2 = extr_f2(w);
    switch (f2)
    {
    case 0:
        if (flags & EXT_F)
        {
            ir->op = RV_FNMSUB_S;
            break;
        }
        break;

    case 1:
        if (flags & EXT_D)
        {
            ir->op = RV_FNMSUB_D;
            break;
        }
        break;

    case 3:
        if (flags & EXT_Q)
        {
            ir->op = RV_FNMSUB_Q;
            break;
        }
        break;
    }
}
