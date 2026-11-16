/* PAL near miss (Codex wave 6): near miss: 0 words differ with the file's flags.
 * Worker's note: Improved to 48/49 PAL places MATCH by naming moved level-state data D_L01_001D545C_00459EF0. Only level39 jal at +0x58 differs: catalogue func_L01_00415DC8 is 0x004E51B0; retail calls func_L39_00598770. Requires call placement mapping correction. Logs ...
 */
#include "common.h"
/* localdecomp:start func_L01_00459EF0 */
extern s32 D_L01_001D6690;
extern s32 D_001D545C;
extern s32 D_L01_001DFB90;
void func_L01_00459EF0(void) {
    extern void func_L01_00415DC8(s32);
    if ((u32)(D_L01_001D6690 - 3) < 2) {
        switch (D_001D545C) {
        case 11: break;
        case 18:
        case 20:
        case 26:
        case 29:
            D_L01_001DFB90 = 2;
            break;
        }
        func_L01_00415DC8(D_L01_001DFB90);
    }
}
/* localdecomp:end func_L01_00459EF0 */
