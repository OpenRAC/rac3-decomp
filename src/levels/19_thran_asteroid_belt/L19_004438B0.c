#include "common.h"

/* localdecomp:start func_L19_004438B0 */
extern u8 D_001A4BE0[];

/* from rac2-decomp's func_L00_00324120, renamed, constants adapted */
s32 func_L19_004438B0(s32 a0) {
    u8 *b = D_001A4BE0;
    if (*(s32 *)(b + 0x25cc) == 3 || *(s32 *)(b + 0x25c4) == 0x1B) {
        if (*(s32 *)(b + 0x538) != a0)
            goto Lzero;
        return 1;
    }
    if (*(short *)(b + 0x36e) != 0)
        goto Lzero;
    if (*(s32 *)(b + 0x35c) == a0) {
        return 1;
    }
Lzero:
    return 0;
}
/* localdecomp:end func_L19_004438B0 */
