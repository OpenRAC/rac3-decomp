#include "common.h"

typedef union Buf_003D5840 {
    u8 b[8];
    u32 w[2];
} Buf_003D5840;

/* localdecomp:start func_L40_003D5818 */
extern void func_L39_0066DCC8(s32, s32, s32, s32);

void func_L40_003D5818(s32 a0) {
    func_L39_0066DCC8(a0, 1, 0, 250);
}
/* localdecomp:end func_L40_003D5818 */

/* localdecomp:start func_L40_003D5840 */
extern u8 D_L40_003BFE20[];
extern s32 func_L39_0053D8E8(u8 *);

static __inline__ u32 Dec_003D5840(u8 *q) {
    u32 b;
    u32 n;

    if (*q == 0) {
        b = 0;
    } else {
        Buf_003D5840 buf;
        u8 *dp;
        u32 a;
        s32 k;
        s32 m;
        s32 j;

        n = *q;
        k = ((u32)q - n) & 7;
        m = n + 1;
        dp = buf.b;
        for (j = 0; j < 40; j += 5) {
            *dp++ = D_L40_003BFE20[m + ((k + j) & 7) * 255];
        }
        a = buf.w[0] ^ (u32)q;
        b = buf.w[1] ^ a;
        buf.w[0] = a;
        buf.w[1] = b;
    }
    return b;
}

s32 func_L40_003D5840(u8 *a0, u8 *a1) {
    s32 r = 0;
    u8 *e;
    u16 hit;

    if (func_L39_0053D8E8(a1) == 0) {
        e = *(u8 **)(a0 + 0x2530);
        if (e != 0 && e[0x27B] != 0) {
            hit = 0;
            if ((Dec_003D5840(a0 + 0x19E4) ^ 0x31) == 0) {
                hit++;
            }
        } else {
            hit = 0;
        }
        if ((u8)hit == 0) {
            r = (Dec_003D5840(a0 + 0x19E6) != 0x14);
        }
    }
    return r;
}
/* localdecomp:end func_L40_003D5840 */

/* localdecomp:start func_L40_003D59B0 */
typedef union Buf_003D59B0 {
    u8 b[8];
    u32 w[2];
    u16 h[4];
} Buf_003D59B0;

typedef struct Ent_003D59B0 {
    u8 pad0[0x14];
    s16 h14;
    u8 pad16[0x1E - 0x16];
    s16 h1E;
    u8 pad20;
    s8 b21;
    u8 pad22[0x80 - 0x22];
} Ent_003D59B0;

typedef struct Rec_003D59B0 {
    u8 pad0[0x1A52];
    u8 a1A52[1];
} Rec_003D59B0;

typedef struct St_003D59B0 {
    u8 pad0[4];
    s32 w4;
    u8 pad8[0x10 - 8];
    s32 w10;
    u8 pad14[0x18 - 0x14];
    s32 w18;
    s32 w1C;
} St_003D59B0;

typedef struct G_003D59B0 {
    u8 pad0[8];
    u32 w8;
    u8 padC[0x128 - 0xC];
    s32 w128;
} G_003D59B0;

extern G_003D59B0 D_001A5CD0;
extern u8 D_L40_003AA040[];
extern u8 D_L40_003AA041[];
__asm__(".extern D_L40_00247EC8, 16");
extern u32 D_L40_00247EC8;
extern Ent_003D59B0 D_L40_003C2ED0[];

extern void func_L39_00662B18(void *, void *, s32);
extern u8 *func_L39_0061BFB0(u32);
extern void func_L39_005F3488(s32, s32, void *, s32);
extern s32 func_L01_003F8470(void *);
extern void func_L39_00673540(void *, s32, s32);
extern s32 func_L39_00648AE0(u8 *, s32);
extern s32 func_L39_00648840(void *, s32);
extern void func_L39_00648960(void *, s32);
extern void func_L01_00423000(s32, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);

