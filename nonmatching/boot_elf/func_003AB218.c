/* PAL near miss (Codex wave 11): flags: byte-exact only with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division -mno-split-addresses @ps2as" (its file's line: "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division -mno-split-addresses").
 * Worker's note: NEEDS flags '-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division -mno-split-addresses @ps2as': with the file's line p10 check.py prints 16 diff, all from the default assembler pooling 1.076923f and 0.9f in .lit4 (lwc1 via gp) where retail builds them inline (lui/ori/mtc1); tools/check.py --as ps2as prints func_003AB218: MATCH (W/func_003AB218.ps2as.log). D_001DA078 is aliased D_001DA078_003AB218 (later C declares it f32[]); D_001DA074 is f32[] for retail's lui/swc1 form
 * Landing test (2026-11-21, the file compiled as the full build does) with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division -mno-split-addresses @ps2as": byte-exact with that line, but on 3AAD90.c it breaks func_003AB1D8 and func_003AB1F8 (8 diff each): needs a file of its own.
 */
#include "common.h"

/* localdecomp:start func_003AB218 */
extern s32 D_001DA070;
extern f32 D_001DA074[];
extern f32 D_001DA078_003AB218;
void func_003AB218(s32 on) {
    f32 f;
    D_001DA070 = on;
    f = 1.076923f;
    if (on == 0) {
        f = 1.0f;
    }
    D_001DA074[0] = f;
    f = 0.9f;
    if (on == 0) {
        f = 1.0f;
    }
    D_001DA078_003AB218 = f;
}
/* localdecomp:end func_003AB218 */
