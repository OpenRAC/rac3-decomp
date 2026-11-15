/* func_L30_00346DA8: 2 diff with the file's flags, once scratch nop table line 'func_L30_00346DA8 2' is in config/levels/divs_nops.txt (without it 20 diff: the two nops before div.s). Left: retail loads a->x4 and the src pointer before its beqz on src; gcc puts the x4 load in the beqz delay slot (reordering the null tests did not help, 6 diff). */
#include "common.h"

typedef int q_00346DA8 __attribute__((mode(TI)));
extern s32 D_L30_001DCF50;
extern s32 D_L30_001DCF54;
extern f32 D_L30_001DCF60;
extern f32 D_L30_001DCF64;
extern f32 D_L30_001DCF68;
extern f32 D_L30_001DCF74;
extern void func_L30_0034C958(u8 *, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_0038DBD8(s32, f32, s32);
extern s32 func_00382498(s32, s32);

void func_L30_00346DA8(u8 *moby, u8 *a) {
    s32 src;
    u8 *vars;
    f32 k;
    s32 n;
    if (a != 0) {
        n = *(s32 *)(a + 4);
        src = *(s32 *)a;
        if (src != 0 && (vars = *(u8 **)(src + 0x68)) != 0 && n != 0) {
        if (*(u16 *)(a + 0xA) & 1) {
            *(q_00346DA8 *)(moby + 0x10) = *(q_00346DA8 *)(src + 0x10);
            func_L30_0034C958(moby + 0x10, D_L30_001DCF60);
            k = D_L30_001DCF74;
            *(f32 *)(a + 0x10) = k * *(f32 *)(vars + 0x90);
            *(f32 *)(a + 0x14) = k * *(f32 *)(vars + 0x98);
            *(s32 *)(moby + 4) = func_0038DBD8(D_L30_001DCF50, func_003824E0(0.0f, 1.0f), D_L30_001DCF54);
            *(u8 *)(moby + 8) = func_00382498(0, 0xFF);
            *(f32 *)(moby + 0xC) = func_003824E0(D_L30_001DCF68, D_L30_001DCF64);
        }
        {
            s16 h = *(s16 *)(moby + 0xA);
            f32 r = (f32)h / (f32)(h + 1);
            *(f32 *)(moby + 0x10) = *(f32 *)(moby + 0x10) + *(f32 *)(a + 0x10);
            *(f32 *)(moby + 0x18) = *(f32 *)(moby + 0x18) + *(f32 *)(a + 0x14);
            *(f32 *)(moby + 0xC) = *(f32 *)(moby + 0xC) * r;
        }
    }
    }
}

INCLUDE_ASM("asm/levels", func_L30_00346DA8);
