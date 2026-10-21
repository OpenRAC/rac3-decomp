#include "common.h"

/* localdecomp:start func_L01_003F34E0 */
extern u8 D_L01_001E2FD0[];

u8 *func_L01_003F34E0(s32 a0, s32 a1) {
    u8 *p = D_L01_001E2FD0 + a0 * 8448;
    s32 i;
    for (i = 0; i < 48; i++) {
        if (*(s16 *)(p + 134) == a1) {
            return p;
        }
        p += 176;
    }
    return 0;
}
/* localdecomp:end func_L01_003F34E0 */
