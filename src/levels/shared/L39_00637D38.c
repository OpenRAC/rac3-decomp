#include "common.h"

/* localdecomp:start func_L39_00637D38 */
typedef int u128_00637D38 __attribute__((mode(TI)));

extern s32 func_0038CB00(void *);
extern void func_L39_00637E10(void *);

void func_L39_00637D38(u8 *g) {
    s32 b;
    s32 h;
    f32 f;

    *(u128_00637D38 *)(g + 0x3D0) = *(u128_00637D38 *)(g + 0xFC0);
    *(f32 *)(g + 0x3E8) = *(f32 *)(g + 0xFD0);
    func_0038CB00(g + 0x3F8);
    func_0038CB00(g + 0x3FA);
    b = g[0x3E7];
    f = 1.0f;
    if (b == 0) {
        *(s16 *)(g + 0x3FA) = 3;
        if (*(s16 *)(g + 0x3F8) != 0) {
            f = (f32)(b / 3);
        }
    } else if (b == 1) {
        *(s16 *)(g + 0x3F8) = 3;
        h = *(s16 *)(g + 0x3FA);
        if (h != 0) {
            f = (f32)((3 - h) / 3);
        }
    }
    *(f32 *)(g + 0xFB4) *= f;
    func_L39_00637E10(g);
    *(s32 *)(g + 0xFD8) = 0;
    *(s32 *)(g + 0xFD4) = 0;
}
/* localdecomp:end func_L39_00637D38 */

INCLUDE_ASM("asm/levels", func_L39_00637E10);

INCLUDE_ASM("asm/levels", func_L39_00637EC8);

INCLUDE_ASM("asm/levels", func_L39_00638458);

/* localdecomp:start func_L39_006384B0 */
typedef struct {
    char _p0[0xFB0];
    s32 fFB0;
    s32 fFB4;
} S1_006384B0;

/* from rac4-decomp's func_00162968 */
void func_L39_006384B0(S1_006384B0 *arg0) {
    arg0->fFB0 = 0;
    arg0->fFB4 = 0;
}
/* localdecomp:end func_L39_006384B0 */

INCLUDE_ASM("asm/levels", func_L39_006384C0);

/* localdecomp:start func_L39_006387D0 */
extern void func_0038CE20(void *, void *, f32);

void func_L39_006387D0(u8 *a0, f32 s) {
    func_0038CE20(a0 + 320, a0 + 320, s);
    func_0038CE20(a0 + 336, a0 + 336, s);
    func_0038CE20(a0 + 288, a0 + 288, s);
    func_0038CE20(a0 + 400, a0 + 400, s);
    *(f32 *)(a0 + 4020) *= s;
}
/* localdecomp:end func_L39_006387D0 */

INCLUDE_ASM("asm/levels", func_L39_00638848);

/* localdecomp:start func_L39_00638C28 */
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

extern u8 D_L39_004997E0[];
extern Tab_00638C28 D_001A5810;
extern s32 func_L39_00629DE0(void *);
extern s32 func_L01_004FF5D8(void *);
extern s32 func_L39_005C42E8(s32, s32);
extern s32 func_L01_00460778(s32, s32, s32, s32, void *);
extern s32 func_L01_004606E8(s32, s32, void *, void *);

s32 func_L39_00638C28(Self_00638C28 *s) {
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
            *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
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
    a = func_L39_00629DE0(s);
    b = func_L01_004FF5D8(s);
    if ((s->p2534->w1A0 & func_L39_005C42E8(8, s->s2544)) != 0) {
        if (b > 0) {
            if (D_001A5810.bA4[s->s2544] != 2 || (u32)(a - 2) >= 2) {
                if (func_L01_00460778(func_L39_005C42E8(0x40, s->s2544), 0x1F000, b + 4, b, s->p2534) != 0) {
                    s->vt->f34(s, 0xB, 1, 0, 1);
                    return 1;
                }
            }
        }
    }
    if (s->s2F0 >= 6) {
        if (func_L01_004606E8(func_L39_005C42E8(0x40, s->s2544), 7, 0, s->p2534) != 0) {
            s->vt->f34(s, 7, 1, 0, 1);
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L39_00638C28 */

INCLUDE_ASM("asm/levels", func_L39_00638DF0);

INCLUDE_ASM("asm/levels", func_L39_00638F50);

INCLUDE_ASM("asm/levels", func_L39_006390D0);
