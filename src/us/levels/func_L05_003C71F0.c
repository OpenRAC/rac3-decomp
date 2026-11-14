#include "common.h"

/* NTSC-U counterpart of func_L05_003C9318 (src/levels/shared/L05_003C9318.c): 0.02 -> 0.0166667 */
#include "vu0.h"

/* localdecomp:start func_L05_003C71F0 */
extern void func_00388830(void *, void *, f32);
extern void func_003BF6A8(void *, f32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E1D8(s32);
extern u8 *func_L05_00465110(void *, void *, void *, s32, s32);
extern vu0_v4 D_L05_001E2700_003C71F0;
__asm__(".extern D_L05_001DEDA8, 8");
extern u8 D_L05_001DEDA8[8];
__asm__(".extern D_L05_001DEDC0, 4");
extern s32 D_L05_001DEDC0;
__asm__(".extern D_L05_001DEDC4, 4");
extern f32 D_L05_001DEDC4;
__asm__(".extern D_L05_001DEDC8, 4");
extern f32 D_L05_001DEDC8;
__asm__(".extern D_L05_001DEDCC, 4");
extern f32 D_L05_001DEDCC;
__asm__(".extern D_L05_001DEDD0, 4");
extern f32 D_L05_001DEDD0;
__asm__(".extern D_L05_001DEDD4, 4");
extern f32 D_L05_001DEDD4;
__asm__(".extern D_L05_001DEDD8, 4");
extern f32 D_L05_001DEDD8;
__asm__(".extern D_L05_001DEDDC, 4");
extern f32 D_L05_001DEDDC;

void func_L05_003C71F0(vu0_v4 *a0) {
    vu0_v4 r;
    vu0_v4 p;
    vu0_v4 d;
    s32 i;

    *(vu0_q *)&r = 0;
    *(vu0_q *)&p = *(vu0_q *)a0;
    p.w = 0.0f;
    p.z += D_L05_001DEDD8;
    vec_sub_ab(&d, &D_L05_001E2700_003C71F0, &p);
    d.z = 0.0f;
    func_00388830(&d, &d, D_L05_001DEDDC);
    vec_add_ab(&p, &p, &d);
    for (i = 0; i < D_L05_001DEDC0; i++) {
        func_003BF6A8(&p, D_L05_001DEDC4);
        r.x = func_0037E250(D_L05_001DEDC8, D_L05_001DEDCC) * 0.0166666675f;
        r.y = func_0037E250(D_L05_001DEDC8, D_L05_001DEDCC) * 0.0166666675f;
        r.z = func_0037E250(D_L05_001DEDD0, D_L05_001DEDD4) * 0.0166666675f;
        func_L05_00465110(&p, &r, D_L05_001DEDA8, func_0037E1D8(2), 1);
    }
}
/* localdecomp:end func_L05_003C71F0 */
