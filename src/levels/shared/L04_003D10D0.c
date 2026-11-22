#include "common.h"

/* localdecomp:start func_L04_003D10D0 */
void func_L04_003D10D0(u8 *a0, u8 *a1) {
    u8 *s = *(u8 **)(a1 + 104);
    u8 *d = *(u8 **)(a0 + 104);
    *(s32 *)(d + 128) = *(s32 *)(s + 0);
    if (*(f32 *)(s + 4) > 0.0f) {
        *(f32 *)(d + 132) = *(f32 *)(s + 4);
    }
    *(s32 *)(d + 136) = *(s32 *)(s + 8);
    if (*(f32 *)(s + 12) > 0.0f) {
        *(f32 *)(d + 132) = *(f32 *)(s + 12);
    }
    *(s32 *)(d + 144) = *(s32 *)(s + 88);
    *(s32 *)(d + 152) = *(s32 *)(s + 32);
}
/* localdecomp:end func_L04_003D10D0 */

/* localdecomp:start func_L04_003D1128 */
typedef void (*Fn_003CF2A0)(u8 *);

extern u8 D_001A30B0[];
extern void func_003C2880(s32);
extern void func_003A4F28(s32);
extern Fn_003CF2A0 *func_L01_0043B548(s32, s32);

void func_L04_003D1128(u8 *self) {
    u8 *v = *(u8 **)(self + 104);
    s32 idx;
    u8 *e;

    if (*(s32 *)(v + 156) != 0) {
        func_003C2880(*(s32 *)(v + 156));
        *(s32 *)(v + 156) = 0;
    }
    if (*(s32 *)(v + 160) != 0) {
        func_003C2880(*(s32 *)(v + 160));
        *(s32 *)(v + 160) = 0;
    }
    idx = *(s32 *)(v + 164);
    if (idx != -1) {
        e = D_001A30B0 + (idx << 7);
        if (*(u8 **)(e + 220) == self && e[208] != 0) {
            func_003A4F28(idx);
        }
    }
    *(s32 *)(v + 164) = -1;
    (*func_L01_0043B548(6625, 108))(self);
}
/* localdecomp:end func_L04_003D1128 */

/* localdecomp:start func_L04_003D11E0 */
int func_L04_003D11E0(u8 *a) {
    int r = 3;
    if (a[32] != 2) {
        r = 0;
    }
    return r;
}
/* localdecomp:end func_L04_003D11E0 */

/* localdecomp:start func_L04_003D11F8 */
#include "vu0.h"

extern f32 func_00382538(void);
extern void func_0038CE20(void *, void *, f32);
extern void func_003C4C18(void *, f32);
extern void func_L01_00409658(void *, f32, f32, f32, s32, s32, s32, s32, s32, s32);
extern void func_003D9508(void *, s32, s32, s32, f32, f32, f32);

void func_L04_003D11F8(vu0_v4 *a, vu0_v4 *b) {
    vu0_v4 cur;
    vu0_v4 step;
    f32 pts[10][4] __attribute__((aligned(16)));
    s32 i;

    vec_sub_ab(&step, b, a);
    func_0038CE20(&step, &step, 0.111111112f);
    cur = *a;
    for (i = 0; i < 10; i++) {
        *(vu0_v4 *)pts[i] = cur;
        if (i != 0 && i != 9) {
            func_003C4C18(pts[i], 0.3f);
        }
        pts[i][3] = 0.075f;
        vec_add_ab(&cur, &cur, &step);
    }
    func_L01_00409658(pts, 0.075f, 4.0f, 0.0f, 0x17, 0x17, 0xB, -1, 0x80802020, 0);
    func_003D9508(a, 0x31, -1, 1, 0.5f, 0.3f, func_00382538());
    func_003D9508(a, 0x31, 0x80802020, 1, 1.2f, 0.3f, func_00382538());
    func_003D9508(b, 0x31, -1, 1, 0.5f, 0.3f, func_00382538());
    func_003D9508(b, 0x31, 0x80802020, 1, 1.2f, 0.3f, func_00382538());
}
/* localdecomp:end func_L04_003D11F8 */

/* localdecomp:start func_L04_003D1420 */
#include "vu0.h"

typedef struct O_3D1420_003D1420 O_3D1420_003D1420;
typedef struct {
    u8 pad0[0x90];
    s32 i90;
    O_3D1420_003D1420 *p94;
} M_3D1420_003D1420;
struct O_3D1420_003D1420 {
    u8 pad0[0x10];
    vu0_q q10;
    u8 pad20[0x68 - 0x20];
    M_3D1420_003D1420 *p68;
    u8 pad6C[0x90 - 0x6C];
    s32 i90;
    u8 pad94[0xD0 - 0x94];
    vu0_q qD0;
    vu0_q qE0;
};
extern f32 D_L04_001DEB30_003D1420; __asm__(".extern D_L04_001DEB30_003D1420, 4");
extern f32 D_L04_001DEB34_003D1420; __asm__(".extern D_L04_001DEB34_003D1420, 4");
extern void func_0038CE20(void *, void *, f32);
extern void func_L04_003D11F8_003D1420(vu0_q *, vu0_q *);

