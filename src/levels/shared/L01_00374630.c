#include "common.h"
#include "vu0.h"
#include "structs/weapon.h"

/* localdecomp:start func_L01_00374630 */
extern s32 func_0038CAD0(void *);
extern void func_L01_003743C8(void *);
extern f32 func_00382538(void);
extern f32 func_003824E0(f32, f32);
extern void func_003D9508(void *, s32, s32, s32, f32, f32, f32);

void func_L01_00374630(u8 *obj) {
    u8 *v = *(u8 **)(obj + 104);
    u8 *m;

    if (func_0038CAD0(v + 84) != 0) {
        return;
    }
    func_L01_003743C8(obj);
    func_L01_003743C8(obj);
    m = v + 16;
    func_003D9508(m, 49, 0x3F204090, 1, 0.9f, 0.0f, func_00382538());
    func_003D9508(m, 49, 0x3F204090, 1, 0.9f, 0.0f, func_00382538());
    func_003D9508(m, 11, 0x3F204090, 1, 0.9f, 0.08f, 0.0f);
    func_003D9508(m, 65, 0x3F909090, 1, 1.0f, 0.0f, func_003824E0(30.0f, 60.0f) * 0.017453292f);
}
/* localdecomp:end func_L01_00374630 */

LINKER_REMNANT("asm/levels", func_L01_00374770);

/* localdecomp:start func_L01_00374790 */
typedef int u128_374790 __attribute__((mode(TI)));

typedef struct {
    f32 dir_pos[4];   /* 0x00 */
    f32 pad10[4];
    u128_374790 color;     /* 0x20 */
    f32 f30;
    s32 x34;
    void *owner;      /* 0x38 */
    u8 pad3c[0x4C - 0x3C];
    s32 x4c;
    u8 pad50[4];
    s32 x54;
    u8 pad58[4];
    s32 x5c;
    u8 pad60[4];
    s32 x64;
    f32 size;         /* 0x68 */
    s32 x6c;
    f32 x70;
    f32 x74;
    s32 x78;
    s32 x7c;
    s32 x80;
    u8 pad84[8];
    s32 x8c;
    f32 f90;
    s32 x94;
} R_374790;

typedef struct {
    u8 pad0[0x10];
    u128_374790 pos;       /* 0x10 */
    u8 x20;
    u8 pad21[0xF];
    u8 x30;
    u8 pad31;
    s16 x32;
    u16 flags;        /* 0x34 */
    u8 pad36[0x68 - 0x36];
    R_374790 *state;  /* 0x68 */
    u8 pad6c[0x98 - 0x6C];
    s32 x98;
} M_374790;

