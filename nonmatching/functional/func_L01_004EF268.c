/* functional: high. 4 words differ in scheduling of the lqc2/vadd/sqc2 block vs the constant load; same reads, writes and calls. */
#include "common.h"
/* localdecomp:start func_L01_004EF268 */
extern u8 D_001A4BE0[];
void func_L01_004EF268(void) {
    extern f32 func_0038CED8(void *);
    extern f32 func_0038D160(f32, f32);
    extern void func_0012FE98(void *, void *);
    extern void func_0038CE20(void *, void *, f32);
    Vec4 v;
    u8 *h = D_001A4BE0;
    f32 dot;
    if (*(s16 *)(h + 0x36E) != 0 &&
        *(f32 *)(h + 0x33C) < 0.15f &&
        *(f32 *)(h + 0x118) > 0.0f &&
        h[0x2A7] != 0 &&
        *(f32 *)(h + 0x258) > 0.0f) {
        f32 len = func_0038CED8(h + 0x250);
        if (func_0038D160(*(f32 *)(h + 0x258), len) >= 0.87266463f) {
            v.q = *(u128_t *)(h + 0x250);
            v.f[2] = 0.0f;
            func_0012FE98(&v, &v);
            dot = -*(f32 *)(h + 0xF0) * v.f[0] - *(f32 *)(h + 0xF4) * v.f[1];
            if (dot > 0.0f) {
                func_0038CE20(&v, &v, dot);
                __asm__(
                    "lqc2 $vf1, %1\n\t"
                    "lqc2 $vf2, %2\n\t"
                    "vadd.xyz $vf1, $vf1, $vf2\n\t"
                    "sqc2 $vf1, %0"
                    : "=m"(*(Vec4 *)(h + 0xF0))
                    : "m"(*(Vec4 *)(h + 0xF0)), "m"(v)
                    : "vf1", "vf2");
                *(f32 *)(h + 0xF8) -= 0.0432f;
            }
        }
    }
}
/* localdecomp:end func_L01_004EF268 */
