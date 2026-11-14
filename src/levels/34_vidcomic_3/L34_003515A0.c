#include "common.h"

/* localdecomp:start func_L34_003515A0 */
s32 func_003C24B0(s32, s32);
void func_L01_00456160(s32, s32);
void func_003C7C38(s32);
void func_L01_004450F0(s32, s32, s32);

s32 func_L34_003515A0(s32 arg0, s32 arg1) {
    u8 *p = (u8 *)func_003C24B0(0x16F4, 0x80);
    u8 *st;

    if (p != 0) {
        func_L01_00456160((s32)p, arg0);
        *(s32 *)(p + 0xF4) = 0;
        func_003C7C38((s32)p);
        st = *(u8 **)(p + 0x68);
        *(s32 *)(st + 0x0) = 0x14D;
        *(s32 *)(st + 0x10) = -1;
        *(s32 *)(st + 0x14) = 0;
        if (arg1 != 0) {
            *(f32 *)(p + 0x2C) = *(f32 *)(p + 0x2C) * 0.4f;
            func_L01_004450F0((s32)p, 2, -1);
        }
    }
    return (s32)p;
}
/* localdecomp:end func_L34_003515A0 */

/* localdecomp:start func_L34_00351648 */
typedef struct {
    f32 x;
    f32 y;
    u8 pad8[8];
} E_00351648;

typedef struct {
    s32 count;
    u8 pad4[0xC];
    E_00351648 e[1];
} T_00351648;

