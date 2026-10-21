/* Near miss of func_00392868 with its file's own flags: tools/check.py reports 84 diff
   (the US draft it started from: 85).
   What differs: 84 diffs left. What was fixed: the global D_001DA050 is now reached with `lui
   %hi`/`lw %lo` (declared as an unsized array `extern u32 *D_001DA050_00392868_x[];`, per
   docs/wiki/Matching-Patterns.md) instead of `$gp`, the final pointer update is `D[0] = D[0] +
   n*4 + 0x14` (same bytes as the draft's `+=`), and the loop body is now instruction-for-
   instruction the same shape as retail. What still differs: (1) the three 64-bit constants (9
   bytes) - retail's `ori $r,$zero,0x8000; dsll/dsll32 shift; ori lo` is Ps2EeAs's expansion of
   the `li` macro (that is the @ps2as form the US matched with),...
*/

/* US draft of func_00392868 (rac3-uya-decomp func_0038E030, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override). */

/* localdecomp:start func_00392868 */
extern u32 *D_001DA050_00392868_x[];
extern void func_003A9440(s32, unsigned long);
void func_00392868(s32 x, s32 y) {
    s32 n = x / 32;
    unsigned long *p, *q, *r;
    s32 i, a, b, lo, hi;
    func_003A9440(0x42, (0x8000UL << 24) | 0x4A);
    D_001DA050_00392868_x[0][0] = (n + 5) | 0x10000000;
    D_001DA050_00392868_x[0][1] = 0;
    D_001DA050_00392868_x[0][2] = 0;
    D_001DA050_00392868_x[0][3] = (n + 5) | 0x50000000;
    p = (unsigned long *)D_001DA050_00392868_x[0];
    r = p + 2;
    D_001DA050_00392868_x[0] = (u32 *)r;
    p[2] = (0x8000UL << 45) | 1;
    r[1] = 0xE;
    r[2] = 0x32003;
    r[3] = 0x47;
    r[4] = (0x9000UL << 46) | 1;
    r[5] = 0x10;
    r[6] = 0x146;
    r[7] = (0x8000UL << 16) | 0x8080;
    r[8] = n | 0x8000 | (0x9000UL << 46);
    r[9] = 0x44;
    i = 0;
    if (n > i) {
        unsigned long t0, t1;
        a = y * 8;
        t0 = (unsigned long)(0x8000 - a) << 16;
        t1 = (unsigned long)(a + 0x7FF0) << 16;
        b = -(x * 8);
        lo = b + 0x8000;
        hi = b + 0x8200;
        q = p + 12;
        do {
            *q++ = lo | t0;
            *q++ = hi | t1;
            hi += 0x200;
            lo += 0x200;
            i++;
        } while (i < n);
    }
    D_001DA050_00392868_x[0] = D_001DA050_00392868_x[0] + n * 4 + 0x14;
}
/* localdecomp:end func_00392868 */
