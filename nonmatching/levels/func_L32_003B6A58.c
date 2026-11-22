/* PAL near miss (wave 12 retry r01): 25 words differ with the file's flags (the wave 11 draft: 120).
 * Changed against the draft: D_L32_001DEE74/EE78 are read as D_L32_001DEE70_sdata[2]/[1] and
 * D_L32_001DFE1C is an unsized extern, both with section(".sdata") and no .extern hint (the
 * Matching-Patterns recipe): gcc emits one lw/la macro per table, counts the offset forms as two
 * instructions (so the div stays in each arm's b delay slot, as retail) and loop.c has no split
 * %hi to hoist; the 0x210 stride is a local set before loop 2 (retail keeps it in s7: frame 0x60);
 * the first loop is written as a goto loop (37 with the for loop: its loop notes double i's
 * reference weight, so i outranks st in global-alloc).
 * Left: callee-saved permutation slot s3/s1, i s1/s2, obj s2/s3 (global-alloc priorities slot
 * 0.353 < obj 0.358 < i 0.395; retail needs st > slot > i > obj), and tbl[i]'s reload address
 * addu s4,s5 where retail has addu s5,s4.
 */
#include "common.h"

/* localdecomp:start func_L32_003B6A58 */
extern s32 D_L32_001DF9C0;
extern s32 D_L32_001DEE70;
extern s32 D_L32_001DEE70_sdata[] __attribute__((section(".sdata")));
typedef int u128_003B6A58 __attribute__((mode(TI)));
typedef struct Q_003B6A58 {
    u8 pad00[0x80];
    u8 f80[0x210 - 0x80];
} Q_003B6A58;
typedef struct R_003B6A58 {
    u8 pad00[0x68];
    Q_003B6A58 *f68;
    u8 pad6C[0x100 - 0x6C];
} R_003B6A58;
extern R_003B6A58 *D_L32_001DFE1C[] __attribute__((section(".sdata")));

void func_L32_003B6A58(u8 *obj)
{
    extern void func_003C2F58(void *, s32, void *);
    extern s32 func_00382498(s32, s32);
    extern u8 *func_L32_0039FE78(u128_003B6A58 *, s32, s32, f32 *, f32 *);
    u8 *st;
    u8 **tbl;
    u8 **q, **slot;
    s32 i, flag, found, n, j, lo, hi, off, size;
    u128_003B6A58 vec;
    f32 y;
    f32 *p;

    flag = 0;
    st = *(u8 **)(obj + 0x68);
    tbl = (u8 **)(st + 0x150);
    q = tbl;
    i = 0x2F;
loop1:
    if (*q != 0) {
        if (!((*q)[0x20] < 0xFD)) {
            *q = 0;
        }
    }
    i--;
    q++;
    if (i >= 0) goto loop1;
    y = *(f32 *)(obj + 0x10);
    if (!(*(f32 *)(st + 0x22C) < y)) {
        if (*(f32 *)(st + 0x228) < y) {
            flag = (D_L32_001DF9C0 % D_L32_001DEE70_sdata[2]) == 0;
        } else if (*(f32 *)(st + 0x224) < y) {
            flag = (D_L32_001DF9C0 % D_L32_001DEE70_sdata[1]) == 0;
        } else if (*(f32 *)(st + 0x238) < y) {
            flag = (D_L32_001DF9C0 % D_L32_001DEE70) == 0;
        }
    }
    if (flag) {
        found = 0;
        i = 0;
        size = 0x210;
        for (; i < 0x30 && !found; i++) {
            slot = &tbl[i];
            if (*slot == 0) {
                found = 1;
                func_003C2F58(obj, 1, &vec);
                if (*(f32 *)(obj + 0x10) > *(f32 *)(st + 0x228)) {
                    hi = 3;
                    lo = 2;
                } else {
                    hi = 1;
                    lo = 0;
                }
                n = func_00382498(lo, hi);
                off = n * size + 0x80;
                *slot = func_L32_0039FE78(&vec, (s32)D_L32_001DFE1C[0][*(s32 *)(st + 0x230)].f68 + off, 1, 0, 0);
                if (tbl[i] != 0) {
                    p = (f32 *)(*(u8 **)(tbl[i] + 0x68) + 0x100);
                    for (j = 0x1F; j >= 0; j--, p++) {
                        p[-0x20] += *(f32 *)(obj + 0x10) - *(f32 *)(st + 0x130);
                        p[0] += *(f32 *)(obj + 0x18) - *(f32 *)(st + 0x250);
                    }
                }
            }
        }
    }
}
/* localdecomp:end func_L32_003B6A58 */
