#include "common.h"

/* NTSC-U counterpart of func_L20_003FF448 (src/levels/20_final_boss/L20_003FF448.c): 1/60 for 0.02, data +0x40 */
/* localdecomp:start func_L20_003FD138 */
#include "vu0.h"

/* follows func_L05_00361498 (level 5, the same particle loop) */
extern void func_003BDA38(void *, s32, void *);
extern void func_003BD9A0(void *, s32, void *);
extern void func_003888F0(void *, void *, void *);
extern void func_00388830(void *, void *, f32);
extern void func_003BF6A8(void *, f32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E1D8(s32);
extern u8 *func_L05_00465110(void *, void *, void *, s32, s32);
extern vu0_v4 D_L20_001E2E00;
__asm__(".extern D_L20_001DF6D8, 8");
extern u8 D_L20_001DF6D8[8];
__asm__(".extern D_L20_001DF710, 8");
extern u8 D_L20_001DF710[8];
__asm__(".extern D_L20_001DF6F0, 4");
extern s32 D_L20_001DF6F0;
__asm__(".extern D_L20_001DF6F4, 4");
extern f32 D_L20_001DF6F4;
__asm__(".extern D_L20_001DF6F8, 4");
extern f32 D_L20_001DF6F8;
__asm__(".extern D_L20_001DF6FC, 4");
extern f32 D_L20_001DF6FC;
__asm__(".extern D_L20_001DF700, 4");
extern f32 D_L20_001DF700;
__asm__(".extern D_L20_001DF704, 4");
extern f32 D_L20_001DF704;
__asm__(".extern D_L20_001DF708, 4");
extern f32 D_L20_001DF708;

void func_L20_003FD138(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    vu0_v4 r;
    vu0_v4 p;
    u8 m[0x40] __attribute__((aligned(16)));
    vu0_v4 o;
    vu0_v4 d;
    s32 i;
    s32 j;

    *(vu0_q *)&r = 0;
    for (i = 0; i < 2; i++) {
        func_003BDA38(*(void **)(s + 0x3EC), 2, &p);
        func_003BD9A0(*(void **)(s + 0x3EC), 2, m);
        func_003888F0(&o, D_L20_001DF710 + i * 16, m);
        vec_add_ab(&p, &p, &o);
        vec_sub_ba(&d, &D_L20_001E2E00, &p);
        func_00388830(&d, &d, D_L20_001DF708);
        vec_add_ab(&p, &p, &d);
        for (j = 0; j < D_L20_001DF6F0; j++) {
            func_003BF6A8(&p, D_L20_001DF6F4);
            r.x = func_0037E250(D_L20_001DF6F8, D_L20_001DF6FC) * 0.016666668f;
            r.y = func_0037E250(D_L20_001DF6F8, D_L20_001DF6FC) * 0.016666668f;
            r.z = func_0037E250(D_L20_001DF700, D_L20_001DF704) * 0.016666668f;
            func_L05_00465110(&p, &r, D_L20_001DF6D8, func_0037E1D8(2), func_0037E1D8(3) - 1);
        }
    }
}
/* localdecomp:end func_L20_003FD138 */
