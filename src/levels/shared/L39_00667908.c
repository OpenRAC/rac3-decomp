#include "common.h"

typedef struct { u8 pad[0x2D8]; s32 x2D8; s32 x2DC; u8 pad2E0[0x2F8 - 0x2E0]; s32 x2F8; } X_006683F8;
typedef struct { u8 pad[0x2528]; X_006683F8 *x2528; u8 pad2[0x254C - 0x252C]; s32 x254C; } P_006683F8;

/* localdecomp:start func_L39_00667908 */
typedef struct {
    u8 pad0[0x252C];
    s32 *x252C;
    u8 pad2530[0x254C - 0x2530];
    s32 x254C;
} S_00667908;

typedef struct {
    s32 count;
} T_00667908;

extern T_00667908 *D_L39_00241120;
extern S_00667908 *func_L39_0061BF38(s32);

void func_L39_00667908(s32 a, s32 b)
{
    s32 i;
    S_00667908 *p;

    for (i = 0; i < D_L39_00241120->count; i++) {
        p = func_L39_0061BF38(i);
        if (p->x254C == a && p->x252C != 0 && *p->x252C == b) {
            p->x254C = 0;
        }
    }
}
/* localdecomp:end func_L39_00667908 */

/* localdecomp:start func_L39_006679A0 */
typedef struct { s32 w0; u8 pad4[0x252C - 4]; void *x252C; u8 pad2530[0x254C - 0x2530]; s32 x254C; } P_006679A0;
typedef struct { u8 pad[0xBC]; u8 xBC; } M_006679A0;
typedef struct { u8 pad[0x2D0]; M_006679A0 *x2D0; u8 pad2D4[0x308 - 0x2D4]; f32 x308; u8 pad30C[0x324 - 0x30C]; s32 x324; u8 pad328[0x340 - 0x328]; } Q_006679A0;
typedef struct { u8 pad[0x16C]; s32 w16C; } S_006679A0;
extern s32 D_L39_002461F8;
extern char D_L39_00337700[];
extern void func_L39_00667208(void *, u32, s32, s32);
__asm__(".extern D_L39_002461F8, 4");
extern P_006679A0 *D_L39_0024CE20[] __attribute__((section(".sdata")));
extern S_006679A0 D_001A5CD0;
void func_L39_006679A0(void) {
    s32 i;
    Q_006679A0 *o;
    s32 s;
    s32 r;
    for (i = 0; i < D_L39_00241120->count; i++) {
        if (D_L39_0024CE20[i] != 0 && *((u8 *)D_L39_0024CE20[i] + 0x1A14) != 0) {
            r = 0;
            switch (D_L39_0024CE20[i]->x254C) {
            case 1:
            case 4:
                r = 0;
                break;
            case 2:
            case 3:
                r = 1;
                break;
            }
            if (r != 0) {
                if (D_L39_0024CE20[i]->x252C != 0) {
                    func_L39_00667208(D_L39_0024CE20[i]->x252C, D_L39_0024CE20[i]->w0, r, D_001A5CD0.w16C);
                } else {
                    D_L39_0024CE20[i]->x254C = 0;
                }
            }
        }
    }
    for (i = 0; i < D_L39_002461F8; i++) {
        o = &((Q_006679A0 *)D_L39_00337700)[i];
        if (o != 0 && o->x2D0 != 0 && o->x308 <= 0.0f) {
            s = o->x2D0->xBC;
            if (s != 7 && s != 9 && s != 11 && s != 10) {
                o->x324 = 0;
                func_L39_00667208(o, 0xFFFFFFFF, 6, D_001A5CD0.w16C);
            }
        }
    }
}
/* localdecomp:end func_L39_006679A0 */

