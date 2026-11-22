/* PAL near miss (sol-round3-b): 819 words differ with the file flags; 751 with diagnostic 2 2 2 division padding. The 0x140 frame, register allocation and collision branch layout still differ from retail. */
#include "common.h"
#include "vu0.h"

typedef struct {
    u8 pad0[0x11];
    u8 startAnimation;
    u8 pad12[2];
    u8 idleTicks;
    u8 endAnimation;
    u8 pad16[4];
    u8 mode;
    u8 contactAge;
    u8 pad1C[0x10];
    f32 damping;
    f32 probeRange;
    f32 probeOffset;
    u16 flags;
    u8 pad3A[2];
    f32 repel;
    f32 minimumHeight;
    u8 pad44[8];
    f32 acceleration;
    f32 fallAcceleration;
    f32 stopFrame;
    u8 pad58[8];
    f32 endFrame;
    f32 turnTarget;
    f32 turnRate;
    u8 pad6C[0xF];
    u8 finishFrame;
    s32 collisionId;
    vu0_v4 velocity;
    vu0_v4 rotation;
    u8 padA0[0x10];
    f32 groundSnap;
} MoveState_00454728;

typedef struct {
    u8 pad0[0x18];
    s32 obstacle;
    s32 kind;
    vu0_v4 hit;
    vu0_v4 corrected;
    vu0_v4 normal;
} Contact_00454728;

