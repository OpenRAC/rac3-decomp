#include "common.h"

/* localdecomp:start func_L01_00361880 */
typedef int s128 __attribute__((mode(TI)));
typedef struct {
    s128 velocity;  /* 0x00 */
    u8 pad10[0x30];
    s32 f40;
    u8 pad44[4];
    s32 f48;
    u8 pad4C[4];
    s32 f50;
    s32 f54;
    s32 f58;
} __attribute__((aligned(16))) Vars_361880;

extern u8 *func_003BCFB0(s32 class, s32 vars_size);
extern f32 func_0037E250(f32 low, f32 high);
extern void func_003C26C8(u8 *moby);
extern u8 *D_L01_001E1178;

u8 *func_L01_00361880(s128 *pos, s128 *velocity, s32 a2, s32 a3, s32 a4)
{
    u8 *pod = func_003BCFB0(0x185A, 0x80);
    Vars_361880 *vars;

    if (pod != 0) {
        pod[0x30] = 0xFF;
        *(u16 *)(pod + 0x32) = 0x1FF;
        pod[0x31] = 1;
        pod[0x20] = 0;
        vars = *(Vars_361880 **)(pod + 0x68);
        *(s128 *)(pod + 0x10) = *pos;
        vars->velocity = *velocity;
        vars->f40 = 0;
        *(f32 *)(pod + 0xF0) = func_0037E250(-3.1415927f, 3.1415927f);
        *(f32 *)(pod + 0xF4) = func_0037E250(-3.1415927f, 3.1415927f);
        *(f32 *)(pod + 0xF8) = func_0037E250(-3.1415927f, 3.1415927f);
        *(s32 *)(pod + 0xFC) = 0;
        *(f32 *)(pod + 0x2C) = *(f32 *)(*(u8 **)(pod + 0x24) + 0x24) * 1.25f;
        vars->f58 = a4;
        func_003C26C8(pod);
        D_L01_001E1178 = pod;
        vars->f48 = 0x32;
        vars->f50 = a3;
        vars->f54 = a2;
    }
    return pod;
}
/* localdecomp:end func_L01_00361880 */
