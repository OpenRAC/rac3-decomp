#include "common.h"

INCLUDE_ASM("asm/levels", func_L30_003417B8);

INCLUDE_ASM("asm/levels", func_L30_00341BA0);

/* localdecomp:start func_L30_00341D88 */
extern s32 func_L01_00452FB0(u8 *, u8 *, s32, s32, s32);
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_L24_0043C3B0(u8 *, s32, s32, s32, f32, f32);
extern f32 D_001A4C60[];

void func_L30_00341D88(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    if (func_L01_00452FB0(a0, p + 0x160, 0, 0, 0) != 0) {
        if (a0[0x20] != 3 && a0[0x20] != 0x42) {
            func_L01_004450F0(a0, 3, -1);
        }
    }
    if (a0[0x20] != 3 && a0[0x20] != 0x42) {
        func_L24_0043C3B0(a0, *(s32 *)(p + 0x290), 0, 0, 16.0f, 8.0f);
    }
    *(f32 *)(a0 + 0x14) = D_001A4C60[1];
}
/* localdecomp:end func_L30_00341D88 */

INCLUDE_ASM("asm/levels", func_L30_00341E38);

/* localdecomp:start func_L30_00342030 */
extern void func_L01_0043A430(void *, s32, void *);
extern void func_0038D750(void *, s32, f32);
extern f32 func_0038DB00(f32, f32);

void func_L30_00342030(u8 *arg0) {
    u8 *state = *(u8 **)(arg0 + 0x68);

    if (state[0x251] == 0) {
        func_L01_0043A430(arg0, 0, state + 0x250);
    }
    func_0038D750(state + 0x260, 2, *(f32 *)(state + 0x29C));
    *(f32 *)(state + 0x29C) = func_0038DB00(*(f32 *)(state + 0x29C), 0.17453293f);
}
/* localdecomp:end func_L30_00342030 */

INCLUDE_ASM("asm/levels", func_L30_00342090);

INCLUDE_ASM("asm/levels", func_L30_003420E0);

INCLUDE_ASM("asm/levels", func_L30_00342600);

INCLUDE_ASM("asm/levels", func_L30_003427F8);

INCLUDE_ASM("asm/levels", func_L30_00342980);

INCLUDE_ASM("asm/levels", func_L30_00342A08);

INCLUDE_ASM("asm/levels", func_L30_00342C80);
