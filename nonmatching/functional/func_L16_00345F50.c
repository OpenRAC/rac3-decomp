/* functional: high. Near miss (30 diffs): retail converts (s32)t twice (cvt.w.s kept in the FPU for the fraction); same result. Needs -mvu0-use-vf0-vf2 (the file already has it). */
#include "vu0.h"
extern void func_L16_00346010(void *, s32, void *, f32);
extern void func_0038CE20(void *, void *, f32);

void func_L16_00345F50(s32 path, void *out, f32 t, f32 k) {
    struct {
        vu0_v4 a;
        vu0_v4 b;
        vu0_v4 c;
    } l;
    s32 i = (s32)t;

    func_L16_00346010((void *)path, (i + 1) % *(s32 *)path, &l.a, k);
    func_L16_00346010((void *)path, i, &l.b, k);
    vec_sub_ba(&l.c, &l.a, &l.b);
    func_0038CE20(&l.c, &l.c, t - (f32)(s32)t);
    vec_add_ab(out, &l.b, &l.c);
}
