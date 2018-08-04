#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "opmem.h"
#include "instrcution.h"
#include "isaobj.h"

//
// private function.
//
static void transDis(char *buffer, char *fmt, ...);
static void setDisBuffer(char *buffer, char *isaSysbols, char *SourceOp, char *DestinationOp);
static void setPrefixDisBuffer(char *buffer, ISA_OBJ *pISA_OBJ);
static void setModDisBuffer(char *buffer, char *isaType, ISA_OBJ *pISA_OBJ);
static Status transByteToString(uchar Number, char *strb);
static Status transWordToString(uchar NumberHigh, uchar NumberLow, char *strb);
static Status transUByteToString(uchar Number, char *strb);
static Status transUWordToString(uchar NumberHigh, uchar NumberLow, char *strb);
static char *getRegister(uchar reg ,uchar opsize, uchar flag);
static char *getEffectAddrType(uchar effectaddrtype);
// 
//  sysblos.
//
#define SET_SYSBLOS(Name, Sysblos)      static char Name[] = #Sysblos ;
#define SET_SAME_SYSBLOS(Name)          SET_SYSBLOS(Name, Name)

#define MATCH_SREG      (1)
#define MATCH_REG       (0)

static char SPACE = " ";
static char comma = ",";

SET_SYSBLOS(colon, :);
SET_SYSBLOS(add, +);
SET_SYSBLOS(sub, -);
SET_SYSBLOS(leftpar, [);
SET_SYSBLOS(right, ]);
SET_SYSBLOS(AX, AX);
SET_SYSBLOS(CX, CX);
SET_SYSBLOS(DX, DX);
SET_SYSBLOS(BX, BX);
SET_SYSBLOS(SP, SP);
SET_SYSBLOS(BP, BP);
SET_SYSBLOS(AH, AH);
SET_SYSBLOS(CH, CH);
SET_SYSBLOS(DH, DH);
SET_SYSBLOS(BH, BH);
SET_SYSBLOS(AL, AL);
SET_SYSBLOS(CL, CL);
SET_SYSBLOS(DL, DL);
SET_SYSBLOS(BL, BL);

SET_SYSBLOS(ES, ES);
SET_SYSBLOS(CS, CS);
SET_SYSBLOS(SS, SS);
SET_SYSBLOS(DS, DS);

//
// ISA sysblos.
//

// DATA TRANSFER
SET_SAME_SYSBLOS(MOV);
SET_SAME_SYSBLOS(PUSH);
SET_SAME_SYSBLOS(POP);
SET_SAME_SYSBLOS(XCHG);
SET_SAME_SYSBLOS(IN);
SET_SAME_SYSBLOS(OUT);
SET_SAME_SYSBLOS(XLAT);
SET_SAME_SYSBLOS(LEA);
SET_SAME_SYSBLOS(LDS);
SET_SAME_SYSBLOS(LES);
SET_SAME_SYSBLOS(LAHF);
SET_SAME_SYSBLOS(SAHF);
SET_SAME_SYSBLOS(PUSHF);
SET_SAME_SYSBLOS(POPF);


// ARITHMETIC
SET_SAME_SYSBLOS(ADD);
SET_SAME_SYSBLOS(ADC);
SET_SAME_SYSBLOS(INC);
SET_SAME_SYSBLOS(AAA);
SET_SAME_SYSBLOS(BAA);
SET_SAME_SYSBLOS(SUB);
SET_SAME_SYSBLOS(SSB);
SET_SAME_SYSBLOS(DEC);
SET_SAME_SYSBLOS(NEG);
SET_SAME_SYSBLOS(CMP);
SET_SAME_SYSBLOS(AAS);
SET_SAME_SYSBLOS(DAS);
SET_SAME_SYSBLOS(MUL);
SET_SAME_SYSBLOS(IMUL);
SET_SAME_SYSBLOS(AAM);
SET_SAME_SYSBLOS(DIV);
SET_SAME_SYSBLOS(IDIV);
SET_SAME_SYSBLOS(AAD);
SET_SAME_SYSBLOS(CBW);
SET_SAME_SYSBLOS(CWD);

