#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));

typedef struct Vars_3E9BA8 {
    f32 f0;
    f32 f4;
    u8 pad8[0x2C - 0x8];
    f32 f2C;
    u8 pad30[0xC50 - 0x30];
    vu0_v4 vecs[12];
    f32 rot[12];
    f32 fD40;
} Vars_3E9BA8;

/* localdecomp:start func_L20_003E9AC0 */
extern f32 func_0038CF38(f32 *, f32 *);
extern f32 D_L20_001E2E80[];
__asm__(".extern D_L20_001E2E80, 16");
extern f32 func_003C4138(f32 *, f32, f32);
extern f32 D_L20_001DF210;
__asm__(".extern D_L20_001DF210, 4");
extern void func_L20_003E8288(u8 *a0, f32 size);
extern f32 D_L20_001DF178;
__asm__(".extern D_L20_001DF178, 4");
extern s32 D_L20_001DF170;
__asm__(".extern D_L20_001DF170, 4");
extern s32 D_L20_001DF174;
__asm__(".extern D_L20_001DF174, 4");
extern f32 D_L20_001DF17C;
__asm__(".extern D_L20_001DF17C, 4");
extern f32 D_L20_001DF180;
__asm__(".extern D_L20_001DF180, 4");
extern f32 D_L20_001DF184;
__asm__(".extern D_L20_001DF184, 4");
extern u32 D_L20_001DF188;
__asm__(".extern D_L20_001DF188, 4");
extern u32 D_L20_001DF18C;
__asm__(".extern D_L20_001DF18C, 4");
extern f32 D_L20_001DF220;
__asm__(".extern D_L20_001DF220, 4");
extern s32 D_L20_001DF218;
__asm__(".extern D_L20_001DF218, 4");
extern s32 D_L20_001DF21C;
__asm__(".extern D_L20_001DF21C, 4");
extern f32 D_L20_001DF224;
__asm__(".extern D_L20_001DF224, 4");
extern f32 D_L20_001DF228;
__asm__(".extern D_L20_001DF228, 4");
extern f32 D_L20_001DF22C;
__asm__(".extern D_L20_001DF22C, 4");
extern u32 D_L20_001DF230;
__asm__(".extern D_L20_001DF230, 4");
extern u32 D_L20_001DF234;
__asm__(".extern D_L20_001DF234, 4");
extern f32 D_L20_001DF23C;
__asm__(".extern D_L20_001DF23C, 4");
extern f32 D_L20_001DF240;
__asm__(".extern D_L20_001DF240, 4");
extern s32 D_L20_001D66B0;
__asm__(".extern D_L20_001D66B0, 16");
extern void func_L01_00404808(void (*)(void *), void *);

void func_L20_003E9AC0(u8 *p) {
    f32 len = func_0038CF38((f32 *)(p + 0x10), D_L20_001E2E80);
    if (len <= 2.0f && 1.0f < len) {
        func_003C4138(&D_L20_001DF210, 0.5f, 0.2f);
    } else if (len <= 1.0f) {
        func_003C4138(&D_L20_001DF210, 0.0f, 0.2f);
    } else {
        func_003C4138(&D_L20_001DF210, 2.0f, 0.1f);
    }
    func_L20_003E8288(p, D_L20_001DF210);
}
/* localdecomp:end func_L20_003E9AC0 */

/* localdecomp:start func_L20_003E9BA8 */
/* PAL port of the NTSC-U match src/us/levels/func_L20_003E7C98.c */
#include "vu0.h"

