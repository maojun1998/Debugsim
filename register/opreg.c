#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "regtype.h"


static char rchr[5];
static char rfgchr[17];

static const char 	*ushort_to_hex(unsigned short reg_no);
static const char 	*ushort_to_bin(unsigned short reg_no);
static STAUS 	    show_psw_sig(unsigned short reg_no);

static Regrp x86RisgerGroup;

static Regrp *regrp = &x86RisgerGroup;

EX_STAUS Init_Reg(void)
{
	int i;
    
    REG_TYPE reg_cs;
    
    //
    // When 8086 cpu boot, the init cs = 0xffff, ip = 0x0000.
    //
    reg_cs = 0xffff;
	for (i = 0; i < sizeof(Regrp); i++) {
		*((char *)regrp + i) = 0;
	}
    SetCs(&reg_cs);
	return 0;
}

EX_STAUS Show_Reg(void)
{

	printf("AX=");
	printf(ushort_to_hex(regrp->gergrp.ax.AX));
	printf("  ");
	
	printf("BX=");
	printf(ushort_to_hex(regrp->gergrp.bx.BX));
	printf("  ");
	
	printf("CX=");
	printf(ushort_to_hex(regrp->gergrp.cx.CX));
	printf("  ");
	
	printf("DX=");
	printf(ushort_to_hex(regrp->gergrp.dx.DX));
	printf("  ");
	
	printf("SP=");
	printf(ushort_to_hex(regrp->ptrgrp.SP));
	printf("  ");

	
	printf("BP=");
	printf(ushort_to_hex(regrp->ptrgrp.BP));
	printf("  ");

	
	printf("SI=");
	printf(ushort_to_hex(regrp->idrgrp.SI));
	printf("  ");

	
	printf("DI=");
	printf(ushort_to_hex(regrp->idrgrp.DI));
	printf("  ");
	
	/* new line */
	printf("\n");


	printf("DS=");
	printf(ushort_to_hex(regrp->sergrp.DS));
	printf("  ");
	
	printf("ES=");
	printf(ushort_to_hex(regrp->sergrp.ES));
	printf("  ");
	
	printf("SS=");
	printf(ushort_to_hex(regrp->sergrp.SS));
	printf("  ");
	
	printf("CS=");
	printf(ushort_to_hex(regrp->sergrp.CS));
	printf("  ");
	
	printf("IP=");
	printf(ushort_to_hex(regrp->ptrgrp.IP));
	printf("       ");
	printf("PSW=");
	printf(ushort_to_bin(regrp->flrgrp.PSW));

	/* new line */
	printf("\n");
	
	printf("PSW STAUS:        ");

	show_psw_sig(regrp->flrgrp.PSW);
	
	printf("\n");
	return 0;
	
}

static EX_STAUS Read_Reg(char regname[], REG_TYPE *buffer)
{
	if (!(strcmp("AL", regname))) {
		*buffer = regrp->gergrp.ax.low_high_reg.AL;
		
	}else
	if (!(strcmp("AH", regname))) {
		*buffer = regrp->gergrp.ax.low_high_reg.AH;
		
	}else 
	if (!(strcmp("BL", regname))) {
		*buffer = regrp->gergrp.bx.low_high_reg.BL;
		
	}else 
	if (!(strcmp("BH", regname))) {
		*buffer = regrp->gergrp.bx.low_high_reg.BH;
		
	}else 
	if (!(strcmp("CL", regname))) {
		*buffer = regrp->gergrp.cx.low_high_reg.CL;
		
	}else 
	if (!(strcmp("CH", regname))) {
		*buffer = regrp->gergrp.cx.low_high_reg.CH;
		
	}else 
	if (!(strcmp("DL", regname))) {
		*buffer = regrp->gergrp.dx.low_high_reg.DL;
		
	}else
	if (!(strcmp("DH", regname))) {
		*buffer = regrp->gergrp.dx.low_high_reg.DH;
		
	}else
	if (!(strcmp("AX", regname))) {
		*buffer = regrp->gergrp.ax.AX;
		
	}else
	if (!(strcmp("BX", regname))) {
		*buffer = regrp->gergrp.bx.BX;
		
	}else
	if (!(strcmp("CX", regname))) {
		*buffer = regrp->gergrp.cx.CX;
		
	}else
	if (!(strcmp("DX", regname))) {
		*buffer = regrp->gergrp.dx.DX;
		
	}else
	if (!(strcmp("SP", regname))) {
		*buffer = regrp->ptrgrp.SP;
		
	}else
	if (!(strcmp("BP", regname))) {
		*buffer = regrp->ptrgrp.BP;
		
	}else
	if (!(strcmp("SI", regname))) {
		*buffer = regrp->idrgrp.SI;
		
	}else
	if (!(strcmp("DI", regname))) {
		*buffer = regrp->idrgrp.DI;
		
	}else
	if (!(strcmp("DS", regname))) {
		*buffer = regrp->sergrp.DS;
		
	}else
	if (!(strcmp("ES", regname))) {
		*buffer = regrp->sergrp.ES;
		
	}else
	if (!(strcmp("SS", regname))) {
		*buffer = regrp->sergrp.SS;
		
	}else
	if (!(strcmp("CS", regname))) {
		*buffer = regrp->sergrp.CS;
		
	}else
	if (!(strcmp("IP", regname))) {
		*buffer = regrp->ptrgrp.IP;
		
	}else
	if (!(strcmp("PSW", regname))) {
		*buffer = regrp->flrgrp.PSW;
			
	}else {
		return -1;
	}
	return 0;
}

