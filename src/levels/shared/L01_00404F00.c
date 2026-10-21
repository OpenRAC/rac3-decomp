#include "common.h"

/* localdecomp:start func_L01_00404F00 */
extern s32 D_L01_001DF948;
extern s32 D_001A1ED4[];
extern s32 D_001D4BC4;
extern void func_003A92F0(s32 a0);
extern s32 func_0012C908(s32 a0);
extern void func_003A9108(void);
extern void func_L01_004C5F70(s32 a0, s32 a1, s32 a2);
void func_L01_00404F00(s32 a0) {
    func_003A92F0(1);
    func_0012C908(0);
    D_L01_001DF948++;
    func_003A9108();
    func_L01_004C5F70(a0, D_001A1ED4[0], D_001D4BC4 << 11);
}
/* localdecomp:end func_L01_00404F00 */
