#include "common.h"

INCLUDE_ASM("asm/levels", func_L19_00336A48);

/* localdecomp:start func_L19_00336C58 */
extern f32 D_L19_001D7EC4;
extern f32 D_L19_001E1010;
extern void func_L01_00443B88(f32 *, f32, f32);
extern f32 func_003824E0(f32, f32);
extern void func_L02_00428520(void *, f32 *, f32, f32, f32);
extern void func_L19_00465AD0(f32 *, f32 *, s32);

void func_L19_00336C58(u8 *a0)
{
    f32 v[4];
    f32 buf[4];
    s32 i;
    f32 f14;
    f32 f20;
    f32 f21;

    D_L19_001E1010 = D_L19_001D7EC4;
    D_L19_001D7EC4 = 0.99f;
    for (i = 0xC7; i >= 0; i--) {
        func_L01_00443B88(buf, 0.020000001f, 0.28000003f);
        __asm__("abs.s %0, %1" : "=f"(f14) : "f"(buf[2]));
        buf[2] = f14 + 0.10000001f;
        f21 = func_003824E0(-5.0f, 5.0f);
        f20 = func_003824E0(-5.0f, 5.0f);
        f14 = func_003824E0(10.0f, 25.0f);
        func_L02_00428520(a0, v, f21, f20, f14);
        func_L19_00465AD0(v, buf, 0x190);
    }
}
/* localdecomp:end func_L19_00336C58 */
