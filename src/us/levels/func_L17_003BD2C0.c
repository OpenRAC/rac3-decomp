#include "common.h"

/* NTSC-U counterpart of func_L17_003BF000 (src/levels/17_crash_site/L17_003BE8C8.c) */
#include "vu0.h"
extern void func_L01_00441FB8(u8 *, s32, s32);

/* localdecomp:start func_L17_003BD2C0 */
typedef int u128_t __attribute__((mode(TI)));

typedef struct P_3BF000 {
    u8 pad0[0x8];
    f32 f8;
    u8 pad1[0x4];
    f32 f10;
    s16 f14;
} P_3BF000;

typedef struct S_3BF000 {
    u8 pad0[0x18];
    f32 f18;
    u8 pad1[0x4];
    u8 f20;
    u8 pad2[0x3];
    struct { u8 pad[0x24]; f32 f24; } *f24;
    u8 pad3[0x4];
    f32 f2C;
    u8 pad4[0x1];
    u8 f31;
    u8 pad5[0x2];
    u16 f34;
    u8 pad6[0xC];
    u8 f42;
    u8 f43;
    u8 pad7[0x1C];
    u8 f60;
    u8 pad8[0x7];
    P_3BF000 *f68;
    u8 pad9[0x84];
    f32 fF0;
    f32 fF4;
    f32 fF8;
} S_3BF000;

extern u8 D_001A4BE0[];
extern u8 D_001A4C60[];
extern u8 D_001CCFD0[];
extern u8 D_00142CC0[];
extern u8 D_00142D60[];
typedef struct T_3BF000 { s16 f0; s16 f2; s32 f4; } T_3BF000;
extern T_3BF000 D_L17_001DEDB4_003BD2C0;
extern f32 D_L17_001DE6AC;
extern f32 D_L17_001DE6B0;
extern f32 D_L17_001DE6B4;
extern s32 D_L17_001DE9DC_003BD2C0;
__asm__(".extern D_L17_001DE6AC, 4");
__asm__(".extern D_L17_001DE6B0, 4");
__asm__(".extern D_L17_001DE6B4, 4");
__asm__(".extern D_L17_001DE9DC_003BD2C0, 4");
__asm__(".extern D_L17_001DEDB4_003BD2C0, 16");

void func_L05_003DB6E8(void *);
void func_L05_003DB2E8(void *);
void func_L04_003E19F0(void *);
void func_0039C710(void);
void func_L01_004F12C0(void *, void *, s32, s32);
void func_L01_003E9730(s32, s32);
s32 func_00399C90(s32, s32);
s32 func_00399F90(void);
void func_L01_00441FB8(u8 *, s32, s32);
void func_003BE4F0(void *, s32, s32, s32);
void func_L01_0044ECE0(s32, s32, s32);
void func_003BD360(void *);
void func_L01_0050BB98(s32, s32, f32);
s32 func_L01_00452EC8(void *);
s32 func_003883C8(void *);
s32 func_L01_00417F60(s32, s32);
f32 func_00389380(f32, f32);
f32 func_L01_0040C018(void *, void *);

void func_L17_003BD2C0(void *m) {
    S_3BF000 *s = m;
    P_3BF000 *p;
    u8 *c;
    u8 *g;

    p = s->f68;
    if (s->f20 == 0) {
        if (D_00142CC0[0] != 0) {
            func_003BD360(s);
            return;
        } else {
            f32 t;
            *(u128_t *)p = *(u128_t *)((u8 *)s + 0x10);
            p->f10 = s->fF8;
            s->f2C = s->f24->f24 * D_L17_001DE6AC;
            t = p->f8 + D_L17_001DE6B0;
            s->fF4 = 1.5707964f;
            s->f18 = t;
            func_L01_00441FB8((u8 *)s, 1, -1);
        }
    }

    switch (s->f20) {
    case 1:
        func_L05_003DB6E8(s);
        s->fF0 = func_00389380(s->fF0, D_L17_001DE6B4 * 0.017453292f * 0.016666668f);
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
        D_L17_001DEDB4_003BD2C0.f4 = 1;
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
                func_L01_00441FB8((u8 *)s, 3, -1);
            }
        }
        break;
    case 3:
        if (func_003883C8((u8 *)p + 0x14) != 0) {
            func_L01_0044ECE0(0xAF7, -1, 0);
            D_00142CC0[0] = 1;
            D_00142D60[0] = 1;
            func_00399F90();
            s->f31 = 0;
            s->f34 = s->f34 | 1;
            D_L17_001DE9DC_003BD2C0 = 0;
            func_L01_004F12C0(D_001A4C60, D_001A4C60 + 0x10, 0, 0);
            func_L01_003E9730(0, 0);
            func_00399C90(0, -1);
            p->f14 = 0x3c;
            func_L01_00441FB8((u8 *)s, 4, -1);
        }
        break;
    case 4:
        if (func_L01_00452EC8(s)) {
            func_L01_0044ECE0(0xAF7, 0x78, 0);
        }
        if (func_003883C8((u8 *)p + 0x14)) {
            if (func_L01_00417F60(0x1627, 0x138)) {
                func_003BD360(s);
            }
        }
        break;
    }
}
/* localdecomp:end func_L17_003BD2C0 */
