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


typedef struct _ISA_PREFIX {
    char rep_prefix;                    // rep prefix
    char lock_prefix;                   // lock prefix 
    char seg_prefix;                    // seg prefix
} ISA_PREFIX;

typedef struct _ISA_OBJ {
    ISA_PREFIX isa_prefix;              // See below.
    enum  ISA_TYPE isa_type;            // ISA type.
    char  isa_mod;                      // EA mod.
    char  reg_mm_d;                     // Direction
    char  isa_opsize;                   // Word or Bytes.
    char  reg;                          // Which register.
    char  args1;                        // EA disp High.
    char  args2;                        // EA disp Low.
    char  args3;                        // Data High
    char  args4;                        // Data Low.
    char  isa_size;                     // The count of isa size.
} ISA_OBJ;


//
//  ISA_OBJ's filed --> isa_opsize.
//
#define ISA_OPSIZE_BYTE             (0)
#define ISA_OPSIZE_WORD             (1)

//
// ISA_OBJ's 
// 







#endif // isaobj.h