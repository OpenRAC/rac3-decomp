#include "common.h"

/* NTSC-U counterpart of func_L05_00361498 (src/levels/shared/L05_00360A10.c): 0.02 -> 0.0166667 */
#include "vu0.h"

/* localdecomp:start func_L05_003601F8 */
extern void func_003888C8(void *, void *, void *);
extern void func_00388830(void *, void *, f32);
extern void func_003BF6A8(void *, f32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E1D8(s32);
extern u8 *func_L05_00465110(void *, void *, void *, s32, s32);
extern vu0_v4 D_L05_001E2700_003601F8;
__asm__(".extern D_L05_001DD8E0_003601F8, 8");
extern u8 D_L05_001DD8E0_003601F8[8];
__asm__(".extern D_L05_001DD920, 8");
extern u8 D_L05_001DD920[8];
__asm__(".extern D_L05_001DD8F8, 4");
extern s32 D_L05_001DD8F8;
__asm__(".extern D_L05_001DD8FC, 4");
extern f32 D_L05_001DD8FC;
__asm__(".extern D_L05_001DD900, 4");
extern f32 D_L05_001DD900;
__asm__(".extern D_L05_001DD904, 4");
extern f32 D_L05_001DD904;
__asm__(".extern D_L05_001DD908, 4");
extern f32 D_L05_001DD908;
__asm__(".extern D_L05_001DD90C, 4");
extern f32 D_L05_001DD90C;
__asm__(".extern D_L05_001DD910_003601F8, 4");
extern f32 D_L05_001DD910_003601F8;

void func_L05_003601F8(u8 *a0) {
    vu0_v4 r;
    vu0_v4 p;
    vu0_v4 d;
    s32 i;

    *(vu0_q *)&r = 0;
    func_003888C8(&p, D_L05_001DD920, a0 + 0xC0);
    vec_add_ba(&p, a0 + 0x10, &p);
    vec_sub_ab(&d, &D_L05_001E2700_003601F8, &p);
    func_00388830(&d, &d, D_L05_001DD910_003601F8);
    vec_add_ab(&p, &p, &d);
    for (i = 0; i < D_L05_001DD8F8; i++) {
        func_003BF6A8(&p, D_L05_001DD8FC);
        r.x = func_0037E250(D_L05_001DD900, D_L05_001DD904) * 0.0166666675f;
        r.y = func_0037E250(D_L05_001DD900, D_L05_001DD904) * 0.0166666675f;
        r.z = func_0037E250(D_L05_001DD908, D_L05_001DD90C) * 0.0166666675f;
        func_L05_00465110(&p, &r, D_L05_001DD8E0_003601F8, func_0037E1D8(2), func_0037E1D8(3) - 1);
    }
}
/* localdecomp:end func_L05_003601F8 */
