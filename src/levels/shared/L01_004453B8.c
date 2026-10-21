#include "common.h"

/* localdecomp:start func_L01_004453B8 */
extern f32 func_0038DB00(f32 a, f32 b);
extern f32 func_0038D098(f32 a);
extern f32 func_0038DAB8(f32 a, f32 b);

f32 func_L01_004453B8(f32 a, f32 b, f32 t) {
    f32 r = func_0038DB00(b, a);
    f32 c = func_0038D098(t * 3.1415927f);
    return func_0038DAB8(a, r * ((1.0f - c) * 0.5f));
}
/* localdecomp:end func_L01_004453B8 */

INCLUDE_ASM("asm/levels", func_L01_00445438);

/* localdecomp:start func_L01_00445510 */
extern f32 func_0038D098(f32 a);
extern f32 func_0038DB00(f32 a, f32 b);
extern f32 func_0038DAB8(f32 a, f32 b);
void func_L01_00445510(f32 *out, f32 *a, f32 *b, f32 t) {
    f32 h = (1.0f - func_0038D098(t * 3.1415927f)) * 0.5f;
    out[0] = func_0038DAB8(a[0], func_0038DB00(b[0], a[0]) * h);
    out[1] = func_0038DAB8(a[1], func_0038DB00(b[1], a[1]) * h);
    out[2] = func_0038DAB8(a[2], func_0038DB00(b[2], a[2]) * h);
}
/* localdecomp:end func_L01_00445510 */

LINKER_REMNANT("asm/levels", func_L01_004455D0);

INCLUDE_ASM("asm/levels", func_L01_004455E8);

LINKER_REMNANT("asm/levels", func_L01_00445720);

INCLUDE_ASM("asm/levels", func_L01_00445728);

LINKER_REMNANT("asm/levels", func_L01_00445AA8);

INCLUDE_ASM("asm/levels", func_L01_00445AD0);

INCLUDE_ASM("asm/levels", func_L01_00445BE0);

LINKER_REMNANT("asm/levels", func_L01_00445C38);

INCLUDE_ASM("asm/levels", func_L01_00445C48);

/* localdecomp:start func_L01_00445D30 */
extern u8 *D_L01_001E0214;
extern s32 D_L01_001E0058;
extern s16 *D_L01_001E020C;
extern s16 *D_L01_0021DE20[];
extern u8 *D_L01_001E001C;
extern u16 D_L01_001E0210;
s32 func_L01_00445D30(u8 **out, u8 *start, s32 a2, s32 a3) {
    s16 *p;
    s32 neg;
    s32 idx;
    *out = 0;
    if (start != D_L01_001E0214) {
        if (D_L01_001E0058 < start[33]) {
            goto fail;
        }
        D_L01_001E0214 = 0;
        D_L01_001E020C = D_L01_0021DE20[start[33]];
        if (D_L01_001E020C == 0) {
        fail:
            return -1;
        }
        D_L01_001E020C = D_L01_001E020C - 1;
        do {
            p = D_L01_001E020C;
            D_L01_001E020C = p + 1;
            idx = p[1] & 0x7FFF;
            D_L01_001E0210 = idx;
            D_L01_001E0214 = D_L01_001E001C + (idx << 8);
            if (p[1] < 0) {
                goto fail;
            }
        } while (start != D_L01_001E0214);
    } else if (*D_L01_001E020C < 0) {
        goto fail;
    }
    do {
        p = D_L01_001E020C;
        D_L01_001E020C = p + 1;
        idx = p[1] & 0x7FFF;
        D_L01_001E0210 = idx;
        D_L01_001E0214 = D_L01_001E001C + (idx << 8);
        *out = D_L01_001E0214;
        neg = (s8)D_L01_001E0214[32] < 0;
        if (!a2) {
            if (a3) {
                continue;
            }
            if (!neg) {
                goto ret0;
            }
        } else if (!a3 || neg) {
        ret0:
            return 0;
        }
    } while (*D_L01_001E020C >= 0);
    *out = 0;
    return -1;
}
/* localdecomp:end func_L01_00445D30 */

LINKER_REMNANT("asm/levels", func_L01_00445E98);

/* localdecomp:start func_L01_00445EA8 */
s32 func_L01_00445EA8(s32 *a0, s32 a1) {
    s32 v = *a0;
    s32 n = (v >> 24) - a1;
    if (n < 0) {
        n = 0;
    }
    *a0 = (v & 0xFFFFFF) | (n << 24);
    return n == 0;
}
/* localdecomp:end func_L01_00445EA8 */

