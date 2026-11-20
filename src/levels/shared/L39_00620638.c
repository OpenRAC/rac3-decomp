#include "common.h"

/* localdecomp:start func_L39_00620638 */
typedef int u128_00620638 __attribute__((mode(TI)));

typedef struct {
    u128_00620638 q[1];
} V4_00620638;

typedef struct {
    u8 pad0[0x34];
    s32 (*fn34)(void *, s32, s32, s32, s32);
} VT_00620638;

typedef struct {
    u8 pad0[0x68];
    u8 *p68;
} Obj58_00620638;

typedef struct {
    u8 pad0[0x27B];
    u8 b27B;
} Obj30_00620638;

typedef struct {
    u8 pad0[0x14];
    VT_00620638 *p14;
    u8 pad18[0xA0 - 0x18];
    V4_00620638 vA0;
    s32 wB0;
    s32 wB4;
    u8 padB8[0x19E4 - 0xB8];
    u8 b19E4;
    u8 b19E5;
    u8 b19E6;
    u8 pad19E7[0x1A06 - 0x19E7];
    u8 b1A06;
    u8 pad1A07[0x1A0A - 0x1A07];
    u8 b1A0A;
    u8 pad1A0B[0x1A14 - 0x1A0B];
    u8 b1A14;
    u8 pad1A15[0x2450 - 0x1A15];
    s32 w2450;
    u8 pad2454[0x2458 - 0x2454];
    Obj58_00620638 *p2458;
    u8 pad245C[0x24C9 - 0x245C];
    u8 b24C9;
    u8 pad24CA[0x2524 - 0x24CA];
    void *p2524;
    u8 pad2528[0x2530 - 0x2528];
    Obj30_00620638 *p2530;
    u8 pad2534[0x2544 - 0x2534];
    s32 w2544;
} G_00620638;

typedef struct {
    u32 w0;
    u32 w4;
} R_00620638;

typedef union {
    u8 b[8];
    u32 w[2];
} Buf_00620638;

typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    u8 pad4[4];
    u32 w8;
} Msg_00620638;

extern u8 D_L39_004997E0[];
typedef struct {
    u16 a;
    u16 b;
} Cnt_00620638;

typedef struct {
    u8 pad0[0x78];
    Cnt_00620638 t[8][9];
} Stats_00620638;

extern Stats_00620638 D_L39_00352940;
extern G_00620638 *D_L39_0024CE20[] __attribute__((section(".sdata")));
extern u8 *func_00382348(void *);
extern void func_L39_00662B18(void *, void *, s32);
extern void func_L01_00511158(void *, void *, void *, f32);
extern void func_L39_00629290(void *);
extern void func_L39_00628760(void *);
extern void func_L39_0057B4C0(s32, s32);
extern s32 func_L39_00648840(void *, s32);
extern void func_L39_00648960(void *, s32);
extern void *func_L39_0051DB38(void *, void *, s32);
extern void *func_L39_00556448(void *, void *, s32);
extern s32 func_L39_00672118(s32);
extern void func_L39_00629550(void *, void *);

static __inline__ u32 Dec_00620638(u8 *q) {
    Buf_00620638 buf;
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
    for (i = 0; i < 40; i += 5) {
        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
    }
    a = buf.w[0] ^ (u32)q;
    b = buf.w[1] ^ a;
    buf.w[0] = a;
    buf.w[1] = b;
    return b;
}

void func_L39_00620638(G_00620638 *g, R_00620638 *r) {
    u8 ba, bb, bc, bd, be, bf;
    u8 host;
    u8 *t;
    s32 tm;
    s32 z;

    switch (r->w0 & 0xF) {
    case 5:
    case 7:
        if ((Dec_00620638(&g->b19E6) ^ 0x14) == 0
            || (host = g->p2530 != 0 ? (g->p2530->b27B != 0 && (Dec_00620638(&g->b19E4) ^ 0x31) == 0) : 0)) {
            return;
        }
        func_L39_00662B18(r, &ba, 1);
        func_L39_00662B18(r, &bb, 1);
        t = func_00382348(g->p2524);
        t[0xE] = 3;
        if (g->b1A14 != 0) {
            V4_00620638 save = g->vA0;
            func_L01_00511158(g, &g->vA0, &g->vA0, 0.7f);
            func_L39_00629290(g);
            g->vA0 = save;
        }
        func_L39_00628760(g);
        g->p14->fn34(g, 0x31, 1, 0, 1);
        g->p2530->b27B = 1;
        g->b1A06 = 0;
        g->w2450 = 0;
        if (g->b1A14 != 0) {
            func_L39_0057B4C0(g->b24C9, 1);
        }
        g->b1A0A = 1;
        tm = r->w4 + (r->w0 >> 13) + bb * 1000;
        g->wB0 = 0;
        g->wB4 = 0;
        if ((r->w0 & 0xF) == 5) {
            if (func_L39_00648840(g, 0x18) == 0) {
                func_L39_00648960(g, 0x18);
            }
            g->p2458 = func_L39_0051DB38(g->p2524, g, tm);
        } else {
            if (func_L39_00648840(g, 0x17) == 0) {
                func_L39_00648960(g, 0x17);
            }
            g->p2458 = func_L39_00556448(g->p2524, g, tm);
        }
        t = func_00382348(g->p2524);
        if (t != 0) {
            t[0xE] = 3;
        }
        z = func_L39_00672118(9);
        D_L39_00352940.t[g->w2544][z].b++;
        if (ba != 0xFF) {
            G_00620638 *o;
            D_L39_00352940.t[ba][z].a++;
            o = D_L39_0024CE20[ba];
            if (o != 0 && o->b1A14 != 0) {
                Msg_00620638 m;
                m.b1 = 0x39;
                m.b2 = g->w2544;
                m.w8 = *(u32 *)o;
                m.b0 = o->w2544;
                m.b3 = 9;
                func_L39_00629550(o, &m);
            }
        }
        break;
    case 6:
        func_L39_00662B18(r, &bc, 1);
        func_L39_00662B18(r, &bd, 1);
        t = func_00382348(g->p2524);
        if (t != 0) {
            t[0xE] = 1;
        }
        if (g->p2458 != 0) {
            u8 *q = g->p2458->p68;
            if (bc) {
                *(s32 *)(q + 0x84) = 2;
            } else if (bd) {
                *(s32 *)(q + 0x84) = 3;
            } else {
                *(s32 *)(q + 0x84) = 1;
            }
        }
        g->p2458 = 0;
        break;
    case 8:
        func_L39_00662B18(r, &be, 1);
        func_L39_00662B18(r, &bf, 1);
        t = func_00382348(g->p2524);
        if (t != 0) {
            t[0xE] = 1;
        }
        if (g->p2458 != 0) {
            u8 *q = g->p2458->p68;
            if (be) {
                *(s32 *)(q + 0x84) = 2;
            } else if (bf) {
                *(s32 *)(q + 0x84) = 3;
            } else {
                *(s32 *)(q + 0x84) = 1;
            }
        }
        g->p2458 = 0;
        break;
    }
}
/* localdecomp:end func_L39_00620638 */
