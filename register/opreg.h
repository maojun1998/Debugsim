/*
 *		Interface for register opreator.
 *		Such write or read register.
 */


#ifndef __OPREG_H__		// opreg.h
#define __OPREG_H__



#include "regtype.h"



EX_STAUS Init_Reg(Regrp *regrp);

EX_STAUS Show_Reg(Regrp *regrp);

EX_STAUS Read_Reg(Regrp *regrp, char regname[], REG_TYPE *buffer);

EX_STAUS Write_Reg(Regrp *regrp, char regname[], REG_TYPE *buffer);



#endif	// opreg.h