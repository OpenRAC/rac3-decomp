/* functional: high. Retail takes the object in $t1 (9th parameter slot) and ignores every other argument (it rebuilds its own constants); prototype kept as the caller func_L09_00350B30 passes it. VU0 xyz adds/subs as plain float ops (w kept). Compiles at level 09 (721 diff words, scheduling/stack 0x150 vs 0x160). */
#include "vu0.h"

typedef struct {
    vu0_v4 v[4];
    s32 c[4];
    f32 uv[8];
    long x70;
    u8 pad78[0x18];
} S_00350CB0;

extern f32 D_L09_001DD3E8;
extern u8 D_L09_001E2B00[];

extern void func_L01_0034D840(void *);
extern void func_003D93B0(void *, s32, s32, s32);
extern void func_003D2DA0(void *, s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_00382538(void);
extern void func_003D9508(void *, s32, s32, s32, f32, f32, f32);

static __inline__ void add3_00350CB0(vu0_v4 *d, vu0_v4 *a, vu0_v4 *b) {
    vu0_v4 r = *a;
    r.x = a->x + b->x;
    r.y = a->y + b->y;
    r.z = a->z + b->z;
    *d = r;
}

static __inline__ void sub3_00350CB0(vu0_v4 *d, vu0_v4 *a, vu0_v4 *b) {
    vu0_v4 r = *a;
    r.x = a->x - b->x;
    r.y = a->y - b->y;
    r.z = a->z - b->z;
    *d = r;
}

/* Only the last argument (the object, in $t1) is used; the others are retail's unused leading parameters. */
void func_L09_00350CB0(u8 *a0, s32 a1, f32 fa, s32 a3, f32 fb, f32 fc, s32 t0, s32 t1, u8 *obj) {
    S_00350CB0 s;
    vu0_v4 v90, vA0, vB0, vC0, vD0;
    u8 *st = *(u8 **)(obj + 0x68);
    vu0_v4 *pos = (vu0_v4 *)(obj + 0x10);
    f32 f, u, v, sn, cs, rot;
    s32 i;

    func_L01_0034D840(&s);
    func_003D93B0(&s, 0x1C, 1, 0x80);
    s.c[0] = 0xFF1414FF;
    s.c[1] = 0xFF1414FF;
    s.c[2] = 0x80204080;
    s.c[3] = 0x80204080;
    s.uv[0] = 0.0f; s.uv[1] = 0.0f; s.uv[2] = 0.0f; s.uv[3] = 1.0f;
    s.uv[4] = 1.0f; s.uv[5] = 0.0f; s.uv[6] = 1.0f; s.uv[7] = 1.0f;
    for (i = 0; i < 4; i++) {
        f = s.uv[i * 2] - *(f32 *)(st + 0x28);
        s.uv[i * 2] = f;
        if (f <= 7.0f) {
            s.uv[i * 2] = f + 7.0f;
        }
    }
    f = *(f32 *)(st + 0x28) + 0.1f;
    *(f32 *)(st + 0x28) = f;
    if (4.0f <= f) {
        *(f32 *)(st + 0x28) = f - 4.0f;
    }

    sub3_00350CB0(&v90, pos, (vu0_v4 *)D_L09_001E2B00);
    func_0038CF68(&vA0, st, -2.0f);
    add3_00350CB0(&vB0, pos, &vA0);
    func_0038CE90(&vC0, &v90, &vA0);
    func_0038CF68(&vC0, &vC0, 0.2f);
    func_0038CF68(&vD0, st, D_L09_001DD3E8);
    add3_00350CB0(&vD0, pos, &vD0);
    add3_00350CB0(&s.v[0], &vD0, &vC0);
    sub3_00350CB0(&s.v[1], &vD0, &vC0);
    add3_00350CB0(&s.v[2], &vB0, &vC0);
    sub3_00350CB0(&s.v[3], &vB0, &vC0);
    func_003D2DA0(&s, 0, 0);

    s.c[0] = s.c[2];
    s.c[1] = s.c[3];
    s.c[2] = 0x801010;
    s.c[3] = 0x801010;
    s.v[0] = s.v[2];
    s.v[1] = s.v[3];
    add3_00350CB0(&s.v[2], &s.v[2], &vA0);
    add3_00350CB0(&s.v[3], &s.v[3], &vA0);
    func_003D2DA0(&s, 0, 0);

    func_0038CF68(&vA0, st, -4.0f);
    s.uv[0] = 0.0f; s.uv[1] = 0.0f; s.uv[2] = 0.0f; s.uv[3] = 1.0f;
    s.uv[4] = 1.0f; s.uv[5] = 0.0f; s.uv[6] = 1.0f; s.uv[7] = 1.0f;
    rot = *(f32 *)(st + 0x1C);
    sn = func_0038D098(rot);
    cs = func_0038D0B0(rot);
    for (i = 0; i < 4; i++) {
        u = s.uv[i * 2] - 0.5f;
        v = s.uv[i * 2 + 1] - 0.5f;
        s.uv[i * 2] = u * sn - v * cs;
        s.uv[i * 2 + 1] = u * cs + v * sn;
        s.uv[i * 2] += 0.5f;
        s.uv[i * 2 + 1] += 0.5f;
    }
    *(f32 *)(st + 0x1C) = func_0038DAB8(*(f32 *)(st + 0x1C), 0.17453292f);

    func_003D93B0(&s, 8, 1, 0x80);
    s.c[0] = 0x5A141480;
    s.c[1] = 0x5A141480;
    s.c[2] = 0x808080;
    s.c[3] = 0x808080;
    s.x70 = 5;
    func_0038CF68(&vC0, &vC0, 0.2f);
    func_0038CF68(&vD0, st, D_L09_001DD3E8);
    add3_00350CB0(&vD0, pos, &vD0);
    add3_00350CB0(&s.v[0], &vD0, &vC0);
    sub3_00350CB0(&s.v[1], &vD0, &vC0);
    add3_00350CB0(&vB0, &vD0, &vA0);
    add3_00350CB0(&vB0, &vB0, &vA0);
    add3_00350CB0(&s.v[2], &vB0, &vC0);
    sub3_00350CB0(&s.v[3], &vB0, &vC0);
    func_003D2DA0(&s, 0, 0);

    s.c[0] = 0x5A141480;
    s.c[1] = 0x5A141480;
    s.c[2] = 0x808080;
    s.c[3] = 0x808080;
    func_0038CF68(&vC0, &vC0, 0.1f);
    func_0038CF68(&vD0, st, 0.75f);
    add3_00350CB0(&vD0, pos, &vD0);
    add3_00350CB0(&s.v[0], &vD0, &vC0);
    sub3_00350CB0(&s.v[1], &vD0, &vC0);
    add3_00350CB0(&vB0, &vD0, &vA0);
    add3_00350CB0(&vB0, &vB0, &vA0);
    add3_00350CB0(&s.v[2], &vB0, &vC0);
    sub3_00350CB0(&s.v[3], &vB0, &vC0);
    func_003D2DA0(&s, 0, 0);

    s.c[0] = 0x3C141480;
    s.c[1] = 0x3C141480;
    s.c[2] = 0x808080;
    s.c[3] = 0x808080;
    func_0038CF68(&vC0, &vC0, 0.4f);
    func_0038CF68(&vD0, st, 0.75f);
    add3_00350CB0(&vD0, pos, &vD0);
    add3_00350CB0(&s.v[0], &vD0, &vC0);
    sub3_00350CB0(&s.v[1], &vD0, &vC0);
    add3_00350CB0(&vB0, &vD0, &vA0);
    add3_00350CB0(&vB0, &vB0, &vA0);
    add3_00350CB0(&s.v[2], &vB0, &vC0);
    sub3_00350CB0(&s.v[3], &vB0, &vC0);
    func_003D2DA0(&s, 0, 0);

    s.c[0] = 0x64FFFFFF;
    s.c[1] = 0x64FFFFFF;
    s.c[2] = 0x808080;
    s.c[3] = 0x808080;
    func_0038CF68(&vC0, &vC0, 0.2f);
    func_0038CF68(&vD0, st, 0.0f);
    add3_00350CB0(&vD0, pos, &vD0);
    add3_00350CB0(&s.v[0], &vD0, &vC0);
    sub3_00350CB0(&s.v[1], &vD0, &vC0);
    func_0038CF68(&vA0, st, -0.6f);
    add3_00350CB0(&vB0, &vD0, &vA0);
    add3_00350CB0(&vB0, &vB0, &vA0);
    add3_00350CB0(&s.v[2], &vB0, &vC0);
    sub3_00350CB0(&s.v[3], &vB0, &vC0);
    func_003D2DA0(&s, 0, 0);

    func_003D9508(pos, 0x10, 0x202020B0, 1, 1.0f, 0.08f, func_00382538());
    func_003D9508(pos, 0x10, 0x80808080, 1, 0.4f, 0.08f, func_00382538());
}
