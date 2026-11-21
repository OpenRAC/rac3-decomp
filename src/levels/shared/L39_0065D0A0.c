#include "common.h"

typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    u8 b0C;
    u8 b0D;
    u8 b0E;
} S_006618D8;
typedef struct {
    u8 pad0[4];
    s32 w4;
    u8 pad8[0x128 - 8];
    s32 w128;
    u8 pad12C[0x170 - 0x12C];
    s32 w170;
    u8 pad174[0x7D4 - 0x174];
    u8 b7D4;
} S_1A5CD0_006618D8;

/* localdecomp:start func_L39_0065D0A0 */
typedef struct VT_0065D0A0 {
    u8 pad0[0x34];
    void (*fn34)(void *, s32, s32, s32, s32);
} VT_0065D0A0;

typedef struct Aux_0065D0A0 {
    u8 pad0[0x1A0];
    u32 w1A0;
    u32 w1A4;
} Aux_0065D0A0;

typedef struct Obj450_0065D0A0 {
    u8 pad0[0x20];
    u8 b20;
} Obj450_0065D0A0;

typedef struct Obj2524_0065D0A0 {
    u8 pad0[0x43];
    u8 b43;
} Obj2524_0065D0A0;

typedef struct Rec_0065D0A0 {
    u8 pad0[0xC];
    s32 i0C;
    s32 i10;
    u8 pad14[0x18];
} Rec_0065D0A0;

typedef union Buf_0065D0A0 {
    u8 b[8];
    u32 w[2];
    u16 h[4];
} Buf_0065D0A0;

typedef struct Self_0065D0A0 {
    /* 0x000 */ u8 pad0[0x14];
    /* 0x014 */ VT_0065D0A0 *vt;
    /* 0x018 */ u8 pad18[0xE0 - 0x18];
    /* 0x0E0 */ u8 unkE0[0x2AC - 0xE0];
    /* 0x2AC */ f32 f2AC;
    /* 0x2B0 */ u8 pad2B0[0x2D0 - 0x2B0];
    /* 0x2D0 */ s32 s2D0;
    /* 0x2D4 */ u8 pad2D4[4];
    /* 0x2D8 */ s16 h2D8;
    /* 0x2DA */ u8 pad2DA[4];
    /* 0x2DE */ s16 h2DE;
    /* 0x2E0 */ u8 pad2E0[0x2F0 - 0x2E0];
    /* 0x2F0 */ s32 s2F0;
    /* 0x2F4 */ u8 pad2F4[0x320 - 0x2F4];
    /* 0x320 */ s16 h320;
    /* 0x322 */ u8 pad322[0x332 - 0x322];
    /* 0x332 */ s16 h332;
    /* 0x334 */ u8 pad334[4];
    /* 0x338 */ unsigned long q338;
    /* 0x340 */ u8 pad340[0x378 - 0x340];
    /* 0x378 */ u8 b378;
    /* 0x379 */ u8 pad379[0x450 - 0x379];
    /* 0x450 */ Obj450_0065D0A0 *p450;
    /* 0x454 */ u8 pad454[0x460 - 0x454];
    /* 0x460 */ s32 s460;
    /* 0x464 */ u8 pad464[0x46A - 0x464];
    /* 0x46A */ u8 b46A;
    /* 0x46B */ u8 pad46B[0x470 - 0x46B];
    /* 0x470 */ s32 s470;
    /* 0x474 */ s32 s474;
    /* 0x478 */ s32 s478;
    /* 0x47C */ u8 pad47C[0x61C - 0x47C];
    /* 0x61C */ s32 s61C;
    /* 0x620 */ u8 pad620[8];
    /* 0x628 */ f32 f628;
    /* 0x62C */ u8 pad62C[0x730 - 0x62C];
    /* 0x730 */ u8 unk730[0x748 - 0x730];
    /* 0x748 */ s32 s748;
    /* 0x74C */ u8 pad74C[8];
    /* 0x754 */ s32 s754;
    /* 0x758 */ u8 pad758[0x107C - 0x758];
    /* 0x107C */ s16 h107C;
    /* 0x107E */ u8 pad107E[0x1310 - 0x107E];
    /* 0x1310 */ s32 s1310;
    /* 0x1314 */ u8 pad1314[0x14AC - 0x1314];
    /* 0x14AC */ u8 b14AC;
    /* 0x14AD */ u8 pad14AD;
    /* 0x14AE */ u8 b14AE;
    /* 0x14AF */ u8 pad14AF[0x14E4 - 0x14AF];
    /* 0x14E4 */ s32 s14E4;
    /* 0x14E8 */ u8 pad14E8[0x15EE - 0x14E8];
    /* 0x15EE */ u8 b15EE;
    /* 0x15EF */ u8 pad15EF[0x18D4 - 0x15EF];
    /* 0x18D4 */ s32 s18D4;
    /* 0x18D8 */ u8 pad18D8[0x18F0 - 0x18D8];
    /* 0x18F0 */ f32 f18F0;
    /* 0x18F4 */ u8 pad18F4[0x19E4 - 0x18F4];
    /* 0x19E4 */ u8 b19E4;
    /* 0x19E5 */ u8 pad19E5;
    /* 0x19E6 */ u8 b19E6;
    /* 0x19E7 */ u8 pad19E7[0x1A05 - 0x19E7];
    /* 0x1A05 */ u8 b1A05;
    /* 0x1A06 */ u8 pad1A06;
    /* 0x1A07 */ u8 b1A07;
    /* 0x1A08 */ u8 pad1A08[0x1A0C - 0x1A08];
    /* 0x1A0C */ u8 b1A0C;
    /* 0x1A0D */ u8 b1A0D;
    /* 0x1A0E */ u8 pad1A0E[0x1A14 - 0x1A0E];
    /* 0x1A14 */ u8 b1A14;
    /* 0x1A15 */ u8 pad1A15[0x1A40 - 0x1A15];
    /* 0x1A40 */ u8 b1A40;
    /* 0x1A41 */ u8 pad1A41[0x2448 - 0x1A41];
    /* 0x2448 */ s32 s2448;
    /* 0x244C */ u8 pad244C[0x2468 - 0x244C];
    /* 0x2468 */ f32 f2468;
    /* 0x246C */ u8 pad246C[0x24A0 - 0x246C];
    /* 0x24A0 */ s16 h24A0;
    /* 0x24A2 */ u8 pad24A2[0x24FE - 0x24A2];
    /* 0x24FE */ u8 b24FE;
    /* 0x24FF */ u8 b24FF;
    /* 0x2500 */ u8 b2500;
    /* 0x2501 */ u8 pad2501[0x251C - 0x2501];
    /* 0x251C */ s32 s251C;
    /* 0x2520 */ u8 pad2520[4];
    /* 0x2524 */ Obj2524_0065D0A0 *p2524;
    /* 0x2528 */ u8 pad2528[0x2534 - 0x2528];
    /* 0x2534 */ Aux_0065D0A0 *p2534;
    /* 0x2538 */ u8 pad2538[0x2544 - 0x2538];
    /* 0x2544 */ s32 s2544;
} Self_0065D0A0;