extern f32 D_L20_001DF220;
__asm__(".extern D_L20_001DF220, 4");
extern s32 D_L20_001DF218;
__asm__(".extern D_L20_001DF218, 4");
extern s32 D_L20_001DF21C;
__asm__(".extern D_L20_001DF21C, 4");
extern f32 D_L20_001DF224;
__asm__(".extern D_L20_001DF224, 4");
extern f32 D_L20_001DF228;
__asm__(".extern D_L20_001DF228, 4");
extern f32 D_L20_001DF22C;
__asm__(".extern D_L20_001DF22C, 4");
extern u32 D_L20_001DF230;
__asm__(".extern D_L20_001DF230, 4");
extern u32 D_L20_001DF234;
__asm__(".extern D_L20_001DF234, 4");
extern u8 D_L20_001E2E00[];
extern f32 func_0038D0B0(f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_003D9508(void *v, s32 id, u32 col, s32 e, f32 a, f32 b, f32 c);
extern void func_0038D890(void *, void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_0040A8C0(u128_t *a, u128_t *b, s32 c, s32 d, u32 c0, u32 c1, u32 c2, u32 c3, f32 e, f32 f, f32 g);

void func_L20_003E9BA8(u8 *obj) {
    vu0_v4 w;
    vu0_v4 p;
    vu0_v4 q;
    Vars_3E9BA8 *vars;
    s32 i;
    s32 col;

    vars = *(Vars_3E9BA8 **)(obj + 0x68);
    col = func_0038DBD8(D_L20_001DF218, D_L20_001DF21C, func_0038D0B0(D_L20_001DF220) * 0.5f + 0.5f);
    D_L20_001DF220 = func_0038DAB8(D_L20_001DF220, func_003824E0(D_L20_001DF224, D_L20_001DF228) * 0.017453292f * 0.020000001f);
    func_003D9508(obj + 0x10, 0x43, col, 1, 2.25f, -0.1f, vars->f0);
    func_003D9508(obj + 0x10, 0x31, 0x7FFFFFFF, 1, 1.0f, 0.0f, -vars->f4);
    func_003D9508(obj + 0x10, 0x4B, 0xDFFFFFFF, 3, 2.0f, 0.025f, -vars->f0);
    for (i = 0; i < 12; i++) {
        vec_sub_ab(&w, &D_L20_001E2E00, obj + 0x10);
        func_0038D890(&vars->vecs[i], &vars->vecs[i], &w, vars->rot[i]);
        vars->f2C = vars->f2C + 0.03f;
        if (vars->f2C > 2.5f) {
            vars->f2C = 2.5f;
        }
        func_0038CF68(&vars->vecs[i], &vars->vecs[i], vars->f2C);
        vec_add_ab(&p, &vars->vecs[i], obj + 0x10);
        q = *(vu0_v4 *)(obj + 0x10);
        func_L01_0040A8C0(&p, &q, 0x12, 1, D_L20_001DF230, D_L20_001DF230, D_L20_001DF234, D_L20_001DF234, D_L20_001DF22C, 3.0f, vars->fD40);
    }
    vars->fD40 = vars->fD40 - func_003824E0(0.025f, 0.035f);
    if (vars->fD40 <= -8.0f) {
        vars->fD40 = vars->fD40 + 8.0f;
    }
}
/* localdecomp:end func_L20_003E9BA8 */

/* localdecomp:start func_L20_003E9E38 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003E9E38;

typedef struct {
    f32 f0;                         /* 0x000 */
    f32 f4;                         /* 0x004 */
    u8 pad8[0xC - 0x8];
    f32 fC;                         /* 0x00C */
    u8 pad10[0x14 - 0x10];
    s16 h14;                        /* 0x014 */
    s16 h16;                        /* 0x016 */
    s16 h18;                        /* 0x018 */
    s16 h1A;                        /* 0x01A */
    s32 i1C;                        /* 0x01C */
    s16 timer;                      /* 0x020 */
    s16 h22;                        /* 0x022 */
    u8 pad24[0x2C - 0x24];
    f32 len;                        /* 0x02C */
    u8 pad30[0xC50 - 0x30];
    V4_003E9E38 pts[12];            /* 0xC50 */
    f32 ang[12];                    /* 0xD10 */
} S_003E9E38;

extern f32 func_0038DAB8(f32, f32);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038D890(void *, void *, void *, f32);
extern f32 func_00382538(void);
extern s32 func_0038CB00(void *);
extern void func_00382580(void *, f32, f32);
extern u8 *func_L01_004735F0(void *, void *, s32, f32);
extern void func_L01_00404A10(void *, void *);
extern void func_L20_003E84B0(u8 *);
extern void func_L20_003E8E68(u8 *m);
extern void func_L20_003E90C0(u8 *);
extern void func_L20_003E9BA8(u8 *obj);
extern void func_L20_003E9AC0(u8 *p);
__asm__(".extern D_L20_001E2E00, 16");
extern s32 D_L20_001DF20C;
__asm__(".extern D_L20_001DF20C, 4");

/* d.xyz = qa - *b, with qa already in a VU0 register */
static __inline__ void sub_003E9E38(void *d, vu0_q qa, void *b) {
    vu0_q qb, qr;
    __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(vu0_v4 *)b));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(qr) : "j"(qa), "j"(qb));
    __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)d) : "j"(qr));
}

