#include "common.h"

/* NTSC-U counterpart of func_003A1F30 (src/frontbin/3A1158.c): 60 Hz timings (12 -> 15, 250 -> 300, 350 -> 420) */
/* localdecomp:start func_U_0039CEA8 */
typedef struct {
    u32 h; s16 a; s16 b; s16 c; s16 st; s16 fl; u8 pE[2]; s16 f10; u8 p12[2]; s32 f14; s32 f18; u8 p1C[4]; s32 f20; s32 f24;
} E_0039CEA8;
typedef struct {
    u8 p0[4]; s16 h4; u8 b6; u8 b7; s32 f8; u8 pC[4]; s32 f10; s32 f14;
    void (*f18)(s32, s32); s32 f1C; u8 p20[4]; s32 f24; s32 f28; s16 f2C; u8 p2E[2];
    s32 f30; s32 f34; s32 f38; s16 f3C; s16 f3E; u8 p40[4];
    E_0039CEA8 e[4];
} S_0039CEA8;
extern S_0039CEA8 D_001CCFD0_0039CEA8;
__asm__(".extern D_U_001D6DB0, 4");
__asm__(".extern D_U_001D6DB4, 4");
extern f32 D_U_001D6DB0;
extern f32 D_U_001D6DB4;
extern s32 func_U_00388398(void *);
extern void func_U_0039C548(s32, s32, s32, s32 *, s32);
extern s32 func_0013C2C0(s32, s32, s32, s32, s32, s32, void *, long);
extern void func_0013C2A0(s32, s32, s32, s32, s32, s32);
extern s32 func_U_0039FFC8(u32, s32);
extern s32 func_0013CDF0(s32);
extern void func_U_0039C8A8(s32, s32, s32);
extern void func_U_0039C9A0(s32, s32, s32);
extern s32 func_U_0039CAB8(s32, s32, s32, s32);
extern void func_U_0039DA08(s32, long);
extern void func_U_0039C7B0(s32, s32, s32);
extern void func_0013CC40(s32);
extern void func_U_0039CC98(void *);
extern s32 func_U_0039D510(s32, s32, s32);
void func_U_0039CEA8(void) {
    s32 x;
    s16 h;
    if (D_001CCFD0_0039CEA8.b7 != 0) return;
    if (!(D_001CCFD0_0039CEA8.e[0].fl & 0x8000) && !(D_001CCFD0_0039CEA8.e[0].st & 0x8000)) {
        if (D_001CCFD0_0039CEA8.e[0].h == 0 && (D_001CCFD0_0039CEA8.e[0].c & 1) && D_001CCFD0_0039CEA8.f3C == -1) {
            func_U_0039C8A8(D_001CCFD0_0039CEA8.e[0].a, D_001CCFD0_0039CEA8.e[0].c, D_001CCFD0_0039CEA8.e[0].b);
        } else if (D_001CCFD0_0039CEA8.e[0].h != 0 && D_001CCFD0_0039CEA8.e[0].h != 0xFFFFFFFF && D_001CCFD0_0039CEA8.e[0].st == 8) {
            func_U_0039C9A0(D_001CCFD0_0039CEA8.e[0].a, D_001CCFD0_0039CEA8.e[0].c, D_001CCFD0_0039CEA8.e[0].b);
        }
    }
    if (func_U_00388398(&D_001CCFD0_0039CEA8.f38) != 0 && D_001CCFD0_0039CEA8.f3C != -1 && D_001CCFD0_0039CEA8.f2C == 0) {
        if (D_001CCFD0_0039CEA8.e[0].a != D_001CCFD0_0039CEA8.f3C) {
        if (D_001CCFD0_0039CEA8.f3E == -1) {
            if (D_001CCFD0_0039CEA8.e[0].st & 0x8000) {
                D_001CCFD0_0039CEA8.f2C = 3;
                D_001CCFD0_0039CEA8.e[0].st = 5;
            } else {
                D_001CCFD0_0039CEA8.f34 = 15;
                D_001CCFD0_0039CEA8.e[3].f18 = 15;
                D_001CCFD0_0039CEA8.f2C = 6;
            }
            D_001CCFD0_0039CEA8.f38 = 300;
        } else if (func_U_0039CAB8(D_001CCFD0_0039CEA8.f3C, D_001CCFD0_0039CEA8.f3E, D_001CCFD0_0039CEA8.e[0].c, D_001CCFD0_0039CEA8.e[0].b) != 0) {
            D_001CCFD0_0039CEA8.f38 = 0x1A4;
        }
        } else D_001CCFD0_0039CEA8.f3C = -1;
    }
    if (D_001CCFD0_0039CEA8.f24 >= 0) {
        if (D_001CCFD0_0039CEA8.e[2].h == 0) {
            func_U_0039C548(D_001CCFD0_0039CEA8.f24, 0, D_001CCFD0_0039CEA8.f28, (s32 *)&D_001CCFD0_0039CEA8.e[2].h, 0x400);
            D_001CCFD0_0039CEA8.f28 = 0;
            D_001CCFD0_0039CEA8.f24 = -1;
        } else if (D_001CCFD0_0039CEA8.e[2].st != 6 && D_001CCFD0_0039CEA8.e[2].st != 7) {
            D_001CCFD0_0039CEA8.e[2].st = 5;
        }
    }
    if (D_001CCFD0_0039CEA8.e[0].st != 9 && D_001CCFD0_0039CEA8.e[0].h != 0xFFFFFFFF && !(D_001CCFD0_0039CEA8.e[0].fl & 0x8000) && !(D_001CCFD0_0039CEA8.e[0].st & 0x8000)
        && (D_001CCFD0_0039CEA8.f3E == -1 || (!(D_001CCFD0_0039CEA8.e[3].fl & 0x8000) && !(D_001CCFD0_0039CEA8.e[3].st & 0x8000)))) {
        switch (D_001CCFD0_0039CEA8.f2C) {
        case 6: {
            u32 old = D_001CCFD0_0039CEA8.e[0].h;
            D_001CCFD0_0039CEA8.e[0].h = 0xFFFFFFFF;
            func_0013C2C0(old, 5, D_001CCFD0_0039CEA8.e[0].b * D_001CCFD0_0039CEA8.e[3].f18 / D_001CCFD0_0039CEA8.f34, 0, 0, 0, func_U_0039DA08, (long)&D_001CCFD0_0039CEA8.e[0].h);
            if (func_U_00388398(&D_001CCFD0_0039CEA8.e[3].f18) != 0) {
                D_001CCFD0_0039CEA8.f2C = 3;
                D_001CCFD0_0039CEA8.e[0].st = 5;
            }
            break;
        }
        case 2: {
            s32 v = D_001CCFD0_0039CEA8.e[0].b * (D_001CCFD0_0039CEA8.f34 - (D_001CCFD0_0039CEA8.f30 - D_001CCFD0_0039CEA8.e[3].f18)) / D_001CCFD0_0039CEA8.f34;
            if (v <= 0 || !((D_001CCFD0_0039CEA8.e[3].st == 4 && D_001CCFD0_0039CEA8.e[3].f10 != 0) || D_001CCFD0_0039CEA8.e[3].h != 0) || D_001CCFD0_0039CEA8.e[0].h == 0) {
                D_001CCFD0_0039CEA8.f2C = 3;
                D_001CCFD0_0039CEA8.e[0].st = 5;
            } else if (D_001CCFD0_0039CEA8.e[0].st != 9) {
                u32 old = D_001CCFD0_0039CEA8.e[0].h;
                D_001CCFD0_0039CEA8.e[0].h = 0xFFFFFFFF;
                func_0013C2C0(old, 5, v, 0, 0, 0, func_U_0039DA08, (long)&D_001CCFD0_0039CEA8.e[0].h);
            }
            break;
        }
        case 3:
            if (D_001CCFD0_0039CEA8.e[0].st == 0 && (D_001CCFD0_0039CEA8.e[3].f10 != 0 || D_001CCFD0_0039CEA8.e[3].h == 0)) {
                func_U_0039C7B0(D_001CCFD0_0039CEA8.f3C, D_001CCFD0_0039CEA8.e[0].c, D_001CCFD0_0039CEA8.e[0].b);
                D_001CCFD0_0039CEA8.f3C = -1;
                D_001CCFD0_0039CEA8.f2C = 4;
            }
            break;
        case 4:
            if (D_001CCFD0_0039CEA8.e[0].st == 3 && (D_001CCFD0_0039CEA8.e[3].f18 < D_001CCFD0_0039CEA8.f34 || D_001CCFD0_0039CEA8.e[3].st != 4 || (D_001CCFD0_0039CEA8.e[3].f10 == 0 && D_001CCFD0_0039CEA8.e[3].h == 0))) {
                func_0013CC40(D_001CCFD0_0039CEA8.e[0].h);
                D_001CCFD0_0039CEA8.e[0].st = 8;
                D_001CCFD0_0039CEA8.f2C = 5;
            }
            break;
        case 5:
            if (D_001CCFD0_0039CEA8.e[3].st != 4 || D_001CCFD0_0039CEA8.e[3].f10 == 0) D_001CCFD0_0039CEA8.f2C = 0;
            break;
        }
    }
    {
        E_0039CEA8 *e;
        x = D_U_001D6DB0 * 1024.0f;
        e = &D_001CCFD0_0039CEA8.e[0];
        if (e->st == 4 && D_001CCFD0_0039CEA8.e->h != 0xFFFFFFFF) func_0013C2A0(D_001CCFD0_0039CEA8.e->h, 1, x, 0, 0, 0);
        x = D_U_001D6DB4 * 1024.0f;
        e = &D_001CCFD0_0039CEA8.e[1];
        if (e->st == 4 && e->h != 0xFFFFFFFF && e->f20 != -1) func_U_0039FFC8(e->f20, x);
    }
    func_U_0039CC98((void *)&D_001CCFD0_0039CEA8.e[0].h);
    func_U_0039CC98((void *)&D_001CCFD0_0039CEA8.e[3].h);
    func_U_0039CC98((void *)&D_001CCFD0_0039CEA8.e[1].h);
    func_U_0039CC98((void *)&D_001CCFD0_0039CEA8.e[2].h);
    if (D_001CCFD0_0039CEA8.e[2].st == 2 && D_001CCFD0_0039CEA8.e[2].f24 < 0) {
        if (D_001CCFD0_0039CEA8.e[1].st != 6 && D_001CCFD0_0039CEA8.e[1].st != 7) D_001CCFD0_0039CEA8.e[1].st = 5;
        if (D_001CCFD0_0039CEA8.e[2].st != 6 && D_001CCFD0_0039CEA8.e[2].st != 7) D_001CCFD0_0039CEA8.e[2].st = 5;
    } else {
        D_001CCFD0_0039CEA8.e[2].f24--;
    }
    if (D_001CCFD0_0039CEA8.b6 != 0) {
        if (func_0013CDF0(1) == 0) {
            D_001CCFD0_0039CEA8.h4 = 0;
            D_001CCFD0_0039CEA8.b6 = 0;
            if (D_001CCFD0_0039CEA8.f18 != 0) {
                void (*fn)(s32, s32) = D_001CCFD0_0039CEA8.f18;
                s32 a = D_001CCFD0_0039CEA8.f1C;
                D_001CCFD0_0039CEA8.f18 = 0;
                D_001CCFD0_0039CEA8.f1C = 0;
                fn(a, 0);
            }
        }
    } else {
        h = D_001CCFD0_0039CEA8.h4;
        if (h == 2) {
            D_001CCFD0_0039CEA8.h4 = 0;
            func_U_0039D510(D_001CCFD0_0039CEA8.f14, D_001CCFD0_0039CEA8.f8, D_001CCFD0_0039CEA8.f10);
            if (D_001CCFD0_0039CEA8.h4 == 0) D_001CCFD0_0039CEA8.h4 = h;
        }
    }
}
/* localdecomp:end func_U_0039CEA8 */
