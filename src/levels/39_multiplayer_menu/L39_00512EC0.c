#include "common.h"

/* localdecomp:start func_L39_00512EC0 */
typedef struct { s32 unk0; s32 unk4; unsigned long *unk8; } S_00512EC0;
extern unsigned long func_001306F8(unsigned long, unsigned long);
s32 func_L39_00512EC0(S_00512EC0 *arg0, unsigned long *arg1) {
    unsigned long x = *arg0->unk8;
    unsigned long bit, r, mask;
    s32 i;
    if ((x & 1) == 0) {
        return 0x107;
    }
    mask = 3;
    bit = 2;
    r = 1;
    if ((x & mask) > bit) {
        r += bit;
    }
    for (i = 0x3D; i >= 0; i--) {
        bit <<= 1;
        mask |= bit;
        if ((func_001306F8(x, r) & mask) > bit) {
            r += bit;
        }
    }
    *arg1 = ~r + 1;
    return 0;
}
/* localdecomp:end func_L39_00512EC0 */