void func_L20_003E9E38(u8 *p) {
    S_003E9E38 *v = *(S_003E9E38 **)(p + 0x68);
    V4_003E9E38 a;
    V4_003E9E38 d;
    s32 i;
    s32 j;
    s32 k;
    u8 *ray;
    u8 state;

    v->f0 = func_0038DAB8(v->f0, 0.03490659f);
    v->f4 = func_0038DAB8(v->f4, 0.10471976f);
    state = p[0x20];
    switch (state) {
    case 0:
        for (i = 0; i < 12; i++) {
            v->ang[i] = func_003824E0(0.017453294f, 0.05235988f);
            v->len = 2.0f;
            a.x = func_0038D098(*(f32 *)(p + 0xF8));
            a.y = func_0038D0B0(*(f32 *)(p + 0xF8));
            a.z = 0.0f;
            vec_sub_ab(&d, ((f32 *)&D_L20_001E2E00), p + 0x10);
            func_0038CF68(&d, &d, 1.0f);
            func_0038CE90(&v->pts[i], &a, &d);
            func_0038CF68(&v->pts[i], &v->pts[i], v->len);
            func_0038D890(&v->pts[i], &v->pts[i], &d, func_00382538());
        }
        func_L20_003E84B0(p);
        v->timer = (v->i1C * 5 + 2) / 6;
        p[0x20] = 2;
        v->fC = 2.5f;
        v->h18 = 1;
        v->h1A = 1;
        break;
    case 2:
        if (func_0038CB00(&v->timer) != 0) {
            p[0x20] = 3;
            v->timer = (v->h14 * 5 + 2) / 6;
            func_L20_003E84B0(p);
        }
        break;
    case 3:
        if (func_0038CB00(&v->timer) != 0) {
            if (v->h16 != 0) {
                p[0x20] = 2;
                v->timer = 4;
            } else {
                v->timer = 4;
            }
        } else if (v->h22 == 0) {
            func_L20_003E84B0(p);
        }
        break;
    }
    for (j = 0; j < 1; j++) {
        vu0_q qp;

        func_00382580(&a, 0.025f, 0.15f);
        vec_add_ba(&a, &a, p + 0x10);
        __asm__("lqc2 %0, %1" : "=j"(qp) : "m"(*(vu0_v4 *)(p + 0x10)));
        sub_003E9E38(&d, qp, &a);
        func_0038CF68(&d, &d, 0.015000001f);
        ray = func_L01_004735F0(&a, &d, 0xC, 3.0f);
        if (ray != 0) {
            *(u32 *)(ray + 4) = 0xFF20FF20;
        }
    }
    for (k = 0; k < 1; k++) {
        vu0_q qp;

        func_00382580(&a, 0.025f, 0.15f);
        vec_add_ba(&a, &a, p + 0x10);
        __asm__("lqc2 %0, %1" : "=j"(qp) : "m"(*(vu0_v4 *)(p + 0x10)));
        sub_003E9E38(&d, qp, &a);
        func_0038CF68(&d, &d, 0.015000001f);
        ray = func_L01_004735F0(&a, &d, 0xC, 1.5f);
        if (ray != 0) {
            *(u32 *)(ray + 4) = 0x7FFFFFFF;
        }
    }
    func_L01_00404A10(func_L20_003E9AC0, p);
    func_L01_00404A10(func_L20_003E9BA8, p);
    if (v->h22 != 0) {
        func_L20_003E8E68(p);
        if (D_L20_001DF20C < v->h22) {
            func_L01_00404A10(func_L20_003E90C0, p);
        }
    }
}
/* localdecomp:end func_L20_003E9E38 */

/* localdecomp:start func_L20_003EA258 */
/* PAL port of the NTSC-U match src/us/levels/func_L20_003E8318.c */
#include "vu0.h"

extern f32 D_L20_001DF23C;
__asm__(".extern D_L20_001DF23C, 4");
extern f32 D_L20_001DF240;
__asm__(".extern D_L20_001DF240, 4");
extern s32 D_L20_001D66B0;
__asm__(".extern D_L20_001D66B0, 16");
extern void func_L20_003EA488(void *);
extern void func_L01_004AA7E8(void *, s32);
extern void func_003C2880(void *);
extern void func_L01_00404808(void (*)(void *), void *);
extern u8 *func_00382348(s32);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038DAB8(f32, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);

void func_L20_003EA258(u8 *obj) {
    u8 buf[0x30];
    vu0_v4 q;
    vu0_v4 r;
    u8 *vars;
    u8 *e;
    f32 ang;
    f32 k;
    f32 sc;
    s32 i;

    vars = *(u8 **)(obj + 0x68);
    switch (obj[0x20]) {
    case 0:
        *(vu0_q *)vars = *(vu0_q *)(obj + 0x10);
        obj[0x20] = 3;
        *(s32 *)(vars + 0x18) = 17;
        break;
    case 3:
        *(s32 *)(obj + 0x98) = 0;
        *(u16 *)(obj + 0x34) = (*(u16 *)(obj + 0x34) | 0x41) & 0xEFFF;
        func_L01_004AA7E8(obj, 1);
        if (*(f32 *)(vars + 0x1C) > D_L20_001DF23C) {
            func_003C2880(obj);
            return;
        }
        func_L01_00404808(func_L20_003EA488, obj);
        k = D_L20_001DF240 * 0.020000001f;
        *(f32 *)(vars + 0x1C) = *(f32 *)(vars + 0x1C) + k;
        *(f32 *)(vars + 0x20) = *(f32 *)(vars + 0x20) + k;
        sc = 2.0f;
        if (*(s32 *)(obj + 0xB8) != 0) {
            e = func_00382348(*(s32 *)(obj + 0xB8));
            if (e != 0) {
                sc = (f32)e[0x16];
            }
        }
        func_L01_00446760(buf, obj, 0x08000001, &D_L20_001D66B0, sc);
        ang = 0.0f;
        q.x = func_0038D098(ang) * *(f32 *)(vars + 0x1C);
        q.y = func_0038D0B0(ang) * *(f32 *)(vars + 0x1C);
        q.z = 0.0f;
        ang = 0.5235988f;
        vec_add_ba(&q, &q, obj + 0x10);
        for (i = 11; i >= 0; i--) {
            r.x = func_0038D098(ang) * *(f32 *)(vars + 0x1C);
            r.y = func_0038D0B0(ang) * *(f32 *)(vars + 0x1C);
            r.z = 0.0f;
            vec_add_ba(&r, &r, obj + 0x10);
            func_003D3CB0(&q, &r, 9, obj, buf);
            ang = func_0038DAB8(ang, 0.5235988f);
            q = r;
        }
        break;
    }
}
/* localdecomp:end func_L20_003EA258 */

