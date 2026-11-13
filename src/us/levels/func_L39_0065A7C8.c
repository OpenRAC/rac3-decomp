#include "common.h"

/* NTSC-U counterpart of func_L39_0065D0A0 (src/levels/shared/L39_0065D0A0.c) */
/* localdecomp:start func_L39_0065A7C8 */
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

extern Glob_0065D0A0 D_001A5990;
extern u8 D_L39_004998A0[];
extern u8 D_L39_00483AC0[];
extern Rec_0065D0A0 D_L39_0047A968[];

extern s32 func_L01_0045D358(s32, s32, void *, void *);
extern s32 func_L39_005C2098(s32, s32);
extern s32 func_L39_00639598(void *, void *);
extern void func_L39_0063A9F8(void *, s32);
extern void func_L39_00628CD0(void *, s32, s32, s32, f32);
extern s32 func_L39_0061FC10(void *, s32);
extern s32 func_L39_00670818(void *, s32, s32, s32);
extern void func_L39_0061F5C0(void *, s32);
extern void func_L39_005F0CE0(s32, s32, void *);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern s32 func_003883C8(void *);

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
        *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
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
        *d++ = D_L39_00483AC0[((k + i) & 7) * 209 + m];
    }
    a = buf.w[0] ^ (u32)q;
    b = buf.w[1] ^ a;
    buf.w[0] = a;
    buf.w[1] = (b >> 16) / (((b ^ (b >> 16)) << 16) + 1);
    return buf.h[2];
}

