#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L24_003B6050 */
extern s32 D_001D545C;
extern s32 D_L24_001DD570;
__asm__(".extern D_L24_001DD570, 16");
extern s32 func_L24_003B6320(u8 *);
extern void func_003C2880(void *);
extern void func_L24_00355C18(u8 *, s32, s32, void *, s32, f32);
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_003C2F58(void *, s32, void *);
extern s32 func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_004AA7E8(void *, s32);

void func_L24_003B6050(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    s32 t;
    if (func_L24_003B6320(a0) != 0) {
        func_003C2880(a0);
        return;
    }
    t = D_001D545C;
    if (t != 0x539 && t != 0x18 && t != 3) {
        return;
    }
    if (*(s32 *)(p + 0x938) != 0) {
        return;
    }
    if (D_L24_001DD570 != 0 && a0[0x20] < 2) {
        return;
    }
    if (a0[0x20] == 1) {
        *(u16 *)(*(u8 **)(p + 0x8DC) + 0x34) &= 0xFFBE;
        *(u16 *)(*(u8 **)(p + 0x8DC) + 0x34) |= *(u16 *)(*(u8 **)(*(u8 **)(p + 0x8DC) + 0x24) + 0x44) & 0x1000;
        *(s32 *)(*(u8 **)(p + 0x8DC) + 0x98) = *(s32 *)(*(u8 **)(*(u8 **)(p + 0x8DC) + 0x24) + 0x10);
        *(u16 *)(a0 + 0x34) &= 0xFFBE;
        *(u16 *)(a0 + 0x34) |= *(u16 *)(*(u8 **)(a0 + 0x24) + 0x44) & 0x1000;
        *(s32 *)(a0 + 0x98) = *(s32 *)(*(u8 **)(a0 + 0x24) + 0x10);
        func_L24_00355C18(a0, 1, 0, p + 0x910, *(s32 *)(p + 0x90C), *(f32 *)(p + 0x930));
        if (func_L01_00447490(a0, -1, 0) != 0) {
            func_L01_004450F0(a0, 2, -1);
            if (a0[0x43] != 4) {
                func_003C3A10(a0, 4, 0, 3);
            }
        }
    } else if (a0[0x20] == 2) {
        if (a0[0x60] & 2) {
            u8 v[16] __attribute__((aligned(16)));
            func_003C2F58(a0, 5, v);
            func_L01_003303B8(v, 0, 0x19, 0x14, 0x14, 0x14, 0x2D, 2, 0.75f, 0.0f, 0.0f, 2.0f,
                0, 1, 0, 0, 1, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            a0[0xA8] = 0xFF;
            *(u16 *)(*(u8 **)(p + 0x8DC) + 0x34) |= 0x41;
            *(u16 *)(*(u8 **)(p + 0x8DC) + 0x34) &= 0xEFFF;
            *(s32 *)(*(u8 **)(p + 0x8DC) + 0x98) = 0;
            func_L01_004AA7E8(*(u8 **)(p + 0x8DC), 1);
            *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x41) & 0xEFFF;
            *(s32 *)(a0 + 0x98) = 0;
            func_L01_004AA7E8(a0, 1);
            *(u16 *)(a0 + 0x34) |= 2;
            func_L01_004450F0(a0, 3, -1);
        }
    }
}
/* localdecomp:end func_L24_003B6050 */

/* localdecomp:start func_L24_003B6320 */
extern s32 D_001D545C;
extern s32 func_L24_003B64C8();
extern void func_L01_0044FD88(void *, s32, s32, s32);
extern void func_L01_00404808(void *, void *);
extern void func_L24_003B66C8(u8 *);
extern void func_L24_003B69F8(void *);
extern f32 func_L01_004395E0(void *);
extern void func_003C4138(void *, f32, f32);

