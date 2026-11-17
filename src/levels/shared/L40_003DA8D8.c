#include "common.h"

/* localdecomp:start func_L40_003DA8D8 */
typedef int u128_003DA8D8 __attribute__((mode(TI)));

extern u8 *func_L01_0046CA28(u8 *a0, s32 a1, s32 a2, s32 a3);

void func_L40_003DA8D8(u8 *m, u128_003DA8D8 *pos, s32 idx) {
    u8 *v = *(u8 **)(m + 0x68);
    u8 **slots = (u8 **)(v + 0x30);
    u8 **slot = &slots[idx];

    if (*slot == 0) {
        u8 *o = func_L01_0046CA28((u8 *)pos, 0, 1, 0);
        *slot = o;
        if (o != 0) {
            o += 0x20;
            *(s32 *)(o + 0xC) = 0;
            *(f32 *)(o + 0x8) = 0.25f;
            *(f32 *)(*slot + 0xC) = 60000.0f;
            if (v[0x43] != 0) {
                *(u32 *)(*slot + 4) = 0x7F003F7F;
            } else {
                *(u32 *)(*slot + 4) = 0x7F7F4040;
            }
        }
    } else {
        *(u128_003DA8D8 *)(*slot + 0x10) = *pos;
        (*slot)[8] += 4;
    }
}
/* localdecomp:end func_L40_003DA8D8 */
