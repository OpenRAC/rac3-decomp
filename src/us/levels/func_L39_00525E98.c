#include "common.h"

/* NTSC-U counterpart of func_L39_00526340 (src/levels/shared/L39_00524E00.c) */
extern u8 *func_0037E0B8(void *);
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00525030;
typedef struct R_00525030 { u8 pad0[0x10]; void *p10; } R_00525030;
typedef struct M_00525030 {
    u8 pad0[0x10];
    V_00525030 pos;
    u8 pad20[4];
    R_00525030 *p24;
    u8 pad28[0x70];
    void *p98;
    u8 pad9C[0xE];
    s16 hAA;
    u8 padAC[0x14];
    V_00525030 vC0;
    u8 padD0[0x10];
    V_00525030 vE0;
    u8 padF0[8];
    f32 fF8;
} M_00525030;
typedef struct C_00525030 { u8 pad0[0x18]; M_00525030 *hit; u8 pad1C[4]; V_00525030 pos; } C_00525030;
extern void func_003886E8(void *, void *, f32);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern u8 *func_0037E0B8(void *);
extern f32 func_00388730(void *, void *);
extern f32 func_00388770(void *);
extern void func_0037E4B8(void *, f32, f32, f32);
extern C_00525030 D_L39_0025F840;
extern V_00525030 D_L39_0025F860;
#include "vu0.h"
extern void func_003888F0(void *, void *, void *);
extern void func_003886E8(void *, void *, f32);
extern u8 *func_0037E0B8(void *);
extern void func_L39_00525E98(void *);
#include "vu0.h"
typedef struct {
    vu0_v4 pos[12];
} T_00526280;
extern T_00526280 D_L39_003B5240[];
extern void func_003886E8(void *, void *, f32);

/* localdecomp:start func_L39_00525E98 */
#include "vu0.h"
typedef vu0_v4 V_00526340;
typedef struct G_00526340 {
    u8 pad0[0x250];
    V_00526340 v250;
    u8 pad260[0x2524 - 0x260];
    M_00525030 *p2524;
    u8 pad2528[0x2544 - 0x2528];
    s32 i2544;
} G_00526340;
typedef struct T_00526340 {
    V_00526340 pos;
    M_00525030 *target;
    u8 pad14[0x30 - 0x14];
    f32 f30;
    f32 f34;
    u8 pad38[0x48 - 0x38];
    f32 f48;
    f32 f4C;
    u8 pad50[4];
    G_00526340 *g;
} T_00526340;
typedef struct S_00526340 {
    u8 pad0[0x10];
    V_00526340 pos;
    u8 pad20[0x68 - 0x20];
    T_00526340 *t;
    u8 pad6C[0xD0 - 0x6C];
    V_00526340 vD0;
} S_00526340;
typedef struct { s32 c[5]; } K_00526340;
extern f32 func_L01_00447C00(f32);
extern void func_00388830(void *, void *, f32);
extern void func_003886C0(void *, void *, void *, f32);
extern void func_00388758(void *, void *, void *);
extern void func_00389158(void *, void *, void *, f32);
extern void func_003888F0(void *, void *, void *);
extern void func_L39_005FD3A8(void *, void *);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern s32 func_L39_005BC958(void *, void *, f32);
extern void func_L39_00526B18(u8 *);
extern void func_L01_004026A0(void *, void *);
extern f32 func_L39_005B2510(f32, f32);
extern s32 func_L39_005B2498(s32);
extern f32 func_L39_005B2568(f32, f32);
extern u8 *func_L01_00467DA8(u8 *position, s32 life, f32 size, f32 start_size, s32 colour, s32 roll_kind,
                             s32 spin, void *velocity, f32 unk, s32 delay);
extern u8 *func_L01_0046AED8(void *, s32, f32, f32, s32, s32, s32, f32 *, s32);
extern V_00526340 D_L39_003B5840_00525E98[][12];
extern V_00526340 D_L39_003B5E40_00525E98[][12];
extern V_00526340 D_L39_003B6440[][12][20];
extern K_00526340 D_L39_0024AB18;
__asm__(".extern D_L39_00242AB0, 16");
extern u8 D_L39_00242AB0[] __attribute__((section(".sdata")));
extern u8 *D_L39_00296A9C __attribute__((section(".data")));
static __inline__ void qcopy_00526340(void *d, void *s) { *(vu0_q *)d = *(vu0_q *)s; }

