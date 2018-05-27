//
// Created by nb1317 on 5/25/18.
//

#ifndef PROJECT_USEFULCONSTANTS_H
#define PROJECT_USEFULCONSTANTS_H

//instead of having a 32 bit mask, we'll shift the bits stored in the CPSR to get the remaining 4 bits
#define N_MASK 0x8
#define Z_MASK 0X4
#define C_MASK 0x2
#define V_MASK 0x1

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
