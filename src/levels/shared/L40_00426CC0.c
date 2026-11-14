#include "common.h"

/* declared by functions of L40_00426B60.c, which this file was cut from */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec4_426250;
typedef struct {
    u8 pad0[720];
    f32 *pos;
} Q426250;
typedef struct {
    u8 pad0[9508];
    f32 *pos;
    Q426250 *q;
    u8 pad252C[9544 - 9516];
    s32 team;
} P426250;
typedef struct {
    u8 pad0[16];
    s32 f10;
} V426250;
typedef struct {
    u8 pad0[36];
    V426250 *v;
    u8 pad28[152 - 40];
    s32 f98;
} A426250;
typedef struct {
    u8 pad0[596];
    f32 range;
    u8 pad258[636 - 600];
    s32 team;
} B426250;
extern s32 func_L39_006481F8(P426250 *p);
extern f32 func_L01_0040E548(void *a, void *b);
extern s32 func_L40_00424BA0(void *a, void *b, f32 *c);

/* localdecomp:start func_L40_00426CC0 */
typedef union Buf_00426CC0 {
    u8 b[8];
    u32 w[2];
} Buf_00426CC0;

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec4_00426CC0;

extern u8 D_L40_003BFE20[];
extern void func_L39_005FF198(u8 *, u8 *, f32 *);
extern void func_003C2F58(void *, s32, void *);
extern u32 func_L39_0061D780(void *);
extern u8 *func_L39_0061D7B0(void *);
extern u8 *func_L39_00668620(void *);

u32 func_L40_00426CC0(A426250 *a, s32 a1) {
    B426250 *pv = *(B426250 **)((u8 *)a + 0x68);
    u32 s20 = *(u32 *)((u8 *)pv + 0x220);
    s32 team = pv->team;
    Vec4_00426CC0 v0;
    Vec4_00426CC0 v1;
    f32 *t;
    Vec4_00426CC0 *pos;
    u32 id;
    u8 *r;

    func_L39_005FF198(0, (u8 *)a + 0x10, &v0.x);
    func_003C2F58(a, 3, &v1);
    pos = &v1;
    if (a1 == 0 && s20 != 0xFFFFFFFF) {
        return 0xFFFFFFFF;
    }
    a->f98 = 0;
    t = func_L40_00426B60(a, pv, pos);
    a->f98 = a->v->f10;
    if (t == 0) {
        return 0xFFFFFFFF;
    }
    id = func_L39_0061D780(t);
    r = func_L39_0061D7B0(t);
    if (r == 0) {
        return 0xFFFFFFFF;
    }
    switch (r[3] & 0xF) {
    case 0: {
        u32 v;

        if (id == 0xFFFFFFFF) {
            return 0xFFFFFFFF;
        }
        if (*(s32 *)(r + 0x2548) == team) {
            return 0xFFFFFFFF;
        }
        {
            u8 *q = r + 0x19E6;
            if (*q == 0) {
                v = 0;
            } else {
                Buf_00426CC0 buf;
                u32 x;
                s32 n = *q;
                s32 k = ((u32)q - n) & 7;
                s32 m = n + 1;
                s32 i;
                u8 *d = buf.b;
                for (i = 0; i < 40; i += 5) {
                    *d++ = D_L40_003BFE20[m + ((k + i) & 7) * 255];
                }
                x = buf.w[0] ^ (u32)q;
                buf.w[0] = x;
                buf.w[1] ^= x;
                v = buf.w[1];
            }
        }
        if ((v ^ 0x14) == 0) {
            return 0xFFFFFFFF;
        }
        {
            u8 *q = r + 0x19E4;
            if (*q == 0) {
                v = 0;
            } else {
                Buf_00426CC0 buf;
                u32 x;
                s32 n = *q;
                s32 k = ((u32)q - n) & 7;
                s32 m = n + 1;
                s32 i;
                u8 *d = buf.b;
                for (i = 0; i < 40; i += 5) {
                    *d++ = D_L40_003BFE20[m + ((k + i) & 7) * 255];
                }
                x = buf.w[0] ^ (u32)q;
                buf.w[0] = x;
                buf.w[1] ^= x;
                v = buf.w[1];
            }
        }
        if ((v ^ 0x31) == 0) {
            return 0xFFFFFFFF;
        }
        return *(s32 *)r;
    }
    case 3: {
        u8 *o = func_L39_00668620(t);

        if ((*(u8 **)(o + 0x2D0))[0xBC] == 7 || (*(u8 **)(o + 0x2D0))[0xBC] == 10) {
            return 0xFFFFFFFF;
        }
        if (*(u8 **)(o + 0x2D8) != 0 || *(u8 **)(o + 0x2DC) != 0) {
            if (*(u8 **)(o + 0x2D8) != 0 && *(s32 *)(*(u8 **)(o + 0x2D8) + 0x2548) == team) {
                return 0xFFFFFFFF;
            }
            if (*(u8 **)(o + 0x2DC) != 0 && *(s32 *)(*(u8 **)(o + 0x2DC) + 0x2548) == team) {
                return 0xFFFFFFFF;
            }
            return *(s32 *)o;
        }
        break;
    }
    case 1:
    case 2:
    case 4:
    case 5:
    case 6:
    case 7:
        break;
    }
    return 0xFFFFFFFF;
}
/* localdecomp:end func_L40_00426CC0 */

