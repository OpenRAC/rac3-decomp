#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003D8CF0 */
extern s32 D_001A1ED0_003D8CF0[];

void func_003D8CF0(unsigned long **pp, s32 w, s32 h, s32 fbw, s32 x0, s32 y0, s32 x1, s32 y1, s32 z) {
    *(*pp)++ = 0x2000000000000001UL;
    *(*pp)++ = 0xEE;
    *(*pp)++ = 0;
    *(*pp)++ = 0x3F;
    *(*pp)++ = (unsigned long)(D_001A1ED0_003D8CF0[2] >> 13) | 0x31000000;
    *(*pp)++ = 0x4F;
    *(*pp)++ = 0x4000000000000001UL;
    *(*pp)++ = 0xEEEEEEEEEEEEEEEEUL;
    *(*pp)++ = 0;
    *(*pp)++ = 0x19;
    *(*pp)++ = ((unsigned long)(w - 1) << 16) | ((unsigned long)(h - 1) << 48);
    *(*pp)++ = 0x41;
    *(*pp)++ = (unsigned long)(D_001A1ED0_003D8CF0[1] >> 13) | ((unsigned long)fbw << 16) | (0xFFFFFFUL << 32);
    *(*pp)++ = 0x4D;
    *(*pp)++ = 0x70802;
    *(*pp)++ = 0x48;
    *(*pp)++ = 0x4400000000000001UL;
    *(*pp)++ = 0x5510;
    *(*pp)++ = 0x306;
    *(*pp)++ = 0xFFFFFF;
    *(*pp)++ = (unsigned long)x0 | ((unsigned long)y0 << 16) | ((unsigned long)z << 32);
    *(*pp)++ = (unsigned long)x1 | ((unsigned long)y1 << 16) | ((unsigned long)z << 32);
    *(*pp)++ = 0x1000000000008001UL;
    *(*pp)++ = 0xEEEEEEEEEEEEEEEEUL;
    *(*pp)++ = 0;
    *(*pp)++ = 0x3F;
    *(*pp)++ = 0x1000000000008001UL;
    *(*pp)++ = 0xE;
    *(*pp)++ = 0;
    *(*pp)++ = 0x3F;
}
/* localdecomp:end func_003D8CF0 */
