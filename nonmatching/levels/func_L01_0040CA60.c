/* Near miss (b9-t1): 2 of 116 words differ (retail's second vec_add loads vf2 before the first add's sqc2; mine after).
 * Needs -mvu0-use-vf0-vf2 on L01_0040C3C0.c's flag line and "func_L01_0040CA60 2" in config/levels/divs_nops.txt.
 */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L01_0040CA60 */
typedef int u128_40CA60 __attribute__((mode(TI)));
typedef union {
    u128_40CA60 q;
    f32 f[4];
} Vec4_40CA60;
extern void func_L01_0040D220(Vec4_40CA60 *, Vec4_40CA60 *, Vec4_40CA60 *, Vec4_40CA60 *, Vec4_40CA60 *, f32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CF68(Vec4_40CA60 *, Vec4_40CA60 *, f32);
void func_L01_0040CA60(void *a0, s32 n, void *a2, f32 s) {
    Vec4_40CA60 *buf = a0;
    Vec4_40CA60 *p = a2;
    Vec4_40CA60 t0, t1, tmp;
    f32 inv = 1.0f / (f32)(n - 2);
    s32 i;
    t0 = p[3];
    vec_add_ba(&t0, &t0, &p[0]);
    t1 = p[4];
    vec_add_ba(&t1, &t1, &p[1]);
    for (i = 0; i < n - 1; i++) {
        func_L01_0040D220(&buf[i], &p[0], &p[1], &t0, &t1, (f32)i * inv);
        if (i > 0 && i < n - 2) {
            tmp.f[3] = 0.0f;
            tmp.f[0] = func_003824E0(-1.0f, 1.0f);
            tmp.f[1] = func_003824E0(-1.0f, 1.0f);
            tmp.f[2] = func_003824E0(-1.0f, 1.0f);
            func_0038CF68(&tmp, &tmp, s);
            vec_add_ba(&buf[i], &buf[i], &tmp);
        }
    }
    vec_sub_ab(&tmp, &buf[n - 2], &buf[n - 3]);
    vec_add_ab(&buf[n - 1], &buf[n - 2], &tmp);
}
/* localdecomp:end func_L01_0040CA60 */
