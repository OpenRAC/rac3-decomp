#include "common.h"
/* localdecomp:start func_L01_00322B80 */
#include "vu0.h"
extern void func_0037E2F0(void *, f32, f32);
extern void func_00388830(f32 *, s32, f32);
extern void func_L01_0046FE70(void *, void *, s32, f32);

void func_L01_00322B80(f32 *a0) {
    vu0_q v;
    vu0_q w;
    func_0037E2F0(&v, 0.025f, 0.15f);
    vec_add_ba(&v, &v, a0);
    vec_sub_ab(&w, a0, &v);
    ((void (*)(void *, void *, f32))func_00388830)(&w, &w, 0.0125000011f);
    func_L01_0046FE70(&v, &w, 0xF, 1.0f);
}
/* localdecomp:end func_L01_00322B80 */
