#include "dec.h"

int rv_decode(int flags, rv_uint8_t *buf, rv_uint64_t len, inst_t *ir)
{
    rv_uint32_t b0, b1, b2, b3;

    if (len == 0)
        return 0;

    b0 = buf[0];
    if ((b0 & 3) != 3)
    {
        if (len < 2)
            return 0;
        if (flags & EXT_C)
        {
            b1 = buf[1];
            dec_compr(flags, b0 | b1 << 8, ir);
        }
        return 2;
    }

    if (len < 4)
        return 0;

    b1 = buf[1];
    b2 = buf[2];
    b3 = buf[3];
    rv_uint32_t w0 = b0 | b1 << 8 | b2 << 16 | b3 << 24;

    rv_uint64_t b4, b5, b6, b7, b8, b9;
    rv_uint64_t w1;

    rv_uint8_t op = extr_op(b0);
    switch (op)
    {
    default:
        break;

    case 0:
        dec_load(flags, w0, ir);
        break;

    case 1:
        dec_loadfp(flags, w0, ir);
        break;

    case 2:
        dec_cust0(flags, w0, ir);
        break;

    case 3:
        dec_misc(flags, w0, ir);
        break;

    case 4:
        dec_opimm(flags, w0, ir);
        break;

    case 5:
        dec_auipc(flags, w0, ir);
        break;

    case 6:
        dec_opimm32(flags, w0, ir);
        break;

    case 7:
        if (len < 6)
            return 0;
        b4 = buf[4];
        b5 = buf[5];
        w1 = b4 | b5 << 8;
        dec_ext48a(flags, w0, w1, ir);
        return 6;

    case 8:
        dec_store(flags, w0, ir);
        break;

    case 9:
        dec_storefp(flags, w0, ir);
        break;

    case 10:
        dec_cust1(flags, w0, ir);
        break;

    case 11:
        dec_amo(flags, w0, ir);
        break;

    case 12:
        dec_op(flags, w0, ir);
        break;

    case 13:
        dec_lui(flags, w0, ir);
        break;

    case 14:
        dec_op32(flags, w0, ir);
        break;

    case 15:
        if (len < 8)
            return 0;
        b4 = buf[4];
        b5 = buf[5];
        b6 = buf[6];
        b7 = buf[7];
        w1 = b4 | b5 << 8 | b6 << 16 | b7 << 24;
        dec_ext64(flags, w0, w1, ir);
        break;

    case 16:
        dec_fmadd(flags, w0, ir);
        break;

    case 17:
        dec_fmsub(flags, w0, ir);
        break;

    case 18:
        dec_fnmsub(flags, w0, ir);
        break;

    case 19:
        dec_fnmadd(flags, w0, ir);
        break;

    case 20:
        dec_opfp(flags, w0, ir);
        break;

    case 21:
        // rvv
        dec_rsvd0(flags, w0, ir);
        break;

    case 22:
        dec_cust2(flags, w0, ir); // or rv128
        break;

    case 23:
        if (len < 6)
            return 0;
        b4 = buf[4];
        b5 = buf[5];
        w1 = b4 | b5 << 8;
        dec_ext48b(flags, w0, w1, ir);
        return 6;

    case 24:
        dec_branch(flags, w0, ir);
        break;

    case 25:
        dec_jalr(flags, w0, ir);
        break;

    case 26:
        dec_rsvd1(flags, w0, ir);
        break;

    case 27:
        dec_jal(flags, w0, ir);
        break;

    case 28:
        dec_sys(flags, w0, ir);
        break;

    case 29:
        dec_rsvd2(flags, w0, ir);
        break;

    case 30:
        dec_cust3(flags, w0, ir); // or rv128
        break;

    case 31:
        if (len < 10)
            return 0;
        b4 = buf[4];
        b5 = buf[5];
        b6 = buf[6];
        b7 = buf[7];
        b8 = buf[8];
        b9 = buf[9];
        w1 = b4 | b5 << 8 | b6 << 16 | b7 << 24 | b8 << 32 | b9 << 40;
        dec_ext80(flags, w0, w1, ir);
        return 10;
    }

    return 4;
}