/* localdecomp:start func_L39_00667B68 */
typedef struct { u8 pad[0xBC]; u8 bBC; } Sub_00667B68;
typedef struct {
    s32 id;
    u8 pad4[0x2D0 - 4];
    Sub_00667B68 *p2D0;
    u8 pad2D4[4];
    u8 *p2D8;
    u8 *p2DC;
    u8 pad2E0[8];
    s32 w2E8;
    u8 pad2EC[0x2F8 - 0x2EC];
    u32 w2F8;
    s16 s2FC;
    u8 pad2FE[0x304 - 0x2FE];
    s16 s304;
    u8 pad306[2];
    f32 f308;
    u8 pad30C[0x31C - 0x30C];
    s32 w31C;
    s32 w320;
    u8 pad324[0x340 - 0x324];
} O_00667B68;
typedef struct { u8 pad[0x27B]; u8 b27B; } P2530_00667B68;
typedef struct { s32 w0; } P2558_00667B68;
typedef struct {
    u8 pad0[0x19E4];
    u8 b19E4;
    u8 pad19E5;
    u8 b19E6;
    u8 pad19E7[0x1A14 - 0x19E7];
    u8 b1A14;
    u8 pad1A15[0x2476 - 0x1A15];
    u8 b2476;
    u8 pad2477[0x24C9 - 0x2477];
    u8 b24C9;
    u8 pad24CA[0x2530 - 0x24CA];
    P2530_00667B68 *p2530;
    u8 pad2534[0x254C - 0x2534];
    s32 s254C;
    u8 pad2550[8];
    P2558_00667B68 *p2558;
} G_00667B68;
typedef struct { u32 w0; u8 pad4[4]; s32 w8; } M_00667B68;
typedef struct { void (*fn)(void *); } Dummy_00667B68;
typedef struct { u8 pad[0x18]; void (*fn18)(void *); } T_00667B68;
typedef union { u8 b[8]; u32 w[2]; f32 f[2]; } Buf_00667B68;

extern T_00667B68 D_L39_0033AB08[];
extern u8 D_L39_004997E0[];
extern s32 D_001DAAF4_sda;
__asm__(".extern D_001DAAF4_sda, 4");
__asm__(".extern D_L39_002461F8, 4");
extern s32 D_001A5DF8[];
extern s32 D_001A5E3C[];
extern void func_L39_00662B18(void *, void *, s32);
extern G_00667B68 *func_L39_0061BFB0(u32);
extern O_00667B68 *func_L39_006685D8(s32);
extern void func_L39_006673E8(void *, void *, s32);
extern void func_L39_00667540(void *, void *);
extern void func_L39_00667700(void *, void *, s32);
extern void func_L39_006672C0(void *, void *);
extern void func_00382810(s32, s32, s32, f32, f32, f32, f32);


static __inline__ u32 decU_00667B68(u8 *q) {
    Buf_00667B68 buf;
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
            *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
        }
        buf.w[0] ^= (u32)q;
        buf.w[1] ^= buf.w[0];
        r = buf.w[1];
    }
    return r;
}

static __inline__ f32 decF_00667B68(u8 *q) {
    Buf_00667B68 buf;
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
            *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
        }
        buf.w[0] ^= (u32)q;
        buf.w[1] ^= buf.w[0];
        r = buf.f[1];
    }
    return r;
}

static __inline__ u8 isDead_00667B68(G_00667B68 *g) {
    return decU_00667B68(&g->b19E6) == 0x14;
}

static __inline__ u8 isAlive_00667B68(G_00667B68 *g) {
    f32 z = 0.0f; if (!(decF_00667B68(&g->b2476) > z)) return 0; return 1;
}

