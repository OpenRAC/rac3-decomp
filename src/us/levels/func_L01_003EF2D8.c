#include "common.h"

/* NTSC-U counterpart of func_L01_003F1218 (src/levels/shared/L01_003EB9C8.c) */
/* localdecomp:start func_L01_003EF2D8 */
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    u8 pad14[0x148];
    s32 f15C;
    s32 f160;
    s32 f164;
    s32 f168;
    s32 f16C;
    s32 f170;
    s32 f174;
    s32 f178;
    s32 f17C;
} S_003F1218;
extern S_003F1218 D_00142430;
extern s32 D_001D6694_sda_003EF2D8;
extern s32 D_001D4CE8;
__asm__(".extern D_001D4CE8, 16");
extern s32 D_001D4CEC;
__asm__(".extern D_001D4CEC, 16");
extern s32 D_L01_001DF800 __attribute__((section(".sdata")));
extern s32 D_L01_001DF9C8;
__asm__(".extern D_L01_001DF9C8, 16");
extern u16 D_001A7E18[];
extern u16 D_001A7F38[];
extern void func_0039BEC0(s32, s32, s32, s32, s32);
extern void func_00384B68(s32);
extern void func_003A3EF0(s32, unsigned long);
extern s32 func_00392108(s32, s32);
extern void func_00392400(s32, s32, s32, s32, s32, s32);
extern unsigned long func_003921D8(int);
extern void func_00392DD8(f32, f32, f32, f32, f32, s32, s32, long);
extern void func_00384C98(void);

void func_L01_003EF2D8(void) {
    s32 v;
    s32 n;
    f32 big;
    f32 ang;

    if ((u32)(D_00142430.f15C - 0xF) >= 2 && D_00142430.f164 != 0xF && D_L01_001DF800 == 0) {
        return;
    }
    if (D_00142430.f16C != 0 || D_00142430.f10 != 0) {
        D_00142430.f17C = 0;
        D_001D4CE8 = 0x18;
        D_001D4CEC = 0x40;
        D_L01_001DF800 = 0;
        if (D_001D6694_sda_003EF2D8 == 0) {
            func_0039BEC0(4, 1, 1, 0, 0);
        } else {
            func_0039BEC0(4, 2, 1, 0, 0);
        }
        return;
    }
    v = D_L01_001DF800;
    if (v == -1) {
        if (D_001D6694_sda_003EF2D8 != 0) {
            return;
        }
        if (D_001A7E18[0x90] != 0) {
            D_L01_001DF800 = 0;
            return;
        }
        D_001A7E18[0x90] = 1;
    } else {
        if (D_001D6694_sda_003EF2D8 == 0 && D_001A7F38[0] == 0) {
            func_0039BEC0(4, 1, 2, 0, 0);
            D_L01_001DF800 = -1;
            return;
        }
        if ((u32)(D_00142430.f15C - 0xF) < 2 || D_00142430.f164 == 0xF) {
            D_L01_001DF800 = 0x1E;
        } else {
            D_L01_001DF800 = v - 1;
        }
        func_00384B68(0);
        n = 0x37;
        big = 272.0f;
        func_003A3EF0(0x47, 0x2004B);
        func_00392400(func_00392108(0x755D, 0), 0x1A9, 0xFA, 0x40, 0x40, 0x80);
        ang = (f32)(D_L01_001DF9C8 % n) * -6.2831855f / (f32)n;
        func_00392DD8(7312.0f, 4512.0f, big, big, ang, 0x40, 0x40, func_003921D8(func_00392108(0x755D, 1)));
        func_00384C98();
        if (D_001D4CE8 != 3) {
            return;
        }
    }
    D_L01_001DF800 = 0;
}
/* localdecomp:end func_L01_003EF2D8 */
