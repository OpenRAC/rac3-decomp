/* functional: high. Callback for the beam end points (registered by func_L04_003D0968 via func_L01_00404A10); VU0 adds as float math. 76 diffs. */
#include "common.h"
#include "vu0.h"
extern void func_0038CE20(void *, void *, f32);
extern void func_L04_003D11F8(u8 *, u8 *);
extern f32 D_L04_001DEB30;
__asm__(".extern D_L04_001DEB30, 4");
extern f32 D_L04_001DEB34;
__asm__(".extern D_L04_001DEB34, 4");

void func_L04_003D1420(u8 *a0) {
    u8 *pv = *(u8 **)(a0 + 0x68);
    u8 *ch = *(u8 **)(pv + 0x94);
    vu0_v4 p0, p1, t;

    if (*(s32 *)(pv + 0x90) < 0) {
        *(vu0_q *)&p0 = *(vu0_q *)(a0 + 0x10);
    } else {
        func_0038CE20(&p0, a0 + 0xE0, D_L04_001DEB30);
        func_0038CE20(&t, a0 + 0xD0, D_L04_001DEB34);
        p0.x += t.x;
        p0.y += t.y;
        p0.z += t.z;
        p0.x += ((vu0_v4 *)(a0 + 0x10))->x;
        p0.y += ((vu0_v4 *)(a0 + 0x10))->y;
        p0.z += ((vu0_v4 *)(a0 + 0x10))->z;
    }
    if (*(s32 *)(ch + 0x90) < 0) {
        *(vu0_q *)&p1 = *(vu0_q *)(*(u8 **)(pv + 0x94) + 0x10);
    } else {
        func_0038CE20(&p1, *(u8 **)(pv + 0x94) + 0xE0, D_L04_001DEB30);
        func_0038CE20(&t, *(u8 **)(pv + 0x94) + 0xD0, -D_L04_001DEB34);
        p1.x += t.x;
        p1.y += t.y;
        p1.z += t.z;
        p1.x += ((vu0_v4 *)(*(u8 **)(pv + 0x94) + 0x10))->x;
        p1.y += ((vu0_v4 *)(*(u8 **)(pv + 0x94) + 0x10))->y;
        p1.z += ((vu0_v4 *)(*(u8 **)(pv + 0x94) + 0x10))->z;
    }
    func_L04_003D11F8((u8 *)&p0, (u8 *)&p1);
}
