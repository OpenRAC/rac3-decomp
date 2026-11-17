#include "common.h"

/* localdecomp:start func_L30_0034E370 */
extern s32 D_L30_001DD5B4; __asm__(".extern D_L30_001DD5B4, 4");
extern s32 D_L30_001DD5B8; __asm__(".extern D_L30_001DD5B8, 4");
extern f32 D_L30_001DD5BC; __asm__(".extern D_L30_001DD5BC, 4");
extern f32 D_L30_001DD5C0; __asm__(".extern D_L30_001DD5C0, 4");
extern s32 D_L30_001DF2C0;
extern void func_L30_0034E420(void *, void *);
extern u32 func_L30_0034E4D0(void *, s32);
extern f32 func_0038DB48(f32);
extern void func_003D9508(void *, s32, u32, s32, f32, f32, f32);
void func_L30_0034E370(void *a0) {
    u8 pos[16];
    u32 colour;
    if (*((u8 *)a0 + 0x20) < 0xFD) {
        func_L30_0034E420(a0, pos);
        colour = func_L30_0034E4D0(a0, 2);
        func_003D9508(pos, D_L30_001DD5B8, colour, 0, D_L30_001DD5C0, D_L30_001DD5BC,
                      func_0038DB48((f32)(D_L30_001DF2C0 % D_L30_001DD5B4) * 6.2831855f / (f32)D_L30_001DD5B4));
    }
}
/* localdecomp:end func_L30_0034E370 */
