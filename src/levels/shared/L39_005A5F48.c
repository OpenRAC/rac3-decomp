#include "common.h"

/* localdecomp:start func_L39_005A5F48 */
extern s32 D_L39_002403FC;
__asm__(".extern D_L39_002403FC, 16");
extern s32 D_001A4528[];
extern s32 D_001D4CEC_sda;

void func_L39_005A5F48(void) {
    D_001A4528[0] = 0;
    D_001D4CEC_sda = D_L39_002403FC | 0x800;
}
/* localdecomp:end func_L39_005A5F48 */
