#include "common.h"

/* localdecomp:start func_L39_0053C1E8 */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V_0053C1E8;
extern void func_0038CF68(void *, void *, f32);

void func_L39_0053C1E8(void *a0, void *a1, f32 a2)
{
    u8 *p = *(u8 **)((u8 *)a0 + 0x68);
    V_0053C1E8 *d = a1;
    V_0053C1E8 v;

    if (*(s16 *)(p + 0x36) != -1) {
        d->z += a2;
    } else {
        func_0038CF68(&v, p + 0x20, a2);
        __asm__ __volatile__(
            "lqc2 $vf1, %0\n"
            "lqc2 $vf2, %1\n"
            "vadd.xyz $vf1, $vf1, $vf2\n"
            "sqc2 $vf1, %0\n"
            : "+m"(*d) : "m"(v));
    }
}
/* localdecomp:end func_L39_0053C1E8 */