void func_L39_00667B68(s32 a0, M_00667B68 *a1) {
    u32 v;
    G_00667B68 *g;
    s32 id;
    O_00667B68 *o;
    P2530_00667B68 *q;
    u8 host;

    id = a1->w8;
    func_L39_00662B18(a1, &v, 4);
    g = func_L39_0061BFB0(v);
    switch (a1->w0 & 0xF) {
    case 9: {
        O_00667B68 *p;
        s32 j;
        for (j = 0; j < D_L39_002461F8; j++) {
            p = &((O_00667B68 *)D_L39_00337700)[j];
            if (p->s304 == v) {
                p->id = id;
                return;
            }
        }
        break;
    }
    case 15: {
        f32 f;
        o = func_L39_006685D8(id);
        f = (f32)v;
        if (f < o->f308) {
            if (D_L39_0033AB08[o->s2FC].fn18 != 0) {
                (D_L39_0033AB08 + o->s2FC)->fn18(o->p2D0);
            }
            o->f308 = f;
        }
        break;
    }
    case 14:
        o = func_L39_006685D8(id);
        if (o->p2D0->bBC == 0) {
            o->p2D0->bBC = 11;
            o->w2E8 = 150;
        }
        break;
    case 6: {
        s32 s = D_001A5DF8[0] + D_001DAAF4_sda;
        o = func_L39_006685D8(id);
        if (o->p2D0->bBC == 0) {
            func_L39_00667208((void *)o, s, 7, -1);
        }
        break;
    }
    case 7:
        o = func_L39_006685D8(id);
        if (o->p2D0->bBC == 0) {
            o->p2D0->bBC = 9;
            o->w2E8 = v;
        }
        break;
    case 13:
        func_L39_00667908(2, id);
        o = func_L39_006685D8(id);
        o->w320 = 0;
        break;
    case 12:
        func_L39_00667908(1, id);
        o = func_L39_006685D8(id);
        o->w31C = 0;
        break;
    case 0:
        if (g != 0) {
            o = func_L39_006685D8(id);
            if (o->w31C <= 0 && o->p2D8 == 0) {
                o->w31C = 250;
                func_L39_00667208((void *)o, v, 10, g->p2558->w0);
            }
        }
        break;
    case 10:
        o = func_L39_006685D8(id);
        if (!isDead_00667B68(g) && isAlive_00667B68(g) && !(host = (q = g->p2530) != 0 ? (q->b27B != 0 && (decU_00667B68(&g->b19E4) ^ 0x31) == 0) : 0)
            && (g->s254C == 1 || g->s254C == 4) && o->p2D8 == 0) {
            func_L39_00667208((void *)o, v, 2, -1);
        } else {
            func_L39_00667208((void *)o, v, 12, D_001A5E3C[0]);
        }
        break;
    case 1:
        if (g != 0) {
            o = func_L39_006685D8(id);
            if (o->w320 <= 0 && o->p2DC == 0) {
                o->w320 = 250;
                func_L39_00667208((void *)o, v, 11, g->p2558->w0);
            }
        }
        break;
    case 11:
        if (g != 0) {
            o = func_L39_006685D8(id);
            if (!isDead_00667B68(g) && isAlive_00667B68(g)
                && (g->s254C == 2 || g->s254C == 3) && !(host = (q = g->p2530) != 0 ? (q->b27B != 0 && (decU_00667B68(&g->b19E4) ^ 0x31) == 0) : 0) && o->p2DC == 0) {
                func_L39_00667208((void *)o, v, 3, -1);
            } else {
                func_L39_00667208((void *)o, v, 13, D_001A5E3C[0]);
            }
        }
        break;
    case 2:
        if (g != 0) {
            func_L39_00667908(1, id);
            o = func_L39_006685D8(id);
            o->w31C = 0;
            if (o != 0 && o->p2D8 == 0) {
                if ((u8 *)g == o->p2DC) {
                    func_L39_006673E8(o, g, 0);
                }
                func_L39_00667540(o, g);
            }
        }
        break;
    case 3:
        if (g != 0) {
            func_L39_00667908(2, id);
            o = func_L39_006685D8(id);
            o->w320 = 0;
            if (o != 0 && o->p2DC == 0) {
                if (o->p2D8 == (u8 *)g) {
                    if (g->b1A14 != 0) {
                        func_00382810(g->b24C9, 30, 3, 1.1100293f, 0.005f, 0.2f, 0.0f);
                        o->w2F8 |= 2;
                    }
                    func_L39_00667700(o, g, 0);
                }
                func_L39_006672C0(o, g);
            }
        }
        break;
    case 4:
        o = func_L39_006685D8(id);
        if (o != 0) {
            func_L39_00667700(o, g, 0);
        }
        break;
    case 5:
        o = func_L39_006685D8(id);
        if (o != 0) {
            func_L39_006673E8(o, g, 0);
        }
        break;
    }
}
/* localdecomp:end func_L39_00667B68 */