s32 func_L24_003B6320(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    f32 f1;
    if (a0[0x20] == 0 && func_L24_003B64C8() != 0) {
        return 1;
    }
    if (*(s32 *)(p + 0x900) < 6) {
        *(s32 *)(p + 0x900) += 1;
    }
    if (*(s32 *)(p + 0x8DC) != 0) {
        func_L01_0044FD88(a0, *(s32 *)(p + 0x8DC), 0, 0);
        func_L01_00404808(func_L24_003B66C8, a0);
        func_L24_003B69F8(a0);
    }
    f1 = func_L01_004395E0(a0);
    if (a0[0x43] == 0 || (a0[0x42] == 3 && f1 > 17.0f)) {
        func_003C4138(p + 0x8E4, 2.0f, 0.12000000476837158f);
        func_003C4138(p + 0x8E8, 2.0f, 0.12000000476837158f);
    } else if (a0[0x42] == 5 && f1 > 16.0f) {
        func_003C4138(p + 0x8E4, 3.5f, 0.12000000476837158f);
        func_003C4138(p + 0x8E8, 1.5f, 0.12000000476837158f);
    }
    if (D_001D545C == 0x18) {
        *(f32 *)(a0 + 0x18) = 101.86f;
    } else {
        *(f32 *)(a0 + 0x18) = 48.84f;
    }
    return 0;
}
/* localdecomp:end func_L24_003B6320 */

/* localdecomp:start func_L24_003B64C8 */
typedef int vu0_q_003B64C8 __attribute__((mode(TI)));

__asm__(".extern D_L24_001DE800, 4");
extern f32 D_L24_001DE800;
extern s32 D_L24_001DD584;
extern f32 D_L24_001DD580;
extern f32 D_L24_001DD57C;

typedef struct {
    u8 pad0[0x10];
    vu0_q_003B64C8 x10;
    u8 pad20[0x4];
    u8 *x24;
    u8 pad28[0x4];
    f32 x2C;
    u8 pad30[0x4];
    u16 x34;
    u8 pad36[0x62];
    s32 x98;
} M_003B64C8;

typedef struct {
    u8 pad0[0x30];
    f32 x30;
    s16 x34;
    u8 pad36[0x3];
    u8 x39;
    u8 pad3A[0x6];
    f32 x40;
    u8 pad44[0x14];
    u8 x58;
    u8 pad59;
    u8 x5A;
    u8 pad5B[0x15];
    f32 x70;
    f32 x74;
    f32 x78;
    f32 x7C;
    f32 x80;
    u8 pad84[0x18];
    f32 x9C;
    f32 xA0;
    u8 padA4[0x8DC - 0xA4];
    M_003B64C8 *x8DC;
    u8 pad8E0[0x4];
    f32 x8E4;
    f32 x8E8;
    u8 pad8EC[0x4];
    s32 x8F0;
    s32 x8F4;
    u8 pad8F8[0x14];
    s32 x90C;
    u8 pad910[0x20];
    f32 x930;
    u8 pad934[0xC];
    vu0_q_003B64C8 x940;
} S_003B64C8;

extern M_003B64C8 *func_003C24B0(s32, s32);
extern void func_L01_00456160(void *, void *);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_L01_004450F0(void *, s32, s32);

s32 func_L24_003B64C8(u8 *arg) {
    M_003B64C8 *a0 = (M_003B64C8 *)arg;
    S_003B64C8 *p = *(S_003B64C8 **)(arg + 0x68);
    M_003B64C8 *e;
    p->x70 = 0.5f;
    p->x74 = 0.1f;
    p->x78 = 0.5f;
    p->x7C = 1.0f;
    p->x80 = 0.785398185f;
    p->xA0 = 0.34906584f;
    p->x9C = 0.00392000005f;
    if (p->x34 == 0) {
        p->x34 = 100;
        p->x30 = 100.0f;
    }
    p->x39 = 1;
    p->x40 = 2.0f;
    p->x58 = 0x14;
    p->x5A = 0xE;
    func_L01_00456160(p->x8DC = func_003C24B0(0x1B5C, 0x80), a0);
    a0->x2C = *(f32 *)(a0->x24 + 0x24) * D_L24_001DE800;
    p->x8F0 = 0x4096006B;
    p->x8F4 = 0x450030;
    p->x8E4 = 2.0f;
    p->x8E8 = 2.0f;
    e = p->x8DC;
    e->x2C = *(f32 *)(e->x24 + 0x24) * 0.300000012f * D_L24_001DE800;
    a0->x34 &= 0xFFBE;
    a0->x34 |= *(u16 *)(a0->x24 + 0x44) & 0x1000;
    a0->x98 = *(s32 *)(a0->x24 + 0x10);
    p->x8DC->x34 &= 0xFFBE;
    p->x8DC->x34 |= *(u16 *)(p->x8DC->x24 + 0x44) & 0x1000;
    p->x8DC->x98 = *(s32 *)(p->x8DC->x24 + 0x10);
    p->x90C = D_L24_001DD584;
    p->x930 = D_L24_001DD580;
    func_L01_0045BD78(a0, D_L24_001DD57C, D_L24_001DD57C, 0.50265485f, 0.50265485f);
    p->x940 = a0->x10;
    func_L01_004450F0(a0, 1, -1);
    return 0;
}
/* localdecomp:end func_L24_003B64C8 */

