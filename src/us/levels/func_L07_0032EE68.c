#include "common.h"

/* localdecomp:start func_L07_0032EE68 */
typedef struct {
    s32 w[0x1F];
    u16 h7C;
    u8 pad7E[0x20];
    u8 b9E;
    u8 b9F;
    u8 padA0[8];
    u8 bA8;
    u8 padA9;
    u8 bAA;
} St_0032EE68;
typedef struct {
    u8 pad0[0x10];
    f32 f10;
    f32 f14;
    u8 pad18[8];
    u8 b20;
    u8 pad21[0x47];
    St_0032EE68 *p68;
    u8 pad6C[0x2A];
    u16 h96;
} Obj_0032EE68;
typedef struct { s16 h0; u8 pad2[14]; } Row_0032EE68;

extern f32 D_L07_001DED50;
extern f32 D_001DED50_sda;
__asm__(".extern D_001DED50_sda, 4");
extern u8 D_001A4BE0[];
extern u8 *D_L07_001DF41C_0032EE68;
extern u16 D_001A7466[];
extern f32 D_001A7404[];
extern u8 D_L07_002B0D40_0032EE68[];
extern void func_L07_0032F258(void *);
extern void func_L07_0032F698(void *);
extern void func_L01_004282C0(s32, s32);
extern void func_L07_00330270(void *);
extern void func_L01_00475A28(void);
extern void func_L01_00477BD0(void);
extern void func_L01_00478140(void);
extern void func_L01_004FC518(s32, s32);
extern void func_L07_003300F8(void *);
extern void func_L07_00331CB8(void *);
extern void func_L07_00331958(void *);
extern void func_L07_00331470(void *);
extern void func_L07_003317A8(void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L07_00330B48(void *);
extern f32 func_L01_0040C018(void *, void *);
extern f32 func_00388A28(f32, f32);
extern f32 func_00389380(f32, f32);
extern f32 func_L03_0032F4A0(f32);
extern s32 func_L07_003AFCC0(void *);
extern f32 func_00389468(f32, f32);
extern s32 func_L07_00331F98(void *);
extern s32 func_L07_00331860(void *);
extern s32 func_L07_00330EC0(void *);
extern void func_L07_00330370(void *);
extern void func_L07_00334AF0(void *);
extern void func_L07_003307F0(void *);
extern s32 func_L01_00452F60(void *);
extern void func_L07_00330858(void *);

void func_L07_0032EE68(Obj_0032EE68 *a) {
    St_0032EE68 *s;
    f32 ang;
    f32 d;
    s32 k;
    s32 idx;

    if (a->b20 == 0) {
        func_L07_0032F258(a);
    }
    func_L07_0032F698(a);
    s = a->p68;
    switch (a->b20) {
    case 1:
        break;
    case 2:
        if (D_L07_001DED50 < 1.0f) {
            D_001DED50_sda = D_L07_001DED50 + 0.08f;
        } else {
            D_L07_001DED50 = 1.0f;
            func_L01_004282C0(1, 0);
            func_L07_00330270(a);
        }
        break;
    case 3:
        D_001DED50_sda = D_L07_001DED50 - 0.08f;
        if (D_001DED50_sda <= 0.0f) {
            D_001DED50_sda = 0.0f;
            func_L01_00475A28();
            func_L01_00477BD0();
            func_L01_00478140();
            func_L01_004FC518(0, 1);
            func_L07_003300F8(a);
        }
        break;
    case 4:
        func_L07_00331CB8(a);
        func_L07_00331958(a);
        func_L07_00331470(a);
        func_L07_003317A8(a);
        func_L01_00441FB8(a, 5, -1);
        break;
    case 5:
        a->h96 = a->h96 + 1;
        if (a->h96 >= 0x1F) {
            func_L07_00330B48(a);
            a->h96 = 0;
        }
        d = func_L01_0040C018(D_001A4BE0 + 0x80, (u8 *)a + 0x10);
        if (d > 576.0f && d < 615.04f) {
            u8 *hero = D_001A4BE0;
            ang = func_00388A28(*(f32 *)(hero + 0x80) - a->f10, *(f32 *)(hero + 0x84) - a->f14);
            k = (s32)(func_L03_0032F4A0(func_00389380(ang, 0.3926991f)) / 0.3926991f) >> 1;
            if ((k & 3) != 2) {
                if (k < 7) {
                    idx = k - (k >= 3);
                } else {
                    idx = k - 2;
                }
                if (func_L07_003AFCC0(D_L07_001DF41C_0032EE68 + (s->w[idx] << 8)) != 0) {
                    if (func_00389468(ang, (f32)k * 0.785398f) < 0.12217305f) {
                        D_001A7466[0] = s->h7C;
                    }
                }
            }
        }
        if (func_L07_00331F98(a) != 0) {
            break;
        }
        if (func_L07_00331860(a) != 0) {
            break;
        }
        func_L01_00441FB8(a, 6, -1);
        break;
    case 6:
        a->h96 = a->h96 + 1;
        if (a->h96 >= 0x1F) {
            func_L07_00330B48(a);
            a->h96 = 0;
        }
        if (func_L07_00330EC0(a) != 0) {
            break;
        }
        func_L01_00441FB8(a, 7, -1);
        break;
    case 7:
        if (s->b9F < ((Row_0032EE68 *)((s->b9E << 4) + (s32)D_L07_002B0D40_0032EE68))->h0 - 1) {
            func_L07_00330370(a);
            func_L01_00441FB8(a, 4, -1);
            break;
        }
        if (s->bAA == 0) {
            func_L07_00334AF0(a);
        }
        s->bA8 = 0;
        func_L07_003307F0(a);
        break;
    case 8:
        D_001A7404[0] = 200.0f;
        if (func_L01_00452F60(a) != 0) {
            func_L07_00330858(a);
            func_L01_00441FB8(a, 1, -1);
        }
        break;
    }
}
/* localdecomp:end func_L07_0032EE68 */
