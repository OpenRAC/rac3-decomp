/* Near miss (b9-t1): 7 words differ (only where retail puts the sq of the quadword copy: after the sb/sw and the loop's address setup; this C puts it right after the lq).
 * Level 3 of the shared file L03_003487D8.c; the extern of D_L03_00281EA0 is new.
 */
#include "common.h"
/* localdecomp:start func_L03_00348B88 */
typedef int u128_348B88 __attribute__((mode(TI)));
extern s32 D_L03_00281EA0[];
extern u8 *func_003C24B0(s32, s32);
u8 *func_L03_00348B88(u8 *a0) {
    u8 *p = func_003C24B0(0x118A, 0x80);
    s32 i;
    if (p != 0) {
        *(u128_348B88 *)(p + 0x10) = *(u128_348B88 *)(a0 + 0x10);
        *(u8 **)(p + 0xB8) = a0;
        p[0x30] = 0xFF;
        for (i = 0; i < 64; i++) {
            D_L03_00281DA0[i] = 0;
            D_L03_00281EA0[i] = 0;
            D_L03_001E13C8[i] = 0;
        }
    }
    return p;
}
/* localdecomp:end func_L03_00348B88 */