INCLUDE_ASM("asm/levels", func_L20_003EA488);

/* localdecomp:start func_L20_003EAA70 */
typedef struct M_003EAA70 {
    u8 pad0[0x10];
    vu0_q pos;                      /* 0x10 */
    s8 state;                       /* 0x20 */
    u8 pad21[0x2C - 0x21];
    f32 scale;                      /* 0x2C */
    u8 b30;                         /* 0x30 */
    u8 b31;                         /* 0x31 */
    u16 h32;                        /* 0x32 */
    u8 pad34[0x38 - 0x34];
    unsigned long d38;              /* 0x38 */
    u8 pad40[0x68 - 0x40];
    void *pvar;                     /* 0x68 */
    u8 pad6C[0xB8 - 0x6C];
    struct M_003EAA70 *parent;      /* 0xB8 */
    u8 padBC[0xF8 - 0xBC];
    f32 rotz;                       /* 0xF8 */
} M_003EAA70;

typedef struct {
    vu0_q pos;                      /* 0x00 */
    u8 pad10[0x18 - 0x10];
    s32 i18;                        /* 0x18 */
    f32 f1C;                        /* 0x1C */
    u8 pad20[0x30 - 0x20];
    vu0_q dir;                      /* 0x30 */
} V_003EAA70;

extern u8 *func_003C24B0(s32, s32);
extern f32 func_0038D160(f32, f32);
extern u8 *func_00382348(s32);
extern s32 func_L01_004AAC98(s32, s32, void *, s32);
extern void func_L01_00446780(void *, void *, f32, s32, f32, f32, s32, s32, s32);

M_003EAA70 *func_L20_003EAA70(M_003EAA70 *parent, f32 *dir, vu0_q *pos) {
    M_003EAA70 *m = (M_003EAA70 *)func_003C24B0(0x1D26, 0x40);

    if (m != 0) {
        V_003EAA70 *v;
        u8 *r;
        f32 scale;

        m->b30 = parent->b30;
        m->parent = parent;
        m->h32 = parent->h32;
        m->b31 = 1;
        m->state = 0;
        v = m->pvar;
        m->d38 = parent->d38;
        scale = 2.0f;
        m->scale = m->scale * 0.5f;
        m->pos = *pos;
        v->dir = *(vu0_q *)dir;
        m->rotz = func_0038D160(dir[0], dir[1]);
        v->pos = m->pos;
        m->state = 3;
        v->i18 = 0x11;
        if (m->parent != 0) {
            r = func_00382348((s32)m->parent);
            if (r != 0) {
                scale = r[0x16];
            }
        }
        func_L01_004AAC98(0x12, 0, m, 0x1AFD);
        func_L01_00446780(m, &m->pos, 2.0f, 1, scale, 1.0f, 0, 1, 0);
        v->f1C = 2.0f;
    }
    return m;
}
/* localdecomp:end func_L20_003EAA70 */

/* localdecomp:start func_L20_003EABD8 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003EABD8;
typedef struct {
    u8 p0[0x10];
    V4_003EABD8 pos;
    u8 state;
    u8 p21[3];
    u8 *cls;
    u8 p28[8];      /* 0x2C: scale, written through an offset (see the log) */
    u8 p30[4];
    u16 flags;
    u8 p36[0x32];
    u8 *vars;
    u8 p6C[0x2C];
    s32 w98;
    u8 p9C[0xE];
    s16 oclass;
    u8 pAC[0xC];
    u8 *owner;
    u8 pBC[4];
    u8 mtx[0x30];
    f32 rot[4];
} M_003EABD8;
typedef struct {
    V4_003EABD8 v;
    u8 p10[8];
    u8 b18;
    u8 b19;
    s16 h1A;
    u8 p1C[4];
    s32 w20;
    u8 p24[0xC];
} S_003EABD8;

