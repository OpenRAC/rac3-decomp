#include "common.h"

/* localdecomp:start func_L09_00403E40 */
extern u8 D_L09_001E2B80[];
__asm__(".extern D_L09_001E2B80, 16");
extern u8 *D_L09_001DF884;
__asm__(".extern D_L09_001DF884, 16");

void func_L09_00403E40(s32 arg0, s32 arg1) {
    u8 *e = D_L09_001E2B80 + arg0 * 1120;
    u8 *p = *(u8 **)(e + 0x50);
    s16 k = *(s16 *)(p + 0x84);
    u8 *q = (u8 *)((k << 5) + (s32)D_L09_001DF884);
    u8 *r = *(u8 **)(q + 0x1C);
    *(u8 *)(r + 0x20) = arg1;
}
/* localdecomp:end func_L09_00403E40 */
