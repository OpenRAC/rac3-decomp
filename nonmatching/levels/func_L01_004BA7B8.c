/* NTSC-U draft (Claude wave S/us): C of func_L01_004B6C20, the NTSC-U twin of func_L01_004BA7B8, with NTSC-U names and addresses (the two versions' code differs).
 * flags: byte-exact on NTSC-U only with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (its file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division") (NTSC-U twin "func_L01_004B6C20", whose code is not the PAL one).
 * Worker's note: MATCH only with @ps2as added (re-checked: with the PAL file src/levels/shared/L01_004BA278.c flags 16 diff: 1.0f is lui/mtc1 in both but 1.2f = 0x3F99999A is loaded by lwc1 from the sdata pool instead of retails inline lui/ori/mtc1 (Ps2EeAs li.s expansion), ...
 */
#include "common.h"

/* localdecomp:start func_L01_004B6C20 */
extern f32 D_L01_001DF9D0;
extern f32 D_L01_001D6720;
__asm__(".extern D_L01_001D6720, 4");
extern void func_00385B60(s32);

void func_L01_004B6C20(void) {
    D_L01_001D6720 = 1.2f;
    if (D_L01_001DF9D0 < 1.0f) {
        func_00385B60(6);
    }
}
/* localdecomp:end func_L01_004B6C20 */
