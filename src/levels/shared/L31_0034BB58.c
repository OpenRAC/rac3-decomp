#include "common.h"

typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1C;
    f32 f20;
    f32 f24;
} Vec_00349D18;
typedef struct {
    u8 pad[0x68];
    Vec_00349D18 *w68;
} Obj_00349D18;

extern f32 D_L31_001DD018;
extern float D_L31_001DD09C;
extern float D_L31_001DD0A0;
extern u8 D_L31_001D66B0[8];
extern void func_L30_0034CB68(s32, u8 *, s32, s32, s32, s32, float, float);

/* localdecomp:start func_L31_0034BB58 */
/* log:
 * v1: first draft, vu0.h helpers (j-form)
 */
#include "vu0.h"

__asm__(".extern D_L31_001DD218, 4");
__asm__(".extern D_L31_001DD224, 4");
__asm__(".extern D_L31_001DD220, 4");

extern f32 D_L31_001DD218;
extern f32 D_L31_001DD224;
extern f32 D_L31_001DD220;
extern f32 D_L31_001E12B4;
extern vu0_v4 D_L31_001E22A0;
extern void func_L31_0034BA10(void *, vu0_v4 *, f32);
extern f32 func_0038DB48(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);

void func_L31_0034BB58(void *m, vu0_v4 *out, f32 t) {
    vu0_v4 side;
    vu0_v4 mid;
    vu0_v4 ahead;
    vu0_v4 behind;
    vu0_v4 dir;
    f32 a;
    f32 b;
    f32 s;

    if (t > 1.0f) {
        t = 1.0f;
    } else if (t < 0.0f) {
        t = 0.0f;
    }
    a = t + D_L31_001DD218;
    if (a > 1.0f) {
        a = 1.0f;
    }
    b = t - D_L31_001DD218;
    if (b < 0.0f) {
        b = 0.0f;
    }
    func_L31_0034BA10(m, &ahead, a);
    func_L31_0034BA10(m, &mid, t);
    func_L31_0034BA10(m, &behind, b);
    s = D_L31_001DD220 * func_0038D0B0(func_0038DB48(D_L31_001E12B4 * 6.2831855f * D_L31_001DD224 * t));
    vec_sub_ba(&dir, &ahead, &behind);
    func_0038CE90(&side, &dir, &D_L31_001E22A0);
    func_0038CF68(&side, &side, s);
    vec_add_ab(out, &mid, &side);
}
/* localdecomp:end func_L31_0034BB58 */

INCLUDE_ASM("asm/levels", func_L31_0034BCA8);

/* localdecomp:start func_L31_0034BF90 */
#include "vu0.h"

typedef struct {
    f32 pos[4];
    u8 pad10[0x10];
    u8 state;
    u8 pad21[0x3];
    struct Cls_0034BF90 *cls;
    u8 pad28[0x4];
    f32 f2C;
    u8 pad30[0x13];
    u8 b43;
    u8 pad44[0x1C];
    u8 flags;
    u8 pad61[0x7];
    struct Vars_0034BF90 *vars;
    u8 pad6C[0x3C];
    u8 bA8;
    u8 padA9[0x17];
    u8 c0[0x30];
    u8 f0[0x10];
} Moby_0034BF90;

typedef struct Cls_0034BF90 {
    u8 pad0[0x24];
    f32 f24;
} Cls_0034BF90;

typedef struct {
    u8 pad0[0x20];
    Moby_0034BF90 *moby;
    u8 pad24[0x8];
    f32 f2C;
} Hit_0034BF90;

typedef struct {
    u8 pad0[0x20];
    u8 state;
    u8 pad21[0x89];
    s16 oClass;
} Other_0034BF90;

typedef struct Vars_0034BF90 {
    u8 pad0[0x30];
    f32 f30;
    s16 h34;
    u8 pad36[0xE];
    u8 b44;
    u8 pad45[0x2B];
    u8 w70[0x7];
    u8 b77;
    u8 pad78[0x60];
    s32 wD8;
    u8 padDC[0x34];
    u8 w110[0xC];
    s32 w11C;
    u8 pad120[0x20];
    u8 w140[0x10];
    Other_0034BF90 *w150;
    s32 w154;
} Vars_0034BF90;

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_0034BF90;

