#include "common.h"

/* NTSC-U counterpart of func_L01_0035DEC8 (src/levels/shared/L01_0035BF48.c): 25 -> 30; 250 -> 300; 58 -> 70 */
typedef int s128 __attribute__((mode(TI)));
extern u8 *func_003C24B0(s32 class, s32 vars_size);
extern s32 func_L01_004C4A18(u8 *moby, s32 a1, f32 x, f32 y, f32 z);

/* localdecomp:start func_L01_0035D178 */
typedef struct {
    s128 velocity;  /* 0x00 */
    u8 pad10[0x10];
    s32 bounces;    /* 0x20 */
    s32 landed;     /* 0x24 */
    s32 countdown;  /* 0x28: frames until it lets its agents out */
    s32 shadow;     /* 0x2C */
    s32 sound;      /* 0x30 */
} __attribute__((aligned(16))) PodVars_0035DEC8;

extern u8 *func_003C24B0(s32 class, s32 vars_size);
extern f32 func_003824E0(f32 low, f32 high);
extern void func_003C7C38(u8 *moby);
extern s32 func_L01_004C4A18(u8 *moby, s32 a1, f32 x, f32 y, f32 z);
extern void func_L01_0035D848(u8 *pod);

/* agent_pod_spawn: the Agents of Doom's pod (class 0x1853) at pos with velocity, turned at
   random, letting its agents out after 300 frames (the US's 300). */
u8 *func_L01_0035D178(s128 *pos, s128 *velocity)
{
    u8 *pod = func_003C24B0(0x1853, 0x80);
    PodVars_0035DEC8 *vars;

    if (pod != 0) {
        pod[0x30] = 0xFF;
        *(u16 *)(pod + 0x32) = 0x1FF;
        pod[0x31] = 1;
        pod[0x20] = 0;
        vars = *(PodVars_0035DEC8 **)(pod + 0x68);
        *(s128 *)(pod + 0x10) = *pos;
        vars->velocity = *velocity;
        vars->landed = 0;
        vars->bounces = 30;
        vars->countdown = 300;
        /* any turn, -pi to pi, about each axis */
        *(f32 *)(pod + 0xF0) = func_003824E0(-3.1415927f, 3.1415927f);
        *(f32 *)(pod + 0xF4) = func_003824E0(-3.1415927f, 3.1415927f);
        *(f32 *)(pod + 0xF8) = func_003824E0(-3.1415927f, 3.1415927f);
        *(s32 *)(pod + 0xFC) = 0;
        /* 1.2 x its class's scale */
        *(f32 *)(pod + 0x2C) = *(f32 *)(*(u8 **)(pod + 0x24) + 0x24) * 1.2f;
        func_003C7C38(pod);
        vars->shadow = func_L01_004C4A18(pod, 0, 1.0f, 1.0f, 1.0f);
        vars->sound = 0x46;
        func_L01_0035D848(pod);
    }
    return pod;
}
/* localdecomp:end func_L01_0035D178 */
