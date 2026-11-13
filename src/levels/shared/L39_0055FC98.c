#include "common.h"

/* localdecomp:start func_L39_0055FC98 */
typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u8 b[8];
    u32 w[2];
    u16 h[4];
} Buf_0055FC98;
typedef struct {
    u8 pad0[0x98];
    s32 f98;
} R_0055FC98;
typedef struct {
    u8 pad0[0x200];
    u32 f200;
    u8 pad204[0x22C - 0x204];
    s32 team;
    s32 f230;
    u8 pad234[0x258 - 0x234];
    R_0055FC98 *r;
} S_0055FC98;
typedef struct {
    u8 pad0[0x2548];
    s32 team;
} T_0055FC98;
typedef struct {
    s32 f0;
    u8 pad4[0x2D0 - 4];
    u8 *f2D0;
    u8 pad2D4[4];
    T_0055FC98 *f2D8;
    T_0055FC98 *f2DC;
} Q_0055FC98;
extern u8 D_L39_004997E0[];
extern void *func_L39_0055FAE8(void *, void *, void *);
extern u32 func_L39_0061D780(void *);
extern u8 *func_L39_0061D7B0(void *);
extern Q_0055FC98 *func_L39_00668620(s32);
u32 func_L39_0055FC98(u8 *a0, s32 a1) {
    S_0055FC98 *s = *(S_0055FC98 **)(a0 + 0x68);
    u8 vec[16] __attribute__((aligned(16)));
    void *list[12];
    u32 buf[2];
    u8 *b;
    s32 i2;
    s32 team = s->team;
    u32 w = s->f200;
    void *e;
    u8 *o;
    Q_0055FC98 *q;
    s32 n;
    u8 *p1;
    u8 *p2;
    long t1;
    long t2;
    s32 x;
    s32 i;
    s32 saved;
    u32 id;

    *(u128_t *)vec = *(u128_t *)(a0 + 0x10);
    *(f32 *)(vec + 8) = *(f32 *)(vec + 8) + 0.5f;
    if (w != 0xFFFFFFFF && a1 == 0) {
        return 0xFFFFFFFF;
    }
    if (team == -2) {
        return 0xFFFFFFFF;
    }
    saved = s->r->f98;
    s->r->f98 = 0;
    n = 0;
    e = func_L39_0055FAE8(a0, s, vec);
    if (e != 0) {
        list[0] = e;
        n = 1;
    }
    s->r->f98 = saved;
    if (e == 0) {
        return 0xFFFFFFFF;
    }
    for (i = 0; i < n; i++) {
        e = list[i];
        if (e == 0) {
            return 0xFFFFFFFF;
        }
        id = func_L39_0061D780(e);
        o = func_L39_0061D7B0(e);
        if (o == 0) {
            continue;
        }
        switch (o[3] & 0xF) {
        case 0:
            if (s->f230 != 0) {
                continue;
            }
            if (*(s32 *)(o + 0x2548) == team) {
                continue;
            }
            p1 = o + 0x19E6;
            x = 0;
            t1 = *p1;
            if (t1 != 0) {
                s32 m;
                s32 k;
                s32 n = *p1;
                m = n + 1;
                k = ((s32)p1 - n) & 7;
                b = (u8 *)buf;
                for (i2 = 0; i2 < 40; i2 += 5) {
                    *b++ = D_L39_004997E0[m + ((k + i2) & 7) * 255];
                }
                buf[0] ^= (u32)p1;
                buf[1] ^= buf[0];
                x = buf[1];
            }
            if ((x ^ 0x14) == 0) {
                continue;
            }
            p2 = o + 0x19E4;
            x = 0;
            t2 = *p2;
            if (t2 != 0) {
                s32 m;
                s32 k;
                s32 n = *p2;
                m = n + 1;
                k = ((s32)p2 - n) & 7;
                b = (u8 *)buf;
                for (i2 = 0; i2 < 40; i2 += 5) {
                    *b++ = D_L39_004997E0[m + ((k + i2) & 7) * 255];
                }
                buf[0] ^= (u32)p2;
                buf[1] ^= buf[0];
                x = buf[1];
            }
            if ((x ^ 0x31) == 0) {
                continue;
            }
            if (id != 0xFFFFFFFF) {
                return *(s32 *)o;
            }
            break;
        case 3:
            q = func_L39_00668620((s32)e);
            if (q->f2D0[0xBC] == 7) {
                continue;
            }
            if (q->f2D0[0xBC] == 10) {
                continue;
            }
            if (q->f2D8 == 0) {
                if (q->f2DC == 0) {
                    continue;
                }
            } else if (q->f2D8->team == team) {
                continue;
            }
            if (q->f2DC != 0 && q->f2DC->team == team) {
                continue;
            }
            return q->f0;
        case 1:
        case 2:
        case 4:
        case 5:
        case 6:
        case 7:
            break;
        }
    }
    return 0xFFFFFFFF;
}
/* localdecomp:end func_L39_0055FC98 */

