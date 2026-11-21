/* functional: high. Byte-exact only with extra -mvu0-use-vf0-vf2; under file flags only vf scheduling/VU register choice differs. */
#include "vu0.h"
extern void func_00382580(void *, f32, f32);
extern void func_0038CF68(f32 *, s32, f32);
extern void func_L01_004735F0(void *, void *, s32, f32);

void func_L01_00323080(f32 *a0) {
    vu0_q v;
    vu0_q w;
    func_00382580(&v, 0.025f, 0.15f);
    vec_add_ba(&v, &v, a0);
    vec_sub_ab(&w, a0, &v);
    ((void (*)(void *, void *, f32))func_0038CF68)(&w, &w, 0.015000001f);
    func_L01_004735F0(&v, &w, 0xC, 1.0f);
}