extern u8 D_001A30B0[];
extern u8 D_001A4BE0[];
extern T_00351648 *D_L34_0021D840[];
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L34_00351B58(u8 *);
extern void func_L34_00352018(u8 *);
extern void func_L34_00351C68(u8 *);
extern void func_L34_00351D48(u8 *);
extern void func_L01_00448890(void *, void *, s32, f32, f32, f32, f32);
extern void func_003C41A0(f32 *, void *, f32, f32, f32, f32);
extern s32 func_0038CAD0(void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern void func_003C3A10(void *, s32, s32, s32);
extern s32 func_00382498(s32, s32);
extern f32 fabsf(f32);

void func_L34_00351648(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    s32 idx;
    u8 c;
    T_00351648 *t;
    u8 *e;

    idx = *(s32 *)(p + 0x18C);
    if (idx == -1 || (e = D_001A30B0 + (idx << 7), *(u8 **)(e + 0xDC) != a0) || e[0xD0] == 0) {
        *(s32 *)(p + 0x18C) = func_003A52A0(0, 4, a0);
    }
    func_L34_00351B58(a0);
    switch (a0[0x20]) {
    case 0:
        func_L34_00352018(a0);
        func_L01_004450F0((s32)a0, 3, -1);
        break;
    case 1:
        *(f32 *)(p + 0x64) = 0.2617994f;
        func_L01_00448890(a0 + 0xF8, p + 0x168, 0, -1.5707964f, 0.0069813174f, 0.0034906587f, 0.17453294f);
        func_003C41A0((f32 *)(a0 + 0x18), p + 0x170, *(f32 *)(p + 0x16C), 0.006f, 0.0028000001f, 0.14000002f);
        func_L34_00351C68(a0);
        if (fabsf(*(f32 *)(a0 + 0x18) - *(f32 *)(p + 0x16C)) < 2.5f) {
            func_L01_004450F0((s32)a0, 2, -1);
        }
        break;
    case 2: {
        u8 *g;

        *(f32 *)(p + 0x64) = 0.7853982f;
        func_L01_00448890(a0 + 0xF8, p + 0x168, 0, -1.5707964f, 0.0069813174f, 0.0034906587f, 0.17453294f);
        func_003C41A0((f32 *)(a0 + 0x18), p + 0x170, *(f32 *)(p + 0x16C), 0.006f, 0.0028000001f, 0.10000001f);
        g = D_001A4BE0;
        func_003C41A0((f32 *)(a0 + 0x14), p + 0x174, *(f32 *)(g + 0x84), 0.0028000001f, 0.002f, 0.10000001f);
        func_L34_00351C68(a0);
        if (fabsf(*(f32 *)(a0 + 0x14) - *(f32 *)(g + 0x84)) < 1.5f) {
            *(f32 *)(p + 0x154) = *(f32 *)(a0 + 0x18);
            *(s32 *)(p + 0x14C) = 0;
            func_L01_004450F0((s32)a0, 3, -1);
        }
        break;
    }
    case 3: {
        u8 *g = D_001A4BE0;

        func_003C41A0((f32 *)(a0 + 0x14), p + 0x174, *(f32 *)(g + 0x84), 0.0028000001f, 0.002f, 0.10000001f);
        if (*(s32 *)(p + 0x17C) == 0 && func_0038CAD0(p + 0x188) != 0) {
            if (func_0038DBA0(*(f32 *)(a0 + 0xF8),
                              func_0038D160(*(f32 *)(g + 0x80) - *(f32 *)(a0 + 0x10),
                                            *(f32 *)(g + 0x84) - *(f32 *)(a0 + 0x14))) < 1.5707964f
                && fabsf(*(f32 *)(g + 0x80) - *(f32 *)(a0 + 0x10)) < 3.0f) {
                *(s32 *)(p + 0x17C) = 1;
                *(s32 *)(p + 0x180) = 3;
            }
        }
        if (*(s32 *)(p + 0x17C) != 0) {
            c = a0[0x43];
            if (c == 0) {
                func_003C3A10(a0, 1, 0, 2);
            } else if ((a0[0x60] & 2) && c != 2) {
                func_003C3A10(a0, 2, 0, 2);
            }
            if (func_0038CAD0(p + 0x184) != 0) {
                func_L34_003515A0((s32)a0, 1);
                *(s32 *)(p + 0x184) = func_00382498(6, 12);
                if (--*(s32 *)(p + 0x180) <= 0) {
                    *(s32 *)(p + 0x17C) = 0;
                    *(s32 *)(p + 0x188) = 100;
                }
            }
        } else {
            c = a0[0x43];
            if (c == 2) {
                func_003C3A10(a0, 3, 0, 2);
            } else if ((a0[0x60] & 2) && c != 0) {
                func_003C3A10(a0, 0, 0, 2);
            }
        }
        if (*(s32 *)(p + 0x140) != -1) {
            t = D_L34_0021D840[*(s32 *)(p + 0x140)];
            if (*(f32 *)(a0 + 0x10) < t->e[0].x && *(f32 *)(a0 + 0x10) < t->e[t->count - 1].x) {
                *(s32 *)(p + 0x144) = 1;
            } else if (t->e[0].x < *(f32 *)(a0 + 0x10) && t->e[t->count - 1].x < *(f32 *)(a0 + 0x10)) {
                *(s32 *)(p + 0x144) = -1;
            }
            func_L34_00351D48(a0);
        }
        break;
    }
    }
}
/* localdecomp:end func_L34_00351648 */

/* localdecomp:start func_L34_00351B58 */
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_003A4F28(s32);
extern void func_L34_00351EB0(void *);
extern void func_003C2880(void *);
extern void func_L01_0044E850(void *, void *, s32, f32, f32);
extern u8 D_001A30B0[];

void func_L34_00351B58(u8 *a0) {
    u8 *s1 = *(u8 **)(a0 + 0x68);
    s32 idx;

    if (func_L01_00447490(a0, 0x10000, 0) != 0) {
        idx = *(s32 *)(s1 + 0x18C);
        if (idx != -1) {
            u8 *e = D_001A30B0 + (idx << 7);
            if (*(u8 **)(e + 0xDC) == a0 && e[0xD0] != 0) {
                func_003A4F28(idx);
            }
        }
        *(s32 *)(s1 + 0x18C) = -1;
        func_L34_00351EB0(a0);
        func_003C2880(a0);
    } else {
        func_L01_0044E850(a0, s1, 3, 0.028800001f, 0.43200004f);
    }
}
/* localdecomp:end func_L34_00351B58 */

/* localdecomp:start func_L34_00351C18 */
s32 func_003C24B0(s32, s32);
void func_L01_00456160(s32, s32);

s32 func_L34_00351C18(s32 arg0) {
    s32 temp_v0;

    temp_v0 = func_003C24B0(0x16F5, 0x1C0);
    if (temp_v0 != 0) {
        func_L01_00456160(temp_v0, arg0);
    }
    return temp_v0;
}
/* localdecomp:end func_L34_00351C18 */

/* localdecomp:start func_L34_00351C68 */
#include "vu0.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00351C68;

extern void func_L01_0043A430(void *, s32, void *);
extern f32 func_0038DAB8(f32, f32);
extern void func_003C3FC0(void *, void *);

void func_L34_00351C68(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    V_00351C68 v;

    if (p[0x81] == 0) {
        func_L01_0043A430(a0, 0, p + 0x80);
    }
    qzero(&v);
    *(f32 *)(p + 0x15C) = func_0038DAB8(*(f32 *)(p + 0x15C), 0.38397247f);
    v.z = *(f32 *)(p + 0x15C);
    func_003C3FC0(p + 0x90, &v);
    *(f32 *)(p + 0x160) = func_0038DAB8(*(f32 *)(p + 0x160), 0.12915437f);
    if (p[0xC1] == 0) {
        func_L01_0043A430(a0, 1, p + 0xC0);
    }
    qzero(&v);
    v.y = *(f32 *)(p + 0x160);
    func_003C3FC0(p + 0xD0, &v);
    if (p[0x101] == 0) {
        func_L01_0043A430(a0, 2, p + 0x100);
    }
    func_003C3FC0(p + 0x110, &v);
}
/* localdecomp:end func_L34_00351C68 */

INCLUDE_ASM("asm/levels", func_L34_00351D48);

/* localdecomp:start func_L34_00351EB0 */
typedef int s128_00351EB0 __attribute__((mode(TI)));

extern u8 D_L34_001D66B0[8];
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32);
extern void *func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);

