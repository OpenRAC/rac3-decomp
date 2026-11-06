#include "common.h"

/* localdecomp:start func_L01_003D0910 */
__asm__(".extern D_L01_001DF360, 4");
extern s32 D_L01_001DF360 __attribute__((section(".sdata")));
extern s32 D_001A4E18 __attribute__((section(".data")));
extern void func_L01_0044F2E8(s32, s32, s32, s32, s32, s32, s32);

void func_L01_003D0910(void) {
    D_001A4E18 = D_L01_001DF360;
    func_L01_0044F2E8(0, 5, 0, 1, 0, 0, 0);
}
/* localdecomp:end func_L01_003D0910 */
