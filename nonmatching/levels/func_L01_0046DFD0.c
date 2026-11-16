/* NTSC-U draft (Claude wave S/us): C of func_L01_0046A920, the NTSC-U twin of func_L01_0046DFD0, with NTSC-U names and addresses (the two versions' code differs).
 * flags: byte-exact on NTSC-U only with "-mvu0-use-vf0-vf2" (its file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as") (NTSC-U twin "func_L01_0046A920", whose code is not the PAL one).
 * Worker's note: byte-exact (MATCH, C in near/func_L01_0046A920.xhigh.c) only with -mvu0-use-vf0-vf2 added to the PAL file line (-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as): without it the vu0.h j-class asm fails (vf17 spilled), so it cannot land. Levers that took 30 ...
 */
#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of the PAL function at the same position (L01, @ps2as neighbours) */
/* localdecomp:start func_L01_0046A920 */
typedef struct {
    u8 pad_00[0x10];
    vu0_v4 pos;
    vu0_v4 vel;
} Obj_46A920;

extern f32 D_L01_001E0320;
__asm__(".extern D_L01_001E0320, 16");
extern f32 D_L01_001E0328;
extern void func_003C7CE0(void *);

void func_L01_0046A920(Obj_46A920 *o) {
    vu0_v4 g;
    vu0_v4 *p = &o->vel;
    f32 w = p->w;

    if (*(f32 *)((u8 *)o + 0x18) < w) {
        func_003C7CE0(o);
        return;
    }
    g = o->vel;
    g.w = 0.0f;
    vec_add_ba(&o->pos, &o->pos, &g);
    g.z = -0.00013888889f;
    g.x = 0.0f;
    g.y = 0.0f;
    vec_add_ba(&o->pos, &o->pos, &D_L01_001E0320);
    g.w = 0.0f;
    vec_add_ba(&o->vel, &g, &o->vel);
    p->w = w + D_L01_001E0328;
}
/* localdecomp:end func_L01_0046A920 */
