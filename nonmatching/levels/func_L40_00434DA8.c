/* NTSC-U draft (2026-11-14, Claude worker): C of func_L40_00434240, the NTSC-U twin of func_L40_00434DA8, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/shared/L40_00434AB8.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division -mno-split-addresses").
 */
#include "common.h"

/* localdecomp:start func_L40_00434240 */
typedef struct V4_00434240 {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_00434240;

typedef union Buf {
    u8 b[8];
    u32 w[2];
    f32 f[4];
} Buf;

typedef struct S_00434240 {
    f32 f0;
    f32 f4;
    s32 w8;
    u8 *p0C;
    u8 pad10[1];
    u8 b11;
    u8 pad12[0x30 - 0x12];
    f32 f30;
} S_00434240;

typedef struct G_00434240 {
    u8 pad[0x190];
    s8 b190;
} G_00434240;

__asm__(".extern D_L40_002417C0, 16");
extern G_00434240 *D_L40_002417C0;
extern s32 *D_L40_002412A0;
extern u8 D_L40_003BFF60[];
extern u8 D_L40_003BFF61[];
__asm__(".extern D_L40_00248048, 16");
extern u32 D_L40_00248048;

extern s32 func_L39_005BC958(void *, s32, f32);
extern s32 func_L40_00434200(void *);
extern void func_003BD360(void *);
extern void func_L01_00437350(void *, s32, void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern u8 *func_L39_006197C0(s32);
extern void func_L39_005F0CE0(s32, s32, void *);
extern s32 func_L01_00452EC8(void *);
extern void func_L01_00402498(void *, void *);
extern f32 func_003BEBF8(void *, f32, f32);
extern void func_00389018(void *, s32, f32);
extern f32 func_003893C8(f32, f32);
extern void func_L40_00434820(void);

static inline u8 Gt(f32 a, f32 b) {
    return (u8)(a > b);
}

static inline u8 Ne(f32 a, f32 b) {
    return (u8)(a != b);
}

static inline f32 SfGet(u8 *q) {
    Buf buf;
    s32 n, k, m, i;
    u8 *d;
    if (*q == 0) {
        return 0.0f;
    }
    n = *q;
    k = ((u32)q - n) & 7;
    m = n + 1;
    d = buf.b;
    for (i = 0; i < 40; i += 5) {
        *d++ = D_L40_003BFF60[m + ((k + i) & 7) * 255];
    }
    buf.w[0] ^= (u32)q;
    buf.w[1] ^= buf.w[0];
    return buf.f[1];
}

static inline void SfSet(u8 *q, f32 v) {
    u8 *hk = q;
    Buf buf;
    u32 key;
    s32 k, m, j, tt;
    u8 *d;
    if (*q == 0) {
        *q = ++D_L40_003BFF60[0];
    } else {
        tt = *q;
        *q = D_L40_003BFF61[0];
        D_L40_003BFF61[0] = tt;
    }
    key = ((u32 *)D_L40_003BFF60)[((u32)hk * D_L40_00248048) % 510];
    k = ((u32)q - *q) & 7;
    buf.w[0] = (u32)q ^ key;
    buf.f[1] = v;
    buf.w[1] ^= key;
    m = *q + 1;
    d = buf.b;
    for (j = 0; j < 40; j += 5) {
        D_L40_003BFF60[m + ((k + j) & 7) * 255] = *d++;
    }
}

void func_L40_00434240(u8 *a0) {
    S_00434240 *s;
    V4_00434240 vec;
    s32 s5;
    s32 i;

    s = *(S_00434240 **)(a0 + 0x68);
    if (*(u16 *)(a0 + 0x96) < 0x7FFD) {
        *(u16 *)(a0 + 0x96) += 1;
    }
    vec = *(V4_00434240 *)(a0 + 0x10);
    vec.w = 2.0f;
    if (func_L39_005BC958(&vec, 0, (f32)a0[0x30]) == -1) {
        s->w8 = 0;
        return;
    }
    s5 = func_L40_00434200(a0);
    switch (a0[0x20]) {
    case 0:
        if (D_L40_002417C0->b190 == 0) {
            func_003BD360(a0);
            return;
        }
        s->p0C = 0;
        if (s->b11 == 0) {
            func_L01_00437350(a0, 0, (u8 *)s + 0x10);
        }
        func_L01_00441FB8(a0, 1, -1);
    case 1:
        if (s->p0C != 0) {
            if (*(u8 **)(s->p0C + 0x2CC) != a0) {
                s->p0C = 0;
            }
        } else {
            for (i = 0; i < *D_L40_002412A0; i++) {
                u8 *t0 = func_L39_006197C0(i);
                s32 ok;
                s32 t4;
                f32 zero;
                if (t0 != 0 && *(u8 **)(t0 + 0x2CC) == a0 && *(s16 *)(t0 + 0x2DE) == 0) {
                    f32 fa = SfGet(t0 + 0x2554);
                    f32 fb = SfGet(t0 + 0x2476);
                    ok = fb < fa;
                    if ((u8)ok && s5 != 0) {
                        if (s->w8 == 0) {
                            s32 arg = 0;
                            s->w8 = 1;
                            t4 = (s32)SfGet(t0 + 0x2554);
                            zero = 0.0f;
                            ok = SfGet(t0 + 0x2476) != zero;
                            if ((u8)ok) {
                                SfSet(t0 + 0x2476, (f32)t4);
                                *(s32 *)(t0 + 0x2514) = 360;
                            }
                            s->p0C = t0;
                            func_L39_005F0CE0(arg, 0, a0);
                            func_L01_00441FB8(a0, 2, -1);
                            break;
                        }
                    } else {
                        s->w8 = 0;
                    }
                } else {
                    s->w8 = 0;
                }
            }
        }
        break;
    case 2:
        if (func_L01_00452EC8(a0) != 0) {
            s->f0 = 0.0f;
        }
        if (s->f0 < 0.85f) {
            func_L01_00402498(func_L40_00434820, a0);
            func_003BEBF8(s, 0.85f, 0.033333335f);
        } else {
            func_L01_00441FB8(a0, 1, -1);
        }
        break;
    }
    if (s5 != 0) {
        s->f30 = 1.0f;
    } else {
        s->f30 = 0.0f;
    }
    func_00389018((u8 *)s + 0x20, 2, s->f4);
    s->f4 = func_003893C8(s->f4, 0.058177646f);
}
/* localdecomp:end func_L40_00434240 */
