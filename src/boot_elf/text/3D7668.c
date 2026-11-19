#include "common.h"
#include "vu0.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 3D6C70.c's earlier functions (tools/port_from_us.py) */
extern void func_003D6E98(long **, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 D_001D5600;
extern s32 D_001D5604;
extern s32 D_001D4BD0_003D6F78;
extern s32 D_001D4BD4_003D6F78;
extern void func_003D6E98(long **, s32, s32, s32, s32, s32, s32, s32, s32);

/* localdecomp:start func_003D7668 */
#include "vu0.h"
void func_003D7668(u8 **pp, s32 a1, s32 w, s32 h, s32 a4, s32 w2, s32 h2) {
    s32 lw, lh;
    s32 sw, sh, ow, oh;
    s32 k1, k2;
    sw = w << 4;
    sh = h << 4;
    ow = (w2 << 4) + 0x98;
    oh = (h2 << 4) + 0x98;
    k1 = 0x98;
    k2 = 0x98;
    w = (w > 0x3F) ? w : 0x40;
    h = (h > 0x3F) ? h : 0x40;
    w2 = (w2 > 0x3F) ? w2 : 0x40;
    h2 = (h2 > 0x3F) ? h2 : 0x40;
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
    func_003D7438((long **)pp, a1, w, h, w >> 6, lw, lh, a4, w2, h2, w2 >> 6, k1, k2,
                  ow, oh, 0, 0, sw, sh);
}
/* localdecomp:end func_003D7668 */

/* localdecomp:start func_003D7790 */
void func_003D7790(s32 p0, s32 a1, s32 w, s32 h, s32 a4) {
    long **pp = (long **)p0;
    s32 lw, lh;
    s32 ow, oh, sw, sh, ow1, oh1;
    sw = w << 4;
    ow = sw + 0xA0;
    sh = h << 4;
    ow1 = (w + 1) << 4;
    oh = sh + 0xA0;
    oh1 = (h + 1) << 4;
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
    *(*pp)++ = 0x5000000000000001UL;
    *(*pp)++ = 0xEEEEEEEEEEEEEEEEUL;
    *(*pp)++ = ((long)(w - 1) << 16) | ((long)(h - 1) << 48);
    *(*pp)++ = 0x41;
    *(*pp)++ = (a1 >> 8) | ((long)(w >> 6) << 14) | ((long)lw << 26) | ((long)lh << 30) | 0x400000000UL;
    *(*pp)++ = 7;
    *(*pp)++ = (a4 >> 13) | ((long)(w >> 6) << 16);
    *(*pp)++ = 0x4D;
    *(*pp)++ = 0x60;
    *(*pp)++ = 0x15;
    *(*pp)++ = 5;
    *(*pp)++ = 9;
    *(*pp)++ = 0x2400000000000001UL;
    *(*pp)++ = 1;
    *(*pp)++ = 0x80808080;
    *(*pp)++ = 0x316;
    func_003D6E98(pp, 0xA0, 0xA0, 0, 0, ow, oh, sw, sh);
    *(*pp)++ = 0x1000000000000001UL;
    *(*pp)++ = 0xEEEEEEEEEEEEEEEEUL;
    *(*pp)++ = 0;
    *(*pp)++ = 0x3F;
    *(*pp)++ = 0x2000000000000001UL;
    *(*pp)++ = 0xEEEEEEEEEEEEEEEEUL;
    *(*pp)++ = (a4 >> 8) | ((long)(w >> 6) << 14) | ((long)lw << 26) | ((long)lh << 30) | 0x400000000UL;
    *(*pp)++ = 7;
    *(*pp)++ = (a1 >> 13) | ((long)(w >> 6) << 16);
    *(*pp)++ = 0x4D;
    *(*pp)++ = 0x2400000000000001UL;
    *(*pp)++ = 1;
    *(*pp)++ = 0x80808080;
    *(*pp)++ = 0x316;
    func_003D6E98(pp, 0xA0, 0xA0, 0x10, 0x10, ow, oh, ow1, oh1);
    *(*pp)++ = 0x1000000000008001UL;
    *(*pp)++ = 0xEEEEEEEEEEEEEEEEUL;
    *(*pp)++ = 0;
    *(*pp)++ = 0x3F;
}
/* localdecomp:end func_003D7790 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003D7C00);

/* localdecomp:start func_003D7C08 */
extern void func_003D7790(s32, s32, s32, s32, s32);
 
void func_003D7C08(s32 a0, s32 a1, s32 a2) {
    func_003D7790(a0, a1, 0x100, 0x100, a2);
}
/* localdecomp:end func_003D7C08 */

/* localdecomp:start func_003D7C30 */
extern void func_003D7790(s32, s32, s32, s32, s32);
 
void func_003D7C30(s32 a0, s32 a1, s32 a2) {
    func_003D7790(a0, a1, 0x80, 0x80, a2);
}
/* localdecomp:end func_003D7C30 */

/* localdecomp:start func_003D7C58 */
extern void func_003D7790(s32, s32, s32, s32, s32);
 
void func_003D7C58(s32 a0, s32 a1, s32 a2) {
    func_003D7790(a0, a1, 0x40, 0x40, a2);
}
/* localdecomp:end func_003D7C58 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003D7C80);
