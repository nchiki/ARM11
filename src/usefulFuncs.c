#include <stdio.h>
#include <stdint.h>
#include "usefulFuncs.h"
#include "emulate_utils/instruction_basic.h"

//extracts any number of bits from any starting index
uint32_t getBitRange(uint32_t num, int start, int length){
    uint32_t res = 0;
    for(int i = start; i < start + length; i++){
        res += (1 << i) & num;
    }
    return (res >> start);
}
//

