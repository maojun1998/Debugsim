#ifndef __ISATRANS_H__
#define __ISATRANS_H__

/*
 *	ISA const types for identy the ISA. 
 */
// This mov instrcutions.
tydef enum _mov {
	MOV_REG_TO_REG;
	MOV_REG_FROM_REG;
	MOV_MM_TO_	



} MOV_ISA;

void isatrans(char *address, char *next_address);



#endif