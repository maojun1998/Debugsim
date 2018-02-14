/*
 *	This is oprate memmory function.
 */


#ifndef __OPMEM_H__		//opmem.h
#define __OPMEM_H__

#include "memtype.h"


void rdbt(U_SHORT segaddr, U_SHORT offaddr, U_CHAR *pointer);

void rdwd(U_SHORT segaddr, U_SHORT offaddr, U_SHORT *pointer);

void rddw(U_SHORT segaddr, U_SHORT offaddr, U_INT *pointer);

void wtbt(U_SHORT segaddr, U_SHORT offaddr, U_CHAR *pointer);

void wtwd(U_SHORT segaddr, U_SHORT offaddr, U_SHORT *pointer);

void wtdw(U_SHORT segaddr, U_SHORT offaddr, U_INT *pointer);

#endif //opmem.h