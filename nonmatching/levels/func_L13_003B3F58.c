/* NTSC-U draft (Claude wave C2): C of func_L13_003B2090, the NTSC-U twin of func_L13_003B3F58, with NTSC-U names and addresses (the two versions' code differs).
 * flags: byte-exact on NTSC-U only with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (its file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division") (NTSC-U twin "func_L13_003B2090", whose code is not the PAL one).
 * Worker's note: flags: byte-exact (0 diff) only with BOTH -mvu0-use-vf0-vf2 (vec_add_ba from vu0.h) and @ps2as (inline 0.1f / 1/6 constants); its PAL file has neither. Six-iteration double spark spawn (i = 5..0): func_L01_00440A88, rand 1..2, func_00388830(pos, p, p->f30), ...
 */
#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L13_003B3F58 (src/levels/shared/L13_003B3938.c) */
/* localdecomp:start func_L13_003B2090 */
extern void func_L01_00440A88(f32 *, f32, f32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E208(s32, s32);
extern void func_00388830(void *, void *, f32);
extern void func_L01_00467DA8(f32 *, s32, f32, f32, s32, s32, s32, f32 *, f32, s32);

void func_L13_003B2090(u8 *obj)
{
    u8 *p = *(u8 **)(obj + 0x68);
    f32 vel[4];
    f32 pos[4];
    s32 i;
    f32 f20;
    f32 f21;

    for (i = 5; i >= 0; i--) {
        func_L01_00440A88(vel, 0.10000001f, 0.16666667f);
        f20 = func_0037E250(1.0f, 2.0f);
        func_00388830(pos, p, *(f32 *)(p + 0x30));
        vec_add_ba(pos, p + 0x10, pos);
        func_L01_00467DA8(pos, 10, f20, f20, 0x7F076007, 0, func_0037E208(-3, 3), vel, 0.0f, 0);
        f21 = f20 * 0.5f;
        func_L01_00467DA8(pos, 10, f21, f21, 0x7F075F07, 0, func_0037E208(-3, 3), vel, 0.0f, 0);
    }
}
/* localdecomp:end func_L13_003B2090 */
