/* func_L01_00455550: matched only compiled after func_L01_00454728's C in the same file: with that function back to INCLUDE_ASM every level differs from +0xF4 on (a vector load scheduled earlier), with every prototype it used still in front (reverted from src/levels/shared/L01_00454728.c, 2026-11-27). */
#include "common.h"
/* localdecomp:start func_L01_00455550 */
/* declared by func_L01_00454728's C before it went back to INCLUDE_ASM */
#include "vu0.h"
extern f32 func_003C4138(f32 *, f32, f32);
extern f32 func_L01_004395E0(void *);
extern s32 func_L01_004461B8(f32, f32, f32, f32 *, f32 *);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern f32 func_L01_00448890(void *, void *, s32, f32, f32, f32, f32);
extern void func_L01_00446780(void *, void *, s32, f32, f32, f32, s32, s32, s32);
extern f32 func_0038CEA8(void *);
extern s32 func_L01_003FB640(void *, s32, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern void func_0038D308(void *, void *);
extern void func_0038D5F0(void *, void *, void *);
#include "vu0.h"

typedef struct {
    u8 pad0[0x1A];
    u8 mode;
    u8 pad1B[0x11];
    f32 boundarySpeed;
    f32 probeRange;
    f32 probeOffset;
    u16 flags;
    u8 pad3A[2];
    f32 slideSpeed;
    f32 minimumHeight;
    u8 pad44[8];
    f32 speed;
    f32 slopeSpeed;
    f32 maxAnimation;
    u8 pad58[8];
    f32 animationThreshold;
    f32 turnTarget;
    f32 turnRate;
    u8 pad6C[0x14];
    vu0_v4 velocity;
} MoveState_00455550;

extern void func_003C5180(void *, void *, s32);
extern void func_L01_004515D8(void *, void *, s32);
extern f32 func_L01_004513A8(void *, s32, s32);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00451388(void *, void *, void *, f32);
extern f32 func_003C4138(f32 *, f32, f32);
extern f32 func_L01_00451580(void *);
extern f32 func_L01_004395E0(void *);
extern s32 func_L01_004461B8(f32, f32, f32, f32 *, f32 *);
extern void func_L01_0044E130(void *, s32 *);
extern f32 func_L01_00451700(void *, void *, s32);
extern f32 func_L01_00448890(void *, void *, s32, f32, f32, f32, f32);
extern void func_0038D308(void *, void *);
extern void func_0038D5F0(void *, void *, void *);
extern void func_L01_00446780(void *, void *, s32, f32, f32, f32, s32, s32, s32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_L01_003FB640(void *, s32, void *, f32);
typedef struct {
    u8 pad0[0x18];
    s32 obstacle;
    s32 kind;
    vu0_v4 hit;
    vu0_v4 corrected;
    vu0_v4 normal;
} Contact_00455550;
extern Contact_00455550 D_L01_001EAA00;

static __inline__ void copy_vec_00455550(vu0_v4 *out, const vu0_v4 *in) {
    vu0_q value;
    __asm__("lqc2 %0, %1" : "=j"(value) : "m"(*in));
    __asm__("sqc2 %1, %0" : "=m"(*out) : "j"(value));
}

s32 func_L01_00455550(u8 *moby, MoveState_00455550 *state) {
    vu0_v4 probeEnd, start, normal, tangent, direction, slide;
    union {
        vu0_v4 rotation[3];
        struct { vu0_v4 turn, slopeAdjustment, rayStart; } vector;
    } transform;
    vu0_v4 rayEnd;
    f32 speed, root0, root1, zero, finalSpeed;
    f32 length, impact, projected;
    s32 result = 0;
    s32 useHit;

    func_003C5180(((vu0_v4 *)(moby + 0x10)), &normal, 0);
    func_L01_004515D8(moby + 0xC0, &normal, 0);
    impact = func_L01_004513A8(((vu0_v4 *)(moby + 0x10)), 0, 0);
    projected = -func_0038CE68((&state->velocity), &normal);

    if (state->mode == 0) {
        func_L01_00451388(moby, (&state->velocity), (&state->velocity), state->speed);
        length = state->speed * func_0038CEA8(&normal);
    } else {
        func_L01_00451388(moby, (&state->velocity), (&state->velocity), state->slopeSpeed);
        length = state->slopeSpeed * func_0038CEA8(&normal);
    }

    *(vu0_q *)&start = *(vu0_q *)(moby + 0x10);
    func_L01_00451388(moby, &start, &start, -state->probeOffset);
    func_0038CF68(&tangent, &normal, -projected);
    vec_sub_ab((&state->velocity), (&state->velocity), &tangent);
    speed = func_0038CEA8((&state->velocity));
    {
        f32 target = 0.04000000283f;
        if (state->mode >= 2) target = 0.0f;
        func_003C4138(&speed, target, state->boundarySpeed);
    }
    func_0038CF68((&state->velocity), (&state->velocity), speed);
    vec_add_ab((&state->velocity), (&state->velocity), &tangent);

    if (*(f32 *)(moby + 0x10) < 2.0f || *(f32 *)(moby + 0x10) > 1021.0f || *(f32 *)(moby + 0x14) < 2.0f || *(f32 *)(moby + 0x14) > 1021.0f ||
        *(f32 *)(moby + 0x18) < 2.0f || *(f32 *)(moby + 0x18) > 1021.0f) {
        result = 1;
    }
    if (state->mode != 0 && func_L01_00451580(((vu0_v4 *)(moby + 0x10))) < state->minimumHeight) {
        result |= 1;
    }

    if (state->animationThreshold > 0.0f && state->maxAnimation > 0.0f) {
        switch (state->mode) {
        case 0:
            {
            f32 distance = fabs_asm(projected / length);
            if (distance > 2.0f) {
                f32 speed = 2.0f * (state->maxAnimation - func_L01_004395E0(moby)) / distance;
                if (speed > 0.0f) func_003C4138((f32 *)(moby + 0x48), speed, 0.1200000048f);
            }
            }
            break;
        case 1:
            if (state->animationThreshold <= func_L01_004395E0(moby)) {
                *(f32 *)(moby + 0x48) = 0.0f;
            } else {
                f32 acceleration = length * -0.5f;
                f32 speed;
                length = 60.0f;
                if (func_L01_004461B8(acceleration, projected - acceleration, impact, &root0, &root1) > 0 &&
                    root0 > 0.0f && root0 < length) {
                    length = root0;
                }
                if (length < 0.0001f) length = 0.0001f;
                speed = 2.0f * (state->animationThreshold - func_L01_004395E0(moby)) / length;
                if (speed > 2.0f) speed = 2.0f;
                else if (speed < 0.0f) speed = 0.0f;
                func_003C4138((f32 *)(moby + 0x48), speed, 0.1200000048f);
            }
            break;
        case 2:
            *(f32 *)(moby + 0x48) = 1.0f;
            func_0038CF68(&direction, &normal, -0.2f);
            vec_add_ba(&direction, &direction, ((vu0_v4 *)(moby + 0x10)));
            func_0038CF68(&slide, &normal, 1.0f);
            vec_add_ab(&slide, &slide, ((vu0_v4 *)(moby + 0x10)));
            if (!func_003D3CB0(&direction, &slide, 2, moby, 0)) state->mode = 1;
            break;
        }
    }

    func_L01_0044E130(&direction, (s32 *)&state->turnTarget);
    {
        f32 yaw = func_L01_00451700(moby, &direction, 0);
        zero = 0.0f;
        func_L01_00448890(&zero, &state->turnRate, 0, yaw, 0.02010619454f, 0.005026548635f, 3.14159274f);
    }
    qzero(&slide);
    slide.z = state->turnRate;
    func_0038D308(transform.rotation, &slide);
    func_0038D5F0(moby + 0xC0, moby + 0xC0, transform.rotation);

    vec_add_ab(((vu0_v4 *)(moby + 0x10)), ((vu0_v4 *)(moby + 0x10)), (&state->velocity));
    vec_add_ab(&probeEnd, &start, (&state->velocity));
    vec_add_ab(&direction, &probeEnd, (&state->velocity));
    func_L01_00446780(moby, &direction, 0x8000000, state->probeRange, 1.0f, 1.0f, 0, 1, 0);

    if (state->probeRange < func_0038CEA8((&state->velocity)) && func_003D3CB0(&start, &probeEnd, 0x24, moby, 0)) {
        *(vu0_q *)&probeEnd = *(vu0_q *)&D_L01_001EAA00.hit;
    }

    {
        s32 missed = func_L01_003FB640(&probeEnd, 0x24, moby, state->probeRange);
        useHit = 0;
        if (!missed) {
            if (!func_003D3CB0(&probeEnd, ((vu0_v4 *)(moby + 0x10)), 0x24, moby, 0)) goto finish;
            useHit = 1;
        }
    }
    result |= 4;
    if (useHit) {
        *(vu0_q *)(moby + 0x10) = *(vu0_q *)&D_L01_001EAA00.hit;
    } else {
        *(vu0_q *)(moby + 0x10) = *(vu0_q *)&D_L01_001EAA00.corrected;
        func_0038CF68(&transform.vector.turn, &normal, state->probeOffset);
        vec_add_ab(((vu0_v4 *)(moby + 0x10)), ((vu0_v4 *)(moby + 0x10)), &transform.vector.turn);
    }

    length = 1.0f;
    func_0038CF68(&slide, &D_L01_001EAA00.normal, length);
    if (func_0038CE68(&slide, &normal) <= -0.707f) {
        f32 dot = func_0038CE68((&state->velocity), &slide);
        if (dot < 0.0f) {
            if (D_L01_001EAA00.obstacle == 0 || D_L01_001EAA00.kind > 0) {
                func_0038CF68(&transform.vector.rayStart, moby + 0xE0, 0.2f);
                func_0038CF68(&rayEnd, moby + 0xE0, -2.0f);
                vec_add_ba(&transform.vector.rayStart, &transform.vector.rayStart, ((vu0_v4 *)(moby + 0x10)));
                vec_add_ba(&rayEnd, &rayEnd, ((vu0_v4 *)(moby + 0x10)));
                if (func_003D3CB0(&transform.vector.rayStart, &rayEnd, 2, moby, 0)) state->mode = 2;
            }
            func_0038CF68(&transform.vector.slopeAdjustment, &slide, dot);
            vec_sub_ab((&state->velocity), (&state->velocity), &transform.vector.slopeAdjustment);
            if (state->mode == 2) {
                finalSpeed = func_0038CEA8((&state->velocity));
                func_003C4138(&finalSpeed, 0.0f, state->slopeSpeed);
                func_0038CF68((&state->velocity), (&state->velocity), finalSpeed);
            }
        }
    } else {
        f32 dot = func_0038CE68((&state->velocity), &slide);
        if (dot < 0.0f) {
            dot = dot * -(state->slideSpeed + length);
            func_0038CF68(&transform.vector.slopeAdjustment, &slide, dot);
            vec_add_ab((&state->velocity), (&state->velocity), &transform.vector.slopeAdjustment);
        }
    }

finish:
    if (state->mode == 0 && projected < 0.0f) {
        state->mode = 1;
    } else if (state->flags & 2) {
        if ((result & 4) && projected <= 0.0f) result |= 1;
    } else if (moby[0x60] & 2) {
        result |= (state->flags & 1) ? 1 : 2;
    }
    return result;
}
/* localdecomp:end func_L01_00455550 */
