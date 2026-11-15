#include "common.h"

/* localdecomp:start func_L39_00620E28 */
/* func_L39_00620E28: log. MATCH only with --as ps2as (D_L39_0024B9C8 and D_L39_00241640 are read by lui/lw macros, as in func_L39_00621388).
   Draft's gaps closed by: n as s32 passed to inline helpers Less/Sub taking s16 n (the (s16)n sll is shared, the sra repeated),
   Dec16C returning s16, Sub computing `s32 t = Dec16C(q) - n` before Set16C, g as a struct so &g->a1A52[w] adds w + g, and FindE
   written as `p = &D[i]; return &D[p->b21];` (the other arm `&D[i]`). Uses n units of the protected ammo count of weapon w. */
typedef union Buf_00620E28 {
    u8 b[8];
    u32 w[2];
    u16 h[4];
} Buf_00620E28;

typedef struct Ent_00620E28 {
    u8 pad0[0x1E];
    s16 h1E;
    u8 pad20;
    s8 b21;
    u8 pad22[0x80 - 0x22];
} Ent_00620E28;

typedef struct Mp_00620E28 {
    u8 pad0[0x19B];
    s8 b19B;
} Mp_00620E28;

typedef struct S_00620E28 {
    u8 pad0[0x478];
    s32 x478;
    u8 pad47C[0x1A14 - 0x47C];
    u8 b1A14;
    u8 pad1A15[0x1A52 - 0x1A15];
    u8 a1A52[1];
} S_00620E28;

extern u8 D_L39_00483A00[];
extern u8 D_L39_00483A01[];
extern u32 D_L39_0024B9C8;
extern Ent_00620E28 D_L39_0049C890[];
extern Mp_00620E28 *D_L39_00241640;
extern s32 func_L39_00648AE0(u8 *, s32);

static __inline__ void PrepC_00620E28(u8 *q) {
    s32 t;
    if (*q == 0) {
        *q = ++D_L39_00483A00[0];
    } else {
        t = *q;
        *q = D_L39_00483A01[0];
        D_L39_00483A01[0] = t;
    }
}

static __inline__ s16 Dec16C_00620E28(u8 *q) {
    Buf_00620E28 buf;
    u32 a;
    u32 b;
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
    for (i = 0; i < 24; i += 3) {
        *d++ = D_L39_00483A00[((k + i) & 7) * 209 + m];
    }
    a = buf.w[0] ^ (u32)q;
    b = buf.w[1] ^ a;
    buf.w[0] = a;
    buf.w[1] = (b >> 16) / (((b ^ (b >> 16)) << 16) + 1);
    return buf.h[2];
}

static __inline__ void Set16C_00620E28(u8 *q, s16 v) {
    u8 *hk = q;
    Buf_00620E28 buf;
    u32 key;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    PrepC_00620E28(q);
    key = ((u32 *)D_L39_00483A00)[((u32)hk * D_L39_0024B9C8) % 418];
    k = ((u32)q - *q) & 7;
    buf.h[2] = v;
    buf.w[0] = (u32)q ^ key;
    buf.w[1] = ((buf.w[1] & 0xFFFF) | (buf.w[1] << 16)) ^ key;
    m = *q + 1;
    d = buf.b;
    for (i = 0; i < 24; i += 3) {
        D_L39_00483A00[((k + i) & 7) * 209 + m] = *d++;
    }
}

static __inline__ Ent_00620E28 *FindE_00620E28(u8 *g, s32 i) {
    Ent_00620E28 *p;
    if (func_L39_00648AE0(g, i)) {
        p = &D_L39_0049C890[i];
        return &D_L39_0049C890[p->b21];
    }
    return &D_L39_0049C890[i];
}

static __inline__ s32 Less_00620E28(u8 *q, s16 n) {
    return Dec16C_00620E28(q) < n;
}

static __inline__ void Sub_00620E28(u8 *q, s16 n) {
    s32 t = Dec16C_00620E28(q) - n;
    Set16C_00620E28(q, t);
}

s32 func_L39_00620E28(S_00620E28 *g, s32 w, s32 n) {
    if (g->b1A14 != 0) {
        if (w == -1) {
            w = g->x478;
        }
        if (FindE_00620E28((u8 *)g, w)->h1E != 0) {
            if (Less_00620E28(&g->a1A52[w], n)) {
                return 0;
            }
            Sub_00620E28(&g->a1A52[w], n);
            if (D_L39_00241640->b19B != 0 && Dec16C_00620E28(&g->a1A52[w]) <= 0) {
                Set16C_00620E28(&g->a1A52[w], FindE_00620E28((u8 *)g, w)->h1E);
            }
        }
    }
    return 1;
}
/* localdecomp:end func_L39_00620E28 */
