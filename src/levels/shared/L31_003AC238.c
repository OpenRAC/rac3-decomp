#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

/* declared by functions of L31_003ABC08.c, which this file was cut from */
extern f32 func_003824E0(f32 a, f32 b);

/* localdecomp:start func_L31_003AC238 */
#include "vu0.h"

__asm__(".extern D_L31_001DEAEC, 4");
extern f32 D_L31_001DEAEC;
extern u8 D_L31_001E22A0[];
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32 a, f32 b);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CEA8(void *);
extern u8 *func_L31_003AC0B0(u128_t *, u128_t *, s32, s32, s32, s32, f32, f32, f32, f32);

void func_L31_003AC238(u8 *a0, u8 *a1) {
    u8 *s = *(u8 **)(a0 + 0x68);
    vu0_v4 d;
    vu0_v4 dir;
    vu0_v4 v20;
    vu0_v4 v30;
    vu0_v4 v40;
    vu0_v4 v50;
    s32 n;
    s32 i;
    f32 t;

    if (*(s32 *)(s + 0x3C) < 0) {
        return;
    }
    n = func_00382498(*(s32 *)(s + 0x38), *(s32 *)(s + 0x34));
    vec_sub_ab(&d, a1, a0 + 0x10);
    func_0038CE90(&dir, s, D_L31_001E22A0);
    func_0038CF68(&dir, &dir, 1.0f);
    for (i = 0; i < n; i++) {
        func_0038CE20(&v20, s, -func_003824E0(0.6f, 1.0f) * *(f32 *)(s + 0x2C));
        func_0038CE20(&v30, &dir, func_00382498(0, 1) ? 1.0f : -1.0f);
        t = func_0038CEA8(s);
        func_0038CE20(&v30, &v30, t * func_003824E0(0.0f, *(f32 *)(s + 0x48)));
        vec_add_ab(&v40, &v20, &v30);
        func_0038CE20(&v50, &v40, D_L31_001DEAEC);
        vec_add_ab(&v50, &v50, a0 + 0x10);
        /* the call passes its arguments in this order: the same registers as the definition's */
        ((u8 *(*)(u128_t *, u128_t *, s32, f32, s32, f32, s32, s32, f32, f32))func_L31_003AC0B0)(
            (u128_t *)&v50, (u128_t *)&v40, *(s32 *)(s + 0x3C), *(f32 *)(s + 0x44), *(s32 *)(s + 0x30),
            *(f32 *)(s + 0x18), 0, (s32)a0, *(f32 *)(s + 0x40),
            func_003824E0(-*(f32 *)(s + 0x28), *(f32 *)(s + 0x28)));
    }
}
/* localdecomp:end func_L31_003AC238 */
