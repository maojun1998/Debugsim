#ifndef __MEMTYPE_H__	//memtype.h
#define __MEMTYPE_H__



#define MEM_SIZE 		1024

#define TWENTY_AND_NO 	(0xFFFFFFFF >> 12)

#define SEG_L_SHIF 		4

typedef unsigned char 	U_CHAR;
typedef unsigned int  	U_INT;
typedef unsigned short 	U_SHORT;
typedef char			CHAR;
typedef short 			SHORT;
typedef int  			INT;

typedef U_CHAR  		BYTE;
typedef U_SHORT 		WORD;
typedef U_INT   		DWORD;

typedef struct _mem {
	BYTE mem[MEM_SIZE * MEM_SIZE];
}Mem;

typedef struct _addr{
	WORD segaddr;
	WORD offaddr;
}Addr;

#endif	//memtype.h