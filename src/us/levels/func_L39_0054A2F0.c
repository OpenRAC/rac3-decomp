#include "common.h"

/* NTSC-U counterpart of func_L39_0054AC10 (src/levels/shared/L39_0054AC10.c) */
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0x21];
    s8 b21;
    u8 pad22[0x28 - 0x22];
    f32 f28;
    u8 pad2C[0x80 - 0x2C];
} T_0054A250;
extern f32 *func_0037E0B8(void *);
extern s32 func_L39_00646268(void *, s32);
extern u8 D_L39_004998A0[];
extern T_0054A250 D_L39_0049C950[];
extern s32 D_L39_003BDE20[][24];

/* localdecomp:start func_L39_0054A2F0 */
#include "vu0.h"

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_0054AC10;

typedef struct {
    s32 team;
    s32 w4;
    u8 pad8[0xC30];
    s32 wC38;
} I_0054AC10;

typedef struct {
    s32 w0;
    u8 pad4[0x9C];
    V4_0054AC10 pos;
    u8 padB0[0x3A0 - 0xB0];
    V4_0054AC10 v3A0;
    u8 pad3B0[0x1310 - 0x3B0];
    s32 w1310;
    u8 pad1314[0x19E4 - 0x1314];
    u8 chk;
    u8 pad19E5[0x1A08 - 0x19E5];
    u8 b1A08;
    u8 pad1A09[0x1A14 - 0x1A09];
    u8 b1A14;
    u8 pad1A15[0x2524 - 0x1A15];
    u8 *w2524;
    u8 pad2528[0x2544 - 0x2528];
    s32 w2544;
    s32 w2548;
    u8 pad254C[0x2558 - 0x254C];
    I_0054AC10 *info;
} Pl_0054AC10;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
    struct M_0054AC10 *w0C;
    struct M_0054AC10 *target;
    f32 f14;
    f32 f18;
    f32 f1C;
    f32 f20;
    s16 h24;
    u8 b26;
    u8 b27;
    f32 f28;
    s32 slot;
    V4_0054AC10 v30;
    V4_0054AC10 v40;
    s32 w50;
    u8 pad54[4];
    u8 *owner;
    f32 f5C;
    f32 f60;
    s32 w64;
    s32 w68;
    u8 pad6C;
    u8 b6D;
    u8 pad6E;
    u8 b6F;
} P_0054AC10;

typedef struct M_0054AC10 {
    u8 pad0[0x10];
    V4_0054AC10 pos;
    u8 state;
    u8 pad21[0xB];
    f32 scale;
    u8 b30;
    u8 b31;
    s16 h32;
    u16 h34;
    u8 pad36[0x32];
    P_0054AC10 *vars;
    u8 pad6C[0x24];
    s32 w90;
    u8 pad94[0x24];
    struct M_0054AC10 *parent;
    u8 bBC;
    u8 padBD[3];
    V4_0054AC10 mat[3];
} M_0054AC10;

extern u8 *func_003BCFB0(s32, s32);
extern u8 *func_L39_0061B038(void *);
extern f32 func_003887C8(void *, void *);
extern void func_003886E8(u128_t *, u128_t *, f32);
extern void func_00388830(void *, void *, f32);
extern void func_00388758(void *, void *, void *);
extern void func_L39_005FD3D8(u8 *, f32 *, void *, f32, f32, f32);
extern f32 func_L39_005B2510(f32, f32);
extern f32 func_L39_005B2568(f32, f32);
extern f32 func_L39_005B25C8_0054A2F0(void);
extern void func_L39_005BA378(void *, void *, s32);
extern f32 func_00388730(void *, void *);
extern void func_L39_005FD658(s32);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern void func_L39_005FD6D8(void);
extern void func_L01_003988D0(u8 *a0, u8 *a1);
extern void func_003C26C8(void *);
extern void func_L01_00448BD8(void *p, short *a, short n);
extern s32 func_L39_005FCD98(void *, void *, f32, f32, f32);
extern void func_0014AA48(u32 *, s32);

extern u32 D_L39_0024B188_0054A2F0 __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024B188_0054A2F0, 4");
typedef struct {
    u8 pad0[0x21];
    s8 b21;
    u8 pad22[2];
    f32 f24;
    u8 pad28[0x58];
} T_0054AC10;
extern u8 D_L39_004998A0[];

