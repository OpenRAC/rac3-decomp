/* NTSC-U draft (Claude wave C2): C of func_L19_003AD7D8, the NTSC-U twin of func_L19_003AF428, with NTSC-U names and addresses (the two versions' code differs).
 * flags: byte-exact on NTSC-U only with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (its file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division") (NTSC-U twin "func_L19_003AD7D8", whose code is not the PAL one).
 * Worker's note: flags: byte-exact (MATCH) only with BOTH -mvu0-use-vf0-vf2 (vec_add_ab from vu0.h) and @ps2as (inline li.s +-0.0349066 for func_0037E250) but its PAL file L19_003AF1D0.c has neither; with the PAL flags it does not compile (vu0 helper) and the float consts ...
 */
#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L19_003AF428 (src/levels/shared/L19_003AF1D0.c) */
/* localdecomp:start func_L19_003AD7D8 */
extern u8 D_L19_001E8E60[];
extern u8 *func_003BCFB0(s32, s32);
extern f32 func_0037E250(f32, f32);
extern void func_L01_00452E70(void *, void *);
extern void func_00388830(void *, void *, f32);
extern s32 func_003CE740(void *, void *, s32, s32, s32);
extern void func_003886E8(void *, void *, f32);
extern void func_L01_00441FB8(void *, s32, s32);

u8 *func_L19_003AD7D8(u8 *a0, u8 *a1, u8 *a2) {
    f32 v0[4] __attribute__((aligned(16)));
    f32 v10[4] __attribute__((aligned(16)));
    u8 *m;
    u8 *d;
    vu0_q q;

    m = func_003BCFB0(0x1AB7, 0x80);
    if (m != 0) {
        d = *(u8 **)(m + 0x68);
        *(s32 *)d = 200;
        *(f32 *)(d + 8) = func_0037E250(-0.03490659f, 0.03490659f);
        *(vu0_q *)(d + 0x20) = *(vu0_q *)a2;
        func_L01_00452E70(m, a0);
        q = *(vu0_q *)a1;
        *(vu0_q *)(m + 0x10) = q;
        *(vu0_q *)v10 = q;
        func_00388830(v0, d + 0x20, -0.5f);
        vec_add_ab(v0, v0, v10);
        if (func_003CE740(v0, v10, 2, 0, 0) != 0) {
            *(vu0_q *)(m + 0x10) = *(vu0_q *)D_L19_001E8E60;
            func_003886E8(d + 0x20, d + 0x20, -1.0f);
        }
        func_L01_00441FB8(m, 0, 0);
    }
    return m;
}
/* localdecomp:end func_L19_003AD7D8 */
