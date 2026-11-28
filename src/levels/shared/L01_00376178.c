#include "common.h"

/* localdecomp:start func_L01_00376178 */
#include "vu0.h"
typedef struct {
    vu0_v4 v[4]; u32 color[4]; f32 uv[4][2];
    u8 pad70[0x18]; unsigned long tag;
} Draw_00376178;
typedef struct {
    Draw_00376178 draw;
    vu0_v4 basis[3]; vu0_v4 pos; vu0_v4 delta; vu0_v4 matrix[3];
} Work_00376178;
typedef int u128_00376178 __attribute__((mode(TI)));
extern vu0_v4 D_L01_001E2A40;
extern vu0_v4 D_001A4EC0;
extern vu0_v4 D_L01_001D7C50[];
extern void func_003D93B0(void *, s32, s32, s32);
extern void func_0038CF68_00376178(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038D308(void *, void *);
extern void func_0038D5F0(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D028(void *, void *, void *);
extern void func_003A9440(s32, unsigned long);
extern void func_003D2DA0(void *, s32, s32);
extern void func_00389478(void *, f32 *, f32 *);

void func_L01_00376178(void *position, s32 texture, f32 size, f32 offset, f32 angle, f32 stretch) {
    Work_00376178 w;
    s32 i;
    func_003D93B0(&w.draw, texture, 1, 0x80);
    w.draw.tag = 0x800000004A;
    w.draw.color[3] = 0x80808080;
    w.draw.color[2] = 0x80808080;
    w.draw.color[1] = 0x80808080;
    w.draw.color[0] = 0x80808080;
    *(u128_00376178 *)&w.pos = *(u128_00376178 *)position;
    w.draw.uv[0][0] = 0; w.draw.uv[0][1] = 0;
    w.draw.uv[1][0] = 0; w.draw.uv[1][1] = 1;
    w.draw.uv[2][0] = 1; w.draw.uv[2][1] = 0;
    w.draw.uv[3][0] = 1; w.draw.uv[3][1] = 1;
    vec_sub_ab(&w.basis[0], &D_L01_001E2A40, &w.pos);
    func_0038CF68_00376178(&w.basis[0], &w.basis[0], 1.0f);
    func_0038CE90(&w.basis[1], &w.basis[0], &D_001A4EC0);
    func_0038CF68_00376178(&w.basis[1], &w.basis[1], 1.0f);
    func_0038CE90(&w.basis[2], &w.basis[1], &w.basis[0]);
    if (angle != 0.0f) {
        *(u128_00376178 *)&w.delta = 0;
        w.delta.x = angle;
        func_0038D308(w.matrix, &w.delta);
        func_0038D5F0(w.basis, w.basis, w.matrix);
    }
    func_0038CE20(&w.delta, w.basis, offset);
    vec_add_ab(&w.pos, &w.pos, &w.delta);
    for (i = 0; i < 4; i++) {
        func_0038CE20(&w.draw.v[i], &D_L01_001D7C50[i], size);
        func_0038D028(&w.draw.v[i], &w.draw.v[i], w.basis);
    }
    func_003A9440(0x47, 0x31001);
    func_003D2DA0(&w.draw, 0, 0);
    {
        s32 k;
        s32 j;
        *(u128_00376178 *)&w.matrix[0] = *(u128_00376178 *)&w.draw.v[0];
        for (k = 1; k < 4; k++) vec_add_ba(&w.matrix[0], &w.matrix[0], &w.draw.v[k]);
        func_0038CE20(&w.matrix[0], &w.matrix[0], 0.25f);
        for (j = 0; j < 4; j++) {
            vec_sub_ab(&w.matrix[1], &w.draw.v[j], &w.matrix[0]);
            func_0038CE20(&w.matrix[1], &w.matrix[1], stretch);
            vec_add_ab(&w.matrix[1], &w.matrix[0], &w.matrix[1]);
            func_00389478(&w.matrix[1], &w.draw.uv[j][0], &w.draw.uv[j][1]);
        }
    }
    func_003D93B0(&w.draw, -1, 1, 0x80);
    w.draw.tag = 0x2000000054;
    func_003A9440(0x47, 0x53001);
    func_003D2DA0(&w.draw, 0, 0);
    func_003A9440(0x47, 0x5360B);
}
/* localdecomp:end func_L01_00376178 */

/* localdecomp:start func_L01_00376490 */
/* func_L01_00376490 (wave 14 retry r83, from r53's 8-diff first draft): the ribbon loop is the matched sibling
 * func_L01_00360A48's form, i = 0; do { ... i++; } while (i < 33); with i declared in the loop's own block and the
 * 24-entry loop counting with n. gcse's PRE then hoists i + 1 above the if (i != 0) block as retail does, and the
 * reaching registers (and so reload's stack slots) come in retail's order. */
typedef struct {
    vu0_v4 v[4]; u32 color[4]; f32 uv[4][2];
    unsigned long x70; u8 pad78[0x10]; unsigned long tag;
} Draw_00376490;
typedef struct {
    u8 pad0[0x40]; f32 phase, radius; u8 pad48[0x20];
    f32 scale; u8 pad6C[4];
    f32 a, b, angle, angle2, t; u8 pad84[4]; f32 spin; u8 pad8C[0x14];
    vu0_v4 direction[24], result[24]; f32 angles[24];
} State_00376490;
void func_L01_00376490(u8 *obj) {
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern f32 func_0038DAB8(f32, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038D890(void *, void *, void *, f32);
    extern void func_L01_0040A8C0(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_00382538(void);
    extern void func_003D9508(void *, s32, s32, s32, f32, f32, f32);
    vu0_v4 v0, dir, side, up, base, start, prev, cur, tmp;
    Draw_00376490 pk;
    State_00376490 *s = *(State_00376490 **)(obj + 0x68);
    f32 t = s->t;
    f32 shrink, ang, sn, cs, grow, lim;
    s32 j, k, n;

    if (1.0f < t) {
        s->t = 1.0f;
    } else if (t < 0.0f) {
        s->t = 0.0f;
    }
    shrink = (1.0f - func_0038D098(t * 3.1415927f)) * 0.5f * 0.6f;
    vec_sub_ab(&dir, obj + 0x10, &D_L01_001E2A40);
    func_0038CF68(&dir, &dir, s->t + 0.5f);
    func_0038CF68(&up, &D_001A4EC0, 1.0f);
    func_0038CE90(&up, &dir, &up);
    func_0038CF68(&up, &up, s->t + 1.0f);
    func_0038CE90(&side, &up, &dir);
    func_0038CF68(&side, &side, s->t + 0.5f);
    func_0038CF68(&v0, &up, -0.05f);
    vec_add_ba(&base, obj + 0x10, &v0);
    vec_add_ba(&start, &base, &dir);
    func_0038CE20(&v0, &dir, -0.05f);
    vec_add_ab(&base, &base, &dir);
    ang = s->spin = func_0038DAB8(s->spin, 0.0139626348f);
    {
        s32 i;

        i = 0;
        do {
            *(vu0_q *)&cur = *(vu0_q *)&base;
            sn = func_0038D098(ang);
            cs = func_0038D0B0(ang);
            if (sn != 0.0f) {
                func_0038CE20(&tmp, &up, sn);
                vec_add_ab(&cur, &cur, &tmp);
            }
            if (cs != 0.0f) {
                func_0038CE20(&tmp, &side, cs);
                vec_add_ab(&cur, &cur, &tmp);
            }
            if (i != 0) {
                func_003D93B0(&pk, 0x4D, 1, 0x80);
                pk.tag = 0x800000004A;
                *(vu0_q *)&pk.v[0] = *(vu0_q *)&prev;
                *(vu0_q *)&pk.v[1] = *(vu0_q *)&cur;
                pk.color[3] = 0x80808080;
                pk.color[2] = 0x80808080;
                pk.color[1] = 0x80808080;
                pk.color[0] = 0x80808080;
                pk.uv[0][0] = 0.0f; pk.uv[0][1] = 0.0f;
                pk.uv[1][0] = 1.0f; pk.uv[1][1] = 0.0f;
                pk.uv[2][0] = 0.0f; pk.uv[2][1] = 1.0f;
                pk.uv[3][0] = 1.0f; pk.uv[3][1] = 1.0f;
                *(vu0_q *)&pk.v[2] = *(vu0_q *)&start;
                *(vu0_q *)&pk.v[3] = *(vu0_q *)&start;
                func_003A9440(0x47, 0x31001);
                func_003D2DA0(&pk, 0, 0);
                for (j = 0; j < 4; j++) {
                    func_00389478(&pk.v[j], &pk.uv[j][0], &pk.uv[j][1]);
                }
                tmp.x = (pk.uv[0][0] + pk.uv[1][0]) * 0.5f;
                tmp.y = (pk.uv[0][1] + pk.uv[1][1]) * 0.5f;
                for (k = 2; k < 4; k++) {
                    pk.uv[k][0] += (tmp.x - pk.uv[k][0]) * shrink;
                    pk.uv[k][1] += (tmp.y - pk.uv[k][1]) * shrink;
                }
                func_003D93B0(&pk, -1, 1, 0x80);
                pk.x70 = 5;
                pk.tag = 0x8000000054;
                func_003A9440(0x47, 0x53001);
                func_003D2DA0(&pk, 0, 0);
                func_003A9440(0x47, 0x5360B);
            }
            *(vu0_q *)&prev = *(vu0_q *)&cur;
            ang = func_0038DAB8(ang, 0.19634955f);
            i++;
        } while (i < 33);
    }
    s->a -= 0.04f;
    if (s->a <= 0.1f) {
        s->a = s->scale * 2.25f;
    }
    s->b -= 0.025f;
    if (s->b <= 0.1f) {
        s->b = s->scale * 2.25f;
    }
    s->angle = func_0038DAB8(s->angle, 0.052359879f);
    s->angle2 = func_0038DAB8(s->angle, 0.087266468f);
    func_L01_00376178(obj + 0x10, 54, s->a, 0.5f, s->angle, 0.8f);
    func_L01_00376178(obj + 0x10, 54, s->b, 0.5f, s->angle2, 0.8f);
    func_L01_00376178(obj + 0x10, 54, s->scale * 2.27f, 0.5f, -s->angle, 0.8f);
    func_L01_00376178(obj + 0x10, 54, s->scale * 2.27f, 0.5f, s->angle, 0.8f);
    for (n = 0; n < 24; n++) {
        func_0038D890(&s->result[n], &s->result[n], &s->direction[n], s->angles[n]);
        grow = s->radius + 0.03f;
        lim = s->scale * 3.0f;
        s->radius = grow;
        if (lim < grow) {
            s->radius = lim;
        }
        func_0038CF68(&s->result[n], &s->result[n], s->radius);
        vec_add_ab(&cur, &s->result[n], obj + 0x10);
        *(vu0_q *)&tmp = *(vu0_q *)(obj + 0x10);
        func_L01_0040A8C0(&cur, &tmp, 18, 1, 0x2020FF, 0x2020FF, 0x2FFF2020, 0x2FFF2020,
                          s->scale * 0.08f, s->scale * 3.0f, s->phase);
    }
    s->phase -= func_003824E0(0.025f, 0.035f);
    if (s->phase <= -8.0f) {
        s->phase += 8.0f;
    }
    func_003D9508(obj + 0x10, 57, 0x4FFFFFFF, 1, s->scale * 0.25f * 1.3f, 0.0f, func_00382538());
    func_003D9508(obj + 0x10, 11, 0x3FFF2040, 3, s->scale * 0.3f * 1.3f, 0.01f, func_00382538());
    func_003D9508(obj + 0x10, 57, 0x4FFFFFFF, 1, s->scale * 0.27f * 1.3f, 0.0f, func_00382538());
    func_003D9508(obj + 0x10, 11, 0x3FFF2040, 1, s->scale * 0.35f * 1.3f, 0.01f, func_00382538());
}
/* localdecomp:end func_L01_00376490 */

/* localdecomp:start func_L01_00376D08 */
#include "vu0.h"
typedef struct {
    u8 pad[0x40]; f32 phase, radius; u8 pad48[0x28];
    f32 a, b, angle, angle2; u8 pad80[0x20];
    vu0_v4 direction[24], result[24]; f32 angles[24];
} State_00376D08;
typedef struct { u8 pad0[0x10]; vu0_v4 pos; u8 pad20[0x48]; State_00376D08 *state; } M_00376D08;
extern f32 func_0038DAB8(f32, f32);
extern void func_L01_00376178(void *, s32, f32, f32, f32, f32);
extern void func_0038D890(void *, void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_0040A8C0(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern void func_003D9508(void *, s32, s32, s32, f32, f32, f32);
void func_L01_00376D08(M_00376D08 *obj)
{
    vu0_v4 at, center;
    State_00376D08 *s = obj->state;
    s32 i;
    s->a -= 0.04f;
    if (s->a <= 0.0f) s->a = 0.0f;
    s->b -= 0.025f;
    if (s->b <= 0.0f) s->b = 0.0f;
    s->angle = func_0038DAB8(s->angle, 0.052359879f);
    s->angle2 = func_0038DAB8(s->angle, 0.087266468f);
    func_L01_00376178(&obj->pos, 54, s->a, 0.5f, s->angle, 0.5f);
    func_L01_00376178(&obj->pos, 54, s->b, 0.5f, s->angle2, 0.5f);
    func_L01_00376178(&obj->pos, 54, s->radius, 0.5f, -s->angle, 0.8f);
    func_L01_00376178(&obj->pos, 54, s->radius, 0.5f, s->angle, 0.8f);
    s->radius -= 0.125f;
    if (s->radius < 0.0f) s->radius = 0.0f;
    for (i = 0; i < 24; i++) {
        func_0038D890(&s->result[i], &s->result[i], &s->direction[i], s->angles[i]);
        func_0038CF68(&s->result[i], &s->result[i], s->radius);
        vec_add_ab(&at, &s->result[i], &obj->pos);
        *(vu0_q *)&center = *(vu0_q *)&obj->pos;
        func_L01_0040A8C0(&at, &center, 18, 1, 0x2020FF, 0x2020FF, 0x1FFF2020, 0x1FFF2020, 0.08f, 3.0f, s->phase);
    }
    s->phase -= func_003824E0(0.025f, 0.035f);
    if (s->phase <= -8.0f) s->phase += 8.0f;
    func_003D9508(&obj->pos, 57, 0x4FFFFFFF, 1, 0.25f, 0.0f, func_00382538());
    func_003D9508(&obj->pos, 11, 0x3FFF2040, 3, 0.3f, 0.01f, func_00382538());
    func_003D9508(&obj->pos, 57, 0x4FFFFFFF, 1, 0.27f, 0.0f, func_00382538());
    func_003D9508(&obj->pos, 11, 0x3FFF2040, 1, 0.35f, 0.01f, func_00382538());
}
/* localdecomp:end func_L01_00376D08 */

/* localdecomp:start func_L01_003770A8 */
__asm__(".extern D_L01_001DDAD4, 4");
__asm__(".extern D_L01_001DDAE0, 4");
__asm__(".extern D_L01_001DDAEC, 4");
__asm__(".extern D_L01_001DDAE4, 4");
__asm__(".extern D_L01_001DDAF0, 4");
__asm__(".extern D_L01_001DDAE8, 4");
__asm__(".extern D_L01_001DDAF4, 4");
__asm__(".extern D_L01_001DDAF8, 4");

typedef struct {
    u8 pad0[0x10];
    f32 pos[4];       /* 0x10 */
    u8 pad20[0x68 - 0x20];
    u8 *state;        /* 0x68 */
} M_3770A8;

extern f32 D_L01_001DDAD4;   /* spin of the first billboard, degrees a frame */
extern f32 D_L01_001DDAE0;
extern f32 D_L01_001DDAEC;
extern f32 D_L01_001DDAE4;
extern f32 D_L01_001DDAF0;
extern f32 D_L01_001DDAE8;
extern f32 D_L01_001DDAF4;
extern f32 D_L01_001DDAF8;   /* the drawn size */
extern f32 func_0038DAB8(f32, f32);
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern void func_003D9508(void *, s32, s32, s32, f32, f32, f32);
extern void func_L01_0040AAC8(void *, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32);

/* rift_flight_draw: the rift's in-flight draw within 96 u of the view */
void func_L01_003770A8(M_3770A8 *obj) {
    f32 *q = obj->pos;
    f32 *st = (f32 *)obj->state;
    f32 s;
    f32 r;

    st[12] = func_0038DAB8(st[12], D_L01_001DDAD4 * 0.017453292f);
    D_L01_001DDAE0 = func_0038DAB8(D_L01_001DDAE0, func_003824E0(-0.5f, -1.0f) * 0.017453292f);
    D_L01_001DDAEC = func_0038DAB8(D_L01_001DDAEC, func_003824E0(-1.0f, -2.0f) * 0.017453292f);
    D_L01_001DDAE4 = func_0038DAB8(D_L01_001DDAE4, func_003824E0(-1.0f, -1.5f) * 0.017453292f);
    D_L01_001DDAF0 = func_0038DAB8(D_L01_001DDAF0, func_003824E0(-1.5f, -2.5f) * 0.017453292f);
    D_L01_001DDAE8 = func_0038DAB8(D_L01_001DDAE8, func_003824E0(-0.5f, -1.5f) * 0.017453292f);
    D_L01_001DDAF4 = func_0038DAB8(D_L01_001DDAF4, func_003824E0(-0.5f, -1.5f) * 0.017453292f);
    func_003D9508(q, 76, 0x6FFF4040, 1, D_L01_001DDAF8 * 1.2f, 0.01f, D_L01_001DDAF0);
    func_003D9508(q, 76, 0x7FFF0032, 1, D_L01_001DDAF8 * 0.7f, 0.01f, -D_L01_001DDAEC);
    func_003D9508(q, 76, 0x7F701010, 1, D_L01_001DDAF8 * 0.2f, 0.01f, D_L01_001DDAEC);
    func_003D9508(q, 75, 0x7F204080, 1, D_L01_001DDAF8 * 0.7f, 0.01f, D_L01_001DDAF0);
    func_L01_0040AAC8(q, 71, 72, 0x4FFF0032, 0, D_L01_001DDAF8, 1.0f, 1.4f, D_L01_001DDAE0, D_L01_001DDAEC, 0.0f);
    func_L01_0040AAC8(q, 71, 72, 0x4F804020, 0, D_L01_001DDAF8, 1.0f, 1.4f, D_L01_001DDAE4, D_L01_001DDAF0, 0.05f);
    func_L01_0040AAC8(q, 71, 72, 0x4F20207F, 0, D_L01_001DDAF8, 1.0f, 1.4f, D_L01_001DDAE8, D_L01_001DDAF4, 0.1f);
    s = D_L01_001DDAF8 * 1.4f;
    r = func_00382538();
    func_003D9508(q, 11, 0x3FFF2040, 1, s, 0.01f, r);
}
/* localdecomp:end func_L01_003770A8 */
