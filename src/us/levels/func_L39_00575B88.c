#include "common.h"

/* NTSC-U counterpart of func_L39_005768C8 (src/levels/shared/L39_005768C8.c): 25 -> 30 */
/* localdecomp:start func_L39_00575B88 */
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
extern S_005768C8 D_001A4560;
extern s32 D_001D5A18_sda_00575B88;
extern s32 D_L39_00240578;
__asm__(".extern D_L39_00240578, 16");
extern s32 D_L39_0024057C;
__asm__(".extern D_L39_0024057C, 16");
extern s32 D_L39_0024B908 __attribute__((section(".sdata")));
extern s32 D_L39_0024BAC8;
__asm__(".extern D_L39_0024BAC8, 16");
extern u16 D_L39_00200628[];
extern u16 D_L39_00200748[];
extern void func_L39_005BD7D8(s32, s32, s32, s32, s32);
extern void func_L39_005883C8(s32);
extern void func_003A9440_00575B88(s32, unsigned long);
extern s32 func_00396968_00575B88(s32, s32);
extern void func_00396C60_00575B88(s32, s32, s32, s32, s32, s32);
extern unsigned long func_L39_0059B580(int);
extern void func_00397638_00575B88(f32, f32, f32, f32, f32, s32, s32, long);
extern void func_00389370_00575B88(void);

void func_L39_00575B88(void) {
    s32 v;
    s32 n;
    f32 big;
    f32 ang;

    if ((u32)(D_001A4560.f15C - 0xF) >= 2 && D_001A4560.f164 != 0xF && D_L39_0024B908 == 0) {
        return;
    }
    if (D_001A4560.f16C != 0 || D_001A4560.f10 != 0) {
        D_001A4560.f17C = 0;
        D_L39_00240578 = 0x18;
        D_L39_0024057C = 0x40;
        D_L39_0024B908 = 0;
        if (D_001D5A18_sda_00575B88 == 0) {
            func_L39_005BD7D8(4, 1, 1, 0, 0);
        } else {
            func_L39_005BD7D8(4, 2, 1, 0, 0);
        }
        return;
    }
    v = D_L39_0024B908;
    if (v == -1) {
        if (D_001D5A18_sda_00575B88 != 0) {
            return;
        }
        if (D_L39_00200628[0x90] != 0) {
            D_L39_0024B908 = 0;
            return;
        }
        D_L39_00200628[0x90] = 1;
    } else {
        if (D_001D5A18_sda_00575B88 == 0 && D_L39_00200748[0] == 0) {
            func_L39_005BD7D8(4, 1, 2, 0, 0);
            D_L39_0024B908 = -1;
            return;
        }
        if ((u32)(D_001A4560.f15C - 0xF) < 2 || D_001A4560.f164 == 0xF) {
            D_L39_0024B908 = 0x1E;
        } else {
            D_L39_0024B908 = v - 1;
        }
        func_L39_005883C8(0);
        n = 0x37;
        big = 272.0f;
        func_003A9440_00575B88(0x47, 0x2004B);
        func_00396C60_00575B88(func_00396968_00575B88(0x755D, 0), 0x1A9, 0xFA, 0x40, 0x40, 0x80);
        ang = (f32)(D_L39_0024BAC8 % n) * -6.2831855f / (f32)n;
        func_00397638_00575B88(7312.0f, 4512.0f, big, big, ang, 0x40, 0x40, func_L39_0059B580(func_00396968_00575B88(0x755D, 1)));
        func_00389370_00575B88();
        if (D_L39_00240578 != 3) {
            return;
        }
    }
    D_L39_0024B908 = 0;
}
/* localdecomp:end func_L39_00575B88 */
