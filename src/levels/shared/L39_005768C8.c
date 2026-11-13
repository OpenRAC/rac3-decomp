#include "common.h"

/* localdecomp:start func_L39_005768C8 */
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
} S_005768C8;
extern S_005768C8 D_001A43E0;
extern s32 D_001D5A18_sda;
extern s32 D_L39_002403F8;
__asm__(".extern D_L39_002403F8, 16");
extern s32 D_L39_002403FC;
__asm__(".extern D_L39_002403FC, 16");
extern s32 D_L39_0024B808 __attribute__((section(".sdata")));
extern s32 D_L39_0024B9C8;
__asm__(".extern D_L39_0024B9C8, 16");
extern u16 D_L39_002004A8[];
extern u16 D_L39_002005C8[];
extern void func_L39_005BF798(s32, s32, s32, s32, s32);
extern void func_L39_00589538(s32);
extern void func_003A9440(s32, unsigned long);
extern s32 func_00396968(s32, s32);
extern void func_00396C60(s32, s32, s32, s32, s32, s32);
extern unsigned long func_L39_0059C910(int);
extern void func_00397638(f32, f32, f32, f32, f32, s32, s32, long);
extern void func_00389370(void);

void func_L39_005768C8(void) {
    s32 v;
    s32 n;
    f32 big;
    f32 ang;

    if ((u32)(D_001A43E0.f15C - 0xF) >= 2 && D_001A43E0.f164 != 0xF && D_L39_0024B808 == 0) {
        return;
    }
    if (D_001A43E0.f16C != 0 || D_001A43E0.f10 != 0) {
        D_001A43E0.f17C = 0;
        D_L39_002403F8 = 0x18;
        D_L39_002403FC = 0x40;
        D_L39_0024B808 = 0;
        if (D_001D5A18_sda == 0) {
            func_L39_005BF798(4, 1, 1, 0, 0);
        } else {
            func_L39_005BF798(4, 2, 1, 0, 0);
        }
        return;
    }
    v = D_L39_0024B808;
    if (v == -1) {
        if (D_001D5A18_sda != 0) {
            return;
        }
        if (D_L39_002004A8[0x90] != 0) {
            D_L39_0024B808 = 0;
            return;
        }
        D_L39_002004A8[0x90] = 1;
    } else {
        if (D_001D5A18_sda == 0 && D_L39_002005C8[0] == 0) {
            func_L39_005BF798(4, 1, 2, 0, 0);
            D_L39_0024B808 = -1;
            return;
        }
        if ((u32)(D_001A43E0.f15C - 0xF) < 2 || D_001A43E0.f164 == 0xF) {
            D_L39_0024B808 = 0x19;
        } else {
            D_L39_0024B808 = v - 1;
        }
        func_L39_00589538(0);
        n = 0x37;
        big = 272.0f;
        func_003A9440(0x47, 0x2004B);
        func_00396C60(func_00396968(0x755D, 0), 0x1A9, 0xFA, 0x40, 0x40, 0x80);
        ang = (f32)(D_L39_0024B9C8 % n) * -6.2831855f / (f32)n;
        func_00397638(7312.0f, 4512.0f, big, big, ang, 0x40, 0x40, func_L39_0059C910(func_00396968(0x755D, 1)));
        func_00389370();
        if (D_L39_002403F8 != 3) {
            return;
        }
    }
    D_L39_0024B808 = 0;
}
/* localdecomp:end func_L39_005768C8 */

INCLUDE_ASM("asm/levels", func_L39_00576B28);

INCLUDE_ASM("asm/levels", func_L39_00576CB0);