void func_L40_003D59B0(u8 *a0, s32 *a1) {
    St_003D59B0 *s = *(St_003D59B0 **)(a0 + 0x68);
    u32 id;
    u8 *r;
    s32 v;
    s16 h;

    switch (*a1 & 0xF) {
    case 0:
        func_L39_00662B18(a1, &id, 4);
        r = func_L39_0061BFB0(id);
        if (r != 0) {
            if ((*(u32 *)r >> 28) == D_001A5CD0.w8) {
                func_L39_005F3488(0, 0, a0, 0x189C);
            }
            if (func_L01_003F8470(a0) == 0) {
                func_L39_00673540(r + 0x1A40, s->w10, 0);
            }
            if (s->w1C == 0) {
                Ent_003D59B0 *e;
                Ent_003D59B0 *e2;
                u16 cur;
                s32 i;
                s32 i2;

                /* item lookup */
                i = s->w10;
                if (func_L39_00648AE0(r, i)) {
                    e = D_L40_003C2ED0 + D_L40_003C2ED0[i].b21;
                } else {
                    e = &D_L40_003C2ED0[i];
                }
                /* decode the protected value */
                {
                    u8 *p;
                    u8 *q;
                    Buf_003D59B0 buf;
                    u32 a;
                    u32 b;
                    s32 n;
                    s32 k;
                    s32 m;
                    s32 j;
                    u8 *dp;

                    p = (u8 *)(s->w10 + (u32)r);
                    p += 0x1A52;
                    q = p;

                    if (*q == 0) {
                        cur = 0;
                    } else {
                        n = *q;
                        k = ((u32)q - n) & 7;
                        m = n + 1;
                        dp = buf.b;
                        for (j = 0; j < 24; j += 3) {
                            *dp++ = D_L40_003AA040[((k + j) & 7) * 209 + m];
                        }
                        a = buf.w[0] ^ (u32)q;
                        b = buf.w[1] ^ a;
                        buf.w[0] = a;
                        buf.w[1] = (b >> 16) / (((b ^ (b >> 16)) << 16) + 1);
                        cur = buf.h[2];
                    }
                }
                v = e->h1E - (s16)cur;
                i2 = s->w10;
                if (func_L39_00648AE0(r, i2)) {
                    e2 = D_L40_003C2ED0 + D_L40_003C2ED0[i2].b21;
                } else {
                    e2 = &D_L40_003C2ED0[i2];
                }
                /* encode the new value */
                {
                    u8 *q;
                    s16 vv;
                    u8 *hk;
                    Buf_003D59B0 buf;
                    u32 key;
                    s32 k;
                    s32 m;
                    s32 j;
                    s32 tt;
                    u8 *dp;

                    q = (u8 *)(s->w10 + (u32)r); q += 0x1A52;
                    vv = e2->h1E;
                    hk = q;

                    if (*q == 0) {
                        *q = ++D_L40_003AA040[0];
                    } else {
                        tt = *q;
                        *q = D_L40_003AA041[0];
                        D_L40_003AA041[0] = tt;
                    }
                    key = ((u32 *)D_L40_003AA040)[((u32)hk * D_L40_00247EC8) % 418];
                    k = ((u32)q - *q) & 7;
                    buf.h[2] = vv;
                    buf.w[0] = (u32)q ^ key;
                    buf.w[1] = ((buf.w[1] & 0xFFFF) | (buf.w[1] << 16)) ^ key;
                    m = *q + 1;
                    dp = buf.b;
                    for (j = 0; j < 24; j += 3) {
                        D_L40_003AA040[((k + j) & 7) * 209 + m] = *dp++;
                    }
                }
            } else {
                s16 d = s->w1C;
                s32 nv;
                s16 t;
                s32 cur;
                s32 diff;
                u16 ret;
                u16 ret2;
                s32 i;
                Ent_003D59B0 *e;

                {
                    u8 *q;
                    Buf_003D59B0 buf;
                    u32 a;
                    u32 b;
                    s32 n;
                    s32 k;
                    s32 m;
                    s32 j;
                    u8 *dp;

                    q = (u8 *)(s->w10 + (u32)r); q += 0x1A52;

                    if (*q == 0) {
                        ret = 0;
                    } else {
                        n = *q;
                        k = ((u32)q - n) & 7;
                        m = n + 1;
                        dp = buf.b;
                        for (j = 0; j < 24; j += 3) {
                            *dp++ = D_L40_003AA040[((k + j) & 7) * 209 + m];
                        }
                        a = buf.w[0] ^ (u32)q;
                        b = buf.w[1] ^ a;
                        buf.w[0] = a;
                        buf.w[1] = (b >> 16) / (((b ^ (b >> 16)) << 16) + 1);
                        ret = buf.h[2];
                    }
                }
                cur = (s16)ret;
                nv = (s16)(d + cur);
                i = s->w10;
                if (func_L39_00648AE0(r, i)) {
                    e = D_L40_003C2ED0 + D_L40_003C2ED0[i].b21;
                } else {
                    e = &D_L40_003C2ED0[i];
                }
                if (e->h1E < nv) {
                    s32 i3 = s->w10;
                    Ent_003D59B0 *e3;
                    if (func_L39_00648AE0(r, i3)) {
                        e3 = D_L40_003C2ED0 + D_L40_003C2ED0[i3].b21;
                    } else {
                        e3 = &D_L40_003C2ED0[i3];
                    }
                    nv = e3->h1E;
                }
                t = nv;
                {
                    u8 *q;
                    Buf_003D59B0 buf;
                    u32 a;
                    u32 b;
                    s32 n;
                    s32 k;
                    s32 m;
                    s32 j;
                    u8 *dp;

                    q = (u8 *)(s->w10 + (u32)r); q += 0x1A52;

                    if (*q == 0) {
                        ret2 = 0;
                    } else {
                        n = *q;
                        k = ((u32)q - n) & 7;
                        m = n + 1;
                        dp = buf.b;
                        for (j = 0; j < 24; j += 3) {
                            *dp++ = D_L40_003AA040[((k + j) & 7) * 209 + m];
                        }
                        a = buf.w[0] ^ (u32)q;
                        b = buf.w[1] ^ a;
                        buf.w[0] = a;
                        buf.w[1] = (b >> 16) / (((b ^ (b >> 16)) << 16) + 1);
                        { s16 hv = buf.h[2]; ret2 = hv; }
                    }
                }
                diff = (s16)ret2 - t;
                v = (s16)diff;
                {
                    u8 *q;
                    s16 vv;
                    u8 *hk;
                    Buf_003D59B0 buf;
                    u32 key;
                    s32 k;
                    s32 m;
                    s32 j;
                    s32 tt;
                    u8 *dp;

                    q = (u8 *)(s->w10 + (u32)r); q += 0x1A52;
                    vv = nv;
                    hk = q;

                    if (*q == 0) {
                        *q = ++D_L40_003AA040[0];
                    } else {
                        tt = *q;
                        *q = D_L40_003AA041[0];
                        D_L40_003AA041[0] = tt;
                    }
                    key = ((u32 *)D_L40_003AA040)[((u32)hk * D_L40_00247EC8) % 418];
                    k = ((u32)q - *q) & 7;
                    buf.h[2] = vv;
                    buf.w[0] = (u32)q ^ key;
                    buf.w[1] = ((buf.w[1] & 0xFFFF) | (buf.w[1] << 16)) ^ key;
                    m = *q + 1;
                    dp = buf.b;
                    for (j = 0; j < 24; j += 3) {
                        D_L40_003AA040[((k + j) & 7) * 209 + m] = *dp++;
                    }
                }
            }
            if (r[0x1A14] != 0) {
                Ent_003D59B0 *e;
                s32 i = s->w10;
                if (func_L39_00648AE0(r, i)) {
                    e = D_L40_003C2ED0 + D_L40_003C2ED0[i].b21;
                } else {
                    e = &D_L40_003C2ED0[i];
                }
                h = e->h14;
                if (func_L39_00648840(r, 0x16) == 0) {
                    func_L39_00648960(r, 0x16);
                } else {
                    func_L01_00423000(h, v, -1, r[0x24C9]);
                }
            }
        }
        s->w18 = D_001A5CD0.w128;
        s->w4 = id;
        func_L01_004450F0(a0, 3, -1);
        break;
    case 1:
        func_L01_004450F0(a0, 1, -1);
        break;
    }
}
/* localdecomp:end func_L40_003D59B0 */

