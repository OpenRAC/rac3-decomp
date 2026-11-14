#include "common.h"

/* localdecomp:start func_L07_003B52E8 */
extern s32 func_0037E1D8(s32);
extern void func_L07_003B4BE0(u8 *, s32);
extern s32 func_L07_003A0BC0(s32, u8 *, s32, s32);
extern void func_L01_00452F40(u8 *, s32);

void func_L07_003B52E8(u8 *a0, s32 a1) {
    u8 *s = *(u8 **)(a0 + 0x68);
    s32 old = s[0x31F];
    s32 changed = old != a1;

    if (changed) {
        *(f32 *)(s + 0x310) = *(f32 *)(s + 0x30);
        s[0x31F] = a1;
        s[0x320] = 0;
    }
    if (a1 == 0) {
        if (changed || func_0037E1D8(4) == 0) {
            func_L07_003B4BE0(a0, 6);
        } else {
            func_L07_003B4BE0(a0, 7);
        }
    } else if (a1 == 1) {
        if (*(s16 *)(s + 0x328) == 0) {
            func_L07_003A0BC0(4, a0, 0, 0x78);
            *(s16 *)(s + 0x328) = 0x258;
        }
        if (changed || func_0037E1D8(4) == 0) {
            func_L07_003B4BE0(a0, 0xB);
        } else {
            func_L07_003B4BE0(a0, 0xC);
        }
    }
    func_L01_00452F40(a0, 0);
}
/* localdecomp:end func_L07_003B52E8 */
