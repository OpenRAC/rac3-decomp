#include "common.h"

/* NTSC-U counterpart of func_L03_003B9688 (src/levels/shared/L03_003B8F10.c): 0.02 -> 0.0166667 */
#include "vu0.h"

/* localdecomp:start func_L03_003B79E8 */
typedef int u128_3B9760 __attribute__((mode(TI)));
extern u8 *func_003BCFB0(s32, s32);
extern void func_003BDA38(u8 *, s32, u8 *);

u8 *func_L03_003B79E8(u8 *a0, s32 a1, f32 f) {
    u8 *m = func_003BCFB0(0x1C19, 0x80);
    if (m != 0) {
        u8 *pv = *(u8 **)(m + 0x68);
        u8 *s;
        m[0x30] = 0xFF;
        *(s16 *)(m + 0x32) = 0x40;
        m[0x31] = 1;
        *(u8 **)(m + 0xB8) = a0;
        *(f32 *)(pv + 0x20) = f * 0.0166666675f;
        *(s32 *)(pv + 0x28) = 0;
        *(s32 *)(pv + 0x2C) = 0;
        *(s32 *)(pv + 0x34) = a1;
        s = *(u8 **)(a0 + 0x68);
        func_003BDA38(*(u8 **)s, a1, pv + 0x10);
        func_003BDA38(*(u8 **)s, a1 - 0x20, pv);
        *(s32 *)(pv + 0x30) = *(s32 *)s;
        *(u128_3B9760 *)(m + 0x10) = *(u128_3B9760 *)(pv + 0x10);
    }
    return m;
}
/* localdecomp:end func_L03_003B79E8 */