/* follows func_L01_003E1DC0's call of func_L01_003303B8 */
void func_L34_00351EB0(void *a0) {
    s128_00351EB0 v;
    s128_00351EB0 *pv = &v;

    v = *(s128_00351EB0 *)((u8 *)a0 + 0x10);
    func_L01_00451FE0(a0, 0xF, D_L34_001D66B0, 0xFF, 0xB4, 0, 0, 0x23, 0, 3, 3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f);
    func_003A52A0(2, 0, a0);
    func_L01_003303B8(pv, 1, 25, 20, 20, 20, 45, 2, 0.5f, 0.0f, 0.0f, 2.0f,
                      1, 1, 1, 0, 1, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
}
/* localdecomp:end func_L34_00351EB0 */

/* localdecomp:start func_L34_00352018 */
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);

void func_L34_00352018(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    f32 r;

    *(s32 *)(p + 0x144) = 1;
    r = func_003824E0(0.8f, 1.2f) * 0.10000001f;
    *(f32 *)(p + 0x178) = r;
    *(f32 *)(p + 0x14C) = func_00382538();
    *(f32 *)(p + 0x154) = *(f32 *)(a0 + 0x18);
}
/* localdecomp:end func_L34_00352018 */

/* localdecomp:start func_L34_00352090 */
#include "vu0.h"

typedef struct {
    u8 pad0[0x20];
    f32 f20;
    u8 pad24[0x28 - 0x24];
    f32 f28;
    f32 f2C;
} V_00352090;

typedef struct {
    u8 pad0[0x10];
    u8 *f10;
    u8 pad14[0x16C - 0x14];
    u8 *f16C;
} T_00352090;

