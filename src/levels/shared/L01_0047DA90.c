#include "common.h"

/* localdecomp:start func_L01_0047DA90 */
extern s8 D_L01_001D8224;

void func_L01_0047DA90(void) {
    D_L01_001D8224 = 1;
}
/* localdecomp:end func_L01_0047DA90 */

INCLUDE_ASM("asm/levels", func_L01_0047DAA0);

/* localdecomp:start func_L01_0047DAB0 */
extern u8 D_L01_001D672D[];
extern u8 D_L01_001D8225;

u8 func_L01_0047DAB0(void) {
    if (D_L01_001D672D[0] != 0) {
        D_L01_001D8225 = 0;
    }
    return D_L01_001D8225;
}
/* localdecomp:end func_L01_0047DAB0 */

INCLUDE_ASM("asm/levels", func_L01_0047DAC8);

INCLUDE_ASM("asm/levels", func_L01_0047DAD0);

/* localdecomp:start func_L01_0047DAE0 */
int func_L01_0047DAE0(void) {
    return 8192;
}
/* localdecomp:end func_L01_0047DAE0 */
