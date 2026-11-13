#include "common.h"
#include "vu0.h"

typedef struct T_0034F950 {
    u8 pad_00[0xD4];
    s32 f_D4;
    s32 f_D8;
    s32 f_DC;
} T_0034F950;
typedef struct U_0034F950 {
    u8 pad_00[0x68];
    T_0034F950 *f_68;
} U_0034F950;

INCLUDE_ASM("asm/levels", func_L36_0034E8C0);

/* localdecomp:start func_L36_0034F950 */
/* Ps2EeAs only uses $gp for this if it knows the size before the use. */
__asm__(".extern D_L36_001DD3A8, 8");
extern f32 func_003824E0(f32, f32);
extern f32 D_L36_001DD3A8[2];

void func_L36_0034F950(U_0034F950 *a0) {
    T_0034F950 *s;
    s32 i;
    s32 old;
    f32 r;
    f32 x;

    i = 0;
    s = a0->f_68;
    s->f_D4 = 1;
    old = s->f_D8;
    s->f_DC = old;
    x = 1.0f;
    if (old != 4) {
        x = x - D_L36_001DD3A8[old];
    }
    r = func_003824E0(0.0f, x);
    if (0.0f <= r) {
        do {
            if (i != s->f_DC) {
                r = r - D_L36_001DD3A8[i];
            }
            i++;
        } while (0.0f <= r);
    }
    s->f_D8 = i - 1;
}
/* localdecomp:end func_L36_0034F950 */

/* localdecomp:start func_L36_0034FA10 */
__asm__(".extern D_L36_001DD388, 8");
__asm__(".extern D_L36_001DD398, 8");
extern f32 func_003824E0(f32, f32);
extern f32 func_003C4088(f32, f32, f32);
extern f32 D_L36_001DD388[2];
extern f32 D_L36_001DD398[2];
extern f32 D_001A4C64[];
void func_L36_0034FA10(u8 *a0, s32 a1) {
    u8 *s = *(u8 **)(a0 + 0x68);
    s32 i = 0;
    f32 best;
    f32 r;
    best = func_003824E0(0.0f, 1.0f);
    r = func_003824E0(0.0f, 1.0f);
    if (best < r) {
        if (a1 & 2) {
            best = r;
            i = 1;
        }
    }
    r = func_003824E0(0.0f, 1.0f);
    if (best < r) {
        if (a1 & 4) {
            best = r;
            i = 2;
        }
    }
    *(f32 *)(s + 0xB0) = func_003C4088(*(f32 *)(s + 0x114), *(f32 *)(s + 0x118), D_L36_001DD388[i]);
    *(f32 *)(s + 0xB4) = D_001A4C64[0];
    *(f32 *)(s + 0xB8) = func_003C4088(*(f32 *)(s + 0x11C), *(f32 *)(s + 0x120), D_L36_001DD398[i]);
}
/* localdecomp:end func_L36_0034FA10 */

INCLUDE_ASM("asm/levels", func_L36_0034FB20);

