#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L04_00366800 */
typedef int u128_t_366800 __attribute__((mode(TI)));
extern u8 D_L04_001E2840[];
extern void func_L04_00366AC8(u8 *, u8 *);
extern void func_L04_00366DC8(u8 *, u8 *);
extern s32 func_L01_00456250(void *);
extern s32 func_003A52A0(s32, s32, void *);
extern f32 func_L01_0040E548(void *, void *);
extern s32 func_0038CAD0(void *);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_L01_0045D248(void *, void *, void *);
extern s32 func_L01_0045D218(void *, void *);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_003C48A8(void *, void *);
extern void func_L01_00366EA8(void *, void *, void *, s32, s32);
extern void func_L01_0044F450(void *, void *);
extern void func_L01_004472C0(void *);

void func_L04_00366800(u8 *a0) {
    u8 *q = *(u8 **)(a0 + 0x68);
    u8 *h;
    vu0_v4 d;

    switch (a0[0x20]) {
    case 0:
        func_L04_00366AC8(a0, q);
        break;
    case 1:
        if (func_L01_00456250(*(u8 **)(q + 0x12C)) != 0) {
            if (*(s32 *)(q + 0x300) == 0) {
                func_003A52A0(0, 0, a0);
                *(s32 *)(q + 0x300) = 1;
            }
        } else {
            *(s32 *)(q + 0x300) = 0;
        }
        func_L04_00366DC8(a0, q);
        *(s32 *)(*(u8 **)(q + 0x12C) + 0x98) = 0;
        if (func_L01_0040E548(a0 + 0x10, q + 0x2C0) < *(f32 *)(q + 0x64)) {
            if (func_0038CAD0(q + 0x130) != 0) {
                *(u128_t_366800 *)&d = *(u128_t_366800 *)(q + 0x2D0);
            } else {
                vec_sub_ab(&d, q + 0x2C0, a0 + 0x10);
            }
            func_0038CF68(&d, &d, 1.0f);
            func_L01_0045D248(a0, q + 0x2C0, &d);
            if (*(s32 *)(q + 0xCC) & 2) {
                if (a0[0x43] != 1) {
                    func_003C3A10(a0, 1, 0, 10);
                }
            } else if (a0[0x43] != 0) {
                func_003C3A10(a0, 0, 0, 10);
            }
        } else {
            func_L01_0045D218(a0, q + 0x2C0);
            *(s32 *)(q + 0x130) = 0x5A;
            if (a0[0x43] != 1) {
                func_003C3A10(a0, 1, 0, 10);
            }
        }
        h = *(u8 **)(q + 0x12C);
        *(s32 *)(h + 0x98) = *(s32 *)(*(u8 **)(h + 0x24) + 0x10);
        func_003C48A8(a0 + 0xC0, a0 + 0xF0);
        func_L01_00366EA8(q + 0x134, q + 0x138, q + 0x140, 0, func_L01_00456250(*(u8 **)(q + 0x12C)));
        if (func_L01_0040E548(a0 + 0x10, q + 0x2E0) > 0.0001f || func_L01_0040E548(a0 + 0xF0, q + 0x2F0) > 3.0461742e-06f) {
            func_L01_0044F450(a0, q + 0x180);
            *(u128_t_366800 *)(q + 0x2E0) = *(u128_t_366800 *)(a0 + 0x10);
            *(u128_t_366800 *)(q + 0x2F0) = *(u128_t_366800 *)(a0 + 0xF0);
        }
        break;
    }
    if (a0[0x31] != 0) {
        if (func_L01_0040E548(D_L04_001E2840, a0 + 0x10) < 576.0f) {
            func_L01_004472C0(a0);
            a0[0x6F] = 0x16;
        }
    }
}
/* localdecomp:end func_L04_00366800 */

/* localdecomp:start func_L04_00366AC8 */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_366AC8;
typedef int u128_t_366AC8 __attribute__((mode(TI)));

typedef struct {
    u8 pad0[0x30];
    f32 f30, f34, f38, f3C, f40;
    u8 pad44[0x18];
    s32 f5C;
    f32 f60, f64;
    s32 f68;
} State_366AC8;

extern u16 *D_L04_0021C9A0[];
extern u8 *D_L04_001DFD9C;
__asm__(".extern D_L04_001DFD9C, 16");
extern u8 *D_L04_001DFE80;
__asm__(".extern D_L04_001DFE80, 16");
extern u8 D_001BBC40[];
extern s32 D_001DFDD8_sda;
__asm__(".extern D_001DFDD8_sda, 4");
extern s32 D_001D545C_sda;
__asm__(".extern D_001D545C_sda, 4");
extern f32 D_001DD7F4_sda;
__asm__(".extern D_001DD7F4_sda, 4");

