#include "common.h"

/* localdecomp:start func_L40_0053DE38 */
typedef struct {
    s32 a;
    s32 b;
    s32 c;
} E_0053DE38;

typedef struct {
    u8 pad0[0x40];
    s32 a40[8];
    s32 a60[8];
    s32 a80[2];
    s32 a88[8];
    s32 aA8[8];
} T_0053DE38;

typedef struct {
    u8 pad[0x20C];
    T_0053DE38 *p20C;
} S_0053DE38;

extern E_0053DE38 D_L40_00347AB0[];
extern S_0053DE38 D_L40_00357260;
extern u8 *D_L40_0024845C;
extern f32 func_L01_0040E548(void *, void *);
extern s32 func_L40_0053E000(f32 radius, s32 a0, u8 *a1, u8 a2);

s32 func_L40_0053DE38(s32 a0, u8 *a1, f32 radius) {
    s32 i;
    s32 r;

    for (i = 0; i < 15; i++) {
        if (D_L40_00347AB0[i].a == -1 && D_L40_00347AB0[i].b == -1) {
            return -1;
        }
        if (D_L40_00347AB0[i].a != -1) {
            T_0053DE38 *t = D_L40_00357260.p20C;
            if (t->a88[D_L40_00347AB0[i].a] != a0) {
                if (func_L01_0040E548(a1 + 0x10, D_L40_0024845C + (t->a40[D_L40_00347AB0[i].a] << 8) + 0x10) < radius) {
                    r = func_L40_0053E000(radius, a0, a1, D_L40_00347AB0[i].c);
                    if (r != -1 && r != 0) {
                        return r;
                    }
                }
            }
        } else if (D_L40_00347AB0[i].b != -1) {
            T_0053DE38 *t = D_L40_00357260.p20C;
            if (t->aA8[D_L40_00347AB0[i].b] != a0) {
                if (func_L01_0040E548(a1 + 0x10, D_L40_0024845C + (t->a60[D_L40_00347AB0[i].b] << 8) + 0x10) < radius) {
                    return func_L40_0053E000(radius, a0, a1, D_L40_00347AB0[i].c);
                }
            }
        }
    }
    return -1;
}
/* localdecomp:end func_L40_0053DE38 */

/* localdecomp:start func_L40_0053E000 */
extern u16 *D_L40_0028EA20[];
extern s32 D_L40_00248498;
extern u8 *D_L40_0024845C;
extern f32 func_L01_0040E548(void *, void *);
extern s32 func_L39_0061D780(void *);

s32 func_L40_0053E000(f32 radius, s32 a0, u8 *a1, u8 a2) {
    u16 *p;
    u8 *o;
    u8 *best;
    f32 bestd;
    f32 d;
    u32 k;

    best = 0;
    bestd = 99999.0f;
    p = D_L40_0028EA20[a2];
    if (a2 != 0xFF && a2 <= D_L40_00248498 && p != 0) {
        do {
            o = D_L40_0024845C + ((*p & 0x7FFF) << 8);
            if (o == 0) break;
            if (*(s16 *)(o + 0xAA) == 0x1A63) {
                k = (u8)(o[0x20] - 2) < 4;
            } else {
                k = (u8)(o[0x20] - 2) < 3;
            }
            if (k) {
                d = func_L01_0040E548(a1 + 0x10, o + 0x10);
                if (d < bestd) {
                    bestd = d;
                    best = o;
                }
            }
            p++;
            if (a2 == 0xFF || a2 > D_L40_00248498 || p == 0) break;
        } while ((s16)p[-1] >= 0 || p == D_L40_0028EA20[a2]);
    }
    if (best != 0) {
        if (!(radius * 0.75f < bestd)) {
            return func_L39_0061D780(best);
        }
    }
    return -1;
}
/* localdecomp:end func_L40_0053E000 */

INCLUDE_ASM("asm/levels", func_L40_0053E1A8);

/* localdecomp:start func_L40_0053E760 */
typedef int Q_0053E760 __attribute__((mode(TI)));
typedef union Buf_0053E760 { u8 b[8]; u32 w[2]; f32 f[2]; } Buf_0053E760;
typedef struct { u8 pad0[0x10]; Q_0053E760 q10; u8 b20; u8 pad21[0x1F]; s32 w40; } R_0053E760;
typedef struct Obj_0053E760 Obj_0053E760;
typedef struct { u8 pad0[0x10]; R_0053E760 *(*get)(Obj_0053E760 *); } VT_0053E760;
struct Obj_0053E760 {
    u8 pad0[0x14];
    VT_0053E760 *vt;
};
extern u8 D_L40_003BFE20[];
extern u8 *func_L40_0053F248(s32);
extern u8 *func_L40_004EDEA8(s32);
extern Obj_0053E760 *func_L40_004EF0D0(s32);

