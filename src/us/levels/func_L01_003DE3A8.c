#include "common.h"

/* localdecomp:start func_L01_003DE3A8 */
typedef int s128 __attribute__((mode(TI)));

typedef struct {
    s128 q00;
    u8 pad10[0x10];
    s16 h20;
    u8 pad22[6];
    s32 w28;
} __attribute__((aligned(16))) Vars_003DE3A8;

extern u8 *func_003BCFB0(s32 class, s32 vars_size);
extern s32 func_0037E208(s32 low, s32 high);
extern f32 func_0037E2A8(void);
extern f32 func_0037E250(f32 low, f32 high);
extern void func_00388BD0(void *dst, void *angles);
extern void func_003BF2F8(void *dst, void *src, f32 amount);
extern s32 func_L01_004C4A18(u8 *moby, s32 a1, f32 x, f32 y, f32 z);
extern void func_003C26C8(u8 *moby);

u8 *func_L01_003DE3A8(s128 *pos, s128 *dir) {
    u8 *moby = func_003BCFB0(0x1E05, 0x80);
    Vars_003DE3A8 *vars;
    f32 r;

    if (moby != 0) {
        *(u16 *)(moby + 0x32) = 0xFF;
        moby[0x30] = 0xFF;
        moby[0x20] = 0;
        vars = *(Vars_003DE3A8 **)(moby + 0x68);
        *(s128 *)(moby + 0x10) = *pos;
        vars->q00 = *dir;
        vars->h20 = func_0037E208(300, 500);
        *(u16 *)(moby + 0x34) |= 0x100;
        *(f32 *)(moby + 0xF0) = func_0037E2A8();
        *(f32 *)(moby + 0xF4) = func_0037E2A8();
        *(f32 *)(moby + 0xF8) = func_0037E2A8();
        moby[0x23] = 0x40;
        func_00388BD0(moby + 0xC0, moby + 0xF0);
        r = func_0037E250(0.043633234f, 0.08726647f);
        func_003BF2F8((u8 *)vars + 0x10, moby + 0xD0, r);
        r = func_0037E250(0.25f, 0.3f);
        *(f32 *)(moby + 0x2C) = *(f32 *)(*(u8 **)(moby + 0x24) + 0x24) * r;
        vars->w28 = func_L01_004C4A18(moby, 0, 1.0f, 1.0f, 1.0f);
        func_003C26C8(moby);
    }
    return moby;
}
/* localdecomp:end func_L01_003DE3A8 */
