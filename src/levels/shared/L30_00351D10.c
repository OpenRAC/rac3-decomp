#include "common.h"

/* localdecomp:start func_L30_00351D10 */
#include "vu0.h"
/* log:
 * - straight transcription, j-form vu0.h helpers, ps2as + .extern hints: 94 diff (if/else with two calls)
 * - k loaded before the if, one call after it: 98-202 diff (sched / default+override)
 * - the call and the vadd that follows written out in both arms: gcc cross-jumps [call, vadd]: MATCH
 *   (needs --flags=-mvu0-use-vf0-vf2 --as ps2as)
 */
extern f32 func_003824E0(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_003C4C18(void *, f32);
extern s32 func_00382498(s32, s32);
extern void func_L01_00471BF0(void *, void *, s32);
extern s32 func_00382468(s32);
extern u8 *func_L01_004729D8(void *, void *, void *, s32, s32, u8, u8, u8, f32, s32, s32);
extern vu0_v4 D_L30_001E2110[];
extern f32 D_L30_001DD96C;
extern f32 D_L30_001DD970;
extern f32 D_L30_001DDA00;
extern f32 D_L30_001DD9DC;
extern s32 D_L30_001DD95C;
extern s32 D_L30_001DD958;
extern f32 D_L30_001DDA08;
extern f32 D_L30_001DDA0C;
extern u8 D_L30_001DD978;
extern s32 D_L30_001DDA10;
extern f32 D_L30_001DDA04;
extern u8 D_L30_001DDA14;

__asm__(".extern D_L30_001DD96C, 4");
__asm__(".extern D_L30_001DD970, 4");
__asm__(".extern D_L30_001DDA00, 4");
__asm__(".extern D_L30_001DD9DC, 4");
__asm__(".extern D_L30_001DD95C, 4");
__asm__(".extern D_L30_001DD958, 4");
__asm__(".extern D_L30_001DDA08, 4");
__asm__(".extern D_L30_001DDA0C, 4");
__asm__(".extern D_L30_001DD978, 1");
__asm__(".extern D_L30_001DDA10, 4");
__asm__(".extern D_L30_001DDA04, 4");
__asm__(".extern D_L30_001DDA14, 1");

void func_L30_00351D10(void *a0, void *a1, void *a2) {
    vu0_v4 c;
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 e;
    vu0_v4 d;
    f32 s;
    u8 *p;
    s32 col;
    u8 lo;

    func_0038CE20(&a, a2, func_003824E0(2.0f, 3.0f));
    a.z += D_L30_001DD96C;
    func_0038CE20(&b, &D_L30_001E2110[1], -0.3f);
    vec_add_ab(&c, &b, a1);
    c.y += D_L30_001DD970;
    func_0038CE20(&b, &D_L30_001E2110[1], D_L30_001DDA00);
    vec_add_ba(&a, &b, &a);
    func_003C4C18(&a, D_L30_001DD9DC);
    func_L01_00471BF0(&c, &a, func_00382498(D_L30_001DD95C, D_L30_001DD958));
    func_0038CE20(&d, &D_L30_001E2110[1], -0.2f);
    vec_add_ba(&c, &d, a1);
    b = *(vu0_v4 *)a2;
    func_0038CE20(&e, a2, D_L30_001DDA08);
    func_0038CE20(&d, &D_L30_001E2110[0], func_003824E0(1.2f, 2.0f));
    vec_add_ba(&e, &d, &e);
    func_0038CE20(&d, &D_L30_001E2110[1], 0.15f);
    vec_add_ab(&b, &d, &b);
    if (func_00382468(2)) {
        s = 103.0f;
        func_0038CE20(&d, &D_L30_001E2110[0], D_L30_001DDA0C);
        vec_add_ab(&b, &d, &b);
    } else {
        s = 110.0f;
        func_0038CE20(&d, &D_L30_001E2110[0], -D_L30_001DDA0C);
        vec_add_ab(&b, &d, &b);
    }
    if (D_L30_001DD978) {
        col = func_00382468(2) ? 0x48 : 0x44;
        lo = (s32)(func_003824E0(0.05f, 0.15f) * 128.0f);
        p = func_L01_004729D8(&c, &b, &e, col, (D_L30_001DDA10 * 5 + 2) / 6, lo,
                          (s32)(func_003824E0(0.7f, 1.3f) * 128.0f), (s32)s,
                          D_L30_001DDA04 * 0.0200000014f, D_L30_001DDA14, 1);
        if (p != 0) {
            p[3] = func_00382468(2) ? 0x44 : 0x48;
        }
    }
}
/* localdecomp:end func_L30_00351D10 */
