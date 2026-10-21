#include "common.h"

/* localdecomp:start func_L39_005FCC58 */
extern u32 D_L39_002412DC;
extern s32 D_L39_0049A680[];
extern s32 D_L39_00242920;
extern s32 D_L39_001E13C8;
extern s32 D_L39_0024CAD8;
extern void func_003A90A0(void);

void func_L39_005FCC58(void) {
    u32 m = D_L39_002412DC;
    u32 k = m;
    if (m >= 37) {
        m = 0;
    }
    D_L39_00242920 = 0x1E000;
    D_L39_001E13C8 = D_L39_0049A680[m];
    if (k - 39 < 21) {
        D_L39_0024CAD8 = 0x120000;
    }
    func_003A90A0();
}
/* localdecomp:end func_L39_005FCC58 */
