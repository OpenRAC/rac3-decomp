#include "common.h"

/* localdecomp:start func_L40_003F6028 */
extern u8 *D_L40_00241640[];
s32 func_L40_003F6028(u8 *a0) {
    s32 r = 1;
    if (*(s16 *)(a0 + 0xAA) == 0xCBE && *(s32 *)(D_L40_00241640[0] + 0x180) != 1) {
        a0 = *(u8 **)(a0 + 0x68);
        if (*(s32 *)(a0 + 0x40) != 0 || *(s32 *)(a0 + 0xB8) >= 3) {
            r = 0;
        }
    }
    return r;
}
/* localdecomp:end func_L40_003F6028 */
