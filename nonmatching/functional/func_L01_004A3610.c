/* functional: high. Same reads/writes/calls as retail read against the asm: early return if state byte 4, copy 0x404 bytes, loop over 0x7FF entries updating the visited nibbles, then fills the D_L01_00237800 checkpoint record and calls func_0039EC28(0,-1). Differs from retail only in register allocation, and D_001D545C is read gp-relative here, lui-relative in retail. */
#include "vu0.h"
extern u8 D_001A4BE0[];
extern u8 D_001A30B0[];
extern u8 D_001BBC40[];
extern u8 D_001BBE90[];
extern u8 D_001CCFD0[];
extern u32 D_001D545C;
extern u8 D_L01_00236BF0[];
extern u8 D_L01_00237860[];
extern char D_L01_00237800[];
extern u8 D_L01_001DF9E4;
extern u8 D_L01_001DF9E5;
extern u8 D_L01_001DF9E6;
extern f32 D_L01_001DF9E8;
extern f32 D_L01_001DF9EC;
extern f32 D_L01_001DF9F0;
extern f32 D_L01_001DF9F4;
extern s32 D_L01_001F3F40;
extern void func_0038CC88(void *, void *, s32);
extern s32 func_0039EC28(s32, s32);

void func_L01_004A3610(u8 *a, u8 *b) {
    s32 j;
    u8 *src;
    u8 *dst;
    u8 *p;
    u8 *base;
    u32 lvl;
    u8 v;
    u8 t;
    s32 pa;
    u8 *e;

    if (D_001A4BE0[0x25E4] == 4) {
        return;
    }
    func_0038CC88(D_L01_00237860, D_L01_00236BF0, 0x404);
    lvl = D_001D545C;
    src = D_L01_00236BF0 + 0x404;
    dst = D_L01_00237860 + 0x404;
    for (j = 0; j < 0x7FF; j++) {
        v = src[j];
        if (v == 0) {
            continue;
        }
        if (v != 1 && !(D_001BBC40[v + lvl * 16 - 2] & 0x80)) {
            continue;
        }
        dst[j] = v;
        p = D_001BBE90 + (j >> 1) + (lvl << 10);
        t = *p;
        if (j & 1) {
            if (((t >> 4) & 7) != 7) {
                *p = t + 0x10;
            }
        } else {
            if ((t & 7) != 7) {
                *p = t + 1;
            }
        }
    }
    e = (u8 *)D_L01_00237800;
    *(s32 *)e = 1;
    *(vu0_v4 *)(e + 0x10) = *(vu0_v4 *)a;
    *(vu0_v4 *)(e + 0x20) = *(vu0_v4 *)b;
    pa = *(s32 *)(D_001A4BE0 + 0x25C0);
    *(s32 *)(e + 0x30) = *(s32 *)(pa + 0x38);
    *(s32 *)(e + 0x34) = *(s32 *)(pa + 0x3C);
    *(s32 *)(e + 0x38) = *(s32 *)(D_001A30B0 + 0xB4);
    e[0x3C] = D_001A30B0[0x40];
    e[0x3D] = D_001A30B0[0x41];
    e[0x3E] = D_001A30B0[0x42];
    *(s32 *)(e + 0xC64) = *(s16 *)(D_001CCFD0 + 0x48);
    *(s32 *)(e + 0xC68) = D_L01_001F3F40;
    e[0x3F] = D_L01_001DF9E4;
    e[0x40] = D_L01_001DF9E5;
    e[0x41] = D_L01_001DF9E6;
    *(f32 *)(e + 0x44) = D_L01_001DF9E8;
    *(f32 *)(e + 0x48) = D_L01_001DF9EC;
    *(f32 *)(e + 0x50) = D_L01_001DF9F4;
    *(s32 *)(e + 0x54) = D_001A4BE0[0x25E4];
    *(s32 *)(e + 0x58) = pa;
    *(s32 *)(e + 0x5C) = *(s16 *)(D_001A4BE0 + 0x287A);
    *(f32 *)(e + 0x4C) = D_L01_001DF9F0;
    func_0039EC28(0, -1);
}
