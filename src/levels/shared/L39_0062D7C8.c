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

/* localdecomp:start func_L39_0062D7C8 */
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

extern Glob_0062D7C8 D_001A5810;
extern u8 D_L39_004997E0[];

extern s32 func_L01_004606E8(s32, s32, void *, void *);
extern s32 func_L01_00460778(s32, s32, s32, s32, void *);
extern s32 func_L01_004FF5D8(void *);
extern s32 func_L39_005C42E8(s32, s32);
extern s32 func_L39_006212E8(void *);
extern s32 func_L39_00629DE0(void *);

s32 func_L39_0062D7C8(Self_0062D7C8 *s, s32 a1, s32 a2) {
    s32 out;
    s32 window;

    if (func_L01_004606E8(func_L39_005C42E8(0x40, s->s2544), a1, &out, s->p2534) == 0) {
        return 0;
    }
    window = func_L01_004FF5D8(s);
    if ((s->p2534->w1A0 & func_L39_005C42E8(8, s->s2544)) != 0 && window > 0 &&
        (D_001A5810.bA4[s->s2544] != 2 || s->b3E7 != 3) &&
        func_L01_00460778(func_L39_005C42E8(0x40, s->s2544), 0x1F000, a1 + window, window,
                          s->p2534) != 0) {
        s->vt->fn34(s, 0xB, 1, 0, 1);
        return 1;
    }
    if (s->h3E4 != 0 ||
        (s->s1310 == 1 && func_L01_004606E8(0x28, 2, 0, s->p2534) != 0 &&
         func_L39_006212E8(s) != 10)) {
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
                *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
            }
            a = buf.w[0] ^ (u32)q;
            b = buf.w[1] ^ a;
            buf.w[0] = a;
            buf.w[1] = b;
            dec = b;
        }
        eq = dec == 0x10;
        if (!eq && 0.9f < s->f2468) {
            s32 r = func_L39_00629DE0(s);
            if (r != 2 && !(D_001A5810.bA4[s->s2544] == 2 && r == 3)) {
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
/* localdecomp:end func_L39_0062D7C8 */

INCLUDE_ASM("asm/levels", func_L39_0062DA30);

INCLUDE_ASM("asm/levels", func_L39_0062E930);

INCLUDE_ASM("asm/levels", func_L39_0062EF58);

INCLUDE_ASM("asm/levels", func_L39_0062FCF0);

/* localdecomp:start func_L39_0062FE58 */
typedef union Buf_0062FE58 {
    u8 b[8];
    u32 w[2];
    u128_t q;
    f32 f[4];
} Buf_0062FE58;

extern u8 D_L39_004997E0[];
extern f32 func_L01_00448728(s32, f32, s32, f32, f32, f32, s32);
extern void func_L39_006331D0(u8 *m, f32 x, f32 y, f32 z);
extern void func_L39_006302E0(u8 *s);

void func_L39_0062FE58(u8 *s) {
    Buf_0062FE58 buf;
    u32 dec;
    s32 eq;
    s32 mode;

    mode = s[0x1A06];
    if (*(s16 *)(s + 0x33E) != 0) {
        mode = 1;
    }
    switch (mode) {
    case 0:
        {
            u8 *q = s + 0x19E4;
            if (*q == 0) {
                dec = 0;
            } else {
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
                    *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
                }
                a = buf.w[0] ^ (u32)q;
                b = buf.w[1] ^ a;
                buf.w[0] = a;
                buf.w[1] = b;
                dec = b;
            }
        }
        eq = dec == 0x24;
        if (eq) {
            return;
        }
        {
            u8 *q = s + 0x19E4;
            if (*q == 0) {
                dec = 0;
            } else {
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
                    *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
                }
                a = buf.w[0] ^ (u32)q;
                b = buf.w[1] ^ a;
                buf.w[0] = a;
                buf.w[1] = b;
                dec = b;
            }
        }
        eq = dec == 0x25;
        if (eq) {
            return;
        }
        {
            u8 *q = s + 0x19E6;
            if (*q == 0) {
                dec = 0;
            } else {
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
                    *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
                }
                a = buf.w[0] ^ (u32)q;
                b = buf.w[1] ^ a;
                buf.w[0] = a;
                buf.w[1] = b;
                dec = b;
            }
        }
        eq = dec == 0x11;
        if (eq) {
            return;
        }
        {
            u8 *q = s + 0x19E4;
            if (*q == 0) {
                dec = 0;
            } else {
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
                    *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
                }
                a = buf.w[0] ^ (u32)q;
                b = buf.w[1] ^ a;
                buf.w[0] = a;
                buf.w[1] = b;
                dec = b;
            }
        }
        eq = dec == 0x76;
        if (eq) {
            return;
        }
        {
            u8 *q = s + 0x19E4;
            if (*q == 0) {
                dec = 0;
            } else {
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
                    *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
                }
                a = buf.w[0] ^ (u32)q;
                b = buf.w[1] ^ a;
                buf.w[0] = a;
                buf.w[1] = b;
                dec = b;
            }
        }
        eq = dec == 0x30;
        if (eq) {
            return;
        }
        {
            u8 *q = s + 0x19E4;
            if (*q == 0) {
                dec = 0;
            } else {
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
                    *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
                }
                a = buf.w[0] ^ (u32)q;
                b = buf.w[1] ^ a;
                buf.w[0] = a;
                buf.w[1] = b;
                dec = b;
            }
        }
        eq = dec == 0x2C;
        if (eq) {
            return;
        }
        {
            u8 *q = s + 0x19E4;
            if (*q == 0) {
                dec = 0;
            } else {
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
                    *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
                }
                a = buf.w[0] ^ (u32)q;
                b = buf.w[1] ^ a;
                buf.w[0] = a;
                buf.w[1] = b;
                dec = b;
            }
        }
        eq = dec == 0x2B;
        if (eq) {
            return;
        }
        buf.q = *(u128_t *)(s + 0xB0);
        func_L01_00448728((s32)&buf.f[0], 0.0f, (s32)(s + 0xC0), 0.0216f, 0.43200004f, 0.10471976f, 0);
        func_L01_00448728((s32)&buf.f[1], 0.0f, (s32)(s + 0xC4), 0.0216f, 0.43200004f, 0.10471976f, 0);
        func_L39_006331D0(s, *(f32 *)(s + 0xC0), *(f32 *)(s + 0xC4), 0.0f);
        break;
    case 1:
    case 2:
        func_L39_006302E0(s);
        break;
    }
}
/* localdecomp:end func_L39_0062FE58 */

