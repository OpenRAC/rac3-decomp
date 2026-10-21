#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_0061ECE0);

LINKER_REMNANT("asm/levels", func_L39_0061ED70);

INCLUDE_ASM("asm/levels", func_L39_0061ED80);

INCLUDE_ASM("asm/levels", func_L39_0061F3F0);

INCLUDE_ASM("asm/levels", func_L39_0061F5A0);

INCLUDE_ASM("asm/levels", func_L39_0061FBC8);

INCLUDE_ASM("asm/levels", func_L39_0061FDF0);

INCLUDE_ASM("asm/levels", func_L39_0061FEA8);

INCLUDE_ASM("asm/levels", func_L39_00620168);

/* localdecomp:start func_L39_00620240 */
void func_L39_00620240(f32 *out, s32 *outi, s32 base, f32 *a, f32 *b, s32 *p1, s32 *p2, f32 unused, f32 minv) {
    f32 d = *p2 - *p1;
    f32 m = (d < minv) ? minv : d;
    f32 t;
    f32 u;

    t = m / d;
    *outi = base + (s32)m;
    u = 1.0f - t;
    out[0] = u * a[0] + t * b[0];
    out[1] = u * a[1] + t * b[1];
    out[2] = u * a[2] + t * b[2];
}
/* localdecomp:end func_L39_00620240 */

INCLUDE_ASM("asm/levels", func_L39_006202E0);

INCLUDE_ASM("asm/levels", func_L39_006205B0);
