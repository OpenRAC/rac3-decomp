#include "common.h"

/* NTSC-U counterpart of func_L39_0063C840 (src/levels/shared/L39_0063BDE0.c): 0.05328 -> 0.037; 0.432 -> 0.3; 0.03024 -> 0.021; 0.3888 -> 0.27; 0.02016 -> 0.014 */
extern u8 D_L39_004998A0[];
#include "vu0.h"
extern u8 D_L39_004998A0[];
extern f32 func_00389468(f32, f32);
extern u8 D_L39_004998A0[];
extern void func_L39_00632600(u8 *, f32, f32);
extern void func_L39_006325E0(u8 *, f32, f32);

/* localdecomp:start func_L39_00639FF8 */
typedef union Buf_0063C840 {
    u8 b[8];
    u16 h[4];
    u32 w[2];
} Buf_0063C840;

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_0063C840;

extern u8 *D_L39_00292D20[];
__asm__(".extern D_L39_002412AC, 16");
extern s32 D_L39_002412AC;
extern u8 *func_0037E0B8(void *);
extern f32 func_00388800(void *, void *);
extern f32 func_00388A28(f32, f32);
extern f32 func_003893C8(f32, f32);
extern void func_L39_0062F938(void *, void *, s32, f32, f32, f32);
extern void func_L01_0050D180(void *, void *, void *, f32);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern void func_L39_006325F0(u8 *, f32, f32);

/* reads an obfuscated 32-bit state stored as an index byte at q */
static __inline__ u32 DecU_0063C840(u8 *q) {
    Buf_0063C840 buf;
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
        *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
    }
    a = buf.w[0] ^ (u32)q;
    buf.w[0] = a;
    buf.w[1] ^= a;
    return buf.w[1];
}

/* reads an obfuscated 16-bit value stored as an index byte at q */
static __inline__ s16 Dec16_0063C840(u8 *q) {
    Buf_0063C840 buf;
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
        *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
    }
    a = buf.w[0] ^ (u32)q;
    b = buf.w[1] ^ a;
    buf.w[0] = a;
    buf.w[1] = (b >> 16) / (((b ^ (b >> 16)) << 16) + 1);
    return buf.h[2];
}

/* tests the obfuscated 16-bit value at q against v */
static __inline__ s32 Gt16_0063C840(u8 *q, s16 v) {
    return Dec16_0063C840(q) > v;
}