INCLUDE_ASM("asm/levels", func_L39_006302E0);

/* localdecomp:start func_L39_006304A8 */
#include "vu0.h"
extern void func_0038D028(Vec4 *, Vec4 *, u8 *);
extern f32 func_0038D160(f32, f32);
extern void func_0038D328(float *, void *);
extern void func_0038D5B0(float *, float *);

void func_L39_006304A8(u8 *p, Vec4 *in, f32 *out) {
    float m[16];
    float inv[16];
    Vec4 v;

    v.q = in->q;
    func_0038D328(m, (void *)(*(s32 *)(p + 9508) + 240));
    func_0038D5B0(inv, m);
    ((void (*)(Vec4 *, Vec4 *, void *))func_0038D028)(&v, &v, inv);
    out[0] = func_0038D160(sqrt_asm(v.f[0] * v.f[0] + v.f[2] * v.f[2]), v.f[1]);
    out[1] = -func_0038D160(v.f[2], v.f[0]);
}
/* localdecomp:end func_L39_006304A8 */

INCLUDE_ASM("asm/levels", func_L39_00630548);

/* localdecomp:start func_L39_00631100 */
#include "vu0.h"

typedef union Buf_00631100 {
    u8 b[8];
    u32 w[2];
} Buf_00631100;

extern u8 D_L39_004997E0[];
extern f32 func_L39_00632678(u8 *, f32 *);
extern f32 func_0038CF38(void *, void *);
extern void func_L01_00448340(void *, void *, s32 *, f32, f32, f32);
extern void func_L01_004482A0(f32 *, s32 *, f32, f32, f32, f32);

