#include "common.h"

/* localdecomp:start func_L16_004DCA98 */
extern s32 D_L16_001DFC40;
__asm__(".extern D_L16_001DFC40, 16");
extern s32 D_L16_001DB03C __attribute__((section(".sdata")));

void func_L16_004DCA98(s32 value) {
    D_L16_001DB03C = D_L16_001DFC40 + value;
}
/* localdecomp:end func_L16_004DCA98 */
