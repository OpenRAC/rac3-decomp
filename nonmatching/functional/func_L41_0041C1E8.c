/* functional: high. 53 instructions differ (branch layout/scheduling); returns 0 on both failure paths exactly as retail (v0 = null). */
#include "common.h"
/* localdecomp:start func_L41_0041C1E8 */
#include "vu0.h"
extern u8 D_L41_0025BAC0[];
extern u8 *func_L01_00447490(void *, s32, s32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);

u8 *func_L41_0041C1E8(u8 *obj) {
    u8 *e = func_L01_00447490(obj, -1, 0);
    if (e == 0) {
        return 0;
    }
    if (e[0x29] < 3) {
        obj[0xA8] = 0xFF;
        return 0;
    }
    if (*(s16 *)(*(u8 **)(e + 0x20) + 0xAA) != 0x108F) {
        return e;
    }
    {
        vu0_v4 a;
        vu0_v4 b;
        qzero(&a);
        a.z = 0.25f;
        qzero(&b);
        b.z = -0.25f;
        vec_add_ab(&a, &a, *(u8 **)(e + 0x20) + 0x10);
        vec_add_ab(&b, &b, *(u8 **)(e + 0x20) + 0x10);
        if (func_003D3CB0(&a, &b, 1, *(void **)(e + 0x20), 0) != 0 && *(u8 **)(D_L41_0025BAC0 + 0x18) == obj) {
            *(vu0_q *)e = *(vu0_q *)(D_L41_0025BAC0 + 0x20);
        } else {
            *(vu0_q *)e = 0;
        }
    }
    return e;
}
/* localdecomp:end func_L41_0041C1E8 */
