#include "common.h"

/* NTSC-U counterpart of func_L07_003B70F0 (src/levels/07_annihilation_nation/L07_003AF398.c) */
typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L07_003B5800 */
extern void func_003BD9A0(void *, s32, void *);
extern void func_00388830(void *, void *, f32);
extern s32 func_0037E1D8(s32);
extern s32 func_L07_003D2680(void *, void *, void *, s32, f32);

void func_L07_003B5800(u8 *a0, s32 a1) {
    f32 m[16] __attribute__((aligned(16)));
    f32 v40[4] __attribute__((aligned(16)));
    f32 v50[4] __attribute__((aligned(16)));
    u8 *d;
    u8 mask;
    u8 flags;
    s32 i;
    f32 sc;
    f32 *p50;
    f32 *p10;

    mask = a1;
    d = *(u8 **)(a0 + 0x68);
    for (i = 0; i < 6; i++) {
        if ((mask >> i) & 1) {
            func_003BD9A0(a0, i + 6, m);
            *(u128_t *)v40 = *(u128_t *)&m[12];
            p50 = v50;
            p10 = &m[4];
            sc = 0.33333334f;
            if (i >= 3) {
                sc = -0.33333334f;
            }
            func_00388830(p50, p10, sc);
            flags = func_0037E1D8(20) == 0;
            if (d[0x321] == 5) {
                flags |= 2;
            }
            if (d[0x321] == 5 || d[0x321] == 2) {
                if (func_0037E1D8(3) == 0) {
                    flags |= 4;
                }
            }
            *(s32 *)(d + 0x308) = func_L07_003D2680(a0, v40, p50, flags, (f32)d[0x45]);
        }
    }
}
/* localdecomp:end func_L07_003B5800 */
