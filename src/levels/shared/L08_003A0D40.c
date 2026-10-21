#include "common.h"

/* localdecomp:start func_L08_003A0D40 */
extern void func_003A52A0(s32 a0, s32 a1, u8 *a2);
extern void func_L01_004443E8(u8 *a0, s32 a1, s32 a2);
void func_L08_003A0D40(u8 *a0) {
    func_003A52A0(0, 0, a0);
    *(s32 *)(a0 + 184) = 0;
    func_L01_004443E8(a0, 0, 3);
    *(u16 *)(a0 + 52) &= ~0x20;
}
/* localdecomp:end func_L08_003A0D40 */
