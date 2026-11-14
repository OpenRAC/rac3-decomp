#include "common.h"

/* localdecomp:start func_L21_00338D38 */
extern u8 *D_001A73E8[];

s32 func_L21_00338D38(void) {
    u8 *p = D_001A73E8[0];
    u8 r;
    return r = p != 0 && (u32)(*(u16 *)(p + 0xAA) - 0x1C6B) < 3;
}
/* localdecomp:end func_L21_00338D38 */
