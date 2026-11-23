#include "common.h"

/* NTSC-U counterpart of func_L39_0065F4B8 (src/levels/shared/L39_0065D0A0.c) */
typedef struct Glob_0065D0A0 {
    u8 pad0[0xA4];
    u8 bA4[4];
} Glob_0065D0A0;
extern Glob_0065D0A0 D_001A5990;
extern u8 D_L39_004998A0[];
extern u8 D_L39_00483AC0[];
extern s32 func_L39_005C2098(s32, s32);
extern u8 D_L39_004998A0[];

/* localdecomp:start func_L39_0065CBE0 */
typedef struct V_0065F4B8 {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} __attribute__((aligned(16))) V_0065F4B8;

typedef union Buf_0065F4B8 {
    u8 b[8];
    u32 w[2];
    u16 h[4];
} Buf_0065F4B8;

typedef struct Hdr_0065F4B8 {
    unsigned long x : 16;
    unsigned long y : 16;
    unsigned long z : 16;
    unsigned long seq : 8;
    unsigned long f56 : 1;
    unsigned long f57 : 1;
    unsigned long f58 : 2;
    unsigned long f60 : 4;
} Hdr_0065F4B8;

typedef struct Pkt_0065F4B8 {
    s32 w[4];
    Hdr_0065F4B8 hdr;
    u8 data[0x88];
} Pkt_0065F4B8;

typedef struct VT_0065F4B8 {
    u8 pad0[0x28];
    void (*fn28)(void *);
} VT_0065F4B8;

typedef struct Pad_0065F4B8 {
    u8 pad0[0x1A0];
    s32 w1A0;
    u8 pad1A4[0x1CC - 0x1A4];
    s32 w1CC;
} Pad_0065F4B8;

typedef struct O2530_0065F4B8 {
    u8 pad0[0x27B];
    u8 b27B;
} O2530_0065F4B8;

typedef struct O24_0065F4B8 {
    u8 pad0[0x10];
    s32 w10;
} O24_0065F4B8;

typedef struct O424_0065F4B8 {
    u8 pad0[0x24];
    O24_0065F4B8 *p24;
    u8 pad28[0x98 - 0x28];
    s32 w98;
} O424_0065F4B8;

typedef struct In_0065F4B8 {
    u8 pad0[0x48];
    s32 w48;
    u8 pad4C[0x80 - 0x4C];
    u16 h80;
    u16 h82;
    u16 h84;
} In_0065F4B8;

typedef struct O2558_0065F4B8 {
    u8 pad0[4];
    In_0065F4B8 *p4;
    u8 pad8[0x160 - 8];
    s32 w160;
    s32 w164;
    u8 pad168[4];
    s32 s16C;
    V_0065F4B8 v170;
    V_0065F4B8 v180;
    V_0065F4B8 v190;
} O2558_0065F4B8;

typedef struct Core_0065F4B8 {
    u8 pad0[4];
    s32 w4;
    u8 pad8[0x128 - 8];
    s32 w128;
    s32 w12C;
    u8 pad130[0x170 - 0x130];
    s32 w170;
    u8 pad174[0x7D0 - 0x174];
    s32 w7D0;
    u8 b7D4;
} Core_0065F4B8;

typedef struct E_0065F4B8 {
    s32 w0;
    s32 w4;
    s32 w8;
    u8 padC[0x1C - 0xC];
} E_0065F4B8;

