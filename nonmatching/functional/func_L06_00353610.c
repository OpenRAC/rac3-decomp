/* functional: high. check.py at level_06: 2 instruction diffs (lq/sq order in the else copy); same values. */
#include "common.h"
#include "vu0.h"
extern void func_0038CE90(void *, void *, void *);
void func_L06_00353610(u8 *a0, u8 *p, s32 i, void *a3, void *a4, void *out) {
    vu0_v4 s0;
    vu0_v4 s1;
    vu0_v4 v;
    vu0_v4 w;
    s32 n = *(s32 *)p;
    if (i < n - 1 || *(s32 *)(a0 + 0x340) != 0) {
        s0 = *(vu0_v4 *)(p + i * 16 + 0x10);
        s1 = *(vu0_v4 *)(p + ((i + 1) % n) * 16 + 0x10);
    } else {
        s1 = *(vu0_v4 *)(p + i * 16 + 0x10);
        s0 = *(vu0_v4 *)(p + i * 16);
    }
    vec_sub_ba(&v, &s1, &s0);
    v.z = 0.0f;
    vec_sub_ab(&w, a4, a3);
    w.z = 0.0f;
    func_0038CE90(out, &v, &w);
}
