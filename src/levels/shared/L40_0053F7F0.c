#include "common.h"

/* localdecomp:start func_L40_0053F7F0 */
typedef struct {
    u8 pad0[0x8];
    s32 w8;
    u8 padC[0x12C - 0xC];
    s32 w12C;
} S_0053F7F0;

extern S_0053F7F0 D_001A5CD0;
extern s32 func_L39_0061CF78(s32);
extern s32 func_L39_0066C4D8(s32);

s32 func_L40_0053F7F0(s32 arg0) {
    s32 r = arg0 % D_001A5CD0.w12C;

    if (r == D_001A5CD0.w8) {
        return 1;
    }
    if (func_L39_0061CF78(r) != 0) {
        return 0;
    }
    return func_L39_0066C4D8(r);
}
/* localdecomp:end func_L40_0053F7F0 */

INCLUDE_ASM("asm/levels", func_L40_0053F850);
