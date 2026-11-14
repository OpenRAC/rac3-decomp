#include "common.h"

/* NTSC-U counterpart of func_L01_002F98F8 (src/levels/shared/L01_002F7800.c) */
typedef int s128 __attribute__((mode(TI)));
extern u8 *func_003BCFB0(s32 class, s32 vars_size);
extern s32 func_L01_004C4A18(u8 *moby, s32 a1, f32 x, f32 y, f32 z);

/* localdecomp:start func_L01_002F9920 */
typedef struct {
    s128 velocity;  /* 0x00 */
    s32 bounces;    /* 0x10 */
    s32 landed;     /* 0x14 */
    s32 countdown;  /* 0x18 */
    s32 shadow;     /* 0x1C */
} __attribute__((aligned(16))) Vars_002F9920;

extern u8 *func_003BCFB0(s32 class, s32 vars_size);
extern f32 func_0037E250(f32 low, f32 high);
extern void func_003C26C8(u8 *moby);
extern s32 func_L01_004C4A18(u8 *moby, s32 a1, f32 x, f32 y, f32 z);

u8 *func_L01_002F9920(s128 *pos, s128 *velocity)
{
    u8 *pod = func_003BCFB0(0x79, 0x80);
    Vars_002F9920 *vars;

    if (pod != 0) {
        pod[0x30] = 0xFF;
        *(u16 *)(pod + 0x32) = 0x1FF;
        pod[0x31] = 1;
        pod[0x20] = 0;
        vars = *(Vars_002F9920 **)(pod + 0x68);
        *(s128 *)(pod + 0x10) = *pos;
        vars->velocity = *velocity;
        vars->landed = 0;
        vars->bounces = 30;
        vars->countdown = 300;
        *(f32 *)(pod + 0xF0) = func_0037E250(-3.1415927f, 3.1415927f);
        *(f32 *)(pod + 0xF4) = func_0037E250(-3.1415927f, 3.1415927f);
        *(f32 *)(pod + 0xF8) = func_0037E250(-3.1415927f, 3.1415927f);
        *(s32 *)(pod + 0xFC) = 0;
        func_003C26C8(pod);
        vars->shadow = func_L01_004C4A18(pod, 0, 1.0f, 1.0f, 1.0f);
    }
    return pod;
}
/* localdecomp:end func_L01_002F9920 */
