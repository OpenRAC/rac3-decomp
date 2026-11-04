#include "common.h"

/* localdecomp:start func_L10_004399A0 */
extern s32 *D_L10_001DEF4C[];
extern u8 *D_L10_001DEF48[];
extern void func_L01_00456270(s32);

s32 func_L10_004399A0(s32 a, s32 n) {
    s32 i;
    u8 *rec;
    s32 *p;
    s32 cnt;
    s32 *q;

    if (n >= 0) {
        q = D_L10_001DEF4C[0];
        if (!(n < q[0])) {
            return 0;
        }
    } else {
        return 0;
    }
    func_L01_00456270(n);
    p = (s32 *)(D_L10_001DEF48[0] + n * 0xE0);
    cnt = ((u8 *)p)[4];
    if (cnt == 0) {
        return 0;
    }
    for (i = 0; i < cnt; i++) {
        if (p[0] != 0 && p[0] == a) {
            return 1;
        }
        p += 2;
    }
    return 0;
}
/* localdecomp:end func_L10_004399A0 */
