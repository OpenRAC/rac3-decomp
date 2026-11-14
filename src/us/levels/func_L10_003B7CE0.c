#include "common.h"

/* NTSC-U counterpart of func_L10_003B9DB0 (src/levels/10_zeldrin_starport/L10_003B9078.c) */
extern void func_003BE4F0(u8 *, s32, s32, s32);

/* localdecomp:start func_L10_003B7CE0 */
typedef int u128_t_3B9DB0 __attribute__((mode(TI)));
typedef struct P_3B9DB0 {
    u8 pad0[0x10];
    f32 f10;
    s16 f14;
} P_3B9DB0;
typedef struct S_3B9DB0 {
    u8 pad0[0x20];
    u8 f20;
    u8 pad1[0x3];
    u8 *f24;
    u8 pad2[0x4];
    f32 f2C;
    u8 pad3[0x1];
    u8 f31;
    u8 pad4[0x2];
    u16 f34;
    u8 pad5[0xC];
    u8 f42;
    u8 f43;
    u8 pad6[0x1C];
    u8 f60;
    u8 pad7[0x7];
    P_3B9DB0 *f68;
    u8 pad8[0x8C];
    f32 fF8;
} S_3B9DB0;
typedef struct T_3B9DB0 { s16 f0; s16 f2; s32 f4; } T_3B9DB0;
extern u8 D_001A4BE0[];
extern u8 D_001A4C60[];
extern u8 D_001CCFD0[];
extern u8 D_00142CBA[];
extern T_3B9DB0 D_L10_001DF0B4;
extern f32 D_L10_001DE7B0;
extern s32 D_L10_001DECDC;
__asm__(".extern D_L10_001DE7B0, 4");
__asm__(".extern D_L10_001DF0B4, 16");

void func_L04_003E1690(void *);
void func_L05_003DB2E8(void *);
void func_L04_003E19F0(void *);
s32 func_0039C710(void);
void func_L01_00416B38(s32);
void func_L01_004F12C0(void *, void *, s32, s32);
void func_L01_003E9730(s32, s32);
s32 func_00399C90(s32, s32);
void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(u8 *, s32, s32, s32);
void func_L01_0044ECE0(s32, s32, s32);
void func_003BD360(void *);
void func_L01_0050BB98(s32, s32, f32);
s32 func_L01_00452EC8(void *);
s32 func_003883C8(void *);
s32 func_L01_00417F60(s32, s32);
f32 func_00389380(f32, f32);
f32 func_L01_0040C040(void *, void *);

void func_L10_003B7CE0(void *m) {
    S_3B9DB0 *s = m;
    P_3B9DB0 *p;
    u8 *c;
    u8 *g;

    p = s->f68;
    if (s->f20 == 0) {
        if (D_00142CBA[0] != 0) {
            func_003BD360(s);
            return;
        }
        s->f2C = *(f32 *)(s->f24 + 0x24) * D_L10_001DE7B0;
        *(u128_t_3B9DB0 *)p = *(u128_t_3B9DB0 *)((u8 *)s + 0x10);
        p->f10 = s->fF8;
        func_L01_00441FB8(s, 1, -1);
    }

    switch (s->f20) {
    case 1:
        s->fF8 = func_00389380(s->fF8, 0.07563094f);
        func_L04_003E1690(s);
        if (func_L01_0040C040(D_001A4C60, (u8 *)s + 0x10) < 25.0f) {
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
        D_L10_001DF0B4.f4 = 1;
        func_L04_003E19F0(s);
        *(u128_t_3B9DB0 *)((u8 *)s + 0x10) = *(u128_t_3B9DB0 *)(g + 0x80);
        *(u128_t_3B9DB0 *)((u8 *)s + 0xF0) = *(u128_t_3B9DB0 *)(g + 0x90);
        if (*(u32 *)(g + 0xC08) & 2) {
            func_L01_0050BB98(0, 0, 30.0f);
        }
        if (s->f42 == 1 && (s->f60 & 2)) {
            if (s->f43 != 0) {
                func_003BE4F0((u8 *)s, 0, 0, 0);
            }
            s->f31 = 0;
            s->f34 = s->f34 | 1;
            func_L01_00441FB8(s, 5, -1);
        }
        break;
    case 5:
        if (func_003883C8((u8 *)p + 0x14) != 0) {
            func_L01_00416B38(0x1A);
            func_L01_00416B38(7);
            D_L10_001DECDC = 0;
            func_L01_004F12C0(D_001A4C60, D_001A4C60 + 0x10, 0, 0);
            func_L01_003E9730(0, 0);
            func_00399C90(0, -1);
            p->f14 = 0x3c;
            func_L01_00441FB8(s, 4, -1);
        }
        break;
    case 4:
        if (func_L01_00452EC8(s)) {
            func_L01_0044ECE0(0x1B82, 0x78, 0);
        }
        if (func_003883C8((u8 *)p + 0x14) != 0 && func_L01_00417F60(0x1426, 0x114) != 0) {
            func_003BD360(s);
        }
        break;
    }
}
/* localdecomp:end func_L10_003B7CE0 */
