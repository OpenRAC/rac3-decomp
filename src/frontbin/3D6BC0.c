#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations carried from the file this was cut from */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);


extern s32 D_001D5600;
extern s32 D_001D5604;
extern s32 D_001D4BD0_003D6BC0;
extern s32 D_001D4BD4_003D6BC0;
/* localdecomp:start func_003D6BC0 */
#include "vu0.h"
extern void func_003D6AE0(long **, s32, s32, s32, s32, s32, s32, s32, s32);
void func_003D6BC0(u8 **pp8, s32 a1, s32 w, s32 h, s32 a4, s32 a5, s32 a6) {
    long **pp = (long **)pp8;
    s32 lw, lh, x, y, z;
    s32 ow, oh;
    ow = (w << 4) + 8;
    oh = (h << 4) + 8;
    w = (w > 0x3F) ? w : 0x40;
    h = (h > 0x3F) ? h : 0x40;
    if (w & (w - 1)) {
        lw = 0x1F - plzcw_asm(w);
    } else {
        lw = 0x1E - plzcw_asm(w);
    }
    if (h & (h - 1)) {
        lh = 0x1F - plzcw_asm(h);
    } else {
        lh = 0x1E - plzcw_asm(h);
    }
    if (a4 != 0) {
        x = 2; y = 2; z = 1;
    } else if (a5 != 0) {
        x = 1; y = 1; z = 1;
    } else {
        x = 2; y = 2; z = 2;
    }
    *(*pp)++ = 0x4000000000000001UL;
    *(*pp)++ = 0xEEEE;
    *(*pp)++ = ((long)x << 2) | ((long)y << 4) | ((long)z << 6) | ((long)a6 << 32);
    *(*pp)++ = 0x42;
    *(*pp)++ = 5;
    *(*pp)++ = 8;
    *(*pp)++ = (a1 >> 8) | ((long)(w >> 6) << 14) | ((long)lw << 26) | ((long)lh << 30) | 0x400000000UL;
    *(*pp)++ = 6;
    *(*pp)++ = 0x31001;
    *(*pp)++ = 0x47;
    *(*pp)++ = 0x2400000000000001UL;
    *(*pp)++ = 1;
    *(*pp)++ = 0x80808080;
    *(*pp)++ = 0x156;
    func_003D6AE0(pp, D_001D4BD0_003D6BC0 - 8, D_001D4BD4_003D6BC0 - 8, 8, 8,
                  (D_001D5600 << 4) + D_001D4BD0_003D6BC0 - 8, (D_001D5604 << 4) + D_001D4BD4_003D6BC0 - 8, ow, oh);
    *(*pp)++ = 0x1000000000008001UL;
    *(*pp)++ = 0xE;
    *(*pp)++ = 0;
    *(*pp)++ = 0x3F;
    *(*pp)++ = 0x1400000000000001UL;
    *(*pp)++ = 0xEEEEEEEEEEEEEEEEUL;
    *(*pp)++ = 0x60;
    *(*pp)++ = 0x14;
}
/* localdecomp:end func_003D6BC0 */
