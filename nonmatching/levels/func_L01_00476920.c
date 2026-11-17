/* PAL near miss (Codex wave 8): near miss: does not compile in its file's context yet (declaration conflicts; the worker's note at the top has the details).
 * Worker's note: types2.log COMPILE ERROR only void-value uses: existing void func_0038CF38(Vec4*,Vec4*), func_0038CF00(Vec4*,Vec4*) and earlier void func_L01_004766E0(Vec4*,Vec4*,f32) block retail f0 uses; context returns need f32 then rematch; no casts or incompatible ...
 */
#include "common.h"
/* localdecomp:start func_L01_00476920 */
#include "vu0.h"
/* Context correction required: the file declares CF38/CF00 and defines 4766E0
 * as void, although retail consumes their f0 results. Keep their existing
 * signatures here, rather than casting a named function to another type.
 * The resulting void-value errors are intentional evidence of this blocker. */
f32 func_L01_00476920(Vec4 *out, Vec4 *point, Vec4 *a, Vec4 *b, f32 height) {
    extern void func_0038CF38(Vec4 *, Vec4 *);
    extern void func_0038CF00(Vec4 *, Vec4 *);
    extern void func_L01_004766E0(Vec4 *, Vec4 *, f32);
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
/* localdecomp:end func_L01_00476920 */
