#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;
typedef int s128 __attribute__((mode(TI)));

/* localdecomp:start func_L01_002FEA20 */
typedef union {
    vu0_q q;
    f32 f[4];
} Vector_2FEA20;

typedef struct {
    u8 pad0[0x14];
    u8 *proxy;
    f32 phase;
    f32 blend;
    f32 speed;
    s32 flags;
} State_2FEA20;

typedef struct {
    u8 pad0[0x150];
    Vector_2FEA20 velocity;
    u8 pad160[0x58];
    s32 timer;
    u8 pad1BC[0x180];
    f32 speed;
    u8 pad340[0x20];
    s32 powerAttack;
    u8 pad364[0x280];
    f32 verticalSpeed;
    u8 pad5E8[0x3C];
    s32 hasTarget;
    u8 pad628[0x3FC];
    u8 *focus;
    s32 focusActive;
    u8 padA2C[0xC];
    s32 alternateMode;
    u8 padA3C[0xC];
    s32 interrupted;
    u8 padA4C[4];
    u8 *alternate;
    u8 *facingTarget;
    u8 padA58[4];
    s16 release;
    u8 padA5E[0x32];
    u8 *secondTarget;
    u8 padA94[8];
    s32 secondRelease;
    u8 padAA0[0x20];
    u8 *marker;
    u8 padAC4[8];
    s32 markerPending;
    u8 *lastMarker;
    u8 padAD4[0x12C];
    f32 restoreBlend;
    u8 padC04[0x60C];
    u32 inputMask;
    u8 pad1214[0xC];
    s32 handTicks;
    u8 pad1224[0x13A0];
    s32 state;
    u8 pad25C8[4];
    s32 stateType;
    u8 pad25D0[4];
    s32 movementMode;
    u8 pad25D8[0x15];
    u8 markersDisabled;
} Hero_2FEA20;

extern Hero_2FEA20 D_001A4BE0_002FEA20;
extern Vector_2FEA20 D_001A4C60_002FEA20;
extern Vector_2FEA20 D_L01_001E16B0_002FEA20;
extern vu0_q D_L01_001E16B0_002FEA20_q;
extern Vector_2FEA20 D_L01_001E16C0_002FEA20;
extern u8 D_L01_001E16B0_u[8];
extern u8 D_L01_001E16C0_u[8];
extern f32 D_L01_001E16C8_002FEA20;
__asm__(".extern D_L01_001E16C8_002FEA20, 16");
extern Vector_2FEA20 D_L01_001E29C0_002FEA20;
extern s32 D_L01_001DC430_002FEA20;
extern u8 *D_001D52FC_002FEA20;
__asm__(".extern D_001D52FC_002FEA20, 4");
__asm__(".extern D_L01_001DC430_002FEA20, 4");

