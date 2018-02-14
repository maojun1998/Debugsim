#include "memtype.h"
#include "opmem.h"


static Mem mem;

void rdbt(U_SHORT segaddr, U_SHORT offaddr, U_CHAR *pointer)
{
	U_INT eff_addr;
	
	eff_addr = (segaddr << SEG_L_SHIF) + offaddr;
	eff_addr &= TWENTY_AND_NO;
	
	*pointer = *(BYTE *)&mem.mem[eff_addr];

}

void rdwd(U_SHORT segaddr, U_SHORT offaddr, U_SHORT *pointer)
{
	
	U_INT eff_addr;
	
	eff_addr = (segaddr << SEG_L_SHIF) + offaddr;
	eff_addr &= TWENTY_AND_NO;
	
	*pointer = *(WORD *)&mem.mem[eff_addr];
}

void rddw(U_SHORT segaddr, U_SHORT offaddr, U_INT *pointer)
{
	U_INT eff_addr;
	
	eff_addr = (segaddr << SEG_L_SHIF) + offaddr;
	eff_addr &= TWENTY_AND_NO;
	
	*pointer = *(DWORD *)&mem.mem[eff_addr];
	
}

void wtbt(U_SHORT segaddr, U_SHORT offaddr,U_CHAR *pointer)
{
	U_INT eff_addr;
	
	eff_addr = (segaddr << SEG_L_SHIF) + offaddr;
	eff_addr &= TWENTY_AND_NO;
	
	*(BYTE *)&mem.mem[eff_addr] = *pointer;
	
}

void wtwd(U_SHORT segaddr, U_SHORT offaddr, U_SHORT *pointer)
{	
	U_INT eff_addr;
	
	eff_addr = (segaddr << SEG_L_SHIF) + offaddr;
	eff_addr &= TWENTY_AND_NO;
	
	*(WORD *)&mem.mem[eff_addr] = *pointer;
}

void wtdw(U_SHORT segaddr, U_SHORT offaddr, U_INT *pointer)
{
	U_INT eff_addr;
	
	eff_addr = (segaddr << SEG_L_SHIF) + offaddr;
	eff_addr &= TWENTY_AND_NO;
	
	*(DWORD *)&mem.mem[eff_addr] = *pointer;
}