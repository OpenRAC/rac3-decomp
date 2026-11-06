#include "common.h"

/* localdecomp:start func_L39_005A42D8 */
extern s32 D_001A46A8[];
extern s32 D_001D4CEC_sda;

void func_L39_005A42D8(void) {
    s32 previous = *(s32 *)0x0024057C;
    D_001A46A8[0] = 0;
    D_001D4CEC_sda = previous | 0x800;
}
/* localdecomp:end func_L39_005A42D8 */
