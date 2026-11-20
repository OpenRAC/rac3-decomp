#include "common.h"

/* declared by functions of L39_00550D48.c, which this file was cut from */
extern s32 func_L39_00551918(u8 *);

/* declared by functions of L39_00551918.c, which this file was cut from */
extern u8 D_L39_003C13E0[];

/* localdecomp:start func_L39_00551A38 */
#include "vu0.h"

typedef struct {
    f32 v[4][4];
    u32 color[4];
    f32 uv[8];
    u8 pad[0x20];
} Quad_00551A38;

extern u8 D_L39_003C13E0[];
extern u8 D_L39_004997E0[];
extern void func_003D93B0(void *, s32, s32, s32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_003D2DA0(void *, void *, s32);

typedef struct Pt_00551A38 {
    vu0_v4 pos;
    u8 pad10[0x20];
} Pt_00551A38;

typedef union Buf_00551A38 {
    u8 b[8];
    u32 w[2];
    vu0_v4 v;
} Buf_00551A38;

void func_L39_00551A38(u8 *a0) {
    Quad_00551A38 q0;
    Quad_00551A38 q1;
    u8 *st = *(u8 **)(a0 + 0x68);
    Pt_00551A38 *base;
    f32 scale;
    s32 c0, c1, c2, c3;
    s32 alpha;
    s32 i;
    f32 t;
    f32 inv;
    Buf_00551A38 cr;
    vu0_v4 perp, va, vb;

    if (*(s16 *)(st + 0x30) < 2 || *(s16 *)(st + 0x32) == 0) {
        return;
    }
    base = (Pt_00551A38 *)(D_L39_003C13E0 + st[0x3A] * 0x12C0);
    func_003D93B0(&q0, 0xE, 1, 0x80);
    q0.uv[0] = 0.0f;
    q0.uv[2] = 0.0f;
    q0.uv[4] = 1.0f;
    q0.uv[6] = 1.0f;
    q0.uv[1] = 0.0f;
    q0.uv[3] = 1.0f;
    q0.uv[5] = 0.0f;
    q0.uv[7] = 1.0f;
    q0.uv[0] = q0.uv[2] = *(f32 *)(st + 0x48) + q0.uv[0];
    q0.uv[4] = q0.uv[6] = *(f32 *)(st + 0x48) + q0.uv[4];
    func_003D93B0(&q1, 0xE, 1, 0x80);
    q1.uv[0] = 0.0f;
    q1.uv[2] = 0.0f;
    q1.uv[4] = 1.0f;
    q1.uv[6] = 1.0f;
    q1.uv[1] = 0.0f;
    q1.uv[3] = 1.0f;
    q1.uv[5] = 0.0f;
    q1.uv[7] = 1.0f;
    q1.uv[0] = q1.uv[2] = *(f32 *)(st + 0x48) + q1.uv[0];
    q1.uv[4] = q1.uv[6] = *(f32 *)(st + 0x48) + q1.uv[4];
    scale = (f32)*(s16 *)(st + 0x32) * *(f32 *)(st + 0x34);
    if ((*(u8 **)(st + 0x3C))[0x1A14] != 0) {
        u8 *q = *(u8 **)(st + 0x3C) + 0x19E4;
        u32 a;
        u32 r;
        if (*q == 0) {
            r = 0;
        } else {
            s32 n = *q;
            s32 k = ((u32)q - n) & 7;
            s32 m = n + 1;
            s32 j;
            u8 *d = cr.b;
            for (j = 0; j < 40; j += 5) {
                *d++ = D_L39_004997E0[m + ((k + j) & 7) * 255];
            }
            a = cr.w[0] ^ (u32)q;
            cr.w[0] = a;
            cr.w[1] ^= a;
            r = cr.w[1];
        }
        if ((r ^ 0x1D) == 0 || *(s32 *)(*(u8 **)(st + 0x3C) + 0x1310) != 0) {
            scale *= 0.5f;
        }
    }
    alpha = scale * 0.0f;
    c0 = (alpha << 24) | 0x804000;
    alpha = scale * 255.0f;
    c1 = (alpha << 24) | 0xFFFF00;
    alpha = scale * 0.0f;
    c2 = (alpha << 24) | 0xFF1010;
    alpha = scale * 128.0f;
    c3 = (alpha << 24) | 0x404000;
    q0.color[1] = c0;
    q0.color[0] = c0;
    q1.color[1] = c2;
    q1.color[0] = c2;

    vec_sub_ab(&va, &base[0], *(u8 **)(st + 0x3C) + 0x23A0);
    vec_sub_ab(&vb, &base[1], &base[0]);
    func_0038CE90(&cr.v, &vb, &va);
    func_0038CF68(&perp, &cr.v, base[0].pos.w);
    vec_add_ba(q0.v[0], &base[0], &perp);
    vec_sub_ab(q0.v[1], &base[0], &perp);
    func_0038CE20(&perp, &perp, 3.0f);
    vec_add_ba(q1.v[0], &base[0], &perp);
    vec_sub_ab(q1.v[1], &base[0], &perp);
    inv = 1.0f / (f32)*(s16 *)(st + 0x30);
    for (i = 1; i < *(s16 *)(st + 0x30); i++) {
        vec_sub_ab(&va, &base[i], *(u8 **)(st + 0x3C) + 0x23A0);
        vec_sub_ab(&vb, &base[i], &base[i - 1]);
        func_0038CE90(&cr.v, &vb, &va);
        func_0038CF68(&perp, &cr.v, base[i].pos.w);
        vec_add_ba(q0.v[2], &base[i], &perp);
        vec_sub_ab(q0.v[3], &base[i], &perp);
        func_0038CE20(&perp, &perp, 3.0f);
        t = (f32)i * inv;
        vec_add_ba(q1.v[2], &base[i], &perp);
        vec_sub_ab(q1.v[3], &base[i], &perp);
        q0.color[2] = q0.color[3] = func_0038DBD8(c0, c1, t);
        q1.color[2] = q1.color[3] = func_0038DBD8(c2, c3, t);
        func_003D2DA0(&q0, 0, 0);
        func_003D2DA0(&q1, 0, 0);
        *(vu0_q *)q0.v[0] = *(vu0_q *)q0.v[2];
        *(vu0_q *)q0.v[1] = *(vu0_q *)q0.v[3];
        *(vu0_q *)q1.v[0] = *(vu0_q *)q1.v[2];
        *(vu0_q *)q1.v[1] = *(vu0_q *)q1.v[3];
        q0.color[0] = q0.color[1] = q0.color[2];
        q1.color[0] = q1.color[1] = q1.color[2];
    }
}
/* localdecomp:end func_L39_00551A38 */
