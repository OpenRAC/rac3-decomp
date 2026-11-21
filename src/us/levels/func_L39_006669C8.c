#include "common.h"

/* NTSC-U counterpart of func_L39_006692A0 (src/levels/shared/L39_00668D60.c): 26 -> 31 */
extern void func_L39_00664930(void *, u32, s32, s32);
extern s32 func_L39_006197F0(void *);

/* localdecomp:start func_L39_006669C8 */
typedef int Q_006692A0 __attribute__((mode(TI)));
typedef union V_006692A0 {
    Q_006692A0 q;
    f32 f[4];
} V_006692A0;
typedef union Buf_006692A0 {
    u8 b[8];
    u32 w[2];
    f32 f[2];
} Buf_006692A0;
typedef struct Obj_006692A0 {
    u8 pad0[0x10];
    V_006692A0 v10;
    u8 pad20[0xAA - 0x20];
    s16 hAA;
    u8 padAC[0xBC - 0xAC];
    u8 bBC;
    u8 padBD[3];
    V_006692A0 vC0;
    V_006692A0 vD0;
    V_006692A0 vE0;
    V_006692A0 vF0;
} Obj_006692A0;
typedef struct Sub2530_006692A0 { u8 pad0[0x27B]; u8 b27B; } Sub2530_006692A0;
typedef struct Sub2534_006692A0 { u8 pad0[0x1A4]; s32 w1A4; } Sub2534_006692A0;
typedef struct Plr_006692A0 {
    s32 w0;
    u8 pad4[0x20 - 0x4];
    V_006692A0 v20;
    V_006692A0 v30;
    V_006692A0 v40;
    u8 pad50[0xA0 - 0x50];
    V_006692A0 vA0;
    V_006692A0 vB0;
    u8 padC0[0x2CC - 0xC0];
    Obj_006692A0 *p2CC;
    u8 pad2D0[0x2F0 - 0x2D0];
    s32 w2F0;
    u8 pad2F4[0x19E4 - 0x2F4];
    u8 b19E4;
    u8 pad19E5;
    u8 b19E6;
    u8 pad19E7[0x2450 - 0x19E7];
    s32 w2450;
    u8 pad2454[0x2476 - 0x2454];
    u8 b2476;
    u8 pad2477[0x24C9 - 0x2477];
    u8 b24C9;
    u8 pad24CA[0x251C - 0x24CA];
    s32 w251C;
    u8 pad2520[0x252C - 0x2520];
    void *p252C;
    Sub2530_006692A0 *p2530;
    Sub2534_006692A0 *p2534;
    u8 pad2538[0x2544 - 0x2538];
    s32 w2544;
    s32 w2548;
    s32 w254C;
    s32 w2550;
} Plr_006692A0;
typedef struct Slf_006692A0 {
    u8 pad0[0x2D0];
    Obj_006692A0 *o2D0;
    u8 pad2D4[4];
    Plr_006692A0 *p2D8;
    Plr_006692A0 *p2DC;
    u8 pad2E0[0x2F8 - 0x2E0];
    s32 w2F8;
    s16 h2FC;
    u8 pad2FE[0x308 - 0x2FE];
    f32 f308;
    u8 pad30C[0x328 - 0x30C];
    s32 w328;
} Slf_006692A0;
typedef struct Ent_006692A0 {
    s32 w0;
    s32 w4;
    s32 w8;
    u8 padC[0x1C - 0xC];
} Ent_006692A0;
typedef struct Fn_006692A0 {
    u8 pad0[0xC];
    void (*fC)(void *);
    u8 pad10[0x1C - 0x10];
} Fn_006692A0;
typedef struct G_006692A0 {
    u8 pad0[0x16C];
    s32 w16C;
    u8 pad170[0x6AC - 0x170];
    u8 b6AC;
} G_006692A0;
typedef struct Cnt_006692A0 { s32 count; } Cnt_006692A0;

extern u8 D_L39_004998A0[];
extern Cnt_006692A0 *D_L39_002412A0;
extern G_006692A0 D_001A5E50;
extern Ent_006692A0 D_L39_00484160[];
extern Fn_006692A0 D_L39_0033AC08_006669C8[];

extern Plr_006692A0 *func_L39_006197C0(s32);
extern void func_L39_00665D88(void *, void *, s32);
extern void func_L39_00664E28(void *, void *, s32);
extern void func_L01_0045D318(void *);
extern void func_L39_0061A850(void *, void *, void *, s32, s32);
extern void func_L39_0061EBD0(void *);
extern f32 func_L01_0040C040(void *, void *);
extern void func_L01_0044ECE0(s32, s32, s32);

