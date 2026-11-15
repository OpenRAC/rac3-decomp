#include "common.h"

/* localdecomp:start func_L16_003E8D20 */
#include "vu0.h"
extern f32 func_00382538(void);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CE20(void *, void *, f32);

void func_L16_003E8D20(void *out, void *base, f32 lo, f32 hi)
{
    vu0_v4 v;
    f32 ang;

    qzero(&v);
    ang = func_00382538();
    v.x = func_0038D098(ang);
    v.y = func_0038D0B0(ang);
    func_0038CE20(&v, &v, func_003824E0(lo, hi));
    vec_add_ba(out, &v, base);
}
/* localdecomp:end func_L16_003E8D20 */

INCLUDE_ASM("asm/levels", func_L16_003E8DC0);

/* localdecomp:start func_L16_003E9068 */
extern vu0_v4 D_001E2B00;
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_0040A8C0(void *, void *, s32, s32, u32, u32, u32, u32, f32, f32, f32);

void func_L16_003E9068(void *pos, void *dir, f32 len, f32 f1, f32 f2, f32 width, f32 f4,
                       s32 a2, s32 a3, u8 alpha0, u8 alpha1, s32 tex)
{
    vu0_v4 d;
    vu0_v4 s;
    vu0_v4 b;
    vu0_v4 a;

    vec_sub_ab(&a, &D_001E2B00, pos);
    func_0038CF68(&a, &a, len);
    vec_add_ba(&a, &a, pos);
    func_0038CE20(&b, dir, width * 0.5f);
    vec_add_ab(&s, &a, &b);
    a2 += alpha0 << 24;
    a3 += alpha1 << 24;
    a2 += alpha0 << 24;
    a3 += alpha1 << 24;
    vec_sub_ab(&d, &a, &b);
    func_L01_0040A8C0(&d, &s, tex, 1, a2, a2, a3, a3, f1, f2, f4);
}
/* localdecomp:end func_L16_003E9068 */
