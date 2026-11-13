#include "common.h"

/* localdecomp:start func_L30_003A8D68 */
#include "vu0.h"

extern s32 D_L30_001DEAB0;
extern s32 D_L30_001DEAB4;
extern vu0_q D_L30_002A2560[];
extern s32 func_L01_004561B8(u8 *);
extern void func_L01_004450F0(u8 *, s32, s32);

void func_L30_003A8D68(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    s32 i;

    if (a0[0x20] == 0) {
        if (func_L01_004561B8(a0)) {
            D_L30_001DEAB4 = 0;
            D_L30_001DEAB0 = 1;
            a0[0x30] = 0xFF;
            qzero(s);
            qzero(s + 0x10);
            *(s32 *)(s + 0x20) = 0;
            *(s32 *)(s + 0x24) = 0;
            *(s32 *)(s + 0x28) = 0;
            for (i = 0x1F; i >= 0; i--) {
                qzero(&D_L30_002A2560[i]);
            }
        }
        func_L01_004450F0(a0, 1, -1);
    }
}
/* localdecomp:end func_L30_003A8D68 */

INCLUDE_ASM("asm/levels", func_L30_003A8E10);
