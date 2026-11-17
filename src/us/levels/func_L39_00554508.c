#include "common.h"

/* NTSC-U counterpart of func_L39_00554E60 (src/levels/shared/L39_00554E60.c) */
/* localdecomp:start func_L39_00554508 */
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

extern G_00554E60 D_L39_0025F840;
extern M_00554E60 *D_L39_002638C0[];
extern f32 D_L39_0024BD30;

extern s32 func_003CF790(void *, s32, f32, void *, s32);
extern E_00554E60 *func_L39_0061B038(void *);
extern f32 func_L01_00443D00(void *, void *, f32, s32, void *);
extern s32 func_003D00C0(void);
extern f32 func_00388730(void *, void *);
extern void func_003886E8(void *, void *, f32);
extern void func_00388830(void *, void *, f32);
extern s32 func_L01_003F9498(void *, f32, s32, void *);
extern s32 func_L01_003FBAF8(void *, f32, s32);

static __inline__ E_00554E60 *alive_00554E60(M_00554E60 *m) {
    E_00554E60 *e = func_L39_0061B038(m);
    if (e == 0) {
        return 0;
    }
    if (e->flags & 0x0F000000) {
        return 0;
    }
    return e;
}

s32 func_L39_00554508(M_00554E60 *obj, V_00554E60 *target, H_00554E60 *hero, f32 radius, f32 step, f32 height, f32 ceil) {
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
    n = func_003CF790(&obj->pos, 0, 1.5f, obj, 0);
    retried = 0;
    nlist = 0;
    for (cnt = 0, i = 0; i < n; i++) {
        if (alive_00554E60(D_L39_002638C0[i]) != 0) {
            nlist++;
            D_L39_002638C0[i]->f98 = 0;
            list[cnt++] = D_L39_002638C0[i];
        }
    }
    obj->pos.z += height + step;
    d->z += height + step;
    vec_sub_ab(&dir, d, &obj->pos);
    t = func_L01_00443D00(&obj->pos, d, radius, 0x84, obj);
retry:
        k = func_003D00C0();
        if (k == 13 || k == 11 || k == 3) {
            state = 3;
        }
        if (k == 12) {
            *(vu0_q *)&obj->pos = *(vu0_q *)&saved;
            return 1;
        }
        if (0.0f < t && t < 1.0f) {
            g = D_L39_0025F840.f18;
            if (g != 0 && (g->hAA == 0x107C || g->hAA == 0x107E)) {
                e = func_L39_0061B038(g);
                if (fabs_asm(e->f310) > 0.03333333507180214f) {
                    if (hero != 0) {
                        hero->f24CC = e->f2D8 != 0 ? *e->f2D8 : 0xFFFFFFFF;
                        hero->f24D0 = -1;
                    }
                    state = 3;
                }
            }
            *(vu0_q *)&normal = *(vu0_q *)&D_L39_0025F840.v40;
            k = func_003D00C0();
            if (k == 13 || k == 11 || k == 3) {
                state = 3;
            }
            if (state != 3) {
                if (D_L39_0025F840.v40.z > 0.7f && k != 12) {
                    state = 2;
                } else if (state != 2) {
                    state = 1;
                }
            }
            dp = func_00388730(&dir, &normal);
            func_003886E8(&push, &normal, dp * -1.01f);
            func_003886E8(&slide, &dir, t);
            vec_add_ba(&dir, &dir, &push);
            func_003886E8(&push, &normal, 0.007f);
            vec_add_ba(&slide, &slide, &push);
            vec_add_ab(&obj->pos, &obj->pos, &slide);
            if (retried == 0) {
                func_003886E8(&dir, &dir, 1.0f - t);
                vec_add_ba(&next, &obj->pos, &dir);
                t = func_L01_00443D00(&obj->pos, &next, radius, 0x84, obj);
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
            if (func_L01_003F9498(d, radius, 4, obj) == 0 && func_L01_003FBAF8(d, radius, 0) == 0) {
                *(vu0_q *)&obj->pos = *(vu0_q *)d;
            } else {
                g = D_L39_0025F840.f18;
                if (g != 0 && (g->hAA == 0x107C || g->hAA == 0x107E)) {
                    if (fabs_asm(func_L39_0061B038(g)->f310) > 0.03333333507180214f) {
                        state = 3;
                    }
                }
            }
        } else {
            vec_add_ab(&obj->pos, &obj->pos, &dir);
            {
                g = D_L39_0025F840.f18;
                if (g != 0 && (g->hAA == 0x107C || g->hAA == 0x107E)) {
                    if (fabs_asm(func_L39_0061B038(g)->f310) > 0.03333333507180214f) {
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
            if (func_L01_003F9498(&obj->pos, radius, 0, obj) != 0) {
                hit = 1;
                k = func_003D00C0();
                g = D_L39_0025F840.f18;
                if (g != 0 && (g->hAA == 0x107C || g->hAA == 0x107E)) {
                    if (fabs_asm(func_L39_0061B038(g)->f310) > 0.03333333507180214f) {
                        state = 3;
                    }
                }
                func_00388830(&normal, &D_L39_0025F840.v40, 1.0f);
                if (k == 13 || k == 11 || k == 3) {
                    state = 3;
                } else if (state != 3 && normal.z > 0.7f && k != 12) {
                    state = 2;
                } else if (state == 0) {
                    state = 1;
                }
                *(vu0_q *)&obj->pos = *(vu0_q *)&D_L39_0025F840.v30;
            }
        }
        if (func_L01_003FBAF8(&obj->pos, radius, 0) != 0) {
            *(vu0_q *)&obj->pos = *(vu0_q *)&D_L39_0025F840.v30;
            hit = 1;
        }
        if (hit == 0) {
            break;
        }
    }
    obj->pos.z -= height;
    if (obj->pos.z <= D_L39_0024BD30) {
        state = 4;
    }
    for (i = 0; i < nlist; i++) {
        list[i]->f98 = list[i]->f24->f10;
    }
    return state;
}
/* localdecomp:end func_L39_00554508 */