/* localdecomp:start func_L36_0034FE78 */
__asm__(".extern D_L36_001DD3CC, 4");
__asm__(".extern D_L36_001DD368, 4");
__asm__(".extern D_L36_001DD420, 4");
__asm__(".extern D_L36_001DD418, 4");
__asm__(".extern D_L36_001DD40C, 4");
__asm__(".extern D_L36_001DD410, 4");
__asm__(".extern D_L36_001DD414, 4");
__asm__(".extern D_L36_001DD3D4, 4");
__asm__(".extern D_L36_001DD3DC, 4");
extern s32 D_L36_001DD3CC;
extern f32 D_L36_001DD368;
extern f32 D_L36_001DD420;
extern f32 D_L36_001DD418;
extern f32 D_L36_001DD40C;
extern f32 D_L36_001DD410;
extern f32 D_L36_001DD414;
extern f32 D_L36_001DD3D4;
extern f32 D_L36_001DD3DC;
extern f32 D_L36_001E1880;
extern u8 D_001A4BE0[];
extern vu0_v4 D_001A4C60;
extern s32 func_0038CAD0(void *);
extern void func_L01_0044ABD0(void *, void *);
extern u8 *func_L01_00447490(void *, s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_003C4A40(void *, void *);
extern void func_L01_004450F0(void *, s32, s32);
extern f32 func_003C4088(f32, f32, f32);
extern void func_L30_0034CB68(u8 *, void *, s32, s32, s32, s32, f32, f32);
void func_L36_0034FE78(u8 *a0) {
    u8 *s;
    u8 *t;
    u8 *hero;
    vu0_v4 v;
    vu0_v4 w;
    f32 a;
    f32 b;
    f32 x;
    f32 dmg;
    s16 id;

    s = *(u8 **)(a0 + 0x68);
    func_0038CAD0(s + 0xE8);
    func_L01_0044ABD0(a0, s + 0x70);
    t = func_L01_00447490(a0, 0x10000, 0);
    if (t != 0) {
        a0[0xA8] = 0xFF;
        dmg = *(f32 *)(t + 0x2C);
        if (0.0f < dmg) {
            id = *(s16 *)(*(u8 **)(t + 0x20) + 0xAA);
            if (id != 0x167E && id != 0x1903 && id != 0x1644 && a0[0x20] == 2 && *(s32 *)(s + 0xE8) <= 0) {
                f32 push = D_L36_001DD368;
                *(s32 *)(s + 0xE8) = D_L36_001DD3CC;
                *(f32 *)(s + 0x30) = *(f32 *)(s + 0x30) - dmg;
                v = *(vu0_v4 *)(t + 0x10);
                func_0038CF68(&v, &v, push);
                vec_add_ab(s + 0xC0, s + 0xC0, &v);
                if (*(s32 *)(s + 0xD8) != 4) {
                    *(s32 *)(s + 0xDC) = *(s32 *)(s + 0xD8);
                    *(s32 *)(s + 0xD4) = 1;
                    *(s32 *)(s + 0xD8) = 4;
                }
                s[0x77] = 0xFF;
                func_003C4A40(a0, s + 0x70);
                if (*(f32 *)(s + 0x30) <= 0.0f) {
                    func_L01_004450F0(a0, 0x42, -1);
                }
            }
        }
    }
    hero = D_001A4BE0;
    *(f32 *)(a0 + 0x14) = *(f32 *)(hero + 0x84);
    if (a0[0x43] == 1) {
        x = *(f32 *)(s + 0xC8) * 0.5f / D_L36_001DD420 + 0.5f;
        if (1.0f < x) {
            x = 1.0f;
        } else if (x < 0.0f) {
            x = 0.0f;
        }
        a = func_003C4088(D_L36_001DD418, D_L36_001DD40C, x);
        x = *(f32 *)(s + 0xC0) * 0.5f / D_L36_001DD420 + 0.5f;
        if (1.0f < x) {
            x = 1.0f;
        } else if (x < 0.0f) {
            x = 0.0f;
        }
        b = func_003C4088(D_L36_001DD410, D_L36_001DD414, x);
    } else {
        vec_sub_ab(&w, hero + 0x80, a0 + 0x10);
        func_0038CF68(&w, &w, 1.0f);
        a = func_003C4088(D_L36_001DD418, D_L36_001DD40C, w.z * 0.5f + 0.5f);
        b = func_003C4088(D_L36_001DD410, D_L36_001DD414, w.x * 0.5f + 0.5f);
    }
    if (((D_L36_001DD418 < *(f32 *)(a0 + 0xF4) + D_L36_001DD3D4) ? D_L36_001DD418 : *(f32 *)(a0 + 0xF4) + D_L36_001DD3D4) < a) {
        a = (D_L36_001DD418 < *(f32 *)(a0 + 0xF4) + D_L36_001DD3D4) ? D_L36_001DD418 : *(f32 *)(a0 + 0xF4) + D_L36_001DD3D4;
    } else if (a < ((*(f32 *)(a0 + 0xF4) - D_L36_001DD3D4 < D_L36_001DD40C) ? D_L36_001DD40C : *(f32 *)(a0 + 0xF4) - D_L36_001DD3D4)) {
        a = (*(f32 *)(a0 + 0xF4) - D_L36_001DD3D4 < D_L36_001DD40C) ? D_L36_001DD40C : *(f32 *)(a0 + 0xF4) - D_L36_001DD3D4;
    }
    if (((D_L36_001DD414 < *(f32 *)(a0 + 0xF8) + D_L36_001DD3D4) ? D_L36_001DD414 : *(f32 *)(a0 + 0xF8) + D_L36_001DD3D4) < b) {
        b = (D_L36_001DD414 < *(f32 *)(a0 + 0xF8) + D_L36_001DD3D4) ? D_L36_001DD414 : *(f32 *)(a0 + 0xF8) + D_L36_001DD3D4;
    } else if (b < ((*(f32 *)(a0 + 0xF8) - D_L36_001DD3D4 < D_L36_001DD410) ? D_L36_001DD410 : *(f32 *)(a0 + 0xF8) - D_L36_001DD3D4)) {
        b = (*(f32 *)(a0 + 0xF8) - D_L36_001DD3D4 < D_L36_001DD410) ? D_L36_001DD410 : *(f32 *)(a0 + 0xF8) - D_L36_001DD3D4;
    }
    *(f32 *)(a0 + 0xF4) = a;
    *(f32 *)(a0 + 0xF8) = b;
    if (a0[0x20] == 2 && *(s32 *)(s + 0xD8) != 4) {
        vec_sub_ba(&v, &D_001A4C60, a0 + 0x10);
        func_0038CF68(&v, &v, 1.0f);
        func_L30_0034CB68(a0, &v, 1, -1, 0, 0, (f32)s[0x44],
                          D_L36_001DD3DC * *(f32 *)(a0 + 0x2C) / *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24));
    }
    D_L36_001E1880 = *(f32 *)(s + 0x30);
}
/* localdecomp:end func_L36_0034FE78 */

