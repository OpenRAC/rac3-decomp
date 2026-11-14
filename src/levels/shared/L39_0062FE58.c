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
