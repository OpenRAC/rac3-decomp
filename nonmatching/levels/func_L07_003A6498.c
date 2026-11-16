/*
 * PAL near miss, P02 wave 2, 2026-11-16.
 * Owner: src/levels/07_annihilation_nation/L07_003A46C8.c.
 * Exact flags: -O2 -G8 -fopt-stack -mno-check-zero-division
 *              -fno-sched-interblock @ps2as.
 * Stock checker: 12 differing instructions, three formulations/checks.
 * Twin of func_L07_00353FF0; shared indexed-array experiments plateaued.
 * Remaining differences: scratch-array address setup and second-loop allocation.
 * No flags or metadata changed. Uses the stock owning-file context.
 */
#include "common.h"
extern void func_0038C750(void);
extern long func_00389598(s32);
extern void func_003A9440(s32, long);
extern f32 func_0038CF00(void *, void *);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_003D3A24(s32, void *, void *, void *, s32);
extern f32 D_L07_002A2100[10][6];
extern s32 D_L07_002A21F0[10][2];
extern f32 D_L07_002A2240[10][4];
extern f32 D_L07_001E1650[10];
void func_L07_003A6498(u8 *a, u8 *b, s32 count, s32 start, s32 texture)
{
    s32 i, j, next, color, k;
    f32 total, t, inverse;
    f32 *out;
    if (count < 2) return;
    func_0038C750();
    total = 0.0f;
    func_003A9440(6, func_00389598(texture));
    func_003A9440(0x14, 0xFF9000000260L);
    func_003A9440(8, 0);
    func_003A9440(0x42, 0x4000000044L);
    for (i = 0; i < count; i++) {
        j = (i + start) % count;
        next = (j + 1) % count;
        if (i != count - 1) {
            f32 d = func_0038CF00(a + j * 16, a + next * 16);
            total += d;
            D_L07_001E1650[i] = d;
        }
        out = D_L07_002A2100[i];
        out[0] = *(f32 *)(a + j * 16);
        out[1] = *(f32 *)(a + j * 16 + 4);
        out[2] = *(f32 *)(a + j * 16 + 8);
        out[3] = *(f32 *)(b + j * 16);
        out[4] = *(f32 *)(b + j * 16 + 4);
        out[5] = *(f32 *)(b + j * 16 + 8);
    }
    inverse = 1.0f / total;
    t = 0.0f;
    for (k = 0; k < count; k++) {
        color = func_0038DBD8(0x408020, 0x30802020, t);
        D_L07_002A21F0[k][0] = D_L07_002A21F0[k][1] = color;
        D_L07_002A2240[k][0] = t;
        D_L07_002A2240[k][2] = t;
        D_L07_002A2240[k][1] = 0.0f;
        t += D_L07_001E1650[k] * inverse;
        D_L07_002A2240[k][3] = 1.0f;
    }
    func_003D3A24(count * 2, D_L07_002A2100, D_L07_002A21F0, D_L07_002A2240, 1);
    func_003A9440(0x47, 0x5360B);
}