void func_L39_00639FF8(u8 *o) {
    s32 v;
    u8 *m;
    u8 *r;
    u8 *best;
    s32 i;
    u8 *p;
    u8 *q;
    f32 bestPri;
    f32 bestScore;
    f32 d;
    f32 a;
    f32 ang;
    f32 score;
    f32 pri;
    f32 b;

    v = 0;
    if (*(s32 *)(o + 0x1078) != 0) {
        v = *(s32 *)(o + 0x3E0) == 0;
    }
    if ((DecU_0063C840(o + 0x19E6) ^ 1) != 0 && (DecU_0063C840(o + 0x19E6) ^ 4) != 0 &&
        (DecU_0063C840(o + 0x19E6) ^ 2) != 0 && (DecU_0063C840(o + 0x19E6) ^ 7) != 0 &&
        DecU_0063C840(o + 0x19E6) != 0) {
        *(u8 **)(o + 0x2454) = 0;
    } else {
        V4_0063C840 pos;
        V4_0063C840 tmp;

    if (!v) {
        if (((D_L39_002412AC + 4) & 7) == *(s32 *)(o + 0x2544)) {
            bestScore = 100000000.0f;
            bestPri = 0.0f;
            best = 0;
            for (i = 0; (m = D_L39_00292D20[i]) != 0; i++) {
                r = func_0037E0B8(m);
                if (r == 0) {
                    continue;
                }
                if (r[8] == *(s32 *)(o + 0x2548)) {
                    continue;
                }
                d = func_00388800(o + 0xA0, m + 0x10);
                if ((f32)r[0x28] < d) {
                    continue;
                }
                ang = func_00389468(func_00388A28(*(f32 *)(m + 0x10) - *(f32 *)(o + 0xA0),
                                                *(f32 *)(m + 0x14) - *(f32 *)(o + 0xA4)),
                                  *(f32 *)(o + 0xB8));
                if (1.919862151145935f < ang) {
                    continue;
                }
                if (1.0471975803375244f < fabs_asm(func_00388A28(func_00388800(m + 0x10, o + 0xA0),
                                                                 *(f32 *)(o + 0xA8) - *(f32 *)(m + 0x18)))) {
                    continue;
                }
                score = ang * d + d;
                if (m == *(u8 **)(o + 0x2454)) {
                    score -= 1.5f;
                    if (score < 0.0f) {
                        score = 0.0f;
                    }
                }
                pri = (f32)r[0x29];
                if (pri > bestPri || score < bestScore) {
                    if (bestPri < pri) {
                        bestPri = pri;
                    }
                    bestScore = score;
                    best = m;
                }
            }
            *(u8 **)(o + 0x2454) = best;
        }
        if (*(u8 **)(o + 0x2454) != 0) {
            func_L39_0062F938(o, &pos, 1, 0.0f, 0.0f, 1.2000000476837158f);
            tmp = *(V4_0063C840 *)(*(u8 **)(o + 0x2454) + 0x10);
            func_L01_0050D180(o, &tmp, &tmp, 0.5f);
            if (func_003CE740(&pos, &tmp, 2, 0, 0)) {
                *(u8 **)(o + 0x2454) = 0;
            }
        }
    }
    if (*(u8 **)(o + 0x2454) != 0 || v) {
    p = v ? *(u8 **)(o + 0x1078) : *(u8 **)(o + 0x2454);
    pos = *(V4_0063C840 *)(p + 0x10);
    q = func_0037E0B8(p);
    if (q != 0) {
        if (v) {
            pos.z += *(f32 *)(q + 0x10);
        } else {
            pos.z += (f32)q[0x2A] * 0.125f;
        }
    }
    if (v) {
        func_L39_0062F938(o, &tmp, 1, 0.5f, 0.0f, 0.550000011920929f);
    } else {
        func_L39_0062F938(o, &tmp, 1, 0.30000001192092896f, 0.0f, 0.8500000238418579f);
    }
    a = func_003893C8(func_00388A28(pos.x - tmp.x, pos.y - tmp.y), *(f32 *)(o + 0xB8));
    b = func_00388A28(func_00388800(&pos, &tmp), tmp.z - pos.z);
    if (1.029744267463684f < a) {
        a = 1.029744267463684f;
    } else if (a < -1.029744267463684f) {
        a = -1.029744267463684f;
    }
    if (0.6108652353286743f < b) {
        b = 0.6108652353286743f;
    }
    if (b < -0.4363323152065277f) {
        b = -0.4363323152065277f;
    }
    if (Gt16_0063C840(o + 0x311, -3)) {
        if (0.296705961227417f < a) {
            a = 0.296705961227417f;
        } else if (a < -0.296705961227417f) {
            a = -0.296705961227417f;
        }
        b = 0.0f;
    }
    if (v) {
        func_L39_006325F0(o, 0.0370000005f, 0.300000012f);
        *(f32 *)(o + 0x928) = a;
        func_L39_006325E0(o, 0.0370000005f, 0.300000012f);
        *(f32 *)(o + 0x874) = b;
    } else {
        func_L39_00632600(o, 0.0209999997f, 0.270000011f);
        *(f32 *)(o + 0x9D4) = b;
        *(f32 *)(o + 0x9D8) = a * 0.699999988079071f;
        func_L39_006325F0(o, 0.0140000004f, 0.300000012f);
        *(f32 *)(o + 0x928) = *(f32 *)(o + 0x9D8) * 0.550000011920929f;
    }
    }
    }
    *(s32 *)(o + 0x1078) = 0;
}
/* localdecomp:end func_L39_00639FF8 */
