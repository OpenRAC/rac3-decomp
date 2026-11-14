/* func_L03_003C8918: near miss (file L03_003C81D0.c). 75 differences with -mvu0-use-vf0-vf2 @ps2as, 2 with -fno-sched-interblock (an a3/f12 argument move order): gcc's inter-block (haifa) scheduler hoists the 2pi and 1/16 constants above the per-iteration `(D_L03_001DF4C0 & 3) == (i & 3)` test, retail did not; the flag is not one the level build uses (build-fidelity rule 5); continue/if forms, `a = 0.0f` placement and expression splits tried */
#include "common.h"
#include "vu0.h"
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_00382580(void *, f32, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern void func_L03_00458A70(void *, void *, s32, s32, u32, f32);
extern s32 D_L03_001DF4C0;

void func_L03_003C8918(u8 *m) {
    s32 i;
    f32 a;
    f32 t;
    s32 n;
    vu0_v4 p;
    vu0_v4 v;

    for (i = 0; i < 16; i++) {
        a = 0.0f;
        if ((D_L03_001DF4C0 & 3) != (i & 3)) {
            continue;
        }
        a = func_0038DAB8(a, (f32)i * 6.2831855f * 0.0625f);
        p.x = func_0038D098(a) * 1.05f;
        p.y = func_0038D0B0(a) * 1.05f;
        *(s32 *)&p.z = 0;
        vec_add_ab(&p, m + 0x10, &p);
        func_00382580(&v, 0.004f, 0.008f);
        v.z += func_003824E0(0.026f, 0.032f);
        t = func_003824E0(0.1f, 0.25f);
        n = (func_00382498(15, 30) * 5 + 2) / 6;
        func_L03_00458A70(&p, &v, n, func_00382498(-8, 8), 0x60FFFFFF, t);
    }
}