extern void func_0038CF68(void *, void *, f32);
extern void func_L01_0044C280(void *, void *, void *, s32, f32);
extern f32 func_0038DAB8(f32, f32);
extern s32 func_0038CAD0(void *);
extern void func_L01_004AA7E8(void *, s32);
extern s32 func_L20_003EB4E0(void *pv, void *qv);
extern void func_003C2880(void *);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_00404808(void (*)(void *), void *);
extern void func_L20_003EBA98(void);
extern s32 func_L01_004561B8(void *);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern void func_L01_004CB320(void);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern void func_L01_004CB358(void);
extern s32 func_L01_003FB640(void *, s32, f32, void *);
extern s32 func_003D4D00(void *, s32, f32, void *, void *);
extern void func_L01_00456230(void *, s32);
extern void *func_L20_003EE6E8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern f32 func_0038CEA8(void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CED8(void *);
extern void func_0038D308(void *, void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L20_003EB838(u8 *arg0, u8 *arg1);
extern s32 D_L20_001DF280;
__asm__(".extern D_L20_001DF280, 4");
extern f32 D_L20_001DF294;
__asm__(".extern D_L20_001DF294, 4");
extern s32 D_L20_001DF284;
__asm__(".extern D_L20_001DF284, 4");
extern s32 D_L20_001DF288;
__asm__(".extern D_L20_001DF288, 4");
extern s32 D_L20_001DF28C;
__asm__(".extern D_L20_001DF28C, 4");
extern s32 D_L20_001DF290;
__asm__(".extern D_L20_001DF290, 4");
extern f32 D_L20_001DF298;
__asm__(".extern D_L20_001DF298, 4");
extern f32 D_L20_001DF29C;
__asm__(".extern D_L20_001DF29C, 4");
extern f32 D_L20_001DF2A0;
__asm__(".extern D_L20_001DF2A0, 4");
extern f32 D_L20_001DF2A4;
__asm__(".extern D_L20_001DF2A4, 4");
extern f32 D_L20_001DF2A8;
__asm__(".extern D_L20_001DF2A8, 4");
extern f32 D_L20_001DF2AC;
__asm__(".extern D_L20_001DF2AC, 4");
extern f32 D_L20_001DF2B0;
__asm__(".extern D_L20_001DF2B0, 4");
extern s32 D_L20_001DF2B4;
__asm__(".extern D_L20_001DF2B4, 4");
extern s16 D_L20_001DF2C0;
__asm__(".extern D_L20_001DF2C0, 16");
extern s16 D_L20_001DF2C2;
__asm__(".extern D_L20_001DF2C2, 16");
extern u8 D_L20_001D9BA0[];
extern u8 *D_L20_001E9BD8[];
extern s32 D_L20_001EDC40[];
extern u8 D_001A4BE0[];

void func_L20_003EABD8(M_003EABD8 *m) {
    u8 *pv = m->vars;
    V4_003EABD8 tmp;
    S_003EABD8 s;
    V4_003EABD8 dir;
    f32 t;
    f32 k;
    f32 drop;
    s32 hit;
    s32 n;
    s32 i;
    void *o;
    u8 *e;

    switch (m->state) {
    case 1:
        k = (f32)*(s32 *)pv / (f32)D_L20_001DF280;
        *(f32 *)((u8 *)m + 0x2C) = *(f32 *)(m->cls + 0x24) * D_L20_001DF294 * k;
        *(s16 *)(pv + 0x38) = (f32)D_L20_001DF2C0 * k;
        *(s16 *)(pv + 0x3A) = (f32)D_L20_001DF2C2 * k;
        func_0038CF68(&dir, pv + 0x10, 1.0f);
        func_L01_0044C280(&dir, &dir, D_L20_001D9BA0, 1, D_L20_001DF2A0);
        func_0038CF68(pv + 0x10, &dir, func_0038CEA8(pv + 0x10));
        m->rot[2] = func_0038D160(*(f32 *)(pv + 0x10), *(f32 *)(pv + 0x14));
        m->rot[1] = -func_0038D160(func_0038CED8(pv + 0x10), *(f32 *)(pv + 0x18));
        vec_add_ba(&tmp, &m->pos, pv + 0x10);
        m->rot[0] = func_0038DAB8(m->rot[0], D_L20_001DF2A4);
        func_0038D308(m->mtx, m->rot);
        m->pos = tmp;
        func_L20_003EB838((u8 *)m, pv);
        if (func_0038CAD0(pv)) {
            func_L01_004450F0(m, 2, -1);
            m->flags = (m->flags | 0x41) & ~0x1000;
            m->w98 = 0;
            func_L01_004AA7E8(m, 1);
            *(s32 *)pv = D_L20_001DF284;
        }
        break;
    case 2:
        if (func_0038CAD0(pv)) {
            func_L01_004450F0(m, 3, -1);
            if (func_L20_003EB4E0(m, pv) == 0) {
                func_003C2880(m);
                return;
            }
            *(s32 *)pv = D_L20_001DF288;
            func_003A52A0(1, 0, m);
        }
        break;
    case 3:
        func_L01_00404808(func_L20_003EBA98, m);
        if (func_0038CAD0(pv)) {
            func_L01_004450F0(m, 4, -1);
            *(s32 *)pv = D_L20_001DF28C;
        }
        break;
    case 4:
        func_L01_00404808(func_L20_003EBA98, m);
        if (func_0038CAD0(pv)) {
            u8 *c;
            u8 *vel = pv + 0x10;
            func_L01_004450F0(m, 5, -1);
            m->flags &= ~0x41;
            c = m->cls;
            m->flags |= *(u16 *)(c + 0x44) & 0x1000;
            m->w98 = *(s32 *)(c + 0x10);
            qzero(vel);
            *(f32 *)(pv + 0x18) = -*(f32 *)(pv + 0x8);
            m->rot[2] = func_0038D160(*(f32 *)(pv + 0x10), *(f32 *)(pv + 0x14));
            m->rot[1] = -func_0038D160(func_0038CED8(vel), *(f32 *)(pv + 0x18));
            func_0038D308(m->mtx, m->rot);
            *(vu0_q *)&m->pos = *(vu0_q *)(pv + 0x20);
            m->pos.z += D_L20_001DF2A8;
            *(s32 *)pv = D_L20_001DF290;
        }
        break;
    case 5:
        if (func_L01_004561B8(m)) {
            *(f32 *)(pv + 0x40) = 0.0f;
            *(f32 *)(pv + 0x44) = 0.0f;
        }
        if (*(s32 *)pv < 0x11) {
            *(f32 *)(pv + 0x40) -= 0.05f;
            if (*(f32 *)(pv + 0x40) < 0.0f) {
                *(f32 *)(pv + 0x40) = 0.0f;
            }
        } else {
            *(f32 *)(pv + 0x40) += 0.05f;
            *(f32 *)(pv + 0x44) += 0.15f;
            if (1.0f < *(f32 *)(pv + 0x40)) {
                *(f32 *)(pv + 0x40) = 1.0f;
            }
        }
        if (2.5f < *(f32 *)(pv + 0x44)) {
            *(f32 *)(pv + 0x44) = 2.5f;
        }
        func_L01_00404808(func_L20_003EBA98, m);
        k = *(f32 *)((u8 *)m + 0x2C) / *(f32 *)(m->cls + 0x24) + D_L20_001DF2AC * D_L20_001DF294;
        if (D_L20_001DF294 < k) {
            k = D_L20_001DF294;
        }
        t = 1.0f / D_L20_001DF294;
        drop = D_L20_001DF2B0 * 0.00040000002f;
        *(f32 *)((u8 *)m + 0x2C) = *(f32 *)(m->cls + 0x24) * k;
        k = k * t;
        *(s16 *)(pv + 0x38) = (f32)D_L20_001DF2C0 * k;
        *(s16 *)(pv + 0x3A) = (f32)D_L20_001DF2C2 * k;
        vec_add_ba(&tmp, &m->pos, pv + 0x10);
        *(f32 *)(pv + 0x18) -= drop;
        func_L01_00446760(&s, m->owner, 0x8000001, pv + 0x10, *(f32 *)(pv + 0x4));
        s.h1A = m->oclass;
        vec_sub_ab(&s.v, &m->pos, m->owner + 0x10);
        s.v.z = 0.0f;
        func_0038CF68(&s.v, &s.v, 2.0000002f);
        s.b18 = 3;
        s.v.w = 5627.925f;
        s.w20 |= 1;
        o = m->owner;
        func_L01_004CB320();
        hit = func_003D3CB0(&m->pos, &tmp, 0, o, &s);
        if (hit) {
            e = D_L20_001E9BD8[0];
            if (e != 0 && *(s16 *)(e + 0xAA) == 0x186D && e[0x20] != 2 && e[0x20] != 5) {
                e[0x20] = 4;
            }
        }
        func_L01_004CB358();
        if (hit || func_L01_003FB640(&m->pos, 1, D_L20_001DF298, m->owner) ||
            func_0038CAD0(pv)) {
            n = func_003D4D00(&m->pos, 0, D_L20_001DF29C, m->owner, &s);
            for (i = 0; i < n; i++) {
                s32 *l = D_L20_001EDC40;
                u8 *h = D_001A4BE0;
                if (l[i] == *(s32 *)(h + 0x25C0)) {
                    func_L01_00456230(m->owner, 1);
                }
            }
            func_003A52A0(0, 0, m);
            func_L20_003EE6E8(&m->pos, 1, 0xF, 10, 10, 10, 0x19, 0, 0.75f, 0.0f, 0.0f, 0.0f,
                              0, 1, 0, 0, 0, 0, 1, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                              0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            m->flags = (m->flags | 0x41) & ~0x1000;
            m->w98 = 0;
            func_L01_004AA7E8(m, 1);
            func_L01_004450F0(m, 6, -1);
            return;
        }
        m->pos = tmp;
        func_L20_003EB838((u8 *)m, pv);
        break;
    case 6:
        if (func_L01_004561B8(m)) {
            *(s32 *)pv = D_L20_001DF2B4;
        }
        if (func_0038CAD0(pv)) {
            func_003C2880(m);
        }
        break;
    }
}
/* localdecomp:end func_L20_003EABD8 */

/* localdecomp:start func_L20_003EB388 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003EB388;
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_0044A7D0(u8 *);
extern f32 func_0038CEA8(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern f32 func_00382538(void);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CED8(void *);
extern void func_0038D308(void *, void *);
extern void func_0038CC88(void *, void *, s32);
extern void func_003C7C38(void *);
extern s32 D_L20_001DF280;
__asm__(".extern D_L20_001DF280, 4");
extern f32 D_L20_001DF294;
__asm__(".extern D_L20_001DF294, 4");
extern u32 D_L20_001DF2B8[2];
__asm__(".extern D_L20_001DF2B8, 8");

u8 *func_L20_003EB388(void *owner, V4_003EB388 *pos, f32 *dir, f32 speed, s32 flip) {
    u8 *m = func_003C24B0(0x1D37, 0x50);
    u8 *pv;

    if (m != 0) {
        m[0x30] = 0xFF;
        *(s16 *)(m + 0x32) = 0xFF;
        m[0x31] = 1;
        *(void **)(m + 0xB8) = owner;
        m[0x20] = 0;
        pv = *(u8 **)(m + 0x68);
        func_L01_0044A7D0(m);
        *(V4_003EB388 *)(m + 0x10) = *pos;
        *(V4_003EB388 *)(pv + 0x10) = *(V4_003EB388 *)dir;
        *(f32 *)(pv + 0x8) = func_0038CEA8(dir);
        *(f32 *)(pv + 0x4) = speed;
        if (flip) {
            *(f32 *)(pv + 0x4) = -speed;
        }
        func_L01_004450F0(m, 1, -1);
        *(s32 *)pv = D_L20_001DF280;
        *(u16 *)(m + 0x34) |= 0x100;
        *(f32 *)(m + 0xF0) = func_00382538();
        *(f32 *)(m + 0xF8) = func_0038D160(dir[0], dir[1]);
        *(f32 *)(m + 0xF4) = -func_0038D160(func_0038CED8(dir), dir[2]);
        func_0038D308(m + 0xC0, m + 0xF0);
        *(f32 *)(m + 0x2C) = *(f32 *)(*(u8 **)(m + 0x24) + 0x24) * D_L20_001DF294;
        func_0038CC88(pv + 0x30, D_L20_001DF2B8, 0x10);
        func_003C7C38(m);
    }
    return m;
}
/* localdecomp:end func_L20_003EB388 */

/* localdecomp:start func_L20_003EB4E0 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003EB4E0;

extern u8 D_001A4BE0[];
extern V4_003EB4E0 D_001A4CB0;
extern V4_003EB4E0 D_L20_001E9BE0;
extern f32 D_L20_001DF2CC;
__asm__(".extern D_L20_001DF2CC, 4");
extern f32 D_L20_001DF2D0;
__asm__(".extern D_L20_001DF2D0, 4");
extern s32 D_L20_001DF2D4;
__asm__(".extern D_L20_001DF2D4, 4");
extern f32 D_L20_001DF2D8;
__asm__(".extern D_L20_001DF2D8, 4");
extern f32 D_L20_001DF2DC;
__asm__(".extern D_L20_001DF2DC, 4");
extern f32 D_L20_001DF2E0;
__asm__(".extern D_L20_001DF2E0, 4");
extern f32 D_L20_001DF2E4;
__asm__(".extern D_L20_001DF2E4, 4");
extern f32 D_L20_001DF2E8;
__asm__(".extern D_L20_001DF2E8, 4");
extern f32 D_L20_001DF2EC;
__asm__(".extern D_L20_001DF2EC, 4");

extern f32 func_L01_0040E570(void *, void *);
extern f32 func_L04_00455AF8(void *);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_00382538(void);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);

/* d.xyz = qa + *b, with qa already in a VU0 register */
static __inline__ void add_003EB4E0(void *d, vu0_q qa, void *b) {
    vu0_q qb, qr;
    __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(vu0_v4 *)b));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(qr) : "j"(qa), "j"(qb));
    __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)d) : "j"(qr));
}