static __inline__ T_0054AC10 *Entry_0054AC10(s32 i) {
    return &((T_0054AC10 *)D_L39_0049C950)[i];
}
extern s32 D_L39_00242B3C;
__asm__(".extern D_L39_00242B3C, 16");
extern Pl_0054AC10 *D_L39_0024CF20_0054A2F0[2] __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024CF20_0054A2F0, 16");
extern V4_0054AC10 D_L39_0025F860;
extern u8 D_L39_003BE120[];
extern short D_L39_0024C140[] __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024C140, 16");

static __inline__ s32 Check_0054AC10(Pl_0054AC10 *g) {
    s16 flag = 0;

    if (g != 0) {
        u32 buf[2];
        u8 *b;
        u8 *p = &g->chk;
        s32 x = 0;
        s32 i;
        long t;

        t = *p;
        if (t != 0) {
            s32 n = *p;
            s32 m = n + 1;
            s32 k = ((s32)p - n) & 7;
            b = (u8 *)buf;
            for (i = 0; i < 40; i += 5) {
                *b++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
            }
            buf[0] ^= (u32)p;
            buf[1] ^= buf[0];
            x = buf[1];
        }
        if ((x ^ 0x92) != 0) {
            I_0054AC10 *q = g->info;
            if (q != 0) {
                if (q->w4 != 0) {
                    flag++;
                }
            }
        }
    }
    return (u8)flag;
}

static __inline__ s32 Dead_0054AC10(Pl_0054AC10 *p) {
    return p->b1A14 != 0;
}

static __inline__ void vcopy_0054AC10(void *d, void *s) {
    *(vu0_q *)d = *(vu0_q *)s;
}

static __inline__ s32 Los_0054AC10(void *from, void *to, u8 *ignore, s32 team) {
    s32 hit;

    func_L39_005FD658(team);
    hit = func_003CE740(from, to, 0, ignore, 0);
    func_L39_005FD6D8();
    return hit;
}

