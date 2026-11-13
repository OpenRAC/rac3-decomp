#include "common.h"

/* NTSC-U counterpart of func_L04_003E3280 (src/levels/04_marcadia/L04_003E3280.c) */
/* localdecomp:start func_L04_003E12F8 */
typedef int U128_3E3280 __attribute__((mode(TI)));
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_3E3280;

extern u8 D_001A4BE0[];
__asm__(".extern D_001A4BE0, 16");
extern u8 D_001A4C60[];
__asm__(".extern D_001A4C60, 16");
extern u8 D_001CCFD0[];
__asm__(".extern D_001CCFD0, 16");
extern u8 D_00142CB2[];
__asm__(".extern D_00142CB2, 16");
extern u8 *D_L04_001DFE1C;
__asm__(".extern D_L04_001DFE1C, 16");
extern u8 *D_L04_001DFE20;
__asm__(".extern D_L04_001DFE20, 16");
extern u8 *const D_L04_001DFE20_003E12F8;
__asm__(".extern D_L04_001DFE20_003E12F8, 16");
extern s32 D_L04_001DF7DC;
__asm__(".extern D_L04_001DF7DC, 16");
extern s32 D_L04_001DFBB8;
__asm__(".extern D_L04_001DFBB8, 16");
extern f32 D_001DF158_sda;
__asm__(".extern D_001DF158_sda, 4");

extern void func_L04_003E1690(void *);
extern void func_L04_003E1730(void *);
extern void func_L04_003E19F0(void *);
extern f32 func_00389380(f32, f32);
extern f32 func_L01_0040C040(void *, void *);
extern s32 func_L01_00452EC8(void *);
extern void func_L01_004A6DF8(void *, s32);
extern void func_0039C710(void);
extern void func_003BD360(void *);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_003883C8(void *);
extern void func_L01_00416B38(s32);
extern void func_L01_0044ECE0(s32, s32, s32);
extern void func_L01_004F12C0(void *, void *, s32, s32);
extern void func_L01_003E9730(s32, s32);
extern void func_00399C90(s32, s32);
extern void func_L01_0050BB98(s32, s32, f32);

void func_L04_003E12F8(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    u8 *q;
    u8 *t;
    u16 h;

    if (a0[0x20] == 0) {
        if (D_00142CB2[0] != 0) {
            func_003BD360(a0);
            return;
        }
        *(f32 *)(a0 + 0x2C) = *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24) * D_001DF158_sda;
        *(U128_3E3280 *)p = *(U128_3E3280 *)(a0 + 0x10);
        *(f32 *)(p + 0x14) = *(f32 *)(a0 + 0xF8);
        func_L01_00441FB8(a0, 1, -1);
    }

    switch (a0[0x20]) {
    case 1:
        *(f32 *)(a0 + 0xF8) = func_00389380(*(f32 *)(a0 + 0xF8), 0.07563094f);
        func_L04_003E1690(a0);
        if (func_L01_0040C040(D_001A4C60, a0 + 0x10) < 25.0f) {
            func_L04_003E1730(a0);
        }
        return;
    case 2: {
        u8 *w;
        u8 *t;
        if (func_L01_00452EC8(a0) != 0) {
            q = D_L04_001DFE1C;
            while (q < D_L04_001DFE20) {
                if (q != 0 && *(s16 *)(q + 0xAA) == 0x16BD) {
                    *(s32 *)(q + 0x98) = 0;
                    *(u16 *)(q + 0x34) = (*(u16 *)(q + 0x34) | 0x41) & 0xEFFF;
                    func_L01_004A6DF8(q, 1);
                }
                q += 0x100;
            }
        }
        t = D_001CCFD0;
        if (*(s16 *)(t + 0x76) == 0) {
            if (*(s16 *)(t + 0x9E) == 3 && *(s16 *)(t + 0x98) < 0x1B58) {
                func_0039C710();
            }
        }
        w = D_001A4BE0;
        D_L04_001DFBB8 = 1;
        *(s16 *)(w + 0x1DC) = 3;
        func_L04_003E19F0(a0);
        *(U128_3E3280 *)(a0 + 0x10) = *(U128_3E3280 *)(w + 0x80);
        *(U128_3E3280 *)(a0 + 0xF0) = *(U128_3E3280 *)(w + 0x90);
        if (*(s32 *)(w + 0xC08) & 2) {
            func_L01_0050BB98(0, 0, 30.0f);
        }
        if (a0[0x42] != 1) {
            return;
        }
        if ((a0[0x60] & 2) == 0) {
            return;
        }
        if (a0[0x43] != 0) {
            func_003BE4F0(a0, 0, 0, 0);
        }
        a0[0x31] = 0;
        *(u16 *)(a0 + 0x34) = *(u16 *)(a0 + 0x34) | 1;
        func_L01_00441FB8(a0, 3, -1);
        return;
    }
    case 3: {
        V4_3E3280 v;
        u8 *b;
        u8 *c;
        u8 *t;
        if (func_003883C8(p + 0x18) == 0) {
            return;
        }
        func_L01_00416B38(0x12);
        func_L01_0044ECE0(0xAEF, -1, 1);
        do { D_L04_001DF7DC = 0; } while (0);
        b = D_001A4C60 + 0x10;
        v = *(V4_3E3280 *)b;
        v.z = func_00389380(v.z, 3.1415927f);
        func_L01_004F12C0(b - 0x10, &v, 0, 0);
        func_L01_003E9730(0, 0);
        func_00399C90(0, -1);
        c = D_L04_001DFE1C;
        while (c < D_L04_001DFE20_003E12F8) {
            if (c != 0 && *(s16 *)(c + 0xAA) == 0x16BD) {
                h = *(u16 *)(c + 0x34) & 0xFFBE;
                *(u16 *)(c + 0x34) = h;
                t = *(u8 **)(c + 0x24);
                h = h | (*(u16 *)(t + 0x44) & 0x1000);
                *(u16 *)(c + 0x34) = h;
                *(s32 *)(c + 0x98) = *(s32 *)(t + 0x10);
            }
            c += 0x100;
        }
        func_003BD360(a0);
        return;
    }
    }
}
/* localdecomp:end func_L04_003E12F8 */
