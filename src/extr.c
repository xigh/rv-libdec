#include "dec.h"

rv_uint64_t extr(rv_uint32_t w, int shr, int msh)
{
   rv_uint64_t t0 = (rv_uint64_t) (w >> shr);
   rv_uint64_t t1 = (rv_uint64_t) ((1 << msh) - 1);
   return t0 & t1;
}

rv_uint64_t sign(rv_uint32_t w)
{
    return (w & 0x80000000) ? ~0ull : 0ull;
}

// ----

rv_uint64_t extr_i_imm(rv_uint32_t w)
{
    rv_uint64_t r =
        extr(w, 20, 12) |
        sign(w) << 12;
    return r;
}

rv_uint64_t extr_u_imm(rv_uint32_t w)
{
    rv_uint64_t r =
        extr(w, 12, 20) << 12 |
        sign(w) << 31;
    return r;
}

rv_uint64_t extr_uj_imm(rv_uint32_t w)
{
    rv_uint64_t r =
        extr(w, 21, 10) << 1 |
        extr(w, 20, 1) << 11 |
        extr(w, 12, 8) << 12 |
        sign(w) << 20;
    return r;
}

rv_uint64_t extr_s_imm(rv_uint32_t w)
{
    rv_uint64_t r =
        extr(w, 7, 5) |
        extr(w, 25, 7) << 5 |
        sign(w) << 12;
    return r;
}

rv_uint64_t extr_sb_imm(rv_uint32_t w)
{
    rv_uint64_t r =
        extr(w, 8, 4) << 1 |
        extr(w, 25, 6) << 5 |
        extr(w, 7, 1) << 11 |
        sign(w) << 12;
    return r;
}

// ------

rv_uint8_t extr_op(rv_uint32_t w)
{
    return (rv_uint8_t)extr(w, 2, 5);
}

rv_uint8_t extr_rd(rv_uint32_t w)
{
    return (rv_uint8_t)extr(w, 7, 5);
}

rv_uint8_t extr_f3(rv_uint32_t w)
{
    return (rv_uint8_t)extr(w, 12, 3);
}

rv_uint8_t extr_f6(rv_uint32_t w)
{
    return (rv_uint8_t)extr(w, 26, 6);
}

rv_uint8_t extr_f7(rv_uint32_t w)
{
    return (rv_uint8_t)extr(w, 25, 7);
}

rv_uint8_t extr_rs1(rv_uint32_t w)
{
    return (rv_uint8_t)extr(w, 15, 5);
}

rv_uint8_t extr_rs2(rv_uint32_t w)
{
    return (rv_uint8_t)extr(w, 20, 5);
}

rv_uint8_t extr_rs3(rv_uint32_t w)
{
    return (rv_uint8_t)extr(w, 27, 5);
}

rv_uint8_t extr_f2(rv_uint32_t w)
{
    return (rv_uint8_t)extr(w, 25, 2);
}

rv_uint8_t extr_f5(rv_uint32_t w)
{
    return (rv_uint8_t)extr(w, 27, 5);
}