s32 func_L39_0065A7C8(Self_0065D0A0 *s) {
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
    if (D_001A5990.bA4[s->s2544] != 0) {
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
            if (func_L01_0045D358(flags, 10, &out, s->p2534) == 0) {
                break;
            }
            if (s->h320 != 0) {
                break;
            }
            obj = s->p450;
            if (obj == 0) {
                break;
            }
            if (func_L39_00639598(s, obj) == 0) {
                break;
            }
            if (obj->b20 != 0) {
                break;
            }
            if (s->b24FE != 0) {
                break;
            }
            if ((s->p2534->w1A0 & func_L39_005C2098(8, s->s2544)) != 0 ||
                ((f = Busy_0065D0A0(s)) != 0 &&
                 (s->s2F0 >= 0x15 || D_001A5990.bA4[s->s2544] == 1))) {
                c16 = 0;
                f = Busy_0065D0A0(s);
                if (f != 0) {
                    if (s->s2F0 >= 0x15 || s->s1310 == 1) {
                        c16 = 1;
                    }
                }
                if (c16 == 0 || s->b1A14 == 0) {
                    if (s->s251C != 0) {
                        func_L39_0063A9F8(s, 0);
                    } else {
                        s->vt->fn34(s, 0x15, 1, 0, 1);
                    }
                } else {
                    func_L39_00628CD0(s, 0x1A, 0, 0, 3.0f);
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
            s->s2F0 >= 11) {
            s32 lim = 14;
            if (DecEq_0065D0A0(&s->b19E4, 0xB) || DecEq_0065D0A0(&s->b19E4, 0xE)) {
                lim = 18;
            }
            if (func_L01_0045D358(flags, lim, 0, s->p2534) == 0) {
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
        rec = &D_L39_0047A968[s->h107C];
        if (DecEq_0065D0A0(&s->b19E4, 0x15) && s->s2F0 >= 0x1F && s->b46A == 0 &&
            s->s61C == 0 && (f32)rec->i10 <= s->f628 &&
            (s->p2534->w1A0 & func_L39_005C2098(8, s->s2544)) &&
            func_L01_0045D358(flags, 15, 0, s->p2534) != 0) {
            if (s->s251C != 0) {
                func_L39_0063A9F8(s, 0);
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
            if (n2 >= 16) {
                n2 = 15;
            }
            if (func_L01_0045D358(flags, n2, 0, s->p2534) == 0) {
                break;
            }
        }
        if ((s->p2534->w1A0 & func_L39_005C2098(8, s->s2544)) != 0) {
            if (s->s251C != 0) {
                func_L39_0063A9F8(s, 0);
            } else {
                s->vt->fn34(s, 0x15, 1, 0, 1);
            }
        } else {
            s->vt->fn34(s, 0x13, 1, 0, 1);
        }
        break;
    case 11: {
        s32 id = 5;
        if (s->h2DE != 0) {
            id = 8;
        }
        if (DecEq_0065D0A0(&s->b19E6, 0) || DecEq_0065D0A0(&s->b19E6, 1) ||
            DecEq_0065D0A0(&s->b19E6, 0xC) || DecEq_0065D0A0(&s->b19E6, 4) ||
            DecEq_0065D0A0(&s->b19E6, 2) || DecEq_0065D0A0(&s->b19E6, 0x1E) ||
            DecEq_0065D0A0(&s->b19E6, 5) || DecEq_0065D0A0(&s->b19E4, 0x1D) ||
            DecEq_0065D0A0(&s->b19E4, 0x7D) || s->b24FE != 0) {
            if (func_L01_0045D358(flags, id, 0, s->p2534) == 0) {
                if ((s->p2534->w1A0 & flags) == 0) {
                    break;
                }
                if (s->s470 < 0x10) {
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
            if (func_003CE740(&s->f18F0, s->unk730, 0x22, 0, 0) != 0) {
                if (func_003CE740(s->unkE0, s->unk730, 2, 0, 0) != 0) {
                    if (DecEq_0065D0A0(&s->b19E4, 0x22)) {
                        s->vt->fn34(s, 0, 1, 0, 1);
                    } else {
                        if (s->s748 != 0) {
                            s->s754 = 1;
                        } else if (DecEq_0065D0A0(&s->b19E4, 0) &&
                                   s->p2524->b43 == s->s2448) {
                            func_L39_00628CD0(s, func_L39_0061FC10(s, 0), 0, 0, -2.0f);
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
        x = func_L39_00670818(&s->b1A40, 0, 1, 0);
        if (x == 8) {
            if (DecEq_0065D0A0(&s->b19E6, 0xC) || DecEq_0065D0A0(&s->b19E6, 0) ||
                DecEq_0065D0A0(&s->b19E4, 3) ||
                (DecEq_0065D0A0(&s->b19E6, 1) && s->f2468 < 0.7f)) {
                s->vt->fn34(s, 0x22, 1, 0, 1);
            } else {
                func_L39_0061F5C0(s, -1);
                s->b1A0D = 1;
            }
        } else if (x == 4) {
            func_L39_005F0CE0(1, 0, s->p450);
        }
        break;
    }
    if (s->s2F0 == base) {
        bits = Dec2_0065D0A0(&s->b1A40);
        if ((s16)bits < 0 && s->s18D4 == 0xF) {
            f = Busy_0065D0A0(s);
            if (f == 0 && (s->q338 & 0xFFFFFFFF0000UL) == 0) {
                func_003883C8(&s->h24A0);
                if (s->h24A0 != 0 && s->h320 == 0 && s->b378 == 0 &&
                    (DecEq_0065D0A0(&s->b19E6, 0) || DecEq_0065D0A0(&s->b19E6, 1) ||
                     DecEq_0065D0A0(&s->b19E6, 0xC) ||
                     ((DecEq_0065D0A0(&s->b19E6, 2) || DecEq_0065D0A0(&s->b19E6, 4)) &&
                      s->s2D0 != 0))) {
                    if (s->p2534->w1A4 & func_L39_005C2098(8, s->s2544)) {
                        s->vt->fn34(s, 0x7D, 1, 0, 1);
                    }
                }
                if (s->p2534->w1A4 & func_L39_005C2098(8, s->s2544)) {
                    s->h24A0 = 0x1E;
                }
            }
        }
    }
    return s->s2F0 < base;
}
/* localdecomp:end func_L39_0065A7C8 */
