#include "common.h"

/* NTSC-U counterpart of func_003A2330 (src/boot_elf/text/3A1558.c): 60 Hz timers, 12 -> 15, 250 -> 300, 350 -> 420 */
/* localdecomp:start func_U_003A21F0 */
typedef struct {
    u32 h; s16 a; s16 b; s16 c; s16 st; s16 fl; u8 pE[2]; s16 f10; u8 p12[2]; s32 f14; s32 f18; u8 p1C[4]; s32 f20; s32 f24;
} E_003A21F0;
typedef struct {
    u8 p0[4]; s16 h4; u8 b6; u8 b7; s32 f8; u8 pC[4]; s32 f10; s32 f14;
    void (*f18)(s32, s32); s32 f1C; u8 p20[4]; s32 f24; s32 f28; s16 f2C; u8 p2E[2];
    s32 f30; s32 f34; s32 f38; s16 f3C; s16 f3E; u8 p40[4];
    E_003A21F0 e[4];
} S_003A21F0;
extern S_003A21F0 D_1CCFD0_003A21F0;
__asm__(".extern D_U_001D6DB0, 4");
__asm__(".extern D_U_001D6DB4, 4");
extern f32 D_U_001D6DB0;
extern f32 D_U_001D6DB4;
extern s32 func_U_0038CDF8(void *);
extern void func_U_003A1890(s32, s32, s32, s32 *, s32);
extern s32 func_0013C2C0(s32, s32, s32, s32, s32, s32, void *, long);
extern void func_0013C2A0(s32, s32, s32, s32, s32, s32);
extern s32 func_U_003A56A8(u32, s32);
extern s32 func_0013CDF0(s32);
extern void func_U_003A1BF0(s32, s32, s32);
extern void func_U_003A1CE8(s32, s32, s32);
extern int func_U_003A1E00(int, int, int, int);
extern void func_U_003A2D50(s32, long);
extern void func_U_003A1AF8(s32, s32, s32);
extern void func_0013CC40(s32);
extern void func_U_003A1FE0(void *);
extern s32 func_U_003A2858(s32, s32, s32);
void func_U_003A21F0(void) {
    s32 x;
    s16 h;
    if (D_1CCFD0_003A21F0.b7 != 0) return;
    if (!(D_1CCFD0_003A21F0.e[0].fl & 0x8000) && !(D_1CCFD0_003A21F0.e[0].st & 0x8000)) {
        if (D_1CCFD0_003A21F0.e[0].h == 0 && (D_1CCFD0_003A21F0.e[0].c & 1) && D_1CCFD0_003A21F0.f3C == -1) {
            func_U_003A1BF0(D_1CCFD0_003A21F0.e[0].a, D_1CCFD0_003A21F0.e[0].c, D_1CCFD0_003A21F0.e[0].b);
        } else if (D_1CCFD0_003A21F0.e[0].h != 0 && D_1CCFD0_003A21F0.e[0].h != 0xFFFFFFFF && D_1CCFD0_003A21F0.e[0].st == 8) {
            func_U_003A1CE8(D_1CCFD0_003A21F0.e[0].a, D_1CCFD0_003A21F0.e[0].c, D_1CCFD0_003A21F0.e[0].b);
        }
    }
    if (func_U_0038CDF8(&D_1CCFD0_003A21F0.f38) != 0 && D_1CCFD0_003A21F0.f3C != -1 && D_1CCFD0_003A21F0.f2C == 0) {
        if (D_1CCFD0_003A21F0.e[0].a != D_1CCFD0_003A21F0.f3C) {
        if (D_1CCFD0_003A21F0.f3E == -1) {
            if (D_1CCFD0_003A21F0.e[0].st & 0x8000) {
                D_1CCFD0_003A21F0.f2C = 3;
                D_1CCFD0_003A21F0.e[0].st = 5;
            } else {
                D_1CCFD0_003A21F0.f34 = 15;
                D_1CCFD0_003A21F0.e[3].f18 = 15;
                D_1CCFD0_003A21F0.f2C = 6;
            }
            D_1CCFD0_003A21F0.f38 = 300;
        } else if (func_U_003A1E00(D_1CCFD0_003A21F0.f3C, D_1CCFD0_003A21F0.f3E, D_1CCFD0_003A21F0.e[0].c, D_1CCFD0_003A21F0.e[0].b) != 0) {
            D_1CCFD0_003A21F0.f38 = 420;
        }
        } else D_1CCFD0_003A21F0.f3C = -1;
    }
    if (D_1CCFD0_003A21F0.f24 >= 0) {
        if (D_1CCFD0_003A21F0.e[2].h == 0) {
            func_U_003A1890(D_1CCFD0_003A21F0.f24, 0, D_1CCFD0_003A21F0.f28, (s32 *)&D_1CCFD0_003A21F0.e[2].h, 0x400);
            D_1CCFD0_003A21F0.f28 = 0;
            D_1CCFD0_003A21F0.f24 = -1;
        } else if (D_1CCFD0_003A21F0.e[2].st != 6 && D_1CCFD0_003A21F0.e[2].st != 7) {
            D_1CCFD0_003A21F0.e[2].st = 5;
        }
    }
    if (D_1CCFD0_003A21F0.e[0].st != 9 && D_1CCFD0_003A21F0.e[0].h != 0xFFFFFFFF && !(D_1CCFD0_003A21F0.e[0].fl & 0x8000) && !(D_1CCFD0_003A21F0.e[0].st & 0x8000)
        && (D_1CCFD0_003A21F0.f3E == -1 || (!(D_1CCFD0_003A21F0.e[3].fl & 0x8000) && !(D_1CCFD0_003A21F0.e[3].st & 0x8000)))) {
        switch (D_1CCFD0_003A21F0.f2C) {
        case 6: {
            u32 old = D_1CCFD0_003A21F0.e[0].h;
            D_1CCFD0_003A21F0.e[0].h = 0xFFFFFFFF;
            func_0013C2C0(old, 5, D_1CCFD0_003A21F0.e[0].b * D_1CCFD0_003A21F0.e[3].f18 / D_1CCFD0_003A21F0.f34, 0, 0, 0, func_U_003A2D50, (long)&D_1CCFD0_003A21F0.e[0].h);
            if (func_U_0038CDF8(&D_1CCFD0_003A21F0.e[3].f18) != 0) {
                D_1CCFD0_003A21F0.f2C = 3;
                D_1CCFD0_003A21F0.e[0].st = 5;
            }
            break;
        }
        case 2: {
            s32 v = D_1CCFD0_003A21F0.e[0].b * (D_1CCFD0_003A21F0.f34 - (D_1CCFD0_003A21F0.f30 - D_1CCFD0_003A21F0.e[3].f18)) / D_1CCFD0_003A21F0.f34;
            if (v <= 0 || !((D_1CCFD0_003A21F0.e[3].st == 4 && D_1CCFD0_003A21F0.e[3].f10 != 0) || D_1CCFD0_003A21F0.e[3].h != 0) || D_1CCFD0_003A21F0.e[0].h == 0) {
                D_1CCFD0_003A21F0.f2C = 3;
                D_1CCFD0_003A21F0.e[0].st = 5;
            } else if (D_1CCFD0_003A21F0.e[0].st != 9) {
                u32 old = D_1CCFD0_003A21F0.e[0].h;
                D_1CCFD0_003A21F0.e[0].h = 0xFFFFFFFF;
                func_0013C2C0(old, 5, v, 0, 0, 0, func_U_003A2D50, (long)&D_1CCFD0_003A21F0.e[0].h);
            }
            break;
        }
        case 3:
            if (D_1CCFD0_003A21F0.e[0].st == 0 && (D_1CCFD0_003A21F0.e[3].f10 != 0 || D_1CCFD0_003A21F0.e[3].h == 0)) {
                func_U_003A1AF8(D_1CCFD0_003A21F0.f3C, D_1CCFD0_003A21F0.e[0].c, D_1CCFD0_003A21F0.e[0].b);
                D_1CCFD0_003A21F0.f3C = -1;
                D_1CCFD0_003A21F0.f2C = 4;
            }
            break;
        case 4:
            if (D_1CCFD0_003A21F0.e[0].st == 3 && (D_1CCFD0_003A21F0.e[3].f18 < D_1CCFD0_003A21F0.f34 || D_1CCFD0_003A21F0.e[3].st != 4 || (D_1CCFD0_003A21F0.e[3].f10 == 0 && D_1CCFD0_003A21F0.e[3].h == 0))) {
                func_0013CC40(D_1CCFD0_003A21F0.e[0].h);
                D_1CCFD0_003A21F0.e[0].st = 8;
                D_1CCFD0_003A21F0.f2C = 5;
            }
            break;
        case 5:
            if (D_1CCFD0_003A21F0.e[3].st != 4 || D_1CCFD0_003A21F0.e[3].f10 == 0) D_1CCFD0_003A21F0.f2C = 0;
            break;
        }
    }
    {
        E_003A21F0 *e;
        x = D_U_001D6DB0 * 1024.0f;
        e = &D_1CCFD0_003A21F0.e[0];
        if (e->st == 4 && D_1CCFD0_003A21F0.e->h != 0xFFFFFFFF) func_0013C2A0(D_1CCFD0_003A21F0.e->h, 1, x, 0, 0, 0);
        x = D_U_001D6DB4 * 1024.0f;
        e = &D_1CCFD0_003A21F0.e[1];
        if (e->st == 4 && e->h != 0xFFFFFFFF && e->f20 != -1) func_U_003A56A8(e->f20, x);
    }
    func_U_003A1FE0((void *)&D_1CCFD0_003A21F0.e[0].h);
    func_U_003A1FE0((void *)&D_1CCFD0_003A21F0.e[3].h);
    func_U_003A1FE0((void *)&D_1CCFD0_003A21F0.e[1].h);
    func_U_003A1FE0((void *)&D_1CCFD0_003A21F0.e[2].h);
    if (D_1CCFD0_003A21F0.e[2].st == 2 && D_1CCFD0_003A21F0.e[2].f24 < 0) {
        if (D_1CCFD0_003A21F0.e[1].st != 6 && D_1CCFD0_003A21F0.e[1].st != 7) D_1CCFD0_003A21F0.e[1].st = 5;
        if (D_1CCFD0_003A21F0.e[2].st != 6 && D_1CCFD0_003A21F0.e[2].st != 7) D_1CCFD0_003A21F0.e[2].st = 5;
    } else {
        D_1CCFD0_003A21F0.e[2].f24--;
    }
    if (D_1CCFD0_003A21F0.b6 != 0) {
        if (func_0013CDF0(1) == 0) {
            D_1CCFD0_003A21F0.h4 = 0;
            D_1CCFD0_003A21F0.b6 = 0;
            if (D_1CCFD0_003A21F0.f18 != 0) {
                void (*fn)(s32, s32) = D_1CCFD0_003A21F0.f18;
                s32 a = D_1CCFD0_003A21F0.f1C;
                D_1CCFD0_003A21F0.f18 = 0;
                D_1CCFD0_003A21F0.f1C = 0;
                fn(a, 0);
            }
        }
    } else {
        h = D_1CCFD0_003A21F0.h4;
        if (h == 2) {
            D_1CCFD0_003A21F0.h4 = 0;
            func_U_003A2858(D_1CCFD0_003A21F0.f14, D_1CCFD0_003A21F0.f8, D_1CCFD0_003A21F0.f10);
            if (D_1CCFD0_003A21F0.h4 == 0) D_1CCFD0_003A21F0.h4 = h;
        }
    }
}
/* localdecomp:end func_U_003A21F0 */
