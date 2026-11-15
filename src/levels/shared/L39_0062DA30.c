#include "common.h"

typedef struct {
    u8 pad0[8128];
    f32 hist[224];
    s32 head;
    s32 count;
} S_0062F240;
typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;
typedef struct {
    u8 pad0[0x20];
    f32 m0[4][4];
    f32 m1[4][4];
    u8 pad[0x1A06 - 0xA0];
    u8 mode;
} Obj62FA50;
typedef struct {
    u8 pad[32];
    u8 m20[64];
    u8 m60[6662 - 96];
    u8 mode;
} S_62FD10;

/* declared by functions of L39_0062D7C8.c, which this file was cut from */
extern u8 D_L39_004997E0[];
extern s32 func_L01_004606E8(s32, s32, void *, void *);
extern s32 func_L39_006212E8(void *);

/* localdecomp:start func_L39_0062DA30 */
typedef union {
    u8 b[8];
    u32 w[2];
} Buf_0062DA30;

typedef struct {
    u8 pad0[0x10];
    u8 b10;
} Ent_0062DA30;

typedef struct {
    u8 pad0[0x48];
    Ent_0062DA30 *e[1];
} Arr_0062DA30;

typedef struct {
    u8 pad0[0x24];
    Arr_0062DA30 *p24;
    u8 pad28[0x41 - 0x28];
    u8 b41;
    u8 pad42;
    u8 b43;
} Obj_0062DA30;

typedef struct {
    u8 pad0[0x2F8];
    s32 w2F8;
    u8 pad2FC[0x3E4 - 0x2FC];
    s16 h3E4;
    u8 b3E6;
    u8 pad3E7;
    u8 pad3E8[0x610 - 0x3E8];
    f32 f610;
    u8 pad614[0xFB4 - 0x614];
    f32 fFB4;
    u8 padFB8[0x1310 - 0xFB8];
    s32 w1310;
    u8 pad1314[0x142E - 0x1314];
    u8 b142E;
    u8 pad142F[0x19E4 - 0x142F];
    u8 b19E4;
    u8 b19E5;
    u8 pad19E6[0x2524 - 0x19E6];
    Obj_0062DA30 *p2524;
    u8 pad2528[0x2534 - 0x2528];
    void *p2534;
} S_0062DA30;

extern u8 D_L39_004997E0[];
extern u8 D_L39_004997E1[];
extern u32 D_L39_0024B9C8;
__asm__(".extern D_001DA8E8_sda, 8");
extern f32 D_001DA8E8_sda[][4] __attribute__((section(".sdata")));
extern f32 D_L39_00245FFC[][4] __attribute__((section(".sdata")));
extern s32 D_L39_002460D8[][2] __attribute__((section(".sdata")));

extern s32 func_L01_004606E8(s32, s32, void *, void *);
extern s32 func_L39_006212E8(void *);
extern void func_L39_0062B4A8(void *, s32, s32, s32, f32);

