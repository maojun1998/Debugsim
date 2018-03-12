#ifndef __INSTRCUTION_H__	// instruction.h
#define __INSTRCUTION_H__

// MOD Const Var.
#define  MOD_DP_ABSENT		(0x00)
#define  MOD_DP_SIGEXT		(0x01)
#define  MOD_DP_FULLHL		(0x02)
#define  MOD_DP_TRTREG		(0x03)

// EA: effect address.
#define  RM_BXSD			(0x00)
#define  RM_BXDD			(0x01)
#define  RM_BPSD			(0x02)
#define	RM_BPDD			(0x03)
#define	RM_SD			(0X04)
#define	RM_DD			(0x05)
#define	RM_BPD			(0x06)	// except if mod = 00,DISP = disphigh + displow.
#define	RM_BXD			(0x07)

// REG const var.
#define	REG_W_AX			(0x00)
#define	REG_W_CX			(0x01)
#define	REG_W_DX			(0x02)
#define	REG_W_BP			(0x03)
#define	REG_W_SP			(0x04)
#define	REG_W_BP			(0x05)
#define	REG_W_SI			(0x06)
#define	REG_W_DI			(0x07)

/*
 *	when w = 0.
 */
#define	REG_AL			(0x00)
#define	REG_CL			(0x01)
#define	REG_DL			(0x02)
#define	REG_BL			(0x03)
#define	REG_AH			(0x04)
#define	REG_CH			(0x05)
#define	REG_DH			(0x06)
#define	REG_BH			(0x07)

/*
 *	Segment regsiter.
 */
#define	REG_SG_ES
#define	REG_SG_CS
#define	REG_SG_SS
#define	REG_SG_DS

// This date type for EA status.
typedef union {
	unsigned char rm  : 3;
	unsigned char reg : 3;
	unsigned char mod : 2;
} ea_sum_t;

static char get_rm(isa_t * addr);
static char get_reg(isa_t * addr);
static char get_mod(isa_t * addr);

static char if_mov( ,char *asm_buffer);


#endif	// instruction.h