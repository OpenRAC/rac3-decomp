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


/* localdecomp:start func_003D72B0 */
void func_003D72B0(u8 **pp, s32 a1, s32 w, s32 h, s32 a4, s32 w2, s32 h2) {
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
        { s32 t; __asm__("plzcw %0, %1" : "=r"(t) : "r"(w));
        lw = 0x1F - t; }
    } else {
        { s32 t; __asm__("plzcw %0, %1" : "=r"(t) : "r"(w));
        lw = 0x1E - t; }
    }
    if (h & (h - 1)) {
        { s32 t; __asm__("plzcw %0, %1" : "=r"(t) : "r"(h));
        lh = 0x1F - t; }
    } else {
        { s32 t; __asm__("plzcw %0, %1" : "=r"(t) : "r"(h));
        lh = 0x1E - t; }
    }
    func_003D7080((long **)pp, a1, w, h, w >> 6, lw, lh, a4, w2, h2, w2 >> 6, k1, k2,
                  ow, oh, 0, 0, sw, sh);
}
/* localdecomp:end func_003D72B0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003D73D8);

LINKER_REMNANT("asm/remnants", func_003D7848);

/* localdecomp:start func_003D7850 */
extern void func_003D73D8(s32, s32, s32, s32, s32);
 
void func_003D7850(s32 a0, s32 a1, s32 a2) {
    func_003D73D8(a0, a1, 0x100, 0x100, a2);
}
/* localdecomp:end func_003D7850 */

/* localdecomp:start func_003D7878 */
extern void func_003D73D8(s32, s32, s32, s32, s32);
 
void func_003D7878(s32 a0, s32 a1, s32 a2) {
    func_003D73D8(a0, a1, 0x80, 0x80, a2);
}
/* localdecomp:end func_003D7878 */

/* localdecomp:start func_003D78A0 */
extern void func_003D73D8(s32, s32, s32, s32, s32);
 
void func_003D78A0(s32 a0, s32 a1, s32 a2) {
    func_003D73D8(a0, a1, 0x40, 0x40, a2);
}
/* localdecomp:end func_003D78A0 */

LINKER_REMNANT("asm/remnants", func_003D78C8);