extern void func_003C2F58(void *, s32, void *);
extern void func_0038D308(void *, void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_0044F450(void *, void *);
extern void func_L01_0044ED88(void *, void *, s32, s32, s32, s32, s32, s32);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_L01_00366E48(void *, void *, void *, void *, s32);
extern void func_003C3A10(void *, s32, s32, s32);

void func_L04_00366AC8(u8 *a0, u8 *a1) {
    u16 *p;
    u8 *e;
    V4_366AC8 t;
    u128_t_366AC8 v;
    u8 *q;
    u8 *pos;
    s32 f;
    f32 turn;
    State_366AC8 *state = (State_366AC8 *)a1;

    a0[0x30] = 0x20;
    *(u16 *)(a0 + 0x32) = 0x20;
    *(V4_366AC8 *)(a1 + 0x2C0) = *(V4_366AC8 *)(a0 + 0x10);
    p = D_L04_0021C9A0[*(s32 *)(a1 + 0x120)];

    for (;;) {
        f = *(s32 *)(a1 + 0x120);
        if ((u8)f == 0xFF) break;
        if (D_001DFDD8_sda < f) break;
        if (p == 0) break;
        if ((s16)p[-1] < 0 && p != D_L04_0021C9A0[f]) break;
        e = D_L04_001DFD9C + ((*p & 0x7FFF) << 8);
        if (e == 0) break;
        *(u16 *)(e + 0x34) |= 0x41;
        if (*(s16 *)(e + 0xAA) == 0x1860) {
            *(u8 **)(a1 + 0x12C) = e;
            *(u8 **)(e + 0xB8) = a0;
            func_003C2F58(a0, 0, &t);
            *(V4_366AC8 *)(e + 0x10) = t;
        } else if (*(s16 *)(e + 0xAA) == 0x11C1) {
            *(u8 **)(e + 0xB8) = a0;
            func_003C2F58(a0, 1, &t);
            *(V4_366AC8 *)(e + 0x10) = t;
        }
        p++;
    }

    pos = a0 + 0xF0;
    func_L01_0044ED88(a0, a1 + 0x180, 4, *(s32 *)(a1 + 0x120), -1, -1, 7, 0);

    state->f34 = 0.1f;
    state->f38 = 0.1f;
    state->f30 = 0.2f;
    state->f3C = 0.1f;
    state->f40 = 0.61086524f;
    state->f60 = 0.08726646f;
    state->f64 = 0.75f;
    state->f68 |= 4;
    state->f5C = 0;
    turn = D_001DD7F4_sda;
    turn *= 0.020000001f;
    *(u16 *)(a0 + 0x34) |= 0x100;
    func_L01_0045BD78(a0, 0.0032000002f, turn, 0.0018849557f, 0.041887905f);
    *(s32 *)(a1 + 0x300) = 0;
    *(V4_366AC8 *)(a1 + 0x2E0) = *(V4_366AC8 *)(a0 + 0x10);
    *(V4_366AC8 *)(a1 + 0x2F0) = *(V4_366AC8 *)(a0 + 0xF0);
    func_L01_00366E48(a0, a1 + 0x134, a1 + 0x138, a1 + 0x140, 0);
    *(s32 *)(a1 + 0x130) = 0x5A;
    if (a0[0xB0] != 0xFF) {
        if ((D_001BBC40[a0[0xB0] + (D_001D545C_sda << 4)] & 0x80) != 0) {
            q = D_L04_001DFE80 + (*(s32 *)(a1 + 0x13C) << 7);
            v = *(u128_t_366AC8 *)(q + 0x30);
            *(u128_t_366AC8 *)(a0 + 0x10) = v;
            *(u128_t_366AC8 *)(a1 + 0x2C0) = v;
            *(V4_366AC8 *)(a0 + 0xF0) = *(V4_366AC8 *)(q + 0x70);
            func_0038D308(a0 + 0xC0, pos);
            func_L01_0044F450(a0, a1 + 0x180);
            *(V4_366AC8 *)(a1 + 0x2E0) = *(V4_366AC8 *)(a0 + 0x10);
            *(V4_366AC8 *)(a1 + 0x2F0) = *(V4_366AC8 *)(a0 + 0xF0);
            *(s32 *)(a1 + 0x300) = 1;
        }
    }
    func_L01_004450F0(a0, 1, -1);
    func_003C3A10(a0, 0, 0, 0);
}
/* localdecomp:end func_L04_00366AC8 */

/* localdecomp:start func_L04_00366DC8 */
typedef int u128_t_366DC8 __attribute__((mode(TI)));
extern u8 *D_L04_001DFD9C;
__asm__(".extern D_L04_001DFD9C, 16");
extern u8 *D_L04_001DFE80;
__asm__(".extern D_L04_001DFE80, 16");
extern u8 D_L04_001E95C0[];
__asm__(".extern D_L04_001DD7F0, 4");
extern f32 D_L04_001DD7F0;
extern s32 func_L04_00377698(void *);
extern s32 func_L04_00377720(void *);
extern s32 func_L04_00377118(void *, void *);
extern s32 func_L01_00456250(void *);
extern f32 func_L01_0040E548(void *, void *);
extern void func_0038CE20(f32 *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern f32 func_0038CE68(void *, void *);
extern s32 func_00382380(void *, s32, s32);
extern s32 func_L01_00456500(void *, s32);

void func_L04_00366DC8(u8 *a0, u8 *q) {
    vu0_v4 p;
    vu0_v4 s;
    vu0_v4 t;
    vu0_v4 r;
    vu0_v4 o;
    vu0_v4 n;
    u8 *e;
    u8 *h;
    u8 *d;
    f32 f;
    vu0_q q1;
    vu0_q q2;

    e = (u8 *)((*(s32 *)(q + 0x124) << 8) + (s32)D_L04_001DFD9C);
    if (*(s32 *)(*(u8 **)(e + 0x68) + 0x18) == 0)
        return;
    if (func_L04_00377698(e) == 0)
        return;
    if (func_L04_00377720(&o) == 0)
        return;
    if (func_L04_00377118(&r, &n) == 0)
        return;
    if (*(s32 *)(q + 0x13C) != -1) {
        h = D_L04_001DFE80 + (*(s32 *)(q + 0x13C) << 7);
        if (func_L01_00456250(*(u8 **)(q + 0x12C)) != 0) {
            if (func_L01_0040E548(a0 + 0x10, h + 0x30) < 1.6899998f)
                return;
        }
    } else {
        h = 0;
    }
    *(u128_t_366DC8 *)&s = *(u128_t_366DC8 *)&r;
    func_0038CE20(&t.x, &n, 8.0f);
    vec_add_ab(&t, &t, &o);
    if (func_003D3CB0(&s, &t, 2, a0, 0) == 0)
        return;
    d = D_L04_001E95C0;
    if (func_0038CE68(d, a0 + 0xE0) < 0.2f)
        return;
    f = func_0038CE68(d - 0x20, a0 + 0xE0);
    f = fabs_asm(f - func_0038CE68(a0 + 0x10, a0 + 0xE0));
    if (1.5f < f)
        return;
    *(u128_t_366DC8 *)&p = *(u128_t_366DC8 *)(d - 0x20);
    if (*(s32 *)(q + 0x128) != -1 && func_00382380(&o, *(s32 *)(q + 0x128), 0) == 0)
        return;
    if (*(s32 *)(q + 0x304) != -1 && func_L01_00456500(&o, *(s32 *)(q + 0x304)) == 0)
        return;
    if (func_L01_0040E548(&p, a0 + 0x10) > D_L04_001DD7F0 * D_L04_001DD7F0)
        return;
    if (h != 0 && func_L01_0040E548(&p, h + 0x30) < 1.6899998f) {
        *(f32 *)(q + 0x64) = 0.25f;
        *(u128_t_366DC8 *)(q + 0x2C0) = *(u128_t_366DC8 *)(h + 0x30);
    } else {
        *(u128_t_366DC8 *)(q + 0x2C0) = *(u128_t_366DC8 *)&p;
        *(f32 *)(q + 0x64) = 0.75f;
    }
    __asm__("lqc2 %0, %1" : "=j"(q1) : "m"(n));
    __asm__("vsub.xyz %0, $vf0, %1" : "=j"(q2) : "j"(q1));
    __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)(q + 0x2D0)) : "j"(q2));
}
/* localdecomp:end func_L04_00366DC8 */