void func_L39_00631100(u8 *self) {
    Buf_00631100 buf;

    if (self[0x1A06] != 0) {
        if (*(s16 *)(self + 0x2DE) == 0 && *(f32 *)(self + 0x2AC) < 0.0f) {
            f32 x = fabs_asm(*(f32 *)(self + 0x2AC));
            f32 y = fabs_asm(func_L39_00632678(self, (f32 *)(self + 0x120))) + 0.01f;
            if (x < y) {
                u8 *v = self + 0xA0;
                if (self[0x216] == 0 || func_0038CF38(self + 0x1D0, v) > *(f32 *)(self + 0x1F4) * 0.5f) {
                    *(u128_t *)v = *(u128_t *)(self + 0x260);
                    return;
                }
                func_L01_00448340(v, self + 0x260, (s32 *)(self + 0x2D4), 0.072000004f, 0.3024f, 0.10000001f);
            } else {
                func_L01_00448340(self + 0xA0, self + 0x260, (s32 *)(self + 0x2D4), 0.072000004f, 0.3024f, 0.10000001f);
            }
        } else {
            *(s32 *)(self + 0x2D4) = 0;
        }
        return;
    }
    if (*(s16 *)(self + 0x2DE) == 0 && *(f32 *)(self + 0xA8) < *(f32 *)(self + 0x2A8)) {
        f32 f4 = *(f32 *)(self + 0xA8);
        f32 f3 = *(f32 *)(self + 0x2A8);
        if (fabs_asm(f4 - f3) < fabs_asm(*(f32 *)(self + 0x128)) + 0.01f) {
            if (self[0x216] == 0 || func_0038CF38(self + 0x1D0, self + 0xA0) > *(f32 *)(self + 0x1F4) * 0.5f) {
                *(f32 *)(self + 0xA8) = *(f32 *)(self + 0x2A8);
            } else {
                func_L01_004482A0((f32 *)(self + 0xA8), (s32 *)(self + 0x2D4), *(f32 *)(self + 0x2A8), 0.072000004f, 0.24480002f, 0.10000001f);
            }
        } else {
            if (*(f32 *)(self + 0x158) < 0.0f) {
                *(f32 *)(self + 0xA8) = f4 - *(f32 *)(self + 0x158);
                if (f3 < *(f32 *)(self + 0xA8)) {
                    *(f32 *)(self + 0xA8) = f3;
                }
            }
            func_L01_004482A0((f32 *)(self + 0xA8), (s32 *)(self + 0x2D4), *(f32 *)(self + 0x2A8), 0.072000004f, 0.24480002f, 0.10000001f);
        }
    } else {
        *(s32 *)(self + 0x2D4) = 0;
    }
    {
    u8 *q = self + 0x19E6;
    u32 dec;
    if (*q == 0) {
        dec = 0;
    } else {
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
            *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
        }
        a = buf.w[0] ^ (u32)q;
        b = buf.w[1] ^ a;
        buf.w[0] = a;
        buf.w[1] = b;
        dec = b;
    }
    if (dec != 0) {
        u8 *q2 = self + 0x19E4;
        u32 dec2;
        s32 eq;
        if (*q2 == 0) {
            dec2 = 0;
        } else {
            u32 a;
            u32 b;
            s32 n;
            s32 k;
            s32 m;
            s32 i;
            u8 *d;

            n = *q2;
            k = ((u32)q2 - n) & 7;
            m = n + 1;
            d = buf.b;
            for (i = 0; i < 40; i += 5) {
                *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
            }
            a = buf.w[0] ^ (u32)q2;
            b = buf.w[1] ^ a;
            buf.w[0] = a;
            buf.w[1] = b;
            dec2 = b;
        }
        eq = dec2 == 2;
        if (!eq) {
            goto zero;
        }
    }
    if (*(f32 *)(self + 0x1A4) == 0.0f) {
        f32 hi = *(f32 *)(self + 0x2E4);
        f32 cur = *(f32 *)(self + 0xA8);
        if (hi < cur) {
            *(f32 *)(self + 0x2E4) = cur;
        } else {
            f32 lo = *(f32 *)(self + 0x2E8);
            if (cur < lo) {
                *(f32 *)(self + 0x2E8) = cur;
            } else if (lo == 0.0f) {
                *(f32 *)(self + 0x2E8) = cur;
            } else if (hi - lo < 0.03f) {
                *(f32 *)(self + 0xA8) = hi;
                *(s32 *)(self + 0x2E0) = 1;
            } else {
                *(s32 *)(self + 0x2E0) = 0;
                *(f32 *)(self + 0x2E4) = 0.0f;
                *(f32 *)(self + 0x2E8) = 0.0f;
            }
        }
    } else {
    zero:
        *(s32 *)(self + 0x2E0) = 0;
        *(f32 *)(self + 0x2E4) = 0.0f;
        *(f32 *)(self + 0x2E8) = 0.0f;
    }
    }
}
/* localdecomp:end func_L39_00631100 */

INCLUDE_ASM("asm/levels", func_L39_006314E0);

INCLUDE_ASM("asm/levels", func_L39_006318E8);

/* localdecomp:start func_L39_006319D8 */
s32 func_L39_006319D8(char *a0, s32 a1) {
    char *p = a0 + a1 * 80;
    s32 x = (*(s32 *)(p + 1140) == 2) ? *(s32 *)(p + 1144) : -1;
    return x == 14 || x == 15;
}
/* localdecomp:end func_L39_006319D8 */

