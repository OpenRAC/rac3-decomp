#include "common.h"

/* localdecomp:start func_L39_00635DE8 */
typedef union Buf_00635DE8 {
    u8 b[8];
    u32 w[2];
} Buf_00635DE8;

extern u8 D_L39_004997E0[];
extern u8 D_L39_004997E1[];
extern u8 D_L39_004814A8[];
extern u8 D_L39_004814A9[];
__asm__(".extern D_L39_0024B9C8, 16");
extern u32 D_L39_0024B9C8;

static __inline__ void PrepD_00635DE8(u8 *q) {
    s32 t;
    if (*q == 0) {
        *q = ++D_L39_004997E0[0];
    } else {
        t = *q;
        *q = D_L39_004997E1[0];
        D_L39_004997E1[0] = t;
    }
}

static __inline__ void PrepC_00635DE8(u8 *q) {
    s32 t;
    if (*q == 0) {
        *q = ++D_L39_004814A8[0];
    } else {
        t = *q;
        *q = D_L39_004814A9[0];
        D_L39_004814A9[0] = t;
    }
}

static __inline__ s32 DecD_00635DE8(u8 *q) {
    Buf_00635DE8 buf;
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
        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
    }
    a = buf.w[0] ^ (u32)q;
    buf.w[0] = a;
    buf.w[1] ^= a;
    return buf.w[1];
}

static __inline__ s32 DecC_00635DE8(u8 *q) {
    u32 buf[2];
    s32 x;
    u8 *p;
    u8 *b;
    s32 m;
    s32 k;
    s32 n;
    s32 j;

    p = q;
    if (*p == 0) {
        return 0;
    }
    n = *p;
    m = n + 1;
    k = ((s32)p - n) & 7;
    b = (u8 *)buf;
    for (j = 0; j < 40; j += 5) {
        x = m + ((k + j) & 7) * 193;
        *b++ = D_L39_004814A8[x];
    }
    buf[0] ^= (u32)p;
    buf[1] ^= buf[0];
    return buf[1];
}

static __inline__ void SetD_00635DE8(u8 *q, s32 v) {
    u8 *hk = q;
    Buf_00635DE8 buf;
    u32 key;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    PrepD_00635DE8(q);
    key = ((u32 *)D_L39_004997E0)[((u32)hk * D_L39_0024B9C8) % 510];
    k = ((u32)q - *q) & 7;
    buf.w[0] = (u32)q ^ key;
    buf.w[1] = v ^ key;
    m = *q + 1;
    d = buf.b;
    for (i = 0; i < 40; i += 5) {
        D_L39_004997E0[m + ((k + i) & 7) * 255] = *d++;
    }
}

static __inline__ void SetC_00635DE8(u8 *q, s32 v) {
    u8 *hk = q;
    Buf_00635DE8 buf;
    u32 key;
    s32 x;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    PrepC_00635DE8(q);
    key = ((u32 *)D_L39_004814A8)[((u32)hk * D_L39_0024B9C8) % 386];
    k = ((u32)q - *q) & 7;
    buf.w[0] = (u32)q ^ key;
    buf.w[1] = v ^ key;
    m = *q + 1;
    d = buf.b;
    for (i = 0; i < 40; i += 5) {
        x = m + ((k + i) & 7) * 193;
        D_L39_004814A8[x] = *d++;
    }
}

static __inline__ void CopyC_00635DE8(u8 *d, u8 *s) {
    SetC_00635DE8(d, DecC_00635DE8(s));
}

static __inline__ void CopyD_00635DE8(u8 *d, u8 *s) {
    SetD_00635DE8(d, DecD_00635DE8(s));
}

static __inline__ void IncD_00635DE8(u8 *q) {
    SetD_00635DE8(q, DecD_00635DE8(q) + 1);
}

void func_L39_00635DE8(u8 *g) {
    s32 n;
    s32 m;
    s32 i;
    s32 lim = 8;

    n = DecD_00635DE8(g + 0x1A04);
    m = (n < lim) ? n : lim - 1;
    for (i = m - 1; i >= 0; i--) {
        CopyC_00635DE8(g + 0x19ED + i, g + 0x19EC + i);
        CopyC_00635DE8(g + 0x19F5 + i, g + 0x19F4 + i);
        CopyC_00635DE8(g + 0x19FD + i, g + 0x19FC + i);
    }
    SetC_00635DE8(g + 0x19EC, DecD_00635DE8(g + 0x19E4));
    SetC_00635DE8(g + 0x19F4, DecD_00635DE8(g + 0x19E6));
    SetC_00635DE8(g + 0x19FC, *(s32 *)(g + 0x2F0));
    IncD_00635DE8(g + 0x1A04);
    if (DecD_00635DE8(g + 0x1A04) > lim) {
        SetD_00635DE8(g + 0x1A04, lim);
    }
    CopyD_00635DE8(g + 0x19EA, g + 0x19E7);
    CopyD_00635DE8(g + 0x19EB, g + 0x19E8);
    SetD_00635DE8(g + 0x19E9, *(s32 *)(g + 0x2F0));
    CopyD_00635DE8(g + 0x19E7, g + 0x19E4);
    CopyD_00635DE8(g + 0x19E8, g + 0x19E6);
}
/* localdecomp:end func_L39_00635DE8 */

