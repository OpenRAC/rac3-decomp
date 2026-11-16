/* PAL near miss (Claude wave S2/pal): near miss: 6 words differ with the file's flags.
 * Worker's note: 6 diff with --as ps2as and NEEDS divs row 'func_L16_00434AE8 2' (injected): only the schedule of sd $ra / lui $a0 / addiu $a3 vs the nops differs. Also needs @ps2as (file line lacks it: float consts lui/mtc1) and D_L16_001E6EF4 declared as an array (not ...
 */
#include "common.h"

/* localdecomp:start func_L16_00434AE8 */
extern s32 D_L16_001E6EF4[];
extern s32 D_001D6C88_sda;
__asm__(".extern D_001D6C88_sda, 4");
extern u8 D_L16_001DFF70[];
extern void func_003D9740(void *, s32, s32, s32, s32, f32);

void func_L16_00434AE8(void) {
    s32 a = 0xFF - (s32)((f32)(D_L16_001E6EF4[0] - D_001D6C88_sda) / 15.0f * 255.0f);
    s32 hi = a << 24;
    s32 lo = a | 0xFF00;
    func_003D9740(D_L16_001DFF70, 30, hi | lo, 10, 1, 0.0f);
}
/* localdecomp:end func_L16_00434AE8 */