extern f32 func_0038CED8(void *);
extern f32 func_003C4138(f32 *, f32, f32);
extern void func_0038CFB8(void *, void *, f32);
extern void func_0038D000(void *, void *, void *);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern s32 func_003D5630(void);
extern void func_L01_003016B0(void *, s32, f32, f32);
extern f32 func_003824E0(f32, f32);
extern void func_L01_0046A938(void *, void *, s32, f32, f32);
extern f32 func_00382538(void);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern void func_L01_00468A68(void *, void *, s32, s32);
extern f32 func_L01_004463D0(void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_L01_004395E0(void *);
extern void func_003C3A10(void *, s32, s32, s32);
extern s32 func_L01_004461B8(f32, f32, f32, f32 *, f32 *);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern f32 func_L01_00448890(void *, void *, s32, f32, f32, f32, f32);
extern f32 func_0038D160(f32, f32);
extern void func_L01_00446780(void *, void *, s32, s32, s32, s32, f32, f32, f32);
extern f32 func_0038CEA8(void *);
extern s32 func_L01_003FB640(void *, s32, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern s32 func_L01_00476F10(s32, f32, void *, void *);
extern void func_0038D308(void *, void *);
extern void func_0038D5F0(void *, void *, void *);
extern void func_L01_0044C1B8(void *, void *);
extern s32 func_L01_0044E1B8(void *, f32);

extern Contact_00454728 D_L01_001EAA00;

s32 func_L01_00454728(u8 *moby, MoveState_00454728 *state) {
    vu0_v4 rayEnd, end, offset, origin, candidate;
    union {
        vu0_v4 rotated[3];
        struct { vu0_v4 direction, adjustment, rayStart; } physics;
    } movement;
    f32 speed, floor, root0, root1, finalSpeed;
    f32 distance;
    vu0_v4 *position = (vu0_v4 *)(moby + 0x10);
    vu0_v4 *velocity = &state->velocity;
    void *matrix = moby + 0xC0;
    f32 *yaw = (f32 *)(moby + 0xF8);
    f32 *turnRate = &state->turnRate;
    s32 result = 0;
    s32 contact = 0;
    s32 snapped = 0;
    s32 useHit = 0;

    state->velocity.z -= state->mode == 0 ? state->acceleration : state->fallAcceleration;
    speed = func_0038CED8(velocity);
    {
        f32 target = 0.0200000014f;
        if (state->mode >= 2) target = 0.0f;
        func_003C4138(&speed, target, state->damping);
    }
    func_0038CFB8(velocity, velocity, speed);

    qzero(&offset);
    offset.z = state->probeOffset;
    func_0038D000(&offset, &offset, matrix);
    vec_add_ba(&origin, position, &offset);
    floor = func_003C3D30(&origin, 0, 0, 0.5f);
    if (!func_003D5630()) {
        contact = 1;
        if (state->contactAge == 0 && floor <= origin.z && origin.z + velocity->z < floor) {
            state->contactAge = 1;
            if (*(s16 *)(moby + 0xAA) == 0x16AD || *(s16 *)(moby + 0xAA) == 0x160E) {
                s32 i;
                *(vu0_q *)&end = *(vu0_q *)position;
                end.z = floor;
                func_L01_003016B0(&end, 3, 3.25f, 1.025f);
                for (i = 0; i < 3; i++) {
                    movement.physics.direction.x = position->x + func_003824E0(-0.3f, 0.3f);
                    movement.physics.direction.y = position->y + func_003824E0(-0.3f, 0.3f);
                    movement.physics.direction.z = floor;
                    func_L01_0046A938(&movement.physics.direction, &floor, -1, func_003824E0(0.5f, 0.75f), 5250.0f);
                }
                for (i = 0; i < 16; i++) {
                    f32 angle = func_00382538();
                    f32 scale = func_003824E0(0.0f, 0.0600000024f);
                    s32 type, life;
                    movement.physics.direction.x = func_0038D098(angle) * scale;
                    movement.physics.direction.y = func_0038D0B0(angle) * scale;
                    movement.physics.direction.z = func_003824E0(0.0600000024f, 0.1600000113f);
                    movement.physics.adjustment.x = position->x + movement.physics.direction.x * 8.0f;
                    movement.physics.adjustment.y = position->y + movement.physics.direction.x * 8.0f;
                    movement.physics.adjustment.z = floor - func_003824E0(0.0f, 0.2f);
                    type = func_00382468(2);
                    life = func_00382498(90, 120);
                    func_L01_00468A68(&movement.physics.adjustment, &movement.physics.direction, type, life);
                }
            }
        }
        floor = func_L01_004463D0(position);
    }

    if (state->contactAge != 0) {
        if (state->contactAge < 4) func_0038CE20(velocity, velocity, 0.9f);
        if (state->contactAge < 7) {
            state->contactAge++;
            state->fallAcceleration *= 0.95f;
        }
    }

    if (position->x < 2.0f || position->x > 1021.0f || position->y < 2.0f ||
        position->y > 1021.0f || position->z < 2.0f || position->z > 1021.0f) {
        result = 1;
    }
    if (state->mode != 0 && position->z < state->minimumHeight) {
        result |= 1;
    } else if (moby[0x43] != state->endAnimation && state->endFrame > 0.0f && state->stopFrame > 0.0f) {
        switch (state->mode) {
        case 0:
            distance = fabs_asm(velocity->z / state->acceleration);
            if (distance > 2.0f) {
                f32 rate = 2.0f * (state->stopFrame - func_L01_004395E0(moby)) / distance;
                if (rate > 0.0f) func_003C4138((f32 *)(moby + 0x48), rate, 0.4200000167f);
            }
            break;
        case 1:
            if (state->endFrame <= func_L01_004395E0(moby)) {
                *(f32 *)(moby + 0x48) = 0.0f;
            } else if (state->endAnimation != 255 && (floor == 0.0f ||
                       floor < state->minimumHeight || position->z - floor > 10.0f)) {
                if (moby[0x43] != state->endAnimation) {
                    func_003C3A10(moby, state->endAnimation, 0, 4);
                }
                if (state->fallAcceleration > 0.006f) state->fallAcceleration = 0.006f;
            } else {
                f32 acceleration = state->fallAcceleration * -0.5f;
                f32 time = 60.0f;
                f32 rate;
                if (func_L01_004461B8(acceleration, velocity->z - acceleration, position->z - floor,
                                       &root0, &root1) > 0 && root0 > 0.0f && root0 < time) {
                    time = root0;
                }
                if (time < 0.0001f) time = 0.0001f;
                rate = 2.0f * (state->endFrame - func_L01_004395E0(moby)) / time;
                if (rate > 2.0f) rate = 2.0f;
                else if (rate < 0.0f) rate = 0.0f;
                func_003C4138((f32 *)(moby + 0x48), rate, 0.4200000167f);
            }
            break;
        case 2:
            *(vu0_q *)&end = *(vu0_q *)position;
            *(vu0_q *)&movement.physics.direction = *(vu0_q *)position;
            *(f32 *)(moby + 0x48) = 1.0f;
            movement.physics.direction.z -= 1.0f;
            end.z += 0.2f;
            if (!func_003D3CB0(&end, &movement.physics.direction, 2, moby, 0)) state->mode = 1;
            break;
        }
    }
    func_L01_00448890(yaw, turnRate, 0, state->turnTarget, 0.02010619454f, 0.005026548635f, 3.14f);
    vec_add_ba(position, position, velocity);
    vec_add_ab(&candidate, &origin, velocity);
    {
        f32 ground = func_003C3D30(position, 0, 0, 0.5f);
        if (!(state->flags & 3)) {
            if (ground > 0.0f && (*(u16 *)(moby + 0x34) & 0x20)) {
                u8 *data = *(u8 **)(*(u8 **)(moby + 0x68) + 0x1C);
                if (data != 0 && *(f32 *)(data + 0x10) <
                    func_0038D160(D_L01_001EAA00.normal.z, func_0038CED8(&D_L01_001EAA00.normal))) {
                    position->x = origin.x;
                    position->y = origin.y;
                    if (position->z < floor) position->z = floor;
                    *(vu0_q *)&candidate = *(vu0_q *)position;
                    velocity->y = 0.0f;
                    velocity->x = 0.0f;
                    snapped = 1;
                }
            }
            if (state->groundSnap > 0.0f && !contact && !snapped && state->groundSnap < floor - ground) {
                position->x = origin.x;
                position->y = origin.y;
                if (position->z < floor) position->z = floor;
                *(vu0_q *)&candidate = *(vu0_q *)position;
                velocity->y = 0.0f;
                velocity->x = 0.0f;
            }
        }
    }
    func_0038CE20(&end, velocity, 3.0f);
    vec_add_ab(&end, &end, &candidate);
    func_L01_00446780(moby, &end, 0x8000000, 0, 1, 0, state->probeRange, 1.0f, 1.0f);
    if (state->probeRange < func_0038CEA8(velocity) && func_003D3CB0(&origin, &candidate, 0x24, moby, 0)) {
        *(vu0_q *)&candidate = *(vu0_q *)&D_L01_001EAA00.hit;
    }
    if (!func_L01_003FB640(&candidate, 0x24, moby, state->probeRange)) {
        useHit = 1;
        if (!func_003D3CB0(&candidate, position, 0x24, moby, 0)) goto afterCollision;
    }
    if (useHit) {
        result |= 4;
        *(vu0_q *)position = *(vu0_q *)&D_L01_001EAA00.hit;
    } else {
        result |= 4;
        vec_sub_ba(position, &D_L01_001EAA00.corrected, &offset);
    }

    func_0038CF68(&movement.physics.direction, &D_L01_001EAA00.normal, 1.0f);
    if (movement.physics.direction.z >= 0.707f) {
        f32 dot = func_0038CE68(velocity, &movement.physics.direction);
        if (dot < 0.0f) {
            if (D_L01_001EAA00.obstacle == 0 || D_L01_001EAA00.kind > 0) {
                *(vu0_q *)&movement.physics.rayStart = *(vu0_q *)position;
                *(vu0_q *)&rayEnd = *(vu0_q *)position;
                movement.physics.rayStart.z += 0.2f;
                rayEnd.z -= 2.0f;
                if (func_003D3CB0(&movement.physics.rayStart, &rayEnd, 2, moby, 0)) state->mode = 2;
            }
            func_0038CF68(&movement.physics.adjustment, &movement.physics.direction, dot);
            vec_sub_ab(velocity, velocity, &movement.physics.adjustment);
            if (state->mode == 2) {
                if (D_L01_001EAA00.obstacle != 0 && D_L01_001EAA00.kind < 0) result |= state->flags & 1;
                finalSpeed = func_0038CEA8(velocity);
                func_003C4138(&finalSpeed, 0.0f, state->fallAcceleration);
                func_0038CF68(velocity, velocity, finalSpeed);
            }
        }
    } else {
        f32 dot = func_0038CE68(velocity, &movement.physics.direction);
        if (dot < 0.0f) {
            func_0038CF68(&movement.physics.adjustment, &movement.physics.direction, -(state->repel + 1.0f) * dot);
            vec_add_ab(velocity, velocity, &movement.physics.adjustment);
        }
    }

afterCollision:
    if (state->collisionId != -1) {
        func_L01_00476F10(state->collisionId, state->probeRange, position, position);
    }
    if (state->mode == 0 && velocity->z < 0.0f) {
        state->mode = 1;
    } else if (state->flags & 2) {
        if ((result & 4) && velocity->z <= 0.0f) result |= 1;
        if (*(u16 *)(moby + 0x34) & 0x100) {
            func_0038D308(movement.rotated, &state->rotation);
            func_0038D5F0(matrix, matrix, movement.rotated);
        } else {
            func_L01_0044C1B8(moby + 0xF0, &state->rotation);
            func_0038D308(matrix, moby + 0xF0);
        }
        qzero(&movement.physics.direction);
        movement.physics.direction.z = state->probeOffset;
        func_0038D000(&movement.physics.direction, &movement.physics.direction, matrix);
        vec_sub_ba(&movement.physics.adjustment, &offset, &movement.physics.direction);
        vec_add_ba(position, position, &movement.physics.adjustment);
    } else if ((!contact && state->finishFrame != 255 && moby[0x43] == state->startAnimation &&
                func_L01_0044E1B8(moby, (f32)state->finishFrame)) ||
               ((moby[0x60] & 2) && moby[0x43] != state->endAnimation) ||
               (state->mode == 2 && moby[0x43] == state->endAnimation)) {
        result |= (state->flags & 1) ? 3 : 2;
    }
    if (speed >= 0.02200000174f && state->stopFrame != -1.0f) {
        if (++state->idleTicks >= 50) {
            state->idleTicks = 50;
            result |= (state->flags & 1) ? 3 : 2;
        }
    } else {
        state->idleTicks = 0;
    }
    return result;
}
