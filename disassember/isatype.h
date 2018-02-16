#ifndef __ISATYPE_H__	// isatype.h
#define __ISATYPE_H__


typedef uchar_8     unsigned char;
typedef ushort_16   unsigned short;
typedef uint_32     unsigned int;

/***********************************************************
*                  MOVE INSTRUCTION
************************************************************/

/*
 *  This is a union for Instrcution on the first bytes.
 *  The naming convert. Mov_RM_TF_R is mean that Move
 *  Instruction register or memmory  from or to register.
 */

typedef union _Mov_Format_First {
    struct {
        uchar_8     opsize  : 1;
        uchar_8     opflag  : 1;
        uchar_8     opcode  : 6;
    } Mov_RM_TF_R;
    struct {
        uchar_8     opsize  : 1;
        uchar_8     opcode  : 7;
    } Mov_I_T_RM;
    struct {
        uchar_8     opgreg  : 3;
        uchar_8     opflag  : 1;
        uchar_8     opcode  : 4;
    } Mov_I_T_R;
    struct {
        uchar_8     opsize  : 1;
        uchar_8     opcode  : 7;
    } Mov_M_T_A;
    struct {        
        uchar_8     opsize  : 1;
        uchar_8     opcode  : 7;
    } Mov_A_T_M;
    struct {
        uchar_8     opcode  : 8;
    } Mov_RM_T_S;
    struct {
        uchar_8     opcode  : 8;
    } Mov_S_T_RM;
} Mov_Format_First;


#define MOV_RM_TF_R_OP      (0x22)
#define Mov_I_T_RM_OP       (0x63)
#define MOV_I_T_R_OP        (0x0b)
#define MOV_M_T_A_OP        (0x50)
#define MOV_A_T_M_OP        (0x51)
#define MOV_RM_T_S_OP       (0x8e)
#define MOV_S_T_RM          (0x8c)


/***********************************************************
*                  PUSH INSTRUCTION
************************************************************/

typedef union _Push_Format_First {
    struct {
        uchar_8     opcode  : 8;
    } Push_RM;
    struct {
        uchar_8     opgreg  : 3;
        uchar_8     opcode  : 5;
    } Push_R;
    struct {
        uchar_8     opcode_p1   : 3;
        uchar_8     opsreg      : 2;
        uchar_8     opcode_p2   : 3;
    } Push_S;
} Push_Format_First;

#define PUSH_RM_OP     (0xff)
#define PUSH_R_OP      (0x0a)
#define Push_S_OP1     (0x06)
#define Push_S_OP2     (0x00)


/***********************************************************
*                  POP INSTRUCTION
************************************************************/
typedef union _Pop_Format_First {
    struct {
        uchar_8     opcode  : 8;
    } Pop_RM;
    struct {
        uchar_8     opgrep  : 3;
        uchar_8     opcode  : 5;
    } Pop_R;
    struct {
        uchar_8     opcode_p1   : 3;
        uchar_8     opsreg      : 2;
        uchar_8     opcode_p2   : 3;
    } Pop_S;
}



#endif	// isatype.h