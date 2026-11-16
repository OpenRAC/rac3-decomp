/* NTSC-U draft (Claude wave K): C of func_L13_003AD0C8, the NTSC-U twin of func_L13_003AEEB0, with NTSC-U names and addresses (the two versions' code differs).
 * flags: byte-exact on NTSC-U only with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (its file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division") (NTSC-U twin "func_L13_003AD0C8", whose code is not the PAL one).
 * Worker's note: byte-exact (check MATCH, C in near/func_L13_003AD0C8.medium.c) only with @ps2as added to the PAL line (L13_003ABD48.c: -O2 -G8 -fopt-stack -mno-check-zero-division); with the PAL line alone 78 diff (retail builds every float literal with lui/ori/mtc1, the PAL ...
 */
#include "common.h"

/* NTSC-U counterpart of func_L13_003AEEB0 (src/levels/shared/L13_003ABD48.c).
 * Byte-exact only with @ps2as added to the PAL line (-O2 -G8 -fopt-stack -mno-check-zero-division): retail builds float
 * literals with lui/ori/mtc1. q0 = *(f32 *)(self + 0xF0) is read BEFORE g so the D714 load is not scheduled right behind
 * the D718 multiply: with sched2 on, local-alloc keeps two adjacent quantities out of the same hard reg and put D718 in $f1. */

/* localdecomp:start func_L13_003AD0C8 */
extern f32 D_001DE718_sda;
__asm__(".extern D_001DE718_sda, 4");
extern f32 D_001DE71C_sda;
__asm__(".extern D_001DE71C_sda, 4");
extern f32 D_001DE714_sda;
__asm__(".extern D_001DE714_sda, 4");
extern f32 D_001DE690_sda;
__asm__(".extern D_001DE690_sda, 4");
extern f32 func_00388730(void *, void *);

void func_L13_003AD0C8(u8 *self, void *a1, f32 f) {
    f32 g;
    f32 h;
    f32 t;
    f32 u;

    f32 q0 = *(f32 *)(self + 0xF0);
    g = -(D_001DE714_sda * 0.017453292f);
    *(f32 *)(self + 0xF0) = q0 - f * D_001DE718_sda * D_001DE71C_sda;
    t = (func_00388730(a1, self + 0xD0) / (D_001DE690_sda * 0.0166666675f) < 1.0f)
            ? g * (func_00388730(a1, self + 0xD0) / (D_001DE690_sda * 0.0166666675f))
            : g;
    h = D_001DE714_sda * 0.017453292f;
    *(f32 *)(self + 0xF0) = *(f32 *)(self + 0xF0) * (1.0f - D_001DE71C_sda) + t * D_001DE71C_sda;
    u = (func_00388730(a1, self + 0xC0) / (D_001DE690_sda * 0.0166666675f) < 1.0f)
            ? h * (func_00388730(a1, self + 0xC0) / (D_001DE690_sda * 0.0166666675f))
            : h;
    *(f32 *)(self + 0xF4) = *(f32 *)(self + 0xF4) * (1.0f - D_001DE71C_sda) + u * D_001DE71C_sda;
}
/* localdecomp:end func_L13_003AD0C8 */
