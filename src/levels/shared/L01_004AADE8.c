#include "common.h"

INCLUDE_ASM("asm/levels", func_L01_004AADE8);

/* localdecomp:start func_L01_004AAE90 */
extern s32 D_L01_001DFB68;
extern u8 *D_L01_001DFB6C;
extern u8 D_001A30B0[];
extern s32 func_003A4FF8(u8 *, s32, s32, s32, s32);

s32 func_L01_004AAE90(s32 idx, s32 a1, s32 a2, s32 a3)
{
    s32 r;
    u8 *e;

    if (idx >= D_L01_001DFB68 || idx == 0xFFFFFFFF) {
        return -1;
    }
    r = func_003A4FF8(D_L01_001DFB6C + idx * 32, a1, 0, a2 + 64, a3);
    if (r >= 0) {
        e = D_001A30B0 + r * 128;
        *(s32 *)(e + 256) = a2;
        *(s16 *)(e + 202) = idx;
    }
    return r;
}
/* localdecomp:end func_L01_004AAE90 */

/* localdecomp:start func_L01_004AAF20 */
extern s32 D_L01_001D669C;
extern s32 D_L01_001DFB68;
extern u8 *D_L01_001DFB6C;
extern u8 D_001A30B0[];
extern s32 func_003A4FF8(u8 *, s32, s32, s32, s32);

s32 func_L01_004AAF20(u32 a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    s32 idx;
    s32 r;
    u8 *p;

    if (a == 0xFFFFFFFF) {
        return -1;
    }
    idx = a * 4 + b * 2 + c + D_L01_001D669C;
    if (idx >= D_L01_001DFB68) {
        return -1;
    }
    r = func_003A4FF8(D_L01_001DFB6C + idx * 32, d, e, 0, f);
    if (r >= 0) {
        p = D_001A30B0 + (r << 7);
        *(s32 *)(p + 220) = e;
        *(s16 *)(p + 202) = idx;
    }
    return r;
}
/* localdecomp:end func_L01_004AAF20 */

INCLUDE_ASM("asm/levels", func_L01_004AAFD0);

LINKER_REMNANT("asm/levels", func_L01_004AB010);
