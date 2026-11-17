#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L33_00350188 */
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CEA8(void *);
extern void func_L33_0034FEE8(void *, void *, void *, s32, s32, f32, f32, f32, f32, f32);
extern u8 D_L33_001E2720[];
extern f32 D_L33_001DD7E4;
__asm__(".extern D_L33_001DD7E4, 4");

void func_L33_00350188(u8 *self, void *target) {
    vu0_v4 d;
    vu0_v4 side;
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 sum;
    vu0_v4 pos;
    u8 *p = *(u8 **)(self + 0x68);
    s32 n;
    s32 i;
    f32 len;
    f32 scale;

    if (*(s32 *)(p + 0x3C) < 0) {
        return;
    }
    n = func_00382498(*(s32 *)(p + 0x38), *(s32 *)(p + 0x34));
    vec_sub_ab(&d, target, self + 0x10);
    func_0038CE90(&side, p, D_L33_001E2720);
    func_0038CF68(&side, &side, 1.0f);
    for (i = 0; i < n; i++) {
        func_0038CE20(&a, p, -func_003824E0(0.6f, 1.0f) * *(f32 *)(p + 0x2C));
        func_0038CE20(&b, &side, func_00382498(0, 1) ? 1.0f : -1.0f);
        len = func_0038CEA8(p);
        func_0038CE20(&b, &b, len * func_003824E0(0.0f, *(f32 *)(p + 0x48)));
        vec_add_ab(&sum, &a, &b);
        func_0038CE20(&pos, &sum, D_L33_001DD7E4);
        vec_add_ab(&pos, &pos, self + 0x10);
        scale = self[0x23];
        scale *= 0.0078125f;
        func_L33_0034FEE8(&pos, &sum, self, 0, 0, scale, *(f32 *)(p + 0x30), *(f32 *)(p + 0x40),
                          *(f32 *)(p + 0x44), func_003824E0(-*(f32 *)(p + 0x28), *(f32 *)(p + 0x28)));
    }
}
/* localdecomp:end func_L33_00350188 */
