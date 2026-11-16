/* PAL near miss (Codex wave 7): near miss: 48 words differ with the file's flags.
 * Replaces the earlier draft (US draft of func_003CF048; 49 words differ under tools/check.py with the file's flags, measured
 * 2026-11-16; this one: 48).
 * Worker's note: 15 diff with --divs 2,2: build/codex/w362/func_003CF1B0.05.log; pre-call half matches; post-call FP allocation and independent store scheduling differ; ten compiles stopped. Padding 2,2 tested but not an exact metadata claim.
 */
#include "common.h"
/* localdecomp:start func_003CF1B0 */
extern f32 D_001DA670[];
extern s32 D_001DA680[];
extern f32 D_00225B30[];
extern f32 D_00334FB0[];
void func_003CF1B0(void) {
    extern void func_0038CF80();
    f32 scale,a,b,c,dx,dy;
    scale = D_00225B30[0];
    a = D_001DA670[0] * scale;
    b = D_001DA670[1] * scale;
    c = D_001DA670[2] * scale;
    dx = 1.0f / (a - b);
    dy = 1.0f / (b - c);
    D_001DA680[0] = (s32)(D_001DA670[0] * 1024.0f);
    D_001DA680[1] = (s32)(D_001DA670[1] * 1024.0f);
    D_001DA680[2] = (s32)(D_001DA670[2] * 1024.0f);
    func_0038CF80(D_00334FB0,64);
    D_00334FB0[7] = b;
    D_00334FB0[3] = a;
    D_00334FB0[9] = a * dx;
    D_00334FB0[4] = dy * 0.5f;
    D_00334FB0[12] = (c * dy) * -0.5f;
    D_00334FB0[13] = b * dy;
    D_00334FB0[8] = (b * dx) * -0.5f;
    D_00334FB0[0] = dx * 0.5f;
    D_00334FB0[1] = -dx;
    D_00334FB0[5] = -dy;
}
/* localdecomp:end func_003CF1B0 */
