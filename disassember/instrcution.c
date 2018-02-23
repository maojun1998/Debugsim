#ifndef __INSTRCUTION_H__	// instruction.h
#define __INSTRCUTION_H__

// This date type for EA status.
typedef union {
	unsigned char rm  : 3;
	unsigned char reg : 3;
	unsigned char mod : 2;
} isastatus_t;
// MOD Const Var.
#define  MOD_DP_ABSENT		(0x00)
#define  MOD_DP_SIGEXT		(0x01)
#define  MOD_DP_FULLHL		(0x02)
#define  MOD_DP_TRTREG		(0x03)

#define  RM_

#endif