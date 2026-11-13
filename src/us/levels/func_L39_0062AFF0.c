#include "common.h"

/* NTSC-U counterpart of func_L39_0062D7C8 (src/levels/shared/L39_0062D7C8.c) */
/* localdecomp:start func_L39_0062AFF0 */
typedef struct VT_0062D7C8 {
    u8 pad0[0x34];
    void (*fn34)(void *, s32, s32, s32, s32);
} VT_0062D7C8;

typedef struct Aux_0062D7C8 {
    u8 pad0[0x1A0];
    u32 w1A0;
} Aux_0062D7C8;

typedef union Buf_0062D7C8 {
    u8 b[8];
    u32 w[2];
} Buf_0062D7C8;

typedef struct Self_0062D7C8 {
    /* 0x000 */ u8 pad0[0x14];
    /* 0x014 */ VT_0062D7C8 *vt;
    /* 0x018 */ u8 pad18[0x3E4 - 0x18];
    /* 0x3E4 */ s16 h3E4;
    /* 0x3E6 */ u8 pad3E6;
    /* 0x3E7 */ u8 b3E7;
    /* 0x3E8 */ u8 pad3E8[0x1310 - 0x3E8];
    /* 0x1310 */ s32 s1310;
    /* 0x1314 */ u8 pad1314[0x19E4 - 0x1314];
    /* 0x19E4 */ u8 b19E4;
    /* 0x19E5 */ u8 pad19E5[0x2468 - 0x19E5];
    /* 0x2468 */ f32 f2468;
    /* 0x246C */ u8 pad246C[0x2534 - 0x246C];
    /* 0x2534 */ Aux_0062D7C8 *p2534;
    /* 0x2538 */ u8 pad2538[0x2544 - 0x2538];
    /* 0x2544 */ s32 s2544;
} Self_0062D7C8;

typedef struct Glob_0062D7C8 {
    u8 pad0[0xA4];
    u8 bA4[4];
} Glob_0062D7C8;

extern Glob_0062D7C8 D_001A5990;
extern u8 D_L39_004998A0[];

extern s32 func_L01_0045D358(s32, s32, void *, void *);
extern s32 func_L01_0045D3E8(s32, s32, s32, s32, void *);
extern s32 func_L01_004FB720(void *);
extern s32 func_L39_005C2098(s32, s32);
extern s32 func_L39_0061EB48(void *);
extern s32 func_L39_00627608(void *);

s32 func_L39_0062AFF0(Self_0062D7C8 *s, s32 a1, s32 a2) {
    s32 out;
    s32 window;

    if (func_L01_0045D358(func_L39_005C2098(0x40, s->s2544), a1, &out, s->p2534) == 0) {
        return 0;
    }
    window = func_L01_004FB720(s);
    if ((s->p2534->w1A0 & func_L39_005C2098(8, s->s2544)) != 0 && window > 0 &&
        (D_001A5990.bA4[s->s2544] != 2 || s->b3E7 != 3) &&
        func_L01_0045D3E8(func_L39_005C2098(0x40, s->s2544), 0x1F000, a1 + window, window,
                          s->p2534) != 0) {
        s->vt->fn34(s, 0xB, 1, 0, 1);
        return 1;
    }
    if (s->h3E4 != 0 ||
        (s->s1310 == 1 && func_L01_0045D358(0x28, 2, 0, s->p2534) != 0 &&
         func_L39_0061EB48(s) != 10)) {
        u8 *q = &s->b19E4;
        u32 dec;
        s32 eq;
        if (*q == 0) {
            dec = 0;
        } else {
            Buf_0062D7C8 buf;
            u32 a;
            u32 b;
            s32 n;
            s32 k;
            s32 m;
            s32 i;
            u8 *d;

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
            dec = b;
        }
        eq = dec == 0x10;
        if (!eq && 0.9f < s->f2468) {
            s32 r = func_L39_00627608(s);
            if (r != 2 && !(D_001A5990.bA4[s->s2544] == 2 && r == 3)) {
                s->vt->fn34(s, 0xB, 1, 0, 1);
                return 1;
            }
        }
    }
    if (a2 != 0) {
        return 0;
    }
    s->vt->fn34(s, 7, 1, 0, 1);
    return 1;
}
/* localdecomp:end func_L39_0062AFF0 */
