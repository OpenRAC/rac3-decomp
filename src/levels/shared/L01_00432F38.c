#include "common.h"

/* localdecomp:start func_L01_00432F38 */
extern u32 D_001D4CEC_sda;
extern u32 D_L01_001D4CEC;
__asm__(".extern D_L01_001D4CEC, 16");
void func_L01_00432F38(void) {
    D_001D4CEC_sda = D_L01_001D4CEC | 0x2000;
}
/* localdecomp:end func_L01_00432F38 */

/* localdecomp:start func_L01_00432F50 */
extern u8 D_L01_001DFF20;

u8 func_L01_00432F50(void) {
    return D_L01_001DFF20;
}
/* localdecomp:end func_L01_00432F50 */