/* localdecomp:start func_L40_00426F68 */
/* from rac3's func_L39_0055FF88 */
typedef struct {
    u8 pad0[0x19E6];
    u8 b19E6;
    u8 pad19E7[0x2548 - 0x19E7];
    s32 f2548;
} U_00426F68;
typedef struct {
    f32 f0[4];
    Vec4_426250 pos;
    u8 pad20[0x90 - 0x20];
    U_00426F68 *f90;
    u8 pad94[0xBC - 0x94];
    u8 bBC;
} O_00426F68;
typedef struct {
    u8 pad0[0x2D0];
    O_00426F68 *f2D0;
    u8 pad2D4[4];
    void *f2D8;
    void *f2DC;
} E_00426F68;
typedef struct O2_00426F68 O2_00426F68;
typedef struct {
    u8 pad0[0x10];
    O_00426F68 *(*fn)(O2_00426F68 *);
} VT_00426F68;
struct O2_00426F68 {
    u8 pad0[0x14];
    VT_00426F68 *vt;
};
typedef struct {
    u8 pad0[0x220];
    u32 f220;
    u8 pad224[0x258 - 0x224];
    f32 f258;
    u8 pad25C[0x27C - 0x25C];
    s32 f27C;
} C_00426F68;
typedef struct {
    u8 pad0[0x24];
    V426250 *v;
    u8 pad28[0x68 - 0x28];
    C_00426F68 *f68;
    u8 pad6C[0x98 - 0x6C];
    s32 f98;
} A_00426F68;

extern u8 D_L40_003BFE20[];
extern void func_003C2F58(void *m, s32 a1, void *pos);
extern E_00426F68 *func_L39_006685D8(u32);
extern O2_00426F68 *func_L39_0061D1D8(u32);

typedef union {
    Vec4_426250 v;
    u8 b[8];
    u32 w[2];
} T_00426F68;

s32 func_L40_00426F68(A_00426F68 *a0) {
    C_00426F68 *ctx = a0->f68;
    Vec4_426250 pos;
    T_00426F68 tmp;
    O_00426F68 *obj = 0;
    u32 w = ctx->f220;
    s32 type;

    func_003C2F58(a0, 3, &pos);
    type = (w >> 24) & 0xF;
    if (type == 3) {
        E_00426F68 *e = func_L39_006685D8(w);
        s32 a = func_L39_006481F8(e->f2D8);
        s32 b = func_L39_006481F8(e->f2DC);
        if (e->f2D0->bBC == 7 || e->f2D0->bBC == 10 || (e->f2D8 == 0 && e->f2DC == 0) || (a == 0 && b == 0)) {
            w = -1;
            obj = 0;
        } else {
            obj = e->f2D0;
        }
    } else {
        O2_00426F68 *q = func_L39_0061D1D8(ctx->f220);
        U_00426F68 *u;
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
        cur = ctx->f27C;
        if (u == 0) {
            goto fail;
        }
        p = &u->b19E6;
        if (u->b19E6 == 0) {
            v = 0;
        } else {
            u8 *dst = tmp.b;
            s32 i;
            s32 x;
            s32 k;
            k = u->b19E6 + 1;
            v = u->b19E6;
            x = ((s32)p - v) & 7;
            for (i = 0; i < 40; i += 5) {
                *dst++ = D_L40_003BFE20[k + ((x + i) & 7) * 255];
            }
            tmp.w[0] ^= (u32)p;
            tmp.w[1] ^= tmp.w[0];
            v = tmp.w[1];
        }
        if ((v ^ 0x14) != 0 && u->f2548 != cur && func_L39_006481F8((P426250 *)u) != 0) {
            goto done;
        }
fail:
        w = -1;
        obj = 0;
done:;
    }
    if (obj != 0) {
        f32 d = func_L01_0040E548(&obj->pos, &pos);
        if (ctx->f258 < d) {
            w = -1;
        } else {
            tmp.v.x = obj->f0[0] * 0.0009765625f;
            tmp.v.y = obj->f0[1] * 0.0009765625f;
            tmp.v.z = obj->f0[2] * 0.0009765625f;
            tmp.v.w = 0.0f;
            a0->f98 = 0;
            if (func_L40_00424BA0(&pos, &tmp.v, (f32 *)obj) != 0) {
                w = -1;
                obj = 0;
            }
            a0->f98 = a0->v->f10;
        }
    }
    if (w == -1) {
        w = func_L40_00426CC0((A426250 *)a0, 1);
    }
    return w;
}
/* localdecomp:end func_L40_00426F68 */
