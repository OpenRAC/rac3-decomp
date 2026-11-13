#include "common.h"

LINKER_REMNANT("asm/levels", func_L39_005BE850);

/* localdecomp:start func_L39_005BE878 */
typedef struct {
    u8 pad0[0x10];
    f32 f10;
} S_005BE878;
typedef int Q_005BE878 __attribute__((mode(TI)));

extern S_005BE878 *func_00382348(void *);
extern void func_0038CF68(void *, void *, f32);

void func_L39_005BE878(u8 *a, u8 *out, S_005BE878 *p) {
    if (p == 0) {
        p = func_00382348(a);
        if (p == 0) {
            *(Q_005BE878 *)out = *(Q_005BE878 *)(a + 0x10);
            return;
        }
    }
    func_0038CF68(out, a + 0xE0, p->f10);
    __asm__ __volatile__(
        "lqc2 $vf2, 0x10(%0)\n"
        "lqc2 $vf1, 0x0(%1)\n"
        "vadd.xyz $vf1, $vf1, $vf2\n"
        "sqc2 $vf1, 0x0(%1)\n"
        : : "r"(a), "r"(out) : "memory");
}
/* localdecomp:end func_L39_005BE878 */

LINKER_REMNANT("asm/levels", func_L39_005BE8E8);

/* localdecomp:start func_L39_005BE900 */
extern s32 *D_L39_00241120;
__asm__(".extern D_L39_00241120, 16");
extern u8 *func_L39_0061BF38(s32);
extern s32 func_L39_00591760(s32, f32, void *, f32 *);

s32 func_L39_005BE900(s32 a0, f32 *out, f32 f12) {
    f32 d;
    f32 best;
    s32 idx;
    s32 i;
    u8 *p;
    s32 t;

    idx = -1;
    best = 1024.0f;
    for (i = 0; i < *D_L39_00241120; i++) {
        p = func_L39_0061BF38(i);
        if (p != 0 && *(u8 **)(p + 0x2530) != 0) {
            t = func_L39_00591760(a0, f12, *(u8 **)(p + 0x2530) + 0x3B0, &d);
            if (t != -1) {
                if (t > idx) {
                    idx = t;
                }
                if (d < best) {
                    best = d;
                }
            }
        }
    }
    if (out != 0) {
        *out = best * best;
    }
    return idx;
}
/* localdecomp:end func_L39_005BE900 */