void func_L04_003D1420(O_3D1420_003D1420 *o) {
    vu0_q a[2];
    vu0_q t;
    vu0_q u;
    vu0_q qa, qb;
    M_3D1420_003D1420 *m;
    O_3D1420_003D1420 *other;

    m = o->p68;
    other = m->p94;
    if (m->i90 < 0) {
        a[0] = o->q10;
    } else {
        func_0038CE20(&a[0], &o->qE0, D_L04_001DEB30_003D1420);
        func_0038CE20(&t, &o->qD0, D_L04_001DEB34_003D1420);
        __asm__("lqc2 %0, %4\n"
                "\tlqc2 %1, %5\n"
                "\tvadd.xyz %1, %1, %0\n"
                "\tlqc2 %0, %6\n"
                "\tsqc2 %0, %3\n"
                "\tsqc2 %1, %2"
                : "=&j"(qa), "=&j"(qb), "=m"(a[0]), "=m"(u)
                : "m"(a[0]), "m"(t), "m"(o->q10));
        vec_add_ab(&a[0], &a[0], &u);
    }
    if (other->i90 < 0) {
        a[1] = m->p94->q10;
    } else {
        func_0038CE20(&a[1], &m->p94->qE0, D_L04_001DEB30_003D1420);
        func_0038CE20(&t, &m->p94->qD0, -D_L04_001DEB34_003D1420);
        __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(a[1]));
        __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(t));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(qa) : "j"(qa), "j"(qb));
        __asm__("sqc2 %1, %0" : "=m"(a[1]) : "j"(qa));
        vec_add_ab(&a[1], &a[1], &m->p94->q10);
    }
    func_L04_003D11F8_003D1420(&a[0], &a[1]);
}
/* localdecomp:end func_L04_003D1420 */

/* localdecomp:start func_L04_003D1530 */
__asm__(".extern D_L04_001DEBC0, 4");
extern s32 D_L04_001DEBC0;
s32 *func_L04_003D1530(s32 a0, s32 a1, s32 *a2) {
    if (a1 == 1) {
        *a2 = 28;
        return &D_L04_001DEBC0;
    }
    return 0;
}
/* localdecomp:end func_L04_003D1530 */

/* localdecomp:start func_L04_003D1550 */
#include "vu0.h"

typedef struct {
    u8 p0[0x80];
    vu0_v4 v80;
    vu0_v4 v90;
    u8 pA0[0x30];
    vu0_v4 vD0;
    u8 pE0[0x10];
    u8 aF0[0x26C];
    u8 *p35C;
    u8 p360[0x1680];
    u8 *p19E0;
    u8 p19E4[0x87C];
    f32 f2260;
    f32 f2264;
    u8 p2268[0x358];
    u8 *p25C0;
    s32 i25C4;
    s32 i25C8;
    s32 i25CC;
    u8 p25D0[0x15];
    u8 b25E5;
} G_003D1550;
typedef struct {
    u8 p0[0x44];
    u8 *p44;
} T_003D1550;
typedef struct {
    u8 p0[0x14];
    s32 i14;
    u8 p18[0xC];
    s32 i24;
    u8 p28[0xC];
    s32 i34;
    u8 p38[0x2C];
    s32 i64;
    u8 p68[0x3C];
    u8 bA4;
} C_003D1550;
typedef struct {
    u8 p0[0x20];
    f32 f20;
    u8 p24[4];
    s32 i28;
    s32 i2C;
    f32 f30;
    u8 p34[4];
    s32 i38;
} P_003D1550;
extern G_003D1550 D_001A4BE0; __asm__(".extern D_001A4BE0, 16");
extern T_003D1550 D_001A30B0_003D1550; __asm__(".extern D_001A30B0_003D1550, 16");
extern C_003D1550 D_00143950; __asm__(".extern D_00143950, 16");
extern u8 *D_001D52FC;
extern s32 D_L04_002D1F30[];
typedef struct {
    u8 p0[0x68];
    u8 *p68;
    u8 p6C[0x94];
} M_003D1550;
extern M_003D1550 *D_L04_001DFD9C;
extern P_003D1550 D_L04_001E2840; __asm__(".extern D_L04_001E2840, 16");
extern u8 D_L04_001F06C0[];
extern f32 D_L04_001DEB60; __asm__(".extern D_L04_001DEB60, 4");
extern f32 D_L04_001DEB64; __asm__(".extern D_L04_001DEB64, 4");
extern f32 D_L04_001DEB68; __asm__(".extern D_L04_001DEB68, 4");
extern f32 D_L04_001DEB70[2]; __asm__(".extern D_L04_001DEB70, 4");
extern f32 D_L04_001DEB80; __asm__(".extern D_L04_001DEB80, 4");
extern f32 D_L04_001DEB84; __asm__(".extern D_L04_001DEB84, 4");
extern f32 D_L04_001DEB88; __asm__(".extern D_L04_001DEB88, 4");
extern f32 D_L04_001DEB8C; __asm__(".extern D_L04_001DEB8C, 4");
extern f32 D_L04_001DEB90; __asm__(".extern D_L04_001DEB90, 4");
extern f32 D_L04_001DEB94; __asm__(".extern D_L04_001DEB94, 4");
extern f32 D_L04_001DEB98; __asm__(".extern D_L04_001DEB98, 4");
extern f32 D_L04_001DEB9C; __asm__(".extern D_L04_001DEB9C, 4");
extern f32 D_L04_001DEBA0; __asm__(".extern D_L04_001DEBA0, 4");
extern f32 D_L04_001DEBAC; __asm__(".extern D_L04_001DEBAC, 4");
extern f32 D_L04_001DEBB0; __asm__(".extern D_L04_001DEBB0, 4");
extern s32 D_L04_001DEBB8; __asm__(".extern D_L04_001DEBB8, 4");

