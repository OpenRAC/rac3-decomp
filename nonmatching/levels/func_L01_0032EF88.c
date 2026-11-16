/* NTSC-U draft (Claude wave S/us): C of func_L01_0032EA90, the NTSC-U twin of func_L01_0032EF88, with NTSC-U names and addresses (the two versions' code differs).
 * flags: byte-exact on NTSC-U only with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as -mvu0-use-vf0-vf2" (its file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division") (NTSC-U twin "func_L01_0032EA90", whose code is not the PAL one).
 * Worker's note: 5 diff with both flags (C near/func_L01_0032EA90.xhigh.c; plain flags COMPILE ERROR vf17 spill, the file line lacks @ps2as and -mvu0-use-vf0-vf2): retail pos=vf2, sub=vf1 and the sub pointer lw into a1, mine pos=vf1, sub=vf2 and lw into v1 (vadd.xyz ...
 */
#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L01_0032EF88 (src/levels/shared/L01_0032C6B8.c) */
/* localdecomp:start func_L01_0032EA90 */
extern f32 D_L01_001DCEF0;
__asm__(".extern D_L01_001DCEF0, 4");
extern void func_L01_004C4190(void *, f32);
extern s32 func_003CE740(void *, void *, s32, void *, s32);

void func_L01_0032EA90(u8 *obj) {
    vu0_v4 old;

    old = *(vu0_v4 *)(obj + 0x10);
    vec_add_ba(obj + 0x10, obj + 0x10, *(void **)(obj + 0x68));
    func_L01_004C4190(obj + 0x10, D_L01_001DCEF0 * 0.00027777778f * 0.1f);
    if (func_003CE740(&old, obj + 0x10, 0x10, obj, 0) != 0) {
        obj[0x20] = 8;
    }
}
/* localdecomp:end func_L01_0032EA90 */