// LOGIC
SET_SAME_SYSBLOS(NOT);
SET_SAME_SYSBLOS(SHL);
SET_SAME_SYSBLOS(SAL);
SET_SAME_SYSBLOS(SHR);
SET_SAME_SYSBLOS(SAR);
SET_SAME_SYSBLOS(ROL);
SET_SAME_SYSBLOS(ROR);
SET_SAME_SYSBLOS(RCL);
SET_SAME_SYSBLOS(RCR);
SET_SAME_SYSBLOS(AND);
SET_SAME_SYSBLOS(TEST);
SET_SAME_SYSBLOS(OR);
SET_SAME_SYSBLOS(XOR);

// STRING MANIPULATION
SET_SAME_SYSBLOS(REP);
SET_SAME_SYSBLOS(REPZ);
SET_SAME_SYSBLOS(REPNZ);
SET_SAME_SYSBLOS(MOVS);
SET_SAME_SYSBLOS(CMPS);
SET_SAME_SYSBLOS(SCAS);
SET_SAME_SYSBLOS(LODS);
SET_SAME_SYSBLOS(STOS);

// CONTROL TRANSFER
SET_SAME_SYSBLOS(CALL);
SET_SAME_SYSBLOS(JMP);
SET_SAME_SYSBLOS(RET);
SET_SAME_SYSBLOS(JZ);
SET_SAME_SYSBLOS(JE);
SET_SAME_SYSBLOS(JL);
SET_SAME_SYSBLOS(JNGE);
SET_SAME_SYSBLOS(JLE);
SET_SAME_SYSBLOS(JNG);
SET_SAME_SYSBLOS(JB);
SET_SAME_SYSBLOS(JNAE);
SET_SAME_SYSBLOS(JBE);
SET_SAME_SYSBLOS(JNA);
SET_SAME_SYSBLOS(JP);
SET_SAME_SYSBLOS(JPE);
SET_SAME_SYSBLOS(JO);
SET_SAME_SYSBLOS(JS);
SET_SAME_SYSBLOS(JNE);
SET_SAME_SYSBLOS(JNZ);
SET_SAME_SYSBLOS(JNL);
SET_SAME_SYSBLOS(JGE);
SET_SAME_SYSBLOS(JNLE);
SET_SAME_SYSBLOS(JAE);
SET_SAME_SYSBLOS(JNBE);
SET_SAME_SYSBLOS(JA);
SET_SAME_SYSBLOS(JNP);
SET_SAME_SYSBLOS(JPO);
SET_SAME_SYSBLOS(JNO);
SET_SAME_SYSBLOS(JNS);
SET_SAME_SYSBLOS(LOOP);
SET_SAME_SYSBLOS(LOOPZ);
SET_SAME_SYSBLOS(LOOPE);
SET_SAME_SYSBLOS(LOOPNZ);
SET_SAME_SYSBLOS(LOOPNE);
SET_SAME_SYSBLOS(JCXZ);
SET_SAME_SYSBLOS(INT);
SET_SAME_SYSBLOS(INT_3);
SET_SAME_SYSBLOS(INTO);
SET_SAME_SYSBLOS(IRET);

// PROCESSOR CONTROL
SET_SAME_SYSBLOS(CLC);
SET_SAME_SYSBLOS(CMC);
SET_SAME_SYSBLOS(STC);
SET_SAME_SYSBLOS(CLD);
SET_SAME_SYSBLOS(STD);
SET_SAME_SYSBLOS(CLI);
SET_SAME_SYSBLOS(STI);
SET_SAME_SYSBLOS(HLT);
SET_SAME_SYSBLOS(WAIT);
SET_SAME_SYSBLOS(ESC);
SET_SAME_SYSBLOS(LOCK);




//
// Function Implements.
//