static __inline__ u32 decU_006692A0(u8 *q) {
    Buf_006692A0 buf;
    s32 n, k, m, i;
    u8 *d;
    u32 r;

    if (*q == 0) {
        r = 0;
    } else {
        n = *q;
        k = ((u32)q - n) & 7;
        m = n + 1;
        d = buf.b;
        for (i = 0; i < 40; i += 5) {
            *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
        }
        buf.w[0] ^= (u32)q;
        buf.w[1] ^= buf.w[0];
        r = buf.w[1];
    }
    return r;
}

static __inline__ f32 decF_006692A0(u8 *q) {
    Buf_006692A0 buf;
    s32 n, k, m, i;
    u8 *d;
    f32 r;

    if (*q == 0) {
        r = 0.0f;
    } else {
        n = *q;
        k = ((u32)q - n) & 7;
        m = n + 1;
        d = buf.b;
        for (i = 0; i < 40; i += 5) {
            *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
        }
        buf.w[0] ^= (u32)q;
        buf.w[1] ^= buf.w[0];
        r = buf.f[1];
    }
    return r;
}

static __inline__ u8 isDead_006692A0(Plr_006692A0 *g) {
    return decU_006692A0(&g->b19E6) == 0x14;
}

static __inline__ s32 isState_006692A0(Plr_006692A0 *g, u32 st) {
    u8 r;

    if (g->p2530 != 0) {
        r = 0;
        if (g->p2530->b27B != 0 && (decU_006692A0(&g->b19E4) ^ st) == 0) {
            r |= 1;
        }
    } else {
        r = 0;
    }
    return r;
}

static __inline__ u8 isDown_006692A0(Plr_006692A0 *g) {
    f32 z = 0.0f; if (!(decF_006692A0(&g->b2476) <= z)) return 0; return 1;
}

static __inline__ u8 isAlive_006692A0(Plr_006692A0 *g) {
    f32 z = 0.0f; if (!(decF_006692A0(&g->b2476) > z)) return 0; return 1;
}

static __inline__ u8 attach_006692A0(Slf_006692A0 *s, Plr_006692A0 *p, s32 side) {
    p->w2550 = 0;
    p->p252C = s;
    func_L39_00664930(s, p->w0, side, D_001A5E50.w16C);
    return 1;
}

