#include "common.h"

typedef int Quad_3B4618 __attribute__((mode(TI)));

INCLUDE_ASM("asm/levels", func_L13_003B3938);

/* localdecomp:start func_L13_003B3DA8 */
#include "vu0.h"

extern f32 D_L13_001DE8C4;
__asm__(".extern D_L13_001DE8C4, 4");
extern f32 D_L13_001DE8C8;
__asm__(".extern D_L13_001DE8C8, 4");
extern f32 D_L13_001DE8CC;
__asm__(".extern D_L13_001DE8CC, 4");
extern f32 D_L13_001DE8D0;
__asm__(".extern D_L13_001DE8D0, 4");
extern s32 D_L13_001DE8D4;
__asm__(".extern D_L13_001DE8D4, 4");
extern u32 D_L13_001DE8D8;
__asm__(".extern D_L13_001DE8D8, 4");
extern void func_L01_00451290(void *, void *, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_0040A8C0(void *, void *, s32, s32, u32, u32, u32, u32, f32, f32, f32);

void func_L13_003B3DA8(void *a0) {
    vu0_v4 m0, m1, m2, m3, m4, m5, m6;
    f32 t;
    u8 *v;

    v = *(u8 **)((u8 *)a0 + 0x68);
    func_L01_00451290(a0, &m0, 1);
    *(Quad_3B4618 *)&m2 = *(Quad_3B4618 *)v;
    func_0038CF68(&m0, &m0, 1.0f);
    func_0038CF68(&m2, &m2, -1.0f);
    func_0038CE90(&m1, &m0, &m2);
    func_0038CF68(&m1, &m1, 1.0f);
    *(Quad_3B4618 *)&m3 = *(Quad_3B4618 *)(v + 0x10);
    func_0038CE20(&m0, &m0, D_L13_001DE8C8 * *(f32 *)(v + 0x2C));
    func_0038CE20(&m1, &m1, D_L13_001DE8D0 * *(f32 *)(v + 0x2C));
    func_0038CE20(&m2, &m2, D_L13_001DE8CC);
    func_0038CE20(&m4, &m2, -1.0f);
    vec_add_ab(&m3, &m3, &m4);
    t = *(f32 *)(v + 0x28) + D_L13_001DE8C4 * 1.2f;
    *(f32 *)(v + 0x28) = t;
    if (1.0f < t) {
        *(f32 *)(v + 0x28) = t - 1.0f;
    }
    func_0038CF68(&m5, v, *(f32 *)(v + 0x30));
    vec_add_ab(&m5, v + 0x10, &m5);
    *(Quad_3B4618 *)&m6 = *(Quad_3B4618 *)(v + 0x10);
    func_L01_0040A8C0(&m6, &m5, D_L13_001DE8D4, 0, D_L13_001DE8D8, D_L13_001DE8D8, D_L13_001DE8D8, D_L13_001DE8D8,
                      *(f32 *)(v + 0x2C), *(f32 *)(v + 0x2C) * 1.5f, *(f32 *)(v + 0x28));
}
/* localdecomp:end func_L13_003B3DA8 */

/* localdecomp:start func_L13_003B3F58 */
#include "vu0.h"

extern void func_L01_00443B88(f32 *, f32, f32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_00382498(s32, s32);
extern void func_L01_0046B458(f32 *, s32, s32, s32, s32, f32 *, f32, f32, f32, s32);

void func_L13_003B3F58(u8 *obj) {
    u8 *p = *(u8 **)(obj + 0x68);
    f32 vel[4];
    f32 pos[4];
    s32 i;
    f32 f20;
    f32 f21;

    for (i = 5; i >= 0; i--) {
        func_L01_00443B88(vel, 0.120000005f, 0.20000002f);
        f20 = func_003824E0(1.0f, 2.0f);
        func_0038CF68(pos, p, *(f32 *)(p + 0x30));
        vec_add_ba(pos, p + 0x10, pos);
        ((void (*)(f32 *, s32, f32, f32, s32, s32, s32, f32 *, f32, s32))func_L01_0046B458)(pos, 8, f20, f20, 0x7F076007, 0, func_00382498(-3, 3), vel, 0.0f, 0);
        f21 = f20 * 0.5f;
        ((void (*)(f32 *, s32, f32, f32, s32, s32, s32, f32 *, f32, s32))func_L01_0046B458)(pos, 8, f21, f21, 0x7F075F07, 0, func_00382498(-3, 3), vel, 0.0f, 0);
    }
}
/* localdecomp:end func_L13_003B3F58 */

/* localdecomp:start func_L13_003B40A0 */
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

extern u8 *D_L13_001E8E98[];
extern G_003B40A0 D_L13_001E8E80;
extern vu0_v4 D_L13_001E8EA0;
extern H_003B40A0 D_L13_0021EF18;
extern f32 D_L13_001D66B0[2];
__asm__(".extern D_L13_001D66B0, 16");

extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CF38(void *, void *);
extern s32 func_L01_0040E020(void *);
extern void func_003C2880(void *);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern void func_L01_004CB320(void);
extern void func_L01_004CB358(void);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern f32 func_0038CEA8(void *);
extern void func_L13_003B3F58(u8 *);
extern s32 func_00382498(s32, s32);
extern u8 *func_L01_004713C8(void *, void *, s32, u32, s32, s32, s32, s32, f32, f32, f32);
extern f32 func_003824E0(f32, f32);
extern void func_L01_00404808(void *, void *);
extern void func_L13_003B3DA8(void *);
extern void func_L01_0046B458(f32 *, s32, s32, s32, s32, f32 *, f32, f32, f32, s32);

void func_L13_003B40A0(u8 *self) {
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
    func_0038CF68(&a, v, *(f32 *)(v + 0x30));
    vec_add_ab(&a, v + 0x10, &a);
    func_0038CF68(&b, v, 0.90000004f);
    if (v[0x25] < 0x3A) {
        if (func_0038CF38(v + 0x10, &a) > 3.0000002f) {
            vec_add_ab(v + 0x10, v + 0x10, &b);
        }
    }
    if (func_L01_0040E020(v + 0x25) != 0) {
        func_003C2880(self);
        return;
    }
    *(f32 *)(v + 0x30) = *(f32 *)(v + 0x30) + 0.90000004f;
    if (v[0x25] < 0xD) {
        t = *(f32 *)(v + 0x2C) - 0.15f;
        *(f32 *)(v + 0x2C) = t;
        if (t < 0.0f) {
            *(f32 *)(v + 0x2C) = 0.0f;
        }
    }
    func_0038CF68(&c, v, 1.0f);
    func_L01_00446760(&info, self, *(s32 *)(v + 0x20), &c, (f32)v[0x24]);
    info.x18 = 1;
    info.x19 = 1;
    info.x1A = *(u16 *)(self + 0xAA);
    tgt = *(void **)(self + 0xB8);
    func_L01_004CB320();
    hit = func_003D3CB0(v + 0x10, &a, 0x10, tgt, &info);
    if (hit != 0) {
        o = D_L13_001E8E98[0];
        if (o != 0 && *(s16 *)(o + 0xAA) == 0x186D && o[0x20] != 2 && o[0x20] != 5) {
            o[0x20] = 4;
        }
    }
    func_L01_004CB358();
    if (hit != 0) {
        u8 *q = D_L13_001E8E80.x18;

        if (q == 0 || *(s16 *)(q + 0xAA) == 0x1868) {
            *(s32 *)(v + 0x34) = 1;
            *(vu0_q *)&a = *(vu0_q *)&D_L13_001E8E80.x20;
            vec_sub_ab(&d, &a, v + 0x10);
            *(f32 *)(v + 0x30) = func_0038CEA8(&d);
            func_L13_003B3F58(self);
        }
    }
    tgt = *(void **)(self + 0xB8);
    func_L01_004CB320();
    hit = func_003D3CB0(v + 0x10, &a, 0x12, tgt, 0);
    if (hit != 0) {
        o = D_L13_001E8E98[0];
        if (o != 0 && *(s16 *)(o + 0xAA) == 0x186D && o[0x20] != 2 && o[0x20] != 5) {
            o[0x20] = 4;
        }
    }
    func_L01_004CB358();
    if (hit != 0) {
        *(s32 *)(v + 0x34) = 1;
        *(vu0_q *)&a = *(vu0_q *)&D_L13_001E8EA0;
        vec_sub_ab(&d, &a, v + 0x10);
        *(f32 *)(v + 0x30) = func_0038CEA8(&d);
        func_L13_003B3F58(self);
    }
    hi = 0x1E;
    lo = 0x14;
    if (*(s32 *)(v + 0x34) != 0) {
        hi = 5;
        lo = 3;
    }
    if (v[0x25] >= 0xA) {
        u8 *p;
        s32 n;

        p = ((u8 * (*)(f32 *, s32, s32, s32, s32, f32 *, f32, f32, f32, s32))func_L01_0046B458)(
            (f32 *)(v + 0x10), 8, 0xAF076007, 0, 2, D_L13_001D66B0, 2.0f, 0.0f, 0.0f, 0);
        if (p != 0) {
            p[3] = 0x44;
        }
    }
    for (i = 0; i < 2; i++) {
        u8 *p;
        s32 n;

        n = (func_00382498(lo, hi) * 5 + 2) / 6;
        p = func_L01_004713C8(&a, D_L13_001D66B0, n, 0x96309, func_00382498(-5, 5), 0x4F, 0, 0, 262500.0f, 0.0f,
                              -0.00040000002f);
        if (p != 0) {
            p[2] = D_L13_0021EF18.x1A0[func_00382498(0, 3)];
        }
    }
    d = a;
    for (i = 0; i < 2; i++) {
        u8 *p;
        s32 n;

        d.x += func_003824E0(-0.2f, 0.2f);
        d.y += func_003824E0(-0.2f, 0.2f);
        d.z += func_003824E0(-0.2f, 0.2f);
        n = (func_00382498(lo, hi) * 5 + 2) / 6;
        p = func_L01_004713C8(&d, D_L13_001D66B0, n, 0x509650, func_00382498(-5, 5), 0x4F, 0, 0, 262500.0f, 0.0f,
                              -0.00040000002f);
        if (p != 0) {
            p[2] = D_L13_0021EF18.x184[5];
        }
    }
    func_L01_00404808(func_L13_003B3DA8, self);
}
/* localdecomp:end func_L13_003B40A0 */