extern u8 *func_003C24B0(s32, s32);
extern f32 func_00382538(void);
extern void func_L01_004C7D98(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_L01_004C85C8(void *, f32, f32, f32, s32);
extern f32 func_003824E0(f32, f32);
extern void func_L01_004AA7E8(void *, s32);
typedef struct { s32 w[0x2900 / 4]; } Hw_374790;
extern Hw_374790 D_001A4BE0;

/* rift_spawn: spawn the Rift Inducer's rift (class 0x186B) from the gun */
M_374790 *func_L01_00374790(void *owner, u128_374790 *pos, u128_374790 *dir, f32 size) {
    M_374790 *m = (M_374790 *)func_003C24B0(0x186B, 0x700);
    R_374790 *r;
    u128_374790 *mpos;
    u128_374790 col;

    if (m != 0) {
        m->x20 = 0;
        m->x32 = 0xFF;
        m->x30 = 0xFF;
        mpos = &m->pos;
        r = m->state;
        m->pos = *pos;
        *(u128_374790 *)r = *dir;
        r->owner = owner;
        r->f30 = func_00382538();
        r->x34 = 0;
        func_L01_004C7D98(mpos, &r->pad10);
        func_0038CF68(&r->pad10, &r->pad10, 0.1f);
        col = *(u128_374790 *)((u8 *)D_001A4BE0.w[0x25C0 / 4] + 0xD0);
        r->size = size;
        r->x4c = 0;
        r->x54 = 0;
        r->x5c = 0;
        r->x78 = 0;
        r->x7c = 0;
        r->x80 = 0;
        r->x64 = -1;
        r->x70 = 2.25f;
        r->x74 = 2.25f;
        r->x6c = -1;
        r->color = col;
        r->x8c = func_L01_004C85C8(m, 1.0f, 1.0f, 1.0f, 0);
        r->f90 = func_003824E0(7.0f, 23.0f);
        r->x94 = 0;
        m->x98 = 0;
        m->flags = (m->flags | 0x41) & 0xEFFF;
        func_L01_004AA7E8(m, 1);
    }
    return m;
}
/* localdecomp:end func_L01_00374790 */

/* localdecomp:start func_L01_00374908 */
typedef struct S_3738B0 S_3738B0;

typedef struct {
    u8 pad0[0x54];
    S_3738B0 *w54;
} S_3738B0m;

struct S_3738B0 {
    u8 pad0[0x10];
    f32 pos[4];
    u8 pad20[0x68 - 0x20];
    S_3738B0m *p68;
};

/* the six rift slots are reached from the first one: a scalar here, so the compiler leaves its address to the assembler (lui/addiu in one register) */
extern S_3738B0 *D_L01_001E10E0;
extern f32 func_L01_0040E548(f32 *a0, f32 *a1);

void func_L01_00374908(S_3738B0 *a0, S_3738B0 *a1) {
    S_3738B0m *m;
    S_3738B0m *q;
    S_3738B0 **pp;
    f32 d;
    s32 i;

    if (a0 == 0 || a1 == 0) {
        return;
    }
    m = a0->p68;
    for (i = 0; i < 6; i++) {
        pp = &D_L01_001E10E0 + i;
        if (*pp == 0) {
            continue;
        }
        q = (*pp)->p68;
        if (q == 0 || q->w54 != a1) {
            continue;
        }
        if (m == 0) {
            return;
        }
        d = func_L01_0040E548(a0->pos, a1->pos);
        if (d < func_L01_0040E548((*pp)->pos, a1->pos)) {
            m->w54 = a1;
            q->w54 = 0;
        }
        return;
    }
    m->w54 = a1;
}
/* localdecomp:end func_L01_00374908 */

/* localdecomp:start func_L01_003749E8 */
typedef struct {
    vu0_v4 velocity;
    vu0_v4 directionA;
    vu0_v4 directionB;
    u8 pad30[4];
    s32 timer;
    s32 f38;
    u8 pad3C[8];
    f32 crossScale;
    u8 pad48[4];
    f32 rotation;
    u8 pad50[4];
    u8 *target;
    u8 pad58[0xC];
    s32 sound;
    f32 scale;
    s32 entry;
    u8 pad70[0x10];
    f32 intensity;
    u8 pad84[8];
    void *effect;
    f32 f90;
    s32 f94;
    u8 pad98[8];
    vu0_v4 base[24];
    vu0_v4 vectors[24];
    f32 phase[24];
} UpdateState;

typedef struct {
    u8 pad0[0x18];
    u8 f18;
    u8 f19;
    u16 f1A;
} HitInfo;

typedef struct {
    u8 pad0[0x18];
    u8 *f18;
    u8 pad1c[4];
    u8 f20[0x40];
} Hit_EAA00;

typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    s32 fC;
    vu0_v4 f10;
} SoundRow;

extern u8 D_001A30B0[];
extern u8 D_001425C0[];
extern u8 D_00142DE0[];
extern vu0_v4 D_001A4C60[];
extern vu0_v4 D_L01_001E29C0[];
extern vu0_v4 D_L01_001E2A40[];
extern vu0_v4 D_L01_001E2DC0[];
extern Hit_EAA00 D_L01_001EAA00;
extern SoundRow D_L01_001F1B40[];
extern u8 D_L01_001D66B0;
extern u8 *D_L01_00221098[];
extern u8 *D_L01_001EEA80[];
extern struct WeaponRow D_L01_002C5600[];
extern u32 D_L01_001D7BE0;
__asm__(".extern D_L01_001D7BE0, 4");