M_0054AC10 *func_L39_0054A2F0(M_0054AC10 *a0, V4_0054AC10 *a1, M_0054AC10 *a2, V4_0054AC10 a3, Pl_0054AC10 *a4, s32 a5, f32 f12, f32 f13) {
    M_0054AC10 *m;
    P_0054AC10 *vars;
    Pl_0054AC10 *t;
    f32 scale;
    f32 sq;
    T_0054AC10 *e;
    s32 cnt;
    u8 *r0;
    u8 *r1;
    V4_0054AC10 *p30;
    u8 *r2;

    if (a4 == 0) {
        return 0;
    }
    m = (M_0054AC10 *)func_003BCFB0(0x108C, 0x80);
    if (m != 0) {
    m->b30 = 0xFF;
    m->b31 = 1;
    m->state = 0;
    m->h32 = 0xFF;
    m->h34 |= 0x100;
    m->parent = a0;
    vars = m->vars;
    if (D_L39_0024B188_0054A2F0 >= 0xC1) {
        D_L39_0024B188_0054A2F0 = 0;
    }
    cnt = D_L39_0024B188_0054A2F0;
    vars->slot = cnt;
    D_L39_0024B188_0054A2F0 = (s32)(cnt + 1) % 192;
    vars->owner = (u8 *)a4;
    m->w90 = a4->w0;
    if (func_L39_00646268((u8 *)a4, 4) != 0) {
        e = Entry_0054AC10(Entry_0054AC10(4)->b21);
    } else {
        e = Entry_0054AC10(4);
    }
    scale = e->f24 * 0.016666668f;
    vars->w68 = -1;
    vars->w64 = -1;
    if (a4->b1A14 != 0) {
        func_L39_0054A238(a5);
    }
    r0 = (u8 *)&m->mat[0];
    r1 = (u8 *)&m->mat[1];
    r2 = (u8 *)&m->mat[2];
    p30 = &vars->v30;
    sq = f13 * f13;
    if (a2 != 0) {
        u8 *r = func_L39_0061B038(a2);

        t = 0;
        if (r != 0 && (r[3] & 0xF) == 0) {
            t = (Pl_0054AC10 *)r;
        }
        if (t != 0) {
            if (Check_0054AC10(a4) && a5 != -1) {
                s32 team = a4->info->team;
                vars->w64 = a5;
                vars->w68 = team;
                D_L39_003BDE20[team][a5] = (s32)m;
            }
            if (t->b1A14 == 0 && Check_0054AC10(t)) {
                f32 d = func_003887C8(&t->pos, a1);

                if (d > 6.0f) {
                    u32 tmp = 0;
                    f32 r6;
                    f32 c;
                    f32 c2;
                    f32 lim;

                    func_0014AA48(&tmp, t->info->team);
                    r6 = 6.0f / d;
                    tmp += (s32)((f32)(t->info->wC38 * 4) * 16.666666f);
                    c = r6 * 3.0f;
                    if (c > 3.0f) {
                        c = 3.0f;
                    }
                    c2 = ((f32)tmp * 60.0f / 1000.0f + c) / d;
                    if (c2 > 0.6f / scale) {
                        vars->b6F = 1;
                    }
                    lim = 0.65f / scale;
                    if (c2 > lim) {
                        c2 = lim;
                    }
                    scale = 1.0f / (1.0f / scale + c2);
                } else {
                    vars->b6F = 1;
                }
            } else if (Dead_0054AC10(t)) {
                vars->b6D = 1;
            }
        }
    }
    m->pos = *a1;
    {
        V4_0054AC10 v10;
        V4_0054AC10 v20;
        V4_0054AC10 v30;

        if (a2 != 0) {
            func_003886E8((u128_t *)&v20, (u128_t *)&a2->mat[2], f12);
            vec_add_ba(&v10, &a2->pos, &v20);
        } else {
            qzero(&v10);
        }
        if (a2 != 0) {
            vec_sub_ab(&m->mat[0], &v10, &m->pos);
            func_00388830(r0, r0, 1.0f);
            func_00388758(r1, r0, a4->w2524 + 0xE0);
            func_00388830(r1, r1, 1.0f);
            func_00388758(r2, r1, r0);
        } else {
            m->mat[0] = a3;
            if (a4->w1310 != 0 && a4->b1A08 == 0) {
                func_L39_005FD3D8((u8 *)a4, (f32 *)(r0), a1, 1.0f, 75.0f, 0.52359879f);
            }
            func_00388758(r1, r0, &a4->v3A0);
            func_00388830(r1, r1, 1.0f);
            func_00388758(r2, r1, r0);
        }
    m->mat[0].w = m->mat[1].w = m->mat[2].w = 0.0f;
    vars->f60 = sq;
    vars->w0C = a0;
    vars->f1C = func_L39_005B2510(2.0f, 5.0f);
    if (a2 != 0) {
        vars->f1C = 0.0f;
    }
    vars->f20 = func_L39_005B2568(6.0f, 10.0f);
    vars->f18 = scale;
    vars->f28 = func_L39_005B25C8_0054A2F0();
    vars->target = a2;
    vars->b27 = 1;
    vars->b26 = 1;
    vars->f5C = 3.0f;
    if (a4->b1A14 != 0) {
        vars->f5C = 1.0f;
    }
    vcopy_0054AC10(&vars->v30, &m->mat[0]);
    qzero(&vars->v40);
    if (D_L39_00242B3C != 0) {
        f32 k;

        func_L39_005BA378(&m->pos, &v20, 1);
        k = func_00388730(&v20, p30);
        func_003886E8((u128_t *)&v30, (u128_t *)&v20, k);
        vec_sub_ab(&vars->v30, &vars->v30, &v30);
    }
    if (a2 != 0) {
        u8 *r = (u8 *)func_0037E0B8(a2);

        if (r != 0) {
            *(u16 *)(r + 0x1E) |= 0x80;
            if (r[0xB] != 0) {
                vars->b26 = 0;
            }
        }
    }
    vars->h24 = 95.0f / scale;
    if (a2 != 0) {
        func_003886E8((u128_t *)&v20, (u128_t *)&a2->mat[2], f12);
        vec_add_ab(&v20, &a2->pos, &v20);
        vars->x = v20.x;
        vars->y = v20.y;
        vars->z = v20.z;
        vars->f14 = f12;
    }
    {
        Pl_0054AC10 *s;
        u8 *w;
        s32 k;

        v20 = a0->pos;
        v20.z = a1->z;
        k = a4->w2544;
        s = D_L39_0024CF20_0054A2F0[k];
        w = a4->w2524;
        k = -1;
        if (s != 0) {
            k = s->w2548;
        }
        if (Los_0054AC10(&v20, a1, w, k) != 0) {
            m->bBC = 1;
            m->pos = D_L39_0025F860;
        }
    }
    func_L01_003988D0((u8 *)m, D_L39_003BE120 + vars->slot * 64);
    func_003C26C8(m);
    func_L01_00448BD8(m, D_L39_0024C140, 0x1F);
    m->scale *= 2.5f;
    vars->w50 = func_L39_005FCD98(m, 0, 1.0f, 1.0f, 1.0f);
    }
    }
    return m;
}
/* localdecomp:end func_L39_0054A2F0 */
