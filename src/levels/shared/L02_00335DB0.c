#include "common.h"

/* localdecomp:start func_L02_00335DB0 */
extern s32 func_L01_00301798(u8 *, s32, s32, s32, s32);

void func_L02_00335DB0(u8 *m) {
    u8 *cls;
    u8 *pv;

    cls = *(u8 **)(m + 36);
    pv = *(u8 **)(m + 104);
    *(u16 *)(m + 52) &= ~0x41;
    *(u16 *)(m + 52) |= *(u16 *)(cls + 68) & 0x1000;
    *(s32 *)(m + 152) = *(s32 *)(cls + 16);
    m[32] = 1;
    *(s32 *)(pv + 304) = 0;
    if (*(s16 *)(m + 170) == 501) {
        *(s32 *)(pv + 300) = func_L01_00301798(m, 0, *(s32 *)(pv + 308), *(s32 *)(pv + 312), *(s32 *)(pv + 316));
    } else if (*(s16 *)(m + 170) == 512) {
        *(s32 *)(pv + 300) = func_L01_00301798(m, 1, *(s32 *)(pv + 308), *(s32 *)(pv + 312), *(s32 *)(pv + 316));
    }
    m[127] = 0;
}
/* localdecomp:end func_L02_00335DB0 */
