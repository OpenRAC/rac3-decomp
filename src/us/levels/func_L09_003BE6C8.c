#include "common.h"

/* NTSC-U counterpart of func_L09_003BFFC0 (src/levels/09_tyhrranosis/L09_003BFFC0.c): 5000 -> 6000 */
/* localdecomp:start func_L09_003BE6C8 */
extern s32 func_0038CB00(u8 *);
extern s32 func_003A52A0(s32, s32, u8 *);

void func_L09_003BE6C8(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    if (func_0038CB00(p + 0xD30)) {
        func_003A52A0(9, 0, a0);
        *(s16 *)(p + 0xD30) = 0x1770;
    }
    if (func_0038CB00(p + 0xD34)) {
        a0[0x23] -= 2;
        if ((u8)(a0[0x23] - 1) >= 0x7F) {
            *(u16 *)(a0 + 0x34) |= 0x41;
        }
    }

}
/* localdecomp:end func_L09_003BE6C8 */
