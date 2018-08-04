#ifndef __DISASSEMBER_H__	//	disassember.h
#define __DISASSEMBER_H__


//
//  Imports the Macro Function.
//
#include "instrcution.h"
#include "isaobj.h"

typedef char Status;

#define STATUS_SUCCESSFUL   (1)
#define STATUS_FALSE        (0)

//
//  Function interface.
//
Status 
IsaDis(
    ISA_OBJ *pISA_OBJ,
    Addr    *pAddr
    );

Status 
AllocIsaObj(
    ISA_OBJ **ppISA_OBJ
    );

void 
FreeIsaObj(
    ISA_OBJ *pISA_OBJ
    );

    


#endif	// disassember.h