static __inline__ u32 DecU_0053E760(u8 *q) {
    Buf_0053E760 buf;
    u32 a;
    s32 n;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    if (*q == 0) {
        return 0;
    }
    n = *q;
    k = ((u32)q - n) & 7;
    m = n + 1;
    d = buf.b;
    for (i = 0; i < 40; i += 5) {
        *d++ = D_L40_003BFE20[m + ((k + i) & 7) * 255];
    }
    a = buf.w[0] ^ (u32)q;
    buf.w[0] = a;
    buf.w[1] ^= a;
    return buf.w[1];
}

static __inline__ f32 DecF_0053E760(u8 *q) {
    Buf_0053E760 buf;
    u32 a;
    s32 n;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    if (*q == 0) {
        return 0.0f;
    }
    n = *q;
    k = ((u32)q - n) & 7;
    m = n + 1;
    d = buf.b;
    for (i = 0; i < 40; i += 5) {
        *d++ = D_L40_003BFE20[m + ((k + i) & 7) * 255];
    }
    a = buf.w[0] ^ (u32)q;
    buf.w[0] = a;
    buf.w[1] ^= a;
    return buf.f[1];
}

static __inline__ s32 GtF_0053E760(u8 *q, f32 v) {
    return DecF_0053E760(q) > v;
}

static __inline__ R_0053E760 *Get_0053E760(s32 a0) {
    Obj_0053E760 *o = func_L40_004EF0D0(a0);
    if (o != 0) {
        return o->vt->get(o);
    }
    return 0;
}

void *func_L40_0053E760(s32 a0, Q_0053E760 *out, s32 a2, s32 a3) {
    u8 *p;
    u8 *g;
    u8 *h;
    R_0053E760 *w;

    p = func_L40_0053F248(a0);
    if (p == 0) {
        g = func_L40_004EDEA8(a0);
        if (g != 0 && (DecU_0053E760(g + 0x19E4) ^ 0x39) != 0 && (DecU_0053E760(g + 0x19E6) ^ 0x14) != 0
            && (u8)GtF_0053E760(g + 0x2476, 0.0f) && *(u8 **)(g + 0x2558) != 0
            && (w = *(R_0053E760 **)(*(u8 **)(g + 0x2558) + 4)) != 0 && w->w40 != a2) {
            h = *(u8 **)(g + 0x2528);
            if (h != 0 && *(R_0053E760 **)(h + 0x2D0) != 0) {
                if (*(f32 *)(h + 0x308) <= 0.0f) {
                    return 0;
                }
                *out = (*(R_0053E760 **)(h + 0x2D0))->q10;
                return *(void **)(*(u8 **)(g + 0x2528) + 0x2D0);
            }
            *out = (*(R_0053E760 **)(g + 0x2524))->q10;
            return *(void **)(g + 0x2524);
        }
        {
            R_0053E760 *r = Get_0053E760(a0);
            if (r != 0) {
                *out = r->q10;
                return r;
            }
        }
        if (a3 != 0 && g == 0) {
            R_0053E760 *r = Get_0053E760(a0);
            if (r != 0 && (u32)(r->b20 - 2) < 4) {
                *out = r->q10;
                return r;
            }
        }
        return 0;
    }
    if (p[0x31] != 0 && *(s32 *)(p + 0x18) != a2 && *(s32 *)(*(u8 **)(p + 0x1C) + 0x98) != 0) {
        *out = (*(R_0053E760 **)(p + 0x1C))->q10;
        if (*(s16 *)(*(u8 **)(p + 0x1C) + 0xAA) == 0x109D) {
            ((f32 *)out)[2] += 0.35f;
        }
        return *(void **)(p + 0x1C);
    }
    if (a3 != 0 && p == 0) {
        R_0053E760 *r = Get_0053E760(a0);
        if (r != 0) {
            *out = r->q10;
            return r;
        }
    }
    return 0;
}
/* localdecomp:end func_L40_0053E760 */
