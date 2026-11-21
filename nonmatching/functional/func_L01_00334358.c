/* functional: high. Near-miss draft (10 words differ, instruction order only); callee names mapped to frontbin names (func_00382348, func_003D3CB0, 0038D160, 0038CED8, 0038DAB8, 0038D098, 0038D0B0, 0038CF38) and all constants/branches checked against the PAL asm. COP2 vsub/vadd via vu0.h-style inline asm helpers. Needs "vu0.h". */
/* localdecomp:start func_L01_00334358 */
#include "vu0.h"
extern u8 D_001A4BE0[];
typedef struct { u8 pad[0x18]; void *hit; } Hit_00334358;
extern Hit_00334358 D_L01_001EAA00;
extern vu0_v4 D_L01_001EAA20;
static __inline__ void sub_00334358(vu0_v4 *vars, vu0_v4 *a, vu0_v4 *b) {
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(*vars) : "m"(*a), "m"(*b) : "vf1", "vf2");
}
static __inline__ void add_00334358(vu0_v4 *vars, vu0_v4 *a, vu0_v4 *b) {
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(*vars) : "m"(*a), "m"(*b) : "vf1", "vf2");
}
void func_L01_00334358(void *object, void *vars, f32 minimum) {
    extern u8 *func_00382348(void *);
    extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
    extern f32 func_0038D160(f32, f32);
    extern f32 func_0038CED8(void *);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern f32 func_0038CF38(void *, void *);
    vu0_v4 from, to, candidate, delta, hit_delta;
    u8 *target;
    f32 angle;
    f32 yaw, length, distance, radians;
    *(vu0_q *)(vars + 0x3F0) = *(vu0_q *)(vars + 0x400);
    *(vu0_q *)&to = *(vu0_q *)(vars + 0x400);
    *(vu0_q *)&from = *(vu0_q *)(object + 0x10);
    to.z += *(f32 *)(vars + 0x198);
    from.z += *(f32 *)(vars + 0x198);
    target = func_00382348(*(void **)(vars + 0x440));
    { u8 *hero = D_001A4BE0;
    if (*(void **)(vars + 0x440) == *(void **)(hero + 0x25C0)) {
        *(vu0_q *)&to = *(vu0_q *)(hero + 0xD0);
    } else if (target != 0) {
        to.z += *(f32 *)(target + 0x10);
    }
    }
    if (func_003D3CB0(&from, &to, 16, object, 0) == 0) return;
    if (D_L01_001EAA00.hit != 0 &&
        D_L01_001EAA00.hit == *(void **)(vars + 0x440)) return;
    for (angle = 10.0f; angle <= 100.0f; angle += 10.0f) {
        sub_00334358(&delta, &to, &from);
        yaw = func_0038D160(delta.x, delta.y);
        length = func_0038CED8(&delta);
        if (length < minimum) length = minimum;
        radians = angle * 0.017453292f;
        candidate.x = func_0038D098(func_0038DAB8(radians, yaw)) * length;
        candidate.y = func_0038D0B0(func_0038DAB8(radians, yaw)) * length;
        candidate.z = 0;
        add_00334358(&candidate, &from, &candidate);
        if (candidate.x < 0) candidate.x = 0.5f;
        if (candidate.y < 0) candidate.y = 0.5f;
        if (candidate.z < 0) candidate.z = 0.5f;
        if (func_003D3CB0(&from, &candidate, 16, object, 0) == 0) {
            *(vu0_q *)(vars + 0x3F0) = *(vu0_q *)&candidate;
            return;
        }
        if (D_L01_001EAA00.hit != 0 &&
            D_L01_001EAA00.hit == *(void **)(vars + 0x440)) {
            *(vu0_q *)(vars + 0x3F0) = *(vu0_q *)&candidate;
        }
        sub_00334358(&hit_delta, (vu0_v4 *)(object + 0x10), &D_L01_001EAA20);
        distance = func_0038CED8(&hit_delta);
        if (*(f32 *)(vars + 0x434) < distance && angle < 60.0f) {
            f32 current = func_0038CF38(&D_L01_001EAA20, vars + 0x400);
            if (current < func_0038CF38(vars + 0x420, vars + 0x400)) {
                *(f32 *)(vars + 0x434) = distance;
                *(vu0_q *)(vars + 0x420) = *(vu0_q *)&D_L01_001EAA20;
            }
        }
        radians = -(angle * 0.017453292f);
        candidate.x = func_0038D098(func_0038DAB8(radians, yaw)) * length;
        candidate.y = func_0038D0B0(func_0038DAB8(radians, yaw)) * length;
        candidate.z = 0;
        add_00334358(&candidate, &from, &candidate);
        if (candidate.x < 0) candidate.x = 0.5f;
        if (candidate.y < 0) candidate.y = 0.5f;
        if (candidate.z < 0) candidate.z = 0.5f;
        if (func_003D3CB0(&from, &candidate, 16, object, 0) == 0) {
            *(vu0_q *)(vars + 0x3F0) = *(vu0_q *)&candidate;
            return;
        }
        if (D_L01_001EAA00.hit != 0 &&
            D_L01_001EAA00.hit == *(void **)(vars + 0x440)) {
            *(vu0_q *)(vars + 0x3F0) = *(vu0_q *)&candidate;
        }
        sub_00334358(&hit_delta, (vu0_v4 *)(object + 0x10), &D_L01_001EAA20);
        distance = func_0038CED8(&hit_delta);
        if (*(f32 *)(vars + 0x434) < distance && angle < 60.0f) {
            *(f32 *)(vars + 0x434) = distance;
            *(vu0_q *)(vars + 0x420) = *(vu0_q *)&D_L01_001EAA20;
        }
    }
}
/* localdecomp:end func_L01_00334358 */