void func_L39_006669C8(Slf_006692A0 *s, u8 *done) {
    f32 vec[4] __attribute__((aligned(16)));
    Plr_006692A0 *p;
    s32 r;
    s32 i;
    s32 t;

    r = func_L39_006197F0(s->p2D8);
    if (r >= 0) {
        p = func_L39_006197C0(r);
        if ((p->w2F0 >= 0x1F && s->o2D0->bBC != 0xB && (p->p2534->w1A4 & 0x10)) || isDown_006692A0(p) ||
            (u8)isState_006692A0(p, 0x31)) {
            func_L39_00665D88(s, vec, 1);
            *done = 1;
            s->w2F8 |= 2;
            func_L39_00664E28(s, p, 1);
            func_L01_0045D318(p->p2534);
            s->w328 = r + 1;
            if (!(s->w2F8 & 0x10000000)) {
                func_L39_0061A850(p, vec, &p->vB0, 1, 0);
            }
        } else if (p->w254C == 5 || p->w254C == 3) {
            if (D_L39_0033AC08_006669C8[s->h2FC].fC != 0) {
                (D_L39_0033AC08_006669C8 + s->h2FC)->fC(s->o2D0);
            }
            if (!(s->w2F8 & 0x2000000)) {
                p->w2450 = 0x1D;
            }
            if (!(s->w2F8 & 0x10000000)) {
                p->vA0.q = s->o2D0->v10.q;
                p->vB0.q = s->o2D0->vF0.q;
                p->v20.q = s->o2D0->vC0.q;
                p->v30.q = s->o2D0->vD0.q;
                p->v40.q = s->o2D0->vE0.q;
                func_L39_0061EBD0(p);
            }
        }
    }
    for (i = 0; i < D_L39_002412A0->count; i++) {
        p = func_L39_006197C0(i);
        if (*done == 0 && s->p2D8 == 0 && p->w251C == 0 && D_001A5E50.b6AC == 0 &&
            (p->p2CC == 0 || p->p2CC->hAA != 0x10C3) && p->w254C == 0 &&
            (decU_006692A0(&p->b19E4) ^ 0x31) != 0 && (decU_006692A0(&p->b19E4) ^ 0x37) != 0 &&
            ((t = D_L39_00484160[p->w2544].w0) == 0 || t == 7) &&
            (s->p2DC == 0 || s->p2DC->w2548 == p->w2548) &&
            isAlive_006692A0(p) && s->f308 > 0.0f &&
            (!(s->w2F8 & 0x400) || ((s->w2F8 & 0x100) && p->w2548 == 0) || ((s->w2F8 & 0x200) && p->w2548 == 1)) &&
            !isDead_006692A0(p) &&
            (((s->w2F8 & 0x1000000) && s->o2D0->v10.f[2] - 2.5f <= p->vA0.f[2] && p->vA0.f[2] <= s->o2D0->v10.f[2] + 3.0f &&
              func_L01_0040C040(&s->o2D0->v10, &p->vA0) < 8.0f) ||
             (!(s->w2F8 & 0x1000000) && s->o2D0->v10.f[2] - 2.5f <= p->vA0.f[2] && p->vA0.f[2] <= s->o2D0->v10.f[2] + 3.0f &&
              func_L01_0040C040(&s->o2D0->v10, &p->vA0) < 20.0f))) {
            D_L39_00484160[p->w2544].w0 = 7;
            D_L39_00484160[p->w2544].w8 = 10;
            D_L39_00484160[p->w2544].w4 = 0;
            if (s->w2F8 & 0x1000000) {
                func_L01_0044ECE0(0x8C5, 4, p->b24C9);
            } else {
                func_L01_0044ECE0(0x8C2, 4, p->b24C9);
            }
            if (p->p2534->w1A4 & 0x10) {
                p->w254C = 1;
                attach_006692A0(s, p, 0);
            }
        }
        if (s->p2D8 != 0 && D_001A5E50.b6AC == 0 && !(s->w2F8 & 0x100000) && s->p2D8->w2548 == p->w2548 &&
            (p->p2CC == 0 || p->p2CC->hAA != 0x10C3) && s->p2DC == 0 &&
            (decU_006692A0(&p->b19E4) ^ 0x31) != 0 && (decU_006692A0(&p->b19E4) ^ 0x37) != 0 && p->w254C == 0 &&
            isAlive_006692A0(p) && s->f308 > 0.0f &&
            (!(s->w2F8 & 0x400) || ((s->w2F8 & 0x100) && p->w2548 == 0) || ((s->w2F8 & 0x200) && p->w2548 == 1)) &&
            !isDead_006692A0(p) &&
            ((t = D_L39_00484160[p->w2544].w0) == 0 || t == 7) &&
            s->o2D0->v10.f[2] - 2.5f <= p->vA0.f[2] && p->vA0.f[2] <= s->o2D0->v10.f[2] + 3.0f &&
            func_L01_0040C040(&s->o2D0->v10, &p->vA0) < 20.0f) {
            D_L39_00484160[p->w2544].w0 = 7;
            D_L39_00484160[p->w2544].w8 = 10;
            D_L39_00484160[p->w2544].w4 = 0;
            func_L01_0044ECE0(0x8C3, 4, p->b24C9);
            if (p->p2534->w1A4 & 0x10) {
                p->w254C = 2;
                *done = attach_006692A0(s, p, 1);
            }
        }
        if (s->p2D8 == p && (p->p2534->w1A4 & 2) && (s->o2D0->hAA == 0x107C || s->o2D0->hAA == 0x107E) &&
            s->o2D0->bBC != 0xB && s->o2D0->bBC != 10 && p->w254C != 3 && s->p2DC == 0) {
            p->w254C = 3;
            *done = attach_006692A0(s, p, 1);
        }
        if (s->p2DC == p && p->w251C == 0 && (p->p2534->w1A4 & 2) && s->o2D0->bBC != 0xB &&
            s->o2D0->bBC != 10 && p->w254C != 4 && (s->o2D0->hAA == 0x107C || s->o2D0->hAA == 0x107E) &&
            s->p2D8 == 0) {
            p->w254C = 4;
            *done = attach_006692A0(s, p, 0);
        }
    }
}
/* localdecomp:end func_L39_006669C8 */
