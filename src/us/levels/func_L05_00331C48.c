#include "common.h"

/* NTSC-U counterpart of func_L05_00332598 (src/levels/05_daxx/L05_00332598.c) */
/* localdecomp:start func_L05_00331C48 */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_332598;
extern u8 D_001A4BE0[];
extern u8 D_001A4C60[];
extern u8 D_001A7C10[];
extern s32 D_001D4C38_sda_00331C48;
extern s32 func_L01_00441FB8(u8 *, s32, s32);
extern s32 func_0037E0F0(u8 *, s32, s32);
extern s32 func_L01_00417F60(s32, s32);
extern s32 func_L02_003E4518(f32, f32, f32);

void func_L05_00331C48(u8 *self) {
    u8 flag;
    u8 *c;
    u8 *b;
    if (*(u8 **)(self + 0x68) == 0) {
        return;
    }
    flag = self[0x20];
    if (flag == 0) {
        *(u16 *)(self + 0x34) |= 0x100;
        self[0x30] = 0xFF;
        *(V4_332598 *)(self + 0xF0) = *(V4_332598 *)D_001A4C60;
        func_L01_00441FB8(self, 1, -1);
    } else if (flag == 1) {
        if (func_0037E0F0(D_001A4C60, *(s32 *)*(u8 **)(self + 0x68), 0) == 0) {
            goto tail;
        }
        c = D_001A7C10;
        if (*(u16 *)(c + 0x60) == 0) {
            goto l670;
        }
        if ((u32)(D_001D4C38_sda_00331C48 - *(s32 *)(c + 0x64)) < 0xE11) {
            goto tail;
        }
        if (*(u16 *)(c + 0x60) >= 5) {
            goto tail;
        }
l670:
        if (func_L01_00417F60(0xB7D, 0x20) == 0) {
            goto tail;
        }
        func_L01_00441FB8(self, 2, -1);
    } else if (flag == 2) {
        f32 f20 = 0.01f;
        b = D_001A4BE0;
        self[0x95] = 1;
        if (func_L02_003E4518(*(f32 *)(b + 0x80), *(f32 *)(self + 0xF0), f20)) {
            if (func_L02_003E4518(*(f32 *)(b + 0x84), *(f32 *)(self + 0xF4), f20)) {
                if (func_L02_003E4518(*(f32 *)(b + 0x88), *(f32 *)(self + 0xF8), f20)) {
                    if (*(u16 *)(self + 0x96) != 0) {
                        *(u16 *)(self + 0x96) = *(u16 *)(self + 0x96) - 1;
                    }
                }
            }
        }
        if (*(u16 *)(self + 0x96) >= 0x1C21) {
            func_L01_00441FB8(self, 1, -1);
        }
    }
tail:
    *(V4_332598 *)(self + 0xF0) = *(V4_332598 *)D_001A4C60;
    *(u16 *)(self + 0x96) = *(u16 *)(self + 0x96) + 1;
}
/* localdecomp:end func_L05_00331C48 */
