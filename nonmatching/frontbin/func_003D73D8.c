/* US draft of func_003D73D8 (rac3-uya-decomp func_003D1E68, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003D73D8 */
void func_003D73D8(s32 p0, s32 a1, s32 w, s32 h, s32 a4) {
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
    func_003D6AE0(pp, 0xA0, 0xA0, 0, 0, ow, oh, sw, sh);
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
    func_003D6AE0(pp, 0xA0, 0xA0, 0x10, 0x10, ow, oh, ow1, oh1);
    *(*pp)++ = 0x1000000000008001UL;
    *(*pp)++ = 0xEEEEEEEEEEEEEEEEUL;
    *(*pp)++ = 0;
    *(*pp)++ = 0x3F;
}
/* localdecomp:end func_003D73D8 */
