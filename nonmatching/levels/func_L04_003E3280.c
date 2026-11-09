/* near miss (level 4, Marcadia): 34 differences: needs @ps2as; lbu register of D_00142CB2 in the entry test, the D_L04_001DF75C store scheduled later in case 3, and the case-3 loop limit (retail keeps it in $v1 and copies it to $a2); tested against src/levels/04_marcadia/L04_003E3280.c with tools/check.py --as ps2as */
#include "common.h"

/* localdecomp:start func_L04_003E3280 */
typedef int U128_3E3280 __attribute__((mode(TI)));
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_3E3280;

extern u8 D_001A4BE0[];
__asm__(".extern D_001A4BE0, 16");
extern u8 D_001A4C60[];
__asm__(".extern D_001A4C60, 16");
extern u8 D_001CCFD0[];
__asm__(".extern D_001CCFD0, 16");
extern u8 D_00142CB2;
__asm__(".extern D_00142CB2, 16");
extern u8 *D_L04_001DFD9C;
__asm__(".extern D_L04_001DFD9C, 16");
extern u8 *D_L04_001DFDA0;
__asm__(".extern D_L04_001DFDA0, 16");
extern s32 D_L04_001DF75C;
__asm__(".extern D_L04_001DF75C, 16");
extern s32 D_L04_001DFB38;
__asm__(".extern D_L04_001DFB38, 16");
extern f32 D_001DF118_sda;
__asm__(".extern D_001DF118_sda, 4");
extern u8 *D_001DFDA0_sda;
__asm__(".extern D_001DFDA0_sda, 4");

extern void func_L04_003E3618(void *);
extern void func_L04_003E36B8(void *);
extern void func_L04_003E3978(void *);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_L01_0040E570(void *, void *);
extern s32 func_L01_004561B8(void *);
extern void func_L01_004AA7E8(void *, s32);
extern void func_003A1798(void);
extern void func_003C2880(void *);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_0038CB00(void *);
extern void func_L01_00419188(s32);
extern void func_L01_00451F60(s32, s32, s32);
extern void func_L01_004F50C8(void *, void *, s32, s32);
extern void func_L01_003EB5E0(s32, s32);
extern void func_0039EC28(s32, s32);
extern void func_L01_0050FB40(s32, s32, f32);

void func_L04_003E3280(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    u8 *q;
    u8 *t;
    u16 h;

    if (a0[0x20] == 0) {
        if (D_00142CB2 != 0) {
            func_003C2880(a0);
            return;
        }
        *(f32 *)(a0 + 0x2C) = *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24) * D_001DF118_sda;
        *(U128_3E3280 *)p = *(U128_3E3280 *)(a0 + 0x10);
        *(f32 *)(p + 0x14) = *(f32 *)(a0 + 0xF8);
        func_L01_004450F0(a0, 1, -1);
    }

    switch (a0[0x20]) {
    case 1:
        *(f32 *)(a0 + 0xF8) = func_0038DAB8(*(f32 *)(a0 + 0xF8), 0.09075713f);
        func_L04_003E3618(a0);
        if (func_L01_0040E570(D_001A4C60, a0 + 0x10) < 25.0f) {
            func_L04_003E36B8(a0);
        }
        return;
    case 2: {
        u8 *w;
        u8 *t;
        if (func_L01_004561B8(a0) != 0) {
            q = D_L04_001DFD9C;
            while (q < D_L04_001DFDA0) {
                if (q != 0 && *(s16 *)(q + 0xAA) == 0x16BD) {
                    *(s32 *)(q + 0x98) = 0;
                    *(u16 *)(q + 0x34) = (*(u16 *)(q + 0x34) | 0x41) & 0xEFFF;
                    func_L01_004AA7E8(q, 1);
                }
                q += 0x100;
            }
        }
        t = D_001CCFD0;
        if (*(s16 *)(t + 0x76) == 0) {
            if (*(s16 *)(t + 0x9E) == 3 && *(s16 *)(t + 0x98) < 0x1B58) {
                func_003A1798();
            }
        }
        w = D_001A4BE0;
        D_L04_001DFB38 = 1;
        *(s16 *)(w + 0x1DC) = 3;
        func_L04_003E3978(a0);
        *(U128_3E3280 *)(a0 + 0x10) = *(U128_3E3280 *)(w + 0x80);
        *(U128_3E3280 *)(a0 + 0xF0) = *(U128_3E3280 *)(w + 0x90);
        if (*(s32 *)(w + 0xC08) & 2) {
            func_L01_0050FB40(0, 0, 25.0f);
        }
        if (a0[0x42] != 1) {
            return;
        }
        if ((a0[0x60] & 2) == 0) {
            return;
        }
        if (a0[0x43] != 0) {
            func_003C3A10(a0, 0, 0, 0);
        }
        a0[0x31] = 0;
        *(u16 *)(a0 + 0x34) = *(u16 *)(a0 + 0x34) | 1;
        func_L01_004450F0(a0, 3, -1);
        return;
    }
    case 3: {
        V4_3E3280 v;
        u8 *b;
        u8 *c;
        u8 *e;
        u8 *t;
        if (func_0038CB00(p + 0x18) == 0) {
            return;
        }
        func_L01_00419188(0x12);
        func_L01_00451F60(0xAEF, -1, 1);
        D_L04_001DF75C = 0;
        b = D_001A4C60 + 0x10;
        v = *(V4_3E3280 *)b;
        v.z = func_0038DAB8(v.z, 3.1415927f);
        func_L01_004F50C8(b - 0x10, &v, 0, 0);
        func_L01_003EB5E0(0, 0);
        func_0039EC28(0, -1);
        c = D_L04_001DFD9C;
        e = D_L04_001DFDA0;
        while (c < D_L04_001DFDA0) {
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
        func_003C2880(a0);
        return;
    }
    }
}
/* localdecomp:end func_L04_003E3280 */
