#include "common.h"

/* NTSC-U counterpart of func_L01_003F8E78 (src/levels/shared/L01_003F79D8.c): 0.015708 -> 0.01309; 0.0314159 -> 0.0261799 */
typedef int u128_t __attribute__((mode(TI)));
extern void func_L01_003F6CD0(u8 *self, void *a, void *b);

/* localdecomp:start func_L01_003F6CD0 */
extern f32 func_0038CEA8_003F6CD0(f32 *);
extern void func_003C4CE8_003F6CD0(u8 *a0, void *a1, f32 f12);
extern f32 func_0038D0B0_003F6CD0(f32);
extern void func_0038D688_003F6CD0(void *, void *, void *);

void func_L01_003F6CD0(u8 *self, void *a, void *b)
{
    u128_t vec;
    f32 half;
    f32 lo;
    f32 hi;

    vec = *(u128_t *)b;
    half = func_0038CEA8_003F6CD0((f32 *)&vec) * 0.5f;
    lo = func_0038D0B0_003F6CD0(0.0130899707f);
    hi = func_0038D0B0_003F6CD0(0.0261799414f);
    if (lo < half)
        half = lo;
    func_003C4CE8_003F6CD0((u8 *)&vec, &vec, half);
    func_0038D688_003F6CD0(a, a, &vec);
    if (hi < func_0038CEA8_003F6CD0((f32 *)a))
        func_003C4CE8_003F6CD0(a, a, hi);
}
/* localdecomp:end func_L01_003F6CD0 */