/* localdecomp:start func_L39_00631A08 */
s32 func_L39_00631A08(s32 a0, u8 *p, s32 v) {
    if (v == 255) {
        v = p[169];
    }
    return v;
}
/* localdecomp:end func_L39_00631A08 */

/* localdecomp:start func_L39_00631A20 */
s32 func_L39_00631A20(u8 *a0, s32 a1, f32 *a2) {
    *a2 = 0.0f;
    switch (a1) {
    case 28:
    case 29:
    case 31:
        if (*(f32 *)(a0 + 1576) > 25.0f) {
            *a2 = -1.4835298f;
        }
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L39_00631A20 */

/* localdecomp:start func_L39_00631A88 */

f32 func_L39_00631A88(S_0062F240 *a0, int a1)
{
    int n;
    if (a1 >= 32) {
        a1 = 31;
    }
    n = a0->count;
    if (n < a1) {
        a1 = n;
    }
    return a0->hist[(a0->head - a1 + 31) % 32];
}
/* localdecomp:end func_L39_00631A88 */

INCLUDE_ASM("asm/levels", func_L39_00631AD8);

INCLUDE_ASM("asm/levels", func_L39_00631CB0);

INCLUDE_ASM("asm/levels", func_L39_00631E90);

/* localdecomp:start func_L39_00632100 */

extern f32 func_0038CED8(Vec4 *);
extern void func_0038D028(Vec4 *, Vec4 *, u8 *);
extern f32 func_0038D160(f32, f32);

f32 func_L39_00632100(u8 *m, Vec4 *v) {
    Vec4 t;

    switch (m[6662]) {
    case 0:
        return func_0038D160(v->f[2], func_0038CED8(v));
    case 1:
    case 2:
        t.q = v->q;
        func_0038D028(&t, &t, m + 96);
        return func_0038D160(t.f[2], func_0038CED8(&t));
    }
    return 0.0f;
}
/* localdecomp:end func_L39_00632100 */

/* localdecomp:start func_L39_00632180 */
#include "vu0.h"
extern void func_0038D028(Vec4 *, Vec4 *, u8 *);

void func_L39_00632180(u8 *m, f32 *out, s32 add, f32 x, f32 y, f32 z) {
    qzero(out);
    out[0] = x;
    out[1] = y;
    out[2] = z;
    func_0038D028((Vec4 *)out, (Vec4 *)out, m + 0x20);
    if (add) {
        __asm__ __volatile__(
            "lqc2 $vf2, %1\n"
            "lqc2 $vf1, 0(%0)\n"
            "vadd.xyz $vf1, $vf1, $vf2\n"
            "sqc2 $vf1, 0(%0)\n"
            : : "r"(out), "m"(*(vu0_v4 *)(m + 0xA0)) : "memory");
    }
}
/* localdecomp:end func_L39_00632180 */

INCLUDE_ASM("asm/levels", func_L39_006321F0);

/* localdecomp:start func_L39_00632298 */
extern void func_0038D028(Vec4 *, Vec4 *, u8 *);

extern void func_0038CFB8(f32 *, f32 *, f32);

void func_L39_00632298(Obj62FA50 *o, f32 *dst, f32 *src, f32 scale) {
    switch (o->mode) {
    case 0:
        func_0038CFB8(dst, src, scale);
        break;
    case 1:
    case 2:
        ((void (*)(f32 *, f32 *, void *))func_0038D028)(dst, src, o->m1);
        func_0038CFB8(dst, dst, scale);
        ((void (*)(f32 *, f32 *, void *))func_0038D028)(dst, dst, o->m0);
        break;
    }
}
/* localdecomp:end func_L39_00632298 */

/* localdecomp:start func_L39_00632328 */
extern void func_0038D028(Vec4 *, Vec4 *, u8 *);
void func_L39_00632328(u8 *a, Vec4 *dst, Vec4 *src, f32 s) {
    switch (a[0x1A06]) {
    case 0:
        *dst = *src;
        dst->f[2] *= s;
        break;
    case 1:
    case 2:
        func_0038D028(dst, src, a + 0x60);
        dst->f[2] *= s;
        func_0038D028(dst, dst, a + 0x20);
        break;
    }
}
/* localdecomp:end func_L39_00632328 */

/* localdecomp:start func_L39_006323B8 */
extern void func_0038D028(Vec4 *, Vec4 *, u8 *);
void func_L39_006323B8(u8 *p, float *v, void *m, float s) {
    switch (p[6662]) {
    case 0:
        v[0] *= s;
        v[1] *= s;
        break;
    case 1:
    case 2:
        ((void (*)(float *, void *, void *))func_0038D028)(v, m, p + 96);
        v[0] *= s;
        v[1] *= s;
        ((void (*)(float *, void *, void *))func_0038D028)(v, v, p + 32);
        break;
    }
}
/* localdecomp:end func_L39_006323B8 */

INCLUDE_ASM("asm/levels", func_L39_00632458);

/* localdecomp:start func_L39_00632558 */
extern void func_0038D028(Vec4 *, Vec4 *, u8 *);



void func_L39_00632558(S_62FD10 *s, Vec4 *out, Vec4 *in, f32 z) {
    s32 m = s->mode;

    if (m == 0) {
        out->q = in->q;
        out->f[2] = z;
        return;
    }
    if (m < 0) {
        return;
    }
    if (m < 3) {
        ((void (*)(Vec4 *, Vec4 *, void *))func_0038D028)(out, in, s->m60);
        out->f[2] = z;
        ((void (*)(Vec4 *, Vec4 *, void *))func_0038D028)(out, out, s->m20);
    }
}
/* localdecomp:end func_L39_00632558 */

/* localdecomp:start func_L39_006325D8 */
extern void func_0038D028(Vec4 *, Vec4 *, u8 *);
extern f32 func_0038CED8(Vec4 *);
extern void func_0038D328(float *, void *);
extern void func_0038D5B0(float *, float *);
float func_L39_006325D8(u8 *p, float *v) {
    float m[16];
    float inv[16];
    float t[4];
    switch (p[6662]) {
    case 0:
        return ((float (*)(float *))func_0038CED8)(v);
    case 1:
    case 2:
        func_0038D328(m, (void *)(*(s32 *)(p + 9508) + 240));
        func_0038D5B0(inv, m);
        ((void (*)(float *, void *, void *))func_0038D028)(t, v, inv);
        return ((float (*)(float *))func_0038CED8)(t);
    }
    return 0.0f;
}
/* localdecomp:end func_L39_006325D8 */

/* localdecomp:start func_L39_00632678 */
extern void func_0038D000(f32 *, f32 *, u8 *);
f32 func_L39_00632678(u8 *a, f32 *b) {
    f32 tmp[4];
    switch (a[6662]) {
    case 0:
        return b[2];
    case 1:
    case 2:
        func_0038D000(tmp, b, a + 96);
        return tmp[2];
    }
    return 0.0f;
}
/* localdecomp:end func_L39_00632678 */

/* localdecomp:start func_L39_006326C8 */
#include "vu0.h"
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D160(f32, f32);

f32 func_L39_006326C8(u8 *p) {
    f32 m[16];
    Vec4 v;
    Vec4 a;
    Vec4 b;
    Vec4 c;
    v.f[0] = func_0038D098(0.0f);
    v.f[1] = func_0038D0B0(0.0f);
    v.f[2] = 0.0f;
    func_0038D328(m, p + 0xB0);
    func_0038D028(&v, &v, (u8 *)m);
    if (*(f32 *)(p + 0x230) != 0.0f || *(f32 *)(p + 0x234) != 0.0f) {
        qzero(&a);
        c.q = *(u128_t *)(p + 0x230);
        qzero(&b);
        a.f[2] = -func_0038D160(*(f32 *)(p + 0x230), *(f32 *)(p + 0x234));
        func_0038D328(m, &a);
        func_0038D028(&v, &v, (u8 *)m);
        func_0038D028(&c, &c, (u8 *)m);
        b.f[1] = -func_0038D160(c.f[2], c.f[0]);
        func_0038D328(m, &b);
        func_0038D028(&v, &v, (u8 *)m);
        a.f[2] = -a.f[2];
        func_0038D328(m, &a);
        func_0038D028(&v, &v, (u8 *)m);
    }
    return func_0038D160(v.f[0], v.f[1]);
}
/* localdecomp:end func_L39_006326C8 */

/* localdecomp:start func_L39_00632818 */
#include "vu0.h"
extern void func_L39_00632888(void *, void *, void *, f32);
extern f32 func_0038CE68(void *, void *);

f32 func_L39_00632818(void *a0, u128_t *a1) {
    u128_t t[2];

    t[0] = *a1;
    qzero(&t[1]);
    func_L39_00632888(a0, &t[1], &t[1], 1.0f);
    return func_0038CE68(&t[0], &t[1]);
}
/* localdecomp:end func_L39_00632818 */
