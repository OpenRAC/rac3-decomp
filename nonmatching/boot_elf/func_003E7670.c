/* PAL near miss (Codex wave 11): near miss: 17 words differ with the file's flags.
 * Worker's note: 17 diff (W/func_003E7670.checks/boot_elf.log), C = the matched frontbin copy func_003E72B8 (src/frontbin/3E7188.c): with this file's default assembler li.s 1.0769231f becomes a gp literal-pool lwc1 (retail: lui/ori/mtc1, 2 words longer) and the hazard nop lands after the case-0 branch target (b 0x14 vs 0x10); everything else equal; needs @ps2as on 3E75D0.c's line, as the frontbin copy's file has
 * Landing test (2026-11-21, the file compiled as the full build does): with @ps2as on 3E75D0.c still 57 diff, and that line breaks func_003E7620 and func_003E7658.
 */
#include "common.h"

/* localdecomp:start func_003E7670 */
extern f32 D_001D9688;
extern f32 D_001D968C;
extern s32 D_001D9690;
extern s32 D_001D9694;
extern f32 D_001D96B0;
extern f32 D_001D96B4;
/* the frontbin copy is func_003E72B8 (src/frontbin/3E7188.c) */
void func_003E7670(s32 mode) {
    extern void func_00391068(f32 *, f32 *, s32);
    f32 v[2];
    D_001D9688 = 1.0f;
    D_001D968C = 1.0f;
    D_001D9690 = 0;
    D_001D9694 = 0;
    D_001D9698 = 512.0f;
    switch (mode) {
    case 0:
        D_001D96A0 = 512.0f;
        D_001D969C = 416.0f;
        D_001D96A4 = 416.0f;
        break;
    case 1:
        D_001D96A0 = 512.0f;
        D_001D969C = 448.0f;
        D_001D96A4 = 448.0f;
        break;
    }
    func_003E7620();
    v[1] = v[0] = 0.0f;
    func_00391068(&v[0], &v[1], 1);
    D_001D96B0 = v[0] * 1.0769231f / D_001D969C;
    D_001D96B4 = (v[1] + v[0] * 0.5f) * 1.0769231f / D_001D969C;
}
/* localdecomp:end func_003E7670 */