typedef struct S_0065F4B8 {
    /* 0x0000 */ u8 pad0[0x14];
    /* 0x0014 */ VT_0065F4B8 *vt;
    /* 0x0018 */ u8 pad18[0xA0 - 0x18];
    /* 0x00A0 */ V_0065F4B8 pos;
    /* 0x00B0 */ V_0065F4B8 vB0;
    /* 0x00C0 */ u8 padC0[0x2A8 - 0xC0];
    /* 0x02A8 */ f32 f2A8;
    /* 0x02AC */ f32 f2AC;
    /* 0x02B0 */ u8 pad2B0[0x314 - 0x2B0];
    /* 0x0314 */ u8 b314;
    /* 0x0315 */ u8 pad315[0x320 - 0x315];
    /* 0x0320 */ s16 h320;
    /* 0x0322 */ u8 pad322[0x370 - 0x322];
    /* 0x0370 */ s16 h370;
    /* 0x0372 */ u8 pad372[0x424 - 0x372];
    /* 0x0424 */ O424_0065F4B8 *p424;
    /* 0x0428 */ u8 pad428[0x478 - 0x428];
    /* 0x0478 */ s32 s478;
    /* 0x047C */ u8 pad47C[0x1540 - 0x47C];
    /* 0x1540 */ u8 x1540[0x15EE - 0x1540];
    /* 0x15EE */ u8 b15EE;
    /* 0x15EF */ u8 pad15EF[0x19E0 - 0x15EF];
    /* 0x19E0 */ s16 h19E0;
    /* 0x19E2 */ s16 h19E2;
    /* 0x19E4 */ u8 b19E4;
    /* 0x19E5 */ u8 pad19E5;
    /* 0x19E6 */ u8 b19E6;
    /* 0x19E7 */ u8 pad19E7[0x1A08 - 0x19E7];
    /* 0x1A08 */ u8 b1A08;
    /* 0x1A09 */ u8 pad1A09;
    /* 0x1A0A */ u8 b1A0A;
    /* 0x1A0B */ u8 b1A0B;
    /* 0x1A0C */ u8 pad1A0C[2];
    /* 0x1A0E */ u8 b1A0E;
    /* 0x1A0F */ u8 pad1A0F[4];
    /* 0x1A13 */ u8 b1A13;
    /* 0x1A14 */ u8 pad1A14[0x1A40 - 0x1A14];
    /* 0x1A40 */ u8 b1A40;
    /* 0x1A41 */ u8 b1A41;
    /* 0x1A42 */ u8 pad1A42[0x1A52 - 0x1A42];
    /* 0x1A52 */ u8 a1A52[16];
    /* 0x1A62 */ u8 pad1A62[0x2378 - 0x1A62];
    /* 0x2378 */ s32 hist[8];
    /* 0x2398 */ s32 idx;
    /* 0x239C */ s32 cnt;
    /* 0x23A0 */ u8 pad23A0[0x2450 - 0x23A0];
    /* 0x2450 */ s32 s2450;
    /* 0x2454 */ u8 pad2454[0x24C9 - 0x2454];
    /* 0x24C9 */ u8 b24C9;
    /* 0x24CA */ u8 pad24CA[0x24FE - 0x24CA];
    /* 0x24FE */ u8 b24FE;
    /* 0x24FF */ u8 pad24FF;
    /* 0x2500 */ u8 b2500;
    /* 0x2501 */ u8 pad2501[0x251C - 0x2501];
    /* 0x251C */ s32 s251C;
    /* 0x2520 */ u8 pad2520[4];
    /* 0x2524 */ void *p2524;
    /* 0x2528 */ u8 pad2528[8];
    /* 0x2530 */ O2530_0065F4B8 *p2530;
    /* 0x2534 */ Pad_0065F4B8 *p2534;
    /* 0x2538 */ f32 f2538;
    /* 0x253C */ f32 f253C;
    /* 0x2540 */ f32 f2540;
    /* 0x2544 */ s32 s2544;
    /* 0x2548 */ u8 pad2548[4];
    /* 0x254C */ s32 s254C;
    /* 0x2550 */ s32 s2550;
    /* 0x2554 */ u8 pad2554[4];
    /* 0x2558 */ O2558_0065F4B8 *p2558;
    /* 0x255C */ u8 pad255C[0x430C - 0x255C];
    /* 0x430C */ u8 x430C[0x431C - 0x430C];
    /* 0x431C */ u8 x431C[8];
    /* 0x4324 */ unsigned long w4324 : 32;
    /* 0x4328 */ u8 pad4328[0x44EC - 0x4328];
    /* 0x44EC */ u8 b44EC;
    /* 0x44ED */ u8 b44ED;
    /* 0x44EE */ u8 b44EE;
    /* 0x44EF */ u8 b44EF;
    /* 0x44F0 */ u8 pad44F0[0x4500 - 0x44F0];
} S_0065F4B8;

