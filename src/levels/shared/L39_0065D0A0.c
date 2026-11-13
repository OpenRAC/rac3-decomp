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

INCLUDE_ASM("asm/levels", func_L39_0065F4B8);

INCLUDE_ASM("asm/levels", func_L39_006606E0);

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

INCLUDE_ASM("asm/levels", func_L39_00661488);

/* localdecomp:start func_L39_006617C8 */
extern s32 func_L39_00648840(void *, s32);
extern void func_L39_00648A20(void *, s32, s32);
extern f32 func_L01_0040E570(void *, void *);
extern s32 D_L39_0024112C;
typedef struct { u8 pad0[0x18]; f32 f18; u8 pad1C[0x15]; u8 b31; u8 pad32[2]; u16 h34; } E_006617C8;
extern E_006617C8 *D_L39_00264B68[];

void func_L39_006617C8(u8 *p) {
    s32 i;
    E_006617C8 *e;
    if (D_L39_0024112C & 0x3F) return;
    if (D_L39_0024112C == 0) return;
    if (func_L39_00648840(p, 8) != 0) return;
    for (i = 0; i < 32; i++) {
        e = D_L39_00264B68[i];
        if (e == 0) break;
        if (e->b31 == 0) continue;
        if (e->h34 & 1) continue;
        if (3.0f < *(f32 *)(p + 0xA8) - e->f18) continue;
        if (func_L01_0040E570(p + 0xA0, (u8 *)e + 0x10) < 289.0f) {
            func_L39_00648A20(p, 8, 9);
        }
    }
}
/* localdecomp:end func_L39_006617C8 */

/* localdecomp:start func_L39_006618D8 */
extern void func_0014AD08(s32, s32, s32, s32, s32, void *);


extern S_1A5CD0_006618D8 D_001A5CD0;

void func_L39_006618D8(u8 *p, f32 *v, s32 a2, s8 a3, s32 a4) {
    S_006618D8 s;
    u8 b;

    s.b0D = p[0x2544];
    s.b0C = p[0x44ED];
    b = p[0x44EE];
    s.b0E = b;
    if (a2 != 0) {
        s.b0E = b | 0x40;
    }
    if (a4 != 0) {
        s.b0E |= 0x20;
    }
    s.b0D |= (a3 + 1) << 4;
    s.f0 = v[0];
    s.f4 = v[1];
    s.f8 = v[2];
    if (D_001A5CD0.w170 == 0) {
        func_0014AD08(D_001A5CD0.b7D4 | 0x80, D_001A5CD0.w4, -1,
                    *(s32 *)0x2405E4, 0x10, &s);
    }
}
/* localdecomp:end func_L39_006618D8 */

/* localdecomp:start func_L39_00661988 */
extern s32 D_001A58D0[];
extern s32 D_001A5930[];
extern s32 D_001A5990[];
extern S_1A5CD0_006618D8 D_001A5CD0;

void func_L39_00661988(u8 *p) {
    s32 a = *(s32 *)(p + 0x2544);
    s32 *s1 = &D_001A58D0[a];
    s32 *s2 = &D_001A5930[a];
    s32 *s3 = &D_001A5990[a];
    u8 *o = *(u8 **)(*(u8 **)(p + 0x2558) + 4);
    u8 *dp = o + 0x70;
    s32 i;
    s32 x;

    for (i = 0; i < 3; i++) {
        *(s32 *)(dp - 0x18) = s1[0];
        *(s32 *)(dp - 0xC) = s2[0];
        *(s32 *)(dp) = s3[0];
        s1 += 8;
        s2 += 8;
        s3 += 8;
        dp += 4;
    }
    x = D_001A5CD0.w128;
    if (*(s32 *)(o + 0x4C) < x - 0x4B0) {
        *(s32 *)(o + 0x4C) = x;
    }
}
/* localdecomp:end func_L39_00661988 */
