#include "common.h"

/* localdecomp:start func_L09_003BFFC0 */
extern s32 func_0038CB00(u8 *);
extern s32 func_003A52A0(s32, s32, u8 *);

void func_L09_003BFFC0(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    if (func_0038CB00(p + 0xD30)) {
        func_003A52A0(9, 0, a0);
        *(s16 *)(p + 0xD30) = 0x1388;
    }
    if (func_0038CB00(p + 0xD34)) {
        a0[0x23] -= 2;
        if ((u8)(a0[0x23] - 1) >= 0x7F) {
            *(u16 *)(a0 + 0x34) |= 0x41;
        }
    }

}
/* localdecomp:end func_L09_003BFFC0 */
