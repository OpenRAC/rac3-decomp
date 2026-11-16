/* PAL near miss (Codex wave 8): near miss: 155 words differ with the file's flags.
 * Worker's note: 155 word diff; w434/func_L01_003EA190.09.log. Full PAL draft with exact file callee prototypes and complete single VU sequences. Register allocation, EE/VU interleaving and collision-loop scheduling remain; three final wordings retain residual. No added ...
 */
#include "common.h"
/* localdecomp:start func_L01_003EA190 */
#include "vu0.h"
extern u8 D_L01_001E2AA0[];
extern vu0_q D_L01_001EAA30[];
void func_L01_003EA190(u8 *update) {
    extern f32 func_0038CEA8(f32 *);
    extern void func_L01_003E9F40(u8 *update, f32 *gain, f32 *damping);
    extern f32 func_00382BC8(f32 *, f32, f32, f32, f32, f32);
    extern f32 func_0038CE68(f32 *, f32 *);
    extern f32 func_0038D0C8(f32);
    extern f32 func_00382C58(f32 *, f32, f32, f32, f32, f32);
    extern void func_0038CE20(f32 *, f32 *, f32);
    extern void func_0038CE90(f32 *, f32 *, f32 *);
    extern void func_0038D890(f32 *, f32 *, f32 *, f32);
    extern void func_0038CF68(f32 *, f32 *, f32);
    extern s32 func_L01_003FB640(void *, s32, s32, f32);
    vu0_v4 t[10];
    f32 gain, damping;
    u8 *follow = *(u8 **)(update + 0x70);
    u8 *entry = D_L01_001E2AA0 + *(s32 *)(update + 0x94) * 0x460;
    u8 *spring = follow + 0x180;
    u8 *motion = follow + 0x60;
    f32 lengthA, dotA, lengthB, dotB, angleB, angleA, zero, twist, ratio, direction;
    s32 adjusted;
    s32 i;
    __asm__ volatile (
        "lqc2 vf2, %2\n"
        "lqc2 vf1, %1\n"
        "vadd.xyz vf1, vf1, vf2\n"
        "sqc2 vf1, %0"
        : "=m"(*(vu0_v4 *)(follow))
        : "m"(*(vu0_v4 *)(follow + 0xB0)), "m"(*(vu0_v4 *)(follow + 0x180))
        : "vf1", "vf2");
    lengthA = func_0038CEA8((f32 *)spring);
    lengthB = func_0038CEA8((f32 *)(follow + 0x190));
    func_L01_003E9F40(update, &gain, &damping);
    zero = 0.0f;
    lengthB = func_00382BC8((f32 *)(follow + 0x1A8), lengthB, lengthA, gain, damping, zero);
    dotA = func_0038CE68((f32 *)spring, (f32 *)(entry + 0x20));
    angleA = zero;
    if (!(fabs_asm(lengthA) < 0.0001f)) {
        f32 ratio = dotA / lengthA;
        if (ratio > 1.0f) ratio = 1.0f;
        else if (ratio < -1.0f) ratio = -1.0f;
        angleA = func_0038D0C8(ratio);
    }
    dotB = func_0038CE68((f32 *)(spring + 0x10), (f32 *)(entry + 0x20));
    if (fabs_asm(lengthB) < 0.0001f) {
        angleB = 0.0f;
    } else {
        f32 ratio = dotB / lengthB;
        if (ratio > 1.0f) ratio = 1.0f;
        else if (ratio < -1.0f) ratio = -1.0f;
        angleB = func_0038D0C8(ratio);
    }
    angleB = func_00382C58((f32 *)(spring + 0x24), angleB, angleA, 0.015f, 0.2f, 0.0f);
    func_0038CE20(&t[0].x, (f32 *)(entry + 0x20), dotA);
    __asm__ volatile (
        "lqc2 vf2, %2\n"
        "lqc2 vf1, %1\n"
        "vsub.xyz vf1, vf1, vf2\n"
        "sqc2 vf1, %0"
        : "=m"(*(vu0_v4 *)(&t[1]))
        : "m"(*(vu0_v4 *)(spring)), "m"(*(vu0_v4 *)(&t[0]))
        : "vf1", "vf2");
    func_0038CE20(&t[2].x, (f32 *)(entry + 0x20), dotB);
    __asm__ volatile (
        "lqc2 vf2, %2\n"
        "lqc2 vf1, %1\n"
        "vsub.xyz vf1, vf1, vf2\n"
        "sqc2 vf1, %0"
        : "=m"(*(vu0_v4 *)(&t[3]))
        : "m"(*(vu0_v4 *)(spring + 0x10)), "m"(*(vu0_v4 *)(&t[2]))
        : "vf1", "vf2");
    dotA = func_0038CE68(&t[1].x, &t[3].x);
    lengthA = func_0038CEA8(&t[1].x);
    lengthA *= func_0038CEA8(&t[3].x);
    {
    f32 target;
    if (lengthA < 0.0001f) {
        target = 0.0f;
    } else {
        target = 1.5707963705062866f - func_0038D0C8(dotA / lengthA);
    }
    twist = func_00382C58((f32 *)(spring + 0x20), 0.0f, target, 0.015f, 0.2f, 0.0f);
    }
    func_0038CE90(&t[4].x, &t[3].x, (f32 *)(entry + 0x20));
    if (func_0038CE68(&t[4].x, &t[1].x) >= 0.0f) direction = 1.0f;
    else direction = -1.0f;
    func_0038D890(&t[5].x, &t[3].x, (f32 *)(entry + 0x20), twist * direction);
    adjusted = 0;
    i = 0;
    func_0038CE90(&t[4].x, (f32 *)(entry + 0x20), &t[5].x);
    func_0038D890(&t[5].x, &t[5].x, &t[4].x, angleB);
    func_0038CF68((f32 *)(spring + 0x10), &t[5].x, lengthB);
    func_0038CE20(&t[6].x, (f32 *)(entry + 0x20), *(f32 *)(spring + 0x30));
    __asm__ volatile (
        "lqc2 vf2, %2\n"
        "lqc2 vf1, %1\n"
        "vadd.xyz vf1, vf1, vf2\n"
        "sqc2 vf1, %0"
        : "=m"(*(vu0_v4 *)(&t[7]))
        : "m"(*(vu0_v4 *)(&t[6])), "m"(*(vu0_v4 *)(motion + 0x60))
        : "vf1", "vf2");
    __asm__ volatile (
        "lqc2 vf2, %2\n"
        "lqc2 vf1, %1\n"
        "vadd.xyz vf1, vf1, vf2\n"
        "sqc2 vf1, %0"
        : "=m"(*(vu0_v4 *)(update + 0x30))
        : "m"(*(vu0_v4 *)(&t[7])), "m"(*(vu0_v4 *)(spring + 0x10))
        : "vf1", "vf2");
    *(vu0_q *)&t[8] = *(vu0_q *)(update + 0x30);
    for (; i < 3; i++) {
        if (!func_L01_003FB640(update + 0x30, 0x36, 0, 0.25f)) break;
        *(vu0_q *)(update + 0x30) = D_L01_001EAA30[0];
        adjusted = 1;
    }
    if (adjusted) {
        __asm__ volatile (
        "lqc2 vf2, %2\n"
        "lqc2 vf1, %1\n"
        "vsub.xyz vf1, vf1, vf2\n"
        "sqc2 vf1, %0"
        : "=m"(*(vu0_v4 *)(&t[9]))
        : "m"(*(vu0_v4 *)(update + 0x30)), "m"(*(vu0_v4 *)(&t[8]))
        : "vf1", "vf2");
        __asm__ volatile (
        "lqc2 vf1, %1\n"
        "lqc2 vf2, %2\n"
        "vadd.xyz vf2, vf2, vf1\n"
        "sqc2 vf2, %0"
        : "=m"(*(vu0_v4 *)(motion))
        : "m"(*(vu0_v4 *)(&t[9])), "m"(*(vu0_v4 *)(motion))
        : "vf1", "vf2");
        __asm__ volatile (
        "lqc2 vf2, %2\n"
        "lqc2 vf1, %1\n"
        "vadd.xyz vf1, vf1, vf2\n"
        "sqc2 vf1, %0"
        : "=m"(*(vu0_v4 *)(motion + 0x60))
        : "m"(*(vu0_v4 *)(motion + 0x60)), "m"(*(vu0_v4 *)(&t[9]))
        : "vf1", "vf2");
        __asm__ volatile (
        "lqc2 vf1, %1\n"
        "lqc2 vf2, %2\n"
        "vadd.xyz vf2, vf2, vf1\n"
        "sqc2 vf2, %0"
        : "=m"(*(vu0_v4 *)(motion + 0xB0))
        : "m"(*(vu0_v4 *)(&t[9])), "m"(*(vu0_v4 *)(motion + 0xB0))
        : "vf1", "vf2");
        __asm__ volatile (
        "lqc2 vf1, %1\n"
        "lqc2 vf2, %2\n"
        "vadd.xyz vf1, vf1, vf2\n"
        "sqc2 vf1, %0"
        : "=m"(*(vu0_v4 *)(motion + 0x30))
        : "m"(*(vu0_v4 *)(motion + 0x30)), "m"(*(vu0_v4 *)(&t[9]))
        : "vf1", "vf2");
    }
}
/* localdecomp:end func_L01_003EA190 */
