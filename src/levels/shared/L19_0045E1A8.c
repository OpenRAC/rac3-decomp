#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L19_0045E1A8 */
extern u8 *D_L19_0021EF7C[];
extern u8 *func_L01_004618E0(s32);

u8 *func_L19_0045E1A8(u8 *a0, u8 *a1, s32 a2, s32 a3, u8 t0, s16 t1, u8 t2, f32 f12)
{
    u8 *p;
    u8 *q;

    p = func_L01_004618E0(0x29);
    if (p != 0) {
        q = p + 0x20;
        *(u128_t *)(p + 0x10) = *(u128_t *)a0;
        *(s32 *)(p + 4) = a3;
        if (t2 == 0xFF) {
            p[9] = (t0 >> 5) * 16 + 4;
            if (t0 & 1)
                p[3] = 0x48;
            else
                p[3] = 0x44;
        } else {
            p[9] = t0;
            p[3] = t2;
        }
        p[1] = 0;
        p[2] = D_L19_0021EF7C[0][a2];
        *(f32 *)(p + 0xC) = f12 * 210000.0f;
        *(s16 *)(p + 0xA) = t1;
        p[8] = 0xA0;
        *(u8 **)q = a1;
    }
    return p;
}
/* localdecomp:end func_L19_0045E1A8 */