extern s32 func_L01_005003D0(s32, s32);
extern u8 *func_L01_002FFBC8(u8 *, f32);
extern void func_L01_003F6F20(s32, s32, u32, vu0_q *, f32, s32, f32, s32, f32, s32, f32, f32, f32, f32);
extern void func_003C2F58(u8 *, s32, u8 *);
extern f32 func_0038CF00(void *, void *);
extern f32 func_0038CEA8(void *);
extern void func_0038CFB8(void *, void *, f32);
extern void func_L01_00446978(void *, void *);
extern void func_L01_002FD288(s32, u8 *, s32);
extern u8 D_001425C0[];
extern struct { u8 pad[0x6C]; f32 damage; u8 rest[0x80]; } D_L01_002C5600_002FEA20[];
extern Vector_2FEA20 D_001A4D30_002FEA20;
extern void func_0038CF68(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_00404808(s32, s32);
extern void func_L01_00404A10_002FEA20(void (*)(u8 *), s32);
extern void func_L01_002FD0C8(u8 *);
extern void func_L01_002FD530(s32);
extern void func_L01_002FE280(u8 *);
extern s32 func_0038CAD0(s32 *);
extern s32 func_L01_004DFDB0(s32);
extern void func_L01_0050FB40(s32, s32, f32);

void func_L01_002FEA20(u8 *moby) {
    struct {
        Vector_2FEA20 delta, origin, work, probe;
        struct {
            Vector_2FEA20 impulse;
            u8 *source;
            s32 flags;
            u8 type, mode;
            u16 classId;
            f32 damage;
            s32 active;
        } hit;
    } frame;
    State_2FEA20 *state;
    f32 *proxyVars;
    u8 *target;

    if (D_001A4BE0_002FEA20.state == 1)
        func_L01_005003D0(0x1D, 1);
    state = *(State_2FEA20 **)(moby + 0x68);
    if (!state)
        return;
    frame.delta.q = 0;
    proxyVars = 0;
    if (!state->proxy)
        state->proxy = func_L01_002FFBC8(moby, 0.960000038f);
    if (state->proxy)
        proxyVars = *(f32 **)(state->proxy + 0x68);

    if ((D_001A4BE0_002FEA20.state == 1 || D_001A4BE0_002FEA20.state == 0x1D) && D_001A4BE0_002FEA20.timer >= 2) {
        const f32 half = 0.5f;
        const f32 dimension = 40.0f;
        const f32 angle = 0.0f;
        const f32 step = 90.0f;
        func_L01_003F6F20(0, (s32)moby, 0xFF00FF00, 0, 1.0f, 0x24, angle, -1, step, 4, half, half, dimension, dimension);
        if (D_001A4BE0_002FEA20.focusActive && D_001A4BE0_002FEA20.focus) {
            target = D_001A4BE0_002FEA20.focus;
            func_L01_003F6F20(0, (s32)moby, 0xFF0000FF, (vu0_q *)(target + 0x10), 1.4f, 0x24, angle, -1, step, 4, half, half, dimension, dimension);
        } else if (D_001A4BE0_002FEA20.alternate) {
            target = D_001A4BE0_002FEA20.alternate;
            func_L01_003F6F20(0, (s32)moby, 0xFF0000FF, (vu0_q *)(target + 0x10), 1.4f, 0x24, 0.0f, -1, 90.0f, 4, 0.5f, 0.5f, 40.0f, 40.0f);
        }
    }

    func_003C2F58(moby, 0, D_L01_001E16B0_u);
    func_003C2F58(moby, 1, D_L01_001E16C0_u);
    frame.origin.q = *(vu0_q *)D_L01_001E16B0_u;
    D_L01_001E16C8_002FEA20 -= 0.02f;

    if ((u32)(moby[0x20] - 2) >= 0x13 && state->proxy) {
        u8 *proxy;
        func_003C2F58(moby, 0, state->proxy + 0x10);
        proxy = state->proxy;
        *(vu0_q *)(proxy + 0xC0) = *(vu0_q *)(moby + 0xC0);
        *(vu0_q *)(proxy + 0xD0) = *(vu0_q *)(moby + 0xD0);
        *(vu0_q *)(proxy + 0xE0) = *(vu0_q *)(moby + 0xE0);
    }

    switch (moby[0x20]) {
    case 0:
    case 1:
        if (moby[0x60] & 2)
            moby[0x20] = 1;
        if (D_001A4BE0_002FEA20.state == 0x23 || (D_001A4BE0_002FEA20.stateType == 0xF && D_001A4BE0_002FEA20.hasTarget)) {
            if (proxyVars) {
                state->speed = 0.28f;
                state->blend = 1.0f;
                state->flags = 0;
                state->phase = 0;
                proxyVars[1] = 0.960000038f;
                func_003A52A0(0, 0, moby);
                moby[0x20] = 2;
            }
        } else if (D_001A4BE0_002FEA20.state == 0x8F) {
            if (proxyVars) {
                state->speed = 0.28f;
                state->blend = 1.0f;
                state->phase = 0;
                proxyVars[1] = 0.960000038f;
                func_003A52A0(0, 0, moby);
                moby[0x20] = 15;
            }
        } else if (D_001A4BE0_002FEA20.state == 0x2B && proxyVars) {
            s32 ticks;
            f32 d = func_0038CF00(D_001A4BE0_002FEA20.facingTarget + 0x10, state->proxy + 0x10);
            if (D_001A4BE0_002FEA20.handTicks <= 24)
                ticks = 4;
            else
                ticks = 6;
            proxyVars[1] = d / (f32)ticks;
            state->speed = 0.28f;
            state->blend = 1.0f;
            state->phase = 0;
            func_003A52A0(0, 0, moby);
            moby[0x20] = 9;
        }
        if (!D_001A4BE0_002FEA20.markersDisabled) {
            if (D_001A4BE0_002FEA20.marker) {
                f32 scale = fabs_asm(0.9f - func_0038CF00(&D_L01_001E29C0_002FEA20,
                                    D_001A4BE0_002FEA20.marker + 0x10) / 50.0f * 0.65f);
                frame.work.q = *(vu0_q *)(D_001A4BE0_002FEA20.marker + 0x10);
                func_L01_003F6F20(0, (s32)moby, 0xFF0FFF0F, &frame.work.q, scale, 0x26, 0.0f, -1, 90.0f, 4, 0.5f, 0.5f, 40.0f, 40.0f);
                vec_sub_ba(&frame.delta, D_001A4BE0_002FEA20.marker + 0x10, &frame.origin);
            }
            if (D_001A4BE0_002FEA20.markerPending && D_001A4BE0_002FEA20.marker) {
                D_001A4BE0_002FEA20.markerPending = 0;
                if (D_001A4BE0_002FEA20.powerAttack)
                    D_L01_001DC430_002FEA20 = 3;
                else
                    D_L01_001DC430_002FEA20 = 3;
                D_001A4BE0_002FEA20.lastMarker = D_001A4BE0_002FEA20.marker;
                moby[0x20] = 21;
            }
        }
        break;
    case 2: {
        f32 distance;
        u8 *pp;
        Hero_2FEA20 *hero;
        func_L01_00404808((s32)func_L01_002FE280, (s32)moby);
        vec_sub_ba(&frame.work, D_001A4BE0_002FEA20.focus + 0x10, state->proxy + 0x10);
        distance = proxyVars[1];
        distance += func_0038CEA8(&D_001A4BE0_002FEA20.velocity);
        if (D_001A4BE0_002FEA20.stateType == 0xF)
            distance += D_001A4BE0_002FEA20.verticalSpeed;
        else if ((D_001A4BE0_002FEA20.movementMode == 4 || D_001A4BE0_002FEA20.movementMode == 2) && D_001A4BE0_002FEA20.speed > 2.0f)
            distance = 0.960000038f;
        pp = (u8 *)&D_001A4C60_002FEA20;
        frame.probe = *(Vector_2FEA20 *)pp;
        hero = (Hero_2FEA20 *)(pp - 0x80);
        frame.probe.f[2] += 0.5f;
        if (func_003D3CB0(&frame.probe, hero->focus + 0x10, 2, 0, 0)) {
            if (hero->speed > 0.5f)
                func_L01_005003D0(6, 1);
            else {
                func_L01_005003D0(0, 0);
                func_L01_0050FB40(func_L01_004DFDB0(0), 0, 12.0f);
            }
            moby[0x20] = 6;
        } else if (distance < func_0038CF00(state->proxy + 0x10, hero->focus + 0x10)) {
            func_0038CF68(&frame.work, &frame.work, distance);
            vec_add_ba(state->proxy + 0x10, state->proxy + 0x10, &frame.work);
        } else {
            *(vu0_q *)(state->proxy + 0x10) = *(vu0_q *)(hero->focus + 0x10);
            moby[0x20] = 3;
        }
        break;
    }
    case 3:
        func_003A52A0(1, 0, moby);
        func_L01_00404808((s32)func_L01_002FE280, (s32)moby);
        *(vu0_q *)(state->proxy + 0x10) = *(vu0_q *)(D_001A4BE0_002FEA20.focus + 0x10);
        moby[0x20] = 4;
        break;
    case 4: {
        u8 *pp;
        Hero_2FEA20 *hero;
        func_003C2F58(moby, 0, (u8 *)&frame.work);
        pp = (u8 *)&D_001A4C60_002FEA20;
        frame.work = *(Vector_2FEA20 *)pp;
        hero = (Hero_2FEA20 *)(pp - 0x80);
        frame.work.f[2] += 0.5f;
        if (func_003D3CB0(&frame.work, hero->focus + 0x10, 2, 0, 0)) {
            if (*(s16 *)((u8 *)hero + 0x36E))
                func_L01_005003D0(6, 1);
            else
                func_L01_005003D0(0, 1);
            moby[0x20] = 6;
            break;
        }
        func_L01_00404808((s32)func_L01_002FE280, (s32)moby);
        state->speed *= 0.88f;
        state->phase += 0.69813168f;
        if (state->speed < 0.1680000126f) {
            hero->hasTarget = 0;
            if (state->proxy && func_0038CF00(state->proxy + 0x10, &D_001A4C60_002FEA20) > 3.5f) {
                if (!(*(u32 *)(D_001D52FC_002FEA20 + 0x1A0) & hero->inputMask)) {
                    hero->interrupted = 1;
                    func_L01_005003D0(0, 0);
                    func_L01_0050FB40(func_L01_004DFDB0(0), 0, 12.0f);
                    moby[0x20] = 6;
                } else {
                    func_003A52A0(2, 0, moby);
                    if (hero->alternateMode)
                        func_L01_005003D0(0x25, 1);
                    else
                        func_L01_005003D0(0x24, 1);
                    moby[0x20] = 5;
                }
            } else {
                func_L01_005003D0(0, 1);
                moby[0x20] = 6;
            }
        }
        break;
    }
    case 5:
        *(vu0_q *)(state->proxy + 0x10) = *(vu0_q *)(D_001A4BE0_002FEA20.focus + 0x10);
        state->speed *= 0.88f;
        state->phase += 0.69813168f;
        func_L01_00404808((s32)func_L01_002FE280, (s32)moby);
        if ((u32)(D_001A4BE0_002FEA20.state - 0x24) >= 2)
            moby[0x20] = 6;
        break;
    case 6:
        func_L01_00404808((s32)func_L01_002FE280, (s32)moby);
        proxyVars[1] = 1.600000143f;
        moby[0x20] = 7;
        break;
    case 7: {
        f32 distance;
        func_003C2F58(moby, 0, (u8 *)&frame.probe);
        vec_sub_ab(&frame.work, &frame.probe, state->proxy + 0x10);
        distance = proxyVars[1];
        distance += func_0038CEA8(&D_001A4D30_002FEA20);
        if (distance < func_0038CF00(state->proxy + 0x10, &frame.probe)) {
            func_0038CF68(&frame.work, &frame.work, distance);
            vec_add_ba(state->proxy + 0x10, state->proxy + 0x10, &frame.work);
            func_L01_00404808((s32)func_L01_002FE280, (s32)moby);
        } else {
            *(vu0_q *)(state->proxy + 0x10) = frame.probe.q;
            moby[0x20] = 1;
        }
        break;
    }
    case 9:
        func_L01_00404808((s32)func_L01_002FE280, (s32)moby);
        vec_sub_ba(&frame.work, D_001A4BE0_002FEA20.facingTarget + 0x10, state->proxy + 0x10);
        if (func_0038CEA8(&frame.work) > proxyVars[1]) {
            func_0038CF68(&frame.work, &frame.work, proxyVars[1]);
            vec_add_ba(state->proxy + 0x10, state->proxy + 0x10, &frame.work);
        } else {
            *(vu0_q *)(state->proxy + 0x10) = *(vu0_q *)(D_001A4BE0_002FEA20.facingTarget + 0x10);
            moby[0x20] = 11;
            func_003A52A0(1, 0, moby);
        }
        break;
    case 10:
        func_L01_00404808((s32)func_L01_002FE280, (s32)moby);
        moby[0x20] = 11;
        break;
    case 11:
        func_L01_00404808((s32)func_L01_002FE280, (s32)moby);
        state->speed *= 0.2799999714f;
        state->phase += 0.69813168f;
        if (state->speed < 0.1680000126f) {
            D_001A4BE0_002FEA20.release = 1;
            moby[0x20] = 12;
        }
        break;
    case 12:
        if (D_001A4BE0_002FEA20.facingTarget)
            *(vu0_q *)(state->proxy + 0x10) = *(vu0_q *)(D_001A4BE0_002FEA20.facingTarget + 0x10);
        state->speed *= 0.2799999714f;
        state->phase += 0.69813168f;
        func_L01_00404808((s32)func_L01_002FE280, (s32)moby);
        if (D_001A4BE0_002FEA20.state != 0x2B)
            moby[0x20] = 13;
        break;
    case 13:
        func_L01_00404808((s32)func_L01_002FE280, (s32)moby);
        proxyVars[1] = 1.600000143f;
        moby[0x20] = 14;
        break;
    case 14:
        func_003C2F58(moby, 0, (u8 *)&frame.probe);
        vec_sub_ab(&frame.work, &frame.probe, state->proxy + 0x10);
        if (func_0038CF00(state->proxy + 0x10, &frame.probe) > proxyVars[1]) {
            func_0038CF68(&frame.work, &frame.work, proxyVars[1]);
            vec_add_ba(state->proxy + 0x10, state->proxy + 0x10, &frame.work);
            func_L01_00404808((s32)func_L01_002FE280, (s32)moby);
        } else {
            *(vu0_q *)(state->proxy + 0x10) = frame.probe.q;
            moby[0x20] = 1;
        }
        if (D_001A4BE0_002FEA20.state == 0x2B && proxyVars) {
            proxyVars[1] = func_0038CF00(D_001A4BE0_002FEA20.facingTarget + 0x10, state->proxy + 0x10) / 10.0f;
            state->blend = 1.0f;
            state->speed = 0;
            state->phase = 0;
            moby[0x20] = 9;
        }
        break;
    case 15: {
        u8 *pp;
        Hero_2FEA20 *hero;
        func_L01_00404808((s32)func_L01_002FE280, (s32)moby);
        pp = (u8 *)&D_001A4C60_002FEA20;
        frame.work = *(Vector_2FEA20 *)pp;
        hero = (Hero_2FEA20 *)(pp - 0x80);
        frame.work.f[2] += 0.5f;
        if (func_003D3CB0(&frame.work, hero->secondTarget + 0x10, 2, 0, 0)) {
            if (hero->speed > 0.5f)
                func_L01_005003D0(6, 1);
            else {
                func_L01_005003D0(0, 0);
                func_L01_0050FB40(func_L01_004DFDB0(0), 0, 12.0f);
            }
            moby[0x20] = 19;
        } else {
            vec_sub_ba(&frame.probe, hero->secondTarget + 0x10, state->proxy + 0x10);
            if (func_0038CEA8(&frame.probe) > proxyVars[1]) {
                func_0038CF68(&frame.probe, &frame.probe, proxyVars[1]);
                vec_add_ba(state->proxy + 0x10, state->proxy + 0x10, &frame.probe);
            } else {
                *(vu0_q *)(state->proxy + 0x10) = *(vu0_q *)(hero->secondTarget + 0x10);
                moby[0x20] = 17;
                func_003A52A0(1, 0, moby);
            }
        }
        break;
    }
    case 16:
        func_L01_00404808((s32)func_L01_002FE280, (s32)moby);
        moby[0x20] = 17;
        break;
    case 17:
        func_L01_00404808((s32)func_L01_002FE280, (s32)moby);
        state->speed *= 0.2799999714f;
        state->phase += 0.69813168f;
        if (state->speed < 0.1680000126f) {
            D_001A4BE0_002FEA20.secondRelease = 1;
            moby[0x20] = 18;
        }
        break;
    case 18:
        if (D_001A4BE0_002FEA20.secondTarget)
            *(vu0_q *)(state->proxy + 0x10) = *(vu0_q *)(D_001A4BE0_002FEA20.secondTarget + 0x10);
        state->speed *= 0.2799999714f;
        state->phase += 0.69813168f;
        func_L01_00404808((s32)func_L01_002FE280, (s32)moby);
        if (D_001A4BE0_002FEA20.stateType != 0x21)
            moby[0x20] = 19;
        break;
    case 19:
        func_L01_00404808((s32)func_L01_002FE280, (s32)moby);
        proxyVars[1] = 1.600000143f;
        moby[0x20] = 20;
        break;
    case 20:
        func_003C2F58(moby, 0, (u8 *)&frame.probe);
        vec_sub_ab(&frame.work, &frame.probe, state->proxy + 0x10);
        if (func_0038CF00(state->proxy + 0x10, &frame.probe) > proxyVars[1]) {
            func_0038CF68(&frame.work, &frame.work, proxyVars[1]);
            vec_add_ba(state->proxy + 0x10, state->proxy + 0x10, &frame.work);
            func_L01_00404808((s32)func_L01_002FE280, (s32)moby);
        } else {
            *(vu0_q *)(state->proxy + 0x10) = frame.probe.q;
            moby[0x20] = 1;
        }
        if (D_001A4BE0_002FEA20.stateType == 0x21 && proxyVars) {
            proxyVars[1] = func_0038CF00(D_001A4BE0_002FEA20.secondTarget + 0x10, state->proxy + 0x10) / 10.0f;
            state->blend = 1.0f;
            state->speed = 0;
            state->phase = 0;
            moby[0x20] = 15;
        }
        break;
    case 21:
        if (func_0038CAD0(&D_L01_001DC430_002FEA20)) {
            f32 damage = (D_L01_002C5600_002FEA20 + D_001425C0[0x12])->damage;
            frame.hit.flags = 0x10000;
            frame.hit.active = 1;
            frame.hit.impulse.q = frame.delta.q;
            frame.hit.damage = damage;
            frame.hit.source = moby;
            D_001A4BE0_002FEA20.restoreBlend = 0;
            func_0038CFB8(&frame.hit, &frame.hit, 1.0f);
            frame.hit.type = 3;
            frame.hit.mode = 2;
            frame.hit.impulse.f[2] = 1.0f;
            frame.hit.impulse.f[3] = 5627.9248046875f;
            frame.hit.classId = *(u16 *)(moby + 0xAA);
            func_L01_00446978(D_001A4BE0_002FEA20.lastMarker, &frame.hit);
            moby[0x20] = 22;
            if (D_001A4BE0_002FEA20.powerAttack) {
                D_L01_001DC430_002FEA20 = 3;
                func_L01_002FD288((s32)moby, D_001A4BE0_002FEA20.lastMarker, 3);
                func_L01_002FD288((s32)moby, D_001A4BE0_002FEA20.lastMarker, 3);
                func_L01_002FD288((s32)moby, D_001A4BE0_002FEA20.lastMarker, 3);
            } else {
                D_L01_001DC430_002FEA20 = 2;
                func_L01_002FD288((s32)moby, D_001A4BE0_002FEA20.lastMarker, 2);
                func_L01_002FD288((s32)moby, D_001A4BE0_002FEA20.lastMarker, 2);
                func_L01_002FD288((s32)moby, D_001A4BE0_002FEA20.lastMarker, 2);
            }
            D_001A4BE0_002FEA20.lastMarker = 0;
        }
        break;
    case 8:
    case 24:
        break;
    case 22:
        if (func_0038CAD0(&D_L01_001DC430_002FEA20)) {
            D_001A4BE0_002FEA20.restoreBlend = 1.0f;
            D_L01_001DC430_002FEA20 = 7;
            moby[0x20] = 23;
        }
        break;
    case 23:
        if (func_0038CAD0(&D_L01_001DC430_002FEA20)) {
            D_001A4BE0_002FEA20.markerPending = 0;
            moby[0x20] = 1;
        }
        break;
    }

    func_L01_002FD530((s32)moby);
    if ((moby[0x34] ^ 1) & 1)
        func_L01_00404A10_002FEA20(func_L01_002FD0C8, (s32)moby);
}
/* localdecomp:end func_L01_002FEA20 */