static EX_STAUS Write_Reg(char *regname, REG_TYPE *buffer)
{
	if (!(strcmp("AL", regname))) {
		regrp->gergrp.ax.low_high_reg.AL = *buffer;

	}else if (!(strcmp("AH", regname))) {
		regrp->gergrp.ax.low_high_reg.AH = *buffer;

	}else if (!(strcmp("BL", regname))) {
		regrp->gergrp.bx.low_high_reg.BL = *buffer;

	}else if (!(strcmp("BH", regname))) {
		regrp->gergrp.bx.low_high_reg.BH = *buffer;

	}else if (!(strcmp("CL", regname))) {
		regrp->gergrp.cx.low_high_reg.CL = *buffer;

	}else if (!(strcmp("CH", regname))) {
		regrp->gergrp.cx.low_high_reg.CH = *buffer;

	}else if (!(strcmp("DL", regname))) {
		regrp->gergrp.dx.low_high_reg.DL = *buffer;

	}else if (!(strcmp("DH", regname))) {
		regrp->gergrp.dx.low_high_reg.DH = *buffer;

	}else if (!(strcmp("AX", regname))) {
		regrp->gergrp.ax.AX = *buffer;

	}else if (!(strcmp("BX", regname))) {
		regrp->gergrp.bx.BX = *buffer;

	}else if (!(strcmp("CX", regname))) {
		regrp->gergrp.cx.CX = *buffer;

	}else if (!(strcmp("DX", regname))) {
		regrp->gergrp.dx.DX = *buffer;

	}else if (!(strcmp("SP", regname))) {
		regrp->ptrgrp.SP = *buffer;

	}else if (!(strcmp("BP", regname))) {
		regrp->ptrgrp.BP = *buffer;

	}else if (!(strcmp("SI", regname))) {
		regrp->idrgrp.SI = *buffer;

	}else if (!(strcmp("DI", regname))) {
		regrp->idrgrp.DI = *buffer;

	}else if (!(strcmp("DS", regname))) {
		regrp->sergrp.DS = *buffer;

	}else if (!(strcmp("ES", regname))) {
		regrp->sergrp.ES = *buffer;

	}else if (!(strcmp("SS", regname))) {
		regrp->sergrp.SS = *buffer;

	}else if (!(strcmp("CS", regname))) {
		regrp->sergrp.CS = *buffer;

	}else if (!(strcmp("IP", regname))) {
		regrp->ptrgrp.IP = *buffer;

	}else if (!(strcmp("PSW", regname))) {
		regrp->flrgrp.PSW = *buffer;
		
	}else {
		return -1;
	}
	return 0;
}
static const char *ushort_to_hex(unsigned short reg_no)
{
	char i,j;
	
	rchr[4] = '\0';
	
	for (i = 0; i < 4; i++) {
		j = reg_no % 0x10;
		reg_no = reg_no / 0x10;
		if (j > 9) {
			rchr[4 - 1- i] = j - 10 +ASSIC_A;
		} else {
			rchr[4 - 1- i] = j - 0 + ASSIC_0;
		}
	}
	return rchr;
		
}

