#include "common.h"

/* localdecomp:start func_L39_00554E60 */
#include "vu0.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00554E60;
typedef struct { u8 pad0[0x10]; s32 f10; } C_00554E60;
typedef struct {
    u8 pad0[0x10];
    V_00554E60 pos;      /* 0x10 */
    u8 pad20[0x4];
    C_00554E60 *f24;     /* 0x24 */
    u8 pad28[0x70];
    s32 f98;             /* 0x98 */
    u8 pad9c[0xE];
    s16 hAA;             /* 0xAA */
} M_00554E60;
typedef struct {
    s32 flags;
    u8 pad4[0x2D4];
    u32 *f2D8;           /* 0x2D8 */
    u8 pad2dc[0x34];
    f32 f310;            /* 0x310 */
} E_00554E60;
typedef struct {
    u8 pad0[0x18];
    M_00554E60 *f18;     /* 0x18 */
    u8 pad1c[0x14];
    V_00554E60 v30;      /* 0x30 */
    V_00554E60 v40;      /* 0x40 */
} G_00554E60;
typedef struct {
    u8 pad0[0x24CC];
    u32 f24CC;
    s32 f24D0;
} H_00554E60;

extern G_00554E60 D_L39_0025F740;
extern M_00554E60 *D_L39_002637C0[];
extern f32 D_L39_0024BC30;