/* localdecomp:start func_L04_00367068 */
extern void func_L04_003672E8(void *);
extern void func_L04_00367150(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_00447490(void *, s32, s32);
extern s32 func_0038CAD0(void *);

void func_L04_00367068(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);

    switch (a0[0x20]) {
    case 0:
        *(s32 *)p = 8;
        func_L01_004450F0(a0, 1, -1);
        break;
    case 1:
        if (func_L01_00447490(a0, -1, 0) != 0) {
            func_L01_004450F0(a0, 2, -1);
        }
        break;
    case 2:
        func_L04_003672E8(a0);
        func_L01_004450F0(a0, 3, -1);
        break;
    case 3:
        if (func_0038CAD0(p) != 0) {
            func_L04_00367150(a0);
        }
        break;
    }
    *(u8 *)(a0 + 0xA8) = 0xFF;
}
/* localdecomp:end func_L04_00367068 */

/* localdecomp:start func_L04_00367150 */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_367150;
extern void func_0038D000(void *, void *, void *);
extern s32 func_00382498(s32, s32);
extern void func_L02_003E2E38(void *, void *, f32, void *, s32, s32, s32, f32, f32, f32, f32);

void func_L04_00367150(void *a0) {
    u8 *p = (u8 *)a0;
    V4_367150 a;
    V4_367150 b;
    s32 r;
    s32 *q;

    q = *(s32 **)(p + 0x68);
    b = (V4_367150){0.0f, 0.0f, 0.0f, 0.0f};
    a = (V4_367150){0.0f, 0.0f, 5.0f, 0.0f};
    b.x = 0.040000003f;
    b.z = 0.040000003f;
    func_0038D000(&b, &b, p + 0xC0);
    r = func_00382498(3, 6);
    func_L02_003E2E38(p, &a, 0.0f, &b, r, 0, 0, 0.040000003f, 0.5f, 15.0f, 1.0f);
    b.x = -0.040000003f;
    b.z = 0.048000004f;
    func_0038D000(&b, &b, p + 0xC0);
    r = func_00382498(3, 6);
    func_L02_003E2E38(p, &a, 0.0f, &b, r, 1, 0, 0.040000003f, 0.5f, 15.0f, 1.0f);
    r = func_00382498(0x5A, 0xB4);
    *q = (r * 5 + 2) / 6;
}
/* localdecomp:end func_L04_00367150 */

