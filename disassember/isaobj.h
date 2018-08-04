#ifndef __ISAOBJ_H__    //isaobj.h
#define __ISAOBJ_H__

#include "instrcution.h"



//
// This isa type for all 8086 instrcution. 
// Now i don't want to add 8087's isa.
//


//
// This ISA_TYPE, TYPE-(SOURCE OP)-(DIRCTION)-(DESTINATION OP)
// OP type : I(Immediate number), REG(Register), MM(Memory), ACC(Accumulator:AX),
// COUNT(CX), SREG(Sement Register). RM(Register or Memory)
// DIRCTION TO(To), TF(To or From), F(From).
//
enum  ISA_TYPE {
    
    //
    //  DATA TRANSFER.
    //
    MOV_RM_TF_REG,
    MOV_I_TO_RM,
    MOV_I_TO_REG,
    MOV_M_TO_ACC,
    MOV_ACC_TO_M,
    MOV_RM_TO_SREG,
    MOV_SREG_TO_RM,
    
    PUSH_RM,
    PUSH_REG,
    PUSH_SREG,
    
    POP_RM,
    POP_REG,
    POP_SREG,
    
    XCHG_RM_WITH_REG,
    XCHG_WITH_ACC,
    
    IN_FIXED_PORT,
    IN_VAR_PORT,
    
    OUT_FIXED_PORT,
    OUT_VAR_PORT,
    
    XLAT,
    LEA,
    LDS,
    LES,
    LAHF,
    SAHF,
    PUSHF,
    POPF,
    
    //
    //  ARITHMETIC.
    //
    ADD_RM_WITH_REG_TO_EITHER,
    ADD_I_TO_RM,
    ADD_I_TO_ACC,
    
    ADC_RM_WITH_REG_TO_EITHER,
    ADC_I_TO_RM,
    ADC_I_TO_ACC,
    
    INC_RM,
    INC_REG,
    
    AAA,
    BAA,
    
    SUB_RM_WITH_REG_TO_EITHER,
    SUB_I_TO_RM,
    SUB_I_TO_ACC,
    
    SBB_RM_WITH_REG_TO_EITHER,
    SBB_I_TO_RM,
    SBB_I_TO_ACC,
    
    DEC_RM,
    DEC_REG,
    
    NEG,
    
    CMP_RM_WITH_R,
    CMP_I_WITH_RM,
    CMP_I_WITH_ACC,
    
    AAS,
    DAS,
    MUL,
    IMUL,
    AAM,
    DIV,
    IDIV,
    AAD,
    CBW,
    CWD,
    
    //
    //  LOGIC.
    //
    NOT,
    SHL_SAL,
    SHR,
    SAR,
    ROL,
    ROR,
    RCL,
    RCR,
    
    AND_RM_AND_REG_TO_EITHER,
    AND_I_TO_RM,
    AND_I_TO_ACC,
    
    TEST_RM_AND_REG_TO_EITHER,
    TEST_I_TO_RM,
    TEST_I_TO_ACC,
    
    OR_RM_AND_REG_TO_EITHER,
    OR_I_TO_RM,
    OR_I_TO_ACC,
    
    XOR_RM_AND_REG_TO_EITHER,
    XOR_I_TO_RM,
    XOR_I_TO_ACC,
    
    //
    //STRING MANIPULATION
    //
    REP,
    MOVS,
    CMPS,
    SCAS,
    LODS,
    STOS,
    
    //
    //  CONTROL TRANSFER
    //
    CALL_DIRECT_SREG,
    CALL_INDIRECT_SREG,
    CALL_DIRECT_INTERSEGMENT,
    CALL_INDIRECT_INTERSEGMENT,
    
    JMP_DIRECT_SREG,
    JMP_DIRECT_SREG_SHORT;
    JMP_INDIRECT_SREG,
    JMP_DIRECT_INTERSEGMENT,
    JMP_INDIRECT_INTERSEGMENT,
    
    RET_WITH_SREG,
    RET_SREG_ADD_I_TO_SP,
    RET_INTERSEGMENT;
    RET_SREG_ADD_I_TO_SP_INTERSEGMENT,
    
    JZ_JE,
    JL_JNGE,
    JLE_JNG,
    JB_JNAE,
    JBE_JNA,
    JP_JPE;
    JO,
    JS,
    JNE_JZ
    JNL_JGE,
    JNLE_JG,
    JNB_JAE,
    JNBE_JA,
    JNP_JPO,
    JNO,
    JNS,
    
    LOOP,
    LOOPZ_LOOPE,
    LOOPNZ_LOOPNE,
    
    JCXZ,
    
    INT_SPECFILED,
    INT_TREE,
    
    INTO,
    IRET,
    
    //
    //PROCESSOR CONTROL
    //
    CLC,
    CMC,
    STC,
    CLD,
    STD,
    CLI,
    STI,
    HLT,
    WAIT,
    ESC,
    LOCK
    
};

typedef Status (ISA_CALLBACK *)(struct _ISA_OBJ *pISA_OBJ);
typedef unsigned char uchar;

typedef struct _ISA_PREFIX {
    char rep_prefix;                    // rep prefix
    char lock_prefix;                   // lock prefix 
    char seg_prefix;                    // seg prefix
} ISA_PREFIX;

