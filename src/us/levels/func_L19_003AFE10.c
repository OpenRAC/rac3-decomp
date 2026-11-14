#include "common.h"

/* NTSC-U counterpart of func_L19_003B1A80 (src/levels/19_thran_asteroid_belt/L19_003B1A80.c) */
#include "vu0.h"

/* localdecomp:start func_L19_003AFE10 */
typedef int u128_t_3B1A80 __attribute__((mode(TI)));
extern void func_L19_003AFE00();
extern void func_003BD778(void *, void *);
extern void func_003886E8(void *, void *, f32);
extern void func_L01_0040C920(void *, void *);
extern void func_003888C8(void *, void *, void *);
extern f32 func_00388770(void *);
extern void func_L01_0040BED8(void *, void *, f32);
extern void func_L01_00437350(void *, s32, void *);
extern void func_00388758(void *, void *, void *);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern void func_003BDA38(u8 *a0, s32 a1, u8 *a2);
extern void func_L19_00401860(void *, void *, void *);
extern s32 func_003883C8(void *);
extern s32 func_00388398(void *);
extern void func_L01_00402498(void *, void *);
extern void func_L19_003B1218(u8 *);
extern void func_L01_0044EB78(void *, void *, s32, s32, f32);
extern void func_003C26C8(void *);

void func_L19_003AFE10(u8 *obj) {
    vu0_v4 a;
    vu0_v4 m[3];
    vu0_v4 u;
    vu0_v4 b;
    vu0_v4 c;
    vu0_v4 d;
    vu0_v4 e;
    u8 *v = *(u8 **)(obj + 0x68);
    u8 *r;
    f32 f;

    *(vu0_v4 *)(*(u8 **)(v + 0x39C) + 0x10) = *(vu0_v4 *)(obj + 0x10);
    if (obj[0x95] == 5) {
        *(f32 *)(*(u8 **)(v + 0x39C) + 0x18) -= 1.29999995f;
        func_L19_003AFE00(obj);
        if (v[0x3D1] != 0)
            func_003BD778(obj, v + 0x3D0);
        if (v[0x411] != 0)
            func_003BD778(obj, v + 0x410);
        if (v[0x451] != 0)
            func_003BD778(obj, v + 0x450);
    } else {
        r = v + 0x110;
        if (*(s16 *)(v + 0x3AE) == 0)
            func_003886E8(r, r, 0.899999976f);
        func_L01_0040C920(m, obj + 0xC0);
        func_003888C8(&a, r, m);
        f = func_00388770(&a);
        if (0.001f < fabs_asm(f)) {
            func_L01_0040BED8(&a, &a, f);
            if (v[0x3D1] == 0)
                func_L01_00437350(obj, 0, v + 0x3D0);
            if (v[0x411] == 0)
                func_L01_00437350(obj, 0xB, v + 0x410);
            if (v[0x451] == 0)
                func_L01_00437350(obj, 4, v + 0x450);
            f = f * -2.7925267f;
            *(u128_t_3B1A80 *)&u = 0;
            u.z = 1.0f;
            func_00388758(&b, &a, &u);
            func_003886E8(&c, &b, func_00388978(f));
            c.w = func_00388960(f);
            func_003BDA38(obj, 1, (u8 *)&d);
            func_003886E8(&e, &d, -1.0f);
            func_L19_00401860(&e, &e, &c);
            vec_add_ab(&e, &e, &d);
            f = f * -0.449999988f;
            *(vu0_v4 *)(v + 0x3E0) = c;
            *(vu0_v4 *)(v + 0x400) = e;
            func_003886E8(&c, &b, func_00388978(f));
            c.w = func_00388960(f);
            *(vu0_v4 *)(v + 0x420) = c;
            *(vu0_v4 *)(v + 0x460) = c;
        } else {
            if (v[0x3D1] != 0)
                func_003BD778(obj, v + 0x3D0);
            if (v[0x411] != 0)
                func_003BD778(obj, v + 0x410);
            if (v[0x451] != 0)
                func_003BD778(obj, v + 0x450);
        }
    }
    func_003883C8(v + 0x3B0);
    func_00388398(v + 0x38C);
    if (obj[0x95] != 5 && ((obj[0x34] ^ 1) & 1))
        func_L01_00402498(func_L19_003B1218, obj);
    if (((obj[0x34] ^ 1) & 1))
        func_L01_0044EB78(obj, v + 0x2C0, 5, 1, 2.5f);
    if (obj[0x95] != 4) {
        *(s32 *)(*(u8 **)(v + 0x39C) + 0x98) = *(s32 *)(*(u8 **)(*(u8 **)(v + 0x39C) + 0x24) + 0x10);
        func_003C26C8(*(u8 **)(v + 0x39C));
    }
    if (*(u16 *)(obj + 0x96) < 0xFFFF)
        *(u16 *)(obj + 0x96) = *(u16 *)(obj + 0x96) + 1;
}
/* localdecomp:end func_L19_003AFE10 */
