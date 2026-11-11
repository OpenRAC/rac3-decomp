/* near miss (level 11, Obani Moons): draft, 173 differences counted (measured with --flags=-mvu0-use-vf0-vf2, vec_add_ab needs it): the saved-register class of the level-2 open problem: retail saves $s0-$s6 and $ra with sq in 16-byte ascending slots (frame 0x170) where gcc writes sd in 8-byte slots (frame 0x130), which shifts every stack offset and the schedule; levels have no sq_ra_funcs table, and the frontbin rewrite needs a file without -fopt-stack. The calls, arguments and constants are retail's; not tuned further */
#include "common.h"

/* localdecomp:start func_L11_003BDA60 */
#include "vu0.h"
__asm__(".extern D_L11_001D66B0, 16");
extern u8 D_L11_001D66B0;
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *, s32, u8 *, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32, s32, s32);
extern void func_L05_003DC520(void *, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L02_00429840(void *, void *, f32, f32, s32, s32, void *, f32, s32, s32, f32, s32);
extern void func_L02_003E2E38(void *, void *, f32, void *, s32, s32, s32, f32, f32, f32, f32);
extern void func_L01_003303B8(void *, f32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_003C2880(void *);

void func_L11_003BDA60(u8 *a0, s32 a1, vu0_v4 *dir, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, f32 speed, f32 size, s32 a8)
{
    vu0_v4 d;
    vu0_v4 p;
    vu0_v4 b;
    vu0_v4 c;

    d = *dir;
    func_003A52A0(0, 0, a0);
    func_L01_00451FE0(a0, a1, &D_L11_001D66B0, 0xFF, 0xB4, 0, 0, 0x23, 3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f, 0, 3);
    if (a4 != 0) {
        func_L05_003DC520(a0, a4);
    }
    b = d;
    p = *(vu0_v4 *)(a0 + 0x10);
    func_0038CF68(&b, &b, *(f32 *)(a0 + 0x2C) / *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24) * speed);
    vec_add_ab(&p, &p, &b);
    func_0038CF68(&c, &d, 0.030000001f);
    if (a5 != 0) {
        func_L02_00429840(a0, &p, 1.0f, 0.16000001f, 0xF, 0, &c, 0.5f, a8, 0, 1.0f, 0x3A);
    }
    if (a6 != 0) {
        func_L02_003E2E38(a0, &p, 1.5f, &c, 0xF, 0, 1, 0.02f, 2.0f, 6.0f, 1.0f);
    }
    if (a7 != 0) {
        func_L01_003303B8(&p, size, 0, 0, 0, 0, 2, 5, 0, 0.0f, 0.0f, 0.0f,
            0, 1, 0, 0, 0, 0, 0x1000000, 0, 0x7FD68F, 0xFF8400, 0, 0, 0, 0, 0x7F60A0FF, 0x280000FF, 0, 0);
    }
    func_L01_00451E78(a0, 1, 0.0f);
    func_003C2880(a0);
}
/* localdecomp:end func_L11_003BDA60 */
