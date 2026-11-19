/* functional: medium. Read block by block against the PAL asm. Needs the unit's declarations of func_0038CF38, func_0038CF00 and func_L01_004766E0 changed from void to f32 (retail consumes their f0 result), so it does not compile in context until that fix; compiles with --no-context plus Vec4. */
#include "common.h"
#include "vu0.h"
f32 func_L01_00476920(Vec4 *out, Vec4 *point, Vec4 *a, Vec4 *b, f32 height) {
    extern f32 func_0038CF38(Vec4 *, Vec4 *);
    extern f32 func_0038CF00(Vec4 *, Vec4 *);
    extern f32 func_L01_004766E0(Vec4 *, Vec4 *, f32);
    extern f32 func_L01_00476750(Vec4 *, Vec4 *, Vec4 *, Vec4 *, f32);
    extern void func_003C4098(Vec4 *, Vec4 *, Vec4 *, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern f32 func_0038CE68(void *, void *);
    extern void func_0038CE20(void *, void *, f32);
    Vec4 direction, start, normal, first, second;
    f32 result, length, projection, distance, denom;
    s32 i;
    if (height > 0.0f && fabs_asm(point->f[2] - a->f[2]) < height &&
        fabs_asm(point->f[2] - b->f[2]) < height) {
        result = func_L01_00476750(out, point, a, b, height);
        distance = func_0038CF38(a, out);
        length = func_0038CF38(a, b);
        first.q = a->q;
        second.q = b->q;
        func_003C4098(out, &first, &second, distance / length);
        return result;
    }
    __asm__ __volatile__(
        "lqc2 $vf2, %1\n"
        "lqc2 $vf1, %2\n"
        "vsub.xyz $vf1, $vf1, $vf2\n"
        "sqc2 $vf1, %0"
        : "=m"(direction) : "m"(*a), "m"(*b) : "vf1", "vf2");
    start.q = a->q;
    func_0038CF68(&direction, &direction, 1.0f);
    normal.q = direction.q;
    projection = -func_0038CE68(point, &direction);
    distance = func_0038CE68(&start, &normal);
    denom = func_0038CE68(&direction, &normal);
    func_0038CE20(out, &direction, -(projection + distance) / denom);
    __asm__ __volatile__(
        "lqc2 $vf1, %1\n"
        "lqc2 $vf2, %2\n"
        "vadd.xyz $vf1, $vf1, $vf2\n"
        "sqc2 $vf1, %0"
        : "=m"(*out) : "m"(*out), "m"(start) : "vf1", "vf2");
    for (i = 0; i < 3; i++) {
        if (out->f[i] > a->f[i] && out->f[i] > b->f[i]) break;
        if (out->f[i] < a->f[i] && out->f[i] < b->f[i]) break;
    }
    if (i < 3) {
        distance = func_0038CF00(out, a);
        length = func_0038CF00(out, b);
        if (distance < length) out->q = a->q;
        else out->q = b->q;
    }
    first.q = point->q;
    second.q = out->q;
    return func_L01_004766E0(&first, &second, 0.0f);
}
