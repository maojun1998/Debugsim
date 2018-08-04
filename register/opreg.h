/*
 *		Interface for register opreator.
 *		Such write or read register.
 */


#ifndef __OPREG_H__		// opreg.h
#define __OPREG_H__


#include "regtype.h"



STAUS Init_Reg(Regrp *regrp);

STAUS Show_Reg(Regrp *regrp);

static STAUS Read_Reg(Regrp *regrp, char regname[], REG_TYPE *buffer);

static STAUS Write_Reg(Regrp *regrp, char regname[], REG_TYPE *buffer);

/*
 *	PSW -- Processor Status World. This PSW graph. 
 *     16                                                            0
 *		+---....-----+---+---+---+---+---+---+---+---+---+---+---+---+
 *		|            | O | D | I | T | S | Z |   | A |   | P |   | C |
 *		|            | F | F | F | F | F | F |   | F |   | F |   | F |
 *		+---....-----+---+---+---+---+---+---+---+---+---+---+---+---+
 *
 *
 *
 *
 */

void Set_CF(void);
void Cls_CF(void);
void Set_PF(void);
void Cls_PF(void);
void Set_AF(void);
void Cls_AF(void);
void Set_ZF(void);
void Cls_ZF(void);
void Set_SF(void);
void Cls_SF(void);
void Set_TF(void);
void Cls_TF(void);
void Set_IF(void);
void Cls_IF(void);
void Set_DF(void)；
void Cls_DF(void);
void Set_OF(void);
void Cls_OF(void);

void SetAx(REG_TYPE *reg);
void GetAx(REG_TYPE *reg);
void SetBx(REG_TYPE *reg);
void GetBx(REG_TYPE *reg);
void SetCx(REG_TYPE *reg);
void GetCx(REG_TYPE *reg);
void SetDx(REG_TYPE *reg);
void GetDx(REG_TYPE *reg);
void SetDs(REG_TYPE *reg);
void GetDs(REG_TYPE *reg);
void SetEs(REG_TYPE *reg);
void GetEs(REG_TYPE *reg);
void SetCs(REG_TYPE *reg);
void GetCs(REG_TYPE *reg);
void SetSs(REG_TYPE *reg);
void GetSs(REG_TYPE *reg);
void SetSi(REG_TYPE *reg);
void GetSi(REG_TYPE *reg);
void SetDi(REG_TYPE *reg);
void GetDi(REG_TYPE *reg);
void SetSp(REG_TYPE *reg);
void GetSp(REG_TYPE *reg);
void SetBp(REG_TYPE *reg);
void GetBp(REG_TYPE *reg);
void SetIp(REG_TYPE *reg);
void GetIp(REG_TYPE *reg);


void SetAh(REG_TYPE *reg);
void GetAh(REG_TYPE *reg);
void SetAl(REG_TYPE *reg);
void GetAl(REG_TYPE *reg);
void SetBh(REG_TYPE *reg);
void GetBh(REG_TYPE *reg);
void SetBl(REG_TYPE *reg);
void GetBl(REG_TYPE *reg);
void SetCh(REG_TYPE *reg);
void GetCh(REG_TYPE *reg);
void SetCl(REG_TYPE *reg);
void GetCl(REG_TYPE *reg);
void SetDh(REG_TYPE *reg);
void GetDh(REG_TYPE *reg);
void SetDl(REG_TYPE *reg);
void GetDl(REG_TYPE *reg);











#endif	// opreg.h