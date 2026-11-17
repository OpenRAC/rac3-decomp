#include "common.h"

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_3A25C0;

/* localdecomp:start func_L21_003A3BA0 */
#include "vu0.h"
extern f32 func_00382538(void);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L02_003E2E38(void *, void *, f32, void *, s32, s32, s32, f32, f32, f32, f32);

void func_L21_003A3BA0(u8 *a0)
{
    vu0_v4 v;
    vu0_v4 a;
    vu0_v4 b;
    f32 inv;
    f32 s;
    f32 r;
    u8 *q;
    s32 i;

    inv = 1.0f / *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24);
    q = *(u8 **)(a0 + 0x68);
    s = inv * *(f32 *)(a0 + 0x2C);
    r = func_00382538();
    qzero(&v);
    v.x = func_0038D098(r) * 1.1f;
    v.y = func_0038D0B0(r) * 1.1f + 1.1f;
    func_0038CE20(&v, &v, inv);
    for (i = 0; i < 2; i++) {
        func_0038CE20(&a, a0 + 0xE0, func_003824E0(0.0f, 2.0f));
        func_0038CE20(&b, a0 + 0xC0, func_003824E0(-1.0f, 1.0f));
        vec_add_ab(&a, &b, &a);
        func_0038CE20(&b, a0 + 0xD0, func_003824E0(-1.0f, 1.0f));
        vec_add_ab(&a, &b, &a);
        func_0038CF68(&a, &a, func_003824E0(1.5f, 3.0f) * 0.020000001f);
        ((void (*)(void *, void *, f32, void *, s32, s32, f32, f32, f32, f32, s32))func_L02_003E2E38)(a0, &v, 0.0f, &a, func_00382498(3, 6), i & 1, 0.040000003f, s, 15.0f, 1.0f, 0);
    }
    *(s32 *)(q + 4) -= 1;
    *(s32 *)q = (func_00382498(0x5A, 0xB4) * 5 + 2) / 6;
}
/* localdecomp:end func_L21_003A3BA0 */
