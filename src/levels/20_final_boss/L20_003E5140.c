#include "common.h"

/* declared by functions of L20_003E5058.c, which this file was cut from */
extern f32 func_003824E0(f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_00382498(s32, s32);
extern u8 *func_L01_0046B458(void *, s32, f32, f32, s32, s32, s32, void *, f32, s32);

/* localdecomp:start func_L20_003E5140 */
#include "vu0.h"

typedef struct {
    u8 pad0[0x18];
    u8 x18;
    u8 x19;
    u16 x1A;
    u8 pad1C[0x14];
} __attribute__((aligned(16))) S_003E5140;

typedef struct {
    u8 pad0[0x18];
    u8 *x18;
    u8 pad1C[4];
    vu0_v4 x20;
} G_003E5140;

typedef struct {
    u8 pad0[0xD4];
    u8 *xD4;
} H_003E5140;

extern u8 D_001A30B0_003E5140[];
extern u8 *D_L20_001E9BD8_003E5140[];
extern G_003E5140 D_L20_001E9BC0_003E5140;
extern vu0_v4 D_L20_001E9BE0_003E5140;
extern H_003E5140 D_L20_00220258_003E5140;
extern f32 D_L20_001D66B0_003E5140[2];
__asm__(".extern D_L20_001D66B0_003E5140, 16");

extern f32 func_0038CEA8(void *);
extern s32 func_L01_0040E020(void *);
extern void func_003C2880(void *);
extern void func_003A4F28(s32);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern void func_L01_004CB320(void);
extern void func_L01_004CB358(void);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern void func_L20_003E5058(u8 *);
extern u8 *func_L01_004713C8(void *, void *, s32, u32, s32, s32, s32, s32, f32, f32, f32);
extern void func_L01_00404808(void *, void *);
extern void func_L13_003B3DA8(void *);

void func_L20_003E5140(u8 *self) {
    vu0_v4 a;
    S_003E5140 info;
    vu0_v4 c;
    vu0_v4 d;
    vu0_v4 e;
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
    if (func_L01_0040E020(v + 0x25) == 0) {
        *(f32 *)(v + 0x30) = *(f32 *)(v + 0x30) + 1.2f;
        if (v[0x25] < 0xD) {
            t = *(f32 *)(v + 0x2C) - 0.15f;
            *(f32 *)(v + 0x2C) = t;
            if (t < 0.0f) {
                *(f32 *)(v + 0x2C) = 0.0f;
            }
        }
    } else {
        s32 idx = *(s32 *)(v + 0x38);

        if (idx != -1) {
            u8 *e = D_001A30B0_003E5140 + (idx << 7);

            if (*(u8 **)(e + 0xDC) == self && e[0xD0] != 0) {
                func_003A4F28(idx);
            }
        }
        *(s32 *)(v + 0x38) = -1;
        func_003C2880(self);
        return;
    }
    func_0038CF68(&c, v, 1.0f);
    func_L01_00446760(&info, self, *(s32 *)(v + 0x20), &c, (f32)v[0x24]);
    info.x18 = 1;
    info.x19 = 1;
    info.x1A = *(u16 *)(self + 0xAA);
    tgt = *(void **)(self + 0xB8);
    func_L01_004CB320();
    hit = func_003D3CB0(v + 0x10, &a, 0, tgt, &info);
    if (hit != 0) {
        o = D_L20_001E9BD8_003E5140[0];
        if (o != 0 && *(s16 *)(o + 0xAA) == 0x186D && o[0x20] != 2 && o[0x20] != 5) {
            o[0x20] = 4;
        }
    }
    func_L01_004CB358();
    if (hit != 0) {
        u8 *q = D_L20_001E9BC0_003E5140.x18;

        if (q == 0 || *(s16 *)(q + 0xAA) == 0x1868) {
            *(s32 *)(v + 0x34) = 1;
            *(vu0_q *)&a = *(vu0_q *)&D_L20_001E9BC0_003E5140.x20;
            vec_sub_ab(&d, &a, v + 0x10);
            *(f32 *)(v + 0x30) = func_0038CEA8(&d);
            func_L20_003E5058(self);
        }
    }
    tgt = *(void **)(self + 0xB8);
    func_L01_004CB320();
    hit = func_003D3CB0(v + 0x10, &a, 2, tgt, 0);
    if (hit != 0) {
        o = D_L20_001E9BD8_003E5140[0];
        if (o != 0 && *(s16 *)(o + 0xAA) == 0x186D && o[0x20] != 2 && o[0x20] != 5) {
            o[0x20] = 4;
        }
    }
    func_L01_004CB358();
    if (hit != 0) {
        *(s32 *)(v + 0x34) = 1;
        *(vu0_q *)&a = *(vu0_q *)&D_L20_001E9BE0_003E5140;
        vec_sub_ab(&d, &a, v + 0x10);
        *(f32 *)(v + 0x30) = func_0038CEA8(&d);
        func_L20_003E5058(self);
    }
    hi = 0x1E;
    lo = 0x14;
    if (*(s32 *)(v + 0x34) != 0) {
        hi = 5;
        lo = 3;
    }
    if (v[0x25] >= 3) {
        u8 *p;

        p = func_L01_0046B458(v + 0x10, 4, 2.0f, 0.0f, 0xAF000000, 0, 2, D_L20_001D66B0_003E5140, 0.0f, 0);
        if (p != 0) {
            p[3] = 0x44;
        }
    }
    for (i = 0; i < 2; i++) {
        u8 *p;
        s32 n;

        func_0038CF68(&e, v, -(func_003824E0(0.0f, 50.0f) * 0.020000001f));
        vec_add_ab(&d, &a, &e);
        n = (func_00382498(lo, hi) * 5 + 2) / 6;
        p = func_L01_004713C8(&d, D_L20_001D66B0_003E5140, n, 0x7F000000, func_00382498(-5, 5), 0x4F, 0, 0, 210000.0f,
                              21000.0f, -0.00040000002f);
        if (p != 0) {
            p[3] = 0x44;
            p[2] = D_L20_00220258_003E5140.xD4[0];
        }
    }
    d = a;
    for (i = 0; i < 1; i++) {
        u8 *p;
        s32 n;

        d.x += func_003824E0(-0.2f, 0.2f);
        d.y += func_003824E0(-0.2f, 0.2f);
        d.z += func_003824E0(-0.2f, 0.2f);
        n = (func_00382498(lo, hi) * 5 + 2) / 6;
        p = func_L01_004713C8(&d, D_L20_001D66B0_003E5140, n, 0xA0A96, func_00382498(-5, 5), 0x4F, 0, 0, 157500.0f, 0.0f,
                              -0.00040000002f);
        if (p != 0) {
            p[2] = D_L20_00220258_003E5140.xD4[0];
        }
    }
    func_L01_00404808(func_L13_003B3DA8, self);
}
/* localdecomp:end func_L20_003E5140 */