extern T_00352090 D_L34_0021F218;
extern f32 D_L34_001DD758;
extern f32 D_L34_001DD75C;
extern f32 D_L34_001DD760;
extern s32 D_L34_001DD768;
extern s32 D_L34_001DD76C;
extern f32 D_L34_001DD770;
extern f32 D_L34_001DD774;
extern f32 D_L34_001DD778;
extern f32 D_L34_001DD77C;
extern f32 D_L34_001DD780;
extern f32 D_L34_001DD784;
__asm__(".extern D_L34_001DD758, 4");
__asm__(".extern D_L34_001DD75C, 4");
__asm__(".extern D_L34_001DD760, 4");
__asm__(".extern D_L34_001DD768, 4");
__asm__(".extern D_L34_001DD76C, 4");
__asm__(".extern D_L34_001DD770, 4");
__asm__(".extern D_L34_001DD774, 4");
__asm__(".extern D_L34_001DD778, 4");
__asm__(".extern D_L34_001DD77C, 4");
__asm__(".extern D_L34_001DD780, 4");
__asm__(".extern D_L34_001DD784, 4");

extern s32 func_L01_00448D88(u32, s32);
extern void func_00382580(void *, f32, f32);
extern s32 func_00382498(s32, s32);
extern u8 *func_L01_00465738(void *, void *, s32, s32, s32, s32, s32, s32, s32, f32);
extern f32 func_003824E0(f32, f32);
extern void func_L01_00471BF0(void *, void *, s32);
extern void func_0038CE20(void *, void *, f32);
extern u8 *func_L01_00475C60(void *, void *, s32, s32, s32, s32, f32, f32, f32, s32);
extern s32 func_00382468(s32);

void func_L34_00352090(u8 *a0, void *a1) {
    V_00352090 *q = *(V_00352090 **)(a0 + 0x68);
    f32 v[4];
    f32 k;
    f32 t;
    f32 d;
    s32 c1;
    s32 c2;
    u8 *e;

    k = D_L34_001DD758;
    c1 = func_L01_00448D88(0x4F007FFF, 0);
    c2 = func_L01_00448D88(0x1F00007F, 0);
    q->f2C += D_L34_001DD77C;
    while (q->f2C >= 1.0f) {
        q->f2C -= 1.0f;
        func_00382580(v, D_L34_001DD75C * 0.020000001f, D_L34_001DD760 * 0.020000001f);
        d = -(D_L34_001DD760 * 3.0f * 0.020000001f * *(f32 *)(a0 + 0xE8));
        v[2] = fabs_asm(v[2]) + d;
        func_L01_00465738(a1, v, c1, c2, func_00382498(0x11, 0x1D), 1, -1, -1, 0, k * 40000.0f);
    }
    q->f28 += D_L34_001DD780;
    while (q->f28 >= 1.0f) {
        q->f28 -= 1.0f;
        func_00382580(v, D_L34_001DD770 * 0.020000001f, D_L34_001DD774 * 0.020000001f);
        t = fabs_asm(v[2]);
        d = -(func_003824E0(D_L34_001DD760, D_L34_001DD760 * 4.0f) * 0.020000001f * *(f32 *)(a0 + 0xE8));
        v[2] = t + d + D_L34_001DD778;
        func_L01_00471BF0(a1, v, func_00382498(D_L34_001DD76C, D_L34_001DD768));
    }
    q->f20 += D_L34_001DD784;
    while (q->f20 >= 1.0f) {
        q->f20 -= 1.0f;
        func_0038CE20(v, a0 + 0xE0, -0.18f);
        e = func_L01_00475C60(a1, v, 0x19, 1, 0x7F00B4FF, 0x3000B4FF, 147000.0f, 42000.0f, -5.0f, 0);
        if (e != 0) {
            e[2] = *D_L34_0021F218.f10;
            e[3] = func_00382468(2) ? 0x44 : 0x48;
        }
        e = func_L01_00475C60(a1, v, 0xC, 1, 0x7F007EFF, 0x40007EFF, 63000.004f, 21000.0f, 0.0f, 0);
        if (e != 0) {
            e[2] = *D_L34_0021F218.f16C;
            e[3] = 0x48;
        }
    }
}
/* localdecomp:end func_L34_00352090 */