/* localdecomp:start func_L04_003672E8 */
typedef int u128_t_3672E8 __attribute__((mode(TI)));
extern u8 D_L04_001D66B0[8];
extern void func_L01_00451FE0(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern u8 *func_L01_00452460(void *, s32, s32);
extern void func_0038CE20(f32 *, void *, f32);
extern void func_L02_00429840(void *, void *, s32, s32, void *, s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L02_003E2E38(void *, void *, f32, void *, s32, s32, s32, f32, f32, f32, f32);
extern void func_L02_00428520(void *, f32 *, f32, f32, f32);
extern void func_L01_0044AF78(void *, void *, void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);
extern void func_L01_00451E78(void *, s32, f32);

void func_L04_003672E8(void *o) {
    u8 *a0 = o;
    vu0_v4 b;
    vu0_v4 c;
    vu0_v4 a;
    vu0_v4 d;
    u8 *e;

    func_L01_00451FE0(a0, 0x3F, D_L04_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
    e = func_L01_00452460(a0, 0x1C77, 0);
    *(s32 *)(a0 + 0x98) = 0;
    a0[0x31] = 0;
    *(u16 *)(a0 + 0x34) |= 1;
    if (e != 0) {
        *(s32 *)(e + 0x98) = *(s32 *)(*(u8 **)(e + 0x24) + 0x10);
    }
    *(u128_t_3672E8 *)&b = 0;
    b.z = 1.0f;
    func_0038CE20(&c.x, &b, 4.0f);
    vec_add_ab(&b, &c, a0 + 0x10);
    func_L02_00429840(a0, &b, 7, 1, D_L04_001D66B0, 0x500092D6, 0, 0xB4, 0.25f, 3.0f, 0.5f, 0.75f);
    func_003A52A0(0, 0, a0);
    *(u128_t_3672E8 *)&c = 0;
    *(u128_t_3672E8 *)&a = 0;
    c.z = 18.0f;
    a.z = 0.14000001f;
    func_L02_003E2E38(a0, &c, 0.1f, &a, 0x50, 3, 0, 0.18f, 1.0f, 20.0f, 1.0f);
    *(u128_t_3672E8 *)&d = 0;
    func_L02_00428520(a0, &c.x, 0.0f, 0.0f, 18.0f);
    func_L01_0044AF78(a0, &d, &c, 10, 3, 5, -1, 0, 0, -1, 0, 0x1010001, 0.0f, 0.0f, 0.0f, 1.0f, 9.0f, 0.5f, 0.0f);
    func_L01_00451E78(a0, 1, 0.0f);
}
/* localdecomp:end func_L04_003672E8 */
