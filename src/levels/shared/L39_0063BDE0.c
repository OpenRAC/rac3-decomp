#include "common.h"

/* declared by functions of L39_00639350.c, which this file was cut from */
extern s32 func_0038CB00(s16 *timer);
extern u8 D_L39_004997E0[];

/* localdecomp:start func_L39_0063BDE0 */
typedef struct { u8 pad[0xAA]; s16 t; } S639;
s32 func_L39_0063BDE0(s32 unused, S639 *p) {
    if (p == 0) return 0;
    return p->t == 0x18AB;
}
/* localdecomp:end func_L39_0063BDE0 */

/* localdecomp:start func_L39_0063BE00 */
#include "vu0.h"
typedef union Buf_0063BE00 {
    u8 b[8];
    u32 w[2];
} Buf_0063BE00;

extern u8 D_L39_004997E0[];
extern s32 func_L01_004606E8(s32, s32, s32, s32);
extern s32 func_L39_006212E8(void *);
extern f32 func_L39_00633C78(void *, void *, s32);
extern f32 func_0038DBA0(f32, f32);

/* reads an obfuscated 32-bit state stored as an index byte at q */
static __inline__ s32 get_state_0063BE00(u8 *q) {
    Buf_0063BE00 buf;
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

s32 func_L39_0063BE00(u8 *o, f32 lim) {
    f32 d;

    if (*(s16 *)(o + 0x3E4) != 0 ||
        (*(s32 *)(o + 0x1310) == 1 && func_L01_004606E8(0x28, 2, 0, *(s32 *)(o + 0x2534)) != 0 &&
        func_L39_006212E8(o) != 0xA)) {
        if ((get_state_0063BE00(o + 0x19E4) ^ 0x10) != 0) {
            if (o[0x1A06] != 0) {
                d = fabs_asm(func_L39_00633C78(o, o + 0x23C0, 0));
            } else {
                d = func_0038DBA0(*(f32 *)(o + 0xB8), *(f32 *)(o + 0x23B8));
            }
            if (d < lim) {
                return 0;
            }
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L39_0063BE00 */

/* localdecomp:start func_L39_0063BF40 */
extern s32 func_0038CB00(s16 *timer);
typedef struct {
    char pad0[452];
    int a;
    int b;
} Pad006396F8;

typedef struct {
    char pad0[996];
    unsigned short count;
    char pad3E6[9524 - 998];
    Pad006396F8 *pad;
} Obj006396F8;

extern int func_L39_00639D90(Obj006396F8 *);

void func_L39_0063BF40(Obj006396F8 *o)
{
    if (func_L39_00639D90(o)) {
        ((void (*)(unsigned short *))func_0038CB00)(&o->count);
        return;
    }
    if (o->pad->a & 3) {
        if (o->pad->a & 2)
            o->count++;
        if (o->pad->a & 1)
            o->count++;
    }
    if (o->pad->b & 3) {
        if (o->pad->b & 2)
            ((void (*)(unsigned short *))func_0038CB00)(&o->count);
        if (o->pad->b & 1)
            ((void (*)(unsigned short *))func_0038CB00)(&o->count);
    }
}
/* localdecomp:end func_L39_0063BF40 */

INCLUDE_ASM("asm/levels", func_L39_0063C000);

/* localdecomp:start func_L39_0063C468 */
typedef union Buf_0063C468 {
    u8 b[8];
    u32 w[2];
} Buf_0063C468;

extern u8 D_L39_004997E0[];
extern void func_L39_00621D30(u8 *);
extern void func_L39_00634E48(u8 *, f32, f32);
extern void func_L39_00634E28(u8 *, f32, f32);
extern s32 func_L39_005B43C8(s32, s32);
extern s32 func_0038CAD0(void *);
extern f32 func_L39_005B4410(f32, f32);
extern f32 func_L39_005B4468(f32, f32);
extern f32 func_003C4088(f32, f32, f32);

static __inline__ u32 Dec_0063C468(u8 *q) {
    Buf_0063C468 buf;
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

void func_L39_0063C468(u8 *self) {
    s32 flag;
    s32 t;
    u8 *p;
    u8 c;
    f32 r;

    if (*(s32 *)(self + 0x324) < 0x11) {
        return;
    }
    if (self[0x1A07] != 0 || *(s32 *)(self + 0x1078) != 0) {
        func_L39_00621D30(self);
        func_L39_00634E48(self, 0.0432f, 0.2880000174045563f);
        func_L39_00634E28(self, 0.0432f, 0.2880000174045563f);
        *(s32 *)(self + 0x10A0) = func_L39_005B43C8(0x4B, 0x64);
        *(s16 *)(self + 0x334) = func_L39_005B43C8(0x4B, 0x64);
        return;
    }
    flag = 1;
    t = -1;
    if (*(s32 *)(self + 0x474) == 2) {
        t = *(s32 *)(self + 0x478);
    }
    if (t == 1) {
        flag = 0;
    }
    if (Dec_0063C468(self + 0x19E4) != 0) {
        return;
    }
    p = *(u8 **)(self + 0x2524);
    c = p[0x43];
    if (c >= 3) {
        return;
    }
    if (*(s32 *)(self + 0x2454) != 0) {
        return;
    }
    if ((u32)(c - 1) < 2) {
        *(s32 *)(self + 0x10A0) = func_L39_005B43C8(0x21, 0x3A);
    }
    if (func_0038CAD0(self + 0x10A0)) {
        *(f32 *)(self + 0x1094) = -func_L39_005B4410(-0.15707964f, 0.43633232f);
        if (*(f32 *)(self + 0x208) < 1.5f) {
            *(f32 *)(self + 0x1098) = func_L39_005B4468(0.87266463f, 1.2217305f);
        } else {
            *(f32 *)(self + 0x1098) = func_L39_005B4468(0.34906584f, 0.99483764f);
        }
        r = func_L39_005B4410(0.0f, 1.0f);
        *(f32 *)(self + 0x10A4) = func_003C4088(0.015f, 0.007f, r);
        *(f32 *)(self + 0x10A8) = func_003C4088(0.29f, 0.3f, r);
        *(s32 *)(self + 0x10A0) = func_L39_005B43C8(0x4B, 0xA7) + (s32)(r * 67.0f);
    }
    if ((u32)((*(u8 **)(self + 0x2524))[0x43] - 1) < 2) {
        if (0.34906584f < *(f32 *)(self + 0x1098)) {
            *(f32 *)(self + 0x1098) = 0.34906584f;
        } else if (*(f32 *)(self + 0x1098) < -0.34906584f) {
            *(f32 *)(self + 0x1098) = -0.34906584f;
        }
        if (0.2617994f < *(f32 *)(self + 0x1094)) {
            *(f32 *)(self + 0x1094) = 0.2617994f;
        }
        if (*(f32 *)(self + 0x1094) < 0.0f) {
            *(f32 *)(self + 0x1094) = 0.0f;
        }
    }
    func_L39_00634E48(self, *(f32 *)(self + 0x10A4), *(f32 *)(self + 0x10A8));
    *(f32 *)(self + 0x9D8) = *(f32 *)(self + 0x1098);
    *(f32 *)(self + 0x9D4) = *(f32 *)(self + 0x1094);
    if (flag) {
        func_L39_00634E28(self, 0.011520001105964184f, 0.4320000410079956f);
        *(f32 *)(self + 0x878) = *(f32 *)(self + 0x9D8) * 0.52f;
        *(f32 *)(self + 0x874) = *(f32 *)(self + 0x9D4) * 0.55f;
    }
}
/* localdecomp:end func_L39_0063C468 */

/* localdecomp:start func_L39_0063C840 */
typedef union Buf_0063C840 {
    u8 b[8];
    u16 h[4];
    u32 w[2];
} Buf_0063C840;

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_0063C840;

extern u8 *D_L39_00292C20[];
__asm__(".extern D_L39_0024112C, 16");
extern s32 D_L39_0024112C;
extern u8 *func_00382348(void *);
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern void func_L39_00632180(void *, void *, s32, f32, f32, f32);
extern void func_L01_00511158(void *, void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_L39_00634E38(u8 *, f32, f32);

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
        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
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
        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
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

void func_L39_0063C840(u8 *o) {
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
        if (((D_L39_0024112C + 4) & 7) == *(s32 *)(o + 0x2544)) {
            bestScore = 100000000.0f;
            bestPri = 0.0f;
            best = 0;
            for (i = 0; (m = D_L39_00292C20[i]) != 0; i++) {
                r = func_00382348(m);
                if (r == 0) {
                    continue;
                }
                if (r[8] == *(s32 *)(o + 0x2548)) {
                    continue;
                }
                d = func_0038CF38(o + 0xA0, m + 0x10);
                if ((f32)r[0x28] < d) {
                    continue;
                }
                ang = func_0038DBA0(func_0038D160(*(f32 *)(m + 0x10) - *(f32 *)(o + 0xA0),
                                                *(f32 *)(m + 0x14) - *(f32 *)(o + 0xA4)),
                                  *(f32 *)(o + 0xB8));
                if (1.919862151145935f < ang) {
                    continue;
                }
                if (1.0471975803375244f < fabs_asm(func_0038D160(func_0038CF38(m + 0x10, o + 0xA0),
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
            func_L39_00632180(o, &pos, 1, 0.0f, 0.0f, 1.2000000476837158f);
            tmp = *(V4_0063C840 *)(*(u8 **)(o + 0x2454) + 0x10);
            func_L01_00511158(o, &tmp, &tmp, 0.5f);
            if (func_003D3CB0(&pos, &tmp, 2, 0, 0)) {
                *(u8 **)(o + 0x2454) = 0;
            }
        }
    }
    if (*(u8 **)(o + 0x2454) != 0 || v) {
    p = v ? *(u8 **)(o + 0x1078) : *(u8 **)(o + 0x2454);
    pos = *(V4_0063C840 *)(p + 0x10);
    q = func_00382348(p);
    if (q != 0) {
        if (v) {
            pos.z += *(f32 *)(q + 0x10);
        } else {
            pos.z += (f32)q[0x2A] * 0.125f;
        }
    }
    if (v) {
        func_L39_00632180(o, &tmp, 1, 0.5f, 0.0f, 0.550000011920929f);
    } else {
        func_L39_00632180(o, &tmp, 1, 0.30000001192092896f, 0.0f, 0.8500000238418579f);
    }
    a = func_0038DB00(func_0038D160(pos.x - tmp.x, pos.y - tmp.y), *(f32 *)(o + 0xB8));
    b = func_0038D160(func_0038CF38(&pos, &tmp), tmp.z - pos.z);
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
        func_L39_00634E38(o, 0.05328000336885452f, 0.4320000410079956f);
        *(f32 *)(o + 0x928) = a;
        func_L39_00634E28(o, 0.05328000336885452f, 0.4320000410079956f);
        *(f32 *)(o + 0x874) = b;
    } else {
        func_L39_00634E48(o, 0.030240001156926155f, 0.3888000249862671f);
        *(f32 *)(o + 0x9D4) = b;
        *(f32 *)(o + 0x9D8) = a * 0.699999988079071f;
        func_L39_00634E38(o, 0.020160000771284103f, 0.4320000410079956f);
        *(f32 *)(o + 0x928) = *(f32 *)(o + 0x9D8) * 0.550000011920929f;
    }
    }
    }
    *(s32 *)(o + 0x1078) = 0;
}
/* localdecomp:end func_L39_0063C840 */

/* localdecomp:start func_L39_0063D0F0 */
s32 func_L39_0063D0F0(s32 arg0, s32 arg1) {
    return arg1;
}
/* localdecomp:end func_L39_0063D0F0 */

/* localdecomp:start func_L39_0063D0F8 */
typedef union Buf_0063D0F8 {
    u8 b[8];
    u32 w[2];
} Buf_0063D0F8;

typedef struct E_0063D0F8 {
    s32 w0;
    u8 pad4[0x18];
} E_0063D0F8;

extern u8 D_L39_004997E0[];
extern E_0063D0F8 D_L39_004840A0[];
extern s32 func_0038CB00(s16 *timer);
extern s32 func_L39_005C2FD0(void *);
extern s32 func_L39_005C3078(void *);
void func_L39_006770F8(u8);

/* reads an obfuscated 32-bit state stored as an index byte at q */
static __inline__ s32 get_state_0063D0F8(u8 *q) {
    Buf_0063D0F8 buf;
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

void func_L39_0063D0F8(u8 *o) {
    func_0038CB00((s16 *)(o + 0x24A6));
    func_0038CB00((s16 *)(o + 0x24A8));
    if ((get_state_0063D0F8(o + 0x19E4) ^ 0x37) == 0) {
        return;
    }
    if (*(s32 *)(o + 0x251C) != 0 || o[0x1A0C] != 0 || D_L39_004840A0[*(s32 *)(o + 0x2544)].w0 != 0) {
        return;
    }
    if (func_L39_005C2FD0(*(void **)(o + 0x2534)) & 0x10) {
        *(s16 *)(o + 0x24A6) = 0x11;
    }
    if (*(s16 *)(o + 0x24A6) != 0) {
        if (func_L39_005C3078(*(void **)(o + 0x2534)) & 0x10) {
            o[0x24AA] = 1;
            func_L39_006770F8(o[0x24C9]);
            if (*(s16 *)(o + 0x24A8) == 0) {
                *(s16 *)(o + 0x24A8) = 0x11;
            }
        }
    }
}
/* localdecomp:end func_L39_0063D0F8 */

/* localdecomp:start func_L39_0063D240 */
void func_L39_006770F8(u8);

void func_L39_0063D240(void *arg0, s32 arg1) {
    if ((((*(u8 *)((u8 *)arg0 + 0x1A14)) != 0) || (arg1 != 0)) && ((*(s32 *)((u8 *)arg0 + 0x251C)) != 0)) {
        *(s32 *)((u8 *)arg0 + 0x251C) = 0;
        *(s8 *)((u8 *)arg0 + 0x24AA) = 1;
        func_L39_006770F8((*(u8 *)((u8 *)arg0 + 0x24C9)));
        if ((*(s16 *)((u8 *)arg0 + 0x24A8)) == 0) {
            *(s16 *)((u8 *)arg0 + 0x24A8) = 0x11;
        }
    }
}
/* localdecomp:end func_L39_0063D240 */

/* localdecomp:start func_L39_0063D2A8 */
typedef union Buf_0063D2A8 {
    u8 b[8];
    u32 w[2];
    u16 h[4];
} Buf_0063D2A8;

extern u8 D_L39_00480760[];
extern u8 D_L39_00480761[];
extern u8 D_L39_00483A00[];
extern u8 D_L39_00483A01[];
extern u32 D_L39_0024B9C8;

typedef struct G_0063D2A8 {
    u8 pad0[0x1A32];
    u8 a1A32[8];
    u8 pad1A3A[0x1A52 - 0x1A3A];
    u8 a1A52[16];
} G_0063D2A8;

/* reads a 16-bit value stored obfuscated in table 0x480760 */
static __inline__ s32 GetA_0063D2A8(u8 *q) {
    Buf_0063D2A8 buf;
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
        *d++ = D_L39_00480760[((k + i) & 7) * 193 + m];
    }
    a = buf.w[0] ^ (u32)q;
    b = buf.w[1] ^ a;
    buf.w[0] = a;
    buf.w[1] = (b >> 16) / (((b ^ (b >> 16)) << 16) + 1);
    return buf.w[1];
}

/* stores a value obfuscated in table 0x480760 */
static __inline__ void SetA_0063D2A8(u8 *q, s32 v) {
    u8 *hk = q;
    Buf_0063D2A8 buf;
    u32 key;
    s32 t;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    if (*q == 0) {
        *q = ++D_L39_00480760[0];
    } else {
        t = *q;
        *q = D_L39_00480761[0];
        D_L39_00480761[0] = t;
    }
    key = ((u32 *)D_L39_00480760)[((u32)hk * D_L39_0024B9C8) % 386];
    k = ((u32)q - *q) & 7;
    buf.w[0] = (u32)q ^ key;
    buf.w[1] = ((v & 0xFFFF) | (v << 16)) ^ key;
    m = *q + 1;
    d = buf.b;
    for (i = 0; i < 24; i += 3) {
        D_L39_00480760[((k + i) & 7) * 193 + m] = *d++;
    }
}

/* reads a byte stored obfuscated in table 0x483A00 */
static __inline__ s16 GetCb_0063D2A8(u8 *q) {
    Buf_0063D2A8 buf;
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
        s32 ix = ((k + i) & 7) * 209 + m;
        *d++ = D_L39_00483A00[ix];
    }
    a = buf.w[0] ^ (u32)q;
    b = buf.w[1] ^ a;
    buf.w[0] = a;
    buf.w[1] = (b >> 16) / (((b ^ (b >> 16)) << 16) + 1);
    return buf.b[4];
}

/* reads a halfword stored obfuscated in table 0x483A00 */
static __inline__ s16 GetCh_0063D2A8(u8 *p) {
    u8 *q = p;
    Buf_0063D2A8 buf;
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

/* stores a byte obfuscated in table 0x483A00 */
static __inline__ void SetCb_0063D2A8(u8 *q, u8 v) {
    u8 *hk = q;
    Buf_0063D2A8 buf;
    u32 key;
    s32 t;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    if (*q == 0) {
        *q = ++D_L39_00483A00[0];
    } else {
        t = *q;
        *q = D_L39_00483A01[0];
        D_L39_00483A01[0] = t;
    }
    key = ((u32 *)D_L39_00483A00)[((u32)hk * D_L39_0024B9C8) % 418];
    k = ((u32)q - *q) & 7;
    buf.b[4] = v;
    buf.w[0] = (u32)q ^ key;
    buf.w[1] = ((buf.w[1] & 0xFFFF) | (buf.w[1] << 16)) ^ key;
    m = *q + 1;
    d = buf.b;
    for (i = 0; i < 24; i += 3) {
        s32 ix = ((k + i) & 7) * 209 + m;
        D_L39_00483A00[ix] = *d++;
    }
}

static __inline__ void CopyCb_0063D2A8(u8 *dst, u8 *src) {
    u8 *q = src;

    SetCb_0063D2A8(dst, GetCb_0063D2A8(q));
}

void func_L39_0063D2A8(u8 *o) {
    G_0063D2A8 *g = (G_0063D2A8 *)o;
    s32 idx;
    s32 i;
    s32 cur;

    if (o[0x24AA] == 0) {
        return;
    }
    o[0x24AA] = 0;
    *(s16 *)(o + 0x24A6) = 0;
    *(s16 *)(o + 0x24A8) = 0;
    *(s16 *)(o + 0x31E) = 0;
    if (*(s32 *)(o + 0x478) == 10) {
        if (o[0x1A14] == 0) {
            return;
        }
        SetA_0063D2A8(o + 0x1A19, *(s32 *)(o + 0x18D0));
        cur = GetA_0063D2A8(o + 0x1A1F);
        if (GetA_0063D2A8(o + 0x1A19) == cur) {
            SetA_0063D2A8(o + 0x1A1F, 0);
        }
        return;
    }
    if (GetCb_0063D2A8(&g->a1A32[1]) == 0) {
        if (*(s32 *)(o + 0x478) != 11) {
            return;
        }
        if (GetCb_0063D2A8(&g->a1A32[0]) == 0) {
            return;
        }
    }
    if (o[0x1A14] != 0) {
        if (o[0x1A13] != 0) {
            SetA_0063D2A8(o + 0x1A25, GetCb_0063D2A8(&g->a1A32[1]));
        } else if (*(s32 *)(o + 0x478) == 11) {
            SetA_0063D2A8(o + 0x1A19, GetCb_0063D2A8(&g->a1A32[0]));
            return;
        } else {
            SetA_0063D2A8(o + 0x1A19, GetCb_0063D2A8(&g->a1A32[1]));
        }
    }
    idx = GetCb_0063D2A8(&g->a1A32[0]);
    if (GetCh_0063D2A8(&g->a1A52[idx]) == 0 && idx != 9) {
        for (i = 0; i < 7; i++) {
            CopyCb_0063D2A8(&g->a1A32[i], &g->a1A32[i + 1]);
        }
        return;
    }
    CopyCb_0063D2A8(&g->a1A32[0], &g->a1A32[1]);
    if (GetCb_0063D2A8(&g->a1A32[2]) != 0) {
        CopyCb_0063D2A8(&g->a1A32[1], &g->a1A32[2]);
        SetCb_0063D2A8(&g->a1A32[2], idx);
    } else {
        SetCb_0063D2A8(&g->a1A32[1], idx);
    }
}
/* localdecomp:end func_L39_0063D2A8 */

/* localdecomp:start func_L39_0063E3D0 */
typedef union Buf_0063E3D0 {
    u8 b[8];
    u32 w[2];
    u16 h[4];
} Buf_0063E3D0;

typedef struct Ent_0063E3D0 {
    u8 pad0[8];
    u8 b8;
    u8 pad9[0x80 - 9];
} Ent_0063E3D0;

typedef struct G_0063E3D0 {
    u8 pad0[0x1A19];
    u8 b1A19;
    u8 pad1A1A[0x1A32 - 0x1A1A];
    u8 a1A32[8];
} G_0063E3D0;

extern u8 D_L39_00480760[];
extern u8 D_L39_00480761[];
extern u8 D_L39_00483A00[];
extern u8 D_L39_00483A01[];
extern u32 D_L39_0024B9C8;
extern Ent_0063E3D0 D_L39_0049C890[];

static __inline__ void PrepA_0063E3D0(u8 *q) {
    s32 t;
    if (*q == 0) {
        *q = ++D_L39_00480760[0];
    } else {
        t = *q;
        *q = D_L39_00480761[0];
        D_L39_00480761[0] = t;
    }
}

static __inline__ void PrepC_0063E3D0(u8 *q) {
    s32 t;
    if (*q == 0) {
        *q = ++D_L39_00483A00[0];
    } else {
        t = *q;
        *q = D_L39_00483A01[0];
        D_L39_00483A01[0] = t;
    }
}

static __inline__ void Set16A_0063E3D0(u8 *q, s32 v) {
    Buf_0063E3D0 buf;
    u32 key;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    PrepA_0063E3D0(q);
    key = ((u32 *)D_L39_00480760)[((u32)q * D_L39_0024B9C8) % 386];
    k = ((u32)q - *q) & 7;
    buf.w[0] = (u32)q ^ key;
    buf.w[1] = ((v & 0xFFFF) | (v << 16)) ^ key;
    m = *q + 1;
    d = buf.b;
    for (i = 0; i < 24; i += 3) {
        D_L39_00480760[((k + i) & 7) * 193 + m] = *d++;
    }
}

static __inline__ u8 DecBC_0063E3D0(u8 *q) {
    Buf_0063E3D0 buf;
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
        s32 ix = ((k + i) & 7) * 209 + m;
        *d++ = D_L39_00483A00[ix];
    }
    a = buf.w[0] ^ (u32)q;
    b = buf.w[1] ^ a;
    buf.w[0] = a;
    buf.w[1] = (b >> 16) / (((b ^ (b >> 16)) << 16) + 1);
    return buf.b[4];
}

static __inline__ void SetBC_0063E3D0(u8 *q, u8 v) {
    u8 *hk = q;
    Buf_0063E3D0 buf;
    u32 key;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    PrepC_0063E3D0(q);
    key = ((u32 *)D_L39_00483A00)[((u32)hk * D_L39_0024B9C8) % 418];
    k = ((u32)q - *q) & 7;
    buf.b[4] = v;
    buf.w[0] = (u32)q ^ key;
    buf.w[1] = ((buf.w[1] & 0xFFFF) | (buf.w[1] << 16)) ^ key;
    m = *q + 1;
    d = buf.b;
    for (i = 0; i < 24; i += 3) {
        s32 ix = ((k + i) & 7) * 209 + m;
        D_L39_00483A00[ix] = *d++;
    }
}

static __inline__ void CopyBC_0063E3D0(u8 *dst, u8 *src) {
    u8 *q = src;

    SetBC_0063E3D0(dst, DecBC_0063E3D0(q));
}

void func_L39_0063E3D0(void *arg0, s32 v) {
    G_0063E3D0 *g = arg0;
    s32 i;
    s32 j;
    u8 id;

    Set16A_0063E3D0(&g->b1A19, v);
    if ((D_L39_0049C890 + v)->b8 == 0 && v != 12) {
        return;
    }
    id = v;
    for (i = 0; i < 8; i++) {
        if (DecBC_0063E3D0(&g->a1A32[i]) == id) {
            break;
        }
    }
    if (i == 0) {
        return;
    }
    if (i < 8) {
        for (j = i; j < 7; j++) {
            CopyBC_0063E3D0(&g->a1A32[j], &g->a1A32[j + 1]);
        }
    }
    for (i = 7; i > 0; i--) {
        CopyBC_0063E3D0(&g->a1A32[i], &g->a1A32[i - 1]);
    }
    SetBC_0063E3D0(&g->a1A32[0], id);
}
/* localdecomp:end func_L39_0063E3D0 */
