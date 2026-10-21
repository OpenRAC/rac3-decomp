/* US draft of func_003A9830 (rac3-uya-decomp func_003A42E0, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003A9830 */
extern void func_12C9A0(s32, s16, s16, s16, s16, s16, s16, s16);
long func_003A9830(s32 src, s32 dst, s32 w, s32 h) {
    s32 tw, th, t, t2, t3;
    s32 size, chunk, i;
    s32 p;
    __asm__("plzcw %0, %1" : "=r"(t) : "r"(w));
    tw = 0x1E - t;
    if (w & (w - 1)) tw++;
    chunk = w << 7;
    __asm__("plzcw %0, %1" : "=r"(t2) : "r"(h));
    th = 0x1E - t2;
    if (h & (h - 1)) th++;
    size = w * (h << 2);
    t3 = size - 1;
    size = (t3 + chunk) & -chunk;
    i = 0;
    while (size > 0) {
        *(s32 *)(D_001DA050 + 0) = 0x10000006;
        *(s32 *)(D_001DA050 + 4) = 0;
        *(s32 *)(D_001DA050 + 8) = 0;
        *(s32 *)(D_001DA050 + 0xC) = 0x50000006;
        size -= chunk;
        D_001DA050 = D_001DA050 + 0x10;
        func_12C9A0(D_001DA050, (dst + i) >> 8, w >> 6, 0, 0, 0, w, 0x20);
        p = D_001DA050;
        D_001DA050 = p + 0x60;
        *(s32 *)(p + 0x60) = (chunk >> 4) | 0x30000000;
        *(s32 *)(D_001DA050 + 4) = src + i;
        *(s32 *)(D_001DA050 + 8) = 0;
        *(s32 *)(D_001DA050 + 0xC) = (chunk >> 4) | 0x50000000;
        i += chunk;
        D_001DA050 = D_001DA050 + 0x10;
    }
    return (dst >> 8) | ((long)(w >> 6) << 14) | ((long)tw << 26) | ((long)th << 30) | (0x8000UL << 19);
}
/* localdecomp:end func_003A9830 */