/* localdecomp:start func_L39_0055FF88 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_0055FF88;
typedef struct {
    u8 pad0[0x19E6];
    u8 b19E6;
    u8 pad19E7[0x2548 - 0x19E7];
    s32 f2548;
} U_0055FF88;
typedef struct {
    u8 pad0[0x10];
    V4_0055FF88 pos;
    u8 pad20[0x90 - 0x20];
    U_0055FF88 *f90;
    u8 pad94[0xBC - 0x94];
    u8 bBC;
} O_0055FF88;
typedef struct {
    u8 pad0[0x2D0];
    O_0055FF88 *f2D0;
    u8 pad2D4[4];
    void *f2D8;
    void *f2DC;
} E_0055FF88;
typedef struct O2_0055FF88 O2_0055FF88;
typedef struct {
    u8 pad0[0x10];
    O_0055FF88 *(*fn)(O2_0055FF88 *);
} VT_0055FF88;
struct O2_0055FF88 {
    u8 pad0[0x14];
    VT_0055FF88 *vt;
};
typedef struct {
    u8 pad0[0x200];
    u32 f200;
    u8 pad204[8];
    f32 f20C;
    u8 pad210[0x22C - 0x210];
    s32 f22C;
    u8 pad230[0x254 - 0x230];
    f32 f254;
} C_0055FF88;
typedef struct {
    u8 pad0[0x10];
    V4_0055FF88 f10;
    u8 pad20[0x68 - 0x20];
    C_0055FF88 *f68;
} A_0055FF88;

extern u8 D_L39_004997E0[];
extern E_0055FF88 *func_L39_006685D8(u32);
extern O2_0055FF88 *func_L39_0061D1D8(u32);
extern s32 func_L39_006481F8(void *);
extern f32 func_L01_0040E548(void *, void *);
extern s32 func_L39_0055D7F8(void *);
extern u32 func_L39_0055FC98(u8 *, s32);

s32 func_L39_0055FF88(A_0055FF88 *a0) {
    C_0055FF88 *ctx = a0->f68;
    V4_0055FF88 pos;
    O_0055FF88 *obj = 0;
    u32 w = ctx->f200;
    s32 type = (w >> 24) & 0xF;

    pos = a0->f10;
    if (type == 3) {
        E_0055FF88 *e = func_L39_006685D8(w);
        s32 a = func_L39_006481F8(e->f2D8);
        s32 b = func_L39_006481F8(e->f2DC);
        if (e->f2D0->bBC == 7 || e->f2D0->bBC == 10 || (e->f2D8 == 0 && e->f2DC == 0) || (a == 0 && b == 0)) {
            w = -1;
            obj = 0;
        } else {
            obj = e->f2D0;
        }
    } else {
        O2_0055FF88 *q = func_L39_0061D1D8(ctx->f200);
        U_0055FF88 *u;
        s32 cur;
        u8 *p;
        u32 v;
        if (q != 0) {
            obj = q->vt->fn(q);
        }
        if (obj == 0 || type != 0) {
            goto fail;
        }
        u = obj->f90;
        cur = ctx->f22C;
        if (u == 0) {
            goto fail;
        }
        p = &u->b19E6;
        if (u->b19E6 == 0) {
            v = 0;
        } else {
            u8 buf[8];
            u8 *dst = buf;
            s32 i;
            s32 x;
            s32 k;
            k = u->b19E6 + 1;
            v = u->b19E6;
            x = ((s32)p - v) & 7;
            for (i = 0; i < 40; i += 5) {
                *dst++ = D_L39_004997E0[k + ((x + i) & 7) * 255];
            }
            ((u32 *)buf)[0] ^= (u32)p;
            ((u32 *)buf)[1] ^= ((u32 *)buf)[0];
            v = ((u32 *)buf)[1];
        }
        if ((v ^ 0x14) != 0 && u->f2548 != cur && func_L39_006481F8(u) != 0) {
            goto done;
        }
fail:
        w = -1;
        obj = 0;
done:;
    }
    if (obj != 0) {
        f32 d = func_L01_0040E548(&obj->pos, &pos);
        if (func_L39_0055D7F8(obj) == 0 ? ctx->f254 < d : ctx->f20C < d) {
            w = -1;
        }
    }
    if (w == -1) {
        w = func_L39_0055FC98((u8 *)a0, 1);
    }
    return w;
}
/* localdecomp:end func_L39_0055FF88 */
