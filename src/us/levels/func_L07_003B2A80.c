#include "common.h"

/* NTSC-U counterpart of func_L07_003B4370 (src/levels/07_annihilation_nation/L07_003AF398.c) */
/* localdecomp:start func_L07_003B2A80 */
extern void func_L07_003B1F10(void *, s32);
extern s32 func_0037E1D8(s32);

void func_L07_003B2A80(u8 *a0)
{
    u8 *p = *(u8 **)(a0 + 0x68);

    switch (a0[0x95]) {
    case 1:
        if (p[0x668] >= 6) {
            p[0x668] = 0;
            func_L07_003B1F10(a0, 6);
            *(s16 *)(p + 0x660) = func_0037E1D8(0x64) + 0xFA;
            break;
        }
        /* fall through */
    case 0:
        func_L07_003B1F10(a0, 9);
        p[0x666] = 3;
        break;
    case 2:
        if (p[0x668] >= 3) {
            p[0x668] = 0;
            func_L07_003B1F10(a0, 6);
            *(s16 *)(p + 0x660) = func_0037E1D8(0xC8) + 0x1F4;
        } else {
            func_L07_003B1F10(a0, 9);
            p[0x666] = func_0037E1D8(2) + 3;
        }
        break;
    case 3:
        func_L07_003B1F10(a0, 7);
        *(s16 *)(p + 0x660) = func_0037E1D8(0x190) + 0x3E8;
        break;
    }
}
/* localdecomp:end func_L07_003B2A80 */