INCLUDE_ASM("asm/levels", func_L01_00445EE0);

/* localdecomp:start func_L01_00445F40 */
extern u8 D_L01_001FDBD0[];
extern u8 *D_L01_001FD180[];
extern void func_003C29B0(u8 *);
extern void func_003C7C38(u8 *);
s32 func_L01_00445F40(u8 *m, s32 a1) {
    u8 *p;
    u8 *q;

    if (*(s16 *)(m + 170) == a1) {
        return 0;
    }
    *(s16 *)(m + 170) = a1;
    m[34] = D_L01_001FDBD0[(s16)a1];

    *(u8 **)(m + 36) = D_L01_001FD180[m[34]];
    func_003C29B0(m);
    p = *(u8 **)(m + 36);
    m[98] = p[14];
    *(f32 *)(m + 44) = *(f32 *)(p + 36);
    if (*(s32 *)(m + 152) != 0) {
        *(s32 *)(m + 152) = *(s32 *)(p + 16);
    }
    m[97] = 255;
    q = *(u8 **)(m + 36);
    if (q != 0) {
        if (*(s32 *)(q + 64) != 0) {
            *(u16 *)(m + 52) |= 0x10;
            *(s32 *)(m + 120) = *(s32 *)(q + 64);
        }
        if ((*(u8 **)(m + 36))[15] != 0) {
            m[111] = 24;
            *(u16 *)(m + 52) |= 0x400;
            *(s32 *)(m + 112) = 0;
            *(s32 *)(m + 116) = 0;
            m[189] = 0;
        }
        if ((*(u8 **)(m + 36))[6] != 0) {
            m[99] = 24;
        }
    }
    func_003C7C38(m);
    return 1;
}
/* localdecomp:end func_L01_00445F40 */

/* localdecomp:start func_L01_00446058 */
extern void func_003C7C38(u8 *);
extern void func_003C29B0(u8 *);
extern u8 *D_L01_001FD180[];
typedef struct { u8 p0[0x6]; u8 b6; u8 p7[7]; u8 bE; u8 bF; s32 w10; u8 p14[0x2C]; s32 w40; } S_442F20;
typedef struct {
    u8 p0[0x22]; u8 b22; u8 p23; S_442F20 *w24; u8 p28[0xC]; u16 h34; u8 p36[0x2B]; u8 b61; u8 b62; u8 b63;
    u8 p64[0xB]; u8 b6F; u8 p70[4]; s32 w74; s32 w78; u16 h7C; u8 p7E[0x1A]; s32 w98; u8 p9C[0xE]; s16 hAA;
} P_442F20;
extern u8 D_L01_001FDBD0[];
extern void func_L01_00443EA0(s32, s32);
extern void func_L01_00439880(P_442F20 *, u16 *, s32 *);

s32 func_L01_00446058(P_442F20 *p, s32 b, s32 c) {
    struct { u16 h; u16 pad; s32 w; } tmp;
    if (p->hAA == b) {
        return 0;
    }
    p->hAA = b;
    p->b22 = D_L01_001FDBD0[(s16)b];
    p->w24 = ((S_442F20 * *)&D_L01_001FD180)[p->b22];
    p->b61 = 0xFF;
    func_L01_00443EA0(b, c);
    ((void (*)(P_442F20 *))func_003C29B0)(p);
    p->b62 = p->w24->bE;
    if (p->w98 != 0) {
        p->w98 = p->w24->w10;
    }
    if (p->w24 != 0) {
        if (p->w24->w40 != 0) {
            p->h34 |= 0x10;
            p->w78 = p->w24->w40;
        } else {
            p->w78 = 0;
            p->h34 &= ~0x10;
        }
        if (p->w24->bF != 0) {
            p->b6F = 0x18;
            p->h34 |= 0x400;
        } else {
            p->b6F = 0;
            p->h34 &= ~0x400;
            p->w74 = 0;
        }
        if (p->w24->b6 != 0) {
            p->b63 = 0x18;
        } else {
            p->b63 = 0;
        }
        if (p->h7C != 0) {
            func_L01_00439880(p, &tmp.h, &tmp.w);
            p->h7C = tmp.h;
        }
    }
    ((void (*)(P_442F20 *))func_003C7C38)(p);
    return 1;
}
/* localdecomp:end func_L01_00446058 */

LINKER_REMNANT("asm/levels", func_L01_004461B0);

INCLUDE_ASM("asm/levels", func_L01_004461B8);
