#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_00607498);

LINKER_REMNANT("asm/levels", func_L39_006077E0);

/* localdecomp:start func_L39_006077F8 */
extern u8 D_L39_00245720[];
extern u8 D_L39_00245738[];
extern void func_00118E98(void *, s32, void *);

/* from rac4-decomp's func_004EEDC8, renamed */
f32 func_L39_006077F8(f32 t, f32 p0, f32 m0, f32 m1, f32 p1) {
    f32 t2, t3;
    if (!(t >= 0.0f && t <= 1.0f)) {
        func_00118E98(D_L39_00245720, 0x24, D_L39_00245738);
    }
    t2 = t * t;
    t3 = t2 * t;
    p0 *= 1.0f + (2.0f * t3 - 3.0f * t2);
    m0 *= t3 - 2.0f * t2 + t;
    m1 *= t3 - t2;
    p1 *= -(2.0f * t3) + 3.0f * t2;
    return p0 + m0 + m1 + p1;
}
/* localdecomp:end func_L39_006077F8 */
