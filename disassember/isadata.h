#ifndef __ISADATA_H__	// isadata.h
#define __ISADATA_H__

typedef unsigned char uchar;
typedef unsigned int  uint;

// Type One Instruction.
typedef union _ISA_TYPE_1 {
	uchar opsize : 1;
	uchar opflag : 1;
	uchar opcode : 6;
} ISA_TYPE_1;

// This ISA_TYPE_1 Instruction Opcode Const Var.
#define MOV_RM_TF_R		(0x22)
#define ADD_RM_T_R		(0x00)
#define ADD_I_T_RM		(0x20)
#define ADC_RM_T_R		(0x04)
#define ADC_I_T_RM		(0x20)
#define SUB_RM_T_R		(0x0a)
#define SUB_I_F_RM		(0x20)
#define SSB_RM_T_R		(0x06)
#define SSB_I_F_RM		(0x20)
#define CMP_RM_W_R		(0x0e)
#define CMP_I_W_RM		(0x20)
#define SHL				(0x34)
#define SAL				(0x34)
#define SHR				(0x34)
#define SAR				(0x34)
#define ROL				(0x34)
#define ROR				(0x34)
#define RCL				(0x34)
#define RCR				(0x34)
#define AND_RM_T_R		(0x08)
#define OR_RM_T_R		(0x02)
#define XOR_RM_T_R		(0x0c)


// Type Two Instruction.
typedef union _ISA_TYPE_2 {
	uchar opsize : 1;
	uchar opcode : 7;
} ISA_TYPE_2;

// This ISA_TYPE_2 Instruction Opcode Const Var.
#define MOV_I_T_RM		(0x63)
#define MOV_M_T_A		(0x50)
#define MOV_A_T_M		(0x51)
#define XCHG_RN_R		(0x43)
#define IN_FP			(0x72)
#define IN_VP			(0x76)
#define OUT_FP			(0x73)
#define OUT_VP			(0x77)
#define ADD_I_T_A		(0x02)
#define ADC_I_T_A		(0x0a)
#define INC_RM			(0x7f)
#define SUB_I_F_A		(0x16)
#define SSB_I_F_A		(0x07)
#define DEC_RM			(0x7f)
#define NEG				(0x7b)
#define CMP_I_W_A		(0x1e)
#define MUL				(0x7b)
#define IMUL			(0x7b)
#define	DIV				(0x7b)
#define IDIV			(0x7b)
#define NOT				(0x7b)
#define AND_I_T_RM		(0x40)
#define AND_I_A			(0x12)
#define TEST_RM_W_R		(0x42)
#define TEST_I_W_RM		(0x7b)
#define TEST_I_W_A		(0x54)
#define OR_I_T_RM		(0x40)
#define OR_I_T_A		(0x06)
#define XOR_I_T_RM		(0x40)
#define XOR_I_T_A		(0x1a)
#define REP				(0x79)
#define MOVS			(0x52)
#define CMPS			(0x53)
#define SCAS			(0x57)
#define LODS			(0x56)
#define STOS			(0x55)






// Type Three Instruction.
typedef union _ISA_TYPE_3 {
	uchar opgreg : 3;
	uchar opflag : 1;
	uchar opcode : 4;
} ISA_TYPE_3;

// This ISA_TYPE_2 Instruction Opcode Const Var.
#define MOV_I_T_R		(0x0b)



// Type Four Instruction.
typedef union _ISA_TYPE_4 {
	uchar opsize : 8;
} ISA_TYPE_4;
#define MOV_RM_T_S		(0x8e)
#define MOV_S_T_RM		(0x8c)
#define PUSH_RM			(0xff)
#define POP_RM			(0x8f)
#define XLAT			(0xd7)
#define LEA				(0x8d)
#define LDS				(0xc5)
#define LES				(0xc4)
#define LAHF			(0x9f)
#define SAHF			(0x9e)
#define PUSHF			(0x9c)
#define POPF			(0x9d)
#define AAA				(0x37)
#define BBA				(0x27)
#define AAS				(0x3f)
#define DAS				(0x2f)
#define AAM				(0xd4)
#define AAD				(0xd5)
#define CBW				(0x98)
#define CWD				(0x99)
#define CALL_D_W_S		(0xe8)
#define CALL_IS			(0xff)
#define CALL_DI			(0x9a)
#define CALL_II			(0xff)



// Type Five Instruction.
typedef union _ISA_TYPE_5 {
	uchar opgreg : 3;
	uchar opcode : 5;
} ISA_TYPE_5;





// Type Six Instruction.
typedef union _ISA_TYPE_6 {
	uchar opcode_1 : 3;
	uchar opsreg   : 2;
	uchar opcode_2 : 3;
} ISA_TYPE_6;





#endif	// isadata.h