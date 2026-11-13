#include "common.h"

/* NTSC-U counterpart of func_L05_00323AC0 (src/levels/shared/L05_00323AC0.c): 0.02 -> 0.0166667 */
typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L05_00323320 */
extern u8 *func_003C24B0(s32, s32);

u8 *func_L05_00323320(u8 *object, u128_t *a1, u128_t *a2, float f12, float f13) {
    u128_t v[2];
    u8 *s1;
    u8 *pl;

    v[0] = *a1;
    v[1] = *a2;
    s1 = func_003C24B0(0xD1B, 0x80);

    if (s1 != 0) {
        s1[0x30] = 0xFF;
        *(u16 *)(s1 + 0x32) = 0xFF;
        s1[0x31] = 1;
        s1[0x20] = 0;
        *(u8 **)(s1 + 0xB8) = object;
        pl = *(u8 **)(s1 + 0x68);
        *(long *)(s1 + 0x38) = *(long *)(object + 0x38);
        *(u128_t *)(s1 + 0x10) = *(u128_t *)pl;
        *(u128_t *)pl = v[0];
        *(u128_t *)(pl + 0x20) = v[1];
        *(float *)(pl + 0x3C) = f12;
        *(s32 *)(pl + 0x34) = 0;
        *(s32 *)(pl + 0x38) = 0;
        *(float *)(pl + 0x44) = f13 * 0.0166666675f;
    }
    return s1;
}
/* localdecomp:end func_L05_00323320 */
