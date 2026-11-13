#include "common.h"

/* NTSC-U counterpart of func_L39_00638C28 (src/levels/shared/L39_00637D38.c): 4 -> 5; 6 -> 7; 7 -> 9 */
/* localdecomp:start func_L39_006363E0 */
/* Log: 00638C28 first draft differed only by xori vs compare: written as (Dec ^ 14) == 0 (same idiom as func_L39_0055AD78). */
typedef union Buf_00638C28 {
    u8 b[8];
    u32 w[2];
} Buf_00638C28;

typedef struct VT_00638C28 {
    u8 pad0[0x34];
    s32 (*f34)(void *, s32, s32, s32, s32);
} VT_00638C28;

typedef struct Aux_00638C28 {
    u8 pad0[0x1A0];
    s32 w1A0;
} Aux_00638C28;

typedef struct Self_00638C28 {
    u8 pad0[0x14];
    VT_00638C28 *vt;
    u8 pad18[0x2F0 - 0x18];
    s32 s2F0;
    u8 pad2F4[0x320 - 0x2F4];
    s16 h320;
    u8 pad322[0x19E4 - 0x322];
    u8 b19E4;
    u8 pad19E5[0x2534 - 0x19E5];
    Aux_00638C28 *p2534;
    u8 pad2538[0x2544 - 0x2538];
    s32 s2544;
} Self_00638C28;

typedef struct Tab_00638C28 {
    u8 pad0[0xA4];
    u8 bA4[0x100];
} Tab_00638C28;

extern u8 D_L39_004998A0[];
extern Tab_00638C28 D_001A5990;
extern s32 func_L39_00627608(void *);
extern s32 func_L01_004FB720(void *);
extern s32 func_L39_005C2098(s32, s32);
extern s32 func_L01_0045D3E8(s32, s32, s32, s32, void *);
extern s32 func_L01_0045D358(s32, s32, void *, void *);

s32 func_L39_006363E0(Self_00638C28 *s) {
    s32 a;
    s32 b;
    u8 *q;
    Buf_00638C28 buf;
    u32 r;
    u32 x;
    u32 y;
    s32 n;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    if (s->h320 != 0) {
        return 1;
    }
    q = &s->b19E4;
    if (*q == 0) {
        r = 0;
    } else {
        n = *q;
        k = ((u32)q - n) & 7;
        m = n + 1;
        d = buf.b;
        for (i = 0; i < 40; i += 5) {
            *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
        }
        x = buf.w[0] ^ (u32)q;
        y = buf.w[1] ^ x;
        buf.w[0] = x;
        buf.w[1] = y;
        r = y;
    }
    if ((r ^ 14) == 0) {
        return 0;
    }
    a = func_L39_00627608(s);
    b = func_L01_004FB720(s);
    if ((s->p2534->w1A0 & func_L39_005C2098(8, s->s2544)) != 0) {
        if (b > 0) {
            if (D_001A5990.bA4[s->s2544] != 2 || (u32)(a - 2) >= 2) {
                if (func_L01_0045D3E8(func_L39_005C2098(0x40, s->s2544), 0x1F000, b + 5, b, s->p2534) != 0) {
                    s->vt->f34(s, 0xB, 1, 0, 1);
                    return 1;
                }
            }
        }
    }
    if (s->s2F0 >= 7) {
        if (func_L01_0045D358(func_L39_005C2098(0x40, s->s2544), 9, 0, s->p2534) != 0) {
            s->vt->f34(s, 7, 1, 0, 1);
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L39_006363E0 */