extern u8 D_001A4C60[];
extern s32 D_L31_001DD1B0;
__asm__(".extern D_L31_001DD1B0, 4");
extern f32 D_L31_001DD214;
__asm__(".extern D_L31_001DD214, 4");
extern s32 D_L31_001DD258;
__asm__(".extern D_L31_001DD258, 4");
extern f32 D_L31_001DD29C;
__asm__(".extern D_L31_001DD29C, 4");
extern V4_0034BF90 D_L31_001E12C0 __attribute__((section(".sdata")));
extern f32 D_L31_001E14F0;
extern f32 D_L31_001E14F4;
extern f32 D_L31_001E14F8;
extern f32 D_L31_001E14FC;
extern f32 D_L31_001E1500;
extern f32 D_L31_001E1504;

extern Hit_0034BF90 *func_L01_00447490(void *, s32, s32);
extern void func_L01_0044ABD0(void *, void *);
extern s32 func_L01_004AAC98(s32, s32, s32, s32);
extern void func_003C4A40(void *, void *);
extern void func_L01_003739B8(void *, void *);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_003C2F58(void *, s32, void *);
extern int func_L30_0034D8D8(void *, float);
extern f32 func_0038CF00(void *, void *);
extern s32 func_0038CAD0(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L31_003478E8(void *, void *, void *, f32, f32, f32, f32, f32, f32, f32, s32);
extern void func_0038D308(void *, void *);
extern void func_L31_00412DF0(void *);
extern s32 func_L01_004450F0(void *, s32, s32);

void func_L31_0034BF90(Moby_0034BF90 *m) {
    Vars_0034BF90 *v = m->vars;
    Hit_0034BF90 *hit;
    V4_0034BF90 a;
    V4_0034BF90 b;
    V4_0034BF90 dir;
    V4_0034BF90 pos;
    s32 i;
    u8 st;

    hit = func_L01_00447490(m, 0x10000, 0);
    func_L01_0044ABD0(m, v->w70);
    if (hit != 0) {
        if (0.0f < hit->f2C && m->state != 0x42 && hit->moby != 0) {
            s16 c = ((Other_0034BF90 *)hit->moby)->oClass;
            if ((c == 0x1363 || c == 0x1EF9 || c == 0x15C6) && v->wD8 == 0) {
                v->f30 -= hit->f2C;
                if (!(v->f30 <= 0.0f)) {
                    func_L01_004AAC98(2, 0, hit->moby ? (s32)hit->moby : (s32)m, 0x165E);
                    v->b77 = 0xFF;
                    func_003C4A40(m, v->w70);
                    v->wD8 = D_L31_001DD258;
                    func_L01_003739B8(m, hit);
                    if (m->b43 != 1) {
                        func_003C3A10(m, 1, 0, (D_L31_001DD1B0 * 5 + 2) / 6);
                    }
                }
            }
        }
        m->bA8 = 0xFF;
    }
    func_003C2F58(m, 0, &a);
    if (func_L30_0034D8D8(&a, 1.5f)) {
        v->w11C = 1;
    } else {
        if (v->w11C != 0) {
            u8 *hero = D_001A4C60;
            if (func_0038CF00(&a, hero) < 30.0f) {
                func_L01_004AAC98(6, 0, *(s32 *)(hero + 0x2540), 0x165E);
            }
        }
        v->w11C = 0;
    }
    func_003C2F58(m, 0x1E, &b);
    st = m->state;
    if (st != 0x42 && st != 4 && st != 0xFE && st != 0xFD && v->f30 <= 0.0f) {
        if (func_L30_0034D8D8(&a, 1.5f) && func_L30_0034D8D8(&b, 1.5f)) {
            func_L01_004450F0(m, 4, -1);
        }
    }
    func_0038CAD0(&v->wD8);
    func_0038CAD0(v->w110);
    st = m->state;
    if (st != 0x42 && st != 4 && st != 1 && st != 5 && st != 6 && st != 0xFD && st != 0xFE && v->wD8 == 0) {
        for (i = 0; i < 0x1F; i++) {
            func_003C2F58(m, i, &pos);
            vec_sub_ba(&dir, D_001A4C60, &pos);
            func_0038CF68(&dir, &dir, 1.0f);
            func_L30_0034CB68((s32)m, (u8 *)&dir, 1, -1, (s32)&pos, 0, (f32)v->b44,
                              D_L31_001DD214 * m->f2C / m->cls->f24);
        }
    }
    if (v->w150 != 0) {
        if ((u8)(v->w150->state + 3) < 2) {
            v->w150 = 0;
        } else {
            func_L31_003478E8(v->w150, (u8 *)v->w150 + 0x10, v->w140, -0.0095f, 0.5f, 0.07f, 0.05f, 0.05f, 0.08f, 0.0f, 0);
        }
    }
    if (m->flags & 2) {
        st = m->state;
        if (st == 4 || st == 0x42) {
            if (m->b43 != 1) {
                func_003C3A10(m, 1, 0, (D_L31_001DD1B0 * 5 + 2) / 6);
            }
        } else if (m->b43 != 0) {
            func_003C3A10(m, 0, 0, (D_L31_001DD1B0 * 5 + 2) / 6);
        }
    }
    if (v->w154 == 0 && (st = m->state) != 0x42 && st != 4 && st != 0 && st != 5 && st != 6) {
        s32 third = v->h34 / 3;
        D_L31_001E14F4 = third;
        D_L31_001E14FC = third;
        D_L31_001E1504 = (f32)v->h34 - D_L31_001E14F4 - D_L31_001E14FC;
        D_L31_001E14F0 = v->f30 - D_L31_001E14F4 - D_L31_001E1504;
        if (D_L31_001E14F0 < 0.0f) {
            D_L31_001E14F0 = 0.0f;
        }
        D_L31_001E14F8 = v->f30 - D_L31_001E1504;
        if (D_L31_001E14F8 > D_L31_001E14FC) {
            D_L31_001E14F8 = D_L31_001E14FC;
        } else if (D_L31_001E14F8 < 0.0f) {
            D_L31_001E14F8 = 0.0f;
        }
        D_L31_001E1500 = v->f30;
        if (D_L31_001E1500 > D_L31_001E1504) {
            D_L31_001E1500 = D_L31_001E1504;
        } else if (D_L31_001E1500 < 0.0f) {
            D_L31_001E1500 = 0.0f;
        }
    } else if (v->w154 == 0) {
        D_L31_001E14F4 = 0.0f;
    }
    m->pos[0] = D_L31_001E12C0.x * 1024.0f;
    m->pos[1] = D_L31_001E12C0.y * 1024.0f;
    m->pos[2] = D_L31_001E12C0.z * 1024.0f;
    m->pos[3] = D_L31_001DD29C * 1024.0f;
    func_0038D308(m->c0, m->f0);
    func_L31_00412DF0(m);
}
/* localdecomp:end func_L31_0034BF90 */

/* localdecomp:start func_L31_0034C5A0 */
#include "vu0.h"

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_0034C5A0;

typedef struct {
    u8 pad0[0x120];
    V4_0034C5A0 pos;
    f32 f130;
    f32 f134;
    s32 w138;
} Vars_0034C5A0;

typedef struct {
    u8 pad0[0x10];
    V4_0034C5A0 v10;
    u8 pad20[0x68 - 0x20];
    Vars_0034C5A0 *vars;
} Moby_0034C5A0;

typedef struct {
    f32 m[4][4];
} M_0034C5A0;

typedef struct {
    u8 pad0[0x10];
    M_0034C5A0 m[36];
} Mats_0034C5A0;

__asm__(".extern D_L31_001DD218, 4");
__asm__(".extern D_L31_001DD228, 4");
__asm__(".extern D_L31_001DD22C, 4");
__asm__(".extern D_L31_001DD230, 4");
__asm__(".extern D_L31_001DD234, 4");
__asm__(".extern D_L31_001DD238, 4");
__asm__(".extern D_L31_001DD23C, 4");
extern f32 D_L31_001DD218;
extern f32 D_L31_001DD228;
extern f32 D_L31_001DD22C;
extern f32 D_L31_001DD230;
extern f32 D_L31_001DD234;
extern s32 D_L31_001DD238;
extern s32 D_L31_001DD23C;
extern s32 D_L31_001DF340 __attribute__((section(".sdata")));
extern V4_0034C5A0 D_L31_001E12C0_0034C5A0 __attribute__((section(".sdata")));
extern f32 D_L31_002B2D00[];
extern M_0034C5A0 D_L31_00284120[];
extern Mats_0034C5A0 D_L31_00284110;

extern void func_L31_0034BB58(void *, vu0_v4 *, f32);
extern void func_L31_0034B700(Moby_0034C5A0 *, V4_0034C5A0 *, V4_0034C5A0 *, V4_0034C5A0 *, f32, f32);
extern f32 func_L31_0034B688(V4_0034C5A0 *, V4_0034C5A0 *);
extern void func_0038D750(void *, s32, f32);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038DB48(f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);

void func_L31_0034C5A0(Moby_0034C5A0 *m, f32 t) {
    Vars_0034C5A0 *v = m->vars;
    V4_0034C5A0 a;
    V4_0034C5A0 b;
    V4_0034C5A0 d;
    V4_0034C5A0 c;
    f32 prev = 0.0f;
    f32 ang;
    f32 k;
    s32 i;
    f32 s;

    qzero(&D_L31_001E12C0_0034C5A0);
    v->w138 = 0;
    if (t > 1.0f - D_L31_001DD218 * 0) {
        t = 1.0f - D_L31_001DD218 * 0;
    } else if (t < D_L31_001DD218 * 30) {
        t = D_L31_001DD218 * 30;
    }
    func_L31_0034BB58(m, (vu0_v4 *)&a, t);
    m->v10 = a;
    for (i = 0; i < 30; i++) {
        func_L31_0034B700(m, &b, &c, &a, t, D_L31_002B2D00[i]);
        vec_add_ab(&D_L31_001E12C0_0034C5A0, &D_L31_001E12C0_0034C5A0, &b);
        ang = func_L31_0034B688(&b, &a);
        func_0038D750(&D_L31_00284120[i], 1, ang - prev);
        k = (t - v->f130) * (c.x - v->f130);
        if (k < 0.0f) {
            v->w138 = 1;
            func_0038CE20(&d, &b, fabs_asm((t - v->f130) / (t - c.x)));
            func_0038CE20(&v->pos, &a, fabs_asm((c.x - v->f130) / (t - c.x)));
            vec_add_ab(&v->pos, &v->pos, &d);
        }
        k = (t - v->f134) * (c.x - v->f134);
        if (k < 0.0f) {
            v->w138 = 2;
            func_0038CE20(&d, &b, fabs_asm((t - v->f134) / (t - c.x)));
            func_0038CE20(&v->pos, &a, fabs_asm((c.x - v->f134) / (t - c.x)));
            vec_add_ab(&v->pos, &v->pos, &d);
        }
        prev = ang;
        t = c.x;
        a = b;
        if (t > 1.0f - D_L31_001DD218 * i) {
            t = 1.0f - D_L31_001DD218 * i;
        } else if (t < (30 - i) * D_L31_001DD218) {
            t = (30 - i) * D_L31_001DD218;
        }
    }
    func_0038CE20(&D_L31_001E12C0_0034C5A0, &D_L31_001E12C0_0034C5A0, 1.0f / 30.0f);
    D_L31_00284110.m[34].m[1][0] = D_L31_00284110.m[32].m[1][0] = D_L31_001DD228;
    D_L31_00284110.m[34].m[1][2] = D_L31_00284110.m[32].m[1][2] = D_L31_001DD22C;
    s = D_L31_001DD230 * 0.5f * (func_0038D098(func_0038DB48(D_L31_001DF340 * 6.2831855f / D_L31_001DD238)) + 1.0f);
    func_0038D750(&D_L31_00284110.m[32], 1, s);
    s = D_L31_001DD230 * 0.5f * (func_0038D0B0(func_0038DB48(D_L31_001DF340 * 6.2831855f / D_L31_001DD238)) + 1.0f);
    func_0038D750(&D_L31_00284110.m[34], 1, -s);
    s = D_L31_001DD234 * 0.5f * (func_0038D098(func_0038DB48(D_L31_001DF340 * 6.2831855f / D_L31_001DD23C)) + 1.0f);
    func_0038D750(&D_L31_00284110.m[33], 1, s);
    s = D_L31_001DD234 * 0.5f * (func_0038D0B0(func_0038DB48(D_L31_001DF340 * 6.2831855f / D_L31_001DD23C)) + 1.0f);
    func_0038D750(&D_L31_00284110.m[35], 1, -s);
}
/* localdecomp:end func_L31_0034C5A0 */

/* localdecomp:start func_L31_0034CA18 */
#include "vu0.h"

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_0034CA18;

typedef struct {
    u8 pad0[0x120];
    V4_0034CA18 pos;
    u8 pad130[0x138 - 0x130];
    s32 w138;
    f32 f13C;
} Vars_0034CA18;

typedef struct {
    u8 pad0[0x68];
    Vars_0034CA18 *vars;
} Moby_0034CA18;

__asm__(".extern D_L31_001DD27C, 4");
__asm__(".extern D_L31_001DD28C, 4");
__asm__(".extern D_L31_001DD288, 4");
__asm__(".extern D_L31_001DD274, 4");
__asm__(".extern D_L31_001DD298, 4");
__asm__(".extern D_L31_001DD294, 4");
__asm__(".extern D_L31_001DD270, 4");
__asm__(".extern D_L31_001DD284, 4");
__asm__(".extern D_L31_001DD280, 4");
__asm__(".extern D_L31_001DD290, 4");
__asm__(".extern D_L31_001DD278, 4");
__asm__(".extern D_L31_001DD26C, 4");
__asm__(".extern D_L31_001DD264, 4");
extern s32 D_001A71A0[];
extern f32 D_L31_001DD27C;
extern f32 D_L31_001DD28C;
extern f32 D_L31_001DD288;
extern f32 D_L31_001DD274;
extern f32 D_L31_001DD298;
extern f32 D_L31_001DD294;
extern f32 D_L31_001DD270;
extern f32 D_L31_001DD284;
extern f32 D_L31_001DD280;
extern f32 D_L31_001DD290;
extern s32 D_L31_001DD278;
extern f32 D_L31_001DD26C;
extern s32 D_L31_001DD264;
extern s32 func_L01_004AAC98(s32, s32, s32, s32);
extern f32 func_003824E0(f32, f32);
extern f32 func_003C4088(f32, f32, f32);
/* the definition (L31_003ABC08.c) lists its ints first; ints and floats take registers apart, and
 * this interleaving gives retail's argument-move order */
extern u8 *func_L31_003AC0B0(vu0_q *, vu0_q *, s32, s32, f32, f32, s32, s32, f32, f32);

void func_L31_0034CA18(Moby_0034CA18 *m) {
    Vars_0034CA18 *v = m->vars;
    V4_0034CA18 dir;
    V4_0034CA18 pos;
    f32 r;
    f32 t;
    f32 s;

    if (v->w138 == 0) {
        return;
    }
    func_L01_004AAC98(1, 0, D_001A71A0[0], 0x165E);
    v->f13C += D_L31_001DD27C;
    if (!(1.0f < v->f13C)) {
        return;
    }
    r = func_003824E0(D_L31_001DD28C, D_L31_001DD288);
    v->f13C -= 1.0f;
    pos = v->pos;
    pos.z += func_003824E0(-D_L31_001DD274, D_L31_001DD274);
    qzero(&dir);
    if (v->w138 == 1) {
        dir.x = func_003824E0(D_L31_001DD298, D_L31_001DD294);
        pos.x += D_L31_001DD270;
    } else {
        dir.x = -func_003824E0(D_L31_001DD298, D_L31_001DD294);
        pos.x -= D_L31_001DD270;
    }
    t = func_003C4088(D_L31_001DD284, D_L31_001DD280,
                      (r - D_L31_001DD28C) / (D_L31_001DD288 - D_L31_001DD28C));
    s = func_003824E0(-D_L31_001DD290, D_L31_001DD290);
    func_L31_003AC0B0((vu0_q *)&pos, (vu0_q *)&dir, D_L31_001DD278, 0, r, D_L31_001DD26C, D_L31_001DD264, (s32)m, t, s);
}
/* localdecomp:end func_L31_0034CA18 */