/* localdecomp:start func_L40_003D6070 */
/* section(".sdata") on D_L40_00249330: gcc then emits the address as one `la` macro (lui+addiu into $s2), as retail has; the plain extern splits it and the lui lands in a delay slot. */
typedef struct {
    s32 a;
    u32 b;
    s32 pad[3];
    s32 t0;
    s32 t1;
} S_003D6070;
extern f32 func_L01_0040E548(void *, void *);
extern s32 func_L40_003D5840(u8 *, u8 *);
extern void func_L39_0055DBE8(s32, s32);
extern s32 func_L39_0053D938(s32);
extern s32 *D_L40_00249330[] __attribute__((section(".sdata")));
extern f32 D_L40_00246984;
extern s32 D_001A5DF8[];
s32 func_L40_003D6070(u8 *p, s32 a1) {
    S_003D6070 *q = *(S_003D6070 **)(p + 0x68);
    s32 *e;
    s32 i;

    if (a1 != 0) {
        q->a = -1;
        q->b = 0xFFFFFFFF;
        return 0;
    }
    switch (p[0x20]) {
    case 0:
        break;
    case 1:
    case 2:
        for (i = 0; i < 8; i++) {
            e = D_L40_00249330[i];
            if (e != 0 && func_L01_0040E548((u8 *)e + 0xA0, p + 0x10) < D_L40_00246984 && func_L40_003D5840((u8 *)e, p) != 0) {
                break;
            }
        }
        if (i < 8) {
            func_L39_0055DBE8((s32)p, *e);
        }
        break;
    case 3:
        if (q->t0 > 0 && q->t1 > 0) {
            if (q->t0 < D_001A5DF8[0] - q->t1) {
                if (func_L39_0053D938((s32)p) == 0) {
                    func_L40_003D5818((s32)p);
                }
            }
        }
        break;
    }
    return 0;
}
/* localdecomp:end func_L40_003D6070 */

/* localdecomp:start func_L40_003D61B8 */
s32 func_L40_003D61B8(u8 *p, s32 *a1, s32 *a2) {
    s32 v = *(s32 *)(p + 104);
    *a2 = 12;
    *a1 = v;
    return 0;
}
/* localdecomp:end func_L40_003D61B8 */
