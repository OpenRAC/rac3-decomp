#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L33_00353800 */
extern u8 *func_003C24B0(s32, s32);
s32 func_L33_00352760(s32, s32, s32);
void func_L33_003532D8(void *);
void func_L33_00352ED0(void *, s32);

extern f32 D_L33_001DDB28[] __attribute__((section(".sdata")));
__asm__(".extern D_L33_001DDB28, 8");

void *func_L33_00353800(void *pos, void *vel, s32 idx, s32 a3, s32 t0, s32 t1, s32 t2) {
    s32 cls;
    f32 scale;
    u8 *m;
    u8 *v;

    cls = 0x1761 - idx;
    if (func_L33_00352760(1, cls, t2) == 0) {
        return 0;
    }
    scale = D_L33_001DDB28[idx];
    m = func_003C24B0(cls, 0xD0);
    if (m == 0) {
        func_L33_00352760(0, cls, 0);
        return 0;
    }
    *(vu0_q *)(m + 0x10) = *(vu0_q *)pos;
    m[0x30] = 0xFF;
    *(s16 *)(m + 0x32) = 0x40;
    *(f32 *)(m + 0x2C) = scale * *(f32 *)(*(u8 **)(m + 0x24) + 0x24);
    func_L33_003532D8(m);
    v = *(u8 **)(m + 0x68);
    vec_add_ba(v + 0x60, v + 0x60, vel);
    *(s32 *)(v + 0xAC) = -1;
    *(s32 *)(v + 0x98) = t1;
    *(s32 *)(v + 0x9C) = t0;
    *(s32 *)(v + 0xA0) = a3;
    *(s32 *)(v + 0xA4) = -1;
    *(s32 *)(v + 0x70) = 3;
    if (t0 != -1 || (idx == 2 && t1 != t0)) {
        func_L33_00352ED0(m, 0xF);
    } else {
        func_L33_00352ED0(m, 5);
    }
    return m;
}
/* localdecomp:end func_L33_00353800 */
