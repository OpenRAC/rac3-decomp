#include "common.h"

/* NTSC-U counterpart of func_L05_003DDB90 (src/levels/shared/L05_003DDB90.c): 0.02 -> 0.0166667; 0.04 -> 0.0333333; 0.00666 -> 0.00555 */
#include "vu0.h"

/* localdecomp:start func_L05_003DB6E8 */
extern void func_003BDA38(void *, s32, void *);
extern void func_003886E8(void *, void *, f32);
extern void func_L01_00440A88(void *, f32, f32);
extern s32 func_0037E1D8(s32);
extern void func_L01_00468DC0(void *, void *, s32, s32, s32, s32, s32, s32, f32);

void func_L05_003DB6E8(u8 *a0) {
    vu0_v4 p;
    vu0_v4 v;
    vu0_v4 w;
    s32 i;

    if (a0[0x42] == 1) {
        func_003BDA38(a0, 0, &p);
    } else {
        func_003886E8(&p, a0, 0.0009765625f);
    }
    func_L01_00440A88(&v, 0.0166666675f, 0.0333333351f);
    func_L01_00468DC0(&p, &v, 0x50808080, 0x1E, func_0037E1D8(0xFF) & 0xFF, 0, 0x40, 0, 0.5f);
    for (i = 0; i < 3; i++) {
        func_L01_00440A88(&w, 0.0f, 0.00555000035f);
        vec_add_ab(&v, &v, &w);
        func_L01_00468DC0(&p, &v, 0x40807070, 0x1E, func_0037E1D8(0xFF) & 0xFF, 0, 0x40, 0, 0.3f);
    }
}
/* localdecomp:end func_L05_003DB6E8 */
