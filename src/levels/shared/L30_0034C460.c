#include "common.h"

/* localdecomp:start func_L30_0034C460 */
void func_L30_0034C460(u8 *p, s32 a1, s32 a2, s32 a3, s32 a4) {
    *(s32 *)(p + 0x40) = a1;
    *(s32 *)(p + 0x44) = a2 < 0 ? a1 : a2;
    *(s32 *)(p + 0x48) = a2 < 0 ? a1 : a3;
    *(s32 *)(p + 0x4C) = a2 < 0 ? a1 : a4;
}
/* localdecomp:end func_L30_0034C460 */
