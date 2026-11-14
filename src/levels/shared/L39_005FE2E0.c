#include "common.h"

LINKER_REMNANT("asm/levels", func_L39_005FE2E0);

/* localdecomp:start func_L39_005FE358 */
#include "vu0.h"
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    f32 v[4][4];
    s32 col[4];
    f32 q[8];
    long z70;
    long r78;
    long c80;
    long c88;
} S_005FE358;

extern s32 D_L39_00241128;
__asm__(".extern D_L39_00241128, 16");
extern s32 D_L39_0024112C;
__asm__(".extern D_L39_0024112C, 16");
extern s32 D_001D9928_sda[2];
__asm__(".extern D_001D9928_sda, 8");
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DB48(f32);
extern void func_0038D328(void *, void *);
extern void func_0038D640(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_003D2DA0(void *, void *, s32);
extern long func_L39_00589890(s32);

void func_L39_005FE358(u8 *a0, u8 *a1, void *a2, s32 a3, f32 scale) {
    S_005FE358 s;
    u128_t m1[4];
    u128_t m2[4];
    f32 e1[4];
    f32 e2[4];
    s32 i;
    s32 j;
    u8 b;
    f32 len;
    f32 r;

    if (D_L39_00241128 == 2) {
        return;
    }
    for (i = 0; i < 2; i++) {
        len = sqrt_asm(((f32 *)a1)[0] * ((f32 *)a1)[0] + ((f32 *)a1)[2] * ((f32 *)a1)[2]);
        e1[0] = func_0038DAB8(-func_0038D160(len, ((f32 *)a1)[1]), 1.5707964f);
        e1[1] = func_0038D160(((f32 *)a1)[2], ((f32 *)a1)[0]);
        e1[2] = 0.0f;
        e1[3] = 0.0f;
        r = (f32)(D_L39_0024112C % 150) * 6.2831855f / 150.33333f;
        e2[0] = 0.0f;
        r = func_0038DB48(r);
        b = i & 1;
        if (b) {
            r = -r;
        }
        e2[1] = r;
        e2[2] = 0.0f;
        e2[3] = 0.0f;
        func_0038D328(m2, e2);
        func_0038D328(m1, e1);
        func_0038D640(m1, m1, m2);
        m1[3] = *(u128_t *)a0;
        if (a2 == 0) {
            for (j = 0; j < 4; j++) {
                s.col[j] = D_001D9928_sda[i];
            }
        } else {
            for (j = 0; j < 4; j++) {
                s.col[j] = ((s32 *)a2)[i];
            }
        }
        if (a3) {
            s.r78 = func_L39_00589890((i & 1) ? 0x57 : 0x58);
        } else {
            s.r78 = func_L39_00589890((i & 1) ? 0x12 : 0x11);
        }
        s.c80 = 0xFF9000000260L;
        s.c88 = 0x8000000044L;
        s.z70 = 0;
        s.v[0][0] = -1.0f; s.v[0][1] = 0.0f; s.v[0][2] = 1.0f; s.v[0][3] = 1.0f;
        s.v[1][0] = 1.0f; s.v[1][1] = 0.0f; s.v[1][2] = 1.0f; s.v[1][3] = 1.0f;
        s.v[2][0] = -1.0f; s.v[2][1] = 0.0f; s.v[2][2] = -1.0f; s.v[2][3] = 1.0f;
        s.v[3][0] = 1.0f; s.v[3][1] = 0.0f; s.v[3][2] = -1.0f; s.v[3][3] = 1.0f;
        func_0038CE20(s.v[0], s.v[0], scale);
        func_0038CE20(s.v[1], s.v[1], scale);
        func_0038CE20(s.v[2], s.v[2], scale);
        func_0038CE20(s.v[3], s.v[3], scale);
        s.q[0] = 0.0f; s.q[1] = 1.0f; s.q[2] = 1.0f; s.q[3] = 1.0f;
        s.q[4] = 0.0f; s.q[5] = 0.0f; s.q[6] = 1.0f; s.q[7] = 0.0f;
        func_003D2DA0(&s, m1, 1);
    }
}
/* localdecomp:end func_L39_005FE358 */

/* localdecomp:start func_L39_005FE6A0 */
#include "vu0.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_005FE6A0;
typedef struct { V_005FE6A0 pos; V_005FE6A0 r[3]; } M_005FE6A0;

typedef struct {
    u8 pad0[0x10];
    V_005FE6A0 pos;
    u8 pad20[0xE0 - 0x20];
    V_005FE6A0 vE0;
} Moby_005FE6A0;

typedef struct {
    u8 pad0[0x1A0];
    s32 x1A0;
} P2534_005FE6A0;

typedef struct {
    u8 pad0[0x14];
    u8 *vt;
    u8 pad18[0x20 - 0x18];
    V_005FE6A0 m20[4];
    u8 pad60[0x2D8 - 0x60];
    s16 h2D8;
    u8 pad2DA[0x380 - 0x2DA];
    V_005FE6A0 r[3];
    u8 pad3B0[0x19E4 - 0x3B0];
    u8 b19E4;
    u8 pad19E5[0x1A0C - 0x19E5];
    u8 b1A0C;
    u8 pad1A0D[0x23A0 - 0x1A0D];
    V_005FE6A0 v23A0;
    u8 pad23B0[0x23C0 - 0x23B0];
    V_005FE6A0 v23C0;
    u8 pad23D0[0x2524 - 0x23D0];
    Moby_005FE6A0 *moby;
    u8 pad2528[0x2534 - 0x2528];
    P2534_005FE6A0 *x2534;
} G_005FE6A0;

typedef struct {
    u8 pad0[0x10];
    V_005FE6A0 pos;
    u8 pad20[0xC0 - 0x20];
    V_005FE6A0 r[3];
} Mat_005FE6A0;

extern u8 D_L39_004997E0[];
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D098(f32);
extern void func_0038D810(void *quat, void *matrix);
extern void func_0038D5F0(void *, void *, void *);
extern f32 func_0038CEA8(void *);
extern void func_0038D000(void *, void *, void *);
extern f32 func_L01_004451A8(f32 f12);
extern void func_L39_005BC330(void *, void *, s32);
extern s32 func_L39_005C42E8(s32, s32);

void func_L39_005FE6A0(G_005FE6A0 *g, V_005FE6A0 *out, V_005FE6A0 *target, Moby_005FE6A0 *o,
                       Mat_005FE6A0 *m, f32 lo, f32 hi, f32 dist, f32 k) {
    V_005FE6A0 v0;
    V_005FE6A0 v10;
    V_005FE6A0 dir;
    V_005FE6A0 v30;
    V_005FE6A0 v40;
    V_005FE6A0 v50;
    V_005FE6A0 v60;
    V_005FE6A0 v70;
    V_005FE6A0 v80;
    V_005FE6A0 v90;
    M_005FE6A0 mat;
    V_005FE6A0 quat;
    f32 len;
    f32 inv;
    f32 d;
    f32 h2;

    if (m != 0) {
        mat.pos = m->pos;
        mat.r[0] = m->r[0];
        mat.r[1] = m->r[1];
        mat.r[2] = m->r[2];
    } else {
        mat.pos = g->moby->pos;
        mat.r[0] = g->r[0];
        mat.r[1] = g->r[1];
        mat.r[2] = g->r[2];
    }
    out->x = 1.0f;
    out->y = 0.0f;
    out->z = 0.0f;
    out->w = 0.0f;
    if (g != 0 && g->h2D8 != 0) {
        func_0038CE20(&dir, &g->moby->vE0, -1.0f);
    } else {
        func_L39_005BC330(&mat, &dir, 0);
    }
    len = hi;
    if (o == 0) {
        {
        u8 *q;
        u32 x;
        long t;

        q = &g->b19E4;
        t = *q;
        if (t == 0) {
            x = 0;
        } else {
            u8 *b;
            s32 n, kk, mm, i;

            n = *q;
            kk = ((u32)q - n) & 7;
            mm = n + 1;
            b = (u8 *)&quat;
            for (i = 0; i < 40; i += 5) {
                *b++ = D_L39_004997E0[mm + ((kk + i) & 7) * 255];
            }
            ((u32 *)&quat)[0] ^= (u32)q;
            ((u32 *)&quat)[1] ^= ((u32 *)&quat)[0];
            x = ((u32 *)&quat)[1];
        }
        if ((x ^ 1) == 0) {
            (*(void (**)(void *, s32, s32, s32, s32))(g->vt + 0x34))(g, 0x1D, 0, 0, 1);
        }
        }
        if ((g->x2534->x1A0 & func_L39_005C42E8(4, 0)) && g->b1A0C == 0) {
            V_005FE6A0 axis;
            V_005FE6A0 up;
            V_005FE6A0 xf[3];
            V_005FE6A0 rot[3];
            V_005FE6A0 p;
            f32 h;
            f32 c;
            f32 nd;
            f32 t;

            func_0038CF68(&up, &g->v23C0, 1.0f);
            c = func_0038CE68(&up, &dir);
            if (c < -0.933f) {
                goto clamp;
            }
            func_0038CE20(&v10, &dir, c);
            vec_sub_ab(&v0, &up, &v10);
            func_0038CF68(&v0, &v0, 1.0f);
            func_0038CE90(&axis, &up, &v0);
            h = func_0038CE68(&up, &v0) * 0.5f;
            func_0038CE20(&quat, &axis, func_0038D0B0(h));
            quat.w = func_0038D098(h);
            func_0038D810(&quat, rot);
            func_0038D5F0(xf, rot, &g->v23C0);
            nd = -func_0038CE68(&mat.pos, &dir);
            func_0038CF68(&p, &g->v23C0, 1.0f);
            t = func_0038CE68(&dir, &p);
            if (0.0f < t) {
                func_0038CE20(&p, &p, (func_0038CE68(&dir, &g->v23A0) + nd) / t);
                vec_sub_ba(&p, &g->v23A0, &p);
                vec_sub_ba(&p, &p, &g->v23A0);
                func_0038CE20(&v10, &dir, func_0038CE68(&p, &dir));
                vec_sub_ab(&v0, &p, &v10);
                len = func_0038CEA8(&v0);
                if (hi < len) {
                    len = hi;
                } else if (len < lo) {
                    len = lo;
                }
            } else {
                len = hi;
            }
            len = hi * func_L01_004451A8(len / hi);
            func_0038D000(out, out, xf);
        } else {
            if (func_0038CE68(&mat.r[0], &dir) < -0.933f) {
            clamp:
                out->z = 0.90203f;
                out->x = sqrt_asm(1.0f - 0.90203f * 0.90203f);
                func_0038D000(out, out, g->m20);
            } else {
                func_0038D000(out, out, &mat.r[0]);
            }
        }
        func_0038CF68(out, out, len);
        vec_add_ba(&v30, out, &mat.pos);
    } else {
        v30 = o->pos;
    }
    vec_sub_ab(&v40, &v30, target);
    func_0038CE20(&v10, &dir, func_0038CE68(&v40, &dir));
    vec_sub_ba(&v0, &v40, &v10);
    func_0038CF68(out, &v0, dist);
    d = func_0038CEA8(&v0) / dist;
    inv = 1.0f / d;
    func_0038CE20(&v60, &dir, func_0038CE68(target, &dir));
    h2 = func_0038CE68(&v30, &dir);
    func_0038CE20(&v70, &dir, h2);
    func_0038CE20(&v80, &dir, k * (d * d) * 0.5f);
    vec_sub_ba(&v90, &v60, &v70);
    vec_add_ba(&v90, &v90, &v80);
    func_0038CE20(&v90, &v90, -1.0f);
    func_0038CE20(&v50, &v90, inv);
    vec_add_ab(out, out, &v50);
}
/* localdecomp:end func_L39_005FE6A0 */

INCLUDE_ASM("asm/levels", func_L39_005FED60);