extern s32 func_003D4D00(void *, s32, f32, void *, s32);
extern E_00554E60 *func_L39_0061D7B0(void *);
extern f32 func_L01_00446E38(void *, void *, f32, s32, void *);
extern s32 func_003D5630(void);
extern f32 func_0038CE68(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_L01_003FB640(void *, f32, s32, void *);
extern s32 func_L01_003FDCA0(void *, f32, s32);

static __inline__ E_00554E60 *alive_00554E60(M_00554E60 *m) {
    E_00554E60 *e = func_L39_0061D7B0(m);
    if (e == 0) {
        return 0;
    }
    if (e->flags & 0x0F000000) {
        return 0;
    }
    return e;
}

s32 func_L39_00554E60(M_00554E60 *obj, V_00554E60 *target, H_00554E60 *hero, f32 radius, f32 step, f32 height, f32 ceil) {
    V_00554E60 dst;
    V_00554E60 *d;
    V_00554E60 dir;
    V_00554E60 slide;
    V_00554E60 normal;
    V_00554E60 push;
    V_00554E60 saved;
    M_00554E60 *list[4];
    V_00554E60 next;
    s32 retried;
    s32 nlist;
    s32 cnt;
    u32 state;
    s32 n;
    s32 i;
    s32 j;
    s32 k;
    s32 hit;
    f32 t;
    f32 top;
    f32 dp;
    E_00554E60 *e;
    M_00554E60 *g;

    state = 0;
    d = &dst;
    *(vu0_q *)d = *(vu0_q *)target;
    *(vu0_q *)&saved = *(vu0_q *)&obj->pos;
    n = func_003D4D00(&obj->pos, 0, 1.5f, obj, 0);
    retried = 0;
    nlist = 0;
    for (cnt = 0, i = 0; i < n; i++) {
        if (alive_00554E60(D_L39_002637C0[i]) != 0) {
            nlist++;
            D_L39_002637C0[i]->f98 = 0;
            list[cnt++] = D_L39_002637C0[i];
        }
    }
    obj->pos.z += height + step;
    d->z += height + step;
    vec_sub_ab(&dir, d, &obj->pos);
    t = func_L01_00446E38(&obj->pos, d, radius, 0x84, obj);
retry:
        k = func_003D5630();
        if (k == 13 || k == 11 || k == 3) {
            state = 3;
        }
        if (k == 12) {
            *(vu0_q *)&obj->pos = *(vu0_q *)&saved;
            return 1;
        }
        if (0.0f < t && t < 1.0f) {
            g = D_L39_0025F740.f18;
            if (g != 0 && (g->hAA == 0x107C || g->hAA == 0x107E)) {
                e = func_L39_0061D7B0(g);
                if (fabs_asm(e->f310) > 0.040000003f) {
                    if (hero != 0) {
                        hero->f24CC = e->f2D8 != 0 ? *e->f2D8 : 0xFFFFFFFF;
                        hero->f24D0 = -1;
                    }
                    state = 3;
                }
            }
            *(vu0_q *)&normal = *(vu0_q *)&D_L39_0025F740.v40;
            k = func_003D5630();
            if (k == 13 || k == 11 || k == 3) {
                state = 3;
            }
            if (state != 3) {
                if (D_L39_0025F740.v40.z > 0.7f && k != 12) {
                    state = 2;
                } else if (state != 2) {
                    state = 1;
                }
            }
            dp = func_0038CE68(&dir, &normal);
            func_0038CE20(&push, &normal, dp * -1.01f);
            func_0038CE20(&slide, &dir, t);
            vec_add_ba(&dir, &dir, &push);
            func_0038CE20(&push, &normal, 0.007f);
            vec_add_ba(&slide, &slide, &push);
            vec_add_ab(&obj->pos, &obj->pos, &slide);
            if (retried == 0) {
                func_0038CE20(&dir, &dir, 1.0f - t);
                vec_add_ba(&next, &obj->pos, &dir);
                t = func_L01_00446E38(&obj->pos, &next, radius, 0x84, obj);
                if (t < 1.0f) {
                    if (0.0f <= t) {
                        retried = 1;
                        goto retry;
                    }
                } else {
                    vec_add_ab(&obj->pos, &obj->pos, &dir);
                }
            }
        } else if (t == 0.0f) {
            if (func_L01_003FB640(d, radius, 4, obj) == 0 && func_L01_003FDCA0(d, radius, 0) == 0) {
                *(vu0_q *)&obj->pos = *(vu0_q *)d;
            } else {
                g = D_L39_0025F740.f18;
                if (g != 0 && (g->hAA == 0x107C || g->hAA == 0x107E)) {
                    if (fabs_asm(func_L39_0061D7B0(g)->f310) > 0.040000003f) {
                        state = 3;
                    }
                }
            }
        } else {
            vec_add_ab(&obj->pos, &obj->pos, &dir);
            {
                g = D_L39_0025F740.f18;
                if (g != 0 && (g->hAA == 0x107C || g->hAA == 0x107E)) {
                    if (fabs_asm(func_L39_0061D7B0(g)->f310) > 0.040000003f) {
                        state = 3;
                    }
                }
            }
        }
    if (state < 2) {
        obj->pos.z -= step;
    }
    if (ceil != -1.0f) {
        top = ceil + height;
        if (top < obj->pos.z) {
            obj->pos.z = top;
        }
    }
    for (j = 0; j < 3; j++) {
        hit = 0;
        if (state != 2) {
            if (func_L01_003FB640(&obj->pos, radius, 0, obj) != 0) {
                hit = 1;
                k = func_003D5630();
                g = D_L39_0025F740.f18;
                if (g != 0 && (g->hAA == 0x107C || g->hAA == 0x107E)) {
                    if (fabs_asm(func_L39_0061D7B0(g)->f310) > 0.040000003f) {
                        state = 3;
                    }
                }
                func_0038CF68(&normal, &D_L39_0025F740.v40, 1.0f);
                if (k == 13 || k == 11 || k == 3) {
                    state = 3;
                } else if (state != 3 && normal.z > 0.7f && k != 12) {
                    state = 2;
                } else if (state == 0) {
                    state = 1;
                }
                *(vu0_q *)&obj->pos = *(vu0_q *)&D_L39_0025F740.v30;
            }
        }
        if (func_L01_003FDCA0(&obj->pos, radius, 0) != 0) {
            *(vu0_q *)&obj->pos = *(vu0_q *)&D_L39_0025F740.v30;
            hit = 1;
        }
        if (hit == 0) {
            break;
        }
    }
    obj->pos.z -= height;
    if (obj->pos.z <= D_L39_0024BC30) {
        state = 4;
    }
    for (i = 0; i < nlist; i++) {
        list[i]->f98 = list[i]->f24->f10;
    }
    return state;
}
/* localdecomp:end func_L39_00554E60 */

/* localdecomp:start func_L39_00555548 */
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_00555548;

struct O_00555548;
typedef struct { u8 pad0[0x7C]; f32 f7C; s32 s80; s32 s84; u8 pad88[8]; s32 s90; u8 pad94[8]; s32 s9C; s32 sA0; f32 fA4; s32 sA8; } A_00555548;
typedef struct { u8 pad0[0x240]; struct O_00555548 *p240; u8 pad244[0x254 - 0x244]; s32 i254; u8 pad258[0x27B - 0x258]; u8 b27B; } S2530_00555548;
typedef struct { u8 pad0[0x1A4]; s32 i1A4; u8 pad1A8[0x1D4 - 0x1A8]; s32 i1D4; } S2534_00555548;
typedef struct {
    u8 pad0[0x20];
    u8 m20[0x80];
    V4_00555548 vA0;
    V4_00555548 vB0;
    u8 padC0[0x60];
    V4_00555548 v120;
    u8 pad130[0x1A0A - 0x130];
    u8 b1A0A;
    u8 pad1A0B[9];
    u8 b1A14;
    u8 pad1A15[0x2458 - 0x1A15];
    s32 i2458;
    u8 pad245C[0x24CC - 0x245C];
    u32 i24CC;
    s32 i24D0;
    u8 pad24D4[0x2530 - 0x24D4];
    S2530_00555548 *p2530;
    S2534_00555548 *p2534;
    u8 pad2538[0x2548 - 0x2538];
    s32 i2548;
    u8 pad254C[0x4D30 - 0x254C];
    V4_00555548 v4D30;
    u8 pad4D40[0x4D68 - 0x4D40];
    f32 f4D68;
} W_00555548;
typedef struct O_00555548 {
    u8 pad0[0x10];
    V4_00555548 pos;
    u8 state;
    u8 pad21[0x10];
    u8 b31;
    u8 pad32[0x43 - 0x32];
    u8 b43;
    u8 pad44[4];
    f32 f48;
    u8 pad4C[0x60 - 0x4C];
    u8 b60;
    u8 pad61[7];
    A_00555548 *a68;
    u8 pad6C[3];
    u8 b6F;
    u8 pad70[0x96 - 0x70];
    u16 h96;
    u8 pad98[0xA8 - 0x98];
    u8 bA8;
    u8 padA9[0xF0 - 0xA9];
    V4_00555548 vF0;
} O_00555548;
typedef struct { u8 pad0[0xAA]; s16 hAA; } X_00555548;
typedef struct S17_00555548 { u32 i0; u8 pad4[0x10]; struct { u8 pad[0x1C]; s32 (*f1C)(struct S17_00555548 *, s32); } *vt14; } S17_00555548;
typedef struct { u8 pad0[0x20]; X_00555548 *p20; } S18_00555548;
typedef struct { u8 pad0[0x2D8]; s32 *p2D8; u8 pad2DC[0x310 - 0x2DC]; f32 f310; } E_00555548;

__asm__(".extern D_L39_0024B294, 4");
__asm__(".extern D_L39_0024B298, 4");
__asm__(".extern D_L39_0024B29C, 4");
__asm__(".extern D_L39_0024B274, 4");
__asm__(".extern D_L39_0024B278, 4");
__asm__(".extern D_L39_0024B28C, 4");
__asm__(".extern D_L39_0024B290, 4");
__asm__(".extern D_L39_0024B26C, 4");
__asm__(".extern D_L39_0024B270, 4");
__asm__(".extern D_L39_0024B284, 4");
__asm__(".extern D_L39_0024B288, 4");
__asm__(".extern D_L39_0024B268, 4");
__asm__(".extern D_L39_0024B27C, 4");
__asm__(".extern D_L39_0024B280, 4");
__asm__(".extern D_L39_0024CE20, 32");
extern W_00555548 *D_L39_0024CE20[1];
extern u8 D_L39_0024DE80[];
extern X_00555548 *D_L39_0025F758[];
extern f32 D_L39_0024B294;
extern f32 D_L39_0024B298;
extern f32 D_L39_0024B29C;
extern f32 D_L39_0024B274;
extern f32 D_L39_0024B278;
extern f32 D_L39_0024B28C;
extern f32 D_L39_0024B290;
extern f32 D_L39_0024B26C;
extern f32 D_L39_0024B270;
extern f32 D_L39_0024B284;
extern f32 D_L39_0024B288;
extern s32 D_L39_0024B268;
extern s32 D_L39_0024B27C;
extern s32 D_L39_0024B280;

extern void func_L39_00556638(void *, s32, s32);
extern s32 func_L39_00554E60(M_00554E60 *, V_00554E60 *, H_00554E60 *, f32, f32, f32, f32);
extern S18_00555548 *func_L01_00447490(void *, s32, s32);
extern S17_00555548 *func_L39_0061CEA0(void *);
extern void func_L01_004471A8(void *, f32);
extern s32 func_0038CAD0(void *);
extern void func_L39_00620AF8(void *, s32, s32, s32);
extern void func_0038D328(void *, void *);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);
extern f32 func_003C3D30(void *, s32, void *, f32);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L39_005B43C8(s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern s32 func_L39_005C42E8(s32, s32);
extern f32 func_L39_005B4410(f32, f32);
extern void func_L39_006384B0(void *);
extern void func_L39_00632D78(void *, s32, f32);
extern void func_L39_00633308(void *, s32, f32, f32, f32);
extern void func_L39_00633620(void *, f32, f32);
extern void func_L39_00633670(void *, f32);
extern s32 func_L01_004561B8(void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038DBA0(f32, f32);
extern void func_L01_00448690(void *, s32, f32, f32);
extern void func_L39_00630548(void *);
extern void func_L39_0063B0A8(void *);

void func_L39_00555548(O_00555548 *o) {
    A_00555548 *a = o->a68;
    W_00555548 *w = D_L39_0024CE20[a->s9C];
    V4_00555548 v0;
    V4_00555548 v1;
    f32 d;
    s32 r;
    u8 t2;

    if (a->s84 > 0 || w == 0 || w->i2458 == 0) {
        func_L39_00556638(o, a->s84 == 2, a->s84 == 3);
        return;
    }
    if (w->b1A14 != 0) {
        S18_00555548 *s18 = func_L01_00447490(o, 0x0B030001, 0);
        if (s18 != 0) {
            S17_00555548 *s17 = (s18->p20 != 0) ? func_L39_0061CEA0(s18->p20) : 0;
            if (s17 == 0 || s17->vt14->f1C(s17, w->i2548) == 0 || (s18->p20 != 0 && s18->p20->hAA == 0x18AB)) {
                w->i24CC = (s17 != 0) ? s17->i0 : 0xFFFFFFFF;
                w->i24D0 = -1;
                func_L39_00620AF8(w, 0, 1, 0);
                return;
            }
        }
    }
    o->bA8 = 0xFF;
    func_L01_004471A8(o, 0.5f);
    func_0038CAD0(&a->s80);
    if (a->s80 == 0) {
        if (w != 0 && w->b1A14 != 0) {
            func_L39_00620AF8(w, 1, 1, 0);
            return;
        }
    }
    t2 = w->b1A14;
    if (t2 != 0) {
        V4_00555548 *p = &o->pos;
        *(u128_t *)&w->vA0 = *(u128_t *)p;
        *(u128_t *)&w->vB0 = *(u128_t *)&o->vF0;
        w->b1A0A = 2;
        func_0038D328(w->m20, &w->vB0);
        if (o->b31 != 0) {
            d = func_L01_0040E548(D_L39_0024DE80, p);
            if (d < 144.0f) {
                func_L01_004472C0(o);
                o->b6F = 0xB;
            }
        }
    } else {
        if (o->b31 != 0) {
            d = func_L01_0040E548(D_L39_0024DE80, &o->pos);
            if (d < 144.0f) {
                func_L01_004472C0(o);
                o->b6F = 0xB;
            }
        }
    }
    switch (o->state) {
    case 0:
        d = o->pos.z - func_003C3D30(&o->pos, 0, o, 0.5f);
        if (D_L39_0024B274 < d) {
            a->f7C = 0.0f;
            func_L01_004450F0(o, 4, -1);
            if (d > 0.5f) {
                if (o->b43 != 6) {
                    func_003C3A10(o, 6, 0, 8);
                }
            }
        } else {
            func_L01_004450F0(o, 1, -1);
        }
        break;
    case 1:
        o->f48 = 1.0f;
        if (w->p2534->i1D4 == 0) {
            func_L01_004450F0(o, 2, -1);
            a->s90 = (func_L39_005B43C8(400, 600) * 5 + 2) / 6;
            if (o->b43 != 3) {
                func_003C3A10(o, 3, 0, 3);
            }
            o->f48 = D_L39_0024B28C;
        } else {
            r = func_L39_005C42E8(0x40, 0);
            if (w->p2534->i1A4 & r) {
                func_L01_004450F0(o, 3, -1);
                a->fA4 = o->pos.z + D_L39_0024B278;
                a->f7C = D_L39_0024B26C * 0.020000001f;
                a->sA0 = (D_L39_0024B27C * 5 + 2) / 6;
                if (o->b43 != 6) {
                    func_003C3A10(o, 6, 0, 8);
                }
                o->f48 = D_L39_0024B290;
            } else if (w->p2534->i1A4 & 0xA0) {
                func_L01_004450F0(o, 5, -1);
                a->s90 = (func_L39_005B43C8(180, 360) * 5 + 2) / 6;
                if (o->b43 != 5) {
                    func_003C3A10(o, 5, 0, 5);
                }
            } else if (o->b60 & 2) {
                f32 f20 = 0.0f;
                f32 f21 = func_L39_005B4410(f20, 150.0f);
                if (f20 <= f21 && f21 < 50.0f) {
                    if (o->b43 != 0) {
                        func_003C3A10(o, 0, 0, 8);
                    }
                }
                if (50.0f <= f21 && f21 < 100.0f) {
                    if (o->b43 != 1) {
                        func_003C3A10(o, 1, 0, 8);
                    }
                }
                if (150.0f <= f21 && f21 < 150.0f) {
                    if (o->b43 != 2) {
                        func_003C3A10(o, 2, 0, 8);
                    }
                }
            }
        }
        *(u128_t *)&v0 = *(u128_t *)&o->pos;
        v0.z += 0.5f;
        if (func_L01_003FB640(&v0, D_L39_0024B298, 4, o) != 0) {
            X_00555548 *x = D_L39_0025F758[0];
            if (x != 0) {
                s16 id = x->hAA;
                if (id == 0x107C || id == 0x107E) {
                    E_00555548 *e = (E_00555548 *)func_L39_0061D7B0(x);
                    if (fabs_asm(e->f310) > 0.060000002f) {
                        s32 *p = e->p2D8;
                        w->i24CC = (p != 0) ? *p : -1;
                        w->i24D0 = -1;
                        func_L39_00620AF8(w, 0, 1, 0);
                    }
                }
            }
        }
        break;
    case 5:
        func_L39_006384B0(w);
        if (o->b60 & 2) {
            func_L01_004450F0(o, 1, -1);
            if (o->b43 != 0) {
                func_003C3A10(o, 0, 0, 3);
            }
        }
        break;
    case 3:
        func_0038CAD0(&a->sA0);
        if (a->sA0 <= 0) {
            if (w->p2534->i1A4 & 0x40) {
                a->sA0 = (D_L39_0024B27C * 5 + 2) / 6;
                o->f48 = D_L39_0024B290;
                a->f7C += D_L39_0024B26C * 0.020000001f;
            }
        }
        if ((D_L39_0024B280 * 5 + 2) / 6 < o->h96) {
            a->f7C -= D_L39_0024B270 * 0.00040000002f;
        }
        if (a->f7C < -0.14000002f) {
            a->f7C = -0.14000002f;
        }
        if ((D_L39_0024B268 * 5 + 2) / 6 < o->h96) {
            func_L01_004450F0(o, 4, -1);
            if (o->b43 != 6) {
                func_003C3A10(o, 6, 0, 8);
            }
        }
        func_L39_00632D78(w, 0, D_L39_0024B284 * 0.020000001f);
        func_L39_00633308(w, 0, 0.072000004f, 0.36f, 0.13962635f);
        o->vF0.z = w->vB0.z;
        func_L39_00633620(w, D_L39_0024B288 * 0.014800001f, D_L39_0024B288 * 0.012f);
        func_L39_00633670(w, 99999.0f);
        vec_add_ba(&v0, &o->pos, &w->v120);
        v0.z += a->f7C;
        if (a->fA4 < v0.z) {
            v0.z = a->fA4;
            if (0.0f < a->f7C) {
                a->f7C = 0.0f;
            }
        }
        r = func_L39_00554E60((M_00554E60 *)o, (V_00554E60 *)&v0, (H_00554E60 *)w, D_L39_0024B298, D_L39_0024B29C, D_L39_0024B294, a->fA4);
        if (r < 3) {
            if (r == 2) {
                if (o->h96 >= 9) {
                    func_L01_004450F0(o, 1, -1);
                    if (o->b43 != 0) {
                        func_003C3A10(o, 0, 0, 8);
                    }
                }
            }
        } else {
            func_L39_00620AF8(w, 0, 1, r == 4);
            return;
        }
        break;
    case 2:
        if (func_L01_004561B8(o) != 0) {
            a->sA8 = func_L39_005B43C8(40, 200);
        }
        a->sA8 = a->sA8 - 1;
        if (o->b60 & 2) {
            if (a->sA8 <= 0) {
                if (o->b43 == 4) {
                    func_003C3A10(o, 3, 0, 4);
                } else {
                    func_003C3A10(o, 4, 0, 4);
                }
                a->sA8 = func_L39_005B43C8(40, 200);
            }
        }
        o->f48 = D_L39_0024B28C;
        if (w->p2534->i1D4 != 0) {
            func_L01_004450F0(o, 1, -1);
            a->s90 = (func_L39_005B43C8(400, 600) * 5 + 2) / 6;
        }
        a->f7C = -0.040000003f;
        r = func_L39_005C42E8(0x40, 0);
        if (w->p2534->i1A4 & r) {
            func_L01_004450F0(o, 3, -1);
            a->fA4 = o->pos.z + D_L39_0024B278;
            a->f7C = D_L39_0024B26C * 0.020000001f;
            a->sA0 = (D_L39_0024B27C * 5 + 2) / 6;
            if (o->b43 != 6) {
                func_003C3A10(o, 6, 0, 8);
            }
            o->f48 = D_L39_0024B290;
        } else if (w->p2534->i1A4 & 0xA0) {
            func_L01_004450F0(o, 5, -1);
            if (o->b43 != 5) {
                func_003C3A10(o, 5, 0, 5);
            }
        }
        func_L39_00632D78(w, 0, D_L39_0024B284 * 0.020000001f);
        func_L39_00633308(w, 0, 0.072000004f, 0.36f, 0.13962635f);
        o->vF0.z = w->vB0.z;
        func_L39_00633620(w, D_L39_0024B288 * 0.014800001f, D_L39_0024B288 * 0.012f);
        func_L39_00633670(w, 99999.0f);
        vec_add_ba(&v0, &o->pos, &w->v120);
        v0.z += a->f7C;
        *(u128_t *)&v1 = *(u128_t *)&o->pos;
        r = func_L39_00554E60((M_00554E60 *)o, (V_00554E60 *)&v0, (H_00554E60 *)w, D_L39_0024B298, D_L39_0024B29C, D_L39_0024B294, -1.0f);
        if (r >= 3) {
            func_L39_00620AF8(w, 0, 1, r == 4);
            return;
        }
        if (a->f7C < 0.0f) {
            if (r == 0 || r == 1) {
                d = o->pos.z - func_003C3D30(&o->pos, 0, o, 0.5f);
                if (D_L39_0024B274 < d) {
                    a->f7C = 0.0f;
                    func_L01_004450F0(o, 4, -1);
                    if (d > 0.5f) {
                        if (o->b43 != 6) {
                            func_003C3A10(o, 6, 0, 8);
                        }
                    }
                }
            }
        }
        break;
    case 4:
        a->f7C -= 0.00392f;
        if (a->f7C < 1.2f) {
            if (o->b43 != 6) {
                func_003C3A10(o, 6, 0, 8);
            }
        }
        func_L39_00632D78(w, 0, D_L39_0024B284 * 0.020000001f);
        func_L39_00633308(w, 0, 0.072000004f, 0.36f, 0.13962635f);
        o->vF0.z = w->vB0.z;
        func_L39_00633620(w, D_L39_0024B288 * 0.014800001f, D_L39_0024B288 * 0.012f);
        func_L39_00633670(w, 99999.0f);
        vec_add_ba(&v0, &o->pos, &w->v120);
        v0.z += a->f7C;
        r = func_L39_00554E60((M_00554E60 *)o, (V_00554E60 *)&v0, (H_00554E60 *)w, D_L39_0024B298, D_L39_0024B29C, D_L39_0024B294, -1.0f);
        if (r >= 3) {
            func_L39_00620AF8(w, 0, 1, r == 4);
            return;
        }
        if (r == 2) {
            a->f7C = 0.0f;
            func_L01_004450F0(o, 0, -1);
        }
        break;
    }
    if (o->state == 1) {
        d = o->pos.z - func_003C3D30(&o->pos, 0, o, 0.5f);
        if (D_L39_0024B274 < d) {
            a->f7C = 0.0f;
            func_L01_004450F0(o, 4, -1);
            if (d > 0.5f) {
                if (o->b43 != 6) {
                    func_003C3A10(o, 6, 0, 8);
                }
            }
        }
    }
    if (w->b1A14 == 0) {
        vec_sub_ba(&v1, &w->v4D30, &o->pos);
        func_0038CE20(&v1, &v1, 0.125f);
        vec_add_ab(&o->pos, &o->pos, &v1);
        d = func_0038DBA0(o->vF0.z, w->f4D68);
        {
            f32 k = 15.0f;
            if (d > 0.7853982f) {
                k = 120.0f;
            }
            func_L01_00448690(&o->vF0.z, 0, w->f4D68, k * 0.017453292f * 0.020000001f);
        }
    }
    o->h96 = o->h96 + 1;
    if (w != 0) {
        *(u128_t *)&w->vA0 = *(u128_t *)&o->pos;
        *(u128_t *)&w->vB0 = *(u128_t *)&o->vF0;
        func_L39_00630548(w);
        func_L39_0063B0A8(w);
        w->p2530->p240 = o;
        w->p2530->i254 = 0;
        w->p2530->b27B = 1;
    }
}
/* localdecomp:end func_L39_00555548 */

/* localdecomp:start func_L39_00556448 */
#include "vu0.h"

extern s32 D_001A5DF8[];
extern vu0_v4 D_L39_0025F760[];
extern u8 *func_003C24B0(s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_L39_005B43C8(s32, s32);
extern void func_L39_00556CC0(void *);
extern void func_003C7C38(void *);

u8 *func_L39_00556448(u8 *a0, u8 *a1, s32 a2) {
    u8 *m;
    u8 *state;
    f32 t;
    vu0_v4 tmp;

    m = func_003C24B0(0x10AD, 0xC0);
    if (m != 0) {
        m[0x30] = 0x7F;
        *(s16 *)(m + 0x32) = 0x7F;
        m[0x31] = 1;
        state = *(u8 **)(m + 0x68);
        *(vu0_q *)(m + 0x10) = *(vu0_q *)(a0 + 0x10);
        *(vu0_q *)(m + 0xF0) = *(vu0_q *)(a0 + 0xF0);
        *(f32 *)(m + 0xF0) = 0.0f;
        *(f32 *)(m + 0xF4) = 0.0f;
        if (*(s16 *)(a1 + 0x2D8) != 0) {
            func_0038CF68(m + 0x10, a1 + 0x40, 1.5f);
            vec_add_ab(m + 0x10, m + 0x10, a1 + 0xA0);
        }
        tmp = *(vu0_v4 *)(m + 0x10);
        tmp.z += 1.0f;
        if (func_003D3CB0(&tmp, m + 0x10, 2, 0, 0) != 0) {
            func_0038CF68(&tmp, &D_L39_0025F760[2], 0.005f);
            vec_add_ab(m + 0x10, &D_L39_0025F760[0], &tmp);
        }
        m[0x20] = 0;
        *(s16 *)(state + 0x76) = 0;
        *(s16 *)(state + 0x74) = func_L39_005B43C8(100, 250);
        *(s32 *)(state + 0x90) = 500;
        *(s32 *)(state + 0x94) = 25;
        *(s32 *)(state + 0x7C) = 0;
        *(s32 *)(state + 0x98) = 0;
        *(s32 *)(state + 0x9C) = *(s32 *)(a1 + 0x2544);
        func_L39_00556CC0(m);
        *(s32 *)(m + 0x98) = *(s32 *)(*(u8 **)(m + 0x24) + 0x10);
        *(f32 *)(state + 0x88) = 1.0f;
        t = (f32)(a2 - D_001A5DF8[0]) / 1000.0f;
        if (t < 0.0f) {
            t = 0.017f;
        }
        *(s32 *)(state + 0x80) = (s32)(t * 50.0f);
        func_003C7C38(m);
    }
    return m;
}
/* localdecomp:end func_L39_00556448 */

/* localdecomp:start func_L39_00556638 */
#include "vu0.h"

extern vu0_q D_L39_0025F770;
extern u8 D_L39_004997E0[];
extern f32 D_L39_0024DCC0[];
extern void func_L39_00628760(void *);
extern s32 func_00382348(u8 *);
extern void func_L39_00637EC8(void *, void *, void *, s32, s32, s32, s32);
extern void func_L39_00628038(void *, s32);
extern f32 func_L39_005B44C8(void);
extern void func_00382760(void *, f32, f32, f32);
extern void func_L39_005C8CA8(void *, void *, s32, s32, s32, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_L39_005B4468(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_L01_004749C8(void *, void *, s32);
extern void func_L01_003D6158(void *, s32, s32, s32, s32, f32, f32);
extern void func_L39_0051AE58(void *, void *, void *);
extern void func_L39_00556C78(void *);
extern void func_003C2880(void *);

void func_L39_00556638(void *arg0, s32 a1, s32 a2) {
    u8 *a0 = arg0;
    vu0_v4 b;
    vu0_v4 a;
    u8 *p;
    s32 i;
    s32 j2;

    p = (u8 *)D_L39_0024CE20[*(s32 *)(*(u8 **)(a0 + 0x68) + 0x9C)];
    if (p != 0) {
        *(s32 *)(p + 0x2458) = 0;
        if (p[0x1A14] != 0) {
            *(vu0_q *)&b = *(vu0_q *)(a0 + 0x10);
            *(vu0_q *)&a = *(vu0_q *)&b;
            a.z += 2.0f;
            b.z -= 0.5f;
            if (func_L01_00446E38(&a, &b, *(f32 *)(p + 0x1F4), 0x80, a0) < 1.0f) {
                *(vu0_q *)(a0 + 0x10) = D_L39_0025F770;
            }
            *(vu0_q *)(p + 0xA0) = *(vu0_q *)(a0 + 0x10);
            *(vu0_q *)(p + 0xB0) = *(vu0_q *)(a0 + 0xF0);
        }
        if (a1 != 0) {
            u8 *q;
            func_L39_00628760(p);
            q = (u8 *)func_00382348(*(u8 **)(p + 0x2524));
            if (q != 0) {
                q[0xE] = 1;
            }
            if (p[0x1A14] != 0) {
                p[0x1A0A] = 1;
                func_L39_00637EC8(p, a0 + 0x10, a0 + 0xF0, 0, 1, 1, 0);
            }
        } else {
            s16 flag;
            if (*(u8 **)(p + 0x2530) != 0 && (*(u8 **)(p + 0x2530))[0x27B] != 0) {
                u8 *q;
                long t;
                s32 x;
                flag = 0;
                q = p + 0x19E4;
                t = *q;
                x = 0;
                if (t != 0) {
                    u8 *d;
                    s32 m;
                    s32 k;
                    s32 n = *q;
                    s32 j;
                    m = n + 1;
                    k = ((s32)q - n) & 7;
                    d = (u8 *)&b;
                    for (j = 0; j < 40; j += 5) {
                        *d++ = D_L39_004997E0[m + ((k + j) & 7) * 255];
                    }
                    ((u32 *)&b)[0] ^= (u32)q;
                    ((u32 *)&b)[1] ^= ((u32 *)&b)[0];
                    x = ((u32 *)&b)[1];
                }
                if ((x ^ 0x31) == 0) {
                    flag++;
                }
            } else {
                flag = 0;
            }
            if ((u8)flag) {
                func_L39_00628038(p, 0);
                (*(s32 (**)(void *, s32, s32, s32, s32))(*(u8 **)(p + 0x14) + 0x34))(p, 0x76, 0, 1, 0);
                if (p[0x1A14] == 0) {
                    p[0x1A0A] = 2;
                }
            }
        }
    }

    for (j2 = 0; j2 < 15; j2++) {
        f32 x, y, z;
        x = func_L39_005B4410(0.0f, 0.37f);
        y = func_L39_005B44C8();
        z = func_L39_005B44C8();
        func_00382760(&a, x, y, z);
        a.z += func_L39_005B4410(0.35f, 0.6f);
        vec_add_ba(&a, &a, a0 + 0x10);
        x = func_L39_005B4410(0.0030000002f, 0.024000002f);
        y = func_L39_005B44C8();
        z = func_L39_005B44C8();
        func_00382760(&b, x, y, z);
        func_L39_005C8CA8(&a, &b, 0x4F7F7F7F, 0x202020, func_L39_005B43C8(0x19, 0x2F), 150000.0f);
    }

    for (i = 0; i < 20; i++) {
        f32 r, ang, t, h;
        ang = func_0038D160(D_L39_0024DCC0[0x50] - *(f32 *)(a0 + 0x10), D_L39_0024DCC0[0x51] - *(f32 *)(a0 + 0x14));
        func_L39_005B4468(1.0f, 2.0f);
        b.x = *(f32 *)(a0 + 0x10) + func_L39_005B4468(0.0f, 0.15f);
        b.y = *(f32 *)(a0 + 0x14) + func_L39_005B4468(0.0f, 0.15f);
        b.z = *(f32 *)(a0 + 0x18) + func_L39_005B4468(0.0f, 0.15f);
        r = func_L39_005B4410(3.0f, 7.0f);
        t = func_L39_005B4468(0.0f, 2.6179938f);
        r *= 0.020000001f;
        h = func_0038DAB8(ang, t);
        a.x = func_0038D098(h) * r;
        a.y = func_0038D0B0(h) * r;
        a.z = 0.0f;
        a.z = func_L39_005B4410(5.0f, 10.0f) * 0.020000001f;
        func_L01_004749C8(&b, &a, 0x8E);
    }

    func_L01_003D6158(a0, 0x4E, 0x4F, 0xA, 1, 1.5f, 1.2f);

    for (i = 0; i < 10; i++) {
        f32 x, y, z, w, v;
        x = func_L39_005B4410(0.0f, 0.35f);
        y = func_L39_005B44C8();
        z = func_L39_005B44C8();
        func_00382760(&a, x, y, z);
        a.z += 0.25f;
        vec_add_ba(&a, &a, a0 + 0x10);
        w = func_L39_005B4410(0.060000002f, 0.120000005f);
        v = func_L39_005B44C8();
        func_00382760(&b, w, v, 1.2217305f);
        b.z = func_L39_005B4410(3.0f, 5.0f) * 0.020000001f;
        func_L39_0051AE58(a0, &a, &b);
    }

    func_L39_00556C78(a0);
    func_003C2880(a0);
}
/* localdecomp:end func_L39_00556638 */
