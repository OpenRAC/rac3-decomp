#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L20_003CE2D0 */
typedef struct {
    vu0_v4 v[4];
    u32 col[4];
    f32 uv[4][2];
    unsigned long u70;
    unsigned long u78;
    unsigned long u80;
    unsigned long gif;
} Q_003CE2D0;
extern f32 D_L20_001E2E80[];
__asm__(".extern D_L20_001E2E80, 16");
extern vu0_v4 D_001A4EC0;
extern vu0_v4 D_L20_001D7C50[4];
extern s32 D_L20_001DEB00;
__asm__(".extern D_L20_001DEB00, 4");
extern void func_003D93B0(void *, s32, s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D028(void *, void *, void *);
extern void func_003A9440(s32, unsigned long);
extern void func_003D2DA0(void *, s32, s32);
extern void func_00389478(void *, f32 *, f32 *);

/* Adapted from the repository's matched func_L20_003E6150 family member. */
void func_L20_003CE2D0(u8 *a0, f32 size) {
    Q_003CE2D0 q;
    vu0_v4 d;
    vu0_v4 e;
    vu0_v4 f;
    vu0_v4 p;
    vu0_v4 z;
    vu0_v4 c[3];
    s32 i;
    s32 j;

    func_003D93B0(&q, D_L20_001DEB00, 1, 0x80);
    q.gif = (0x8000L << 24) | 0x4A;
    p = *(vu0_v4 *)(a0 + 0x10);
    q.col[3] = 0x80808080;
    q.col[2] = 0x80808080;
    q.col[1] = 0x80808080;
    q.col[0] = 0x80808080;
    q.uv[0][0] = 0.0f;
    q.uv[0][1] = 0.0f;
    q.uv[1][0] = 0.0f;
    q.uv[1][1] = 1.0f;
    q.uv[2][0] = 1.0f;
    q.uv[2][1] = 0.0f;
    q.uv[3][0] = 1.0f;
    q.uv[3][1] = 1.0f;
    vec_sub_ab(&d, D_L20_001E2E80, &p);
    func_0038CF68(&d, &d, 1.0f);
    func_0038CE90(&e, &d, &D_001A4EC0);
    func_0038CF68(&e, &e, 1.0f);
    func_0038CE90(&f, &e, &d);
    func_0038CE20(&z, &d, 0.05f);
    vec_add_ab(&p, &p, &z);
    for (i = 0; i < 4; i++) {
        func_0038CE20(&q.v[i], &D_L20_001D7C50[i], size);
        func_0038D028(&q.v[i], &q.v[i], &d);
    }
    func_003A9440(0x47, 0x31001);
    func_003D2DA0(&q, 0, 0);
    for (j = 0; j < 4; j++) {
        func_00389478(&q.v[j], &q.uv[j][0], &q.uv[j][1]);
    }
    func_003D93B0(&q, -1, 1, 0x80);
    q.gif = (0x8000L << 22) | 0x54;
    func_003D2DA0(&q, 0, 0);
    func_003A9440(0x47, 0x5360B);
}
/* localdecomp:end func_L20_003CE2D0 */

/* localdecomp:start func_L20_003CE4F8 */
typedef struct {
    vu0_v4 p[32];
    vu0_v4 q[32];
    vu0_v4 grid[4][4];
    vu0_v4 gvel[4][4];
    f32 ang[3];
} Rope_003CE4F8;

typedef struct {
    u8 pad0[8];
    s32 total;
    u8 padC[0x22 - 0xC];
    s16 timer;
    s32 color;
    u8 idx[4];
    u8 pad2C[4];
    Rope_003CE4F8 r[2];
} V_003CE4F8;

typedef struct {
    u8 pad0[0x10];
    vu0_v4 pos;
    u8 pad20[0x68 - 0x20];
    void *pvar;
    u8 pad6C[0xF0 - 0x6C];
    f32 rot[3];
} M_003CE4F8;

extern s32 D_L20_001DEB70;
extern s32 D_L20_001DEB74;
extern f32 D_L20_001DEB48;
extern f32 D_L20_001DEB4C;
extern s32 D_L20_001DEB54;
extern s32 D_L20_001DEB58;
extern f32 D_L20_001DEB60;
extern s32 D_L20_001DEB68;
extern s32 D_L20_001DEB6C;
__asm__(".extern D_L20_001DEB70, 4");
__asm__(".extern D_L20_001DEB74, 4");
__asm__(".extern D_L20_001DEB48, 4");
__asm__(".extern D_L20_001DEB4C, 4");
__asm__(".extern D_L20_001DEB54, 4");
__asm__(".extern D_L20_001DEB58, 4");
__asm__(".extern D_L20_001DEB60, 4");
__asm__(".extern D_L20_001DEB68, 4");
__asm__(".extern D_L20_001DEB6C, 4");
extern f32 D_L20_001E2E00[];
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern void func_L01_00443B88(void *, f32, f32);
extern f32 func_0038CF38(f32 *, f32 *);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_00382538(void);
extern void func_0038D328(void *, void *);
extern s32 func_00382468(s32);
extern s32 func_L01_00463378(void *, void *, void *, s32, s32, s32, s32, s32, s32);

static __inline__ void copy_003CE4F8(vu0_v4 *d, vu0_v4 *s) {
    *d = *s;
}

void func_L20_003CE4F8(u8 *obj) {
    vu0_v4 a[32];
    vu0_v4 b[32];
    V_003CE4F8 *v;
    s32 r;
    f32 spread;

    ((M_003CE4F8 *)obj)->pos.w = 1.0f;
    v = ((M_003CE4F8 *)obj)->pvar;
    r = func_00382498((D_L20_001DEB70 * 5 + 2) / 6, (D_L20_001DEB74 * 5 + 2) / 6);
    v->timer = r;
    v->total = v->timer;
    spread = func_003824E0(4.0f, 5.0f);
    {
        s32 i;

        for (i = 0; i < 32; i++) {
            f32 f = (f32)i / 31.0f;

            f = (0.5f - f) * spread;
            if (i < 3 || i > 28) {
                qzero(&a[i]);
                qzero(&b[i]);
            } else {
                func_L01_00443B88(&a[i], 0.0f, D_L20_001DEB48);
                func_L01_00443B88(&b[i], 0.0f, D_L20_001DEB4C * 0.020000001f);
            }
            a[i].w = 1.0f;
            a[i].y += f;
        }
    }
    {
        s32 i;

        for (i = 0; i < 32; i++) {
            if (i == 0 || i == 31) {
                copy_003CE4F8(&v->r[0].p[i], &a[i]);
                copy_003CE4F8(&v->r[0].q[i], &b[i]);
            } else {
                vu0_v4 t;
                vec_add_ab(&t, &a[i - 1], &a[i]);
                vec_add_ab(&t, &t, &a[i + 1]);
                func_0038CE20(&v->r[0].p[i], &t, 0.333f);
                vec_add_ab(&t, &b[i - 1], &b[i]);
                vec_add_ab(&t, &t, &b[i + 1]);
                func_0038CE20(&v->r[0].q[i], &t, 0.333f);
            }
        }
    }
    {
        s32 i;

        for (i = 0; i < 32; i++) {
            if (i == 0 || i == 31) {
                copy_003CE4F8(&v->r[1].p[i], &a[i]);
                copy_003CE4F8(&v->r[1].q[i], &b[i]);
            } else {
                vu0_v4 t;
                vec_add_ab(&t, &a[i - 1], &a[i]);
                vec_add_ab(&t, &t, &a[i + 1]);
                func_0038CE20(&v->r[1].p[i], &t, 0.333f);
                vec_add_ab(&t, &b[i - 1], &b[i]);
                vec_add_ab(&t, &t, &b[i + 1]);
                func_0038CE20(&v->r[1].q[i], &t, 0.333f);
            }
        }
    }
    {
        s32 k = 0;

        while (k < 4) {
            vu0_v4 t0;
            s32 n;
            s32 j;

            func_L01_00443B88(&t0, D_L20_001DEB48, D_L20_001DEB48);
            n = (s32)func_003824E0((f32)k * 6.0f, (f32)(k + 1) * 6.0f) + 4;
            v->idx[k] = n;
            copy_003CE4F8(&v->r[0].grid[0][k], &v->r[0].p[n]);
            copy_003CE4F8(&v->r[0].gvel[0][k], &v->r[0].q[n]);
            for (j = 1; j < 4; j++) {
                vu0_v4 t1;
                func_L01_00443B88(&t1, 0.1f, 0.1f);
                func_L01_00443B88(&v->r[0].gvel[j][k], 0.0f, D_L20_001DEB4C * 0.020000001f);
                vec_add_ab(&v->r[0].grid[j][k], &v->r[0].grid[j - 1][k], &t0);
                vec_add_ab(&v->r[0].grid[j][k], &v->r[0].grid[j][k], &t1);
            }
            k++;
        }
    }
    {
        s32 k = 0;

        while (k < 4) {
            vu0_v4 t0;
            s32 n;
            s32 j;

            func_L01_00443B88(&t0, D_L20_001DEB48, D_L20_001DEB48);
            n = (s32)func_003824E0((f32)k * 6.0f, (f32)(k + 1) * 6.0f) + 4;
            v->idx[k] = n;
            copy_003CE4F8(&v->r[1].grid[0][k], &v->r[1].p[n]);
            copy_003CE4F8(&v->r[1].gvel[0][k], &v->r[1].q[n]);
            for (j = 1; j < 4; j++) {
                vu0_v4 t1;
                func_L01_00443B88(&t1, 0.1f, 0.1f);
                func_L01_00443B88(&v->r[1].gvel[j][k], 0.0f, D_L20_001DEB4C * 0.020000001f);
                vec_add_ab(&v->r[1].grid[j][k], &v->r[1].grid[j - 1][k], &t0);
                vec_add_ab(&v->r[1].grid[j][k], &v->r[1].grid[j][k], &t1);
            }
            k++;
        }
    }
    {
        f32 d = func_0038CF38((f32 *)(obj + 0x10), D_L20_001E2E00);

        if (d >= 4.0f) {
            vu0_v4 m[4];
            vu0_v4 out;
            vu0_v4 vel;

            v->r[0].ang[2] = ((M_003CE4F8 *)obj)->rot[2];
            v->r[0].ang[1] = ((M_003CE4F8 *)obj)->rot[1];
            v->r[0].ang[1] += func_L01_00443A18(0.0f, 30.0f) * 0.017453292f;
            v->r[0].ang[0] = func_00382538();
            func_0038D328(m, v->r[0].ang);
            copy_003CE4F8(&m[3], &((M_003CE4F8 *)obj)->pos);
            {
                s32 i;

                for (i = 0; i < 32; i += 8) {
                    s32 c;

                    func_0038D028(&out, &v->r[0].p[i], m);
                    copy_003CE4F8(&vel, &v->r[0].q[i]);
                    vel.w = D_L20_001DEB60;
                    c = func_00382468(2) ? D_L20_001DEB68 : D_L20_001DEB6C;
                    func_L01_00463378(&out, &vel, &vel, D_L20_001DEB54, D_L20_001DEB58, i >> 1, 0xF,
                        ((func_00382468(10) + 20) * 5 + 2) / 6, c);
                }
            }
            {
                s32 i;

                for (i = 0; i < 2; i++) {
                    s32 c;

                    func_0038D028(&out, &v->r[0].grid[3][i], m);
                    copy_003CE4F8(&vel, &v->r[0].gvel[3][i]);
                    vel.w = D_L20_001DEB60;
                    c = func_00382468(2) ? D_L20_001DEB68 : D_L20_001DEB6C;
                    func_L01_00463378(&out, &vel, &vel, D_L20_001DEB54, D_L20_001DEB58, v->idx[i] >> 1, 0xF,
                        ((func_00382468(10) + 20) * 5 + 2) / 6, D_L20_001DEB6C);
                }
            }
        }
    }
    {
        f32 d = func_0038CF38((f32 *)(obj + 0x10), D_L20_001E2E00);

        if (d >= 4.0f) {
            vu0_v4 m[4];
            vu0_v4 out;
            vu0_v4 vel;

            v->r[1].ang[2] = ((M_003CE4F8 *)obj)->rot[2];
            v->r[1].ang[1] = ((M_003CE4F8 *)obj)->rot[1];
            v->r[1].ang[1] += func_L01_00443A18(0.0f, 30.0f) * 0.017453292f;
            v->r[1].ang[0] = func_00382538();
            func_0038D328(m, v->r[1].ang);
            copy_003CE4F8(&m[3], &((M_003CE4F8 *)obj)->pos);
            {
                s32 i;

                for (i = 0; i < 32; i += 8) {
                    s32 c;

                    func_0038D028(&out, &v->r[1].p[i], m);
                    copy_003CE4F8(&vel, &v->r[1].q[i]);
                    vel.w = D_L20_001DEB60;
                    c = func_00382468(2) ? D_L20_001DEB68 : D_L20_001DEB6C;
                    func_L01_00463378(&out, &vel, &vel, D_L20_001DEB54, D_L20_001DEB58, i >> 1, 0xF,
                        ((func_00382468(10) + 20) * 5 + 2) / 6, c);
                }
            }
            {
                s32 i;

                for (i = 0; i < 2; i++) {
                    s32 c;

                    func_0038D028(&out, &v->r[1].grid[3][i], m);
                    copy_003CE4F8(&vel, &v->r[1].gvel[3][i]);
                    vel.w = D_L20_001DEB60;
                    c = func_00382468(2) ? D_L20_001DEB68 : D_L20_001DEB6C;
                    func_L01_00463378(&out, &vel, &vel, D_L20_001DEB54, D_L20_001DEB58, v->idx[i] >> 1, 0xF,
                        ((func_00382468(10) + 20) * 5 + 2) / 6, D_L20_001DEB6C);
                }
            }
        }
    }
}
/* localdecomp:end func_L20_003CE4F8 */

/* localdecomp:start func_L20_003CEEB0 */
typedef struct {
    u8 pad0[8];
    s32 total;
    u8 padC[0x22-0xC];
    s16 timer;
    s32 color;
    u8 idx[4];
    u8 pad2C[4];
    vu0_v4 src[4];
    vu0_v4 pos[32];
    vu0_v4 vel[28];
    vu0_v4 grid[4][4];
    vu0_v4 gvel[4][4];
    u8 pad630[0x10];
    vu0_v4 src2[4];
    vu0_v4 pos2[32];
    vu0_v4 vel2[28];
    vu0_v4 grid2[4][4];
    vu0_v4 gvel2[4][4];
} V_003CEEB0;

extern s32 D_L20_001DEB78;
extern s32 D_L20_001DEB7C;
extern s32 D_L20_001DEB1C;
extern s32 D_L20_001DEB20;
extern s32 D_L20_001DEB24;
__asm__(".extern D_L20_001DEB78, 4");
__asm__(".extern D_L20_001DEB7C, 4");
__asm__(".extern D_L20_001DEB1C, 4");
__asm__(".extern D_L20_001DEB20, 4");
__asm__(".extern D_L20_001DEB24, 4");
extern s32 func_0038DBD8(s32, s32, f32);

void func_L20_003CEEB0(u8 *self) {
    V_003CEEB0 *v = *(V_003CEEB0 **)(self + 0x68);
    s32 i;
    s32 k;
    s32 j;
    s32 j2;

    if (v->timer != 0) {
        v->timer--;
        for (i = 0; i < 23; i++) {
            vec_add_ab(&v->pos[i], &v->pos[i], &v->vel[i]);
        }
        for (i = 0; (f32)i < 4.0f; i++) {
            for (k = 1; k < 4; k++) {
                vec_add_ab(&v->grid[k][i], &v->grid[k][i], &v->gvel[k][i]);
            }
        }
        for (j = 0; j < 4; j++) {
            *(vu0_q *)&v->grid[0][j] = *(vu0_q *)&v->src[v->idx[j]];
        }
    }
    if (D_L20_001DEB78 < v->timer) {
        v->color = func_0038DBD8(D_L20_001DEB20, D_L20_001DEB1C,
            (f32)(v->timer - D_L20_001DEB78) / (f32)(v->total - D_L20_001DEB78));
    } else if (D_L20_001DEB7C < v->timer) {
        v->color = func_0038DBD8(D_L20_001DEB24, D_L20_001DEB20,
            (f32)(v->timer - D_L20_001DEB7C) / (f32)(D_L20_001DEB78 - D_L20_001DEB7C));
    } else {
        v->color = 0;
    }
    if (v->timer != 0) {
        v->timer--;
        for (i = 0; i < 23; i++) {
            vec_add_ab(&v->pos2[i], &v->pos2[i], &v->vel2[i]);
        }
        for (i = 0; (f32)i < 4.0f; i++) {
            for (k = 1; k < 4; k++) {
                vec_add_ab(&v->grid2[k][i], &v->grid2[k][i], &v->gvel2[k][i]);
            }
        }
        for (j2 = 0; j2 < 4; j2++) {
            *(vu0_q *)&v->grid2[0][j2] = *(vu0_q *)&v->src2[v->idx[j2]];
        }
    }
}
/* localdecomp:end func_L20_003CEEB0 */