static __inline__ s32 Dec_0062DA30(u8 *q) {
    Buf_0062DA30 buf;
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

static __inline__ s32 DecEq_0062DA30(u8 *q, s32 v) {
    return Dec_0062DA30(q) == v;
}

static __inline__ s32 DecGt_0062DA30(u8 *q, s32 v) {
    return Dec_0062DA30(q) > v;
}

static __inline__ void Prep_0062DA30(u8 *q) {
    s32 t;
    if (*q == 0) {
        *q = ++D_L39_004997E0[0];
    } else {
        t = *q;
        *q = D_L39_004997E1[0];
        D_L39_004997E1[0] = t;
    }
}

static __inline__ void Set_0062DA30(u8 *q, s32 v) {
    u8 *hk = q;
    Buf_0062DA30 buf;
    u32 key;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    Prep_0062DA30(q);
    key = ((u32 *)D_L39_004997E0)[((u32)hk * D_L39_0024B9C8) % 510];
    k = ((u32)q - *q) & 7;
    buf.w[0] = (u32)q ^ key;
    buf.w[1] = v ^ key;
    m = *q + 1;
    d = buf.b;
    for (i = 0; i < 40; i += 5) {
        D_L39_004997E0[m + ((k + i) & 7) * 255] = *d++;
    }
}

void func_L39_0062DA30(S_0062DA30 *s) {
    s32 c;
    s32 cur;
    s32 t;
    s32 x;
    u8 *p;

    if (s->h3E4 != 0 ||
        (s->w1310 == 1 && func_L01_004606E8(0x28, 2, 0, s->p2534) != 0 &&
         func_L39_006212E8(s) != 10)) {
        if (!DecEq_0062DA30(&s->b19E4, 16) && s->b3E6 != 0) {
            if (s->p2524->b43 != 0x14) {
                func_L39_0062B4A8(s, 0x14, 0, 0, 9.0f);
            }
            s->f610 = s->fFB4 * 5.0f / 6.0f * 25.0f;
            if (s->f610 < 0.7f) {
                s->f610 = 0.7f;
            }
            if (s->f610 > 2.2f) {
                s->f610 = 2.2f;
            }
            return;
        }
    }
    if (s->p2524->b43 == 0x14) {
        func_L39_0062B4A8(s, Dec_0062DA30(p = &s->b19E5) + 3, 0, 0, 6.0f);
    } else if (s->w2F8 >= 4 && s->b142E == 0) {
        c = s->fFB4 < D_001DA8E8_sda[Dec_0062DA30(&s->b19E5)][0] * 0.020000001f;
        p = &s->b19E5;
        if (c || D_L39_00245FFC[Dec_0062DA30(&s->b19E5)][0] * 0.020000001f < s->fFB4) {
            if (s->w2F8 >= 4 && s->b142E == 0) {
                cur = Dec_0062DA30(&s->b19E5);
                if (c) {
                    while (s->fFB4 < D_001DA8E8_sda[Dec_0062DA30(&s->b19E5)][0] * 0.020000001f) {
                        Set_0062DA30(p, Dec_0062DA30(&s->b19E5) - 1);
                    }
                } else {
                    while (D_L39_00245FFC[Dec_0062DA30(&s->b19E5)][0] * 0.020000001f < s->fFB4) {
                        Set_0062DA30(p, Dec_0062DA30(&s->b19E5) + 1);
                    }
                }
                if (Dec_0062DA30(&s->b19E5) < 0) {
                    Set_0062DA30(&s->b19E5, 0);
                }
                if (DecGt_0062DA30(&s->b19E5, 1)) {
                    Set_0062DA30(&s->b19E5, 1);
                }
                if (cur != Dec_0062DA30(&s->b19E5)) {
                    t = *(D_L39_002460D8[cur] + Dec_0062DA30(&s->b19E5));
                    x = s->p2524->b41 * s->p2524->p24->e[Dec_0062DA30(&s->b19E5) + 3]->b10 /
                        s->p2524->p24->e[cur + 3]->b10;
                    func_L39_0062B4A8(s, Dec_0062DA30(&s->b19E5) + 3,
                                      (x + t) % s->p2524->p24->e[Dec_0062DA30(&s->b19E5) + 3]->b10, 0, 7.0f);
                }
            }
        }
    }
    switch (Dec_0062DA30(&s->b19E5)) {
    case 0:
        s->f610 = s->fFB4 * 130.83333f;
        if (s->f610 < 0.6f) {
            s->f610 = 0.6f;
        }
        if (s->f610 > 4.0f) {
            s->f610 = 4.0f;
        }
        break;
    case 1:
        s->f610 = s->fFB4 * 10.833333f;
        if (s->f610 < 0.6f) {
            s->f610 = 0.6f;
        }
        if (s->f610 > 2.2f) {
            s->f610 = 2.2f;
        }
        break;
    }
}
/* localdecomp:end func_L39_0062DA30 */
