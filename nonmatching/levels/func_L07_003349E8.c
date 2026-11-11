/* near miss (level 7, Annihilation Nation): 9 differences, all register numbers (retail bit in $v1, index first in the addu); tried an early return, a struct member, base+offset and index+offset forms (5 wordings) */
#include "common.h"

/* localdecomp:start func_L07_003349E8 */
typedef struct { u8 pad[0xAD]; u8 bits[1]; } S_003349E8;
extern S_003349E8 D_001426E0_003349E8;
s32 func_L07_003349E8(s32 arg0) {
    u32 bit = arg0 & 7;
    s32 idx = arg0 >> 3;
    if (bit >= 8) {
        return 0;
    }
    return D_001426E0_003349E8.bits[idx] & (1 << bit);
}
/* localdecomp:end func_L07_003349E8 */
