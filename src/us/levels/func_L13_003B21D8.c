#include "common.h"

/* localdecomp:start func_L13_003B21D8 */
#include "vu0.h"

typedef struct {
    u8 pad0[0x18];
    u8 x18;
    u8 x19;
    u16 x1A;
    u8 pad1C[0x14];
} __attribute__((aligned(16))) S_003B40A0;

typedef struct {
    u8 pad0[0x18];
    u8 *x18;
    u8 pad1C[4];
    vu0_v4 x20;
} G_003B40A0;

typedef struct {
    u8 pad0[0x184];
    u8 *x184;
    u8 pad188[0x1A0 - 0x188];
    u8 *x1A0;
} H_003B40A0;

extern u8 *D_L13_001E8F18[];
extern G_003B40A0 D_L13_001E8F00;
extern vu0_v4 D_L13_001E8F20;
extern H_003B40A0 D_L13_0021EF98;
extern f32 D_L13_001D66B0[2];
__asm__(".extern D_L13_001D66B0, 16");

extern void func_00388830(void *, void *, f32);
extern f32 func_00388800(void *, void *);
extern s32 func_L01_0040BAF0(void *);
extern void func_003BD360(void *);
extern void func_L01_00443628(void *, void *, s32, void *, f32);
extern void func_L01_004C76B8(void);
extern void func_L01_004C76F0(void);
extern s32 func_003CE740(void *, void *, s32, void *, void *);
extern f32 func_00388770(void *);
extern void func_L13_003B2090(u8 *);
extern s32 func_0037E208(s32, s32);
extern u8 *func_L01_0046DCB8(void *, void *, s32, u32, s32, s32, s32, s32, f32, f32, f32);
extern f32 func_0037E250(f32, f32);
extern void func_L01_00402498(void *, void *);
extern void func_L13_003B1EF0(void *);
extern void func_L01_00467DA8(f32 *, s32, s32, s32, s32, f32 *, f32, f32, f32, s32);

void func_L13_003B21D8(u8 *self) {
    vu0_v4 a;
    vu0_v4 b;
    S_003B40A0 info;
    vu0_v4 c;
    vu0_v4 d;
    u8 *v;
    u8 *o;
    void *tgt;
    s32 hit;
    s32 lo;
    s32 hi;
    s32 i;
    f32 t;

    v = *(u8 **)(self + 0x68);
    func_00388830(&a, v, *(f32 *)(v + 0x30));
    vec_add_ab(&a, v + 0x10, &a);
    func_00388830(&b, v, 0.75000006f);
    if (v[0x25] < 70) {
        if (func_00388800(v + 0x10, &a) > 2.5000002f) {
            vec_add_ab(v + 0x10, v + 0x10, &b);
        }
    }
    if (func_L01_0040BAF0(v + 0x25) != 0) {
        func_003BD360(self);
        return;
    }
    *(f32 *)(v + 0x30) = *(f32 *)(v + 0x30) + 0.75000006f;
    if (v[0x25] < 16) {
        t = *(f32 *)(v + 0x2C) - 0.15f;
        *(f32 *)(v + 0x2C) = t;
        if (t < 0.0f) {
            *(f32 *)(v + 0x2C) = 0.0f;
        }
    }
    func_00388830(&c, v, 1.0f);
    func_L01_00443628(&info, self, *(s32 *)(v + 0x20), &c, (f32)v[0x24]);
    info.x18 = 1;
    info.x19 = 1;
    info.x1A = *(u16 *)(self + 0xAA);
    tgt = *(void **)(self + 0xB8);
    func_L01_004C76B8();
    hit = func_003CE740(v + 0x10, &a, 0x10, tgt, &info);
    if (hit != 0) {
        o = D_L13_001E8F18[0];
        if (o != 0 && *(s16 *)(o + 0xAA) == 0x186D && o[0x20] != 2 && o[0x20] != 5) {
            o[0x20] = 4;
        }
    }
    func_L01_004C76F0();
    if (hit != 0) {
        u8 *q = D_L13_001E8F00.x18;

        if (q == 0 || *(s16 *)(q + 0xAA) == 0x1868) {
            *(s32 *)(v + 0x34) = 1;
            *(vu0_q *)&a = *(vu0_q *)&D_L13_001E8F00.x20;
            vec_sub_ab(&d, &a, v + 0x10);
            *(f32 *)(v + 0x30) = func_00388770(&d);
            func_L13_003B2090(self);
        }
    }
    tgt = *(void **)(self + 0xB8);
    func_L01_004C76B8();
    hit = func_003CE740(v + 0x10, &a, 0x12, tgt, 0);
    if (hit != 0) {
        o = D_L13_001E8F18[0];
        if (o != 0 && *(s16 *)(o + 0xAA) == 0x186D && o[0x20] != 2 && o[0x20] != 5) {
            o[0x20] = 4;
        }
    }
    func_L01_004C76F0();
    if (hit != 0) {
        *(s32 *)(v + 0x34) = 1;
        *(vu0_q *)&a = *(vu0_q *)&D_L13_001E8F20;
        vec_sub_ab(&d, &a, v + 0x10);
        *(f32 *)(v + 0x30) = func_00388770(&d);
        func_L13_003B2090(self);
    }
    hi = 0x1E;
    lo = 0x14;
    if (*(s32 *)(v + 0x34) != 0) {
        hi = 5;
        lo = 3;
    }
    if (v[0x25] >= 12) {
        u8 *p;
        s32 n;

        p = ((u8 * (*)(f32 *, s32, s32, s32, s32, f32 *, f32, f32, f32, s32))func_L01_00467DA8)(
            (f32 *)(v + 0x10), 10, 0xAF076007, 0, 2, D_L13_001D66B0, 2.0f, 0.0f, 0.0f, 0);
        if (p != 0) {
            p[3] = 0x44;
        }
    }
    for (i = 0; i < 2; i++) {
        u8 *p;
        s32 n;

        n = func_0037E208(lo, hi);
        p = func_L01_0046DCB8(&a, D_L13_001D66B0, n, 0x96309, func_0037E208(-5, 5), 0x4F, 0, 0, 262500.0f, 0.0f,
                              -0.000277777785f);
        if (p != 0) {
            p[2] = D_L13_0021EF98.x1A0[func_0037E208(0, 3)];
        }
    }
    d = a;
    for (i = 0; i < 2; i++) {
        u8 *p;
        s32 n;

        d.x += func_0037E250(-0.2f, 0.2f);
        d.y += func_0037E250(-0.2f, 0.2f);
        d.z += func_0037E250(-0.2f, 0.2f);
        n = func_0037E208(lo, hi);
        p = func_L01_0046DCB8(&d, D_L13_001D66B0, n, 0x509650, func_0037E208(-5, 5), 0x4F, 0, 0, 262500.0f, 0.0f,
                              -0.000277777785f);
        if (p != 0) {
            p[2] = D_L13_0021EF98.x184[5];
        }
    }
    func_L01_00402498(func_L13_003B1EF0, self);
}
/* localdecomp:end func_L13_003B21D8 */