s32 func_L20_003EB4E0(void *pv, void *qv) {
    u8 *p = pv;
    u8 *q = qv;
    V4_003EB4E0 t;
    V4_003EB4E0 d;
    V4_003EB4E0 best;
    V4_003EB4E0 a;
    vu0_q qh;
    vu0_q qt;
    s32 i;
    u8 *m;
    f32 spread;
    f32 dist;

    if (*(f32 *)(q + 0x4) < 0.0f) {
        *(f32 *)(q + 0x4) = -*(f32 *)(q + 0x4);
        t = D_001A4CB0;
        dist = func_L01_0040E570(*(u8 **)(p + 0xB8) + 0x10, &t);
        if (D_L20_001DF2D8 * D_L20_001DF2D8 < dist) {
            t.z += 0.5f;
            dist = func_L04_00455AF8(&t);
            if (D_001A4CB0.z + 64.0f <= dist) {
                t.z = func_003C3D30(&t, 0, 0, 0.0f);
                *(vu0_q *)(q + 0x20) = *(vu0_q *)&t;
                *(f32 *)(q + 0x28) += D_L20_001DF2D0;
                return 1;
            }
        }
    }
    best.z = -1.0f;
    for (i = 0; i < D_L20_001DF2D4; i++) {
        u8 *hero = D_001A4BE0;

        m = *(u8 **)(hero + 0x25C0);
        if (m != 0) {
            f32 r;
            f32 ang;

            func_0038CF68(&a, m + 0xC0, -D_L20_001DF2E4);
            r = func_003824E0(0.0f, D_L20_001DF2E0);
            spread = D_L20_001DF2DC * 0.017453292f;
            ang = func_0038DAB8(*(f32 *)(m + 0xF8), func_003824E0(-spread, spread));
            t.x = func_0038D098(ang) * r;
            t.y = func_0038D0B0(ang) * r;
            t.z = 0.0f;
            __asm__("lqc2 %0, %1" : "=j"(qh) : "m"(*(vu0_v4 *)(hero + 0xD0)));
            vec_add_ba(&t, &a, &t);
            add_003EB4E0(&t, qh, &t);
        } else {
            f32 ang = func_00382538();

            t.x = func_0038D098(ang) * D_L20_001DF2E8;
            t.y = func_0038D0B0(ang) * D_L20_001DF2E8;
            t.z = 0.0f;
            __asm__("lqc2 %0, %1" : "=j"(qt) : "m"(*(vu0_v4 *)&t));
            add_003EB4E0(&t, qt, hero + 0xD0);
        }
        if (!(func_L01_0040E570(*(u8 **)(p + 0xB8) + 0x10, &t) < D_L20_001DF2D8 * D_L20_001DF2D8)) {
            if (func_003D3CB0(&D_001A4CB0, &t, 2, 0, 0) != 0) {
                vec_sub_ba(&d, &t, &D_001A4CB0);
                func_0038CF68(&t, &d, -D_L20_001DF2CC);
                vec_add_ab(&t, &t, &D_L20_001E9BE0);
            }
            t.z = func_003C3D30(&t, 0, 0, 0.0f);
            if (D_L20_001DF2EC < *(f32 *)(hero + 0xD8) - t.z && best.z < t.z) {
                best = t;
            }
            *(vu0_q *)(q + 0x20) = *(vu0_q *)&t;
            *(f32 *)(q + 0x28) += D_L20_001DF2D0;
            return 1;
        }
    }
    if (0.0f <= best.z) {
        *(vu0_q *)(q + 0x20) = *(vu0_q *)&best;
        *(f32 *)(q + 0x28) += D_L20_001DF2D0;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L20_003EB4E0 */

/* localdecomp:start func_L20_003EB838 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { V4 d; f32 k0, k1, k2; } Loc38;

extern f32 func_003824E0(f32, f32);
extern s32 D_L20_001DFD40;
extern void func_L01_0046E078(void *a0, void *a1, void *a2, void *a3, s32 a4);

void func_L20_003EB838(u8 *arg0, u8 *arg1) {
    Loc38 loc;

    loc.k0 = func_003824E0(-1.0f, -0.9f) * *(f32 *)(arg1 + 0x8);
    loc.k1 = func_003824E0(-0.05f, 0.05f) * *(f32 *)(arg1 + 0x8);
    loc.k2 = func_003824E0(-0.05f, 0.05f) * *(f32 *)(arg1 + 0x8);
    vec_sub_ab(&loc.d, arg0 + 0x10, arg1 + 0x10);
    if ((D_L20_001DFD40 & 3) == (((s32)arg0 >> 8) & 3)) {
        func_L01_0046E078(arg0, &loc.d, &loc.k0, arg1 + 0x30, 1);
    }
}
/* localdecomp:end func_L20_003EB838 */
