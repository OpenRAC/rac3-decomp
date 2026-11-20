#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L05_003C2618 */
extern u8 D_001A30B0[];
extern s32 func_L05_003C28C8(u8 *);
extern void func_L05_003C2B50(u8 *);
extern s32 func_003A52A0(s32, s32, void *);
extern s32 func_L01_00452FB0(void *, void *, s32, s32, s32);
extern void func_L02_00351780(void *);
extern s32 func_L01_00452860(void *, void *, s32);
extern void func_L01_00456BD0(void *, s32);
extern void func_L01_00456C98(void *, s32, f32, void *, s32, s32, s32, s32, s32, f32, f32, s32, s32);

s32 func_L05_003C2618(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    s32 i;
    u8 *e;

    if (a0[0x20] == 0) {
        if (func_L05_003C28C8(a0) != 0) {
            return 1;
        }
    }
    if (p[0x3E] == 2) {
        func_L05_003C2B50(a0);
        return 1;
    }
    if (*(f32 *)(p + 0x30) > 0.0f) {
        i = *(s32 *)(p + 0x320);
        if (i == -1 || *(u8 **)((e = D_001A30B0 + (i << 7)) + 0xDC) != a0 || e[0xD0] == 0) {
            *(s32 *)(p + 0x320) = func_003A52A0(0, 4, a0);
        }
    }
    if (*(f32 *)(a0 + 0x10) < 2.0f || *(f32 *)(a0 + 0x10) > 1021.0f) {
        return 1;
    }
    if (*(f32 *)(a0 + 0x14) < 2.0f || *(f32 *)(a0 + 0x14) > 1021.0f) {
        return 1;
    }
    if (*(f32 *)(a0 + 0x18) < 2.0f || *(f32 *)(a0 + 0x18) > 1021.0f) {
        return 1;
    }
    if (func_L01_00452FB0(a0, p + 0x160, 0, 0, 0) != 0) {
        func_L02_00351780(a0);
    }
    func_L01_00452860(a0, p + 0x30, 0);
    if (p[0x5E] != 0) {
        func_L05_003C2B50(a0);
        return 1;
    }
    if (p[0x5F] != 0) {
        func_L01_00456BD0(a0, 5);
        if (a0[0x95] == 0) {
            func_L01_00456C98(a0, *(s32 *)(p + 0x2C0), *(f32 *)(p + 0x2C4), 0, 0, 0, 0, 3, 0, 10.0f, 1.0f, 0, 0);
        } else {
            func_L01_00456C98(a0, *(s32 *)(p + 0x2C8), *(f32 *)(p + 0x2CC), 0, 0, 0, 0, 3, 0, 10.0f, 1.0f, 0, 0);
        }
    } else {
        func_L01_00456BD0(a0, 3);
        if (a0[0x95] == 0) {
            func_L01_00456C98(a0, *(s32 *)(p + 0x2C0), *(f32 *)(p + 0x2C4), 0, 0, 0, 0, 1, 0, 10.0f, 1.0f, 0, 0);
        } else {
            func_L01_00456C98(a0, *(s32 *)(p + 0x2C8), *(f32 *)(p + 0x2CC), 0, 0, 0, 0, 1, 0, 10.0f, 1.0f, 0, 0);
        }
    }
    return 0;
}
/* localdecomp:end func_L05_003C2618 */

