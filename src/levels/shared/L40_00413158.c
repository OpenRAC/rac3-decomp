#include "common.h"

/* localdecomp:start func_L40_00413158 */
typedef int u128_412938 __attribute__((mode(TI)));

typedef union {
    f32 v[4];
    u128_412938 q;
} __attribute__((aligned(16))) Vec4;

extern u8 *D_L40_002497F8[];
extern void func_L01_00446BC8(u8 *, s32, s32, Vec4 *, f32);

void func_L40_00413158(s32 id)
{
    s32 i;
    u8 *p;

    if (id == 0) {
        return;
    }
    for (i = 0; i < 16; i++) {
        p = D_L40_002497F8[i];
        if (p != 0 && *(s32 *)(*(u8 **)(p + 104) + 352) == id) {
            Vec4 c;

            c.q = 0;
            c.v[0] = 1.0f;
            c.v[1] = 1.0f;
            c.v[2] = 1.0f;
            c.v[3] = 1.0f;
            func_L01_00446BC8(p, id, 0x10000, &c, 5.0f);
            return;
        }
    }
}
/* localdecomp:end func_L40_00413158 */
