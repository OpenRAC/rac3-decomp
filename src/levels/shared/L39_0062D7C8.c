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

/* localdecomp:start func_L39_006302E0 */
typedef struct {
    u8 pad0[0x20];
    f32 m20[16];
    f32 m60[16];
    Vec4 vA0;
    u8 padB0[0x230 - 0xB0];
    Vec4 v230;
    u8 pad240[0x10];
    Vec4 v250;
    u8 pad260[0x2AC - 0x260];
    f32 f2AC;
    u8 pad2B0[0x2DE - 0x2B0];
    s16 h2DE;
    u8 pad2E0[0x33E - 0x2E0];
    s16 h33E;
    u8 pad340[0x1290 - 0x340];
    f32 m1290[16];
    u8 pad12D0[0x1310 - 0x12D0];
    s32 s1310;
    u8 pad1314[0x1A06 - 0x1314];
    u8 mode;
} S_006302E0;

extern void func_0038D028(Vec4 *, Vec4 *, u8 *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D000(f32 *, f32 *, u8 *);
extern void func_L39_006339B0(void *, Vec4 *, f32 *, s32, f32, f32, f32);

void func_L39_006302E0(u8 *s) {
    S_006302E0 *p = (S_006302E0 *)s;
    f32 m[16];
    Vec4 pos;
    Vec4 fwd;
    Vec4 off;
    Vec4 tmp;
    f32 a;
    f32 b;

    pos.q = 0;
    pos.f[2] = 1.0f;
    fwd.q = 0;
    fwd.f[2] = 0.8f;
    off.q = 0;
    off.f[2] = 0.8f;
    func_0038D028(&fwd, &fwd, (u8 *)p->m20);
    a = 0.0504000038f;
    pos.q = p->v230.q;
    b = 0.432000041f;
    if (p->mode == 2) {
        func_0038CE20(&pos, &p->v250, -1.0f);
    }
    if (p->mode == 1 && (p->h2DE < 8 || p->f2AC < 1.0f)) {
        pos.q = p->v230.q;
    }
    if (p->h2DE != 0 && p->h33E != 0) {
        b = 0.00144000014f;
        a = b;
    }
    if (p->s1310 != 0) {
        func_0038D000(p->m1290, p->m1290, (u8 *)p->m60);
    }
    func_L39_006339B0(p, &pos, m, 0, a, b, 0.0f);
    if (p->s1310 != 0) {
        func_0038D000(p->m1290, p->m1290, (u8 *)m);
    }
    if (p->mode == 1 && p->h2DE != 0) {
        func_0038D028(&off, &off, (u8 *)m);
        __asm__ __volatile__(
            "lqc2 $vf1, %2\n"
            "lqc2 $vf2, %0\n"
            "vsub.xyz $vf2, $vf2, $vf1\n"
            "lqc2 $vf1, %3\n"
            "sqc2 $vf1, %1\n"
            "sqc2 $vf2, %0\n"
            "lqc2 $vf1, %0\n"
            "lqc2 $vf2, %1\n"
            "vadd.xyz $vf1, $vf1, $vf2\n"
            "sqc2 $vf1, %0\n"
            : "+m"(p->vA0), "=m"(tmp) : "m"(off), "m"(fwd) : "memory");
    }
}
/* localdecomp:end func_L39_006302E0 */

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