typedef struct Glob_0065D0A0 {
    u8 pad0[0xA4];
    u8 bA4[4];
} Glob_0065D0A0;

extern Glob_0065D0A0 D_001A5810;
extern u8 D_L39_004997E0[];
extern u8 D_L39_00483A00[];
extern Rec_0065D0A0 D_L39_0047A8A8[];

extern s32 func_L01_004606E8(s32, s32, void *, void *);
extern s32 func_L39_005C42E8(s32, s32);
extern s32 func_L39_0063BDE0(void *, void *);
extern void func_L39_0063D240(void *, s32);
extern void func_L39_0062B4A8(void *, s32, s32, s32, f32);
extern s32 func_L39_006223B0(void *, s32);
extern s32 func_L39_00673160(void *, s32, s32, s32);
extern void func_L39_00621D60(void *, s32);
extern void func_L39_005F33E0(s32, s32, void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_0038CB00(void *);

static inline u32 Dec_0065D0A0(u8 *q) {
    Buf_0065D0A0 buf;
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

static inline s32 DecEq_0065D0A0(u8 *q, s32 v) {
    return Dec_0065D0A0(q) == v;
}

static inline s32 Busy_0065D0A0(Self_0065D0A0 *s) {
    return DecEq_0065D0A0(&s->b19E4, 1) || DecEq_0065D0A0(&s->b19E4, 0x1D) ||
           s->b24FE != 0 || s->b2500 != 0;
}

static inline u16 Dec2_0065D0A0(u8 *q) {
    Buf_0065D0A0 buf;
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

s32 func_L39_0065D0A0(Self_0065D0A0 *s) {
    s32 flags;
    s32 out;
    s32 base;
    s32 mode;
    s32 x;
    Rec_0065D0A0 *rec;
    Obj450_0065D0A0 *obj;
    u8 f;
    u8 c16;
    u16 bits;

    if (s->b1A0C != 0) {
        if (s->s478 != 10 || s->h2D8 != 1) {
            return 0;
        }
    }
    if (s->p450 == 0) {
        return 0;
    }
    if (s->b46A != 0) {
        return 0;
    }
    if (s->s474 != 2) {
        return 0;
    }
    mode = s->s478;
    flags = s->s460;
    if (D_001A5810.bA4[s->s2544] != 0) {
        if (flags & 0x20) {
            flags |= 8;
        }
    }
    base = s->s2F0;
    switch (mode) {
    case 10:
        if (s->b378 != 0) {
            break;
        }
        if (DecEq_0065D0A0(&s->b19E6, 0) || DecEq_0065D0A0(&s->b19E6, 1) ||
            (DecEq_0065D0A0(&s->b19E6, 4) && s->b14AC != 0)) {
            if (func_L01_004606E8(flags, 8, &out, s->p2534) == 0) {
                break;
            }
            if (s->h320 != 0) {
                break;
            }
            obj = s->p450;
            if (obj == 0) {
                break;
            }
            if (func_L39_0063BDE0(s, obj) == 0) {
                break;
            }
            if (obj->b20 != 0) {
                break;
            }
            if (s->b24FE != 0) {
                break;
            }
            if ((s->p2534->w1A0 & func_L39_005C42E8(8, s->s2544)) != 0 ||
                ((f = Busy_0065D0A0(s)) != 0 &&
                 (s->s2F0 >= 0x12 || D_001A5810.bA4[s->s2544] == 1))) {
                c16 = 0;
                f = Busy_0065D0A0(s);
                if (f != 0) {
                    if (s->s2F0 >= 0x12 || s->s1310 == 1) {
                        c16 = 1;
                    }
                }
                if (c16 == 0 || s->b1A14 == 0) {
                    if (s->s251C != 0) {
                        func_L39_0063D240(s, 0);
                    } else {
                        s->vt->fn34(s, 0x15, 1, 0, 1);
                    }
                } else {
                    func_L39_0062B4A8(s, 0x1A, 0, 0, 2.0f);
                }
                s->b24FE = c16;
            } else {
                s->vt->fn34(s, 0x13, 1, 0, 1);
            }
            break;
        }
        if ((DecEq_0065D0A0(&s->b19E4, 7) || DecEq_0065D0A0(&s->b19E4, 9) ||
             DecEq_0065D0A0(&s->b19E4, 8) || DecEq_0065D0A0(&s->b19E4, 6) ||
             (DecEq_0065D0A0(&s->b19E4, 0xE) && 32.0f < s->f628) ||
             (DecEq_0065D0A0(&s->b19E4, 0xB) && s->s14E4 != 3 && 18.0f < s->f628) ||
             (DecEq_0065D0A0(&s->b19E4, 0xB) && s->s14E4 == 3 && 20.0f < s->f628) ||
             DecEq_0065D0A0(&s->b19E4, 0x2C) || DecEq_0065D0A0(&s->b19E4, 0x11)) &&
            s->s2F0 >= 9) {
            s32 lim = 12;
            if (DecEq_0065D0A0(&s->b19E4, 0xB) || DecEq_0065D0A0(&s->b19E4, 0xE)) {
                lim = 15;
            }
            if (func_L01_004606E8(flags, lim, 0, s->p2534) == 0) {
                break;
            }
            if ((s->b14AE == 0 ? 0.1f < s->f2AC : 0.57f < s->f2AC) ||
                (DecEq_0065D0A0(&s->b19E4, 8) && 0.57f < s->f2AC)) {
                s->vt->fn34(s, 0x14, 1, 0, 1);
            } else {
                s->vt->fn34(s, 0x13, 1, 0, 1);
            }
            break;
        }
        if (!DecEq_0065D0A0(&s->b19E6, 6)) {
            break;
        }
        rec = &D_L39_0047A8A8[s->h107C];
        if (DecEq_0065D0A0(&s->b19E4, 0x15) && s->s2F0 >= 0x1A && s->b46A == 0 &&
            s->s61C == 0 && (f32)rec->i10 <= s->f628 &&
            (s->p2534->w1A0 & func_L39_005C42E8(8, s->s2544)) &&
            func_L01_004606E8(flags, 0xC, 0, s->p2534) != 0) {
            if (s->s251C != 0) {
                func_L39_0063D240(s, 0);
            } else {
                s->vt->fn34(s, 0x15, 1, 0, 1);
            }
            break;
        }
        if (s->s61C != 0) {
            break;
        }
        if (s->b46A != 0) {
            break;
        }
        if (!((f32)rec->i10 <= s->f628)) {
            break;
        }
        {
            s32 lvl = ((s32)s->f628 - rec->i0C) * 2;
            s32 n2 = lvl > 0 ? lvl : 1;
            if (n2 >= 13) {
                n2 = 12;
            }
            if (func_L01_004606E8(flags, n2, 0, s->p2534) == 0) {
                break;
            }
        }
        if ((s->p2534->w1A0 & func_L39_005C42E8(8, s->s2544)) != 0) {
            if (s->s251C != 0) {
                func_L39_0063D240(s, 0);
            } else {
                s->vt->fn34(s, 0x15, 1, 0, 1);
            }
        } else {
            s->vt->fn34(s, 0x13, 1, 0, 1);
        }
        break;
    case 11: {
        s32 id = 4;
        if (s->h2DE != 0) {
            id = 7;
        }
        if (DecEq_0065D0A0(&s->b19E6, 0) || DecEq_0065D0A0(&s->b19E6, 1) ||
            DecEq_0065D0A0(&s->b19E6, 0xC) || DecEq_0065D0A0(&s->b19E6, 4) ||
            DecEq_0065D0A0(&s->b19E6, 2) || DecEq_0065D0A0(&s->b19E6, 0x1E) ||
            DecEq_0065D0A0(&s->b19E6, 5) || DecEq_0065D0A0(&s->b19E4, 0x1D) ||
            DecEq_0065D0A0(&s->b19E4, 0x7D) || s->b24FE != 0) {
            if (func_L01_004606E8(flags, id, 0, s->p2534) == 0) {
                if ((s->p2534->w1A0 & flags) == 0) {
                    break;
                }
                if (s->s470 < 0xD) {
                    break;
                }
            }
            if (s->b15EE == 0) {
                break;
            }
            if (s->h332 != 0) {
                break;
            }
            if (DecEq_0065D0A0(&s->b19E4, 0x2B)) {
                break;
            }
            s->vt->fn34(s, 0x2B, 1, 0, 1);
        }
        break;
    }
    case 6:
    case 12:
        if ((DecEq_0065D0A0(&s->b19E4, 0x22) || s->b1A07 != 0) && s->b24FF == 0 &&
            s->f18F0 != 0.0f) {
            if (func_003D3CB0(&s->f18F0, s->unk730, 0x22, 0, 0) != 0) {
                if (func_003D3CB0(s->unkE0, s->unk730, 2, 0, 0) != 0) {
                    if (DecEq_0065D0A0(&s->b19E4, 0x22)) {
                        s->vt->fn34(s, 0, 1, 0, 1);
                    } else {
                        if (s->s748 != 0) {
                            s->s754 = 1;
                        } else if (DecEq_0065D0A0(&s->b19E4, 0) &&
                                   s->p2524->b43 == s->s2448) {
                            func_L39_0062B4A8(s, func_L39_006223B0(s, 0), 0, 0, -2.0f);
                        }
                        s->b1A07 = 0;
                        s->b1A05 = 0;
                    }
                    s->b1A0D = 0;
                    s->b24FF = 1;
                }
            }
        } else {
            s->b24FF = 0;
        }
        if (DecEq_0065D0A0(&s->b19E4, 0x1D)) {
            break;
        }
        if (s->b24FE != 0) {
            break;
        }
        if (s->b1A07 != 0) {
            break;
        }
        if (DecEq_0065D0A0(&s->b19E4, 0x22)) {
            break;
        }
        x = func_L39_00673160(&s->b1A40, 0, 1, 0);
        if (x == 8) {
            if (DecEq_0065D0A0(&s->b19E6, 0xC) || DecEq_0065D0A0(&s->b19E6, 0) ||
                DecEq_0065D0A0(&s->b19E4, 3) ||
                (DecEq_0065D0A0(&s->b19E6, 1) && s->f2468 < 0.7f)) {
                s->vt->fn34(s, 0x22, 1, 0, 1);
            } else {
                func_L39_00621D60(s, -1);
                s->b1A0D = 1;
            }
        } else if (x == 4) {
            func_L39_005F33E0(1, 0, s->p450);
        }
        break;
    }
    if (s->s2F0 == base) {
        bits = Dec2_0065D0A0(&s->b1A40);
        if ((s16)bits < 0 && s->s18D4 == 0xF) {
            f = Busy_0065D0A0(s);
            if (f == 0 && (s->q338 & 0xFFFFFFFF0000UL) == 0) {
                func_0038CB00(&s->h24A0);
                if (s->h24A0 != 0 && s->h320 == 0 && s->b378 == 0 &&
                    (DecEq_0065D0A0(&s->b19E6, 0) || DecEq_0065D0A0(&s->b19E6, 1) ||
                     DecEq_0065D0A0(&s->b19E6, 0xC) ||
                     ((DecEq_0065D0A0(&s->b19E6, 2) || DecEq_0065D0A0(&s->b19E6, 4)) &&
                      s->s2D0 != 0))) {
                    if (s->p2534->w1A4 & func_L39_005C42E8(8, s->s2544)) {
                        s->vt->fn34(s, 0x7D, 1, 0, 1);
                    }
                }
                if (s->p2534->w1A4 & func_L39_005C42E8(8, s->s2544)) {
                    s->h24A0 = 0x19;
                }
            }
        }
    }
    return s->s2F0 < base;
}
/* localdecomp:end func_L39_0065D0A0 */

/* localdecomp:start func_L39_0065F1A8 */
typedef union Buf_0065F1A8 {
    u8 b[8];
    u32 w[2];
} Buf_0065F1A8;

typedef struct VT_0065F1A8 {
    u8 pad0[0x34];
    void (*fn34)(void *, s32, s32, s32, s32);
} VT_0065F1A8;

typedef struct S_0065F1A8 {
    u8 pad0[0x14];
    VT_0065F1A8 *vt;
    u8 pad18[0x30C - 0x18];
    s32 s30C;
    u8 pad310[0x754 - 0x310];
    s32 s754;
    u8 pad758[0x19E4 - 0x758];
    u8 b19E4;
    u8 pad19E5[0x1A07 - 0x19E5];
    u8 b1A07;
    u8 pad1A08[0x1A17 - 0x1A08];
    u8 b1A17;
    u8 pad1A18[0x2468 - 0x1A18];
    f32 f2468;
} S_0065F1A8;

extern u8 D_L39_004997E0[];
extern void func_L39_00622288(void *);

s32 func_L39_0065F1A8(S_0065F1A8 *s) {
    Buf_0065F1A8 buf;

    if (({
            u32 r;
            u8 *q = &s->b19E4;
            if (*q == 0) {
                r = 0;
            } else {
                u32 a, b;
                s32 n = *q;
                s32 k = ((u32)q - n) & 7;
                s32 m = n + 1;
                s32 i;
                u8 *d = buf.b;
                for (i = 0; i < 40; i += 5) {
                    *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
                }
                a = buf.w[0] ^ (u32)q;
                b = buf.w[1] ^ a;
                buf.w[0] = a;
                buf.w[1] = b;
                r = b;
            }
            r == 2;
        }) ||
        ({
            u32 r;
            u8 *q = &s->b19E4;
            if (*q == 0) {
                r = 0;
            } else {
                u32 a, b;
                s32 n = *q;
                s32 k = ((u32)q - n) & 7;
                s32 m = n + 1;
                s32 i;
                u8 *d = buf.b;
                for (i = 0; i < 40; i += 5) {
                    *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
                }
                a = buf.w[0] ^ (u32)q;
                b = buf.w[1] ^ a;
                buf.w[0] = a;
                buf.w[1] = b;
                r = b;
            }
            r == 3;
        }) ||
        ({
            u32 r;
            u8 *q = &s->b19E4;
            if (*q == 0) {
                r = 0;
            } else {
                u32 a, b;
                s32 n = *q;
                s32 k = ((u32)q - n) & 7;
                s32 m = n + 1;
                s32 i;
                u8 *d = buf.b;
                for (i = 0; i < 40; i += 5) {
                    *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
                }
                a = buf.w[0] ^ (u32)q;
                b = buf.w[1] ^ a;
                buf.w[0] = a;
                buf.w[1] = b;
                r = b;
            }
            r == 0;
        })) {
        if (s->b1A07 != 0 && s->s30C < 5 && s->f2468 < 0.7f) {
            if (({
                    u8 r;
                    u8 *q = &s->b1A17;
                    if (*q == 0) {
                        r = 0;
                    } else {
                                u32 a, b;
                        s32 n = *q;
                        s32 k = ((u32)q - n) & 7;
                        s32 m = n + 1;
                        s32 i;
                        u8 *d = buf.b;
                        for (i = 0; i < 24; i += 3) {
                            *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
                        }
                        a = buf.w[0] ^ (u32)q;
                        b = buf.w[1] ^ a;
                        buf.w[0] = a;
                        buf.w[1] = (b >> 16) / (((b ^ (b >> 16)) << 16) + 1);
                        r = buf.b[4];
                    }
                    r;
                }) == 0) {
                func_L39_00622288(s);
                s->s754 = 2;
                s->vt->fn34(s, 0x22, 1, 0, 1);
                return 1;
            }
        }
    }
    return 0;
}
/* localdecomp:end func_L39_0065F1A8 */

/* localdecomp:start func_L39_0065F468 */
extern void func_0038CB78(void *, s32, s32);
extern void *func_L39_00662510(u8 *p);
extern u8 D_L39_0047B2E0[];

void func_L39_0065F468(u8 *p) {
    func_0038CB78(p, 0, 0x4500);
    func_L39_00662510(p);
    *(u8 **)(p + 0x14) = D_L39_0047B2E0;
    *(u8 *)(p + 0x1A14) = 1;
    *(u8 *)(p + 0x44EF) = 5;
}
/* localdecomp:end func_L39_0065F468 */

/* localdecomp:start func_L39_0065F4B8 */
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

__asm__(".extern D_L39_00241120, 16");
extern s32 *D_L39_00241120;
extern s32 D_L39_0024112C;
__asm__(".extern D_L39_002461DC, 4");
extern s32 D_L39_002461DC;
__asm__(".extern D_L39_002405CC, 16");
extern s32 D_L39_002405CC;
extern s32 D_L39_00352944 __attribute__((section(".data")));
extern E_0065F4B8 D_L39_004840A0[];
extern S_0065F4B8 D_L39_002FB000[];
extern Core_0065F4B8 D_001A5CD0_0065F4B8;

extern f32 func_L01_0040E548(void *, void *);
extern void func_L39_006613D0();
extern void func_L39_00661488(void *);
extern void func_L39_00622450(void *);
extern void func_L01_00451F60(s32, s32, s32);
extern void func_L39_00622990(void *);
extern void func_L39_00622C28(void *);
extern void func_L39_006233A8(void *, void *, void *, void *);
extern void func_L39_006617C8(u8 *);
extern void func_L39_00629FE0(void *, s32);
extern void func_L39_00656F28(void *);
extern void func_L39_0063EE68_0065F4B8(void *);
extern void func_L39_0063A230(void *);
extern void func_L39_006390D0(void *);
extern s32 func_L39_00639D90(void *);
extern void func_L39_006217C0(void *);
extern void func_L39_0063C468(void *);
extern void func_L39_0063C840(void *);
extern void func_L39_0063EE70_0065F4B8(void *);
extern void func_L39_0063EC20(void *);
extern void func_L35_003A53C0(void *);
extern void func_L39_0063AE10(void *);
extern void func_L39_0062B838(void *, s32);
extern void func_L39_0063EE78(void *);
extern void func_L39_0063FC90(void *);
extern void func_L39_00621388(void *);
extern void func_L39_00621600(void *);
extern void func_L39_00631E90(void *);
extern void func_L39_0063A540(void *);
extern void func_L39_00644D08(void *);
extern void func_L01_004436F4(void *);
extern void func_L39_0063F0C0_0065F4B8(void *);
extern void func_L39_0063F0C8(void *);
extern void func_L39_0063B0A8(void *);
extern s32 func_L39_0066EE90(void *, void *);
extern void func_0038CC88(void *, void *, s32);
extern void func_L39_005BA3A0(f32 *v, s32 *out);
extern void func_0014AD08(s32, s32, s32, s32, s32, void *);
extern void func_L39_00677348(s32, s32);
extern void func_L39_006772F8(s32, s32);
extern void func_L39_00661988(u8 *);
extern void func_L39_00674190(void *);


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
        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
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
        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
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

        *d++ = D_L39_00483A00[x];
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

void func_L39_0065F4B8(S_0065F4B8 *s) {
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
    if (100.0f < func_L01_0040E548(&v, &s->pos)) {
        s->pos = v;
    }
    func_L39_006613D0(s);
    func_L39_00661488(s);
    s->h19E2 = 0;
    s->h19E0 = 0;
    func_L39_00622450(s);
    if (D_001A5CD0_0065F4B8.w170 == 0 && D_001A5CD0_0065F4B8.w12C >= 2 &&
        D_001A5CD0_0065F4B8.w7D0 < D_001A5CD0_0065F4B8.w128 - 3000 && D_L39_00352944 > 0 &&
        D_L39_00352944 + 25000 < D_001A5CD0_0065F4B8.w128) {
        s->p2534->w1CC = 1;
        s->h320 = 2;
        D_L39_004840A0[s->s2544].w0 = 5;
        D_L39_004840A0[s->s2544].w8 = 2;
        func_L01_00451F60(0x18D2, 2, 0);
    }
    s->vt->fn28(s);
    func_L39_00622990(s);
    func_L39_00622C28(s);
    func_L39_006233A8(s, &s->pos, &s->vB0, s->x1540);
    func_L39_006617C8((u8 *)s);
    thr = 2.5f;
    if (s->h370 == -1) {
        thr = 10.0f;
    }
    c = s->f2A8 == 0.0f || thr < s->f2AC;
    if (!DecEq_0065F4B8(&s->b19E6, 0x14) && !DecEq_0065F4B8(&s->b19E4, 0x83) && (s->s478 == 11 || c)) {
        func_L39_00629FE0(s, c);
        if (s->s478 != 11 && c && (s->b1A0E == 0 || s->s251C != 0) && s->b1A0B == 0 &&
            s->b15EE != 0) {
            s->b1A13 = 1;
        }
    }
    func_L39_00656F28(s);
    func_L39_0063EE68_0065F4B8(s);
    func_L39_0063A230(s);
    func_L39_006390D0(s);
    if (s->b1A08 != 0 || func_L39_00639D90(s) != 0 || DecEq_0065F4B8(&s->b19E4, 1) ||
        DecEq_0065F4B8(&s->b19E4, 0x1D) || s->s2544 == (D_L39_0024112C & 7)) {
        func_L39_006217C0(s);
    }
    func_L39_0063C468(s);
    func_L39_0063C840(s);
    func_L39_0063EE70_0065F4B8(s);
    func_L39_0063EC20(s);
    func_L35_003A53C0(s);
    func_L39_0063AE10(s);
    func_L39_0062B838(s, 0);
    func_L39_0063EE78(s);
    func_L39_0063FC90(s);
    x = func_L39_00639D90(s);
    if (s->b1A0A != 0 || (x == 2 && !DecEq_0065F4B8(&s->b19E6, 0x14)) ||
        (x == 1 && (f = Busy_0065F4B8(s)) != 0) ||
        Dec16_0065F4B8(&s->b314) != 0) {
        func_L39_00621388(s);
    } else {
        func_L39_00621600(s);
    }
    func_L39_00631E90(s);
    func_L39_0063A540(s);
    func_L39_00644D08(s);
    func_L01_004436F4(s->p2524);
    func_L39_0063F0C0_0065F4B8(s);
    func_L39_0063F0C8(s);
    if (func_L39_00639D90(s) != 0 && s->s2450 != 4 && s->s2450 != 0x51) {
        s->s2450 = 0x20;
    } else if (s->s2450 == 0x20) {
        s->s2450 = 0;
    }
    func_L39_0063B0A8(s);
    if (s->s2544 == 0 && s->b44EC < 5) {
        if ((s->p2534->w1A0 & func_L39_005C42E8(0x40, 0)) == 0 || s->b44EC != 0) {
            s->b44EC++;
        }
    } else {
        Pkt_0065F4B8 pkt;

        if (D_L39_002461DC++ > 600) {
            D_L39_002461DC = 0;
        }
        n = func_L39_0066EE90(s->x430C, pkt.data);
        if (n != 0) {
            pkt.hdr.f57 = s->b24C9;
            pkt.hdr.f58 = 0;
            if (DecEq_0065F4B8(&s->b19E4, 0x31) &&
                !(host = s->p2530 != 0 ? (s->p2530->b27B != 0 && DecEq_0065F4B8(&s->b19E4, 0x31)) : 0)) {
                pkt.hdr.f58 = 1;
                func_0038CC88(&pkt, s->x431C, 8);
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
                func_L39_005BA3A0(&s->vB0.x, &packed);
                func_0038CC88(&pkt.data[n], &packed, 4);
                n += 4;
                pkt.data[n++] = Dec_0065F4B8(&s->b19E4);
                func_0038CC88(&pkt.data[n], &s->pos, 12);
                n += 12;
                pkt.hdr.f56 = 1;
            } else {
                pkt.hdr.f56 = 0;
            }
            pkt.hdr.seq = s->b44ED++;
            pkt.hdr.f60 = (u8)s->w4324;
            s->b44EE = 0;
            if (D_001A5CD0_0065F4B8.w170 == 0) {
                func_0014AD08(D_001A5CD0_0065F4B8.b7D4 | 0x80, D_001A5CD0_0065F4B8.w4, -1, D_L39_002405CC,
                              n + 0x18, &pkt);
            }
        } else {
            s->b44EE++;
        }
    }
    if (s->p2558->s16C >= 0 && D_001A5CD0_0065F4B8.w128 >= s->p2558->s16C) {
        s->p2558->v190 = s->p2558->v180;
        s->p2558->w160 = s->p2558->w164;
        s->p2558->v180 = s->p2558->v170;
        s->p2558->w164 = s->p2558->s16C - 0xF5;
        s->p2558->s16C = -1;
    }
    for (i = 0; i < *D_L39_00241120; i++) {
        if (&D_L39_002FB000[i] == s) {
            break;
        }
    }
    if (DecEq_0065F4B8(&s->b19E6, 0x14)) {
        func_L39_00677348(i, 1);
        func_L39_006772F8(i, 1);
    } else {
        func_L39_00677348(i, 0);
        func_L39_006772F8(i, 0);
    }
    if (s->p2558 != 0) {
        func_L39_00661988((u8 *)s);
        s->p2558->p4->w48 = s->s478;
        func_L39_00674190(s);
        s->p2558->p4->h84 = 0;
        for (j = 0; j < 16; j++) {
            if (Dec2_0065F4B8(&s->a1A52[j]) != 0 || j == 11 || j == 14 || j == 15) {
                s->p2558->p4->h84 |= 1 << j;
            }
        }
        s->p2558->p4->h80 = Dec2_0065F4B8(&s->b1A40);
        s->p2558->p4->h82 = Dec2_0065F4B8(&s->b1A41);
    }
    if (s->b1A0A == 0 && D_001A5810.bA4[s->s2544] == 2 && !DecEq_0065F4B8(&s->b19E4, 0x90)) {
        s->p424->w98 = s->p424->p24->w10;
    }
    if (++s->s2550 > 100) {
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
/* localdecomp:end func_L39_0065F4B8 */

/* localdecomp:start func_L39_006606E0 */
typedef struct Ent_006606E0 {
    /* 0x00 */ u8 b0;
    /* 0x01 */ u8 pad1[7];
    /* 0x08 */ s32 f8;
    /* 0x0C */ u8 padC[0x11 - 0xC];
    /* 0x11 */ u8 b11;
    /* 0x12 */ u8 pad12[0x18 - 0x12];
    /* 0x18 */ s32 f18;
    /* 0x1C */ s32 f1C;
    /* 0x20 */ s32 f20;
    /* 0x24 */ u8 pad24[0x50 - 0x24];
} Ent_006606E0;

typedef struct Tab_006606E0 {
    /* 0x00 */ u8 pad0[0xB];
    /* 0x0B */ s8 b0B;
    /* 0x0C */ u8 pad0C[0x21 - 0xC];
    /* 0x21 */ s8 b21;
    /* 0x22 */ u8 pad22[0x28 - 0x22];
    /* 0x28 */ f32 f28;
    /* 0x2C */ u8 pad2C[0x80 - 0x2C];
} Tab_006606E0;

typedef struct Self_006606E0 {
    /* 0x000 */ u8 pad0[0x2F0];
    /* 0x2F0 */ s32 s2F0;
    /* 0x2F4 */ u8 pad2F4[0x320 - 0x2F4];
    /* 0x320 */ s16 h320;
    /* 0x322 */ u8 pad322[0x328 - 0x322];
    /* 0x328 */ f32 f328;
    /* 0x32C */ u8 pad32C[0x458 - 0x32C];
    /* 0x458 */ Ent_006606E0 ent[1];
    /* 0x4A8 */ u8 pad4A8[0x628 - 0x4A8];
    /* 0x628 */ f32 f628;
    /* 0x62C */ u8 pad62C[0x14E4 - 0x62C];
    /* 0x14E4 */ s32 s14E4;
    /* 0x14E8 */ u8 pad14E8[0x153C - 0x14E8];
    /* 0x153C */ u8 b153C;
    /* 0x153D */ u8 pad153D[0x19E4 - 0x153D];
    /* 0x19E4 */ u8 b19E4;
    /* 0x19E5 */ u8 pad19E5;
    /* 0x19E6 */ u8 b19E6;
    /* 0x19E7 */ u8 pad19E7[0x1A07 - 0x19E7];
    /* 0x1A07 */ u8 b1A07;
    /* 0x1A08 */ unsigned long q1A08;
    /* 0x1A10 */ u8 pad1A10[0x1A40 - 0x1A10];
    /* 0x1A40 */ u8 b1A40;
    /* 0x1A41 */ u8 pad1A41;
    /* 0x1A42 */ u8 b1A42[1];
    /* 0x1A43 */ u8 pad1A43[0x2488 - 0x1A43];
    /* 0x2488 */ s16 h2488;
    /* 0x248A */ u8 pad248A[0x2534 - 0x248A];
    /* 0x2534 */ void *p2534;
} Self_006606E0;

typedef union Buf_006606E0 {
    u8 b[8];
    u32 w[2];
    u16 h[4];
} Buf_006606E0;

extern u8 D_L39_004997E0[];

static inline u32 Dec_006606E0(u8 *q) {
    Buf_006606E0 buf;
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

static inline s32 DecEq_006606E0(u8 *q, s32 v) {
    return Dec_006606E0(q) == v;
}

__asm__(".extern D_L39_0024112C, 16");
extern s32 D_L39_0024112C;
extern u32 D_L39_0024B9C8;
extern u8 D_L39_0049AAC0[];
extern u8 D_L39_0049AAC1[];
extern Tab_006606E0 D_L39_0049C890[];

extern s32 func_L39_005C2F50(void *);
extern s32 func_L39_00620CF8(void *, s32);
extern s32 func_L39_00620E28(void *, s32, s32);
extern s32 func_L39_00648AE0(u8 *, s32);
extern void func_L39_00672DD8(void *, s32, s32, s32, s32, s32);

static inline Self_006606E0 *Slot_006606E0(Self_006606E0 *s, s32 i) {
    return (Self_006606E0 *)((u8 *)s + i * 0x50);
}

static inline Tab_006606E0 *TabGet_006606E0(Self_006606E0 *s, s32 mode) {
    Tab_006606E0 *e;
    if (func_L39_00648AE0((u8 *)s, mode)) {
        e = &D_L39_0049C890[((Tab_006606E0 *)((u8 *)D_L39_0049C890 + (mode << 7)))->b21];
    } else {
        e = (Tab_006606E0 *)((u8 *)D_L39_0049C890 + (mode << 7));
    }
    return e;
}

static inline void Prep_006606E0(u8 *q) {
    s32 t;
    if (*q == 0) {
        *q = ++D_L39_0049AAC0[0];
    } else {
        t = *q;
        *q = D_L39_0049AAC1[0];
        D_L39_0049AAC1[0] = t;
    }
}

static inline void SetW_006606E0(u8 *q, s32 v) {
    u8 *hk = q;
    Buf_006606E0 buf;
    u32 key;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    Prep_006606E0(q);
    key = ((u32 *)D_L39_0049AAC0)[((u32)hk * D_L39_0024B9C8) % 0x182];
    k = ((u32)q - *q) & 7;
    buf.w[0] = (u32)q ^ key;
    buf.w[1] = v ^ key;
    m = *q + 1;
    d = buf.b;
    for (i = 0; i < 40; i += 5) {
        D_L39_0049AAC0[m + ((k + i) & 7) * 0xC1] = *d++;
    }
}

void func_L39_006606E0(Self_006606E0 *s, s32 i) {
    s32 mode = Slot_006606E0(s, i)->ent[0].f20;
    s32 ok;
    s32 f;
    Tab_006606E0 *t;
    Self_006606E0 *e;

    if (i == 0) {
        if (mode != 10 && s->h320 == 0 && s->ent[0].f18 >= 4) {
            ok = 0;
            f = 0;
            if ((s->q1A08 & 0xFFFFFF00000000UL) != 0 ||
                DecEq_006606E0(&s->b19E6, 0x14) || DecEq_006606E0(&s->b19E4, 0x66) ||
                DecEq_006606E0(&s->b19E4, 0x64) || s->h2488 != 0) {
                f = 1;
            }
            if (f == 0 && (func_L39_005C2F50(s->p2534) & (e = Slot_006606E0(s, i))->ent[0].f8) != 0) {
                ok = 1;
                if (func_L39_00620CF8(s, mode)) {
                    if (e->ent[0].b0 == 0) {
                        e->ent[0].b0 = 1;
                        func_L39_00672DD8(&s->b1A40, 1, -1, -1, 0, 0);
                    }
                } else if (e->ent[0].b0 == 1) {
                    e->ent[0].b0 = 0;
                    func_L39_00672DD8(&s->b1A40, 2, -1, -1, 0, 0);
                }
            } else if (Slot_006606E0(s, i)->ent[0].b0 == 1) {
                Slot_006606E0(s, i)->ent[0].b0 = 0;
                func_L39_00672DD8(&s->b1A40, 2, -1, -1, 0, 0);
            }
            if (f != 0) {
                return;
            }
            if (DecEq_006606E0(&s->b19E4, 0x1D) && s->s2F0 < 0x11) {
                return;
            }
            if (Slot_006606E0(s, i)->ent[0].f18 < 0x13) {
                return;
            }
            if (s->f328 != 0.0f) {
                return;
            }
            if (DecEq_006606E0(&s->b19E4, 0xE) && 25.0f < s->f628 && s->f628 < 35.0f) {
                return;
            }
            if (DecEq_006606E0(&s->b19E4, 0xB) && s->s14E4 == 3 && 10.0f < s->f628 &&
                s->f628 < 20.0f) {
                return;
            }
            if (ok == 0) {
                return;
            }
            t = TabGet_006606E0(s, mode);
            if (t->b0B != 0 ||
                ((DecEq_006606E0(&s->b19E6, 0) || DecEq_006606E0(&s->b19E6, 1) ||
                  DecEq_006606E0(&s->b19E6, 0xC) || DecEq_006606E0(&s->b19E6, 5) ||
                  DecEq_006606E0(&s->b19E6, 0xF) ||
                  (DecEq_006606E0(&s->b19E6, 4) && s->b153C != 0)) &&
                 s->b1A07 == 0) ||
                (DecEq_006606E0(&s->b19E4, 0x22) && 20.0f < s->f628)) {
                t = TabGet_006606E0(s, mode);
                if ((t->b0B == 0 && func_L39_00620CF8(s, -1)) || func_L39_00620E28(s, -1, 1)) {
                    func_L39_00672DD8(&s->b1A40, 8, -1, -1, 0, 0);
                    t = TabGet_006606E0(s, mode);
                    if (t->b0B == 0) {
                        s->ent[0].b11 = 0x11;
                    }
                } else {
                    func_L39_00672DD8(&s->b1A40, 4, -1, -1, 0, 0);
                }
                t = TabGet_006606E0(s, mode);
                s->f328 = 1.0f / t->f28;
                SetW_006606E0(&s->b1A42[mode], D_L39_0024112C);
            }
        }
    }
}
/* localdecomp:end func_L39_006606E0 */

/* localdecomp:start func_L39_00661268 */
s32 func_L39_00661268(u8 *p) {
    u8 *q = *(u8 **)(p + 9512);
    if (q != 0) {
        return *(s32 *)(q + 720);
    }
    return 0;
}
/* localdecomp:end func_L39_00661268 */

/* localdecomp:start func_L39_00661288 */
typedef struct {
    u8 pad0[0x108];
    f32 x;
    f32 y;
    u8 pad110[0x1A0 - 0x110];
    s32 mask;
    u8 pad1A4[0x1B0 - 0x1A4];
    s32 buttons;
    u8 pad1B4[0x1D4 - 0x1B4];
    s32 flag;
} S_65E9B0_Pad;

typedef struct {
    u8 pad0[0x110];
    f32 x;
    f32 y;
    u8 pad118[0x300 - 0x118];
    s32 c300;
    s32 c304;
    u8 pad308[0x338 - 0x308];
    s16 h338;
    u8 pad33A[0x2468 - 0x33A];
    f32 f2468;
    f32 f246C;
    u8 pad2470[0x248C - 0x2470];
    f32 f248C;
    u8 pad2490[0x2534 - 0x2490];
    S_65E9B0_Pad *pad;
    u8 pad2538[0x2544 - 0x2538];
    s32 port;
} S_65E9B0;

extern void func_L39_0063BF40(S_65E9B0 *);
extern s32 func_L39_005C42E8(s32, s32);
extern f32 func_L39_00647588(S_65E9B0 *, f32 *);
extern f32 func_0038CED8(f32 *);
extern f32 func_0038D160(f32, f32);

void func_L39_00661288(S_65E9B0 *p) {
    S_65E9B0_Pad *q;
    s32 b;
    s32 t;
    s32 v;

    func_L39_0063BF40(p);
    if ((p->pad->mask & func_L39_005C42E8(4, p->port)) == 0) {
        p->h338 = 0;
    }
    if (p->pad->flag != 0) {
        p->c300 = 0;
        p->c304++;
    } else {
        p->c304 = 0;
        p->c300++;
    }
    p->x = p->pad->x;
    p->y = -p->pad->y;
    p->f248C = func_L39_00647588(p, &p->x);
    if (func_0038CED8(&p->x) < 0.25f) {
        q = p->pad;
        t = ((q->buttons >> 13) & 1) - ((q->buttons >> 15) & 1);
        p->x = (f32)t;
        b = q->buttons;
        t = (b >> 14) & 1;
        if (b & 0x1000) {
            v = 1 - t;
        } else {
            v = -t;
        }
        p->y = (f32)v;
    }
    p->f2468 = func_L39_00647588(p, &p->x);
    p->f246C = func_0038D160(p->x, p->y);
}
/* localdecomp:end func_L39_00661288 */

/* localdecomp:start func_L39_006613D0 */
typedef struct {
    u8 pad0[9048];
    s32 hist0[8];
    s32 hist1[8];
    s32 index;
    s32 count;
    u8 pad1[9520 - 9120];
    u8 *target;
} Self_65EAF8;

extern void func_003C48A8(void *a, f32 *out);
extern void func_L39_005BA3A0(f32 *v, s32 *out);
extern void func_L39_005BA488(u8 *target, s32 *out);

void func_L39_006613D0(Self_65EAF8 *self) {
    f32 v[4];
    if (*(s16 *)(*(u8 **)(self->target + 80) + 134) == 33) {
        return;
    }
    func_003C48A8(self->target + 896, v);
    func_L39_005BA3A0(v, &self->hist1[self->index]);
    func_L39_005BA488(self->target, &self->hist0[self->index]);
    self->index = (self->index + 1) % 8;
    self->count++;
    if (self->count > 8) {
        self->count = 8;
    }
}
/* localdecomp:end func_L39_006613D0 */
