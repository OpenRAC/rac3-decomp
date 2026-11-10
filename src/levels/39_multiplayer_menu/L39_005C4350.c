#include "common.h"

/* localdecomp:start func_L39_005C4350 */
extern u8 D_L39_00225780[];

s32 func_L39_005C4350(void) {
    s32 count;
    s32 i;
    u8 *base;
    u8 *p;

    count = 0;
    base = D_L39_00225780;
    p = base + 0x558;
    for (i = 7; i >= 0; i--) {
        if (*p != 0) {
            count++;
        }
        p += 0x5C0;
    }
    return count;
}
/* localdecomp:end func_L39_005C4350 */
