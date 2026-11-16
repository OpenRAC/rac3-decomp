#include "common.h"

/* NTSC-U counterpart of func_L30_00351D10 (src/levels/shared/L30_00351D10.c) */
/* localdecomp:start func_L30_00350E00 */
#include "vu0.h"
/* log:
 * - straight transcription, j-form vu0.h helpers, ps2as + .extern hints: 94 diff (if/else with two calls)
 * - k loaded before the if, one call after it: 98-202 diff (sched / default+override)
 * - the call and the vadd that follows written out in both arms: gcc cross-jumps [call, vadd]: MATCH
 *   (needs --flags=-mvu0-use-vf0-vf2 --as ps2as)
 */
extern f32 func_0037E250(f32, f32);
extern void func_003886E8(void *, void *, f32);
extern void func_003BF6A8(void *, f32);
extern s32 func_0037E208(s32, s32);
extern void func_L01_0046E4D8(void *, void *, s32);
extern s32 func_0037E1D8(s32);
extern u8 *func_L01_0046F288(void *, void *, void *, s32, s32, u8, u8, u8, f32, s32, s32);
extern vu0_v4 D_L30_001E2110_00350E00[];
extern f32 D_L30_001DD9AC;
extern f32 D_L30_001DD9B0;
extern f32 D_L30_001DDA40;
extern f32 D_L30_001DDA1C_00350E00;
extern s32 D_L30_001DD99C;
extern s32 D_L30_001DD998;
extern f32 D_L30_001DDA48;
extern f32 D_L30_001DDA4C;
extern u8 D_L30_001DD9B8;
extern s32 D_L30_001DDA50;
extern f32 D_L30_001DDA44;
extern u8 D_L30_001DDA54;

__asm__(".extern D_L30_001DD9AC, 4");
__asm__(".extern D_L30_001DD9B0, 4");
__asm__(".extern D_L30_001DDA40, 4");
__asm__(".extern D_L30_001DDA1C_00350E00, 4");
__asm__(".extern D_L30_001DD99C, 4");
__asm__(".extern D_L30_001DD998, 4");
__asm__(".extern D_L30_001DDA48, 4");
__asm__(".extern D_L30_001DDA4C, 4");
__asm__(".extern D_L30_001DD9B8, 1");
__asm__(".extern D_L30_001DDA50, 4");
__asm__(".extern D_L30_001DDA44, 4");
__asm__(".extern D_L30_001DDA54, 1");

void func_L30_00350E00(void *a0, void *a1, void *a2) {
    vu0_v4 c;
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 e;
    vu0_v4 d;
    f32 s;
    u8 *p;
    s32 col;
    u8 lo;

    func_003886E8(&a, a2, func_0037E250(2.0f, 3.0f));
    a.z += D_L30_001DD9AC;
    func_003886E8(&b, &D_L30_001E2110_00350E00[1], -0.3f);
    vec_add_ab(&c, &b, a1);
    c.y += D_L30_001DD9B0;
    func_003886E8(&b, &D_L30_001E2110_00350E00[1], D_L30_001DDA40);
    vec_add_ba(&a, &b, &a);
    func_003BF6A8(&a, D_L30_001DDA1C_00350E00);
    func_L01_0046E4D8(&c, &a, func_0037E208(D_L30_001DD99C, D_L30_001DD998));
    func_003886E8(&d, &D_L30_001E2110_00350E00[1], -0.2f);
    vec_add_ba(&c, &d, a1);
    b = *(vu0_v4 *)a2;
    func_003886E8(&e, a2, D_L30_001DDA48);
    func_003886E8(&d, &D_L30_001E2110_00350E00[0], func_0037E250(1.2f, 2.0f));
    vec_add_ba(&e, &d, &e);
    func_003886E8(&d, &D_L30_001E2110_00350E00[1], 0.15f);
    vec_add_ab(&b, &d, &b);
    if (func_0037E1D8(2)) {
        s = 103.0f;
        func_003886E8(&d, &D_L30_001E2110_00350E00[0], D_L30_001DDA4C);
        vec_add_ab(&b, &d, &b);
    } else {
        s = 110.0f;
        func_003886E8(&d, &D_L30_001E2110_00350E00[0], -D_L30_001DDA4C);
        vec_add_ab(&b, &d, &b);
    }
    if (D_L30_001DD9B8) {
        col = func_0037E1D8(2) ? 0x48 : 0x44;
        lo = (s32)(func_0037E250(0.05f, 0.15f) * 128.0f);
        p = func_L01_0046F288(&c, &b, &e, col, D_L30_001DDA50, lo,
                          (s32)(func_0037E250(0.7f, 1.3f) * 128.0f), (s32)s,
                          D_L30_001DDA44 * 0.0166666675f, D_L30_001DDA54, 1);
        if (p != 0) {
            p[3] = func_0037E1D8(2) ? 0x44 : 0x48;
        }
    }
}
/* localdecomp:end func_L30_00350E00 */
