
#ifndef PROJECT_USEFULCONSTANTS_H
#define PROJECT_USEFULCONSTANTS_H

//instead of having a 32 bit mask, we'll shift the bits stored in the CPSR to get the remaining 4 bits
#define N_MASK 0x8
#define Z_MASK 0X4
#define C_MASK 0x2
#define V_MASK 0x1
#define Branch_MASK 0x08000000
#define SDT_MASK 0x04000000
#define Multiply_MASK1 0x00000080
#define Multiply_MASK2 0x00000010
#define Z_MASK_32 0x4000


typedef enum {
    EQ = 0,
    NE = 1,
    GE = 0xA,
    LT = 0xB,
    GT = 0xC,
    LE = 0xD,
    AL = 0xE
}cond_code;

typedef enum {
    Halt,
    None,
    Branch,
    Mult,
    SDT,
    DProc
} instruction_type;



#endif //PROJECT_USEFULCONSTANTS_H
