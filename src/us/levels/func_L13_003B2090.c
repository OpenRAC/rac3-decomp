#include "common.h"

/* NTSC-U counterpart of func_L13_003B3F58. */
/* localdecomp:start func_L13_003B2090 */
#include "vu0.h"

extern void func_L01_00440A88(f32 *, f32, f32);
extern f32 func_0037E250(f32, f32);
extern void func_00388830(void *, void *, f32);
extern s32 func_0037E208(s32, s32);
extern void func_L01_00467DA8(f32 *, s32, s32, s32, s32, f32 *, f32, f32, f32, s32);

void func_L13_003B2090(u8 *obj) {
    u8 *p = *(u8 **)(obj + 0x68);
    f32 vel[4];
    f32 pos[4];
    s32 i;
    f32 f20;
    f32 f21;

    for (i = 5; i >= 0; i--) {
        func_L01_00440A88(vel, 0.100000009f, 0.166666672f);
        f20 = func_0037E250(1.0f, 2.0f);
        func_00388830(pos, p, *(f32 *)(p + 0x30));
        vec_add_ba(pos, p + 0x10, pos);
        ((void (*)(f32 *, s32, f32, f32, s32, s32, s32, f32 *, f32, s32))func_L01_00467DA8)(pos, 10, f20, f20, 0x7F076007, 0, func_0037E208(-3, 3), vel, 0.0f, 0);
        f21 = f20 * 0.5f;
        ((void (*)(f32 *, s32, f32, f32, s32, s32, s32, f32 *, f32, s32))func_L01_00467DA8)(pos, 10, f21, f21, 0x7F075F07, 0, func_0037E208(-3, 3), vel, 0.0f, 0);
    }
}
/* localdecomp:end func_L13_003B2090 */
