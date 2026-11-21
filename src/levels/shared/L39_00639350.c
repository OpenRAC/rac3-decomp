#include "common.h"

/* localdecomp:start func_L39_00639350 */
typedef int u128_00639350 __attribute__((mode(TI)));

typedef union Buf_00639350 {
    u8 b[8];
    u32 w[2];
} Buf_00639350;

typedef union Vec_00639350 {
    u128_00639350 q;
    f32 f[4];
} Vec_00639350;

extern u8 D_L39_004997E0[];
extern f32 func_0038CF00(void *, void *);
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern s32 func_L39_005B8928(void *);

/* reads an obfuscated 32-bit state stored as an index byte at q */
static __inline__ s32 get_state_00639350(u8 *q) {
    Buf_00639350 buf;
    u8 *b;
    s32 m;
    s32 k;
    s32 n;
    s32 i;
    long t;

    t = *q;
    if (t == 0) {
        return 0;
    }
    n = *q;
    m = n + 1;
    k = ((s32)q - n) & 7;
    b = buf.b;
    for (i = 0; i < 40; i += 5) {
        *b++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
    }
    buf.w[0] ^= (u32)q;
    buf.w[1] ^= buf.w[0];
    return buf.w[1];
}

f32 func_L39_00639350(u8 *o, void *pv, f32 a, f32 range, f32 hlim, f32 vlim, s32 *out) {
    u8 *p = pv;
    Vec_00639350 v;
    f32 dist;
    f32 h;
    f32 vv;
    f32 m;
    f32 t;
    f32 r;

    *out = 0;
    v.q = *(u128_00639350 *)(o + 0xA0);
    if ((get_state_00639350(o + 0x19E4) ^ 0x14) == 0) {
        v.f[2] = *(f32 *)(o + 0x2A8);
    }
    dist = func_0038CF00(&v, p + 0x10);
    if (range < dist) {
        *out = 1;
    }
    h = func_0038DBA0(func_0038D160(*(f32 *)(p + 0x10) - v.f[0], *(f32 *)(p + 0x14) - v.f[1]), a);
    m = h;
    vv = func_0038DBA0(func_0038D160(func_0038CF38(&v, p + 0x10), *(f32 *)(p + 0x18) - v.f[2]), 0.0f);
    if ((get_state_00639350(o + 0x19E4) ^ 1) == 0 || (get_state_00639350(o + 0x19E4) ^ 0x1D) == 0 || o[0x24FE] != 0) {
        t = func_0038DBA0(func_0038D160(*(f32 *)(p + 0x10) - *(f32 *)(o + 0x23A0),
                                        *(f32 *)(p + 0x14) - *(f32 *)(o + 0x23A4)),
                          *(f32 *)(o + 0x23B8));
        vv = func_0038DBA0(func_0038D160(func_0038CF38(o + 0x23A0, p + 0x10),
                                         *(f32 *)(p + 0x18) - *(f32 *)(o + 0x23A8)),
                           -*(f32 *)(o + 0x23B4));
        m = vv;
        h = t + vv;
        if (vv < t) {
            m = t;
        }
    }
    if (0.0f < hlim && hlim < m) {
        *out = 1;
    }
    if (0.0f < vlim && vlim < vv) {
        *out = 1;
    }
    r = dist + h * dist;
    if (func_L39_005B8928(p) != 0) {
        r += range * 0.8f;
    } else if (p != 0 && *(u8 **)(p + 0x24) != 0 && (*(u8 **)(p + 0x24))[0x46] == 0x16) {
        r += range * 0.8f;
    }
    return r;
}
/* localdecomp:end func_L39_00639350 */

/* localdecomp:start func_L39_00639740 */
#include "vu0.h"

typedef int u128_00639740 __attribute__((mode(TI)));

typedef union Buf_00639740 {
    u8 b[8];
    u32 w[2];
} Buf_00639740;

typedef union Vec_00639740 {
    u128_00639740 q;
    f32 f[4];
} __attribute__((aligned(16))) Vec_00639740;