/* localdecomp:start func_L05_003C28C8 */
extern void func_0038CF68(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_L01_004515D8(void *, void *, void *);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_L01_004450F0(u8 *a0, s32 a1, s32 a2);
extern void func_003C3A10(void *, s32, s32, s32);
extern vu0_v4 D_L05_001EA6E0[];

s32 func_L05_003C28C8(u8 *m) {
    u8 *v;
    vu0_v4 a;
    vu0_v4 b;
    s32 f;

    *(s32 *)(m + 0x78) = 0x7F107F10;
    v = *(u8 **)(m + 0x68);
    *(vu0_q *)(v + 0x340) = *(vu0_q *)(m + 0x10);
    *(vu0_q *)(v + 0x330) = *(vu0_q *)(m + 0xF0);
    if (*(s32 *)(v + 0x2F4) != 0) {
        *(u16 *)(m + 0x34) |= 0x100;
        func_0038CF68(&a, m + 0xE0, -2.0f);
        func_0038CF68(&b, m + 0xE0, 0.5f);
        vec_add_ba(&b, &b, m + 0x10);
        vec_add_ba(&a, &a, m + 0x10);
        if (func_003D3CB0(&b, &a, 0, m, 0) != 0) {
            *(vu0_q *)(m + 0x10) = *(vu0_q *)&D_L05_001EA6E0[0];
            func_L01_004515D8(m + 0xC0, &D_L05_001EA6E0[2], 0);
        }
    }
    f = *(s32 *)(v + 0xA8);
    *(vu0_q *)(v + 0x310) = *(vu0_q *)(m + 0x10);
    *(f32 *)(v + 0x190) = 0.5f;
    v[0x170] = 0xB;
    v[0x1A8] = 3;
    v[0x1D7] = 1;
    *(f32 *)(v + 0x194) = 0.5f;
    *(f32 *)(v + 0x19C) = 0.15f;
    v[0x1DB] = 0xFF;
    *(s32 *)(v + 0xA8) = f | 1;
    *(f32 *)(v + 0x70) = 0.45f;
    *(f32 *)(v + 0x74) = 0.1f;
    v[0x1D8] = 0;
    v[0x1D9] = 0;
    v[0x1DA] = 0;
    *(f32 *)(v + 0x78) = 1.0f;
    *(f32 *)(v + 0x7C) = 60.0f;
    *(f32 *)(v + 0x80) = 2.0943952f;
    *(f32 *)(v + 0xA0) = 0.34906584f;
    *(s32 *)(v + 0x9C) = 0;
    if (*(s32 *)(v + 0x2F4) == 0) {
        *(s32 *)(v + 0xA8) = f | 5;
    }
    func_L01_0045BD78(m, 0.0064000003f, 0.100000009f, 0.0100530973f, 0.251327425f);
    v[0x58] = 0x14;
    v[0x5A] = 0xE;
    if (*(s16 *)(v + 0x34) == 0) {
        *(f32 *)(v + 0x30) = 1.0f;
        *(s16 *)(v + 0x34) = 1;
    }
    v[0x39] = 1;
    v[0x3E] = 1;
    *(f32 *)(v + 0x40) = 0.75f;
    func_L01_004450F0(m, 3, 0);
    if (m[0x43] != 3) {
        func_003C3A10(m, 3, 0, 0);
    }
    if (*(s32 *)(v + 0x2F0) != -1) {
        func_L01_004450F0(m, 1, -1);
    }
    return 0;
}
/* localdecomp:end func_L05_003C28C8 */

/* localdecomp:start func_L05_003C2B50 */
extern u8 D_001A30B0[];
extern s32 D_001D545C;
extern s32 D_L05_001D67BC;
extern u8 D_L05_001D66B0[8];
__asm__(".extern D_L05_001D66B0, 16");
extern void func_L01_00459C50(s32);
extern void func_003A4F28(s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *m, s32 a, void *b, f32 x1, f32 x2, f32 x3, f32 x4, s32 e,
                              f32 x5, f32 x6, s32 f, s32 g, s32 c, s32 d, f32 x0, f32 one,
                              s32 h, s32 k);
extern void func_L01_004443E8(void *, s32, s32);

void func_L05_003C2B50(u8 *a0) {
    u8 *v;
    s32 i;
    u8 *e;

    v = *(u8 **)(a0 + 0x68);
    if (D_001D545C == 0x11 && (v[0x60] != 0 || v[0x47] == 0x87)) {
        D_L05_001D67BC = D_L05_001D67BC + 1;
        if (D_L05_001D67BC >= 0x28) {
            func_L01_00459C50(0x13);
        }
    }
    i = *(s32 *)(v + 0x320);
    if (i != -1) {
        e = D_001A30B0 + (i << 7);
        if (*(u8 **)(e + 0xDC) == a0 && e[0xD0] != 0) {
            func_003A4F28(i);
        }
    }
    *(s32 *)(v + 0x320) = -1;
    func_003A52A0(5, 0, a0);
    func_L01_00451FE0(a0, 0x7FFF, D_L05_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
    func_L01_004443E8(a0, 0, 3);
}
/* localdecomp:end func_L05_003C2B50 */

/* localdecomp:start func_L05_003C2C90 */
typedef int u128_t __attribute__((mode(TI)));
extern void func_0038D308(u8 *a0, u8 *a1);
extern void func_L01_004450F0(u8 *a0, s32 a1, s32 a2);
void func_L05_003C2C90(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 104);
    *(s16 *)(p + 408) = 0;
    *(f32 *)(p + 48) = *(s16 *)(p + 52);
    a0[127] = 0;
    *(u128_t *)(a0 + 16) = *(u128_t *)(p + 832);
    *(u128_t *)(a0 + 240) = *(u128_t *)(p + 816);
    func_0038D308(a0 + 192, p + 816);
    *(s32 *)(a0 + 152) = *(s32 *)(*(u8 **)(a0 + 36) + 16);
    func_L01_004450F0(a0, 0, 0);
}
/* localdecomp:end func_L05_003C2C90 */

/* localdecomp:start func_L05_003C2D08 */
extern s32 func_0038CAD0(void *);
extern s32 func_0038CB00(void *);
extern void func_L01_00404808(void *, void *);
extern void func_L05_003C24F0(void);
extern void func_L01_00451DF8(u8 *, void *, s32, s32, f32);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_003C4C18(void *, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern u8 *func_L05_00468EA8(void *, void *, void *, s32, s32);
extern vu0_v4 D_L05_001E2700;
__asm__(".extern D_L05_001DEB08, 4");
extern s32 D_L05_001DEB08;
__asm__(".extern D_L05_001DEB0C, 4");
extern f32 D_L05_001DEB0C;
__asm__(".extern D_L05_001DEB18, 4");
extern f32 D_L05_001DEB18;
__asm__(".extern D_L05_001DEB1C, 4");
extern f32 D_L05_001DEB1C;
__asm__(".extern D_L05_001DEB50, 8");
extern u8 D_L05_001DEB50[8];

void func_L05_003C2D08(u8 *a0) {
    u8 *v;
    s32 i;
    vu0_v4 p;
    vu0_v4 r;
    vu0_v4 d;
    vu0_v4 m[4];

    v = *(u8 **)(a0 + 0x68);
    func_0038CAD0(v + 0x2D0);
    func_0038CB00(v + 0x2D4);
    if (*(u16 *)(a0 + 0x96) < 0xFFFF) {
        *(u16 *)(a0 + 0x96) += 1;
    }
    func_L01_00404808(func_L05_003C24F0, a0);
    func_L01_00451DF8(a0, v + 0x240, 2, 1, 2.5f);
    if (a0[0x31] != 0 && func_L01_0040E548(&D_L05_001E2700, a0 + 0x10) < 1024.0f) {
        func_L01_004472C0(a0);
        a0[0x6F] = 0x1E;
    }
    *(vu0_q *)&p = *(vu0_q *)(a0 + 0x10);
    func_0038CF68(&d, a0 + 0xE0, 0.6f);
    vec_add_ab(&p, &p, &d);
    for (i = 0; i < D_L05_001DEB08; i++) {
        func_003C4C18(&p, D_L05_001DEB0C);
        func_0038CF68(&r, a0 + 0xE0, func_003824E0(D_L05_001DEB18, D_L05_001DEB1C) * 0.020000001f);
        func_L05_00468EA8(&p, &r, D_L05_001DEB50, func_00382468(2), func_00382468(3) - 1);
    }
}
/* localdecomp:end func_L05_003C2D08 */
