#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L19_00336C58 (src/levels/19_thran_asteroid_belt/L19_00336A48.c): 0.1 -> 0.0833333; 0.02 -> 0.0166667; 0.28 -> 0.233333; 400 -> 480 */
extern f32 D_L19_001E1010_00336220;
extern f32 D_L19_001D7EC4_00336220;
extern void func_L19_00336220(u8 *);

/* localdecomp:start func_L19_00336220 */
extern f32 D_L19_001D7EC4_00336220;
extern f32 D_L19_001E1010_00336220;
extern void func_L01_00440A88(f32 *, f32, f32);
extern f32 func_003824E0(f32, f32);
extern void func_L02_00424E20(void *, f32 *, f32, f32, f32);
extern void func_L19_00461CC0(f32 *, f32 *, s32);

void func_L19_00336220(u8 *a0)
{
    f32 v[4];
    f32 buf[4];
    s32 i;
    f32 f14;
    f32 f20;
    f32 f21;

    D_L19_001E1010_00336220 = D_L19_001D7EC4_00336220;
    D_L19_001D7EC4_00336220 = 0.99f;
    for (i = 0xC7; i >= 0; i--) {
        func_L01_00440A88(buf, 0.0166666675f, 0.233333349f);
        f14 = fabs_asm(buf[2]);
        buf[2] = f14 + 0.0833333358f;
        f21 = func_003824E0(-5.0f, 5.0f);
        f20 = func_003824E0(-5.0f, 5.0f);
        f14 = func_003824E0(10.0f, 25.0f);
        func_L02_00424E20(a0, v, f21, f20, f14);
        func_L19_00461CC0(v, buf, 0x1E0);
    }
}
/* localdecomp:end func_L19_00336220 */
