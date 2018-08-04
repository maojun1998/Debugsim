/*
 *	This is oprate memmory function.
 */


#ifndef __OPMEM_H__		//opmem.h
#define __OPMEM_H__

#include "memtype.h"


#define 
/*
 *  This is Macro function for easy to understand.
 */

#define Mem_Read_Byte(segaddr, offaddr, pointer)            \
                    do {                                    \
                        rdbt(segaddr, offaddr, pointer);    \
                    } while(0)


#define Mem_Read_Word(segaddr, offaddr, pointer)            \
                    do {                                    \
                        rdwd(segaddr, offaddr, pointer);    \
                    } while(0)


#define Mem_Read_Dword(segaddr, offaddr, pointer)           \
                    do {                                    \
                        rddw(segaddr, offaddr, pointer);    \
                    } while(0)


#define Mem_Write_Byte(segaddr, offaddr, pointer)           \
                    do {                                    \
                        wtbt(segaddr, offaddr, pointer);    \
                    } while(0)


#define Mem_Write_Word(segaddr, offaddr, pointer)           \
                    do {                                    \
                        wtwd(segaddr, offaddr, pointer);    \
                    } while(0)


#define Mem_Write_Dword(segaddr, offaddr, pointer)          \
                    do {                                    \
                        wtdw(segaddr, offaddr, pointer);    \
                    } while(0)
/*
 *  Function declaration.
 */
void rdbt(U_SHORT segaddr, U_SHORT offaddr, U_CHAR *pointer);

void rdwd(U_SHORT segaddr, U_SHORT offaddr, U_SHORT *pointer);

void rddw(U_SHORT segaddr, U_SHORT offaddr, U_INT *pointer);

void wtbt(U_SHORT segaddr, U_SHORT offaddr, U_CHAR *pointer);

void wtwd(U_SHORT segaddr, U_SHORT offaddr, U_SHORT *pointer);

void wtdw(U_SHORT segaddr, U_SHORT offaddr, U_INT *pointer);

char getByte(unsigned int address);


#define TransAddrToInt(pAddr)           ((U_INT)(TWENTY_AND_NO & ((U_INT)(pAddr->segaddr << SEG_L_SHIF) + pAddr->offaddr))

#define TransIntToAddr(pAddr, Number)                                       \
                        do {                                                \
                            Number &= TWENTY_AND_NO;                        \
                            pAddr->offaddr = Number & 0x0000000f;           \
                            pAddr->segaddr = (Number >> 4);                 \
                        } while(0)


#endif //opmem.h