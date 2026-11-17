#include "common.h"

typedef int Quad_3B4618 __attribute__((mode(TI)));

INCLUDE_ASM("asm/levels", func_L13_003B3938);

INCLUDE_ASM("asm/levels", func_L13_003B3DA8);

/* localdecomp:start func_L13_003B3F58 */
#include "vu0.h"

extern void func_L01_00443B88(f32 *, f32, f32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_00382498(s32, s32);
extern void func_L01_0046B458(f32 *, s32, s32, s32, s32, f32 *, f32, f32, f32, s32);

void func_L13_003B3F58(u8 *obj) {
    u8 *p = *(u8 **)(obj + 0x68);
    f32 vel[4];
    f32 pos[4];
    s32 i;
    f32 f20;
    f32 f21;

    for (i = 5; i >= 0; i--) {
        func_L01_00443B88(vel, 0.120000005f, 0.20000002f);
        f20 = func_003824E0(1.0f, 2.0f);
        func_0038CF68(pos, p, *(f32 *)(p + 0x30));
        vec_add_ba(pos, p + 0x10, pos);
        ((void (*)(f32 *, s32, f32, f32, s32, s32, s32, f32 *, f32, s32))func_L01_0046B458)(pos, 8, f20, f20, 0x7F076007, 0, func_00382498(-3, 3), vel, 0.0f, 0);
        f21 = f20 * 0.5f;
        ((void (*)(f32 *, s32, f32, f32, s32, s32, s32, f32 *, f32, s32))func_L01_0046B458)(pos, 8, f21, f21, 0x7F075F07, 0, func_00382498(-3, 3), vel, 0.0f, 0);
    }
}
/* localdecomp:end func_L13_003B3F58 */

INCLUDE_ASM("asm/levels", func_L13_003B40A0);