Status 
IsaDis(
    ISA_OBJ *pISA_OBJ,
    Addr    *pAddr
    )
{
    unsigned int address;
    unsigned char prefix;
    unsigned char oneByte;
    unsigned char loopflag;
    
    
    loopflag = 1;
    
    address = TransAddrToInt(pAddr);

    //
    //  Test if oneByte is a prefix. Must keep the pISA_OBJ is the Init one.
    //
    do {
        prefix = getByte(address);
        switch (prefix) {
        case LOCK_PRFIX : 
            address++;
            AddOneIsaSize(pISA_OBJ);
            SetLockPrefix(pISA_OBJ);
            break;
        case REP_PREFIX :
            address++;
            AddOneIsaSize(pISA_OBJ);
            SetRepPrefix(pISA_OBJ);
            break;
        case REPNZ_PRFIX :
            address++;
            AddOneIsaSize(pISA_OBJ);
            SetRepnzPrefix(pISA_OBJ);
            break;
        case REG_SG_ES_PREFIX :
            AddOneIsaSize(pISA_OBJ);
            SetESPrefix(pISA_OBJ);
            break;
        case REG_SG_CS_PREFIX :
            AddOneIsaSize(pISA_OBJ);
            SetCSPrefix(pISA_OBJ);
            break;
        case REG_SG_SS_PREFIX :
            AddOneIsaSize(pISA_OBJ);
            SetSSPrefix(pISA_OBJ);
            break;
        case REG_SG_DS_PREFIX :
            AddOneIsaSize(pISA_OBJ);
            SetDSPrefix(pISA_OBJ);
            break;
        default:
            loopflag = 0;
            break;
        }
    } while (loopflag);
    
    oneByte = prefix;

//
//  Mov
//
    if (GetCodeToChar(oneByte, 2, 6) == OP_MOV_RM_TF_REG) {
        
        
    }
    
//
// reuturn flag.
//
ok:
    return STATUS_SUCCESSFUL;
    
false:
    return STATUS_FALSE;
    
    
}

Status 
AllocIsaObj(
    ISA_OBJ **ppISA_OBJ
    )
{
    int i;
    *ppISA_OBJ = (ISA_OBJ *)malloc(sizeof(ISA_OBJ));
    if (*ppISA_OBJ) {
        for(i = 0; i < sizeof(ISA_OBJ); i++) {
            ((char *)(*ppISA_OBJ))[i] = 0;
        }
        return STATUS_SUCCESSFUL;
    }
    return STATUS_FALSE;
    
}

void 
FreeIsaObj(
    ISA_OBJ *pISA_OBJ
    )
{
    free(pISA_OBJ);
}


//
// "%s %s [%s]", 
//
static void transDis(char *buffer, char *fmt, ...)
{
    int leng;
    char *str;
    va_list args;

    va_start(args, fmt);
    
    while (fmt[0]) {
        if (fmt[0] == '%' && fmt[1] == 's') {
            str = va_arg(args, char *);
            strcat(buffer, str);
            fmt += 2;
            continue;
        }
        leng = strlen(buffer);
        
        buffer[leng] = fmt[0];
        buffer[leng + 1] = 0;
        fmt++;
    }
    
    va_end(fmt);

}

static void setDisBuffer(char *buffer, char *isaSysbols, char *DestinationOp, char *SourceOp)
{
    if (SourceOp != NULL) {
        transDis(buffer, "%s %s, %s",isaSysbols, DestinationOp, SourceOp);
        return;
    }
    if (DestinationOp != NULL) {
        transDis(buffer, "%s %s",isaSysbols, SourceOp);
        return;
    }
    if(isaSysbols != NULL) {
        transDis(buffer, "%s ", isaSysbols);
    }
    return ;
}
static void setPrefixDisBuffer(char *buffer, ISA_OBJ *pISA_OBJ)
{
    if(GetRepPrefix(pISA_OBJ) == REP_PREFIX) {
        transDis(buffer, "%s ", REP);
    }
    if (GetRepPrefix(pISA_OBJ) == REPNZ_PREFIX) {
        transDis(buffer, "%s ", REPNZ);
    }
    if (GetLockPrefix(pISA_OBJ) == LOCK_PRFIX) {
        transDis(buffer, "%s ", LOCK);
    }
    switch (GetSegPrefix(pISA_OBJ)) {
    case REG_SG_ES_PREFIX :
        transDis(buffer, "%s: ", ES);
        break;
    case REG_SG_CS_PREFIX :
        transDis(buffer, "%s: ", CS);
        break;
    case REG_SG_SS_PREFIX :
        transDis(buffer, "%s: ", SS);
        break;
    case REG_SG_DS_PREFIX :
        transDis(buffer, "%s: ", DS);
        break;
    }
    return ;
}