static const char *ushort_to_bin(unsigned short reg_no)
{
	char i,j;
	
	rfgchr[16] = '\0';
	
	for (i = 0; i < 16; i++) {
		j = reg_no % 2;
		reg_no = reg_no / 2;
		rfgchr[16 - 1- i] = j - 0 + ASSIC_0;

	}
	return rfgchr;
}

static EX_STAUS show_psw_sig(unsigned short reg_no)
{	
	printf("CF=%c  ", (char)(((reg_no >> CF_SHR) & 1)+ ASSIC_0));
	printf("PF=%c  ", (char)(((reg_no >> PF_SHR) & 1)+ ASSIC_0));
	printf("AF=%c  ", (char)(((reg_no >> AF_SHR) & 1)+ ASSIC_0));
	printf("ZF=%c  ", (char)(((reg_no >> ZF_SHR) & 1)+ ASSIC_0));
	printf("SF=%c  ", (char)(((reg_no >> SF_SHR) & 1)+ ASSIC_0));
	printf("TF=%c  ", (char)(((reg_no >> TF_SHR) & 1)+ ASSIC_0));
	printf("IF=%c  ", (char)(((reg_no >> IF_SHR) & 1)+ ASSIC_0));
	printf("DF=%c  ", (char)(((reg_no >> DF_SHR) & 1)+ ASSIC_0));
	printf("OF=%c  ", (char)(((reg_no >> OF_SHR) & 1)+ ASSIC_0));
	
	return 0;
}

void Set_CF(void)
{
	
	regrp->flrgrp.PSW |= (1 << CF_SHR);
	
}

void Cls_CF(void)
{
	
	regrp->flrgrp.PSW &= ((U_REG_TYPE)(0xffff) ^ (U_REG_TYPE)((1 << CF_SHR)));
	
}

void Set_PF(void)
{
	
	regrp->flrgrp.PSW |= (1 << PF_SHR);
	
}

void Cls_PF(void)
{
	
	regrp->flrgrp.PSW &= ((U_REG_TYPE)(0xffff) ^ (U_REG_TYPE)((1 << PF_SHR)));
	
}

void Set_AF(void)
{
	
	regrp->flrgrp.PSW |= (1 << AF_SHR);
	
}

void Cls_AF(void)
{
	
	regrp->flrgrp.PSW &= ((U_REG_TYPE)(0xffff) ^ (U_REG_TYPE)((1 << AF_SHR)));
	
}

void Set_ZF(void)
{
	regrp->flrgrp.PSW |= (1 << ZF_SHR);
	
}

void Cls_ZF(void)
{
	
	regrp->flrgrp.PSW &= ((U_REG_TYPE)(0xffff) ^ (U_REG_TYPE)((1 << ZF_SHR)));
	
}

void Set_SF(void)
{
	
	regrp->flrgrp.PSW |= (1 << SF_SHR);
	
}

void Cls_SF(void)
{
	
	regrp->flrgrp.PSW &= ((U_REG_TYPE)(0xffff) ^ (U_REG_TYPE)((1 << SF_SHR)));
	
}


void Set_TF(void)
{
	
	regrp->flrgrp.PSW |= (1 << TF_SHR);
	
}

void Cls_TF(void)
{
	regrp->flrgrp.PSW &= ((U_REG_TYPE)(0xffff) ^ (U_REG_TYPE)((1 << TF_SHR)));
	
}

void Set_IF(void)
{
	
	regrp->flrgrp.PSW |= (1 << IF_SHR);
	
}

void Cls_IF(void)
{
	
	regrp->flrgrp.PSW &= ((U_REG_TYPE)(0xffff) ^ (U_REG_TYPE)((1 << IF_SHR)));
	
}

void Set_DF(void)
{
	
	regrp->flrgrp.PSW |= (1 << DF_SHR);
	
}

void Cls_DF(void)
{
	regrp->flrgrp.PSW &= ((U_REG_TYPE)(0xffff) ^ (U_REG_TYPE)((1 << DF_SHR)));
	
}

void Set_OF(void)
{
	
	regrp->flrgrp.PSW |= (1 << OF_SHR);
	
}

