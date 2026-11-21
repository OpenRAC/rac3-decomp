/* PAL near miss (Codex wave 11): near miss: 120 words differ in its file's context with the file's flags.
 * Replaces the earlier draft (shared-2 worker draft (2026-11-16): does not compile under tools/check.py in its file's context with the file's flags, measured 2026-11-21;
 * this one: 120).
 * Worker's note: likely NEEDS flags '-O2 -G8 -fopt-stack -mno-check-zero-division -mno-split-addresses' (not proven): retail reaches D_L32_001DEE74/EE78/DFE1C as unsplit lui+lw macros (never in a delay slot: the b slots hold the div from the join; the loop's lui is not hoisted), which only N mode gives; with --mode N (W/func_L32_003B6A58.modeN.log) the whole flag block and arg setup match, 78 diff left: 0x210 not hoisted into s7 (frame 0x50 vs 0x60) and saved-register permutation (st s1/s0, obj s2/s3, i s0/s2, slot s3/s1); file line gives 120 (prior draft 92). Draft uses the callee's definition type u8 *(u128 *, s32, s32, f32 *, f32 *), lo/hi locals (retail sets a1 before a0), off = n * 0x210 + 0x80
 */
#include "common.h"

/* localdecomp:start func_L32_003B6A58 */
extern s32 D_L32_001DF9C0;
extern s32 D_L32_001DEE70;
extern s32 D_L32_001DEE74[];
extern s32 D_L32_001DEE78[];
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
extern R_003B6A58 *D_L32_001DFE1C[];

void func_L32_003B6A58(u8 *obj)
{
    extern void func_003C2F58(void *, s32, void *);
    extern s32 func_00382498(s32, s32);
    extern u8 *func_L32_0039FE78(u128_003B6A58 *, s32, s32, f32 *, f32 *);
    u8 *st;
    u8 **tbl;
    u8 **q, **slot;
    s32 i, flag, found, n, j, lo, hi, off;
    u128_003B6A58 vec;
    f32 y;
    f32 *p;

    flag = 0;
    st = *(u8 **)(obj + 0x68);
    tbl = (u8 **)(st + 0x150);
    q = tbl;
    for (i = 0x2F; i >= 0; i--, q++) {
        if (*q != 0) {
            if (!((*q)[0x20] < 0xFD)) {
                *q = 0;
            }
        }
    }
    y = *(f32 *)(obj + 0x10);
    if (!(*(f32 *)(st + 0x22C) < y)) {
        if (*(f32 *)(st + 0x228) < y) {
            flag = (D_L32_001DF9C0 % D_L32_001DEE78[0]) == 0;
        } else if (*(f32 *)(st + 0x224) < y) {
            flag = (D_L32_001DF9C0 % D_L32_001DEE74[0]) == 0;
        } else if (*(f32 *)(st + 0x238) < y) {
            flag = (D_L32_001DF9C0 % D_L32_001DEE70) == 0;
        }
    }
    if (flag) {
        found = 0;
        for (i = 0; i < 0x30 && !found; i++) {
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
                off = n * 0x210 + 0x80;
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
