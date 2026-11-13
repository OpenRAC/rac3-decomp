#include "common.h"

/* NTSC-U counterpart of func_L05_003DD3C8 (src/levels/05_daxx/L05_003DD3C8.c) */
/* localdecomp:start func_L05_003DAF20 */
typedef int u128_t __attribute__((mode(TI)));

typedef struct P_3DD3C8 {
    u8 pad0[0x8];
    f32 f8;
    u8 pad1[0x4];
    f32 f10;
    s16 f14;
} P_3DD3C8;

typedef struct S_3DD3C8 {
    u8 pad0[0x18];
    f32 f18;
    u8 pad1[0x4];
    u8 f20;
    u8 pad2[0x10];
    u8 f31;
    u8 pad3[0x2];
    u16 f34;
    u8 pad4[0xC];
    u8 f42;
    u8 f43;
    u8 pad5[0x1C];
    u8 f60;
    u8 pad6[0x7];
    P_3DD3C8 *f68;
    u8 pad7[0x44];
    u8 fB0;
    u8 pad8[0x3F];
    f32 fF0;
    f32 fF4;
    f32 fF8;
} S_3DD3C8;

extern u8 D_001A4BE0[];
extern u8 D_001A4C60[];
extern u8 D_001CCFD0[];
extern u8 D_001BBC40[];
extern u8 D_00142CBD[];
extern s32 D_001A6290[];
typedef struct T_3DD3C8 { s16 f0; s16 f2; s32 f4; } T_3DD3C8;
extern T_3DD3C8 D_L05_001DF934;
extern s32 D_001D545C_sda_003DAF20;
extern f32 D_001DF220_sda;
extern f32 D_001DF224_sda;
extern s32 D_001DF55C_sda;
__asm__(".extern D_001D545C_sda_003DAF20, 4");
__asm__(".extern D_001DF220_sda, 4");
__asm__(".extern D_001DF224_sda, 4");
__asm__(".extern D_001DF55C_sda, 4");
__asm__(".extern D_L05_001DF934, 16");

void func_L05_003DB6E8(void *);
void func_L05_003DB2E8(void *);
void func_L04_003E19F0(void *);
void func_0039C710(void);
void func_L01_00416B38(s32);
void func_L01_004F12C0(void *, void *, s32, s32);
void func_L01_003E9730(s32, s32);
void func_L01_00438430(s32);
void func_00399C90(s32, s32);
void func_L01_00441FB8(void *, s32, s32);
void func_003BE4F0(void *, s32, s32, s32);
void func_L01_0044ECE0(s32, s32, s32);
void func_L01_0049FDB0(void *, void *);
void func_003BD360(void *);
void func_L01_0050BB98(s32, s32, f32);
s32 func_L01_00452EC8(void *);
s32 func_003883C8(void *);
s32 func_L01_00417F60(s32, s32);
f32 func_00389380(f32, f32);
f32 func_L01_0040C018(void *, void *);
f32 func_L01_0040C040(void *, void *);

void func_L05_003DAF20(void *m) {
    S_3DD3C8 *s = m;
    P_3DD3C8 *p;
    u8 *c;
    u8 *g;
    s32 r;

    p = s->f68;
    if (s->f20 == 0) {
        if (D_00142CBD[0] != 0) {
            if (D_001BBC40[s->fB0 + (D_001D545C_sda_003DAF20 << 4)] & 0x80) {
                func_003BD360(s);
                return;
            }
            s->f31 = 0;
            s->f34 = s->f34 | 1;
            func_L01_00441FB8(s, 5, -1);
        } else {
            f32 t;
            *(u128_t *)p = *(u128_t *)((u8 *)s + 0x10);
            p->f10 = s->fF8;
            t = p->f8 + D_001DF220_sda;
            s->fF4 = 1.5707964f;
            s->f18 = t;
            func_L01_00441FB8(s, 1, -1);
        }
    }

    switch (s->f20) {
    case 1:
        func_L05_003DB6E8(s);
        s->fF0 = func_00389380(s->fF0, D_001DF224_sda * 0.017453292f * 0.0166666675f);
        if (func_L01_0040C018((u8 *)s + 0x10, D_001A4C60) < 9.0f) {
            func_L05_003DB2E8(s);
        }
        break;
    case 2:
        c = D_001CCFD0;
        if (*(s16 *)(c + 0x76) == 0) {
            if (*(s16 *)(c + 0x9E) == 3 && *(s16 *)(c + 0x98) < 0x1B58) {
                if (func_L01_00452EC8(s)) {
                    func_0039C710();
                }
            }
        }
        g = D_001A4BE0;
        *(s16 *)(g + 0x1DC) = 3;
        D_L05_001DF934.f4 = 1;
        func_L04_003E19F0(s);
        *(u128_t *)((u8 *)s + 0x10) = *(u128_t *)(g + 0x80);
        *(u128_t *)((u8 *)s + 0xF0) = *(u128_t *)(g + 0x90);
        if (*(u32 *)(g + 0xC08) & 2) {
            func_L01_0050BB98(0, 0, 30.0f);
        }
        if (s->f42 == 1) {
            func_L05_003DB6E8(s);
            if (s->f60 & 2) {
                if (s->f43 != 0) {
                    func_003BE4F0(s, 0, 0, 0);
                }
                s->f31 = 0;
                s->f34 = s->f34 | 1;
                func_L01_00441FB8(s, 3, -1);
            }
        }
        break;
    case 3:
        if (func_003883C8((u8 *)p + 0x14) != 0) {
            func_L01_00416B38(0x1D);
            {
                u8 *h = D_001A4BE0;
                *(s32 *)(h + 0x25FC) = 0x1D;
                D_001DF55C_sda = 0;
                func_L01_004F12C0(h + 0x80, h + 0x90, 0, 0);
            }
            func_L01_003E9730(0, 0);
            func_L01_00438430(s->fB0);
            p->f14 = 0x3C;
            func_00399C90(0, -1);
            func_L01_00441FB8(s, 4, -1);
        }
        break;
    case 4:
        if (func_L01_00452EC8(s)) {
            func_L01_0044ECE0(0xD2B, 0x78, 0);
        }
        if (func_003883C8((u8 *)p + 0x14)) {
            if (D_001A6290[0] == 0) {
                r = func_L01_00417F60(0x1053, 0xC2);
            } else {
                r = func_L01_00417F60(0x1054, 0xC3);
            }
            if (r) {
                func_003BD360(s);
            }
        }
        break;
    case 5:
        if (func_L01_0040C040((u8 *)s + 0x10, D_001A4C60) < 72.25f) {
            func_L01_00438430(s->fB0);
            func_L01_0049FDB0(D_001A4C60, D_001A4C60 + 0x10);
            func_L01_0044ECE0(0x25A, 0x5A, 0);
            func_003BD360(s);
        }
        break;
    }
}
/* localdecomp:end func_L05_003DAF20 */
