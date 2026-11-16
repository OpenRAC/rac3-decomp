#include "common.h"

/* NTSC-U counterpart of func_L09_003D9E60 (src/levels/09_tyhrranosis/L09_003D9E60.c) */
/* localdecomp:start func_L09_003D8358 */
extern void func_L09_003D87A0(u8 *);
extern s32 func_L01_00417EA0(void);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L01_00452EC8(void *);
extern void func_00388BD0(void *, void *);
extern f32 func_00389380(f32, f32);
extern f32 func_00388978(f32);
extern void func_00388830(void *, void *, f32);
extern void func_00399F90(void);
extern void func_L09_00317268(void *);
extern s32 func_0039FE80(s32, s32, void *);
extern s32 func_L03_0043C598(void *, s32, void *, s32, s32, f32, f32, f32, f32, s32, f32, f32, s32, s32, f32);
extern void func_L01_004412D0(void *, s32, s32);
extern void func_L09_003CB078(void *, s32);
extern s32 func_L01_0032FE90_003D8358(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003BD360(void *);
extern void func_L01_0044EB38(void *, void *, s32, s32, f32);
extern u8 *D_L09_001E011C;
extern f32 D_L09_002F1DF4 __attribute__((section(".data")));
extern u8 D_001426E0[];
extern s32 D_L09_001D66B0_003D8358[2];

void func_L09_003D8358(u8 *a0) {
    u8 *q;
    u8 *o;
    func_L09_003D87A0(a0);
    *(u16 *)(a0 + 0x34) &= ~0x100;
    q = *(u8 **)(a0 + 0x68);
    switch (a0[0x20]) {
    case 0: {
        u16 v;
        *(s32 *)(a0 + 0x98) = *(s32 *)(*(u8 **)(a0 + 0x24) + 0x10);
        *(s16 *)(q + 0x8A) = *(s16 *)(q + 0x88);
        if (func_L01_00417EA0() != 0) {
            *(s16 *)(q + 0x8A) = *(s16 *)(q + 0x8A) * (s32)D_L09_002F1DF4;
        }
        v = *(u16 *)(q + 0x8A);
        q[0x38] = 1;
        q[0x39] = 0;
        q[0x3F] = 0;
        q[0x64] = 0;
        *(f32 *)(q + 0x40) = 0.5f;
        q[0x3E] = 3;
        *(f32 *)(q + 0x30) = (f32)(s16)v;
        q[0x58] = 0x14;
        q[0x5A] = 0xE;
        *(u16 *)(q + 0x34) = v;
        func_L01_00441FB8(a0, 1, -1);
        break;
    }
    case 1:
        if (func_L01_00452EC8(a0) != 0) {
            break;
        }
        if (a0[0x31] != 0) {
            f32 f;
            f32 s;
            *(u16 *)(a0 + 0x34) |= 0x100;
            func_00388BD0(a0 + 0xC0, a0 + 0xF0);
            f = func_00389380(*(f32 *)(q + 0x94), *(f32 *)(q + 0x98));
            *(f32 *)(q + 0x94) = f;
            *(f32 *)(q + 0x98) = (*(f32 *)(q + 0x98) - 0.116355292f) * 0.980000019f + 0.116355292f;
            s = func_00388978(f) * 0.02f + 0.99f;
            func_00388830(a0 + 0xC0, a0 + 0xC0, s);
            func_00388830(a0 + 0xD0, a0 + 0xD0, s);
            func_00388830(a0 + 0xE0, a0 + 0xE0, 1.0f / (s * s));
        }
        if (*(s32 *)(q + 0x80) != -1) {
            o = D_L09_001E011C + (*(s32 *)(q + 0x80) << 8);
            if (*(s16 *)(o + 0xAA) == 0x1A77) {
                *(s32 *)(*(u8 **)(o + 0x68) + 0xC) = 0;
            }
        }
        break;
    case 2: {
        s16 n = *(s16 *)(q + 0x8E);
        if (n < 2) {
            s32 i = n + 0x1A;
            if (D_001426E0[i] == 0) {
                D_001426E0[i] = 1;
                func_00399F90();
            }
        }
        if (*(s32 *)(q + 0x84) != -1) {
            u8 *m = D_L09_001E011C + (*(s32 *)(q + 0x84) << 8);
            if (*(s16 *)(m + 0xAA) == 0xC2B) {
                func_L09_00317268(m);
            }
        }
        func_0039FE80(0, 0, a0);
        func_L03_0043C598(a0, 0x1FFF, D_L09_001D66B0_003D8358, 2, 3, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 1.0f);
        func_L01_004412D0(a0, 0, 3);
        if (*(s32 *)(q + 0x80) != -1) {
            s16 id;
            o = D_L09_001E011C + (*(s32 *)(q + 0x80) << 8);
            id = *(s16 *)(o + 0xAA);
            if (id == 0x1A77) {
                *(s32 *)(*(u8 **)(o + 0x68) + 0xC) = 1;
            } else if (id == 0x1A19) {
                func_L09_003CB078(o, *(s16 *)(q + 0x8E) + 0x1A);
            }
        }
        func_L01_0032FE90_003D8358(a0 + 0x10, 0, 0x19, 0x14, 0x14, 0x14, 0x14, 0, 1.25f, 0.0f, 0.0f, 2.0f,
            0, 1, 0, 0, 0, 1, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF,
            0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        func_003BD360(a0);
        return;
    }
    }
    if (a0[0x31] != 0) {
        func_L01_0044EB38(a0, q + 0x90, 0x8A909090, 0x8A303030, 0.104719765f);
    }
}
/* localdecomp:end func_L09_003D8358 */
