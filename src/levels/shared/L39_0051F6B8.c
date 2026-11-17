#include "common.h"

/* localdecomp:start func_L39_0051F6B8 */
typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;

extern s32 func_L01_00457458(s32, s32);
extern void func_003C2880(u8 *);

void func_L39_0051F6B8(u8 *m) {
    Vec4 v;
    u8 *p;

    if (m == 0) {
        return;
    }
    if (m[32] == 254) {
        return;
    }
    if (m[32] == 253) {
        return;
    }
    p = *(u8 **)(m + 104);
    if (p == 0) {
        return;
    }
    if (!func_L01_00457458(*(s16 *)(m + 170), *(s32 *)(p + 40))) {
        func_003C2880(m);
    } else {
        v.q = *(u128_t *)(m + 16);
        v.f[3] = 2.0f;
    }
}
/* localdecomp:end func_L39_0051F6B8 */