static char *EASYSBOLS[] = {
"BX+SI",
"BX+DI",
"BP+SI",
"BP+DI",
"SI",
"DI",
"BP",
"SP"
};
static void setModDisBuffer(char *buffer, char *isaType, char flag ,ISA_OBJ *pISA_OBJ)
{
    uchar mod;
    uchar opsize;
    uchar direction.
    uchar reg;
    uchar effectaddr;
    char lowdisp;
    char highdisp;
    
    char data[20];
    char disp[20];
    
    char SourceOp[40];
    char DestinationOp[40];
    char regstr[10];

    
    data[0] = 0;
    disp[0] = 0;
    SourceOp[0] = 0;
    DestinationOp[0] = 0;
    regstr[0] = 0;

    
    direction   = GetDirection(pISA_OBJ);
    mod         = GetMod(pISA_OBJ);
    opsize      = GetIsaOpSize(pISA_OBJ);
    reg         = GetReg(pISA_OBJ);
    effectaddr  = GetEffectAddr(pISA_OBJ);
    lowdisp     = GetLowDisp(pISA_OBJ);
    highdisp    = GetHighDisp(pISA_OBJ);
    
    // set one op str.
    
    strcat(DestinationOp, getRegister(reg, opsize, flag));
    
    switch (mod) {
    case MOD_DP_ABSENT :
        if (effectaddr != RM_BP_ON_DISP) {
            strcat(SourceOp ,getEffectAddrType(MOD_DP_ABSENT));
            break;
        }
        transUWordToString(highdisp, lowdisp, disp);

        break;
    case MOD_DP_SIGEXT :
        strcat(SourceOp ,getEffectAddrType(MOD_DP_SIGEXT));
        transByteToString(disp);
        break;
    case MOD_DP_FULLHL :
        strcat(SourceOp ,getEffectAddrType(MOD_DP_FULLHL));
        transUWordToString(highdisp, lowdisp, disp);
    case MOD_DP_TRTREG :
        strcat(SourceOp, getRegister(reg, opsize, flag));
    }
    
    strcat(SourceOp, disp);
    
    setDisBuffer(buffer, isaType, DestinationOp, SourceOp);
    
}
static char *getRegister(uchar reg , uchar opsize, uchar flag)
{
    if (flag == MATCH_SREG) {
        switch (reg) {
        case SREG_ES :
            return ES;
            break;
        case SREG_CS :
            return CS;
            break;
        case SREG_SS :
            return SS;
            break;
        case SREG_DS :
            return DS;
            break;
        default :
            return NULL;
            break;
        }
        
    }
    if (opsize == ISA_OPSIZE_WORD) {
        switch (reg) {
        case REG_W_AX :
           return AX;
           break;
        case REG_W_CX :
           return CX;
           break;
        case REG_W_DX :
           return DX;
           break;
        case REG_W_BX :
           return BX;
           break;
        case REG_W_SP :
           return SP;
           break;
        case REG_W_BP :
           return BP;
           break;
        case REG_W_SI :
           return SI;
           break;
        case REG_W_DI :
           return DI;
           break;
        default :
            return NULL;
            break;
        }
    } else if (opsize == ISA_OPSIZE_BYTE) {
        switch (reg) {
        case REG_AL :
           return AL;
           break;
        case REG_CL :
           return CL;
           break;
        case REG_DL :
           return DL;
           break;
        case REG_BL :
           return BL;
           break;
        case REG_AH :
           return AH;
           break;
        case REG_CH :
           return CH;
           break;
        case REG_DH :
           return DH;
           break;
        case REG_BH :
           return BH;
           break;
        default :
            return NULL;
            break;
        }

    }
    
    return NULL;
}

static char *getEffectAddrType(uchar effectaddrtype);
{
    return EASYSBOLS[effectaddrtype];
}

// "- 0xmm"
static Status transByteToString(uchar Number, char *strb)
{
    int i = 2;
    unsigned char temp;
    strb[0] = 0;
    
    
    if (Number & 0x80) {
        strb[0] = '-';
        strb[1] = ' ';
        strb[2] = 0;
        i = 4;
        Number = (~Number) + 1;
    }
    strcat(strb, "0x");
    temp = Number & 0x0f;
    if (0 <= temp && temp <=9) {
        strb[i+1] = '0' + temp;
    } else {
        strb[i+1] = 'A' + temp - 10;
    }
    temp = Number & 0xf0;
    
    temp >>= 4;
     if (0 <= temp && temp <= 9) {
        strb[i] = '0' + temp;
    } else {
        strb[i] = 'A' + temp - 10;
    }
    strb[i+2] = 0;
    
    
    return STATUS_SUCCESSFUL;
}
static Status transWordToString(uchar NumberHigh, uchar NumberLow, char *strb)
{
    
    
}
static Status transUByteToString(uchar Number, char *strb)
{
    
    
}
static Status transUWordToString(uchar NumberHigh, uchar NumberLow, char *strb)
{
    
    
    
}