__asm__(".extern D_L39_002412A0, 16");
extern s32 *D_L39_002412A0;
extern s32 D_L39_002412AC;
__asm__(".extern D_L39_0024635C, 4");
extern s32 D_L39_0024635C;
__asm__(".extern D_L39_0024074C, 16");
extern s32 D_L39_0024074C;
extern s32 D_L39_00352A44 __attribute__((section(".data")));
extern E_0065F4B8 D_L39_00484160[];
extern S_0065F4B8 D_L39_002FB100[];
extern Core_0065F4B8 D_001A5E50_0065CBE0;

extern f32 func_L01_0040C018(void *, void *);
extern void func_L39_0065EAF8();
extern void func_L39_0065EBB0(void *);
extern void func_L39_0061FCB0(void *);
extern void func_L01_0044ECE0(s32, s32, s32);
extern void func_L39_006201C0(void *);
extern void func_L39_00620458(void *);
extern void func_L39_00620BD8(void *, void *, void *, void *);
extern void func_L39_0065EEF0(u8 *);
extern void func_L39_00627808(void *, s32);
extern void func_L39_00654650(void *);
extern void func_L39_0063C5F8_0065CBE0(void *);
extern void func_L39_006379E8(void *);
extern void func_L39_00636888(void *);
extern s32 func_L39_00637548(void *);
extern void func_L39_0061F020(void *);
extern void func_L39_00639C20(void *);
extern void func_L39_00639FF8(void *);
extern void func_L39_0063C600_0065CBE0(void *);
extern void func_L39_0063C3B0(void *);
extern void func_L35_003A3AA8(void *);
extern void func_L39_006385C8(void *);
extern void func_L39_00629060(void *, s32);
extern void func_L39_0063C608(void *);
extern void func_L39_0063D420(void *);
extern void func_L39_0061EBE8(void *);
extern void func_L39_0061EE60(void *);
extern void func_L39_0062F648(void *);
extern void func_L39_00637CF8(void *);
extern void func_L39_006424D8(void *);
extern void func_L01_004405F4(void *);
extern void func_L39_0063C850_0065CBE0(void *);
extern void func_L39_0063C858(void *);
extern void func_L39_00638860(void *);
extern s32 func_L39_0066C540(void *, void *);
extern void func_00388550(void *, void *, s32);
extern void func_L39_005B83E8(f32 *v, s32 *out);
extern void func_0014AD08(s32, s32, s32, s32, s32, void *);
extern void func_L39_00674960(s32, s32);
extern void func_L39_00674910(s32, s32);
extern void func_L39_0065F0B0(u8 *);
extern void func_L39_00671848(void *);


static __inline__ u32 Dec_0065F4B8(u8 *q) {
    Buf_0065F4B8 buf;
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
        *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
    }
    a = buf.w[0] ^ (u32)q;
    b = buf.w[1] ^ a;
    buf.w[0] = a;
    buf.w[1] = b;
    return b;
}

static __inline__ s32 DecEq_0065F4B8(u8 *q, s32 v) {
    return Dec_0065F4B8(q) == v;
}

static __inline__ s16 Dec16_0065F4B8(u8 *q) {
    Buf_0065F4B8 buf;
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

static __inline__ s16 Dec2_0065F4B8(u8 *p) {
    u8 *q = p;
    Buf_0065F4B8 buf;
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
        s32 x = ((k + i) & 7) * 209 + m;

        *d++ = D_L39_00483AC0[x];
    }
    a = buf.w[0] ^ (u32)q;
    b = buf.w[1] ^ a;
    buf.w[0] = a;
    buf.w[1] = (b >> 16) / (((b ^ (b >> 16)) << 16) + 1);
    return buf.h[2];
}


static __inline__ s32 Busy_0065F4B8(S_0065F4B8 *s) {
    return DecEq_0065F4B8(&s->b19E4, 1) || DecEq_0065F4B8(&s->b19E4, 0x1D) || s->b24FE != 0 ||
           s->b2500 != 0;
}

