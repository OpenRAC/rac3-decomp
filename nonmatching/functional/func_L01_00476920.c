/* functional: medium. Callees whose result retail consumes (func_0038CF38, func_0038CF00, func_L01_004766E0, func_L01_00476750, CF68/CE20) are called through typed function pointers so the unit declarations stay as they are. Read block by block against the PAL asm. Vector ops written as plain C (w lane of the direction kept from b). */
#include "common.h"
#include "vu0.h"
f32 func_L01_00476920(Vec4 *out, Vec4 *point, Vec4 *a, Vec4 *b, f32 height) {
    /* the unit declares some of these as void: call through typed pointers */
    extern void func_L01_004766E0(Vec4 *, Vec4 *, f32);
    extern void func_L01_00476750(Vec4 *, Vec4 *, Vec4 *, Vec4 *, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_003C4098(Vec4 *, Vec4 *, Vec4 *, f32);
    extern f32 func_0038CE68(void *, void *);
    Vec4 direction, start, normal, first, second;
    f32 result, length, projection, distance, denom;
    s32 i;
    if (height > 0.0f && fabs_asm(point->f[2] - a->f[2]) < height &&
        fabs_asm(point->f[2] - b->f[2]) < height) {
        result = ((f32 (*)(Vec4 *, Vec4 *, Vec4 *, Vec4 *, f32))func_L01_00476750)(out, point, a, b, height);
        distance = ((f32 (*)(Vec4 *, Vec4 *))func_0038CF38)(a, out);
        length = ((f32 (*)(Vec4 *, Vec4 *))func_0038CF38)(a, b);
        first.q = a->q;
        second.q = b->q;
        func_003C4098(out, &first, &second, distance / length);
        return result;
    }
    direction.f[0] = b->f[0] - a->f[0];
    direction.f[1] = b->f[1] - a->f[1];
    direction.f[2] = b->f[2] - a->f[2];
    direction.f[3] = b->f[3];
    start.q = a->q;
    ((void (*)(void *, void *, f32))func_0038CF68)(&direction, &direction, 1.0f);
    normal.q = direction.q;
    projection = -func_0038CE68(point, &direction);
    distance = func_0038CE68(&start, &normal);
    denom = func_0038CE68(&direction, &normal);
    ((void (*)(void *, void *, f32))func_0038CE20)(out, &direction, -(projection + distance) / denom);
    out->f[0] += start.f[0];
    out->f[1] += start.f[1];
    out->f[2] += start.f[2];
    for (i = 0; i < 3; i++) {
        if (out->f[i] > a->f[i] && out->f[i] > b->f[i]) break;
        if (out->f[i] < a->f[i] && out->f[i] < b->f[i]) break;
    }
    if (i < 3) {
        distance = ((f32 (*)(Vec4 *, Vec4 *))func_0038CF00)(out, a);
        length = ((f32 (*)(Vec4 *, Vec4 *))func_0038CF00)(out, b);
        if (distance < length) out->q = a->q;
        else out->q = b->q;
    }
    first.q = point->q;
    second.q = out->q;
    return ((f32 (*)(Vec4 *, Vec4 *, f32))func_L01_004766E0)(&first, &second, 0.0f);
}