extern void func_L04_003D3018(u8 *, u8 *);
extern s32 func_L04_003D3228(u8 *, u8 *);
extern void func_L04_003D3B90(void);
extern void func_L04_003D3EE0(void);
extern void func_L04_003D3F00(u8 *, u8 *);
extern void func_L04_003D3F68(u8 *, u8 *, void *);
extern void func_L04_003553F0(u8 *, f32, void *, void *, s32, u32, s32, s32);
extern void func_L04_003FDF80(s32);
extern void func_L04_00477498(void *, void *, u32, s32, f32);
extern s32 func_L04_0050CB28(s32, s32);
extern void func_L01_003EB350(s32, void *);
extern void func_L01_003EB3C0(s32, void *);
extern void func_L01_003EB438(s32, void *, void *, s32, s32, s32);
extern void func_L01_003EB5E0(s32, s32);
extern void func_L01_003F6F20(s32, void *, u32, void *, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);
extern void func_L01_0040E408(void *, void *, f32);
extern s32 func_L01_00424CB0(void *, f32, f32, f32, f32, f32);
extern void func_L01_00424D88(s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_00448890(void *, void *, s32, f32, f32, f32, f32);
extern u8 *func_L01_00449020(void *);
extern s32 func_L01_0044C108(void *);
extern s32 func_L01_0044E1B8(void *, f32);
extern void func_L01_0044E850(void *, void *, s32, f32, f32);
extern s32 func_L01_004561B8(void *);
extern void func_L01_00456230(void *, s32);
extern s32 func_0038CAD0(void *);
extern void func_0038CBA0(void *, s32);
extern void func_0038CDF8(void *, void *, void *, f32);
extern f32 func_0038CEA8(void *);
extern f32 func_0038CED8(void *);
extern f32 func_0038CF00(void *, void *);
extern f32 func_0038CF38(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038D000(void *, void *, void *);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_003C2F58(void *, s32, void *);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_003C7C38(void *);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern void func_00382760(void *, f32, f32, f32);
extern void func_003A4F28(s32);
extern s32 func_003A52A0(s32, s32, void *);

void func_L04_003D1550(u8 *self) {
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 c;
    vu0_v4 d;
    vu0_v4 e;
    vu0_v4 f;
    vu0_v4 g;
    u8 *v;
    u8 *h;
    u8 *q;
    u8 *ent;
    s32 i;
    s32 n;
    s32 idx;
    u32 fl;
    u32 fl2;
    u8 k2;
    s32 idx2;
    f32 m1, m2;
    u8 k;
    f32 x;
    f32 y;
    f32 r1, r2, r3, r4, r5, r6, r7;
    f32 y1, y2, y3;
    f32 dx, dy, dz;

    v = *(u8 **)(self + 0x68);
    if (self[0x20] == 0) {
        func_L04_003D3018(self, v);
    }
    if (func_L01_0044C108(self + 0x10) == 0) {
        return;
    }
    if (func_L04_003D3228(self, v) == 0) {
        return;
    }

    if (self[0x43] == 1 || self[0x43] == 2 || self[0x43] == 5 || self[0x43] == 4) {
        *(f32 *)(v + 0x88) = func_0038DAB8(*(f32 *)(v + 0x88), 0.136135697f);
        *(f32 *)(v + 0x8C) = *(f32 *)(v + 0x8C) + 0.160000011f;
    } else {
        *(f32 *)(v + 0x88) = func_0038DAB8(*(f32 *)(v + 0x88), 0.0418879054f);
        *(f32 *)(v + 0x8C) = *(f32 *)(v + 0x8C) - 0.0400000028f;
    }
    if (0.5f < *(f32 *)(v + 0x8C)) {
        *(f32 *)(v + 0x8C) = 0.5f;
    } else if (*(f32 *)(v + 0x8C) < 0.0f) {
        *(f32 *)(v + 0x8C) = 0.0f;
    }
    *(s32 *)(self + 0x78) = func_0038DBD8(0x8F505050, 0x8F808080,
                                          func_0038D0B0(*(f32 *)(v + 0x88)) * 0.5f + *(f32 *)(v + 0x8C));
    *(u16 *)(self + 0x34) &= ~4;
    func_003C2F58(self, 4, &a);
    a.z += D_L04_001DEB88;

    if (v[0x82] != 2) {
        if (func_0038CAD0(v + 0x98) && self[0xBC] == 1 && D_001A4BE0.i25CC != 0x14 &&
            D_001A4BE0.i25CC != 7 && D_001A4BE0.i25C4 != 0x39 && D_L04_002D1F30[0] == 0) {
            *(vu0_q *)&D_001A4BE0.v90 = *(vu0_q *)(self + 0xF0);
            b.x = func_0038D098(D_001A4BE0.v90.z) * D_L04_001DEB84;
            b.y = func_0038D0B0(D_001A4BE0.v90.z) * D_L04_001DEB84;
            b.z = 0.0f;
            vec_add_ba(&D_001A4BE0.v80, &a, &b);
            func_0038CBA0(D_001A4BE0.aF0, 0xA0);
            b.x = func_0038D098(D_001A4BE0.v90.z) * D_L04_001DEB8C;
            b.y = func_0038D0B0(D_001A4BE0.v90.z) * D_L04_001DEB8C;
            b.z = 0.0f;
            r1 = D_L04_001DEB90 - D_L04_001DEB88;
            vec_add_ab(&D_001A4BE0.vD0, &a, &b);
            D_001A4BE0.vD0.z += r1;
            if (((*(s32 *)(D_001D52FC + 0x1A4) & 0x10) && v[0x81] == 0) ||
                (self[0x20] == 2 && D_001A4BE0.i25C4 != 0x31)) {
                func_L01_003EB5E0(0, 0);
                func_L04_003D3EE0();
                *(s32 *)(D_001A4BE0.p25C0 + 0x98) = *(s32 *)(*(u8 **)(D_001A4BE0.p25C0 + 0x24) + 0x10);
                D_001A4BE0.b25E5 = 0;
                func_L04_0050CB28(0, 1);
                D_001A4BE0.p19E0 = 0;
                self[0xBC] = 2;
                func_L01_004450F0(self, 1, -1);
                func_L01_00456230(self, 0);
                func_003C3A10(self, 0, 0, 1);
            } else {
                if (self[0x20] != 2) {
                    *(s32 *)(v + 0xAC) = 2;
                    func_L01_003EB438(0, D_001A4BE0.p25C0 + 0x10, D_001A4BE0.p25C0 + 0xF0, 0, 0, 0);
                    if (self[0x43] != 3) {
                        func_003C3A10(self, 3, 0, 4);
                    }
                }
                func_L01_004450F0(self, 2, -1);
                func_L01_00456230(self, 1);
                *(f32 *)(self + 0x48) = 2.0f;
                if (v[0x81] != 0) {
                    v[0x82] = 1;
                }
            }
        } else if (self[0xBC] == 2) {
            if (1.20000005f < func_0038CF00(&a, D_001A4BE0.p25C0 + 0x10) ||
                D_001A4BE0.p35C != self || v[0x82] == 1) {
                self[0xBC] = 0;
                *(s32 *)(v + 0x98) = 50;
            }
        } else if (D_001A4BE0.i25CC != 0x14 && D_001A4BE0.i25CC != 7 &&
                   D_001A4BE0.i25C4 != 0x39) {
            if ((v[0x82] == 1 && func_0038CF00(&a, D_001A4BE0.p25C0 + 0x10) < 4.0f) ||
                (D_001A4BE0.p35C == self &&
                 func_0038CF00(&a, D_001A4BE0.p25C0 + 0x10) < 1.20000005f)) {
                if (*(s32 *)(v + 0x98) == 0 && D_L04_002D1F30[0] == 0) {
                    if (v[0x82] == 1) {
                        *(f32 *)(self + 0x18) = *(f32 *)(v + 0xB8) - D_L04_001DEB80;
                    }
                    self[0xBC] = 1;
                    func_L04_0050CB28(0x31, 1);
                    D_001A4BE0.p19E0 = self;
                    *(s32 *)(D_001A4BE0.p25C0 + 0x98) = 0;
                    D_001A4BE0.b25E5 = 1;
                    func_L04_003D3B90();
                }
            }
        }
    }

    switch (self[0x20]) {
    case 1:
        if (v[0x82] != 2 && func_0038CF38(self + 0x10, &D_001A4BE0.v80) < 4.0f) {
            if (v[0x82] == 1) {
                *(f32 *)(self + 0x18) = *(f32 *)(v + 0xB8) - D_L04_001DEB80;
                *(f32 *)(v + 0xC0) = 0.0f;
            } else {
                y1 = *(f32 *)(self + 0x18);
                *(f32 *)(self + 0x18) = y1 + ((*(f32 *)(v + 0xB8) - D_L04_001DEB80) - y1) * 0.109999999f;
                if (D_001A4BE0.p35C != self) {
                    r2 = func_0038D160(D_001A4BE0.v80.x - *(f32 *)(self + 0x10),
                                      D_001A4BE0.v80.y - *(f32 *)(self + 0x14));
                    r2 = func_0038DB00(r2, *(f32 *)(self + 0xF8));
                    r2 = func_0038DAB8(r2, 3.14159274f);
                    *(f32 *)(v + 0xC0) = func_0038DAB8(*(f32 *)(v + 0xC0), r2 * 0.00999999978f) * 0.899999976f;
                    *(f32 *)(self + 0xF8) = func_0038DAB8(*(f32 *)(self + 0xF8), *(f32 *)(v + 0xC0));
                } else {
                    *(f32 *)(v + 0xC0) = 0.0f;
                }
            }
            func_0038D000(&d, D_L04_001DEB70, self + 0xC0);
            vec_add_ab(&d, &d, &a);
            if (*(s32 *)(v + 0xC8) == -1) {
                *(s32 *)(v + 0xCC) = 0;
                *(s32 *)(v + 0xC8) = func_L01_00424CB0(&d, 0.400000006f, 0.0f, 4.0f, 4.0f, 4.0f);
                func_003A52A0(2, 0, self);
                return;
            }
            dx = d.x;
            dy = d.y;
            dz = d.z;
            ent = D_L04_001F06C0 + (*(s32 *)(v + 0xC8) << 5);
            *(f32 *)(ent + 0x10) = dx;
            *(f32 *)(ent + 0x14) = dy;
            *(f32 *)(ent + 0x18) = dz;
            n = *(s32 *)(v + 0xCC) + 1;
            *(s32 *)(v + 0xCC) = n;
            if (n >= 0x29 || !(n & 4) || (n >= 0x19 && (n & 0xA) == 0xA)) {
                *(f32 *)(ent + 0x0) = 4.0f;
                *(f32 *)(ent + 0x1C) = 0.400000006f;
            } else {
                *(s32 *)(ent + 0x1C) = 0;
            }
            return;
        }
        y2 = *(f32 *)(self + 0x18);
        if (y2 < *(f32 *)(v + 0xB8)) {
            *(f32 *)(self + 0x18) = y2 + 0.0200000014f;
        } else {
            *(f32 *)(self + 0x18) = *(f32 *)(v + 0xB8);
        }
        if (D_001A4BE0.p35C == self) {
            return;
        }
        if (*(s32 *)(v + 0xC8) != -1) {
            func_003A52A0(0, 0, self);
            func_L01_00424D88(*(s32 *)(v + 0xC8));
            *(s32 *)(v + 0xC8) = -1;
        }
        return;

    case 2:
        func_L04_003D3F00(self, v);
        D_001A30B0_003D1550.p44 = self;
        y3 = *(f32 *)(self + 0x18);
        if (y3 < *(f32 *)(v + 0xB8)) {
            *(f32 *)(self + 0x18) = y3 + 0.0200000014f;
        } else {
            *(f32 *)(self + 0x18) = *(f32 *)(v + 0xB8);
        }
        k = D_00143950.bA4;
        if (D_L04_001DEBB8 != 0) {
            x = *(f32 *)(D_001D52FC + 0x108) + *(f32 *)(D_001D52FC + 0x100);
            c.x = x;
            if (1.0f < x) {
                c.x = 1.0f;
            } else if (x < -1.0f) {
                c.x = -1.0f;
            }
            {
                f32 hi = 1.0f;
                f32 lo = -1.0f;

                y = -(*(f32 *)(D_001D52FC + 0x10C) + *(f32 *)(D_001D52FC + 0x104));
                c.y = y;
                if (hi < y) {
                    c.y = hi;
                } else if (y < lo) {
                    c.y = lo;
                }
            }
        } else {
            c.x = D_001A4BE0.f2260;
            c.y = D_001A4BE0.f2264;
        }
        switch (k) {
        case 0:
            y = c.y;
            if (D_00143950.i14 == 0) {
                y = -y;
            }
            c.y = y;
            break;
        case 1:
            y = c.y;
            if (D_00143950.i24 == 0) {
                y = -y;
            }
            c.y = y;
            break;
        case 2:
            y = c.y;
            if (D_00143950.i34 == 0) {
                y = -y;
            }
            c.y = y;
            x = c.x;
            if (D_00143950.i64 != 0) {
                x = -x;
            }
            c.x = x;
            break;
        }
        r3 = func_0038CED8(&c);
        if (1.0f < r3) {
            func_L01_0040E408(&c, &c, r3);
        }
        *(f32 *)(v + 0xC0) = *(f32 *)(v + 0xC0) + D_L04_001DEB94 * 0.0174532924f * 0.000400000019f * -c.x;
        if (c.x == 0.0f) {
            *(f32 *)(v + 0xC0) = 0.0f;
        }
        if (*(f32 *)(v + 0xC0) != 0.0f) {
            u8 *e1;
            u8 *b1;
            n = *(s32 *)(v + 0xBC);
            if (n == -1 || (b1 = (u8 *)&D_001A30B0_003D1550, *(u8 **)((e1 = b1 + (n << 7)) + 0xDC) != self) ||
                e1[0xD0] == 0) {
                *(s32 *)(v + 0xBC) = func_003A52A0(3, 4, self);
            }
        } else {
            idx2 = *(s32 *)(v + 0xBC);
            if (idx2 != -1) {
                u8 *e2 = (u8 *)&D_001A30B0_003D1550 + (idx2 << 7);
                if (*(u8 **)(e2 + 0xDC) == self && e2[0xD0] != 0) {
                    func_003A4F28(idx2);
                }
            }
            *(s32 *)(v + 0xBC) = -1;
        }
        *(f32 *)(v + 0xC4) = *(f32 *)(v + 0xC4) + D_L04_001DEB98 * 0.0174532924f * 0.000400000019f * -c.y;
        if (c.y == 0.0f) {
            *(f32 *)(v + 0xC4) = 0.0f;
        }
        *(f32 *)(self + 0xF8) = func_0038DAB8(*(f32 *)(self + 0xF8), *(f32 *)(v + 0xC0));
        r4 = func_0038DAB8(*(f32 *)(v + 0xA0), *(f32 *)(v + 0xC4));
        *(f32 *)(v + 0xA0) = r4;
        if (r4 < -0.52359879f) {
            *(f32 *)(v + 0xA0) = -0.52359879f;
            *(f32 *)(v + 0xC4) = 0.0f;
        } else if (0.52359879f < r4) {
            *(f32 *)(v + 0xA0) = 0.52359879f;
            *(f32 *)(v + 0xC4) = 0.0f;
        }
        m1 = (D_L04_001DEB9C - 1.0f) * 1.20000005f + 1.0f;
        m2 = (D_L04_001DEBA0 - 1.0f) * 1.20000005f + 1.0f;
        *(f32 *)(v + 0xC0) = *(f32 *)(v + 0xC0) * m1;
        *(f32 *)(v + 0xC4) = *(f32 *)(v + 0xC4) * m2;
        *(f32 *)(v + 0x1B8) = *(f32 *)(v + 0x138) = -*(f32 *)(v + 0xA0);
        func_L01_0044E850(self, v + 0xF0, 2, 0.0432000011f, 0.432000041f);
        func_L01_0044E850(self, v + 0x170, 3, 0.0432000011f, 0.432000041f);

        k2 = D_00143950.bA4;
        fl = *(s32 *)(D_001D52FC + 0x1A0);
        if ((fl & 0x20) || ((fl & 8) && k2 != 0) ||
            ((self[0x43] == 1 || self[0x43] == 2) && !(self[0x60] & 2))) {
            fl2 = *(s32 *)(D_001D52FC + 0x1A4);
            if ((fl2 & 0x20) || ((fl2 & 8) && k2 != 0)) {
                if (*(s32 *)(v + 0xB0) == 0) {
                    func_003C3A10(self, 2, 0, 1);
                } else {
                    func_003C3A10(self, 1, 0, 1);
                }
            } else if (self[0x42] == 1) {
                if (func_L01_0044E1B8(self, 1.0f)) {
                    func_00382760(&d, 1.20000005f, *(f32 *)(self + 0xF8), *(f32 *)(v + 0xA0));
                    func_003C2F58(self, 0, &e);
                    func_L04_003553F0(self, (f32)v[0x44], &d, &e, 0x10000, 0xFFFFFFFF, 0, 0);
                    func_003A52A0(1, 0, self);
                    D_L04_001E2840.i28 = 8;
                    D_L04_001E2840.f20 = 0.0299999993f;
                    D_L04_001E2840.f30 = 0.0299999993f;
                    D_L04_001E2840.i38 = 6;
                    D_L04_001E2840.i2C = 0;
                    *(s32 *)(v + 0xB0) = 0;
                    for (i = 4; i >= 0; i--) {
                        *(vu0_q *)&g = 0;
                        g.x = func_003824E0(-1.0f, 1.0f);
                        g.y = func_003824E0(-1.0f, 1.0f);
                        g.z = func_003824E0(-1.0f, 1.0f);
                        f = g;
                        func_0038CF68(&f, &f, func_0038CEA8(&d) * 0.579999924f);
                        vec_add_ab(&f, &d, &f);
                        func_0038CF68(&f, &f, func_003824E0(0.0600000024f, 0.120000005f));
                        func_L04_00477498(&e, &f, 0x5F2F4F6F, func_00382498(4, 8), 50000.0f);
                    }
                    func_0038CF68(&d, &d, 0.0100000007f);
                    func_L04_00477498(&e, &d, 0x2F4F7F7F, func_00382498(3, 6), 500000.0f);
                } else if (self[0x60] & 2) {
                    func_003C3A10(self, 2, 0, 1);
                }
            } else if (self[0x42] == 2) {
                if (func_L01_0044E1B8(self, 1.0f)) {
                    func_00382760(&d, 1.20000005f, *(f32 *)(self + 0xF8), *(f32 *)(v + 0xA0));
                    func_003C2F58(self, 1, &e);
                    func_L04_003553F0(self, (f32)v[0x44], &d, &e, 0x10000, 0xFFFFFFFF, 0, 0);
                    func_003A52A0(1, 0, self);
                    D_L04_001E2840.i28 = 8;
                    D_L04_001E2840.f20 = 0.0299999993f;
                    D_L04_001E2840.f30 = 0.0299999993f;
                    D_L04_001E2840.i38 = 6;
                    D_L04_001E2840.i2C = 0;
                    *(s32 *)(v + 0xB0) = 1;
                    for (i = 4; i >= 0; i--) {
                        *(vu0_q *)&g = 0;
                        g.x = func_003824E0(-1.0f, 1.0f);
                        g.y = func_003824E0(-1.0f, 1.0f);
                        g.z = func_003824E0(-1.0f, 1.0f);
                        f = g;
                        func_0038CF68(&f, &f, func_0038CEA8(&d) * 0.579999924f);
                        vec_add_ab(&f, &d, &f);
                        func_0038CF68(&f, &f, func_003824E0(0.0600000024f, 0.120000005f));
                        func_L04_00477498(&e, &f, 0x5F2F4F6F, func_00382498(4, 8), 50000.0f);
                    }
                    func_0038CF68(&d, &d, 0.0100000007f);
                    func_L04_00477498(&e, &d, 0x2F4F7F7F, func_00382498(3, 6), 500000.0f);
                } else if (self[0x60] & 2) {
                    func_003C3A10(self, 1, 0, 1);
                }
            }
        } else if (self[0x43] != 3 && (self[0x60] & 2)) {
            func_003C3A10(self, 3, 0, 1);
        }

        if (func_0038CAD0(v + 0xAC)) {
            func_003C7C38(self);
            *(u16 *)(self + 0x34) |= 4;
            func_L04_003FDF80(0);
            r5 = D_L04_001DEB60;
            if (*(f32 *)(v + 0xA0) < 0.0f) {
                r5 = r5 + *(f32 *)(v + 0xA0) * D_L04_001DEB68;
            }
            func_003C2F58(self, 5, &c);
            func_00382760(&d, r5, *(f32 *)(self + 0xF8), *(f32 *)(v + 0xA0));
            d.z += D_L04_001DEB64;
            vec_add_ab(&e, &c, &d);
            func_L01_003EB350(0, &e);
            f.x = 0.0f;
            f.y = -*(f32 *)(v + 0xA0);
            f.z = *(f32 *)(self + 0xF8);
            func_L01_003EB3C0(0, &f);
        }
        func_L01_003F6F20(0, self, 0xFF0F0FFF, 0, 0xD, -1, 4, 1.0f, 0.0f, 90.0f, 0.5f, 0.5f, 40.0f, 40.0f);
        return;

    case 3:
        if (func_L01_004561B8(self)) {
            *(s32 *)(v + 0xE0) = 0;
            *(s32 *)(v + 0x94) = 0;
        }
        if (*(u8 **)(v + 0xD4) != 0) {
            if ((*(u8 **)(v + 0xD4))[0x20] == 0xFE) {
                func_L01_004450F0(self, 5, -1);
                *(u8 **)(v + 0xD4) = 0;
                return;
            }
            if ((*(u8 **)(v + 0xD4))[0x20] == 0xFD) {
                func_L01_004450F0(self, 5, -1);
                *(u8 **)(v + 0xD4) = 0;
                return;
            }
            func_L04_003D3F68(self, v, &a);
            idx = *(s32 *)(*(u8 **)(*(u8 **)(v + 0xD4) + 0x68) + 0x50);
            if (idx == -1) {
                return;
            }
            q = func_L01_00449020(&D_L04_001DFD9C[idx]);
            if (q == 0) {
                return;
            }
            if (*(s16 *)(q + 0x1C) == 0) {
                if (func_0038CAD0(v + 0xE0)) {
                    *(f32 *)(v + 0xDC) = func_003824E0(-0.52359879f, 0.52359879f);
                    *(f32 *)(v + 0xD8) = func_00382538();
                    *(s32 *)(v + 0xE0) = func_00382498(0x4B, 0x96);
                }
                func_L01_00448890(self + 0xF8, v + 0xC0, 0, *(f32 *)(v + 0xD8),
                                  D_L04_001DEB94 * 0.5f * 0.0174532924f * 0.000400000019f,
                                  D_L04_001DEB94 * 0.5f * 0.0174532924f * 0.000400000019f,
                                  D_L04_001DEBAC * 0.5f * 0.0174532924f * 0.0200000014f);
                func_L01_00448890(v + 0xA0, v + 0xC4, 0, *(f32 *)(v + 0xDC),
                                  D_L04_001DEB98 * 0.5f * 0.0174532924f * 0.000400000019f,
                                  D_L04_001DEB98 * 0.5f * 0.0174532924f * 0.000400000019f,
                                  D_L04_001DEBB0 * 0.5f * 0.0174532924f * 0.0200000014f);
                if ((u32)(self[0x43] - 4) < 2 && (self[0x60] & 2)) {
                    func_003C3A10(self, 0, 0, 5);
                }
            } else {
                if (func_0038CAD0(v + 0xE0)) {
                    func_003C2F58(self, 0, &d);
                    func_003C2F58(self, 1, &e);
                    func_0038CDF8(&f, &d, &e, 0.5f);
                    vec_sub_ba(&g, q, &f);
                    r6 = func_0038D160(g.x, g.y);
                    *(f32 *)(v + 0xD8) = func_0038DAB8(r6, func_003824E0(-0.0872664601f, 0.0872664601f));
                    r7 = func_0038D160(func_0038CED8(&g), g.z);
                    *(f32 *)(v + 0xDC) = func_0038DAB8(r7, func_003824E0(-0.0872664601f, 0.0872664601f));
                    *(s32 *)(v + 0xE0) = func_00382498(0x19, 0x32);
                }
                func_L01_00448890(self + 0xF8, v + 0xC0, 0, *(f32 *)(v + 0xD8),
                                  D_L04_001DEB94 * 0.5f * 0.0174532924f * 0.000400000019f,
                                  D_L04_001DEB94 * 0.5f * 0.0174532924f * 0.000400000019f,
                                  D_L04_001DEBAC * 0.699999988f * 0.0174532924f * 0.0200000014f);
                func_L01_00448890(v + 0xA0, v + 0xC4, 0, *(f32 *)(v + 0xDC),
                                  D_L04_001DEB98 * 0.5f * 0.0174532924f * 0.000400000019f,
                                  D_L04_001DEB98 * 0.5f * 0.0174532924f * 0.000400000019f,
                                  D_L04_001DEBB0 * 0.699999988f * 0.0174532924f * 0.0200000014f);
                if ((u32)(self[0x43] - 4) >= 2) {
                    if (*(s32 *)(v + 0xB0) == 0) {
                        func_003C3A10(self, 4, 0, 1);
                    } else {
                        func_003C3A10(self, 5, 0, 1);
                    }
                }
            }
            *(f32 *)(v + 0x1B8) = *(f32 *)(v + 0x138) = -*(f32 *)(v + 0xA0);
            func_L01_0044E850(self, v + 0xF0, 2, 0.0432000011f, 0.432000041f);
            func_L01_0044E850(self, v + 0x170, 3, 0.0432000011f, 0.432000041f);
            if (self[0x43] == 5) {
                if (func_L01_0044E1B8(self, 1.0f)) {
                    func_00382760(&d, 1.20000005f, *(f32 *)(self + 0xF8), *(f32 *)(v + 0xA0));
                    func_003C2F58(self, 0, &e);
                    func_L04_003553F0(self, (f32)v[0x44] * 0.100000001f, &d, &e, 0x10000, 0xFFFFFFFF, 0, 0);
                    func_003A52A0(1, 0, self);
                    *(s32 *)(v + 0xB0) = 0;
                    for (i = 4; i >= 0; i--) {
                        *(vu0_q *)&g = 0;
                        g.x = func_003824E0(-1.0f, 1.0f);
                        g.y = func_003824E0(-1.0f, 1.0f);
                        g.z = func_003824E0(-1.0f, 1.0f);
                        f = g;
                        func_0038CF68(&f, &f, func_0038CEA8(&d) * 0.579999924f);
                        vec_add_ab(&f, &d, &f);
                        func_0038CF68(&f, &f, func_003824E0(0.0600000024f, 0.120000005f));
                        func_L04_00477498(&e, &f, 0x5F2F4F6F, func_00382498(4, 8), 50000.0f);
                    }
                    func_0038CF68(&d, &d, 0.0100000007f);
                    func_L04_00477498(&e, &d, 0x2F4F7F7F, func_00382498(3, 6), 500000.0f);
                } else if (self[0x60] & 2) {
                    func_003C3A10(self, 4, 0, 1);
                }
            } else if (self[0x43] == 4) {
                if (func_L01_0044E1B8(self, 1.0f)) {
                    func_00382760(&d, 1.20000005f, *(f32 *)(self + 0xF8), *(f32 *)(v + 0xA0));
                    func_003C2F58(self, 1, &e);
                    func_L04_003553F0(self, (f32)v[0x44] * 0.100000001f, &d, &e, 0x10000, 0xFFFFFFFF, 0, 0);
                    func_003A52A0(1, 0, self);
                    *(s32 *)(v + 0xB0) = 1;
                    for (i = 4; i >= 0; i--) {
                        *(vu0_q *)&g = 0;
                        g.x = func_003824E0(-1.0f, 1.0f);
                        g.y = func_003824E0(-1.0f, 1.0f);
                        g.z = func_003824E0(-1.0f, 1.0f);
                        f = g;
                        func_0038CF68(&f, &f, func_0038CEA8(&d) * 0.579999924f);
                        vec_add_ab(&f, &d, &f);
                        func_0038CF68(&f, &f, func_003824E0(0.0600000024f, 0.120000005f));
                        func_L04_00477498(&e, &f, 0x5F2F4F6F, func_00382498(4, 8), 50000.0f);
                    }
                    func_0038CF68(&d, &d, 0.0100000007f);
                    func_L04_00477498(&e, &d, 0x2F4F7F7F, func_00382498(3, 6), 500000.0f);
                } else if (self[0x60] & 2) {
                    func_003C3A10(self, 5, 0, 1);
                }
            }
        } else {
            if ((u32)(self[0x43] - 4) < 2 && (self[0x60] & 2)) {
                func_003C3A10(self, 0, 0, 5);
            }
            h = *(u8 **)(D_L04_001DFD9C[*(s32 *)(v + 0xD0)].p68 + 0x11C);
            if (h != 0) {
                *(u8 **)(v + 0xD4) = h;
                func_L04_003D3F68(self, v, &a);
            }
        }
        return;
    }
}
/* localdecomp:end func_L04_003D1550 */
