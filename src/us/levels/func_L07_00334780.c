#include "common.h"

/* localdecomp:start func_L07_00334780 */
extern void func_L07_003A0BC0(u8, u8 *, s32, s32);
extern s32 func_0037E1D8(s32);
extern s32 func_0037E208(s32, s32);

s32 func_L07_00334780(u8 *a0) {
    u8 *st = *(u8 **)(a0 + 0x68);
    s32 flags = *(s32 *)(st + 0xE0);

    if (flags & 1) {
        if ((flags & 2) == 0) {
            func_L07_003A0BC0(0x3D, a0, 0, 0x78);
            func_L07_003A0BC0(0x3E, a0, 0, 0x2D0);
            *(s32 *)(st + 0xE0) |= 2;
            return 1;
        }
    }
    if (((st[0xE0] ^ 1) & 1) != 0) {
        func_L07_003A0BC0(0x3C, a0, 0, 0x78);
        *(s32 *)(st + 0xE0) |= 1;
        return 1;
    }
    if (func_0037E1D8(2) != 0) {
        func_L07_003A0BC0(func_0037E208(0x62, 0x69), a0, 0, 0x78);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L07_00334780 */