typedef struct _ISA_OBJ {
    ISA_PREFIX isa_prefix;              // See below.
    enum  ISA_TYPE isa_type;            // ISA type.
    uchar  isa_mod;                     // mod.
    uchar  effectaddr;                  // Effect Addr.
    uchar  reg_mm_d;                    // Direction
    uchar  isa_opsize;                  // Word or Bytes.
    uchar  reg;                         // Which register.
    uchar  args1;                       // EA disp High.
    uchar  args2;                       // EA disp Low.
    uchar  args3;                       // Data High
    uchar  args4;                       // Data Low.
    uchar  isa_size;                    // The count of isa size.
    uchar  isa_dis_buffer[256];         // The disassm buffer.
    ISA_CALLBACK isacallback;           // Callback Function.
} ISA_OBJ;

//  reg_mm_d    
#define ISA_DIRECTION_TO_REG        (1)
#define ISA_DIRECTION_FR_REG        (0)

//
//  ISA_OBJ's filed --> isa_opsize.
//
#define ISA_OPSIZE_BYTE             (0)
#define ISA_OPSIZE_WORD             (1)

//
// ISA_OBJ's 
// 

#define SetPrefix(pISA_OBJ, Prefix, Number)   {                 \
            pISA_OBJ->isa_prefix.##Prefix = Number;             \
        }
        
#define GetLockPrefix(pISA_OBJ)             (pISA_OBJ->isa_prefix.lock_prefix)
#define GetRepPrefix(pISA_OBJ)              (pISA_OBJ->isa_prefix.rep_prefix)
#define GetSegPrefix(pISA_OBJ)              (pISA_OBJ->isa_prefix.seg_prefix)
#define SetLockPrefix(pISA_OBJ)             SetPrefix(pISA_OBJ, lock_prefix, LOCK_PRFIX)
#define SetRepPrefix(pISA_OBJ)              SetPrefix(pISA_OBJ, rep_prefix, REP_PREFIX)
#define SetRepzPrefix(pISA_OBJ)             SetRepPrefix(pISA_OBJ)
#define SetRepnzPrefix(pISA_OBJ)            SetPrefix(pISA_OBJ, rep_prefix, REPNZ_PREFIX)
#define SetESPrefix(pISA_OBJ)               SetPrefix(pISA_OBJ, seg_prefix, REG_SG_ES_PREFIX)
#define SetCSPrefix(pISA_OBJ)               SetPrefix(pISA_OBJ, seg_prefix, REG_SG_CS_PREFIX)
#define SetSSPrefix(pISA_OBJ)               SetPrefix(pISA_OBJ, seg_prefix, REG_SG_SS_PREFIX)
#define SetDSPrefix(pISA_OBJ)               SetPrefix(pISA_OBJ, seg_prefix, REG_SG_DS_PREFIX)
#define GetMod(pISA_OBJ)                    (pISA_OBJ->isa_mod)    
#define SetMod(pISA_OBJ, mod)               {pISA_OBJ->isa_mod = (mod);}
#define GetDirection(pISA_OBJ)              (pISA_OBJ->reg_mm_d)
#define SetDirection(pISA_OBJ, Direct)      {pISA_OBJ->reg_mm_d = Direct;}
#define GetReg(pISA_OBJ)                    (pISA_OBJ->reg)
#define SetReg(pISA_OBJ, RegType)           {pISA_OBJ->reg = RegType;}
#define GetIsaType(pISA_OBJ)                (pISA_OBJ->isa_type)
#define SetIsaType(pISA_OBJ, IsaType)       {pISA_OBJ->isa_type = IsaType;}
#define GetIsaOpSize(pISA_OBJ)              (pISA_OBJ->isa_opsize)
#define SetIsaOpSize(pISA_OBJ, IsaOpSize)   {pISA_OBJ->isa_opsize = IsaOpSize;}
#define GetIsaSize(pISA_OBJ)                (pISA_OBJ->isa_size)
#define SetIsaSize(pISA_OBJ, IsaSize)       {pISA_OBJ->isa_size = IsaSize;}
#define GetHighDisp(pISA_OBJ)               (pISA_OBJ->args1)
#define SetHighDisp(pISA_OBJ, HighDisp)     {pISA_OBJ->args1 = HighDisp;}
#define GetLowDisp(pISA_OBJ)                (pISA_OBJ->args2)
#define SetLowDisp(pISA_OBJ, LowDisp)       (pISA_OBJ->args2 = LowDisp;)
#define GetHighData(pISA_OBJ)               (pISA_OBJ->args3)
#define SetHighData(pISA_OBJ, HighData)     {pISA_OBJ->args3 = HighData;}
#define GetLowData(pISA_OBJ)                (pISA_OBJ->args4)
#define SetLowData(pISA_OBJ, LowData)       {pISA_OBJ->args4 = LowData;}
#define GetOpcode(Opbyte, BitsNo, Size)     (((0xFFFFU) >> (sizeof(char) - Size)) & ((Opbyte) >> (BitsNo)))
#define AddOneIsaSize(pISA_OBJ)             {pISA_OBJ->isa_size += 1;}
#define GetEffectAddr(pISA_OBJ)             (pISA_OBJ->effectaddr)
#define SetEffectAddr(pISA_OBJ, EffectAddr) {pISA_OBJ->effectaddr = (EffectAddr);}

#define SetCallBackFunc(pISA_OBJ, FuncName) {pISA_OBJ->isacallback = IsaExe##FuncName;}
#define GetCallBackFunc(pISA_OBJ)           (pISA_OBJ->isacallback)

#define GetCodeToChar(Opbyte, ShitBitsNo, OpSize)     (((0xFFFFU) >> (sizeof(char) - OpSize)) & ((Opbyte) >> (ShitBitsNo)))


#endif // isaobj.h