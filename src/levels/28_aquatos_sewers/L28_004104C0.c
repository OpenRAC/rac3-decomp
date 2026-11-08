#include "common.h"

/* localdecomp:start func_L28_004104C0 */
__asm__(".extern D_L28_001DECA0, 16");
__asm__(".extern D_L28_001DEC9C, 16");
extern u8 *D_L28_001DECA0;
extern u8 *D_L28_001DEC9C;

/* from rac2-decomp's func_L08_003289D0 */
s32 func_L28_004104C0(s32 a0) {
    u8 *p = D_L28_001DEC9C;
    s32 n = 0;
    for (; p < D_L28_001DECA0; p += 0x100) {
        if (p != 0 && *(s16 *)(p + 0xAA) == a0) {
            if (*(u8 *)(p + 0x20) != 0xFE) {
                if (*(u8 *)(p + 0x20) != 0xFD)
                    n++;
            }
        }
    }
    return n;
}
/* localdecomp:end func_L28_004104C0 */
