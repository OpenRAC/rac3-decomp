#include "common.h"

/* NTSC-U counterpart of func_L20_003E5058 (src/levels/20_final_boss/L20_003E5058.c) */
/* localdecomp:start func_L20_003E3308 */
#include "vu0.h"
extern void func_L01_00440A88(void *, f32, f32);
extern f32 func_0037E250(f32, f32);
extern void func_00388830(void *, void *, f32);
extern s32 func_0037E208(s32, s32);
extern u8 *func_L01_00467DA8(void *, s32, f32, f32, s32, s32, s32, void *, f32, s32);

void func_L20_003E3308(void *a0) {
    u8 *p = *(u8 **)((u8 *)a0 + 0x68);
    vu0_v4 col;
    vu0_v4 pos;
    f32 s;
    s32 i;

    for (i = 0; i < 2; i++) {
        func_L01_00440A88(&col, 0.10000001f, 0.1666666716f);
        s = func_0037E250(1.0f, 2.0f);
        func_00388830(&pos, p, *(f32 *)(p + 0x30));
        vec_add_ba(&pos, p + 0x10, &pos);
        func_L01_00467DA8(&pos, 10, s, s, 0x7F070760, 0, func_0037E208(-3, 3), &col, 0.0f, 0);
    }
}
/* localdecomp:end func_L20_003E3308 */