/* localdecomp:start func_L24_003B66C8 */
#include "vu0.h"
extern void func_003C2F58(void *, s32, void *);
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_0040A8C0(void *, void *, u32, s32, u32, u32, u32, u32, f32, f32, f32);
extern void func_L01_00408C98(void *, s32, void *, void *, s32, s32, f32, s32, s32, s32);
__asm__(".extern D_L24_001DE808, 4");
__asm__(".extern D_L24_001DE804, 4");
extern const u32 D_L24_001DE808;
extern s32 D_L24_001DE804;

void func_L24_003B66C8(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    f32 a[4] __attribute__((aligned(16)));
    f32 b[4] __attribute__((aligned(16)));
    f32 c[4] __attribute__((aligned(16)));
    f32 d[4] __attribute__((aligned(16)));
    f32 w1[4] __attribute__((aligned(16)));
    f32 w2[4] __attribute__((aligned(16)));
    f32 m[16] __attribute__((aligned(16)));
    f32 w[4] __attribute__((aligned(16)));
    f32 t;
    u8 *q;

    t = *(f32 *)(s + 0x8E0) - 0.1f;
    *(f32 *)(s + 0x8E0) = t;
    if (t <= -8.0f) {
        *(f32 *)(s + 0x8E0) = t + 8.0f;
    }
    func_003C2F58(*(u8 **)(s + 0x8DC), 0, a);
    func_003C2F58(*(u8 **)(s + 0x8DC), 2, b);
    func_003C2F58(*(u8 **)(s + 0x8DC), 1, c);
    func_003C2F58(*(u8 **)(s + 0x8DC), 3, d);
    vec_sub_ba(w1, a, c);
    func_0038CF68(w1, w1, *(f32 *)(s + 0x8E8));
    vec_add_ba(c, w1, a);
    vec_sub_ba(w2, b, d);
    func_0038CF68(w2, w2, *(f32 *)(s + 0x8E4));
    vec_add_ab(d, w2, b);
    func_003C2EC0(*(u8 **)(s + 0x8DC), 1, m);
    *(vu0_q *)w = *(vu0_q *)m;
    func_0038CF68(w, w, -2.75f);
    *(vu0_q *)(s + 0x6D0) = *(vu0_q *)w;
    *(f32 *)(s + 0x6DC) = 1.0f;
    *(vu0_q *)w = *(vu0_q *)m;
    func_0038CF68(w, w, 0.75f);
    *(vu0_q *)(s + 0x6C0) = *(vu0_q *)w;
    *(f32 *)(s + 0x6CC) = 1.0f;
    q = s + 0x6C0;
    func_L01_0040A8C0(a, c, D_L24_001DE808, 1, 0x6FFFFFFF, 0x6FFFFFFF, 0x6FFFFFFF, 0x6FFFFFFF, 0.035f, 0.45f, *(f32 *)(s + 0x8E0));
    func_L01_0040A8C0(b, d, D_L24_001DE808, 1, 0x6FFFFFFF, 0x6FFFFFFF, 0x6FFFFFFF, 0x6FFFFFFF, 0.035f, 0.45f, *(f32 *)(s + 0x8E0));
    func_L01_0040A8C0(a, c, D_L24_001DE808, 1, 0x7F96006B, 0x7F96006B, 0x7F96006B, 0x7F96006B, 0.08f, 0.75f, *(f32 *)(s + 0x8E0));
    func_L01_0040A8C0(b, d, D_L24_001DE808, 1, 0x7F96006B, 0x7F96006B, 0x7F96006B, 0x7F96006B, 0.08f, 0.75f, *(f32 *)(s + 0x8E0));
    func_L01_00408C98(q, D_L24_001DE804, s + 0x2C0, s + 0x4C0, *(s32 *)(s + 0x8EC), *(s32 *)(s + 0x8FC), *(f32 *)(s + 0x8F8), *(s32 *)(s + 0x8F0), *(s32 *)(s + 0x8F4), 5);
}
/* localdecomp:end func_L24_003B66C8 */