void func_L39_0065CBE0(S_0065F4B8 *s) {
    V_0065F4B8 v;
    f32 thr;
    s32 c;
    s32 x;
    s32 n;
    s32 i;
    s32 j;
    u8 f;
    u8 host;

    v.x = s->f2538;
    v.y = s->f253C;
    v.z = s->f2540;
    if (100.0f < func_L01_0040C018(&v, &s->pos)) {
        s->pos = v;
    }
    func_L39_0065EAF8(s);
    func_L39_0065EBB0(s);
    s->h19E2 = 0;
    s->h19E0 = 0;
    func_L39_0061FCB0(s);
    if (D_001A5E50_0065CBE0.w170 == 0 && D_001A5E50_0065CBE0.w12C >= 2 &&
        D_001A5E50_0065CBE0.w7D0 < D_001A5E50_0065CBE0.w128 - 3000 && D_L39_00352A44 > 0 &&
        D_L39_00352A44 + 25000 < D_001A5E50_0065CBE0.w128) {
        s->p2534->w1CC = 1;
        s->h320 = 2;
        D_L39_00484160[s->s2544].w0 = 5;
        D_L39_00484160[s->s2544].w8 = 2;
        func_L01_0044ECE0(0x18D2, 2, 0);
    }
    s->vt->fn28(s);
    func_L39_006201C0(s);
    func_L39_00620458(s);
    func_L39_00620BD8(s, &s->pos, &s->vB0, s->x1540);
    func_L39_0065EEF0((u8 *)s);
    thr = 2.5f;
    if (s->h370 == -1) {
        thr = 10.0f;
    }
    c = s->f2A8 == 0.0f || thr < s->f2AC;
    if (!DecEq_0065F4B8(&s->b19E6, 0x14) && !DecEq_0065F4B8(&s->b19E4, 0x83) && (s->s478 == 11 || c)) {
        func_L39_00627808(s, c);
        if (s->s478 != 11 && c && (s->b1A0E == 0 || s->s251C != 0) && s->b1A0B == 0 &&
            s->b15EE != 0) {
            s->b1A13 = 1;
        }
    }
    func_L39_00654650(s);
    func_L39_0063C5F8_0065CBE0(s);
    func_L39_006379E8(s);
    func_L39_00636888(s);
    if (s->b1A08 != 0 || func_L39_00637548(s) != 0 || DecEq_0065F4B8(&s->b19E4, 1) ||
        DecEq_0065F4B8(&s->b19E4, 0x1D) || s->s2544 == (D_L39_002412AC & 7)) {
        func_L39_0061F020(s);
    }
    func_L39_00639C20(s);
    func_L39_00639FF8(s);
    func_L39_0063C600_0065CBE0(s);
    func_L39_0063C3B0(s);
    func_L35_003A3AA8(s);
    func_L39_006385C8(s);
    func_L39_00629060(s, 0);
    func_L39_0063C608(s);
    func_L39_0063D420(s);
    x = func_L39_00637548(s);
    if (s->b1A0A != 0 || (x == 2 && !DecEq_0065F4B8(&s->b19E6, 0x14)) ||
        (x == 1 && (f = Busy_0065F4B8(s)) != 0) ||
        Dec16_0065F4B8(&s->b314) != 0) {
        func_L39_0061EBE8(s);
    } else {
        func_L39_0061EE60(s);
    }
    func_L39_0062F648(s);
    func_L39_00637CF8(s);
    func_L39_006424D8(s);
    func_L01_004405F4(s->p2524);
    func_L39_0063C850_0065CBE0(s);
    func_L39_0063C858(s);
    if (func_L39_00637548(s) != 0 && s->s2450 != 4 && s->s2450 != 0x51) {
        s->s2450 = 0x20;
    } else if (s->s2450 == 0x20) {
        s->s2450 = 0;
    }
    func_L39_00638860(s);
    if (s->s2544 == 0 && s->b44EC < 5) {
        if ((s->p2534->w1A0 & func_L39_005C2098(0x40, 0)) == 0 || s->b44EC != 0) {
            s->b44EC++;
        }
    } else {
        Pkt_0065F4B8 pkt;

        if (D_L39_0024635C++ > 600) {
            D_L39_0024635C = 0;
        }
        n = func_L39_0066C540(s->x430C, pkt.data);
        if (n != 0) {
            pkt.hdr.f57 = s->b24C9;
            pkt.hdr.f58 = 0;
            if (DecEq_0065F4B8(&s->b19E4, 0x31) &&
                !(host = s->p2530 != 0 ? (s->p2530->b27B != 0 && DecEq_0065F4B8(&s->b19E4, 0x31)) : 0)) {
                pkt.hdr.f58 = 1;
                func_00388550(&pkt, s->x431C, 8);
            } else {
                s32 k;

                for (k = 0; k < 4; k++) {
                    s32 m = (s->idx - (4 - k) + 8) % 8;
                    if (s->cnt - 1 < m) {
                        m = 0;
                    }
                    pkt.w[k] = s->hist[m];
                }
            }
            pkt.hdr.x = s->pos.x * 64.0f + 0.5f;
            pkt.hdr.y = s->pos.y * 64.0f + 0.5f;
            pkt.hdr.z = s->pos.z * 64.0f + 0.5f;
            if (--s->b44EF == 0) {
                s32 packed;

                s->b44EF = 5;
                func_L39_005B83E8(&s->vB0.x, &packed);
                func_00388550(&pkt.data[n], &packed, 4);
                n += 4;
                pkt.data[n++] = Dec_0065F4B8(&s->b19E4);
                func_00388550(&pkt.data[n], &s->pos, 12);
                n += 12;
                pkt.hdr.f56 = 1;
            } else {
                pkt.hdr.f56 = 0;
            }
            pkt.hdr.seq = s->b44ED++;
            pkt.hdr.f60 = (u8)s->w4324;
            s->b44EE = 0;
            if (D_001A5E50_0065CBE0.w170 == 0) {
                func_0014AD08(D_001A5E50_0065CBE0.b7D4 | 0x80, D_001A5E50_0065CBE0.w4, -1, D_L39_0024074C,
                              n + 0x18, &pkt);
            }
        } else {
            s->b44EE++;
        }
    }
    if (s->p2558->s16C >= 0 && D_001A5E50_0065CBE0.w128 >= s->p2558->s16C) {
        s->p2558->v190 = s->p2558->v180;
        s->p2558->w160 = s->p2558->w164;
        s->p2558->v180 = s->p2558->v170;
        s->p2558->w164 = s->p2558->s16C - 0xF5;
        s->p2558->s16C = -1;
    }
    for (i = 0; i < *D_L39_002412A0; i++) {
        if (&D_L39_002FB100[i] == s) {
            break;
        }
    }
    if (DecEq_0065F4B8(&s->b19E6, 0x14)) {
        func_L39_00674960(i, 1);
        func_L39_00674910(i, 1);
    } else {
        func_L39_00674960(i, 0);
        func_L39_00674910(i, 0);
    }
    if (s->p2558 != 0) {
        func_L39_0065F0B0((u8 *)s);
        s->p2558->p4->w48 = s->s478;
        func_L39_00671848(s);
        s->p2558->p4->h84 = 0;
        for (j = 0; j < 16; j++) {
            if (Dec2_0065F4B8(&s->a1A52[j]) != 0 || j == 11 || j == 14 || j == 15) {
                s->p2558->p4->h84 |= 1 << j;
            }
        }
        s->p2558->p4->h80 = Dec2_0065F4B8(&s->b1A40);
        s->p2558->p4->h82 = Dec2_0065F4B8(&s->b1A41);
    }
    if (s->b1A0A == 0 && D_001A5990.bA4[s->s2544] == 2 && !DecEq_0065F4B8(&s->b19E4, 0x90)) {
        s->p424->w98 = s->p424->p24->w10;
    }
    if (++s->s2550 > 120) {
        s32 st = s->s254C;
        if (st == 1 || st == 3 || st == 4 || st == 2) {
            if (st == 3) {
                s->s254C = 5;
            } else if (st == 4) {
                s->s254C = 6;
            } else {
                s->s254C = 0;
            }
        }
    }
    s->f2538 = s->pos.x;
    s->f253C = s->pos.y;
    s->f2540 = s->pos.z;
}
/* localdecomp:end func_L39_0065CBE0 */
