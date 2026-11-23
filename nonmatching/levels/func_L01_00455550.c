/* PAL near miss (sol-round3-b): 496 words differ with the file flags; 323 with diagnostic 2 2 2 division padding. The frame size matches, with stack offsets, saved registers, and instruction scheduling still differing. */
#include "common.h"
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
extern void func_L01_00446780(void *, void *, s32, s32, s32, s32, f32, f32, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_L01_003FB640(void *, s32, void *, f32);
extern vu0_q D_L01_001EAA20[];
extern vu0_q D_L01_001EAA30[];
extern vu0_v4 D_L01_001EAA40[];
extern s32 D_L01_001EAA18[];
extern s32 D_L01_001EAA1C[];

static __inline__ void copy_vec_00455550(vu0_v4 *out, const vu0_v4 *in) {
    vu0_q value;
    __asm__("lqc2 %0, %1" : "=j"(value) : "m"(*in));
    __asm__("sqc2 %1, %0" : "=m"(*out) : "j"(value));
}

s32 func_L01_00455550(u8 *moby, MoveState_00455550 *state) {
    vu0_v4 rayEnd;
    union {
        vu0_v4 rotation[3];
        struct { vu0_v4 turn, slopeAdjustment, rayStart; } vector;
    } transform;
    vu0_v4 slide, direction, tangent, normal, start, probeEnd;
    f32 length, impact, root0, root1, zero, projected;
    vu0_v4 savedStart, savedVelocity;
    vu0_v4 *pos = (vu0_v4 *)(moby + 0x10);
    vu0_v4 *velocity = &state->velocity;
    s32 result = 0;
    s32 useHit;

    func_003C5180(pos, &normal, 0);
    func_L01_004515D8(moby + 0xC0, &normal, 0);
    impact = func_L01_004513A8(pos, 0, 0);
    projected = -func_0038CE68(velocity, &normal);

    if (state->mode == 0) {
        func_L01_00451388(moby, velocity, velocity, state->speed);
        length = state->speed * func_0038CEA8(&normal);
    } else {
        func_L01_00451388(moby, velocity, velocity, state->slopeSpeed);
        length = state->slopeSpeed * func_0038CEA8(&normal);
    }

    *(vu0_q *)&start = *(vu0_q *)pos;
    func_L01_00451388(moby, &start, &start, -state->probeOffset);
    func_0038CF68(&tangent, &normal, -projected);
    vec_sub_ab(velocity, velocity, &tangent);
    {
        f32 speed = func_0038CEA8(velocity);
        func_003C4138(&speed, state->mode < 2 ? 0.04000000283f : 0.0f, state->boundarySpeed);
        func_0038CF68(&tangent, &tangent, speed);
        vec_add_ab(velocity, velocity, &tangent);
    }

    if (*(f32 *)(moby + 0x10) < 2.0f || *(f32 *)(moby + 0x10) > 1021.0f || *(f32 *)(moby + 0x14) < 2.0f || *(f32 *)(moby + 0x14) > 1021.0f ||
        *(f32 *)(moby + 0x18) < 2.0f || *(f32 *)(moby + 0x18) > 1021.0f) {
        result = 1;
    }
    if (state->mode != 0 && func_L01_00451580(pos) < state->minimumHeight) {
        result |= 1;
    }

    if (state->animationThreshold > 0.0f && state->maxAnimation > 0.0f) {
        switch (state->mode) {
        case 0:
            length = fabs_asm(projected / length);
            if (length > 2.0f) {
                f32 speed = 2.0f * (state->maxAnimation - func_L01_004395E0(moby)) / length;
                if (speed > 0.0f) func_003C4138((f32 *)(moby + 0x48), speed, 0.1200000048f);
            }
            break;
        case 1:
            if (state->animationThreshold <= func_L01_004395E0(moby)) {
                *(f32 *)(moby + 0x48) = 0.0f;
            } else {
                f32 acceleration = length * -0.5f;
                f32 time = 60.0f;
                f32 speed;
                if (func_L01_004461B8(acceleration, projected - acceleration, impact, &root0, &root1) > 0 &&
                    root0 > 0.0f && root0 < time) {
                    time = root0;
                }
                if (time < 0.0001f) time = 0.0001f;
                speed = 2.0f * (state->animationThreshold - func_L01_004395E0(moby)) / time;
                if (speed > 2.0f) speed = 2.0f;
                else if (speed < 0.0f) speed = 0.0f;
                func_003C4138((f32 *)(moby + 0x48), speed, 0.1200000048f);
            }
            break;
        case 2:
            *(f32 *)(moby + 0x48) = 1.0f;
            func_0038CF68(&direction, &normal, -0.2f);
            vec_add_ba(&direction, &direction, pos);
            func_0038CF68(&slide, &normal, 1.0f);
            vec_add_ab(&slide, &slide, pos);
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

    copy_vec_00455550(&savedVelocity, velocity);
    copy_vec_00455550(&savedStart, &start);
    vec_add_ab(pos, pos, &savedVelocity);
    copy_vec_00455550(&savedVelocity, velocity);
    vec_add_ba(&probeEnd, &savedStart, velocity);
    vec_add_ab(&direction, &probeEnd, &savedVelocity);
    func_L01_00446780(moby, &direction, 0x8000000, 0, 1, 0, state->probeRange, 1.0f, 1.0f);

    if (state->probeRange < func_0038CEA8(velocity) && func_003D3CB0(&start, &probeEnd, 0x24, moby, 0)) {
        *(vu0_q *)&probeEnd = D_L01_001EAA20[0];
    }

    useHit = 0;
    if (!func_L01_003FB640(&probeEnd, 0x24, moby, state->probeRange)) {
        if (!func_003D3CB0(&probeEnd, pos, 0x24, moby, 0)) goto finish;
        useHit = 1;
    }
    result |= 4;
    if (useHit) {
        *(vu0_q *)pos = D_L01_001EAA20[0];
    } else {
        *(vu0_q *)pos = D_L01_001EAA30[0];
        func_0038CF68(&transform.vector.turn, &normal, state->probeOffset);
        vec_add_ab(pos, pos, &transform.vector.turn);
    }

    func_0038CF68(&slide, D_L01_001EAA40, 1.0f);
    if (func_0038CE68(&slide, &normal) <= -0.707f) {
        f32 dot = func_0038CE68(velocity, &slide);
        if (dot < 0.0f) {
            if (D_L01_001EAA18[0] == 0 || D_L01_001EAA1C[0] > 0) {
                func_0038CF68(&transform.vector.rayStart, moby + 0xE0, 0.2f);
                func_0038CF68(&rayEnd, moby + 0xE0, -2.0f);
                vec_add_ba(&transform.vector.rayStart, &transform.vector.rayStart, pos);
                vec_add_ab(&rayEnd, &rayEnd, pos);
                if (func_003D3CB0(&transform.vector.rayStart, &rayEnd, 2, moby, 0)) state->mode = 2;
            }
            func_0038CF68(&transform.vector.slopeAdjustment, &slide, dot);
            vec_sub_ab(velocity, velocity, &transform.vector.slopeAdjustment);
            if (state->mode == 2) {
                f32 speed = func_0038CEA8(velocity);
                func_003C4138(&speed, 0.0f, state->slopeSpeed);
                func_0038CF68(velocity, velocity, speed);
            }
        }
    } else {
        f32 dot = func_0038CE68(velocity, &slide);
        if (dot < 0.0f) {
            func_0038CF68(&transform.vector.slopeAdjustment, &slide, -(state->slideSpeed + length) * dot);
            vec_add_ab(velocity, velocity, &transform.vector.slopeAdjustment);
        }
    }

finish:
    if (state->mode == 0 && projected < 0.0f) {
        state->mode = 1;
    } else if (state->flags & 2) {
        if ((result & 4) && projected <= 0.0f) result |= 1;
    } else if (moby[0x60] & 2) {
        if (state->flags & 1) result |= 1;
        result |= 2;
    }
    return result;
}
