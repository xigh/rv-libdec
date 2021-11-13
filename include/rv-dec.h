#ifndef __RV_DEC_H
#define __RV_DEC_H

#include "rv-sys.h"

enum
{
	EXT_M = (1 << 0),			  // mul
	EXT_A = (1 << 1),			  // atomic
	EXT_F = (1 << 2),			  // float 32
	EXT_D = (1 << 3),			  // float 64
	EXT_Q = (1 << 4),			  // float 128
	EXT_H = (1 << 5),			  // float 16 (in vector extension)
	EXT_CSR = (1 << 6),			  // csr
	EXT_64 = (1 << 7),			  // 64 bits
	EXT_SYS = (1 << 8),			  // system
	EXT_FENCEI = (1 << 9),		  // fence
	EXT_C = (1 << 10),			  // compressed
	EXT_128 = (1 << 11) | EXT_64, // 128 bits
	EXT_V = (1 << 12),			  // vector
	EXT_B = (1 << 13),			  // bits
	EXT_HV = (1 << 14),			  // hypervisor
	EXT_K = (1 << 15),			  // crypto
	EXT_DEBUG = (1 << 16),		  // debug
};

typedef struct inst_t inst_t;
struct inst_t
{
	rv_uint64_t pc;
	rv_uint16_t op;
	rv_uint8_t rd;
	rv_uint8_t rs1;
	rv_uint8_t rs2;
	rv_uint8_t rs3;
	rv_uint8_t uimm;
	rv_uint8_t mod;
	union
	{
		rv_uint64_t u;
		rv_int64_t i;
	} imm;
};

extern int rv_decode(int flags, rv_uint8_t *buf, rv_uint64_t len, inst_t *ir);

enum
{
	RV_UNDEF,
#define RV_OP(x) RV_##x,
#include "rv-ops.inc"
};

#endif // __RV_DEC_H
