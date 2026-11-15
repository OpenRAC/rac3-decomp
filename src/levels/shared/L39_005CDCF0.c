#include "common.h"

/* localdecomp:start func_L39_005CDCF0 */
typedef int s128 __attribute__((mode(TI)));

extern u8 *D_L39_00296818[];
extern void *func_003CD108(s32);

u8 *func_L39_005CDCF0(s128 *a0, s32 a1, u8 a2, s32 a3, s32 t0, s32 t1, s32 t2, u8 *t3, f32 f12) {
    u8 *o;
    u8 *p;

    o = func_003CD108(59);
    if (o != 0) {
        p = o + 0x20;
        *(s32 *)(p + 0x10) = t2;
        *(u8 **)(p + 0x14) = t3;
        if (t2 == 1 && t3 != 0) {
            __asm__ __volatile__(
                "lqc2 $vf2, 0x10(%1)\n"
                "lqc2 $vf1, 0(%2)\n"
                "vsub.xyz $vf1, $vf1, $vf2\n"
                "sqc2 $vf1, 0x20(%0)\n"
                : : "r"(o), "r"(t3), "r"(a0) : "memory");
        }
        *(s128 *)(o + 0x10) = *a0;
        *(s32 *)(o + 4) = a1;
        o[9] = 0x21;
        o[3] = t0 ? 0x44 : 0x48;
        o[8] = a2;
        o[1] = 0;
        *(f32 *)(o + 0xC) = f12 * 210000.0f;
        o[2] = *D_L39_00296818[a3];
        *(s16 *)(o + 0xA) = t1;
    }
    return o;
}
/* localdecomp:end func_L39_005CDCF0 */
