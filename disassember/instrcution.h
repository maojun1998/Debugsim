#ifndef __INSTRCUTION_H__	// instruction.h
#define __INSTRCUTION_H__

//
// Mod Const Var.
//

#define	MOD_DP_ABSENT		(0x00)
#define	MOD_DP_SIGEXT		(0x01)
#define	MOD_DP_FULLHL		(0x02)
#define	MOD_DP_TRTREG		(0x03)

//
// EA: effect address.
//

#define	RM_BX_SI_DISP		(0x00)
#define	RM_BX_DI_DISP		(0x01)
#define	RM_BP_SI_DISP		(0x02)
#define	RM_BP_DI_DISP		(0x03)
#define	RM_SI_ON_DISP		(0X04)
#define	RM_DD_ON_DISP		(0x05)
#define	RM_BP_ON_DISP		(0x06)	// except if mod = 00, DISP = disphigh + displow.
#define	RM_BX_ON_DISP		(0x07)

//
// REG Const Var, w = 1
//

#define	REG_W_AX			(0x00)
#define	REG_W_CX			(0x01)
#define	REG_W_DX			(0x02)
#define	REG_W_BX			(0x03)
#define	REG_W_SP			(0x04)
#define	REG_W_BP			(0x05)
#define	REG_W_SI			(0x06)
#define	REG_W_DI			(0x07)

//
// when w = 0.
//

#define	REG_AL				(0x00)
#define	REG_CL				(0x01)
#define	REG_DL				(0x02)
#define	REG_BL				(0x03)
#define	REG_AH				(0x04)
#define	REG_CH				(0x05)
#define	REG_DH				(0x06)
#define	REG_BH				(0x07)

//
// Segment regsiter.
//

#define	REG_SG_ES_PREFIX	(0x26)
#define	REG_SG_CS_PREFIX	(0x2e)
#define	REG_SG_SS_PREFIX	(0x36)
#define	REG_SG_DS_PREFIX	(0x3e)

//  
//  Lock Bus Prefix, and REP Prefix.
//  

#define LOCK_PRFIX          (0x78)
#define REP_PREFIX          (0xf2)
#define REPZ_PRFIX          (0xf2)
#define REPNZ_PRFIX         (0xf3)





#endif	// instruction.h