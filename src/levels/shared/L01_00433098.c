#include "common.h"

/* localdecomp:start func_L01_00433098 */
__asm__(".extern D_001D4CEC_sda, 4");
__asm__(".extern D_L01_001D4CEC, 16");
extern s32 D_001D4CEC_sda;
extern s32 D_L01_001D4CEC;
void func_L01_00433098(void) {
    D_001D4CEC_sda = D_L01_001D4CEC | 0x20;
}
/* localdecomp:end func_L01_00433098 */