/* localdecomp:start func_L36_00350330 */
typedef int Q_00350330 __attribute__((mode(TI)));
extern u8 *D_L36_001DFC00;
extern u8 *D_L36_001DFB1C;
extern u8 *D_L36_001DFB28;
__asm__(".extern D_L36_001DFC00, 16");
__asm__(".extern D_L36_001DFB1C, 16");
__asm__(".extern D_L36_001DFB28, 16");
extern f32 func_0038CE68(void *, void *);

typedef struct {
    char pad0[0xA0];
    Q_00350330 vA0;
    Q_00350330 vB0;
    Q_00350330 vC0;
    s32 fD0;
    s32 fD4;
    s32 fD8;
    s32 fDC;
    char padE0[8];
    s32 fE8;
    s32 fEC;
    s32 fF0;
    u8 *fF4;
    s32 fF8;
    u8 *fFC;
    u8 *f100;
    char pad104[8];
    s32 f10C;
    u8 *f110;
    f32 f114;
    f32 f118;
    f32 f11C;
    f32 f120;
    s32 f124;
    u8 *f128;
    s32 f12C;
    u8 *f130;
} S_00350330;

void func_L36_00350330(u8 *a0) {
    S_00350330 *s;
    u8 *p;
    u8 *t;
    f32 v[4] __attribute__((aligned(16)));
    Q_00350330 x;

    a0[0x30] = 0xFF;
    s = *(S_00350330 **)(a0 + 0x68);
    x = *(Q_00350330 *)(a0 + 0x10);
    qzero((u8 *)s + 0xC0);
    *(Q_00350330 *)((u8 *)s + 0xA0) = x;
    *(Q_00350330 *)((u8 *)s + 0xB0) = x;
    s->fD0 = 0;
    s->fD4 = 0;
    s->fD8 = -1;
    s->fDC = -1;
    s->fE8 = 0;
    s->fEC = 0;
    s->fF4 = D_L36_001DFC00 + s->fF0 * 0x80;
    s->fFC = D_L36_001DFB1C + s->fF8 * 0x100;
    for (p = D_L36_001DFB28; p != 0; p = *(u8 **)(p + 0x28)) {
        if (*(s16 *)(p + 0xAA) == 0x1B55) {
            s->f100 = p;
        }
    }
    s->f110 = D_L36_001DFC00 + s->f10C * 0x80;
    qzero(v);
    v[0] = 1.0f;
    s->f114 = *(f32 *)(s->f110 + 0x30) - func_0038CE68(s->f110, v);
    s->f118 = *(f32 *)(s->f110 + 0x30) + func_0038CE68(s->f110, v);
    qzero(v);
    v[2] = 1.0f;
    s->f11C = *(f32 *)(s->f110 + 0x38) - func_0038CE68(s->f110 + 0x20, v);
    s->f120 = *(f32 *)(s->f110 + 0x38) + func_0038CE68(s->f110 + 0x20, v);
    s->f128 = D_L36_001DFB1C + s->f124 * 0x100;
    s->f130 = D_L36_001DFB1C + s->f12C * 0x100;
    t = *(u8 **)(s->f130 + 0x68);
    *(f32 *)(t + 0x88) = s->f120;
    *(f32 *)(t + 0x80) = s->f114 + 5.0f;
    *(f32 *)(t + 0x84) = s->f118 - 5.0f;
}
/* localdecomp:end func_L36_00350330 */
