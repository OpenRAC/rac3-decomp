#include "common.h"

/* localdecomp:start func_L35_0031FFD8 */
extern s32 D_L35_001E10D0;

void func_L35_0031FFD8(void) {
    s32 i;
    s32 *p;
    i = 6;
    p = &D_L35_001E10D0;
    do {
        *p = 0;
        i--;
        p--;
    } while (i >= 0);
}
/* localdecomp:end func_L35_0031FFD8 */
