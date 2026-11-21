#include "common.h"

/* NTSC-U counterpart of func_L20_003F2918 (src/levels/20_final_boss/L20_003F1A78.c) */
#include "vu0.h"
#include "vu0.h"
extern s32 func_0037E1D8(s32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E208(s32, s32);
extern f32 func_L01_00440918(f32, f32);
extern s32 func_0037E1D8(s32);
extern vu0_v4 D_L20_001E2E00_003F0878;
extern void func_L01_00440A88(void *, f32, f32);

/* localdecomp:start func_L20_003F0878 */
/* from func_L20_003CE4F8 (same level) */
typedef struct {
    vu0_v4 p[32];
    vu0_v4 q[32];
    vu0_v4 grid[4][4];
    vu0_v4 gvel[4][4];
    f32 ang[3];
} Rope_003F2918;

typedef struct {
    u8 pad0[0x28];
    s32 total;
    u8 pad2C[0x42 - 0x2C];
    s16 timer;
    u8 pad44[4];
    u8 idx[4];
    u8 pad4C[4];
    Rope_003F2918 r[2];
} V_003F2918;

typedef struct {
    u8 pad0[0x10];
    vu0_v4 pos;
    u8 pad20[0x68 - 0x20];
    void *pvar;
    u8 pad6C[0xF0 - 0x6C];
    f32 rot[3];
} M_003F2918;

extern s32 D_L20_001DF438_003F0878;
extern s32 D_L20_001DF43C_003F0878;
extern f32 D_L20_001DF410_003F0878;
extern f32 D_L20_001DF414_003F0878;
extern s32 D_L20_001DF41C_003F0878;
extern s32 D_L20_001DF420_003F0878;
extern f32 D_L20_001DF428_003F0878;
extern s32 D_L20_001DF430_003F0878;
extern s32 D_L20_001DF434_003F0878;
__asm__(".extern D_L20_001DF438_003F0878, 4");
__asm__(".extern D_L20_001DF43C_003F0878, 4");
__asm__(".extern D_L20_001DF410_003F0878, 4");
__asm__(".extern D_L20_001DF414_003F0878, 4");
__asm__(".extern D_L20_001DF41C_003F0878, 4");
__asm__(".extern D_L20_001DF420_003F0878, 4");
__asm__(".extern D_L20_001DF428_003F0878, 4");
__asm__(".extern D_L20_001DF430_003F0878, 4");
__asm__(".extern D_L20_001DF434_003F0878, 4");
extern s32 func_0037E208(s32, s32);
extern f32 func_0037E250(f32, f32);
extern f32 func_00388800(void *, void *);
extern void func_003886E8(void *, void *, f32);
extern void func_003888F0(void *, void *, void *);
extern f32 func_L01_00440918(f32, f32);
extern f32 func_0037E2A8(void);
extern void func_00388BF0(void *, void *);
extern s32 func_0037E1D8(s32);
extern s32 func_L01_0045FEC8(void *, void *, void *, s32, s32, s32, s32, s32, s32);

static __inline__ void copy_003F2918(vu0_v4 *d, vu0_v4 *s) {
    *d = *s;
}

void func_L20_003F0878(void *arg) {
    u8 *obj = arg;
    vu0_v4 a[32];
    vu0_v4 b[32];
    V_003F2918 *v;
    s32 r;
    f32 spread;

    ((M_003F2918 *)obj)->pos.w = 1.0f;
    v = ((M_003F2918 *)obj)->pvar;
    r = func_0037E208(D_L20_001DF438_003F0878, D_L20_001DF43C_003F0878);
    v->timer = r;
    v->total = v->timer;
    spread = func_0037E250(4.0f, 5.0f);
    {
        s32 i;

        for (i = 0; i < 32; i++) {
            f32 f = (f32)i / 31.0f;

            f = (0.5f - f) * spread;
            if (i < 3 || i > 28) {
                qzero(&a[i]);
                qzero(&b[i]);
            } else {
                func_L01_00440A88(&a[i], 0.0f, D_L20_001DF410_003F0878);
                func_L01_00440A88(&b[i], 0.0f, D_L20_001DF414_003F0878 * 0.016666668f);
            }
            a[i].w = 1.0f;
            a[i].y += f;
        }
    }
    {
        s32 i;

        for (i = 0; i < 32; i++) {
            if (i == 0 || i == 31) {
                copy_003F2918(&v->r[0].p[i], &a[i]);
                copy_003F2918(&v->r[0].q[i], &b[i]);
            } else {
                vu0_v4 t;
                vec_add_ab(&t, &a[i - 1], &a[i]);
                vec_add_ab(&t, &t, &a[i + 1]);
                func_003886E8(&v->r[0].p[i], &t, 0.333f);
                vec_add_ab(&t, &b[i - 1], &b[i]);
                vec_add_ab(&t, &t, &b[i + 1]);
                func_003886E8(&v->r[0].q[i], &t, 0.333f);
            }
        }
    }
    {
        s32 i;

        for (i = 0; i < 32; i++) {
            if (i == 0 || i == 31) {
                copy_003F2918(&v->r[1].p[i], &a[i]);
                copy_003F2918(&v->r[1].q[i], &b[i]);
            } else {
                vu0_v4 t;
                vec_add_ab(&t, &a[i - 1], &a[i]);
                vec_add_ab(&t, &t, &a[i + 1]);
                func_003886E8(&v->r[1].p[i], &t, 0.333f);
                vec_add_ab(&t, &b[i - 1], &b[i]);
                vec_add_ab(&t, &t, &b[i + 1]);
                func_003886E8(&v->r[1].q[i], &t, 0.333f);
            }
        }
    }
    {
        s32 k = 0;

        while (k < 4) {
            vu0_v4 t0;
            s32 n;
            s32 j;

            func_L01_00440A88(&t0, D_L20_001DF410_003F0878, D_L20_001DF410_003F0878);
            n = (s32)func_0037E250((f32)k * 6.0f, (f32)(k + 1) * 6.0f) + 4;
            v->idx[k] = n;
            copy_003F2918(&v->r[0].grid[0][k], &v->r[0].p[n]);
            copy_003F2918(&v->r[0].gvel[0][k], &v->r[0].q[n]);
            for (j = 1; j < 4; j++) {
                vu0_v4 t1;
                func_L01_00440A88(&t1, 0.1f, 0.1f);
                func_L01_00440A88(&v->r[0].gvel[j][k], 0.0f, D_L20_001DF414_003F0878 * 0.016666668f);
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

            func_L01_00440A88(&t0, D_L20_001DF410_003F0878, D_L20_001DF410_003F0878);
            n = (s32)func_0037E250((f32)k * 6.0f, (f32)(k + 1) * 6.0f) + 4;
            v->idx[k] = n;
            copy_003F2918(&v->r[1].grid[0][k], &v->r[1].p[n]);
            copy_003F2918(&v->r[1].gvel[0][k], &v->r[1].q[n]);
            for (j = 1; j < 4; j++) {
                vu0_v4 t1;
                func_L01_00440A88(&t1, 0.1f, 0.1f);
                func_L01_00440A88(&v->r[1].gvel[j][k], 0.0f, D_L20_001DF414_003F0878 * 0.016666668f);
                vec_add_ab(&v->r[1].grid[j][k], &v->r[1].grid[j - 1][k], &t0);
                vec_add_ab(&v->r[1].grid[j][k], &v->r[1].grid[j][k], &t1);
            }
            k++;
        }
    }
    {
        f32 d = func_00388800(obj + 0x10, &D_L20_001E2E00_003F0878);

        if (d >= 4.0f) {
            vu0_v4 m[4];
            vu0_v4 out;
            vu0_v4 vel;

            v->r[0].ang[2] = ((M_003F2918 *)obj)->rot[2];
            v->r[0].ang[1] = ((M_003F2918 *)obj)->rot[1];
            v->r[0].ang[1] += func_L01_00440918(0.0f, 30.0f) * 0.017453292f;
            v->r[0].ang[0] = func_0037E2A8();
            func_00388BF0(m, v->r[0].ang);
            copy_003F2918(&m[3], &((M_003F2918 *)obj)->pos);
            {
                s32 i;

                for (i = 0; i < 32; i += 8) {
                    s32 c;

                    func_003888F0(&out, &v->r[0].p[i], m);
                    copy_003F2918(&vel, &v->r[0].q[i]);
                    vel.w = D_L20_001DF428_003F0878;
                    c = func_0037E1D8(2) ? D_L20_001DF430_003F0878 : D_L20_001DF434_003F0878;
                    func_L01_0045FEC8(&out, &vel, &vel, D_L20_001DF41C_003F0878, D_L20_001DF420_003F0878, i >> 1, 0xF,
                        (func_0037E1D8(10) + 20), c);
                }
            }
            {
                s32 i;

                for (i = 0; i < 2; i++) {
                    s32 c;

                    func_003888F0(&out, &v->r[0].grid[3][i], m);
                    copy_003F2918(&vel, &v->r[0].gvel[3][i]);
                    vel.w = D_L20_001DF428_003F0878;
                    c = func_0037E1D8(2) ? D_L20_001DF430_003F0878 : D_L20_001DF434_003F0878;
                    func_L01_0045FEC8(&out, &vel, &vel, D_L20_001DF41C_003F0878, D_L20_001DF420_003F0878, v->idx[i] >> 1, 0xF,
                        (func_0037E1D8(10) + 20), D_L20_001DF434_003F0878);
                }
            }
        }
    }
    {
        f32 d = func_00388800(obj + 0x10, &D_L20_001E2E00_003F0878);

        if (d >= 4.0f) {
            vu0_v4 m[4];
            vu0_v4 out;
            vu0_v4 vel;

            v->r[1].ang[2] = ((M_003F2918 *)obj)->rot[2];
            v->r[1].ang[1] = ((M_003F2918 *)obj)->rot[1];
            v->r[1].ang[1] += func_L01_00440918(0.0f, 30.0f) * 0.017453292f;
            v->r[1].ang[0] = func_0037E2A8();
            func_00388BF0(m, v->r[1].ang);
            copy_003F2918(&m[3], &((M_003F2918 *)obj)->pos);
            {
                s32 i;

                for (i = 0; i < 32; i += 8) {
                    s32 c;

                    func_003888F0(&out, &v->r[1].p[i], m);
                    copy_003F2918(&vel, &v->r[1].q[i]);
                    vel.w = D_L20_001DF428_003F0878;
                    c = func_0037E1D8(2) ? D_L20_001DF430_003F0878 : D_L20_001DF434_003F0878;
                    func_L01_0045FEC8(&out, &vel, &vel, D_L20_001DF41C_003F0878, D_L20_001DF420_003F0878, i >> 1, 0xF,
                        (func_0037E1D8(10) + 20), c);
                }
            }
            {
                s32 i;

                for (i = 0; i < 2; i++) {
                    s32 c;

                    func_003888F0(&out, &v->r[1].grid[3][i], m);
                    copy_003F2918(&vel, &v->r[1].gvel[3][i]);
                    vel.w = D_L20_001DF428_003F0878;
                    c = func_0037E1D8(2) ? D_L20_001DF430_003F0878 : D_L20_001DF434_003F0878;
                    func_L01_0045FEC8(&out, &vel, &vel, D_L20_001DF41C_003F0878, D_L20_001DF420_003F0878, v->idx[i] >> 1, 0xF,
                        (func_0037E1D8(10) + 20), D_L20_001DF434_003F0878);
                }
            }
        }
    }
}
/* localdecomp:end func_L20_003F0878 */
