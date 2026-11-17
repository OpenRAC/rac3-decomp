/* PAL near miss (Codex wave 7): near miss: 46 words differ with the file's flags.
 * Worker's note: 46 instruction diffs in w345/func_L01_004226C8.03.log (sentinel/ready allocation and loop scheduling). Contract COMPILE ERROR proven in w345/func_L01_004226C8.contract.log: owner later declares void func_L01_004226C8(void), retail returns flag in v0; needs ...
 */
#include "common.h"
/* localdecomp:start func_L01_004226C8 */
extern u16 D_001D54D8[32] __attribute__((section(".sdata")));
extern u16 D_001D5516;
s32 func_L01_004226C8(void) {
    extern s32 func_L01_00419CC0(s32);
    s32 i, j;
    s32 ready = 1;
    u16 *p = D_001D54D8;
    for (i = 31; i >= 0; i--, p++) {
        if (*p != 0xFFFF) {
            s32 id = *p & 0x3FFF;
            if (!func_L01_00419CC0(id) || id == 0) {
                *p = 0xFFFF;
                ready = 0;
            }
        }
    }
    for (i = 0; i < 32; i++) {
        if (D_001D54D8[i] == 0xFFFF) {
            for (j = i + 1; j < 32; j++) {
                D_001D54D8[j-1] = D_001D54D8[j];
                if (D_001D54D8[j-1] != 0xFFFF) ready = 1;
            }
            D_001D5516 = -1;
        }
    }
    return ready;
}
/* localdecomp:end func_L01_004226C8 */
