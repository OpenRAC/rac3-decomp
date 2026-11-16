#include "common.h"

/* NTSC-U counterpart of func_L09_003B8580 (src/levels/09_tyhrranosis/L09_003B8580.c) */
#include "vu0.h"

/* localdecomp:start func_L09_003B6D38 */
#include "vu0.h"


typedef struct Vec_T {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec_T;

typedef union PathEnt_T {
    s32 n;
    Vec_T v;
} PathEnt_T;

typedef struct I2_T {
    s32 a;
    s32 b;
} I2_T;

typedef union VI_T {
    Vec_T v;
    I2_T i;
} VI_T;

typedef struct Moby_T Moby_T;
typedef struct Pv_T Pv_T;

typedef struct Cls_T {
    u8 pad0[0x10];
    s32 i010;
    u8 pad14[0x44 - 0x14];
    u16 H044;
} Cls_T;

struct Moby_T {
    u8 pad0[8];
    f32 f008;
    u8 padC[4];
    Vec_T pos;
    u8 b020;
    u8 pad21[2];
    u8 b023;
    Cls_T *cls;
    u8 pad28[0x34 - 0x28];
    u16 H034;
    u8 pad36[0x42 - 0x36];
    u8 b042;
    u8 b043;
    u8 pad44[0x48 - 0x44];
    f32 f048;
    u8 pad4C[0x60 - 0x4C];
    u8 b060;
    u8 pad61[0x68 - 0x61];
    Pv_T *pv;
    u8 pad6C[0x94 - 0x6C];
    u8 b094;
    u8 b095;
    u8 pad96[2];
    s32 i098;
    u8 pad9C[0xBC - 0x9C];
    u8 bBC;
    u8 padBD;
    u8 bBE;
    u8 padBF;
    u8 padC0[0xD0 - 0xC0];
    Vec_T vD0;
    u8 padE0[0x10];
    Vec_T vF0;
};

struct Pv_T {
    u8 pad0[0x30 - 0x0];
    /* 0x030 */ f32 f030;
    u8 pad34[0xD0 - 0x34];
    u8 x0D0[1];
    u8 padD1[0x12C - 0xD1];
    /* 0x12C */ f32 f12C;
    u8 pad130[0x1B4 - 0x130];
    /* 0x1B4 */ f32 f1B4;
    u8 pad1B8[0x1C4 - 0x1B8];
    /* 0x1C4 */ f32 f1C4;
    /* 0x1C8 */ s32 i1C8;
    u8 pad1CC[0x254 - 0x1CC];
    /* 0x254 */ PathEnt_T * P254;
    /* 0x258 */ s16 h258;
    /* 0x25A */ s16 h25A;
    /* 0x25C */ f32 f25C;
    u8 pad260[0xBE8 - 0x260];
    /* 0xBE8 */ f32 fBE8;
    u8 padBEC[0xC30 - 0xBEC];
    /* 0xC30 */ f32 fC30;
    u8 padC34[0xC50 - 0xC34];
    u8 xC50[1];
    u8 padC51[0xC80 - 0xC51];
    u8 xC80[1];
    u8 padC81[0xC98 - 0xC81];
    /* 0xC98 */ s32 iC98;
    u8 xC9C[1];
    u8 padC9D[0xCC8 - 0xC9D];
    /* 0xCC8 */ f32 fCC8;
    /* 0xCCC */ f32 fCCC;
    /* 0xCD0 */ s32 iCD0;
    /* 0xCD4 */ s32 iCD4;
    u8 xCD8[1];
    u8 padCD9[0xCDC - 0xCD9];
    /* 0xCDC */ f32 fCDC;
    /* 0xCE0 */ s32 iCE0;
    /* 0xCE4 */ s32 iCE4;
    /* 0xCE8 */ s32 iCE8;
    /* 0xCEC */ s32 iCEC;
    /* 0xCF0 */ s32 iCF0;
    /* 0xCF4 */ s32 iCF4;
    /* 0xCF8 */ s32 iCF8;
    /* 0xCFC */ s32 iCFC;
    /* 0xD00 */ s32 iD00;
    /* 0xD04 */ s32 iD04;
    /* 0xD08 */ s32 iD08;
    /* 0xD0C */ s32 iD0C;
    /* 0xD10 */ s32 iD10;
    /* 0xD14 */ s32 iD14;
    /* 0xD18 */ s32 iD18;
    /* 0xD1C */ s32 iD1C;
    /* 0xD20 */ s32 iD20;
    u8 padD24[0xD28 - 0xD24];
    /* 0xD28 */ s32 iD28;
    /* 0xD2C */ s8 cD2C;
    /* 0xD2D */ u8 bD2D;
    /* 0xD2E */ u8 bD2E;
    /* 0xD2F */ s8 cD2F;
    /* 0xD30 */ s16 hD30;
    u8 padD32[0xD34 - 0xD32];
    /* 0xD34 */ s16 hD34;
    /* 0xD36 */ s16 hD36;
    /* 0xD38 */ s16 hD38;
    u8 padD3A[0xD3C - 0xD3A];
    /* 0xD3C */ f32 fD3C;
    /* 0xD40 */ u8 bD40;
    /* 0xD41 */ u8 bD41;
    /* 0xD42 */ u8 bD42;
    u8 padD43[0xD4C - 0xD43];
    /* 0xD4C */ f32 fD4C;
    /* 0xD50 */ s32 iD50;
    /* 0xD54 */ s32 iD54;
    u8 padD58[0xD5A - 0xD58];
    /* 0xD5A */ s16 hD5A;
    u8 padD5C[0xD60 - 0xD5C];
    /* 0xD60 */ Vec_T vD60;
};

typedef struct Hero_T {
    u8 pad0[0x80];
    f32 f080;
    f32 f084;
    u8 pad88[0x238 - 0x88];
    s32 i238;
    u8 pad23C[0x25C4 - 0x23C];
    s32 i25C4;
    u8 pad25C8[0x2850 - 0x25C8];
    s32 i2850;
} Hero_T;

typedef struct Rec80_T {
    u8 pad0[0x30];
    Vec_T v30;
    u8 pad40[0x30];
    Vec_T v70;
} Rec80_T;

typedef struct Ctl_T {
    u8 pad0[0x144];
    Moby_T *m144;
    s32 i148;
} Ctl_T;

typedef struct Snd_T {
    u8 pad0[0x1034];
    u32 i1034;
    u8 pad1038[0x1040 - 0x1038];
    u32 i1040;
    u8 pad1044[0x104C - 0x1044];
    u32 i104C;
    u8 pad1050[0x12480 - 0x1050];
    u16 H12480;
    u8 pad12482[0x1248C - 0x12482];
    u16 H1248C;
    u8 pad1248E[0x12498 - 0x1248E];
    u16 H12498;
} Snd_T;

typedef struct Ptr_T {
    u8 pad0[0xAA];
    s16 hAA;
} Ptr_T;

extern u8 D_001A4BE0[];
extern u8 D_001A4C60[];
extern Snd_T D_001A7E18;
extern s32 D_00142660[];
extern u8 D_001426E0[];
extern s32 D_00142C38[];
extern Ptr_T *D_001A73E8[];
extern s32 D_001A4E18[];
extern s32 D_001D545C;
extern u8 *D_L09_001E011C;
extern s32 D_L09_001E0158;
extern Rec80_T *D_L09_001E0200;
extern u8 D_L09_001E2C00[];
__asm__(".extern D_L09_001E2C00, 16");
extern u16 *D_L09_0021CE20[];
extern s32 *D_L09_0021E6C0[];
__asm__(".extern D_L09_0021E6C0, 16");
extern u8 D_L09_002BB2B0[];
extern u8 D_L09_002BB300[];
extern Vec_T D_L09_001D66B0_003B6D38 __attribute__((section(".sdata")));
extern s32 D_L09_001DE788[];
extern s32 D_L09_001DE790[];
extern Vec_T D_L09_001DE6E0_003B6D38 __attribute__((section(".sdata")));
__asm__(".extern D_L09_001DE6E0_003B6D38, 8");
extern Vec_T D_L09_001DE6F0_003B6D38 __attribute__((section(".sdata")));
__asm__(".extern D_L09_001DE6F0_003B6D38, 8");
extern Vec_T D_L09_001DE710_003B6D38 __attribute__((section(".sdata")));
__asm__(".extern D_L09_001DE710_003B6D38, 8");
extern f32 D_L09_001DE720_003B6D38;
__asm__(".extern D_L09_001DE720_003B6D38, 4");
extern f32 D_L09_001DE724;
__asm__(".extern D_L09_001DE724, 4");
extern f32 D_L09_001DE728;
__asm__(".extern D_L09_001DE728, 4");
extern f32 D_L09_001DE72C;
__asm__(".extern D_L09_001DE72C, 4");

extern s32 func_0037E0F0(void *, s32, s32);
extern s32 func_0037E1D8(s32);
extern s32 func_0037E208(s32, s32);
extern f32 func_0037E250(f32, f32);
extern f32 func_0037E2A8(void);
extern s32 func_003883C8(void *);
extern f32 func_00388730(void *, void *);
extern f32 func_00388800(void *, void *);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern f32 func_00388A28(f32, f32);
extern f32 func_00389380(f32, f32);
extern f32 func_003893C8(f32, f32);
extern void func_00399F90(void);
extern void func_0039FB08(s32);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_003BD360(void *);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_003BEA80(void *, void *);
extern void func_003BEB58(void *, void *, void *, f32);
extern void func_003C26C8(void *);
extern void func_L01_003E9588(s32, void *, void *, s32, s32, s32);
extern void func_L01_003EAB30(s32);
extern s32 func_L01_003EAB60(s32);
extern void func_L01_00417F60(s32, s32);
extern f32 func_L01_00436500(void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_00442038(void *, s32);
extern void func_L01_00442050(u8 *, u8);
extern f32 func_L01_00445758(void *, f32, void *, f32, f32, f32, s32);
extern s32 func_L01_0044AF40(void *, f32);
extern s32 func_L01_00451078(void *, void *);
extern s32 func_L01_00452EC8(void *);
extern s32 func_L01_00452EF0(void *);
extern s32 func_L01_00452F18(void *);
extern s32 func_L01_00453210(void *, s32);
extern s32 func_L01_00457440(void *, void *);
extern void func_L01_004576E8(void *);
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern s32 func_L01_00458B30(void *, void *);
extern void func_L01_00458E48(void *, void *, s32, s32);
extern void func_L01_004A6D70(s32, void *);
extern void func_L01_004A6DF8(void *, s32);
extern void func_L01_004F12C0(void *, void *, s32, s32);
extern void func_L01_0050DA68(void *, s32, f32);
extern void func_L01_0050DB10(void);
extern void func_L02_0039E460(void *);
extern void func_L02_0039E538(u8 *a0, s32 a1);
extern void func_L02_003C3A40(s32);
extern s32 func_L08_003CE910(s32);
extern s32 func_L09_003BA698(u8 *);
extern void func_L09_003BAA10(u8 *);
extern void func_L09_003BABD8(u8 *, s32, s32, s32, s32);
extern s32 func_L09_003BBFE8(void *);
extern void func_L09_003BC318(void *, void *, s32, void *);
extern void func_L09_003BC658(void *);
extern void func_L09_003BC8F0(void *);
extern void func_L09_003BC9B0(void *);
extern s32 func_L09_003BCAB8(void *, void *);
extern s32 func_L09_003BCBD8(void *);
extern void func_L09_003BCD58(void *, s32, s32, s32, s32);
extern void func_L09_003BD098(void *, s32, s32);
extern s32 func_L09_003BD2B0(void *, void *, s32, void *);
extern void func_L09_003BD3A0(void *, void *, s32, void *, s32);
extern s32 func_L09_003BD490(void *);
extern s32 func_L09_003BD7B8(void *, void *, s32, void *, s32);
extern void func_L09_003BD860_003B6D38(void *, void *, s32, void *, void *, void *, s32);
extern void func_L09_003BDB60(void *);
extern void func_L09_003BDD70(void *);
extern void func_L09_003BE010(void *);
extern s32 func_L09_003BE138(void *);
extern void func_L09_003BE1C8(void *);
extern void func_L09_003BE400(void *, s32, f32, f32);
extern s32 func_L09_003CBEE8(void *, s32);
extern s32 func_L09_003CBF40(void *);
extern void func_L09_003CBF80(void *);
extern void func_L09_00401D28(s32, s32);

void func_L09_003B6D38(Moby_T *s) {
    VI_T a;
    VI_T b;
    VI_T c;
    VI_T d;
    VI_T e;
    VI_T f;
    VI_T g;
    Pv_T *v;
    Moby_T *bm;

    if (func_L09_003BA698((u8 *)s)) {
        return;
    }
    v = s->pv;
    bm = &((Moby_T *)D_L09_001E011C)[v->iCD0];
    switch (s->b095) {
    case 0:
        if (func_L01_00452EF0(s)) {
            {
                u16 *lp;
                Moby_T *m;

                lp = D_L09_0021CE20[v->iD28];
                while ((v->iD28 & 0xFF) != 0xFF && D_L09_001E0158 >= v->iD28 && lp != 0 &&
                       ((s16)lp[-1] >= 0 || lp == D_L09_0021CE20[v->iD28])) {
                    m = &((Moby_T *)D_L09_001E011C)[*lp & 0x7FFF];
                    if (m == 0) {
                        break;
                    }
                    func_L02_0039E538((u8 *)m, 0);
                    lp++;
                }
            }
            v->f12C = 1.5f;
            s->pos.z = 340.0f;
            func_L09_003CBEE8(&((Moby_T *)D_L09_001E011C)[v->iCF0], 1);
            func_L09_003CBEE8(&((Moby_T *)D_L09_001E011C)[v->iCE8], 1);
            s->H034 |= 0x41;
            {
                u16 *lp;
                Moby_T *m;

                lp = D_L09_0021CE20[v->iD20];
                while ((v->iD20 & 0xFF) != 0xFF && D_L09_001E0158 >= v->iD20 && lp != 0 &&
                       ((s16)lp[-1] >= 0 || lp == D_L09_0021CE20[v->iD20])) {
                    m = &((Moby_T *)D_L09_001E011C)[*lp & 0x7FFF];
                    if (m == 0) {
                        break;
                    }
                    m->i098 = 0;
                    lp++;
                    m->H034 = (m->H034 | 0x41) & 0xEFFF;
                    func_L01_004A6DF8(m, 1);
                    m->H034 |= 2;
                }
            }
            ((Hero_T *)D_001A4BE0)->i2850 = D_00142660[2];
            func_L01_00441FB8(s, 2, -1);
            func_L01_00442050((u8 *)s, 0);
        }
        break;
    case 1: {
        s32 t0 = 3;
        s32 t1 = 4;

        if (func_L01_00452EF0(s)) {
            v->bD42 &= 0xFE;
            v->fD4C = 0.85f;
            func_L01_00441FB8(s, 0xD, -1);
            func_L01_00442050((u8 *)s, 1);
        } else if (s->b020 == 0xD && (v->bD42 & 2)) {
            if (func_L09_003BD2B0(s, v->xC80, 5, D_L09_002BB2B0)) {
                func_L01_00441FB8(s, 0xE, -1);
                func_L01_00442050((u8 *)s, 1);
            }
        } else if (s->b020 == 0xC && (v->bD42 & 2)) {
            func_L09_003BD3A0(s, v->xC80, 5, D_L09_002BB2B0, 1);
            func_L01_00441FB8(s, 0x10, -1);
            func_L01_00442050((u8 *)s, 1);
        } else if (!func_L09_003BD490(s) && !func_L09_003BD7B8(s, v->xC80, 5, D_L09_002BB2B0, 6)) {
            func_L09_003BD860_003B6D38(s, v->xC80, 5, D_L09_002BB2B0, &t0, &t1, 1);
        }
        if (func_003883C8(&v->hD30) ||
            (D_001A73E8[0] != 0 && (D_001A73E8[0]->hAA == 0x19DF || D_001A73E8[0]->hAA == 0x1B33)) ||
            func_L09_003BBFE8(s)) {
            v->bD42 |= 1;
        }
        if (func_L09_003BBFE8(s)) {
            func_L01_00442038(s, 2);
            v->fD4C = 0.65f;
        }
        break;
    }
    case 2: {
        s32 t0 = 3;
        s32 t1 = 4;

        if (func_L01_00452EF0(s)) {
            v->bD42 &= 0xFE;
        } else if (s->b020 == 0xD && (v->bD42 & 2)) {
            if (func_L09_003BD2B0(s, v->xC80, 5, D_L09_002BB2B0)) {
                func_L01_00441FB8(s, 0xF, -1);
                func_L01_00442050((u8 *)s, 1);
            }
        } else if (s->b020 == 0xC && (v->bD42 & 2)) {
            func_L09_003BD3A0(s, v->xC80, 5, D_L09_002BB2B0, 1);
            func_L01_00441FB8(s, 0x10, -1);
            func_L01_00442050((u8 *)s, 1);
        } else if (!func_L09_003BD490(s) && !func_L09_003BD7B8(s, v->xC80, 5, D_L09_002BB2B0, 5)) {
            func_L09_003BD860_003B6D38(s, v->xC80, 5, D_L09_002BB2B0, &t0, &t1, 1);
        }
        if (s->bBC != 5 &&
            (func_003883C8(&v->hD30) ||
             (D_001A73E8[0] != 0 && (D_001A73E8[0]->hAA == 0x19DF || D_001A73E8[0]->hAA == 0x1B33)) ||
             func_L09_003BBFE8(s))) {
            v->bD42 |= 1;
        }
        if (func_L09_003BBFE8(s)) {
            func_L01_00442038(s, 3);
            v->fD4C = 0.5f;
        }
        break;
    }
    case 3: {
        s32 t0 = 3;
        s32 t1 = 4;

        if (func_L01_00452EF0(s)) {
            v->bD42 &= 0xFE;
        } else if (s->b020 == 0xD && (v->bD42 & 2)) {
            if (func_L09_003BD2B0(s, v->xC80, 5, D_L09_002BB2B0)) {
                func_L01_00441FB8(s, 0xF, -1);
                func_L01_00442050((u8 *)s, 1);
            }
        } else if (s->b020 == 0xC && (v->bD42 & 2)) {
            func_L09_003BD3A0(s, v->xC80, 5, D_L09_002BB2B0, 1);
            func_L01_00441FB8(s, 0x10, -1);
            func_L01_00442050((u8 *)s, 1);
        } else if (!func_L09_003BD490(s) && !func_L09_003BD7B8(s, v->xC80, 5, D_L09_002BB2B0, 4)) {
            func_L09_003BD860_003B6D38(s, v->xC80, 5, D_L09_002BB2B0, &t0, &t1, 1);
        }
        if (s->bBC != 5 &&
            (func_003883C8(&v->hD30) ||
             (D_001A73E8[0] != 0 && (D_001A73E8[0]->hAA == 0x19DF || D_001A73E8[0]->hAA == 0x1B33)) ||
             func_L09_003BBFE8(s))) {
            v->bD42 |= 1;
        }
        if (func_L09_003BBFE8(s) && ((Hero_T *)D_001A4BE0)->i2850 > 0 && ((Hero_T *)D_001A4BE0)->i25C4 != 0x6A && ((Hero_T *)D_001A4BE0)->i25C4 != 0x7D) {
            func_L01_00441FB8(s, 1, 4);
            func_L01_00442050((u8 *)s, 0);
        }
        break;
    }
    case 4:
        if (func_L01_00452EF0(s)) {
            if (v->hD5A != -1) {
                func_0039FB08(v->hD5A);
                v->hD5A = -1;
            }
            func_L01_00441FB8(s, 5, -1);
            func_L01_00442050((u8 *)s, 1);
        } else if (s->b020 == 5 && func_L01_003EAB60(v->iD00)) {
            v->bD42 &= 0xFE;
            func_L01_00441FB8(s, 6, -1);
            func_L01_00442050((u8 *)s, 1);
        } else if (s->b020 == 6 && s->bBC == 0xB && func_L01_003EAB60(v->iD04)) {
            v->bD42 &= 0xFE;
            func_L01_00441FB8(s, 7, -1);
            func_L01_00442050((u8 *)s, 1);
        } else if (s->b020 == 7 && func_L01_003EAB60(v->iD08)) {
            func_L01_0050DB10();
            v->bD42 &= 0xFE;
            func_L01_00441FB8(s, 0x14, -1);
            func_L01_00442050((u8 *)s, 1);
        } else if (s->b020 == 0x14 && ((v->bD42 & 2) || func_0037E0F0(D_001A4C60, v->iD14, 0))) {
            func_L01_004A6D70(8, s);
            func_L01_00441FB8(s, 8, -1);
            func_L01_00442050((u8 *)s, 1);
        } else if (s->b020 == 8 && func_L01_003EAB60(v->iD18)) {
            Rec80_T *r;

            {
                u16 *lp;
                Moby_T *m;

                lp = D_L09_0021CE20[v->iD50];
                while ((v->iD50 & 0xFF) != 0xFF && D_L09_001E0158 >= v->iD50 && lp != 0 &&
                       ((s16)lp[-1] >= 0 || lp == D_L09_0021CE20[v->iD50])) {
                    m = &((Moby_T *)D_L09_001E011C)[*lp & 0x7FFF];
                    if (m == 0) {
                        break;
                    }
                    m->i098 = 0;
                    lp++;
                    m->H034 = (m->H034 | 0x41) & 0xEFFF;
                    func_L01_004A6DF8(m, 1);
                    m->i098 = 0;
                    m->H034 |= 2;
                }
            }
            r = (Rec80_T *)((u8 *)D_L09_001E0200 + (v->iD1C << 7));
            func_L01_0050DB10();
            func_L01_004F12C0(&r->v30, &r->v70, 0, 0);
            func_L01_00441FB8(s, 1, 5);
            func_L01_00442050((u8 *)s, 0);
            v->fD4C = 0.35f;
        }
        break;
    case 5: {
        a.i = *(I2_T *)D_L09_001DE788;
        b.i = *(I2_T *)D_L09_001DE790;

        if (func_L01_00452EF0(s)) {
            v->bD42 &= 0xFE;
            func_L01_00441FB8(s, 0xD, -1);
            func_L01_00442050((u8 *)s, 1);
        } else if (s->b020 == 0xD && (v->bD42 & 2)) {
            if (func_L09_003BD2B0(s, v->xC9C, 10, D_L09_002BB300)) {
                func_L01_00441FB8(s, 0xF, -1);
                func_L01_00442050((u8 *)s, 1);
            }
        } else if (s->b020 == 0xC && (v->bD42 & 2)) {
            func_L09_003BD3A0(s, v->xC9C, 10, D_L09_002BB300, 1);
            func_L01_00441FB8(s, 0x10, -1);
            func_L01_00442050((u8 *)s, 1);
        } else if (!func_L09_003BD490(s) && !func_L09_003BD7B8(s, v->xC9C, 10, D_L09_002BB300, 3)) {
            func_L09_003BD860_003B6D38(s, v->xC9C, 10, D_L09_002BB300, &a.i, &b.i, 2);
        }
        if (s->bBC != 6 &&
            (func_003883C8(&v->hD30) ||
             (D_001A73E8[0] != 0 &&
              (D_001A73E8[0]->hAA == 0x19DF || D_001A73E8[0]->hAA == 0x1B33 || D_001A73E8[0]->hAA == 0x1C0C)) ||
             func_L09_003BBFE8(s))) {
            v->bD42 |= 1;
        }
        if (func_L09_003BBFE8(s)) {
            func_L01_00442038(s, 6);
            v->fD4C = 0.15f;
        }
        break;
    }
    case 6: {
        a.i = *(I2_T *)D_L09_001DE788;
        c.i = *(I2_T *)D_L09_001DE790;

        if (func_L01_00452EF0(s)) {
            v->bD42 &= 0xFE;
        } else if (s->b020 == 0xD && (v->bD42 & 2)) {
            if (func_L09_003BD2B0(s, v->xC9C, 10, D_L09_002BB300)) {
                func_L01_00441FB8(s, 0xF, -1);
                func_L01_00442050((u8 *)s, 1);
            }
        } else if (s->b020 == 0xC && (v->bD42 & 2)) {
            func_L09_003BD3A0(s, v->xC9C, 10, D_L09_002BB300, 1);
            func_L01_00441FB8(s, 0x10, -1);
            func_L01_00442050((u8 *)s, 1);
        } else if (!func_L09_003BD490(s) && !func_L09_003BD7B8(s, v->xC9C, 10, D_L09_002BB300, 2)) {
            func_L09_003BD860_003B6D38(s, v->xC9C, 10, D_L09_002BB300, &a.i, &c.i, 2);
        }
        if (s->bBC != 6 &&
            (func_003883C8(&v->hD30) ||
             (D_001A73E8[0] != 0 &&
              (D_001A73E8[0]->hAA == 0x19DF || D_001A73E8[0]->hAA == 0x1B33 || D_001A73E8[0]->hAA == 0x1C0C)) ||
             func_L09_003BBFE8(s))) {
            v->bD42 |= 1;
        }
        if (func_L09_003BBFE8(s)) {
            func_L01_00442038(s, 7);
            v->fD4C = 0.0f;
        }
        break;
    }
    case 7: {
        a.i = *(I2_T *)D_L09_001DE788;
        d.i = *(I2_T *)D_L09_001DE790;

        if (func_L01_00452EF0(s)) {
            v->bD42 &= 0xFE;
        } else if (s->b020 == 0xD && (v->bD42 & 2)) {
            func_L09_003BABD8((u8 *)s, (s32)v->xC9C, 10, (s32)D_L09_002BB300, 0);
            v->hD38 = func_0037E208(5, 10) * 60.0f;
            v->hD30 = func_0037E208(15, 25) * 60.0f;
            v->hD34 = 0;
            v->bD40 = 0;
            if (((Ctl_T *)D_L09_001E2C00)->m144 == bm) {
                ((Ctl_T *)D_L09_001E2C00)->m144 = 0;
            }
            if (((Ctl_T *)D_L09_001E2C00)->m144 == 0) {
                ((Ctl_T *)D_L09_001E2C00)->m144 = s;
                ((Ctl_T *)D_L09_001E2C00)->i148 = 0;
            }
            func_L01_00441FB8(s, 0xE, -1);
            func_L01_00442050((u8 *)s, 1);
        } else if (s->b020 == 0xC && (v->bD42 & 2)) {
            func_L09_003BD3A0(s, v->xC9C, 10, D_L09_002BB300, 1);
            func_L01_00441FB8(s, 0x10, -1);
            func_L01_00442050((u8 *)s, 1);
        } else if (!func_L09_003BD7B8(s, v->xC9C, 10, D_L09_002BB300, 1)) {
            func_L09_003BD860_003B6D38(s, v->xC9C, 10, D_L09_002BB300, &a.i, &d.i, 2);
        }
        if (s->bBC != 6 &&
            (func_003883C8(&v->hD30) ||
             (D_001A73E8[0] != 0 &&
              (D_001A73E8[0]->hAA == 0x19DF || D_001A73E8[0]->hAA == 0x1B33 || D_001A73E8[0]->hAA == 0x1C0C)) ||
             func_L09_003BBFE8(s))) {
            v->bD42 |= 1;
        }
        break;
    }
    case 9:
        if (func_L01_00452EF0(s)) {
            if (v->bD40 == 0) {
                func_003BE4F0(s, 4, 0, 5);
            } else {
                func_003BE4F0(s, 5, 0, 5);
            }
            func_003BE4F0(bm, 0, 0, 5);
        }
        s->bBC = 0;
        s->b020 = 1;
        if (D_00142C38[0] & 0x01000000) {
            func_L09_003CBF80(&((Moby_T *)D_L09_001E011C)[v->iCE0]);
            func_L09_003CBF80(&((Moby_T *)D_L09_001E011C)[v->iCE4]);
            func_L09_003CBF40(&((Moby_T *)D_L09_001E011C)[v->iCE0]);
            {
                u16 *lp;
                Moby_T *m;

                lp = D_L09_0021CE20[v->iD28];
                while ((v->iD28 & 0xFF) != 0xFF && D_L09_001E0158 >= v->iD28 && lp != 0 &&
                       ((s16)lp[-1] >= 0 || lp == D_L09_0021CE20[v->iD28])) {
                    m = &((Moby_T *)D_L09_001E011C)[*lp & 0x7FFF];
                    if (m == 0) {
                        break;
                    }
                    lp++;
                    func_L02_0039E460(m);
                    m->i098 = 0;
                    m->H034 = (m->H034 | 0x41) & 0xEFFF;
                    func_L01_004A6DF8(m, 1);
                }
            }
            func_003BD360(s);
            return;
        }
        break;
    }

    v->bD42 &= 0xF9;
    switch (s->b020) {
    case 2:
        if (v->iCD4 != -1 && func_L01_00453210(D_001A4C60, v->iCD4)) {
            s32 i;

            if (D_001426E0[0x3C] & 1) {
                func_L01_003EAB30(v->iCF4);
                func_L01_00441FB8(s, 3, -1);
            } else {
                func_L02_003C3A40(v->iCF8);
                func_L01_003EAB30(v->iCF8);
                func_L01_00441FB8(s, 4, -1);
            }
            for (i = 0; i < 7; i++) {
                if ((u32)i < 8 && ((D_001426E0[0x3C] >> i) & 1)) {
                    D_001426E0[0x3C] &= ~(1 << i);
                    func_00399F90();
                    if ((u32)(i + 1) < 8) {
                        D_001426E0[0x3C] |= 1 << (i + 1);
                    }
                    func_00399F90();
                    break;
                }
            }
        }
        break;
    case 3:
        if (((s->bBE ^ 1) & 1) && func_L08_003CE910(v->iCF4)) {
            Rec80_T *r = (Rec80_T *)((u8 *)D_L09_001E0200 + (v->iCFC << 7));

            func_L01_004F12C0(&r->v30, &r->v70, 0x74, 0);
            func_0039FE80(8, 4, s);
            func_L01_00452EC8(s);
        } else if (func_L01_003EAB60(v->iCF4)) {
            func_L09_003CBF40(&((Moby_T *)D_L09_001E011C)[v->iCF0]);
            func_L09_003CBF40(&((Moby_T *)D_L09_001E011C)[v->iCE8]);
            s->H034 &= 0xFFBE;
            func_L01_004A6D70(8, s);
            if (((Ctl_T *)D_L09_001E2C00)->m144 == 0) {
                ((Ctl_T *)D_L09_001E2C00)->m144 = s;
                ((Ctl_T *)D_L09_001E2C00)->i148 = 0;
            }
            func_L01_00441FB8(s, 1, 1);
            func_L01_00442050((u8 *)s, 0);
        }
        break;
    case 4:
        if (func_L08_003CE910(v->iCF8)) {
            Rec80_T *r;

            func_L09_003CBF40(&((Moby_T *)D_L09_001E011C)[v->iCF0]);
            func_L09_003CBF40(&((Moby_T *)D_L09_001E011C)[v->iCE8]);
            s->H034 &= 0xFFBE;
            if (((Ctl_T *)D_L09_001E2C00)->m144 == 0) {
                ((Ctl_T *)D_L09_001E2C00)->m144 = s;
                ((Ctl_T *)D_L09_001E2C00)->i148 = 0;
            }
            r = (Rec80_T *)((u8 *)D_L09_001E0200 + (v->iCFC << 7));
            func_L01_004F12C0(&r->v30, &r->v70, 0x74, 0);
            func_L01_00441FB8(s, 1, 1);
            func_L01_00442050((u8 *)s, 0);
        }
        break;
    case 5:
        if (func_L01_00452EC8(s)) {
            v->bD42 &= 0xFE;
            func_L02_003C3A40(v->iD00);
            func_L01_003EAB30(v->iD00);
            v->hD36 = 0x3C;
            v->fD4C = 0.5f;
        } else if (func_003883C8(&v->hD36)) {
            func_L09_003CBEE8(&((Moby_T *)D_L09_001E011C)[v->iCE8], 0);
            func_L09_003CBEE8(&((Moby_T *)D_L09_001E011C)[v->iCEC], 0);
        } else if (((v->bD42 ^ 1) & 1) && func_L08_003CE910(v->iD00)) {
            Rec80_T *r;

            func_L01_004A6DF8(s, 1);
            r = (Rec80_T *)((u8 *)D_L09_001E0200 + (v->iD0C << 7));
            func_L01_004F12C0(&r->v30, &r->v70, 0x74, 0);
            r = (Rec80_T *)((u8 *)D_L09_001E0200 + (v->iD10 << 7));
            s->pos = r->v30;
            s->vF0 = r->v70;
            func_003BE4F0(s, 8, 0, 0);
            v->bD41 = 0;
            v->fC30 = 0.0f;
            v->bD40 = 1;
            func_003BEA80(v->xC50, &D_L09_001D66B0_003B6D38);
            {
                u16 *lp;
                Moby_T *m;

                lp = D_L09_0021CE20[v->iD20];
                while ((v->iD20 & 0xFF) != 0xFF && D_L09_001E0158 >= v->iD20 && lp != 0 &&
                       ((s16)lp[-1] >= 0 || lp == D_L09_0021CE20[v->iD20])) {
                    m = &((Moby_T *)D_L09_001E011C)[*lp & 0x7FFF];
                    lp++;
                    if (m == 0) {
                        break;
                    }
                    m->H034 &= 0xFFBE;
                    m->H034 |= m->cls->H044 & 0x1000;
                    m->i098 = m->cls->i010;
                    m->H034 &= 0xFFFD;
                }
            }
            v->bD42 |= 1;
        }
        break;
    case 6:
        if (func_L01_00452EC8(s)) {
            func_003BE4F0(s, 8, 0, 0);
        } else if (s->bBC == 1) {
            v->fBE8 = 1.5707964f;
            if (func_003883C8(&v->hD36)) {
                v->hD36 = 0xB4;
                func_L01_00442050((u8 *)s, 0xB);
            }
        }
        break;
    case 7:
        if (func_L01_00452EC8(s)) {
            bm->vF0.z = 0.0f;
            func_L01_0050DA68(&D_L09_001DE710_003B6D38, 0, -3.1400917f);
            v->fC30 = 0.0f;
            func_003BEA80(v->xC50, &D_L09_001D66B0_003B6D38);
            v->hD34 = 0x1AE;
            v->hD36 = 0x14;
            v->hD30 = 0x3E;
            v->bD42 |= 1;
        }
        func_L09_003BCD58(s, 0, 0, 0, 1);
        D_001A4E18[0] = 3;
        break;
    case 8:
        if (func_L01_00452EC8(s)) {
            v->bD42 &= 0xFE;
            func_L02_003C3A40(v->iD18);
            func_L01_003EAB30(v->iD18);
        } else if (((v->bD42 ^ 1) & 1) && func_L08_003CE910(v->iD18)) {
            Rec80_T *r;
            PathEnt_T *pa;

            bm->vF0.z = 0.0f;
            func_L09_003CBF40(&((Moby_T *)D_L09_001E011C)[v->iCEC]);
            r = (Rec80_T *)((u8 *)D_L09_001E0200 + (v->iD14 << 7));
            func_L01_004F12C0(&r->v30, &r->v70, 0, 0);
            r = (Rec80_T *)((u8 *)D_L09_001E0200 + (v->iD1C << 7));
            func_L01_0050DA68(&r->v30, 0, r->v70.z);
            pa = (PathEnt_T *)D_L09_0021E6C0[v->iC98];
            s->pos = pa[pa[0].n].v;
            s->vF0.z = 4.712389f;
            v->hD34 = 0x2D;
            s->H034 &= 0xFFBE;
            v->cD2C = 1;
            v->fCDC = 0.0f;
            {
                u16 *lp;
                Moby_T *m;

                lp = D_L09_0021CE20[v->iD20];
                while ((v->iD20 & 0xFF) != 0xFF && D_L09_001E0158 >= v->iD20 && lp != 0 &&
                       ((s16)lp[-1] >= 0 || lp == D_L09_0021CE20[v->iD20])) {
                    m = &((Moby_T *)D_L09_001E011C)[*lp & 0x7FFF];
                    if (m == 0) {
                        break;
                    }
                    m->i098 = 0;
                    lp++;
                    m->H034 = (m->H034 | 0x41) & 0xEFFF;
                    func_L01_004A6DF8(m, 1);
                    m->H034 |= 2;
                }
            }
            v->P254 = 0;
            func_003BE4F0(s, 8, 0, 0);
            v->fC30 = 0.0f;
            func_003BEA80(v->xC50, &D_L09_001D66B0_003B6D38);
            v->bD42 |= 1;
        } else if ((v->bD42 & 1) && s->bBC == 1) {

            v->fBE8 = 0.43633232f;
            a.v = D_L09_001D66B0_003B6D38;
            a.v.y = -0.017453292f;
            a.v.x = v->fCDC;
            {
                f32 t = func_003893C8(s->vF0.z, 1.701696f);

                func_L01_00445758(&a.v, func_003893C8(func_00388A28(((Hero_T *)D_001A4BE0)->f080 - bm->pos.x, ((Hero_T *)D_001A4BE0)->f084 - bm->pos.y), t),
                              v->xCD8, 0.0034906587097793818f, 0.0034906587097793818f, 0.41887906193733215f, 0);
            }
            v->fCDC = a.v.x;
            func_003BEA80(v->xC50, &a.v);
            ((Hero_T *)D_001A4BE0)->i238 = 3;
            if (func_003883C8(&v->hD34)) {
                func_L01_00442050((u8 *)s, 0xC);
            }
        }
        break;
    case 9:
        if (func_L01_00452EC8(s) || (s->b060 & 2)) {
            func_003BE4F0(s, 0, 0, 10);
            s->f048 = 1.0f;
            if (s->b060 & 2) {
                v->bD42 |= 2;
            }
        }
        break;
    case 10:
        if (func_L01_00452EC8(s) || (s->b060 & 2)) {
            func_003BE4F0(s, 8, 0, 10);
            s->f048 = 0.5f;
            if (s->b060 & 2) {
                v->bD42 |= 2;
            }
        }
        break;
    case 11:
        if (func_L01_00452EC8(s)) {
            func_003BE4F0(s, 1, 0, 10);
            s->f048 = 1.0f;
        }
        func_L01_004576E8(s);
        if (func_L01_0044AF40(s, 15.0f)) {
            func_0039FE80(1, 4, s);
        }
        if (s->b060 & 2) {
            func_L01_004A6D70(1, s);
            v->bD42 |= 2;
        }
    case 12:
        if (func_L01_00452EC8(s)) {
            func_003BE4F0(s, 1, 0, 10);
            s->f048 = 1.0f;
        }
        if (s->b043 == 1) {
            func_L01_004576E8(s);
            if (func_L01_0044AF40(s, 15.0f)) {
                func_0039FE80(1, 4, s);
            }
            if (s->b060 & 2) {
                v->i1C8 &= ~0x404;
                func_L01_004A6D70(1, s);
                func_003BE4F0(s, 0xA, 0, 10);
                s->f048 = 1.0f;
            }
        } else if (s->b043 == 0xA) {
            f32 t = func_L01_00436500(s);

            if (t >= 14.0f && t <= 22.0f) {
                s->pos.z += 0.5f;
            }
            if (s->b060 & 2) {
                func_003BE4F0(s, 8, 0, 0);
                s->pos.z = 340.0f;
                v->bD42 |= 2;
            }
        }
        break;
    case 13:
        if (func_L01_00452EC8(s)) {
            v->i1C8 &= ~0x404;
            s->pos.z = 340.0f;
            func_003BE4F0(s, 6, 0, 10);
            s->f048 = 1.0f;
        }
        if (s->b043 == 6) {
            f32 t = func_L01_00436500(s);

            if (t >= 9.0f && t <= 17.0f) {
                s->pos.z -= 0.5f;
            }
            func_L09_003BE1C8(s);
            func_L09_003BC9B0(s);
            if (s->b060 & 2) {
                func_003BE4F0(s, 1, 0, 10);
                s->f048 = 1.0f;
            }
        } else if (s->b043 == 1) {
            func_L01_004576E8(s);
            if (func_L01_0044AF40(s, 15.0f)) {
                func_0039FE80(1, 4, s);
            }
            if (s->b060 & 2) {
                func_L01_004A6D70(1, s);
                v->bD42 |= 2;
            }
        }
        break;
    case 14:
        if (func_L01_00452EC8(s)) {
            v->i1C8 &= ~0x404;
            func_L01_00458A70(s, 0.004861111287027597f, 0.09166666865348816f, 0.0034906587097793818f, 0.03490658849477768f);
            v->f1B4 = 1.0f;
            func_003BE4F0(s, 2, 0, 10);
            s->f048 = 1.0f;
        }
        func_L09_003BC8F0(s);
        func_L09_003BE400(s, 0, D_L09_001DE724, D_L09_001DE720_003B6D38);
        v->f1C4 = 4.0f;
        if (func_L01_00458B30(s, v->P254)) {
            v->bD42 |= 2;
        }
        v->f1C4 = 1.0f;
        break;
    case 15:
        if (func_L01_00452EC8(s)) {
            v->i1C8 &= ~0x404;
            func_L01_00458A70(s, 0.009999999776482582f, 0.20000001788139343f, 0.0069813174195587635f, 0.06981317698955536f);
            v->f1B4 = 1.0f;
            func_003BE4F0(s, 3, 0, 10);
            s->f048 = 1.0f;
        }
        func_L09_003BC8F0(s);
        func_L09_003BE400(s, 1, D_L09_001DE72C, D_L09_001DE728);
        v->f1C4 = 4.0f;
        if (func_L01_00458B30(s, v->P254)) {
            v->bD42 |= 2;
        }
        v->f1C4 = 1.0f;
        break;
    case 16:
        if (func_L01_00452EC8(s)) {
            v->i1C8 |= 0x404;
            func_L01_00458A70(s, 0.015000000596046448f, 0.30000001192092896f, 0.0034906587097793818f, 0.03490658849477768f);
            v->f1B4 = 1.0f;
            func_003BE4F0(s, 7, 0, 10);
            s->f048 = 1.0f;
        }
        v->f1C4 = 4.0f;
        if (func_L01_00458B30(s, v->P254)) {
            v->bD42 |= 2;
        }
        v->f1C4 = 1.0f;
        break;
    case 17:
        if (func_L01_00452EC8(s)) {
            v->i1C8 |= 0x404;
            func_L01_00458A70(s, 0.015000000596046448f, 0.30000001192092896f, 0.0034906587097793818f, 0.03490658849477768f);
            v->f1B4 = 1.0f;
            func_003BE4F0(s, 7, 0, 10);
            s->f048 = 1.0f;
        }
        if (v->P254 != 0) {
            v->f1C4 = 4.0f;
            if (func_L01_00458B30(s, v->P254)) {
                v->bD42 |= 2;
            }
            v->f1C4 = 1.0f;
        } else if (v->bD41 != 2) {

            a.v.x = v->fCC8;
            a.v.y = v->fCCC;
            a.v.z = 340.0f;
            a.v.w = 0.0f;
            if (func_L01_00457440(s, &a.v)) {
                v->bD42 |= 2;
            }
        }
        break;
    case 18: {

        if (func_L01_00452EC8(s)) {
            v->i1C8 |= 0x404;
            func_L01_00458A70(s, 0.015000000596046448f, 0.30000001192092896f, 0.0034906587097793818f, 0.03490658849477768f);
            v->f1B4 = 1.0f;
            func_003BE4F0(s, 7, 0, 10);
            s->f048 = 1.0f;
            v->fCC8 = s->pos.x;
            v->fCCC = s->pos.y;
        }
        a.v.x = v->fCC8;
        a.v.y = v->fCCC;
        a.v.z = 340.0f;
        a.v.w = 0.0f;
        if (func_00388800(&s->pos, &a.v) < v->f1C4) {
            f32 ang = func_0037E2A8();
            f32 r = func_0037E250(5.0f, 10.0f);

            a.v.x = func_00388960(ang) * r;
            a.v.y = func_00388978(ang) * r;
            vec_add_ab(&a.v, &a.v, &D_L09_001DE6F0_003B6D38);
            if (!func_L01_00453210(&a.v, v->iD54)) {
                a.v = D_L09_001DE6F0_003B6D38;
            }
            v->fCC8 = a.v.x;
            v->fCCC = a.v.y;
        }
        func_L01_00457440(s, &a.v);
        break;
    }
    case 19:
        if (func_L01_00452EC8(s)) {
            v->i1C8 |= 0x404;
            func_L01_00458A70(s, 0.015000000596046448f, 0.30000001192092896f, 0.0034906587097793818f, 0.03490658849477768f);
            v->f1B4 = 1.0f;
            func_003BE4F0(s, 7, 0, 10);
            s->f048 = 1.0f;
            func_L01_00458E48(s, v->P254, v->h258, v->h258);
            func_L01_00458B30(s, v->P254);
            v->hD36 = 10;
            v->fD3C = 0.1f;
        }
        if (v->f25C > v->f1C4) {
            func_L01_00458B30(s, v->P254);
        } else if (!func_003883C8(&v->hD36)) {
            f32 t = (f32)v->hD36 * v->fD3C;

            a.v = v->P254[v->h25A + 1].v;
            b.v = s->pos;
            func_003BEB58(&s->pos, &a.v, &b.v, t);
        } else {
            v->bD42 |= 2;
        }
        break;
    case 20:
        if (func_L01_00452EC8(s)) {
            PathEnt_T *pa;

            s->b023 = 0x80;
            pa = (PathEnt_T *)D_L09_0021E6C0[v->iC98];
            func_L01_00458E48(s, pa, pa[0].n - 1, 0);
            func_L01_003E9588(0, &s->pos, &s->vF0, 1, 0, 0);
            func_L09_00401D28(0, 1);
            s->H034 |= 0x41;
            v->cD2C = 0;
            v->i1C8 |= 0x404;
            func_L01_00458A70(s, 0.004861111287027597f, 0.09166666865348816f, 0.0034906587097793818f, 0.03490658849477768f);
            v->hD34 = 0x78;
            v->bD2D = 0;
            v->hD30 = 0;
            D_001A7E18.H1248C = 0;
            D_001A7E18.H12498 = 0;
            D_001A7E18.H12480 = 0;
            func_0039FE80(1, 4, s);
            v->hD5A = -1;
            v->vD60 = s->vF0;
        }
        ((Hero_T *)D_001A4BE0)->i238 = 3;
        func_L09_003BDD70(s);
        func_L09_003BE010(s);
        if (s->bBC != 0xA) {
            func_L01_00442050((u8 *)s, 0xA);
        }
        if (func_003883C8(&v->hD34) && v->hD5A == -1) {
            func_L01_004A6D70(1, s);
            v->hD5A = func_0039FE80(8, 4, s);
        }
        if (((Hero_T *)D_001A4BE0)->f080 > 265.0f && func_003883C8(&v->hD30)) {
            if (D_001A7E18.H1248C == 0) {
                if (!(D_001A7E18.i1040 & (1 << D_001D545C))) {
                    func_L01_00417F60(0x1861, 0x15A);
                }
            } else if (D_001A7E18.H12498 == 0) {
                if (!(D_001A7E18.i104C & (1 << D_001D545C))) {
                    func_L01_00417F60(0x1862, 0x15B);
                }
            } else if (D_001A7E18.H12480 == 0 && !(D_001A7E18.i1034 & (1 << D_001D545C))) {
                func_L01_00417F60(0x1860, 0x159);
            }
            v->hD30 = 0xB4;
        }
        if (func_L01_00458B30(s, v->P254)) {
            v->bD42 |= 2;
        }
        break;
    case 21: {
        s32 n;
        f32 t;

        if (func_L01_00452EC8(s)) {
            v->i1C8 &= ~0x404;
            func_L01_00458A70(s, 0.005833333358168602f, 0.11666667461395264f, 0.0034906587097793818f, 0.03490658849477768f);
            v->f1B4 = 1.0f;
            func_003BE4F0(s, 9, 0, 10);
            s->f048 = 0.75f;
        }
        n = 0;
        t = func_L01_00436500(s);
        v->f1C4 = 4.0f;
        if (t > 0.0f && t < 31.0f) {
            n = func_L01_00458B30(s, v->P254);
            func_L09_003BC8F0(s);
        } else if (t > 31.0f && t < 40.0f) {
            func_L01_004576E8(s);
            func_L09_003BC658(s);
            func_L09_003BC8F0(s);
        } else if (t > 40.0f && t < 54.0f) {
            n = func_L01_00458B30(s, v->P254);
            func_L09_003BC8F0(s);
        } else if (t > 54.0f && t < 71.0f) {
            func_L01_004576E8(s);
            func_L09_003BC658(s);
            func_L09_003BC8F0(s);
        } else if (t > 71.0f) {
            n = func_L01_00458B30(s, v->P254);
            func_L09_003BC8F0(s);
        }
        if (n) {
            u8 *x = s->b095 < 4 ? v->xC80 : v->xC9C;
            u8 *tb = s->b095 < 4 ? D_L09_002BB2B0 : D_L09_002BB300;

            func_L09_003BC318(s, x, s->b095 < 4 ? 5 : 10, tb);
        }
        v->f1C4 = 1.0f;
        if (s->b060 & 2) {
            v->bD42 |= 2;
        }
        break;
    }
    case 22: {
        s32 n;

        if (func_L01_00452EC8(s)) {
            v->f12C = 1.5f;
        }
        n = func_L01_00451078(s, v->x0D0);
        if (((n & 1) || v->f030 <= 0.0f) && ((Hero_T *)D_001A4BE0)->i2850 > 0 && ((Hero_T *)D_001A4BE0)->i25C4 != 0x6A && ((Hero_T *)D_001A4BE0)->i25C4 != 0x7D) {
            func_L09_003BAA10((u8 *)s);
        } else if (n & 2) {
            v->f12C = 0.05f;
            func_L01_00441FB8(s, s->b094, -1);
        }
        break;
    }
    case 23: {
        s32 n;

        if (func_L01_00452EC8(s)) {
            v->f12C = 1.5f;
        }
        n = func_L01_00451078(s, v->x0D0);
        if ((n & 1) || v->f030 <= 0.0f) {
            func_L09_003BAA10((u8 *)s);
        } else if (n & 2) {
            v->f12C = 0.05f;
            func_L01_00441FB8(s, s->b094, -1);
        }
        break;
    }
    }

    switch (s->bBC) {
    case 1:
        if (func_L01_00452F18(s) || (bm->b060 & 2)) {
            func_003BE4F0(bm, 0, 0, 5);
        }
        break;
    case 2:
        if (func_L01_00452F18(s) || (bm->b060 & 2)) {
            func_003BE4F0(bm, 0, 0, 5);
        }
        if (func_L09_003BCBD8(s)) {
            v->bD42 |= 4;
            func_L01_00442050((u8 *)s, 1);
        }
        break;
    case 3:
    case 4: {
        Vec_T *p;

        if (func_L01_00452F18(s)) {
            v->hD36 = 3;
            v->bD2E = 0;
            if (v->bD41 == 0) {
                v->fCDC = 0.0f;
            }
            vec_sub_ab(&a.v, &bm->pos, D_001A4C60);
            v->cD2F = func_00388730(&bm->vD0, &a.v) > 0.0f ? -1 : 1;
            func_003BE4F0(bm, 0, 0, 10);
        }
        p = 0;
        if (v->bD41 == 2) {
            a.v = D_L09_001D66B0_003B6D38;
            a.v.y = -0.017453292f;
            a.v.x = v->fCDC;
            {
                f32 t = func_003893C8(s->vF0.z, 1.5707964f);

                func_L01_00445758(&a.v, func_003893C8(func_00388A28(((Hero_T *)D_001A4BE0)->f080 - bm->pos.x, ((Hero_T *)D_001A4BE0)->f084 - bm->pos.y), t),
                              v->xCD8, 0.0034906587097793818f, 0.0034906587097793818f, 0.41887906193733215f, 0);
            }
            p = &a.v;
            v->fCDC = a.v.x;
        }
        if (func_L09_003BCAB8(s, p)) {
            func_L09_003BDB60(s);
            func_L09_003BD098(s, s->bBC == 4, 0);
            v->bD42 |= 4;
        }
        break;
    }
    case 5:
    case 6: {
        Vec_T *p;
        s32 i;
        f32 ang;
        f32 r0;
        f32 r1;
        f32 best;

        if (func_L01_00452F18(s)) {
            v->hD36 = 3;
            v->bD2E = 0;
            if (v->bD41 == 0) {
                v->fCDC = 0.0f;
            }
            func_003BE4F0(bm, 0, 0, 10);
        }
        p = 0;
        if (v->bD41 == 2) {
            a.v = D_L09_001D66B0_003B6D38;
            b.v = s->b095 < 4 ? D_L09_001DE6E0_003B6D38 : D_L09_001DE6F0_003B6D38;
            vec_sub_ab(&e.v, &bm->pos, &b.v);
            f.v.x = v->fCC8;
            f.v.y = v->fCCC;
            f.v.z = 340.0f;
            f.v.w = 0.0f;
            vec_sub_ab(&f.v, &f.v, &b.v);
            best = 0.0f;
            for (i = 0; i < 4; i++) {
                ang = (f32)i * 90.0f * 0.017453292f;
                g.v.x = func_00388960(ang);
                g.v.y = func_00388978(ang);
                g.v.z = 0.0f;
                r0 = func_00388730(&g.v, &e.v);
                r1 = func_00388730(&g.v, &f.v);
                if (r0 > 0.0f && r1 > 0.0f) {
                    best = ang;
                    break;
                }
                if (r0 < 0.0f && r1 < 0.0f) {
                    best = func_00389380((f32)i * 90.0f * 0.017453292f, 3.1415927f);
                    break;
                }
            }
            a.v.y = -0.017453292f;
            a.v.x = v->fCDC;
            func_L01_00445758(&a.v, func_003893C8(s->vF0.z, best), v->xCD8, 0.0034906587097793818f, 0.0034906587097793818f,
                              0.41887906193733215f, 0);
            p = &a.v;
            v->fCDC = a.v.x;
        }
        if (func_L09_003BCAB8(s, p)) {
            func_L09_003BD098(s, s->bBC == 6, 0);
            v->bD42 |= 4;
        }
        break;
    }
    case 7: {

        if (func_L01_00452F18(s)) {
            v->hD36 = 0x2D;
            v->bD2D = 0;
            if (v->bD41 == 0) {
                v->fCDC = 0.0f;
            }
            func_003BE4F0(bm, 0, 0, 10);
        }
        a.v = D_L09_001D66B0_003B6D38;
        a.v.y = -0.017453292f;
        a.v.x = v->fCDC;
        func_L01_00445758(&a.v,
                          func_003893C8(func_00388A28(((Hero_T *)D_001A4BE0)->f080 - bm->pos.x, ((Hero_T *)D_001A4BE0)->f084 - bm->pos.y), s->vF0.z),
                          v->xCD8, 0.0034906587097793818f, 0.0034906587097793818f, 0.41887906193733215f, 0);
        v->fCDC = a.v.x;
        if (func_L09_003BCAB8(s, &a.v)) {
            func_003BEA80(v->xC50, &a.v);
            func_L09_003BCD58(s, 0, 0, 0, 0);
            v->bD42 |= 4;
        }
        break;
    }
    case 8: {
        Vec_T *p;

        if (func_L01_00452F18(s)) {
            v->hD36 = 0x2D;
            v->bD2E = 0;
            if (v->bD41 == 0) {
                v->fCDC = 0.0f;
            }
            vec_sub_ab(&a.v, &bm->pos, D_001A4C60);
            v->cD2F = func_00388730(&bm->vD0, &a.v) > 0.0f ? -1 : 1;
            func_003BE4F0(bm, 0, 0, 10);
        }
        p = 0;
        if (v->bD41 == 2) {
            a.v = D_L09_001D66B0_003B6D38;
            a.v.y = -0.017453292f;
            a.v.x = v->fCDC;
            {
                f32 t = func_003893C8(s->vF0.z, 1.5707964f);

                func_L01_00445758(&a.v, func_003893C8(func_00388A28(((Hero_T *)D_001A4BE0)->f080 - bm->pos.x, ((Hero_T *)D_001A4BE0)->f084 - bm->pos.y), t),
                              v->xCD8, 0.0034906587097793818f, 0.0034906587097793818f, 0.41887906193733215f, 0);
            }
            p = &a.v;
            v->fCDC = a.v.x;
        }
        if (func_L09_003BCAB8(s, p)) {
            func_L09_003BDB60(s);
            func_L09_003BCD58(s, 0, 0, 0, 1);
            v->bD42 |= 4;
        }
        break;
    }
    case 9: {
        Vec_T *p;
        s32 i;
        f32 ang;
        f32 r0;
        f32 r1;
        f32 best;

        if (func_L01_00452F18(s)) {
            v->hD36 = 0x2D;
            if (v->bD41 == 0) {
                v->fCDC = 0.0f;
            }
            func_003BE4F0(bm, 0, 0, 10);
        }
        p = 0;
        if (v->bD41 == 2) {
            a.v = D_L09_001D66B0_003B6D38;
            b.v = s->b095 < 4 ? D_L09_001DE6E0_003B6D38 : D_L09_001DE6F0_003B6D38;
            vec_sub_ab(&c.v, &bm->pos, &b.v);
            d.v.x = v->fCC8;
            d.v.y = v->fCCC;
            d.v.z = 340.0f;
            d.v.w = 0.0f;
            vec_sub_ab(&d.v, &d.v, &b.v);
            best = 0.0f;
            for (i = 0; i < 4; i++) {
                ang = (f32)i * 90.0f * 0.017453292f;
                e.v.x = func_00388960(ang);
                e.v.y = func_00388978(ang);
                e.v.z = 0.0f;
                r0 = func_00388730(&e.v, &c.v);
                r1 = func_00388730(&e.v, &d.v);
                if (r0 > 0.0f && r1 > 0.0f) {
                    best = ang;
                    break;
                }
                if (r0 < 0.0f && r1 < 0.0f) {
                    best = func_00389380((f32)i * 90.0f * 0.017453292f, 3.1415927f);
                    break;
                }
            }
            a.v.y = -0.017453292f;
            a.v.x = v->fCDC;
            func_L01_00445758(&a.v, func_003893C8(s->vF0.z, best), v->xCD8, 0.0034906587097793818f, 0.0034906587097793818f,
                              0.41887906193733215f, 0);
            p = &a.v;
            v->fCDC = a.v.x;
        }
        if (func_L09_003BCAB8(s, p)) {
            func_L09_003BCD58(s, 0, 0, 0, 0);
            v->bD42 |= 4;
        }
        break;
    }
    case 10:
        if (func_L01_00452F18(s)) {
            v->bD2D = 0;
            v->hD36 = 0x2D;
            func_003BE4F0(bm, 4, 0, 0);
        }
        if (v->bD2D >= 2) {
            s32 n = func_L09_003BE138(s);

            if (func_0037E1D8(5) || n) {
                func_L09_003BCD58(s, 0, (n ^ 1) & 0xFF, n, 0);
                break;
            }
        }
        func_L09_003BCD58(s, 0, 0, 0, 1);
        break;
    case 11:
        if (func_L01_00452F18(s)) {
            func_003BE4F0(bm, 0, 0, 10);
        }
        v->fBE8 = 1.5707964f;
        if (func_L01_0044AF40(bm, 1.0f)) {
            func_L09_003BCD58(s, 1, 0, 0, 0);
        } else if (func_L01_0044AF40(bm, 8.0f)) {
            func_003BE4F0(bm, (bm->b042 ^ 3) ? 3 : 4, 0, 10);
        }
        break;
    case 12:
        if (func_L01_00452F18(s)) {
            v->bD2E = 0;
            v->cD2F = -1;
            func_003BE4F0(bm, 3, 0, 10);
        }
        if (v->bD2E == 0) {
            v->fBE8 = 0.43633232f;
            func_L09_003BDB60(s);
            if (func_L01_0044AF40(bm, 1.0f)) {
                func_L09_003BCD58(s, 0, 0, 0, 1);
            } else if (func_L01_0044AF40(bm, 8.0f)) {
                func_003BE4F0(bm, (bm->b042 ^ 3) ? 3 : 4, 0, 10);
            }
        } else {

            a.v = D_L09_001D66B0_003B6D38;
            a.v.y = 0.0f;
            a.v.x = v->fCDC;
            func_L01_00445758(&a.v, a.v.y, v->xCD8, 0.0034906587097793818f, 0.0034906587097793818f, 0.41887906193733215f, 0);
            v->fCDC = a.v.x;
            func_003BEA80(v->xC50, &a.v);
        }
        break;
    case 14:
        break;
    }

    if (v->f030 <= 0.0f && ((Hero_T *)D_001A4BE0)->i2850 > 0 && ((Hero_T *)D_001A4BE0)->i25C4 != 0x6A && ((Hero_T *)D_001A4BE0)->i25C4 != 0x7D) {
        func_L09_003BAA10((u8 *)s);
    }
    func_003C26C8(s);
    if (v->bD41 == 1) {
        s->f008 += v->fC30 * 0.5f;
    }
}
/* localdecomp:end func_L09_003B6D38 */