/* localdecomp:start func_L24_003B69F8 */
__asm__(".extern D_L24_001DE804, 4");
extern s32 D_L24_001DE804;
extern void func_003C2F58(void *, s32, void *);
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_0044C280(void *, void *, void *, s32, f32);
extern void func_003C3FC0(void *, void *);

void func_L24_003B69F8(void *arg0) {
    u8 *a0 = arg0;
    f32 a[4] __attribute__((aligned(16)));
    f32 d[16] __attribute__((aligned(16)));
    f32 e[4] __attribute__((aligned(16)));
    f32 f[4] __attribute__((aligned(16)));
    f32 g[4] __attribute__((aligned(16)));
    f32 h[4] __attribute__((aligned(16)));
    f32 i[4] __attribute__((aligned(16)));
    f32 j[4] __attribute__((aligned(16)));
    u8 *p = *(u8 **)(a0 + 0x68);
    *(s32 *)(p + 0x8F8) = 0;
    func_003C2F58(*(u8 **)(p + 0x8DC), 3, a);
    func_003C2EC0(*(u8 **)(p + 0x8DC), 3, d);
    func_003C2F58(*(u8 **)(p + 0x8DC), 2, e);
    vec_sub_ab(f, e, a);
    func_0038CF68(f, f, *(f32 *)(p + 0x8E4));
    vec_add_ab(a, f, e);
    if (*(f32 *)(p + 0x8F8) == 0.0f) {
        s32 n = D_L24_001DE804;
        *(s32 *)(p + 0x8EC) = (*(s32 *)(p + 0x8EC) + 1) % n;
        if (*(s32 *)(p + 0x8FC) < n) {
            *(s32 *)(p + 0x8FC) = *(s32 *)(p + 0x8FC) + 1;
        }
    }
    g[0] = 0;
    g[1] = 0;
    g[2] = 0;
    g[3] = 0;
    if (*(s32 *)(p + 0x900) >= 2) {
        s32 n = D_L24_001DE804;
        s32 t = n - 1;
        s32 k = (*(s32 *)(p + 0x8EC) + t) % n;
        vec_sub_ab(h, a, a0 + 0x10);
        vec_sub_ba(i, p + 0x2C0 + k * 16, a0 + 0x10);
        func_L01_0044C280(j, i, h, 0, 0.5f);
        func_003C3FC0(p + 0x4C0 + *(s32 *)(p + 0x8EC) * 16, g);
        vec_add_ba(p + 0x2C0 + *(s32 *)(p + 0x8EC) * 16, j, a0 + 0x10);
        *(s32 *)(p + 0x8EC) = (*(s32 *)(p + 0x8EC) + 1) % D_L24_001DE804;
    }
    func_003C3FC0(p + 0x4C0 + *(s32 *)(p + 0x8EC) * 16, g);
    *(vu0_q *)(p + 0x2C0 + *(s32 *)(p + 0x8EC) * 16) = *(vu0_q *)a;
}
/* localdecomp:end func_L24_003B69F8 */
