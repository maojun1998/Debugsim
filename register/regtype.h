/*
 *  This is data type for the register.
 */


#ifndef __REGTYPE_H__	//__REGTYPE_H__
#define __REGTYPE_H__


/*
 *		ASSIC CODE CONST VAR.
 */
 
#define ASSIC_0 	0x30
#define ASSIC_9 	0x39
#define ASSIC_A 	0x41
#define ASSIC_F 	0x46


/*
 *	This is Flag register flag.
 */
 
#define CF_SHR 		0
#define PF_SHR 		2
#define AF_SHR 		4
#define ZF_SHR 		6
#define SF_SHR 		7
#define TF_SHR 		8
#define IF_SHR 		9
#define DF_SHR 		10
#define OF_SHR 		11


/*
 *		Const var for flag status.
 */
 
#define FLAG_STATUS_SET		1
#define FLAG_STATUS_CLS 	0



typedef char  			EX_STAUS;
typedef short 			REG_TYPE;
typedef char  			HALF_REG_TYPE;

typedef unsigned short  U_REG_TYPE;
typedef unsigned char   U_HALF_REG_TYPE;


typedef struct _gergrp {
	union _ax {
		struct {
			HALF_REG_TYPE AL;
			HALF_REG_TYPE AH;
		} low_high_reg;
		REG_TYPE AX;
	}ax;
	union _bx {
		struct {
			HALF_REG_TYPE BL;
			HALF_REG_TYPE BH;
		}low_high_reg;
		REG_TYPE BX;
	} bx;
	union _cx {
		struct {
			HALF_REG_TYPE CL;
			HALF_REG_TYPE CH;
		} low_high_reg;
		REG_TYPE CX;
	} cx;
	union _dx {
		struct {
			HALF_REG_TYPE DL;
			HALF_REG_TYPE DH;
		} low_high_reg;
		REG_TYPE DX;
	} dx;
}Gergrp;

typedef struct _sergrp {
	REG_TYPE DS;
	REG_TYPE ES;
	REG_TYPE SS;
	REG_TYPE CS;
} Sergrp;

typedef struct _idsergrp {
	REG_TYPE SI;
	REG_TYPE DI;
} Idrgrp;

typedef struct _ptrgrp {
	REG_TYPE IP;
	REG_TYPE BP;
	REG_TYPE SP;
} Ptrgrp;

/*
 *	PSW -- Processor Status World. This PSW graph. 
 *     32                                                            0
 *		+---....-----+---+---+---+---+---+---+---+---+---+---+---+---+
 *		|            | O | D | I | T | S | Z |   | A |   | P |   | C |
 *		|            | F | F | F | F | F | F |   | F |   | F |   | F |
 *		+---....-----+---+---+---+---+---+---+---+---+---+---+---+---+
 *
 *
 *
 *
 */
typedef struct _flrgrp {
	REG_TYPE PSW;
} Flrgrp;

	
typedef struct _regrp {
	Gergrp gergrp;
	Sergrp sergrp;
	Idrgrp idrgrp;
	Ptrgrp ptrgrp;
	Flrgrp flrgrp;
} Regrp;





/*
 *	This date struct is not used.
 */

/*
 *	typedef union _psw_bits{
 *		unsigned short PSW;
 *	struct {
 *			unsigned int   :20;
 *			unsigned int OF:1;
 *			unsigned int DF:1;
 *			unsigned int IF:1;
 *			unsigned int TF:1;
 *			unsigned int SF:1;
 *			unsigned int ZF:1;
 *			unsigned int   :1;
 *			unsigned int AF:1;
 *			unsigned int   :1;
 *			unsigned int PF:1;
 *			unsigned int   :1;
 *			unsigned int CF:1;
 *		
 *		} flag;
 *	} Psw_Bits;
 */

#endif	//__REGTYPE_H__