void Cls_OF(void)
{
	
	regrp->flrgrp.PSW &= ((U_REG_TYPE)(0xffff) ^ (U_REG_TYPE)((1 << OF_SHR)));
	
}



void SetAx(REG_TYPE *reg)
{
	Write_Reg("AX", reg);
	
}

void GetAx(REG_TYPE *reg)
{
	Read_Reg("AX", reg);
}
void SetBx(REG_TYPE *reg)
{
	Write_Reg("BX", reg);
}

void GetBx(REG_TYPE *reg)
{
	Read_Reg("BX", reg);
	
}
void SetCx(REG_TYPE *reg)
{
	Write_Reg("CX", reg);
	
}

void GetCx(REG_TYPE *reg)
{
	Read_Reg("CX", reg);
	
}

void SetDx(REG_TYPE *reg)
{
	Write_Reg("DX", reg);
	
}
void GetDx(REG_TYPE *reg)
{
	Read_Reg("DX", reg);
	
}
void SetDs(REG_TYPE *reg)
{
    Write_Reg("DS", reg);
    
}
void GetDs(REG_TYPE *reg)
{
    Read_Reg("DS", reg);
    
}
void SetEs(REG_TYPE *reg)
{
    Write_Reg("ES", reg);
    
}
void GetEs(REG_TYPE *reg)
{
    Read_Reg("ES", reg);
    
}
void SetCs(REG_TYPE *reg)
{
    Write_Reg("CS", reg);
    
}
void GetCs(REG_TYPE *reg)
{
    Read_Reg("CS", reg);
    
}
void SetSs(REG_TYPE *reg)
{
    Write_Reg("SS", reg);
    
}
void GetSs(REG_TYPE *reg)
{
    Read_Reg("SS", reg);
    
}
void SetSi(REG_TYPE *reg)
{
    Write_Reg("SI", reg);
    
}
void GetSi(REG_TYPE *reg)
{
    Read_Reg("SI", reg);
    
}
void SetDi(REG_TYPE *reg)
{
    Write_Reg("DI", reg);
}
void GetDi(REG_TYPE *reg)
{
    Read_Reg("DI", reg);
    
}
void SetSp(REG_TYPE *reg)
{
    Write_Reg("SP", reg);
    
}
void GetSp(REG_TYPE *reg)
{
    Write_Reg("SP", reg);
    
}
void SetBp(REG_TYPE *reg)
{
    Write_Reg("BP", reg);
    
}
void GetBp(REG_TYPE *reg)
{
    Read_Reg("BP", reg);
    
}
void SetIp(REG_TYPE *reg)
{
    Write_Reg("IP", reg);
    
}
void GetIp(REG_TYPE *reg)
{
    Read_Reg("IP", reg);
    
}









void SetAh(REG_TYPE *reg)
{
    
    Write_Reg("AH", reg);
    
}
void GetAh(REG_TYPE *reg)
{
    
    Read_Reg("AH", reg);
    
    
}
void SetAl(REG_TYPE *reg)
{
    Write_Reg("AL", reg);
    
}
void GetAl(REG_TYPE *reg)
{
    Read_Reg("AL", reg);
    
}
void SetBh(REG_TYPE *reg)
{
    Write_Reg("BH", reg);
    
}
void GetBh(REG_TYPE *reg)
{
    Read_Reg("BH", reg);
    
}
void SetBl(REG_TYPE *reg)
{
    Write_Reg("BL", reg);
    
}
void GetBl(REG_TYPE *reg)
{
    Read_Reg("BL", reg);
    
}
void SetCh(REG_TYPE *reg)
{
    Write_Reg("CH", reg);
  
}
void GetCh(REG_TYPE *reg)
{
    Read_Reg("CH", reg);    
}
void SetCl(REG_TYPE *reg)
{
    Write_Reg("CL", reg);
}
void GetCl(REG_TYPE *reg)
{
    Read_Reg("CL", reg);
    
}
void SetDh(REG_TYPE *reg)
{
    Write_Reg("DH", reg);
    
}
void GetDh(REG_TYPE *reg)
{
    Read_Reg("DH", reg);
    
}
void SetDl(REG_TYPE *reg)
{
    Write_Reg("DL", reg);
    
}
void GetDl(REG_TYPE *reg)
{
    Read_Reg("DL", reg);
    
}

