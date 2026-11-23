/* functional: medium. check.py at level_06: 95 diffs, almost all a one-instruction shift (retail cross-jumps the two func_0038CE20 calls of the +-0.35f select); everything after the select is identical per the draft's notes. */
#include "vu0.h"
#include "common.h"
extern void func_003C2F58(u8 *a, s32 b, f32 *out);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern u8 *func_L06_00359650(u8 *a0, u8 *a1, f32 *a2, s32 a3, f32 f);
extern void func_L01_0046E078(s32, void *, void *, void *, s32);
extern void func_L06_00354828(u8 *, u8 *, void *, s32);
__asm__(".extern D_L06_001DD2E0, 4");
extern s32 D_L06_001DD2E0[2];
__asm__(".extern D_L06_001DD2F0, 4");
extern s32 D_L06_001DD2F0[2];
__asm__(".extern D_L06_001DD2F8, 4");
extern u8 D_L06_001DD2F8;

void func_L06_00352648(u8 *a0, u8 *a1, s32 side) {
    vu0_v4 pos;
    vu0_v4 dir;
    vu0_v4 p;
    vu0_v4 q;
    vu0_v4 t;
    s32 i;

    func_003C2F58(*(u8 **)(a1 + 0x260), D_L06_001DD2E0[side], (f32 *)&pos);
    if (side == 0) {
        func_0038CE20(&t, *(u8 **)(a1 + 0x260) + 0xD0, -0.35f);
    } else {
        func_0038CE20(&t, *(u8 **)(a1 + 0x260) + 0xD0, 0.35f);
    }
    vec_add_ab(&pos, &t, &pos);
    pos.z += 0.3f;
    func_0038CE20(&dir, *(u8 **)(a1 + 0x260) + 0xC0, 0.2f);
    dir.z = 1.0f;
    func_0038CF68(&dir, &dir, 0.6f);
    func_L06_00359650(a0, (u8 *)&pos, (f32 *)&dir, ((*(s32 *)(a1 + 0x35C) - 1) & 3) == 0, a1[0x45]);
    func_003C2F58(*(u8 **)(a1 + 0x260), D_L06_001DD2F0[side], (f32 *)&p);
    qzero(&q);
    q.z += -0.36f;
    for (i = 3; i >= 0; i--) {
        func_L01_0046E078(0, &p, &q, &D_L06_001DD2F8, 1);
        func_0038CE20(&q, &q, 0.75f);
    }
    func_L06_00354828(a0, a1, &p, 15);
}
