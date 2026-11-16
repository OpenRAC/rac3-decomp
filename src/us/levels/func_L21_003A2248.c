#include "common.h"

/* NTSC-U counterpart of func_L21_003A3BA0 (src/levels/21_obani_draco/L21_003A3BA0.c) */
/* localdecomp:start func_L21_003A2248 */
#include "vu0.h"
extern f32 func_0037E2A8(void);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E208(s32, s32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern void func_003886E8(void *, void *, f32);
extern void func_00388830(void *, void *, f32);
extern void func_L02_003E0520(void *, void *, f32, void *, s32, s32, s32, f32, f32, f32, f32);

void func_L21_003A2248(u8 *a0)
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
    r = func_0037E2A8();
    qzero(&v);
    v.x = func_00388960(r) * 1.1f;
    v.y = func_00388978(r) * 1.1f + 1.1f;
    func_003886E8(&v, &v, inv);
    for (i = 0; i < 2; i++) {
        func_003886E8(&a, a0 + 0xE0, func_0037E250(0.0f, 2.0f));
        func_003886E8(&b, a0 + 0xC0, func_0037E250(-1.0f, 1.0f));
        vec_add_ab(&a, &b, &a);
        func_003886E8(&b, a0 + 0xD0, func_0037E250(-1.0f, 1.0f));
        vec_add_ab(&a, &b, &a);
        func_00388830(&a, &a, func_0037E250(1.5f, 3.0f) * 0.0166666675f);
        ((void (*)(void *, void *, f32, void *, s32, s32, f32, f32, f32, f32, s32))func_L02_003E0520)(a0, &v, 0.0f, &a, func_0037E208(3, 6), i & 1, 0.0333333351f, s, 15.0f, 1.0f, 0);
    }
    *(s32 *)(q + 4) -= 1;
    *(s32 *)q = func_0037E208(0x5A, 0xB4);
}
/* localdecomp:end func_L21_003A2248 */