extern u8 D_L39_004997E0[];
extern f32 func_0038CF00(void *, void *);
extern f32 func_0038CED8(void *);
extern void func_0038D028(void *, void *, void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern s32 func_L39_005B8928(void *);

/* reads an obfuscated 32-bit state stored as an index byte at q */
static __inline__ s32 get_state_00639740(u8 *q) {
    Buf_00639740 buf;
    u8 *b;
    s32 m;
    s32 k;
    s32 n;
    s32 i;
    long t;

    t = *q;
    if (t == 0) {
        return 0;
    }
    n = *q;
    m = n + 1;
    k = ((s32)q - n) & 7;
    b = buf.b;
    for (i = 0; i < 40; i += 5) {
        *b++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
    }
    buf.w[0] ^= (u32)q;
    buf.w[1] ^= buf.w[0];
    return buf.w[1];
}

f32 func_L39_00639740(u8 *o, u8 *p, void *dir, f32 range, f32 hlim, f32 vlim, s32 *out, void *mtx) {
    Vec_00639740 v;
    f32 dist;
    f32 h;
    f32 vv;
    f32 m;
    f32 t;
    f32 r;

    *out = 0;
    v.q = *(u128_00639740 *)(o + 0xA0);
    if ((get_state_00639740(o + 0x19E4) ^ 0x14) == 0 && 0.0f < *(f32 *)(o + 0x2A8)) {
        v.q = *(u128_00639740 *)(o + 0x260);
    }
    dist = func_0038CF00(&v, p + 0x10);
    if (range < dist) {
        *out = 1;
    }
    {
        Vec_00639740 d;
        Vec_00639740 e;
        vec_sub_ba(&d, p + 0x10, &v);
        func_0038D028(&d, &d, o + 0x60);
        e.q = *(u128_00639740 *)dir;
        func_0038D028(&e, &e, o + 0x60);
        t = func_0038D160(d.f[0], d.f[1]);
        h = func_0038DBA0(t, func_0038D160(e.f[0], e.f[1]));
        m = h;
        vv = func_0038D160(func_0038CED8(&d), d.f[2]);
    }
    if ((get_state_00639740(o + 0x19E4) ^ 1) == 0 || (get_state_00639740(o + 0x19E4) ^ 0x1D) == 0 ||
        o[0x24FE] != 0) {
        Vec_00639740 w;
        vec_sub_ba(&w, p + 0x10, o + 0x23A0);
        func_0038D028(&w, &w, mtx);
        t = func_0038D160(w.f[0], w.f[1]);
        vv = func_0038D160(func_0038CED8(&w), w.f[2]);
        m = vv;
        h = t + vv;
        if (vv < t) {
            m = t;
        }
    }
    if (0.0f < hlim && hlim < m) {
        *out = 1;
    }
    if (0.0f < vlim && vlim < vv) {
        *out = 1;
    }
    r = dist + h * dist;
    if (func_L39_005B8928(p) != 0) {
        r += range * 0.8f;
    }
    return r;
}
/* localdecomp:end func_L39_00639740 */

/* localdecomp:start func_L39_00639B70 */
#include "vu0.h"

extern u8 *D_L39_00292C20[];
extern void func_0038D5B0(void *, void *);
extern f32 *func_00382348(void *);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern f32 func_L39_00639740(u8 *, u8 *, void *, f32, f32, f32, s32 *, void *);
extern f32 func_L39_00639350(u8 *, void *, f32, f32, f32, f32, s32 *);

u8 *func_L39_00639B70(u8 *obj, f32 a, f32 b, f32 c, f32 d, void *v, s32 key, s32 flag) {
    u8 buf[0x40];
    vu0_v4 from;
    vu0_v4 to;
    s32 out;
    u8 *best;
    f32 bestd;
    f32 dist;
    u8 *m;
    u8 **pp;

    best = 0;
    bestd = 1.0e8f;
    if (obj[0x1A06] != 0) {
        func_0038D5B0(buf, obj + 0x23C0);
    }
    for (pp = D_L39_00292C20; (m = *pp) != 0; pp++) {
        if (key != -1 && (*(u8 **)(m + 0x24))[0x46] != key) {
            continue;
        }
        if (key == 5) {
            f32 *h = func_00382348(m);
            if (h == 0 || *h == 0.0f) {
                continue;
            }
        }
        if (!(*(u16 *)(m + 0x34) & 0x1000)) {
            continue;
        }
        if (obj[0x1A06] != 0) {
            dist = func_L39_00639740(obj, m, v, a, c, d, &out, buf);
        } else {
            dist = func_L39_00639350(obj, m, b, a, c, d, &out);
        }
        if (out != 0) {
            continue;
        }
        if (!(dist < bestd)) {
            continue;
        }
        if (flag != 0) {
            from = *(vu0_v4 *)(obj + 0xE0);
            func_0038CF68(&to, m + 0xE0, 1.0f);
            vec_add_ab(&to, &to, m + 0x10);
            if (func_003D3CB0(&from, &to, 2, 0, 0) != 0) {
                continue;
            }
        }
        bestd = dist;
        best = m;
    }
    return best;
}
/* localdecomp:end func_L39_00639B70 */

/* localdecomp:start func_L39_00639D90 */
typedef union Buf_00639D90 {
    u8 b[8];
    u32 w[2];
} Buf_00639D90;

extern u8 D_L39_004997E0[];
typedef struct G_00639D90 {
    u8 pad0[0xA4];
    u8 bA4[4];
} G_00639D90;
extern G_00639D90 D_001A5810;
extern s32 D_L39_00241128;
__asm__(".extern D_L39_00241128, 16");

/* reads an obfuscated 32-bit state stored as an index byte at q */
static __inline__ s32 get_state_00639D90(u8 *q) {
    Buf_00639D90 buf;
    u8 *b;
    s32 m;
    s32 k;
    s32 n;
    s32 i;
    long t;

    t = *q;
    if (t == 0) {
        return 0;
    }
    n = *q;
    m = n + 1;
    k = ((s32)q - n) & 7;
    b = buf.b;
    for (i = 0; i < 40; i += 5) {
        *b++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
    }
    buf.w[0] ^= (u32)q;
    buf.w[1] ^= buf.w[0];
    return buf.w[1];
}

s32 func_L39_00639D90(void *obj) {
    u8 *o = (u8 *)obj;
    u8 *e;

    if (D_001A5810.bA4[*(s32 *)(o + 0x2544)] == 0) {
        return 0;
    }
    if (*(s32 *)(o + 0x35C) != 0) {
        return 0;
    }
    if (D_L39_00241128 == 2 || D_L39_00241128 == 6) {
        return 0;
    }
    if (o[0x1A14] != 0) {
        e = *(u8 **)(*(u8 **)(o + 0x2530) + 0x50);
        if (e != 0 && *(s16 *)(e + 0x86) == 5) {
            return 0;
        }
    }
    if ((get_state_00639D90(o + 0x19E4) ^ 0x71) == 0) {
        return 0;
    }
    if ((get_state_00639D90(o + 0x19E4) ^ 0x31) == 0) {
        return 0;
    }
    if ((get_state_00639D90(o + 0x19E4) ^ 0x1C) == 0) {
        return 0;
    }
    if ((get_state_00639D90(o + 0x19E4) ^ 0x8E) != 0) {
        return D_001A5810.bA4[*(s32 *)(o + 0x2544)];
    } else {
        return 0;
    }
}
/* localdecomp:end func_L39_00639D90 */
