#include "common.h"

/* localdecomp:start func_L14_0035F928 */
typedef int u128_t __attribute__((mode(TI)));
extern s32 D_L14_001E9158[];
extern void func_003C2F58(u8 *a0, s32 a1, u8 *a2);
extern s32 func_003D3CB0(u8 *a0, u128_t *a1, s32 a2, u8 *a3, s32 t0);
s32 func_L14_0035F928(u8 *a0) {
    u8 buf[16];
    u128_t q;
    u8 *s1;
    s32 d;
    s1 = *(u8 **)(a0 + 104);
    func_003C2F58(a0, 0, buf);
    q = *(u128_t *)(s1 + 544);
    if (func_003D3CB0(buf, &q, 16, a0, 0) == 0) {
        return 1;
    }
    d = D_L14_001E9158[0];
    if (d != 0) {
        if (d == *(s32 *)(s1 + 560)) {
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L14_0035F928 */
