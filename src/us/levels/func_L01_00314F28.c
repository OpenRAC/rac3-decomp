#include "common.h"

/* NTSC-U counterpart of func_L01_00315350 (src/levels/shared/L01_00314158.c): the effect call passes 150 in place of 125 (60 Hz) */
/* localdecomp:start func_L01_00314F28 */
#include "vu0.h"
typedef union { vu0_q q; f32 f[4]; } V_00314F28;
extern u8 D_L01_001D66B0_00314F28[] __attribute__((section(".sdata")));
extern f32 func_003BE7F0(u8 *, s32, s32, f32);
extern s32 func_003BD668(u8 *, s32);
extern void func_0037E2F0(f32 *, f32, f32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E1D8(s32);
extern void func_003886C0(f32 *, f32 *, f32 *, f32);
extern void func_L01_00471F78_00314F28(f32 *, u8 *, s32, u8, f32, f32);
void func_L01_00314F28(u8 *m) {
    V_00314F28 a, b, c;
    f32 light = func_003BE7F0(m + 0x10, 0, 0, 0.5f);
    s32 count = func_003BD668(m, 0);
    s32 pass, left;
    f32 size;
    V_00314F28 *scratch;
    for (pass = 0; pass < 5; pass++) {
        if (count != 0) {
            scratch = (V_00314F28 *)0x70000000; /* EE scratchpad results. */
            for (left = 0; left < count; left++, scratch += 2) {
                if (scratch[1].f[3] == 0.0f) {
                    a.q = scratch[0].q;
                    a.f[3] = 1.0f;
                    func_0037E2F0(b.f, 0.0f, scratch[0].f[3]);
                    vec_add_ab(&a, &a, &b);
                    size = func_0037E250(0.7f, 1.0f) * scratch[0].f[3];
                    func_L01_00471F78_00314F28(a.f, D_L01_001D66B0_00314F28, 150, (u8)func_0037E1D8(2), size, light);
                } else {
                    a.q = scratch[0].q;
                    b.q = scratch[1].q;
                    a.f[3] = 1.0f;
                    b.f[3] = 1.0f;
                    func_003886C0(c.f, a.f, b.f, func_0037E250(0.0f, 1.0f));
                    c.f[0] += func_0037E250(-scratch[0].f[3] * 0.4f, scratch[0].f[3] * 0.4f);
                    c.f[1] += func_0037E250(-scratch[0].f[3] * 0.4f, scratch[0].f[3] * 0.4f);
                    c.f[2] += func_0037E250(-scratch[0].f[3] * 0.4f, scratch[0].f[3] * 0.4f);
                    size = func_0037E250(0.7f, 1.0f) * scratch[0].f[3];
                    func_L01_00471F78_00314F28(c.f, D_L01_001D66B0_00314F28, 150, (u8)func_0037E1D8(2), size, light);
                }
            }
        }
    }
}
/* localdecomp:end func_L01_00314F28 */
