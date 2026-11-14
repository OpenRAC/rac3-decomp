#include "common.h"

/* NTSC-U counterpart of func_L05_003615D8 (src/levels/shared/L05_00360A10.c): 0.02 -> 0.0166667 */
#include "vu0.h"
extern void func_003888C8(void *, void *, void *);
extern void func_00388830(void *, void *, f32);
extern void func_003BF6A8(void *, f32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E1D8(s32);
extern u8 *func_L05_00465110(void *, void *, void *, s32, s32);
extern vu0_v4 D_L05_001E2700_00360338;

/* localdecomp:start func_L05_00360338 */
extern void func_003888C8(void *, void *, void *);
extern void func_00388830(void *, void *, f32);
extern void func_003BF6A8(void *, f32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E1D8(s32);
extern u8 *func_L05_00465110(void *, void *, void *, s32, s32);
extern vu0_v4 D_L05_001E2700_00360338;
__asm__(".extern D_L05_001DD950_00360338, 8");
extern u8 D_L05_001DD950_00360338[8];
__asm__(".extern D_L05_001DD990, 8");
extern u8 D_L05_001DD990[8];
__asm__(".extern D_L05_001DD968, 4");
extern s32 D_L05_001DD968;
__asm__(".extern D_L05_001DD96C, 4");
extern f32 D_L05_001DD96C;
__asm__(".extern D_L05_001DD970_00360338, 4");
extern f32 D_L05_001DD970_00360338;
__asm__(".extern D_L05_001DD974, 4");
extern f32 D_L05_001DD974;
__asm__(".extern D_L05_001DD978, 4");
extern f32 D_L05_001DD978;
__asm__(".extern D_L05_001DD97C, 4");
extern f32 D_L05_001DD97C;
__asm__(".extern D_L05_001DD980_00360338, 4");
extern f32 D_L05_001DD980_00360338;

void func_L05_00360338(u8 *a0) {
    vu0_v4 r;
    vu0_v4 p;
    vu0_v4 d;
    s32 i;

    *(vu0_q *)&r = 0;
    func_003888C8(&p, D_L05_001DD990, a0 + 0xC0);
    vec_add_ba(&p, a0 + 0x10, &p);
    vec_sub_ab(&d, &D_L05_001E2700_00360338, &p);
    func_00388830(&d, &d, D_L05_001DD980_00360338);
    vec_add_ab(&p, &p, &d);
    for (i = 0; i < D_L05_001DD968; i++) {
        func_003BF6A8(&p, D_L05_001DD96C);
        r.x = func_0037E250(D_L05_001DD970_00360338, D_L05_001DD974) * 0.0166666675f;
        r.y = func_0037E250(D_L05_001DD970_00360338, D_L05_001DD974) * 0.0166666675f;
        r.z = func_0037E250(D_L05_001DD978, D_L05_001DD97C) * 0.0166666675f;
        func_L05_00465110(&p, &r, D_L05_001DD950_00360338, func_0037E1D8(2), func_0037E1D8(3) - 1);
    }
}
/* localdecomp:end func_L05_00360338 */