/* localdecomp:start func_L39_00636F30 */
extern u8 D_L39_004997E0[];
extern u8 D_L39_004814A8[];

s32 func_L39_00636F30(u8 *o, s32 id, s32 limit) {
    u32 buf[2];
    s32 i;
    s32 sum;
    s32 cnt;
    s32 v;

    i = 0;
    sum = *(s32 *)(o + 0x2F0);
    for (;;) {
        {
            u8 *p = o + 0x1A04;
            u8 *b;
            s32 m;
            s32 k;
            s32 n;
            s32 j;
            long t;

            t = *p;
            if (t == 0) {
                cnt = 0;
            } else {
                n = *p;
                m = n + 1;
                k = ((s32)p - n) & 7;
                b = (u8 *)buf;
                for (j = 0; j < 40; j += 5) {
                    *b++ = D_L39_004997E0[m + ((k + j) & 7) * 255];
                }
                buf[0] ^= (u32)p;
                buf[1] ^= buf[0];
                cnt = buf[1];
            }
        }
        if (i >= cnt) {
            break;
        }
        if (limit < sum) {
            return 0;
        }
        {
            u8 *q = (u8 *)(i + (s32)o);
            s32 x;
            u8 *p;
            u8 *b;
            s32 m;
            s32 k;
            s32 n;
            s32 j;

            q += 0x19EC;
            p = q;
            if (*p == 0) {
                v = 0;
            } else {
                n = *p;
                m = n + 1;
                k = ((s32)p - n) & 7;
                b = (u8 *)buf;
                for (j = 0; j < 40; j += 5) {
                    x = m + ((k + j) & 7) * 193;
                    *b++ = D_L39_004814A8[x];
                }
                buf[0] ^= (u32)p;
                buf[1] ^= buf[0];
                v = buf[1];
            }
        }
        if (v != id) {
            {
                u8 *p = o + i + 0x19FC;
                s32 x;
                u8 *b;
                s32 m;
                s32 k;
                s32 n;
                s32 j;

                if (*p == 0) {
                    v = 0;
                } else {
                    n = *p;
                    m = n + 1;
                    k = ((s32)p - n) & 7;
                    b = (u8 *)buf;
                    for (j = 0; j < 40; j += 5) {
                        x = m + ((k + j) & 7) * 193;
                        *b++ = D_L39_004814A8[x];
                    }
                    buf[0] ^= (u32)p;
                    buf[1] ^= buf[0];
                    v = buf[1];
                }
            }
            sum += v;
            i++;
        } else {
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L39_00636F30 */

/* localdecomp:start func_L39_00637120 */
extern u8 D_L39_004997E0[];
extern u8 D_L39_004814A8[];

s32 func_L39_00637120(u8 *o, s32 id, s32 limit) {
    u32 buf[2];
    s32 i;
    s32 sum;
    s32 cnt;
    s32 v;

    i = 0;
    sum = *(s32 *)(o + 0x2F0);
    for (;;) {
        {
            u8 *p = o + 0x1A04;
            u8 *b;
            s32 m;
            s32 k;
            s32 n;
            s32 j;
            long t;

            t = *p;
            if (t == 0) {
                cnt = 0;
            } else {
                n = *p;
                m = n + 1;
                k = ((s32)p - n) & 7;
                b = (u8 *)buf;
                for (j = 0; j < 40; j += 5) {
                    *b++ = D_L39_004997E0[m + ((k + j) & 7) * 255];
                }
                buf[0] ^= (u32)p;
                buf[1] ^= buf[0];
                cnt = buf[1];
            }
        }
        if (i >= cnt) {
            break;
        }
        if (limit < sum) {
            return 0;
        }
        {
            u8 *q = (u8 *)(i + (s32)o);
            s32 x;
            u8 *p;
            u8 *b;
            s32 m;
            s32 k;
            s32 n;
            s32 j;

            q += 0x19F4;
            p = q;
            if (*p == 0) {
                v = 0;
            } else {
                n = *p;
                m = n + 1;
                k = ((s32)p - n) & 7;
                b = (u8 *)buf;
                for (j = 0; j < 40; j += 5) {
                    x = m + ((k + j) & 7) * 193;
                    *b++ = D_L39_004814A8[x];
                }
                buf[0] ^= (u32)p;
                buf[1] ^= buf[0];
                v = buf[1];
            }
        }
        if (v != id) {
            {
                u8 *p = o + i + 0x19FC;
                s32 x;
                u8 *b;
                s32 m;
                s32 k;
                s32 n;
                s32 j;

                if (*p == 0) {
                    v = 0;
                } else {
                    n = *p;
                    m = n + 1;
                    k = ((s32)p - n) & 7;
                    b = (u8 *)buf;
                    for (j = 0; j < 40; j += 5) {
                        x = m + ((k + j) & 7) * 193;
                        *b++ = D_L39_004814A8[x];
                    }
                    buf[0] ^= (u32)p;
                    buf[1] ^= buf[0];
                    v = buf[1];
                }
            }
            sum += v;
            i++;
        } else {
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L39_00637120 */
