/* functional: high. Per-frame update of a multiplayer-menu projectile object (states in object[0x20]: 0 flying with collision, 1 landed/setup, 2 settled and growing, 3 and 4 and 5 idle/timeout states that re-arm effects and expire), then the shared draw-scale tail. Written from the PAL disassembly. Retail's state-2 path hands func_L39_00554A70 an uninitialised stack vector (the second argument is never set on that path); the C keeps that, so `prev` is deliberately left unset outside state 0. */
#include "common.h"
#include "vu0.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00552920;
typedef struct { u8 b[0x20]; } __attribute__((aligned(16))) B_00552920;

extern u8 D_1FE020[];
extern vu0_v4 D_L39_0025F760;
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern s32 func_0038CAD0(void *);
extern u8 func_L39_005FF0B8(void *, void *, void *, s32, f32);
extern f32 func_L39_00632678(void *, void *);
extern s32 func_003D3CB0(void *, void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern s32 func_003D4D00(void *, s32, void *, void *, f32);
extern s32 func_L39_005BE900(void *, s32, f32);
extern void func_L01_00404A10(void *, void *);
extern void func_L39_00554888(u8 *);
extern void func_L39_00553148(u8 *);
extern void func_L39_005537B8(u8 *);
extern void func_L39_00553C30(u8 *);
extern void func_L39_00554A70(void *, void *, void *);
extern s32 func_L39_00554DD8(s32);
extern void func_L39_00554D98(void *, s32);
extern s32 func_L39_005F33E0(s32, s32, void *);
extern s32 func_L39_005F2FA0(void *, s32);
extern void func_L01_00424D88(s32);
extern void func_L39_005F3088(s32);
extern void func_L39_00554E18(void *, s32);
extern void func_003C7C38(void *);
extern void func_003C2880(void *);

void func_L39_00552920(u8 *self) {
    u8 *state = *(u8 **)(self + 0x68);
    u8 *owner = *(u8 **)(state + 0x2C);
    V_00552920 prev;
    V_00552920 t10;
    V_00552920 t20;
    V_00552920 t30;
    B_00552920 buf;
    f32 s20;
    s32 hit;
    s32 cnt;
    s32 idx;
    u8 *rec;
    u8 *o2;

    switch (self[0x20]) {
    case 0:
        prev = *(V_00552920 *)(self + 0x10);
        func_0038CF68(&t10, state + 0x60, 0.2f);
        vec_add_ab(&t10, &t10, self + 0x10);
        state[0x70] = func_L39_005FF0B8(state + 0x60, &t10, state, state[0x70], 0.0048f);
        vec_add_ab(self + 0x10, state, self + 0x10);
        if (*(f32 *)(self + 0x10) < 2.0f || *(f32 *)(self + 0x10) > 1021.0f ||
            *(f32 *)(self + 0x14) < 2.0f || *(f32 *)(self + 0x14) > 1021.0f ||
            *(f32 *)(self + 0x18) < 2.0f || *(f32 *)(self + 0x18) > 1021.0f) {
            goto cleanup;
        }
        cnt = *(s32 *)(state + 0x14) + 1;
        *(s32 *)(state + 0x14) = cnt;
        hit = 0;
        if (cnt >= 0x1A) {
            vec_sub_ab(&t20, self + 0x10, owner + 0xA0);
            if (func_L39_00632678(owner, &t20) < 0.5f) {
                func_0038CF68(&t20, owner + 0x40, -3.0f);
                vec_add_ab(&t20, &t20, &prev);
                if (func_003D3CB0(&prev, &t20, 2, 0, 0) == 0) {
                    hit = -1;
                }
            }
        }
        if (hit == 0) {
            *(s32 *)(*(u8 **)(owner + 0x2524) + 0x98) = 0;
            hit = func_003D3CB0(&prev, self + 0x10, 0x10, *(s32 *)(self + 0xB8), 0);
            o2 = *(u8 **)(owner + 0x2524);
            *(s32 *)(o2 + 0x98) = *(s32 *)(*(u8 **)(o2 + 0x24) + 0x10);
            if (hit == 0) {
                goto state0_check;
            }
        }
        if (hit != -1) {
            *(vu0_v4 *)(self + 0x10) = D_L39_0025F760;
            *(vu0_v4 *)(state + 0x50) = D_L39_0025F760;
        } else {
            *(V_00552920 *)(self + 0x10) = prev;
            *(V_00552920 *)(state + 0x50) = prev;
        }
        func_0038CF68(&t20, state + 0x60, 0.1f);
        vec_add_ab(self + 0x10, self + 0x10, &t20);
        *(s32 *)(state + 0x14) = 0;
        func_L01_004450F0(self, 1, -1);
        func_0038CF68(self + 0xE0, state + 0x60, 1.0f);
        *(V_00552920 *)(self + 0xC0) = *(V_00552920 *)(*(u8 **)(owner + 0x2524) + 0xC0);
        func_0038CE90(self + 0xD0, self + 0xC0, self + 0xE0);
        func_0038CE90(self + 0xC0, self + 0xD0, self + 0xE0);
        func_0038CF68(self + 0xD0, self + 0xD0, *(f32 *)(state + 0x18));
        func_0038CF68(self + 0xE0, self + 0xE0, *(f32 *)(state + 0x1C));
        t30 = *(V_00552920 *)state;
        func_0038CE20(&t30, &t30, 3.0f);
        t30.w = 5627.925f;
        func_L01_00446760(&buf, self, 0x10000, &t30, 5.0f);
        buf.b[0x19] = 1;
        *(u16 *)(buf.b + 0x1A) = *(u16 *)(self + 0xAA);
        buf.b[0x18] = 0;
        func_003D4D00(self + 0x10, 0, self, &buf, 1.0f);
    state0_check:
        t20 = *(V_00552920 *)(self + 0x10);
        t20.w = 2.0f;
        if (func_L39_005BE900(&t20, 0, 96.0f) < 0) {
            goto draw;
        }
        func_L01_00404A10(func_L39_00554888, self);
    trail:
        t30 = *(V_00552920 *)(self + 0x10);
        func_L39_00554A70(self, &t30, &prev);
        goto draw;
    case 1:
        if (func_L39_00554DD8(*(s32 *)(owner + 0x2544)) == 0) {
            func_L39_00554D98(self, *(s32 *)(owner + 0x2544));
        }
        *(s32 *)(state + 0x44) = 0;
        *(s32 *)(state + 0x48) = 0;
        *(s32 *)(state + 0x4C) = 0;
        *(s32 *)(state + 0x34) = 0;
        *(s32 *)(state + 0x38) = 0;
        *(s32 *)(state + 0x3C) = 0;
        *(s32 *)(state + 0x40) = 0;
        func_L39_005F33E0(1, 0, self);
        func_L01_004450F0(self, 2, -1);
        goto draw;
    case 2:
        if (*(f32 *)(self + 0x10) < 2.0f || *(f32 *)(self + 0x10) > 1021.0f ||
            *(f32 *)(self + 0x14) < 2.0f || *(f32 *)(self + 0x14) > 1021.0f ||
            *(f32 *)(self + 0x18) < 2.0f || *(f32 *)(self + 0x18) > 1021.0f) {
            goto cleanup;
        }
        if (*(f32 *)(state + 0x18) < 2.2f) {
            *(f32 *)(state + 0x18) = *(f32 *)(state + 0x18) + 0.02f;
        }
        if (*(f32 *)(state + 0x1C) < 1.2f) {
            *(f32 *)(state + 0x1C) = *(f32 *)(state + 0x1C) + 0.02f;
        }
        if (2.2f <= *(f32 *)(state + 0x18)) {
            if (1.2f <= *(f32 *)(state + 0x1C)) {
                func_L01_004450F0(self, 3, -1);
            }
        }
        func_0038CF68(self + 0xD0, self + 0xD0, *(f32 *)(state + 0x18));
        func_0038CF68(self + 0xE0, self + 0xE0, *(f32 *)(state + 0x1C));
        func_0038CF68(&t10, state + 0x60, 0.01f);
        vec_add_ab(self + 0x10, self + 0x10, &t10);
        t20 = *(V_00552920 *)(self + 0x10);
        t20.w = 2.0f;
        if (func_L39_005BE900(&t20, 0, 96.0f) < 0) {
            goto draw;
        }
        func_L01_00404A10(func_L39_00553148, self);
        goto trail;
    case 3:
        cnt = *(s32 *)(state + 0x14) + 1;
        *(s32 *)(state + 0x14) = cnt;
        if (cnt >= 0x5DD) {
            *(s32 *)(state + 0x14) = 0;
            func_L01_004450F0(self, 5, -1);
        }
        if (func_L39_005F2FA0(self, *(s32 *)(state + 0x20)) == 0) {
            *(s32 *)(state + 0x20) = func_L39_005F33E0(0, 4, self);
        }
        t10 = *(V_00552920 *)(self + 0x10);
        t10.w = 2.0f;
        if (func_L39_005BE900(&t10, 0, 96.0f) < 0) {
            goto draw;
        }
        func_L01_00404A10(func_L39_00553148, self);
        goto draw;
    case 4:
        cnt = *(s32 *)(state + 0x14) + 1;
        *(s32 *)(state + 0x14) = cnt;
        if (cnt >= 0x342) {
            *(s32 *)(state + 0x14) = 0;
            func_L01_004450F0(self, 5, -1);
        }
        if (func_0038CAD0(state + 0x30) != 0) {
            func_L01_004450F0(self, 2, -1);
            *(s32 *)(state + 0x40) = 0;
            *(s32 *)(state + 0x30) = 0x19;
        }
        t10 = *(V_00552920 *)(self + 0x10);
        t10.w = 2.0f;
        if (func_L39_005BE900(&t10, 0, 96.0f) < 0) {
            goto draw;
        }
        func_L01_00404A10(func_L39_005537B8, self);
        goto draw;
    case 5:
        cnt = *(s32 *)(state + 0x14) + 1;
        *(s32 *)(state + 0x14) = cnt;
        if (cnt >= 0x12) {
            goto cleanup;
        }
        func_L01_00404A10(func_L39_00553C30, self);
        goto draw;
    default:
        goto draw;
    }
cleanup:
    idx = *(s32 *)(state + 0x24);
    if (idx != -1) {
        func_L01_00424D88(idx);
    }
    *(s32 *)(state + 0x24) = -1;
    idx = *(s32 *)(state + 0x20);
    if (idx != -1) {
        rec = D_1FE020 + (idx << 7);
        if (*(u8 **)(rec + 0xDC) == self && rec[0xD0] != 0) {
            func_L39_005F3088(idx);
        }
    }
    *(s32 *)(state + 0x20) = -1;
    func_L39_00554E18(self, *(s32 *)(owner + 0x2544));
    func_003C2880(self);
    return;
draw:
    self[0xA8] = 0xFF;
    s20 = *(f32 *)(self + 0x2C);
    *(f32 *)(self + 0x2C) = *(f32 *)(state + 0x18) * s20;
    *(s32 *)(self + 0x98) = *(s32 *)(*(u8 **)(self + 0x24) + 0x10);
    func_003C7C38(self);
    *(f32 *)(self + 0x2C) = s20;
    *(s32 *)(self + 0x98) = 0;
}
