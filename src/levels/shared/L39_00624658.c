#include "common.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
    u8 b0;
    u8 b1;
    u8 b2;
} S_00627EF8;

/* declared by functions of L39_00622990.c, which this file was cut from */
extern u8 D_L39_004997E0[];
extern void func_L39_00623FB8(void *);
extern void func_L39_006244E0(u8 *);

/* declared by functions of L39_00623FB8.c, which this file was cut from */
extern u8 D_L39_004997E0[];

/* localdecomp:start func_L39_00624658 */
#include "vu0.h"

typedef union Buf_00624658 {
    u8 b[8];
    u32 w[2];
    u16 h[4];
    s16 s[4];
    f32 f[2];
} Buf_00624658;

typedef int Q_00624658 __attribute__((mode(TI)));

extern u8 D_L39_004997E0[];
extern u8 D_L39_004997E1[];
extern u32 D_L39_0024B9C8;

extern void func_L39_0062FE58(u8 *);
extern s32 func_0038CB00(void *);
extern s32 func_L01_0040E050(void *);
extern s32 func_0038CAD0(void *);
extern void func_L39_00634F38(u8 *);
extern u8 *func_L39_0061D7B0(void *);
extern void func_003C5060(void *, void *, void *, void *);
extern void func_0038D000(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00446A70(void *, void *, s32, void *, void *, f32);
extern s32 func_L39_00648840(void *, s32);
extern void func_L39_00648960(void *, s32);
extern s32 func_L01_004606E8(s32, s32, s32, s32);
extern s32 func_L39_006212E8(void *);
extern f32 func_L39_00632678(u8 *, f32 *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CEA8(void *);
extern void func_L39_00629958(u8 *);
extern void func_L39_00632180(u8 *, f32 *, s32, f32, f32, f32);
extern void func_L39_00628038(void *, s32);

static inline void Prep_00624658(u8 *q) {
    if (*q == 0) {
        *q = ++D_L39_004997E0[0];
    } else {
        s32 t = *q;
        *q = D_L39_004997E1[0];
        D_L39_004997E1[0] = t;
    }
}

static inline void Set16_00624658(u8 *q, s16 v) {
    u8 *hk = q;
    Buf_00624658 buf;
    u32 key = 0;
    s32 k = 0;
    s32 m = 0;
    s32 i;
    u8 *d = 0;

    Prep_00624658(q);
    k = ((u32)q - *q) & 7;
    buf.h[2] = v;
    key = ((u32 *)D_L39_004997E0)[((u32)hk * D_L39_0024B9C8) % 510];
    buf.w[0] = (u32)q ^ key;
    buf.w[1] = ((buf.w[1] & 0xFFFF) | (buf.w[1] << 16)) ^ key;
    m = *q + 1;
    d = buf.b;
    for (i = 0; i < 24; i += 3) {
        D_L39_004997E0[m + ((k + i) & 7) * 255] = *d++;
    }
}

static inline u16 Dec16_00624658(u8 *q) {
    Buf_00624658 buf;
    u32 a = 0;
    u32 b = 0;
    s32 n = 0;
    s32 k = 0;
    s32 m = 0;
    s32 i;
    u8 *d = 0;

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

static inline u8 DecB_00624658(u8 *q) {
    Buf_00624658 buf;
    u32 a = 0;
    u32 b = 0;
    s32 n = 0;
    s32 k = 0;
    s32 m = 0;
    s32 i;
    u8 *d = 0;

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
    return buf.b[4];
}

static inline u32 Dec32_00624658(u8 *q) {
    Buf_00624658 buf;
    u32 a = 0;
    s32 n = 0;
    s32 k = 0;
    s32 m = 0;
    s32 i;
    u8 *d = 0;

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

static inline s32 Get16_00624658(u8 *q) {
    return (s16)Dec16_00624658(q);
}

static inline void Sub16_00624658(u8 *q, s32 d) {
    s32 v = Get16_00624658(q) - d;
    Set16_00624658(q, v);
}


void func_L39_00624658(void *arg0) {
    u8 *g = arg0;

    if (DecB_00624658(g + 0x1A18) == 0) {
        func_L39_0062FE58(g);
    }
    (*(s32 *)(g + 0x2F0))++;
    (*(s32 *)(g + 0x2F4))++;
    (*(s32 *)(g + 0x2F8))++;
    (*(s32 *)(g + 0x2FC))++;
    (*(u16 *)(g + 0x31E))++;
    func_0038CB00(g + 0x320);
    if (Get16_00624658(g + 0x311) > 0) {
        Sub16_00624658(g + 0x311, 1);
    } else {
        Set16_00624658(g + 0x311, 0);
    }
    func_0038CB00(g + 0x30A);
    if (Get16_00624658(g + 0x31B) > 0) {
        Sub16_00624658(g + 0x31B, 1);
    } else {
        Set16_00624658(g + 0x31B, 0);
    }
    func_0038CB00(g + 0x308);
    func_0038CB00(g + 0x332);
    if (Get16_00624658(g + 0x313) > 0) {
        Sub16_00624658(g + 0x313, 1);
    } else {
        Set16_00624658(g + 0x313, 0);
    }
    func_L01_0040E050(g + 0x328);
    func_0038CB00(g + 0x32C);
    func_0038CB00(g + 0x334);
    if (Get16_00624658(g + 0x316) > 0) {
        Sub16_00624658(g + 0x316, 1);
    } else {
        Set16_00624658(g + 0x316, 0);
    }
    func_0038CB00(g + 0x336);
    if (Get16_00624658(g + 0x318) > 0) {
        Sub16_00624658(g + 0x318, 1);
    } else {
        Set16_00624658(g + 0x318, 0);
    }
    if (Get16_00624658(g + 0x314) > 0) {
        Sub16_00624658(g + 0x314, 1);
    } else {
        Set16_00624658(g + 0x314, 0);
    }
    func_0038CB00(g + 0x32E);
    func_0038CB00(g + 0x33E);
    func_0038CB00(g + 0x340);
    func_0038CB00(g + 0x342);
    if (Get16_00624658(g + 0x31A) > 0) {
        Sub16_00624658(g + 0x31A, 1);
    } else {
        Set16_00624658(g + 0x31A, 0);
    }
    if (Get16_00624658(g + 0x312) > 0) {
        Sub16_00624658(g + 0x312, 1);
    } else {
        Set16_00624658(g + 0x312, 0);
    }
    func_0038CB00(g + 0x348);
    func_0038CB00(g + 0x34A);
    func_0038CAD0(g + 0x35C);
    func_0038CAD0(g + 0x360);
    if ((Dec32_00624658(g + 0x19E6) ^ 0x14) != 0 && (Dec32_00624658(g + 0x19E4) ^ 0x7A) != 0) {
        (*(s32 *)(g + 0x350))++;
    } else {
        *(s32 *)(g + 0x350) = 0;
    }
    func_L39_00634F38(g);
    if (g[0x1A07] != 0) {
        (*(s32 *)(g + 0x30C))++;
    } else {
        *(s32 *)(g + 0x30C) = 0;
    }
    {
        u8 *p = *(u8 **)(g + 0x1FC);
        if (p != 0 && *(s16 *)(p + 0xAA) == 0x107C &&
            (*(s32 *)(g + 0x360) == 0 || *(u8 **)(g + 0x2578) != p)) {
            u8 *o = func_L39_0061D7B0(p);
            f32 a = fabs_asm(*(f32 *)(o + 0x310));
            if (0.100000009f < a) {
                f32 v[4] __attribute__((aligned(16)));
                void *t;
                f32 s;
                vec_sub_ba(v, g + 0xA0, p + 0x10);
                func_003C5060(p, v, v, 0);
                *(s32 *)&v[0] = 0;
                s = (v[1] < v[0]) ? -1.0f : 1.0f;
                v[1] = s;
                v[2] = v[0];
                func_0038D000(v, v, p + 0xC0);
                func_0038CF68(v, v, 0.200000018f);
                v[2] = 0.0800000057f;
                t = 0;
                if (*(u8 **)(o + 0x2D8) != 0) {
                    t = *(void **)(*(u8 **)(o + 0x2D8) + 0x2524);
                }
                if (*(s32 *)(g + 0x2D0) >= 9 &&
                    (*(u8 **)(g + 0x2CC) == 0 || *(s16 *)(*(u8 **)(g + 0x2CC) + 0xAA) != 0x107C) &&
                    0.340000033f < *(f32 *)(o + 0x310)) {
                    Set16_00624658(g + 0x313, 1000);
                    func_L01_00446A70(*(void **)(g + 0x2524), t, 8, g + 0x1D0, v, 20.0f);
                } else {
                    s = a / 0.340000033f;
                    if (1.0f < s) {
                        s = 1.0f;
                    }
                    func_L01_00446A70(*(void **)(g + 0x2524), t, 1, g + 0x1D0, v, s * 4.0f + 2.0f);
                }
            }
        }
    }
    if (g[0x1A06] == 1 && func_L39_00648840(g, 0xB) == 0) {
        func_L39_00648960(g, 0xB);
    }
    if (g[0x1A06] != 0 && Dec32_00624658(g + 0x19E6) == 0 && *(s32 *)(g + 0x2D0) != 0 &&
        *(f32 *)(g + 0x1A0) < 0.002f && *(f32 *)(g + 0x1B4) < 0.002f) {
        *(Q_00624658 *)(g + 0xA0) = *(Q_00624658 *)(g + 0x100);
    }
    if ((*(s16 *)(g + 0x3E4) != 0 ||
         (*(s32 *)(g + 0x1310) == 1 && func_L01_004606E8(0x28, 2, 0, *(s32 *)(g + 0x2534)) != 0 &&
          func_L39_006212E8(g) != 10)) &&
        (Dec32_00624658(g + 0x19E4) ^ 0x10) != 0) {
        *(s32 *)(g + 0x324) = 0;
    } else {
        (*(s32 *)(g + 0x324))++;
    }
    if (*(s16 *)(g + 0x2DE) != 0 && func_L39_00632678(g, (f32 *)(g + 0x120)) < 0.0f) {
        if (*(s32 *)(g + 0x234C) == 0x20) {
            f32 sum[4] __attribute__((aligned(16)));
            s32 i;
            s32 n = 8;
            qzero(sum);

            for (i = 0; i < n; i++) {
                f32 d[4] __attribute__((aligned(16)));
                s32 j0 = (*(s32 *)(g + 0x2348) - i + 31) % 32;
                s32 j1 = (*(s32 *)(g + 0x2348) - i + 30) % 32;
                vec_sub_ab(d, g + 0x1DC0 + j0 * 16, g + 0x1DC0 + j1 * 16);
                vec_add_ab(sum, sum, d);
            }
            func_0038CE20(sum, sum, 1.0f / n);
            if (func_0038CEA8(sum) < 0.0200000014f) {
                (*(u16 *)(g + 0x330))++;
            } else {
                *(u16 *)(g + 0x330) = 0;
            }
        }
    } else {
        *(u16 *)(g + 0x330) = 0;
    }
    func_L39_00629958(g);
    func_L39_00632180(g, (f32 *)(g + 0xE0), 1, 0.0f, 0.0f, 0.7f);
    if (*(f32 *)(g + 0xA8) < 1.0f) {
        (*(void (**)(void *, s32, s32, s32, s32))(*(u8 **)(g + 0x14) + 0x34))(g, 0x76, 1, 0, 1);
        func_L39_00628038(g, 0);
    }
}
/* localdecomp:end func_L39_00624658 */