/* from rac2-decomp's func_L00_003C6B98 */
void func_L39_00525E98(void *obj) {
    S_00526340 *self = obj;
    V_00526340 v0;
    V_00526340 v10;
    V_00526340 v20;
    V_00526340 v30;
    V_00526340 v40;
    M_00525030 *list[128];
    V_00526340 v250;
    V_00526340 v260;
    V_00526340 v270;
    union {
        V_00526340 m[4];
        struct {
            K_00526340 cols;
            V_00526340 axis;
            V_00526340 perp;
        } tr;
    } u;
    s32 col = 0;
    s32 num = 0;
    f32 r1;
    f32 ang;
    T_00526340 *t;
    G_00526340 *g;
    M_00525030 *hit = 0;
    u8 *r = 0;
    u8 *p = 0;
    s32 idx;
    s32 n;
    s32 i;
    s32 j = 0;
    s32 k = 0;
    s32 l = 0;
    s32 cnt = 0;
    s32 s = 0;
    f32 dist;
    f32 d;
    f32 len;
    f32 frac;
    f32 scale;
    f32 w;
    f32 a;
    f32 range;
    f32 step;

    t = self->t;
    g = t->g;
    idx = 0;
    if (g != 0) {
        idx = g->i2544;
    }
    v20.x = 0.0f;
    v20.w = 1.0f;
    func_L39_00525DD8((u8 *)self);
    t->f34 = func_L01_00447C00(t->f34 + 0.20071286f);
    func_00388830(&v0, &self->vD0, -t->f30);
    if (t->target != 0 && (r = func_0037E0B8(t->target)) != 0) {
        func_003886E8(&v40, &t->target->vE0, *(f32 *)(r + 0x10));
        vec_add_ab(&v30, &t->target->pos, &v40);
    } else {
        func_0037E4B8(&v30, 12.0f, t->f48, t->f4C);
        vec_add_ab(&v30, &v30, &t->pos);
    }
    n = 0;
    dist = 12.0f;
    i = 0;
    if (t->target == 0) {
        qcopy_00526340(&v40, &t->pos);
        for (; func_003CE740(&v40, &v30, 0x14, g->p2524, 0) != 0 && ++i < 7; ) {
            hit = D_L39_0025F840.hit;
            if (hit != 0 && (hit->hAA == 0x10AA || hit->hAA == 0x1080)) {
                list[n] = hit;
                n++;
                hit->p98 = 0;
                if (n < 0x80) {
                    qcopy_00526340(&v40, &D_L39_0025F840.pos);
                    continue;
                }
            }
            vec_sub_ab(&v250, &t->pos, &D_L39_0025F860);
            d = func_00388730(&g->p2524->vE0, &v250);
            func_003886E8(&v260, &g->p2524->vE0, d);
            vec_sub_ab(&v270, &v250, &v260);
            dist = func_00388770(&v270);
            break;
        }
        for (l = 0; l < n; l++) {
            list[l]->p98 = list[l]->p24->p10;
        }
    } else {
        vec_sub_ba(&v40, &t->pos, &t->target->pos);
        d = func_00388730(&g->p2524->vE0, &v40);
        func_003886E8(&v250, &g->p2524->vE0, d);
        vec_sub_ab(&v260, &v40, &v250);
        dist = func_00388770(&v260);
    }
    t->f30 = dist * 0.08333f;
    qcopy_00526340(&D_L39_003B5240[idx].pos[0], &t->pos);
    qcopy_00526340(&D_L39_003B5840_00525E98[idx][0], &t->pos);
    qcopy_00526340(&D_L39_003B5E40_00525E98[idx][0], &t->pos);
    for (j = 1; j < 12; j++) {
        func_L39_005FD3A8(&D_L39_003B5240[idx].pos[j], &D_L39_003B5240[idx].pos[j]);
        frac = (f32)j * 0.08333f;
        w = frac * (0.4f - 0.9f) + 0.9f;
        vec_sub_ab(&v10, &D_L39_003B5240[idx].pos[j], &D_L39_003B5240[idx].pos[j - 1]);
        if (j >= 7 && t->target != 0) {
            vec_sub_ab(&v40, &t->target->pos, &D_L39_003B5240[idx].pos[j]);
            func_00388830(&v40, &v40, t->f30);
            func_003886C0(&v0, &v0, &v40, 0.2f);
        }
        func_003886C0(&v40, &v10, &v0, w);
        len = func_00388770(&v40);
        if (len == 0.0f) {
            qcopy_00526340(&D_L39_003B5240[idx].pos[j], &D_L39_003B5240[idx].pos[j - 1]);
        } else {
            func_003886E8(&v40, &v40, t->f30 / len);
            vec_add_ba(&D_L39_003B5240[idx].pos[j], &D_L39_003B5240[idx].pos[j - 1], &v40);
        }
        vec_sub_ab(&v250, &D_L39_003B5240[idx].pos[j], &D_L39_003B5240[idx].pos[j - 1]);
        func_00388758(&v260, &v250, &g->v250);
        func_00388830(&v260, &v260, frac * 1.184f + 0.05f);
        for (k = 0; k < 20; k++) {
            func_00389158(&v270, &v260, &v250, (f32)k * 0.31415921f);
            vec_add_ba(&D_L39_003B6440[idx][j][k], &v270, &D_L39_003B5240[idx].pos[j]);
        }
        qcopy_00526340(&u.m[3], &D_L39_003B5240[idx].pos[j]);
        func_00388830(&u.m[0], &v250, 1.0f);
        func_00388830(&u.m[1], &v260, 1.0f);
        func_00388758(&u.m[2], &u.m[1], &u.m[0]);
        scale = frac * 0.49f + 0.01f;
        ang = func_L01_00447C00(t->f34 + (f32)j * 0.39968038f);
        v20.y = scale * func_00388978(ang);
        v20.z = scale * func_00388960(ang);
        func_003888F0(&D_L39_003B5840_00525E98[idx][j], &v20, u.m);
        v20.z = -v20.z;
        func_003888F0(&D_L39_003B5E40_00525E98[idx][j], &v20, u.m);
    }
    qcopy_00526340(&v40, &self->pos);
    v40.w = 32.0f;
    cnt = 2;
    if (func_L39_005BC958(&v40, &range, 64.0f) != -1) {
        if (!(range < 256.0f)) {
            if (range < 1024.0f) {
                cnt = 4;
            } else {
                cnt = 8;
            }
        }
    } else {
        cnt = 0x80;
    }
    if (cnt < 0x80) {
        func_L01_004026A0(func_L39_00526B18, self);
    }
    a = func_L39_005B2510(0.1f, 1.7f);
    s = func_L39_005B2498(2);
    if (s == 0) {
        s--;
    }
    if (func_L39_005B2498(cnt) == 0) {
        qcopy_00526340(&v250, &D_L39_003B5840_00525E98[idx][11]);
        p = func_L01_00467DA8((u8 *)&v250, 0x1E, a * 0.1f, a, 0x7F10107F, 0, s, D_L39_00242AB0, 0.003f, 1);
        if (p != 0) {
            p[2] = D_L39_00296A9C[7];
        }
        s = -s;
        p = func_L01_00467DA8((u8 *)&v250, 0x1E, a * 0.07f, a * 0.7f, 0x7F7F7F7F, 1, s, D_L39_00242AB0, 0.003f, 1);
        if (p != 0) {
            p[2] = D_L39_00296A9C[7];
        }
    }
    if (func_L39_005B2498(cnt) == 0) {
        qcopy_00526340(&v250, &D_L39_003B5E40_00525E98[idx][11]);
        p = func_L01_00467DA8((u8 *)&v250, 0x1E, a * 0.1f, a, 0x7F104FFF, 0, s, D_L39_00242AB0, 0.003f, 1);
        if (p != 0) {
            p[2] = D_L39_00296A9C[7];
        }
        s = -s;
        p = func_L01_00467DA8((u8 *)&v250, 0x1E, a * 0.07f, a * 0.7f, 0x7F7F7F7F, 1, s, D_L39_00242AB0, 0.003f, 1);
        if (p != 0) {
            p[2] = D_L39_00296A9C[7];
        }
    }
    vec_sub_ab(&v260, &D_L39_003B5240[idx].pos[1], &D_L39_003B5240[idx].pos[0]);
    step = 0.2f;
    func_00388830(&v260, &v260, step);
    if (func_L39_005B2498(cnt) == 0) {
        func_00388830(&v270, &self->vD0, -0.25f);
        vec_add_ba(&v250, &D_L39_003B5240[idx].pos[0], &v270);
        u.tr.cols = D_L39_0024AB18;
        col = u.tr.cols.c[func_L39_005B2498(5)];
        r1 = func_L39_005B2568(0.0f, 0.2617994f);
        func_00389158(&u.tr.axis, &v260, &g->v250, func_L39_005B2568(0.0f, 0.2617994f));
        func_00388758(&u.tr.perp, &v260, &g->v250);
        func_00389158(&u.tr.axis, &u.tr.axis, &u.tr.perp, r1);
        num = (s32)(dist * 1.2f / step);
        if (t->target != 0) {
            num *= 3;
        }
        p = func_L01_0046AED8(&v250, num, a * 0.1f, a, col, 0, s, (f32 *)&u.tr.axis, (s32)t->target);
        if (p != 0) {
            p[2] = D_L39_00296A9C[6];
        }
        p = func_L01_0046AED8(&v250, num, a * 0.07f, a * 0.7f, 0x7F7F7F7F, 1, -s, (f32 *)&u.tr.axis, (s32)t->target);
        if (p != 0) {
            p[2] = D_L39_00296A9C[6];
        }
    }
}
/* localdecomp:end func_L39_00525E98 */
