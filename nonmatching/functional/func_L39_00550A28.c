/* functional: high. Per-frame update of the multiplayer-menu projectile: when in state 2 it notifies the owner (func_L39_005514A0 with a0 = the object itself, a1 = 0, as retail leaves a0 in place) and finishes; otherwise integrates position by the velocity, clamps/ends it when it leaves the 2..1021 box, runs collision (state 2 on hit), spawns 10 trail points via lerp, and ends when the lifetime counter expires; 122 words differ (register numbering only). */
#include "common.h"
#include "vu0.h"

extern s32 *D_L39_00241120;
extern void func_L39_005514A0(u8 *, u8 *);
extern void func_L39_005515E8(u8 *);
extern void func_L39_005516B0(u8 *, void *);
extern s32 func_L39_00550D48(u8 *, void *);
extern void func_0038CDF8(void *, void *, void *, f32);
extern s32 func_0038CB00(u8 *);

void func_L39_00550A28(u8 *m) {
    u8 *p;
    u8 *owner;
    vu0_v4 old;
    vu0_v4 point;
    f32 *pos;
    s32 i;

    p = *(u8 **)(m + 0x68);
    if (m[0x20] == 2) {
        owner = *(u8 **)(p + 0x3C);
        if (owner != 0 && owner[0x1A14] != 0 && p[0x39] != 0 && p[0x3B] == 0) {
            func_L39_005514A0(m, 0);
        }
        func_L39_005515E8(m);
        return;
    }
    old = *(vu0_v4 *)(m + 0x10);
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
            : "=m"(*(vu0_v4 *)(m + 0x10))
            : "m"(*(vu0_v4 *)(m + 0x10)), "m"(*(vu0_v4 *)p)
            : "vf1", "vf2");
    pos = (f32 *)(m + 0x10);
    if (pos[0] < 2.0f || 1021.0f < pos[0] || pos[1] < 2.0f || 1021.0f < pos[1] || pos[2] < 2.0f ||
        1021.0f < pos[2]) {
        if (pos[0] < 5.0f) pos[0] = 5.0f;
        if (pos[1] < 5.0f) pos[1] = 5.0f;
        if (pos[2] < 5.0f) pos[2] = 5.0f;
        if (1016.0f < pos[0]) pos[0] = 1016.0f;
        if (1016.0f < pos[1]) pos[1] = 1016.0f;
        if (1016.0f < pos[2]) pos[2] = 1016.0f;
        m[0x20] = 2;
        return;
    }
    if (m[0x20] == 0) {
        m[0x20] = 1;
    }
    if (func_L39_00550D48(m, &old) != 0) {
        m[0x20] = 2;
    }
    if (p[0x38] != 1 && *D_L39_00241120 == 1) {
        for (i = 0; i < 10; i++) {
            func_0038CDF8(&point, &old, m + 0x10, (f32)i / 10.0f);
            func_L39_005516B0(m, &point);
        }
    }
    func_L39_005515E8(m);
    if (func_0038CB00(p + 0x42) != 0) {
        m[0x20] = 2;
    }
}
