/* functional: high. EXACT at level_01, level_05, level_12 (byte-identical). Needs -mvu0-use-vf0-vf2 line (file line lacks it) already in effect at level_01. */
#include "vu0.h"

extern void func_0038D890(void *, void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern u8 D_L01_001E2080[8];

void func_L01_0039E018(u8 *obj, f32 *out, s32 idx) {
    vu0_v4 v;
    u8 *d = *(u8 **)(obj + 0x68);
    u8 *p;

    func_0038D890(&v, D_L01_001E2080 + idx * 16, d + 0x20, *(f32 *)(d + 0x2C));
    p = *(u8 **)(d + (idx << 2) + 0x30);
    if (p != 0 && obj[0x20] == 2) {
        func_0038CF68(&v, &v, *(f32 *)(p + 0x28));
    }
    vec_add_ab(out, d + 0x10, &v);
    out[2] += *(f32 *)d;
}