extern s32 func_L01_004CB2D8(void);
extern void func_L01_004CAB30(void *, void *);
extern f32 func_0038CEA8(void *);
extern void func_L01_004C8688(void *, void *, s32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);
extern void func_L01_00424D88(s32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_L01_00424CB0(void *, f32, f32, f32, f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern s32 func_003D4D00(void *, s32, f32, void *, void *);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_0038DC20(void *, f32);
extern void func_L01_00404A10(void (*)(void *), void *);
extern void func_L01_003770A8(void *);
extern void func_L01_00376490(void *);
extern void func_L01_00376D08(void *);
extern void func_L01_003773C0(void *, void *, void *);
extern f32 func_003824E0(f32, f32);
extern void func_00382580(void *, f32, f32);
extern void func_0038CE90(void *, void *, void *);
extern s32 func_L01_00377908(void);
extern void func_L01_00377940(void);
extern void func_L01_003778D0(void *);
extern s32 func_L01_004AA710(void *, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_003A4F28(s32);
extern f32 func_L01_00443A18(f32, f32);
extern s32 func_00382498(s32, s32);
extern s32 func_00382468(s32);
extern f32 func_00382538(void);
extern void func_0038D890(void *, void *, void *, f32);
extern u8 *func_L01_004713C8(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);
extern void func_L01_004C7D98(void *, void *);
extern u8 *func_00382348(void *);
extern s32 func_003C4B50(void *);
extern void func_L01_0034E558(void *, s32, void *, void *, s32);
extern u8 **func_L01_00448FB8(void *);
extern f32 func_L01_00448340(void *, void *, void *, f32, f32, f32);
extern void func_0038D308(void *, void *);
extern void func_003C7C38(void *);
extern f32 func_0038CF00(void *, void *);
extern s32 func_L01_00444350(void);
extern void func_L01_0033D0E8(void *);
extern void func_L01_003779C8(void *);
extern void func_L01_004C8668(void *);
extern void func_003C2880(void *);

/* A Veldin projectile's update (shared by 34 levels): state 0 flies and collides, 1 sets up the 24
 * vector pairs, 2 spawns particles and hunts a target, 3 and 4 wind down. The particle chains are
 * per-instruction VU0 asm with TImode operands, as in L03_003AF848.c. */
void func_L01_003749E8(u8 *self) {
    UpdateState *state = *(UpdateState **)(self + 0x68);
    u8 *target;
    u8 *entry;
    vu0_v4 f[13];
    f32 scale;
    s32 ia, ib, ic, id2, ie, if_, ig;
    s32 n, k, k1, k2, id, life, rint;
    u8 *p, *m, *q, *cls, *pd;
    f32 zf;

    if (func_L01_004CB2D8()) {
        func_L01_004CAB30((self + 0x10), (self + 0x10));
    }

    switch (self[0x20]) {
    case 0:
        *(vu0_q *)&f[0] = *(vu0_q *)(self + 0x10);
        scale = func_0038CEA8(&state->velocity);
        func_L01_004C8688(state->effect, state, 0);
        vec_add_ba((self + 0x10), &state->velocity, (self + 0x10));
        state->rotation = func_0038DAB8(state->rotation, 0.6981317400932312f);
        func_0038CF68(&state->directionA, &state->directionA,
                      func_0038D0B0(state->rotation) * 0.05f);
        func_0038CF68(&state->directionB, &state->directionB,
                      func_0038D0B0(state->rotation) * 0.05f);
        vec_add_ba(&state->velocity, &state->directionA, &state->velocity);
        vec_add_ba(&state->velocity, &state->directionB, &state->velocity);
        func_0038CF68(&state->velocity, &state->velocity, scale);
        func_0038CF68(&state->velocity, &state->velocity, scale * 0.9040000438690186f);
        if (*(f32 *)(self + 0x10) < 2.0f || 1021.0f < *(f32 *)(self + 0x10) ||
            *(f32 *)(self + 0x14) < 2.0f || 1021.0f < *(f32 *)(self + 0x14) ||
            *(f32 *)(self + 0x18) < 2.0f || 1021.0f < *(f32 *)(self + 0x18)) {
            if (state->sound != -1) {
                func_L01_00424D88(state->sound);
            }
            state->sound = -1;
            func_L01_004C8668(state->effect);
            func_003C2880(self);
            return;
        }
        state->timer++;
        if (func_003D3CB0(&f[0], (self + 0x10), 0, self, 0)) {
            *(vu0_q *)(self + 0x10) = *(vu0_q *)D_L01_001EAA00.f20;
            *(vu0_q *)&f[1] = *(vu0_q *)(D_L01_001EAA00.f20 + 0x20);
            func_0038CF68(&f[1], &f[1], 0.5f);
            vec_add_ba((self + 0x10), (self + 0x10), &f[1]);
            state->timer = 0;
            func_L01_004450F0(self, 1, -1);
            *(vu0_q *)&f[2] = *(vu0_q *)&state->velocity;
            func_0038CE20(&f[2], &f[2], 3.0f);
            f[2].w = 5627.9248046875f;
            zf = 0.0f;
            func_L01_00446760(&f[3], self, 0x10000, &f[2], zf);
            ((HitInfo *)&f[3])->f18 = 0;
            ((HitInfo *)&f[3])->f19 = 1;
            ((HitInfo *)&f[3])->f1A = *(u16 *)(self + 0xAA);
            if (D_L01_001EAA00.f18 != 0) {
                if (D_L01_001EAA00.f18 != (u8 *)state->f38) {
                    func_003D4D00(D_L01_001EAA00.f20, 0, 1.0f, self, &f[3]);
                }
            } else {
                func_003D4D00(D_L01_001EAA00.f20, 0, 1.0f, self, &f[3]);
            }
        }
        if (state->sound == -1) {
            state->sound = func_L01_00424CB0((self + 0x10), 5.0f, 0.0f, 0.45f, 0.2f, 1.0f);
        } else {
            SoundRow *row = &D_L01_001F1B40[state->sound];
            row->f10 = *(vu0_v4 *)(self + 0x10);
            row->f10.w = 5.0f;
            row->f0 = 0.45f;
            row->f4 = 0.2f;
            row->f8 = 1.0f;
            row->fC = 0;
        }
        *(vu0_q *)&f[1] = *(vu0_q *)(self + 0x10);
        f[1].w = 0.5f;
        if (func_0038DC20(&f[1], 96.0f) > 0) {
            func_L01_00404A10(func_L01_003770A8, self);
            *(vu0_q *)&f[2] = *(vu0_q *)(self + 0x10);
            func_L01_003773C0(self, &f[2], &f[0]);
        }
        if (state->timer >= 30) {
            state->timer = 0;
            func_L01_004450F0(self, 1, -1);
        }
        return;
    case 1: {
        for (ia = 0; ia < 24; ia++) {
            state->phase[ia] = func_003824E0(0.01745329424738884f, 0.05235987901687622f);
            state->crossScale = state->scale * 0.1f;
            func_00382580(&state->base[ia], 1.0f, 1.0f);
            vec_sub_ab(&f[1], D_L01_001E29C0, (self + 0x10));
            func_0038CF68(&f[1], &f[1], 1.0f);
            func_0038CE90(&state->vectors[ia], &state->base[ia], &f[1]);
            func_0038CF68(&state->vectors[ia], &state->vectors[ia], state->crossScale);
        }
        if (state->sound != -1) {
            func_L01_00424D88(state->sound);
        }
        state->sound = -1;
        if (func_L01_00377908() && state->target == 0) {
            func_L01_00377940();
        }
        func_L01_003778D0(self);
        func_L01_004450F0(self, 2, -1);
        return;
    }
    case 2:
        state->timer++;
        if ((state->target == 0 && state->timer >= 501) ||
            (state->target != 0 && 2500.0f < func_L01_0040E548((f32 *)(state->target + 0x10), (f32 *)(self + 0x10)))) {
            state->timer = 0;
            func_L01_004450F0(self, 3, -1);
        }
        if ((state->target == 0 && 900.0f < func_L01_0040E548((f32 *)(self + 0x10), (f32 *)(D_001A4C60))) ||
            (state->target != 0 && 2500.0f < func_L01_0040E548((f32 *)(state->target + 0x10), (f32 *)(D_001A4C60)))) {
            state->timer = 0;
            func_L01_004450F0(self, 3, -1);
        }
        state->intensity += 0.005f;
        if (state->intensity > 0.75f) {
            state->intensity = 0.75f;
        }
        if (!func_L01_004AA710(self, state->entry)) {
            state->entry = func_003A52A0(0, 4, self);
        }
        *(vu0_q *)&f[1] = *(vu0_q *)(self + 0x10);
        f[1].w = 0.5f;
        if (func_0038DC20(&f[1], 96.0f) > 0) {
            f32 s20, s23, s22;
            func_L01_00404A10(func_L01_00376490, self);
            for (ib = 0; ib < 4; ib++) {
                s32 rint;
                s32 life;
                u8 *p;
                rint = (s32)func_L01_00443A18(2.0f, 5.0f);
                func_00382580(&f[2], state->scale, state->scale * 2.200000047683716f);
                {
                    vu0_q x, y, c;
                    __asm__("lqc2 %0, %1" : "=j"(c) : "m"(*(vu0_q *)(self + 0x10)));
                    __asm__("sqc2 %1, %0" : "=m"(*(vu0_q *)&f[10]) : "j"(c));
                    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(vu0_q *)&f[2]));
                    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(vu0_q *)(self + 0x10)));
                    __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
                    __asm__("sqc2 %1, %0" : "=m"(*(vu0_q *)&f[2]) : "j"(x));
                    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(vu0_q *)&f[2]));
                    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(vu0_q *)&f[10]));
                    __asm__("vsub.xyz %0, %1, %2" : "=j"(c) : "j"(x), "j"(y));
                    __asm__("sqc2 %1, %0" : "=m"(*(vu0_q *)&f[3]) : "j"(c));
                }
                func_0038CF68(&f[3], &f[3],
                              func_003824E0(state->scale + state->scale, state->scale * 2.700000047683716f) *
                                  0.020000001415610313f);
                life = func_00382498(20, 25) * 5;
                life = life + 2;
                life = life / 6;
                p = func_L01_004713C8(&f[2], &f[3], life, 0x804040, rint, 0, 0x7F,
                                      state->scale * 0.800000011920929f * 210000.0f,
                                      func_003824E0(state->scale * 0.30000001192092896f, state->scale * 0.5f) * 210000.0f,
                                      0.0f, 6);
                if (p != 0) {
                    p[2] = *D_L01_00221098[23];
                }
            }
            s20 = state->scale * 0.800000011920929f;
            s23 = state->scale * 0.4000000059604645f;
            s22 = state->scale * 0.6000000238418579f;
            func_L01_004C7D98((self + 0x10), &f[4]);
            func_0038CF68(&f[4], &f[4], -5.0f);
            vec_add_ab(&f[5], (self + 0x10), &f[4]);
            if (func_003D3CB0((self + 0x10), &f[5], 0, self, 0)) {
                *(vu0_q *)&f[2] = *(vu0_q *)(D_L01_001EAA00.f20 + 0x20);
                *(vu0_q *)&f[3] = *(vu0_q *)D_L01_001EAA00.f20;
                func_0038CF68(&f[2], &f[2], 0.05f);
                vec_add_ba(&f[3], &f[3], &f[2]);
                func_0038CF68(&f[2], &f[2], 1.0f);
                vec_sub_ab(&f[6], D_L01_001E2A40, (self + 0x10));
                func_0038CE90(&f[7], &f[6], &f[2]);
                func_0038CF68(&f[7], &f[7],
                              func_003824E0(state->scale + state->scale, state->scale * 3.0f));
                for (ic = 0; ic < 5; ic++) {
                s32 rint;
                s32 life;
                u8 *p;
                    rint = (s32)func_L01_00443A18(2.0f, 5.0f);
                    func_0038D890(&f[8], &f[7], &f[2], func_00382538());
                    {
                        vu0_q x, y, c;
                        __asm__("lqc2 %0, %1" : "=j"(c) : "m"(*(vu0_q *)(self + 0x10)));
                        *(vu0_q *)&f[11] = c;
                        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(vu0_q *)&f[8]));
                        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(vu0_q *)&f[3]));
                        __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
                        *(vu0_q *)&f[8] = x;
                        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(vu0_q *)&f[8]));
                        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(vu0_q *)&f[11]));
                        __asm__("vsub.xyz %0, %1, %2" : "=j"(c) : "j"(x), "j"(y));
                        __asm__("sqc2 %1, %0" : "=m"(*(vu0_q *)&f[9]) : "j"(c));
                    }
                    func_0038CF68(&f[9], &f[9], state->scale * 4.0f * 0.020000001415610313f);
                    life = func_00382498(20, 25) * 5;
                life = life + 2;
                life = life / 6;
                    p = func_L01_004713C8(&f[8], &f[9], life, 0x404040, rint, 0, 0x7F,
                                          s20 * 210000.0f,
                                          func_003824E0(s23, s22) * 210000.0f, 0.0f, 6);
                    if (p != 0) {
                        p[2] = *D_L01_00221098[23];
                        if (ic == 3) {
                            p[3] = 0x44;
                        }
                    }
                    if (ic == 3) {
                        if (func_00382468(2)) {
                            f32 s;
                            s32 col;
                            u8 *p2;
                            s = func_003824E0(0.05999999865889549f, 0.12999999523162842f);
                            col = func_00382468(3) ? 0x263438 : 0x273538;
                            func_0038CF68(&f[9], &f[9], 0.1300000101327896f);
                            n = func_00382498(15, 20);
                            p2 = func_L01_004713C8(&f[8], &f[9], (n * 5 + 2) / 6, col, -2, 0x7F, 0x7F,
                                                  s * 210000.0f, s * 210000.0f,
                                                  0.006240000482648611f, 0);
                            if (p2 != 0) {
                                p2[2] = (D_L01_00221098[0x61])[func_00382468(3) + 0xA];
                                p2[3] = 0x44;
                            }
                        }
                    }
                }
            }
            func_0038CF68(&f[2], D_L01_001E2DC0, -0.05000000074505806f);
            vec_add_ba(&f[3], D_L01_001E2DC0, (self + 0x10));
            vec_add_ab(&f[3], &f[3], &f[2]);
            func_0038CF68(&f[6], &D_L01_001E2DC0[2],
                          func_003824E0(state->scale + state->scale, state->scale * 3.0f));
            for (id2 = 0; id2 < 5; id2++) {
                s32 rint;
                s32 life;
                u8 *p;
                rint = (s32)func_L01_00443A18(2.0f, 5.0f);
                func_0038D890(&f[7], &f[6], &f[2], func_00382538());
                {
                    vu0_q x, y, c;
                    __asm__("lqc2 %0, %1" : "=j"(c) : "m"(*(vu0_q *)(self + 0x10)));
                    *(vu0_q *)&f[12] = c;
                    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(vu0_q *)&f[7]));
                    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(vu0_q *)&f[3]));
                    __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
                    *(vu0_q *)&f[7] = x;
                    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(vu0_q *)&f[7]));
                    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(vu0_q *)&f[12]));
                    __asm__("vsub.xyz %0, %1, %2" : "=j"(c) : "j"(x), "j"(y));
                    __asm__("sqc2 %1, %0" : "=m"(*(vu0_q *)&f[8]) : "j"(c));
                }
                func_0038CF68(&f[8], &f[8], state->scale * 4.0f * 0.020000001415610313f);
                life = func_00382498(20, 25) * 5;
                life = life + 2;
                life = life / 6;
                p = func_L01_004713C8(&f[7], &f[8], life, 0x404040, rint, 0, 0x7F,
                                      s20 * 210000.0f,
                                      func_003824E0(s23, s22) * 210000.0f, 0.0f, 6);
                if (p != 0) {
                    p[2] = *D_L01_00221098[23];
                    if (id2 == 3) {
                        p[3] = 0x44;
                    }
                }
            }
        }
        if ((D_L01_002C5600 + D_001425C0[0x5F])->level >= 4) {
            n = func_003D4D00((self + 0x10), 1, state->scale + 4.5f, (void *)D_001A4BE0.w[0x25C0 / 4], 0);
            if (n > 0) {
                u8 **tbl = D_L01_001EEA80;
                for (k1 = n; k1 != 0; k1--, tbl++) {
                    u8 *m;
                    u8 *cls;
                    s32 id, cc;
                    u8 *q;
                    m = *tbl;
                    if (m == 0) {
                        continue;
                    }
                    cls = *(u8 **)(m + 0x24);
                    if (cls == 0 || cls[0x46] != 5) {
                        if (!func_003C4B50(m)) {
                            continue;
                        }
                        m = *tbl;
                    }
                    id = *(s16 *)(m + 0xAA);
                    if (id == 0x1F8) {
                        continue;
                    }
                    if (id == 0x1699) {
                        continue;
                    }
                    cc = 0x165C;
                    if (id == cc) {
                        continue;
                    }
                    cc = 0x1612;
                    if (id == cc) {
                        continue;
                    }
                    cc = 0x16FA;
                    if (id == cc) {
                        continue;
                    }
                    cc = 0x16CB;
                    if (id == cc) {
                        continue;
                    }
                    if (*(u16 *)(m + 0x34) & 2) {
                        continue;
                    }
                    q = func_00382348(m);
                    if (q == 0 || q[0x34] == 0) {
                        continue;
                    }
                    zf = 0.0f;
                    if (!(zf < *(f32 *)q)) {
                        continue;
                    }
                    if (func_00382468(0x12) == 0) {
                        *(vu0_q *)&f[2] = *(vu0_q *)(*tbl + 0x10);
                        func_L01_0034E558(*tbl, 0x800530, &f[2], self, 0);
                    }
                }
            }
        }
        target = state->target;
        if (target == 0) {
            s32 count;
                        count = func_003D4D00((self + 0x10), 1, state->scale + 9.0f, (void *)D_001A4BE0.w[0x25C0 / 4], 0);
            for (k2 = 0; k2 < count; k2++) {
                u8 *m;
                u8 *cls;
                s32 id, cc;
                u8 *q;
                m = D_L01_001EEA80[k2];
                if (m == 0) {
                    continue;
                }
                cls = *(u8 **)(m + 0x24);
                if (cls == 0 || cls[0x46] != 5) {
                    if (!func_003C4B50(m)) {
                        continue;
                    }
                    m = D_L01_001EEA80[k2];
                    cc = 0x1F8;
                } else {
                    cc = 0x1F8;
                }
                id = *(s16 *)(m + 0xAA);
                if (id == cc) {
                    continue;
                }
                if (id == 0x1699 || id == 0x165C || id == 0x1612 || id == 0x16FA ||
                    id == 0x16CB) {
                    continue;
                }
                if (*(u16 *)(m + 0x34) & 2) {
                    continue;
                }
                q = func_00382348(m);
                if (*(s16 *)(D_L01_001EEA80[k2] + 0xAA) == 0x1BF5 && q != 0) {
                    f32 d = *(f32 *)q;
                    if (0.0f < d &&
                        d <= ((D_L01_002C5600 + D_001425C0[0x5F])->damage * state->scale) * 2.0f) {
                        q[0x2E] = 1;
                        return;
                    }
                }
                if (func_003C4B50(D_L01_001EEA80[k2])) {
                    state->target = D_L01_001EEA80[k2];
                    *(vu0_q *)&f[2] = *(vu0_q *)&state->velocity;
                    func_0038CE20(&f[2], &f[2], 3.0f);
                    f[2].w = 5627.9248046875f;
                    func_L01_00446760(&f[3], self, 0x10000, &f[2], 1.0f);
                    ((HitInfo *)&f[3])->f19 = 1;
                    ((HitInfo *)&f[3])->f1A = *(u16 *)(self + 0xAA);
                    ((HitInfo *)&f[3])->f18 = 0;
                    func_003D4D00(D_L01_001EEA80[k2] + 0x10, 0, 1.0f, self, &f[3]);
                    return;
                }
                if (q == 0 || q[0x34] == 0) {
                    continue;
                }
                if (!(0.0f < *(f32 *)q) || q[0x2E] != 0) {
                    continue;
                }
                if (!(*(f32 *)q <= ((D_L01_002C5600 + D_001425C0[0x5F])->damage * state->scale) * 2.0f)) {
                    continue;
                }
                {
                    u8 **list0 = func_L01_00448FB8(D_L01_001EEA80[k2]);
                    if (list0 != 0) {
                        u8 **list = list0;
                        for (ie = 0; ie < 4; ie++, list++) {
                            if (*list != 0) {
                                u8 *r = func_00382348(*list);
                                if (r != 0) {
                                    r[0x2E] = 1;
                                }
                            }
                        }
                    }
                }
                func_L01_00374908((S_3738B0 *)self, (S_3738B0 *)D_L01_001EEA80[k2]);
                if (state->target != D_L01_001EEA80[k2]) {
                    return;
                }
                *(vu0_q *)&f[2] = *(vu0_q *)&state->velocity;
                func_0038CE20(&f[2], &f[2], 3.0f);
                f[2].w = 5627.9248046875f;
                func_L01_00446760(&f[3], self, 0x10000, &f[2], 0.0f);
                ((HitInfo *)&f[3])->f19 = 1;
                ((HitInfo *)&f[3])->f1A = *(u16 *)(self + 0xAA);
                ((HitInfo *)&f[3])->f18 = 0;
                func_003D4D00(D_L01_001EEA80[k2] + 0x10, 0, 1.0f, self, &f[3]);
                return;
            }
            return;
        }
        {
        u8 *qt = func_00382348(target);
        if (qt == 0) {
            state->target = 0;
            return;
        }
        if (qt[0x2E] != 0) {
            state->target = 0;
            return;
        }
        }
        *(u16 *)(state->target + 0x34) |= 2;
        func_L01_00448340(state->target + 0x10, (self + 0x10), state->pad58,
                          state->f90 * state->scale * 1.5f * 0.0004000000189989805f,
                          state->f90 * state->scale * 1.5f * 0.0004000000189989805f,
                          state->f90 * state->scale * 1.5f * 0.020000001415610313f);
        {
        u8 **tbl0 = func_L01_00448FB8(state->target);
        if (tbl0 != 0) {
            u8 **tbl = tbl0;
            for (if_ = 0; if_ < 4; if_++, tbl++) {
                if (*tbl != 0) {
                    func_L01_00448340(*tbl + 0x10, (self + 0x10), state->pad98,
                                      state->f90 * state->scale * 1.5f * 0.0004000000189989805f,
                                      state->f90 * state->scale * 1.5f * 0.0004000000189989805f,
                                      state->f90 * state->scale * 1.5f * 0.020000001415610313f);
                    *(f32 *)(*tbl + 0xF8) = func_0038DAB8(*(f32 *)(*tbl + 0xF8), 0.30000001192092896f);
                    *(f32 *)(*tbl + 0xF0) = func_0038DAB8(*(f32 *)(*tbl + 0xF0), 0.10000000149011612f);
                    *(f32 *)(*tbl + 0xF4) = func_0038DAB8(*(f32 *)(*tbl + 0xF4), -0.20000000298023224f);
                    *(f32 *)(*tbl + 0x2C) = *(f32 *)(*tbl + 0x2C) * 0.9519999623298645f;
                    func_0038D308(*tbl + 0xC0, *tbl + 0xF0);
                }
            }
        }
        }
        if (state->f94 < 30) {
            *(f32 *)(state->target + 0x2C) = *(f32 *)(state->target + 0x2C) * 0.9900000095367432f;
            state->f94++;
        }
        *(f32 *)(state->target + 0xF8) = func_0038DAB8(*(f32 *)(state->target + 0xF8), 0.30000001192092896f);
        *(f32 *)(state->target + 0xF0) = func_0038DAB8(*(f32 *)(state->target + 0xF0), 0.10000000149011612f);
        *(f32 *)(state->target + 0xF4) = func_0038DAB8(*(f32 *)(state->target + 0xF4), -0.20000000298023224f);
        func_0038D308(state->target + 0xC0, state->target + 0xF0);
        func_003C7C38(state->target);
        if (!(func_0038CF00(state->target + 0x10, (self + 0x10)) < 0.10000000149011612f)) {
            return;
        }
        *(u16 *)(state->target + 0x34) &= 0xFFFD;
        q = func_00382348(state->target);
        if (q != 0) {
            if (D_L01_001D7BE0 < 0x29) {
                if (D_L01_001D7BE0 != 9) {
                    n = func_L01_00444350();
                    pd = D_00142DE0;
                    *(s32 *)(pd + 0x17C) += n;
                }
            } else {
                if (D_L01_001D7BE0 != 9) {
                    u8 *pd2;
                    pd2 = D_00142DE0;
                    *(s32 *)(pd2 + 0x17C) += *(u16 *)(state->target + 0xB6);
                }
            }
            func_003A52A0(2, 0, self);
            q[0x2E] = 1;
        }
        if (func_003C4B50(state->target)) {
            p = state->target;
            qzero(p + 0xF0);
            p[0xA8] = 0xFF;
            *(f32 *)(p + 0x2C) = *(f32 *)(*(u8 **)(p + 0x24) + 0x24);
            *(s32 *)(*(u8 **)(p + 0x68) + 0x12C) = 0;
            func_L01_0033D0E8(p);
        }
        state->target = 0;
        for (ig = 0; ig < 3; ig++) {
            u8 *p;
            p = func_L01_004713C8((self + 0x10), &D_L01_001D66B0, 0x11, 0x204080, 5, 0, 0x7F,
                                  state->scale * 3.5f * 210000.0f,
                                  state->scale * 0.20000000298023224f * 210000.0f, 0.0f, 6);
            if (p != 0) {
                p[2] = *D_L01_00221098[0x59];
            }
        }
        return;
    case 3: {
        u8 *tg3 = state->target;
        if (tg3 != 0) {
            if (2500.0f < func_L01_0040E548((f32 *)(tg3 + 0x10), (f32 *)((self + 0x10)))) {
                *(u16 *)(state->target + 0x34) &= 0xFFFD;
                {
                u8 *t3 = func_00382348(state->target);
                if (t3 != 0) {
                    t3[0x2E] = 1;
                }
                }
            } else {
                self[0x20] = 2;
                state->timer = 0;
            }
        }
        if (++state->timer < 18) {
            func_L01_00404A10(func_L01_00376D08, self);
            return;
        }
        }
        break;
    case 4: {
        /* z is set only when a target is held; the sound call below is reached only when none is
         * (that branch resets the timer, so the < 18 test returns), so z is read unset there. Retail
         * schedules the call's second argument as a register that dies, which a literal 0 does not
         * give. Precedent for passing an unset local to a call: rac2's matched func_003116E8
         * (rac2 src/game/0030F7B0.c) passes the unset `member` on its group == 255 path. */
        s32 z;
        if (state->target != 0) {
            self[0x20] = 2;
            state->timer = z = 0;
        }
        if (++state->timer < 18) {
            goto callback;
        }
        func_003A52A0(1, z, self);
        }
        break;
    default:
        return;
    }

    if (state->entry != -1) {
        entry = D_001A30B0 + state->entry * 0x80;
        if (*(u8 **)(entry + 0xDC) == self && entry[0xD0] != 0) {
            func_003A4F28(state->entry);
        }
    }
    state->entry = -1;
    func_L01_003779C8(self);
destroy:
    func_L01_004C8668(state->effect);
    func_003C2880(self);
    return;

callback:
    func_L01_00404A10(func_L01_00376D08, self);
}
/* localdecomp:end func_L01_003749E8 */

LINKER_REMNANT("asm/levels", func_L01_00376170);
