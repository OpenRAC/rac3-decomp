#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;
typedef struct { u8 pad[288]; u8 sub[4020 - 288]; f32 f; } S630;

typedef struct { u8 pad0[0xFB0]; f32 f0FB0; u8 pad1[0x2468 - 0xFB4]; f32 f2468; } S_00633160;

typedef struct {
    u8 pad0[0x474];
    s32 mode;
    s32 kind;
    u8 pad1[0x142F - 0x47C];
    u8 alternate;
    u8 pad2[0x1A07 - 0x1430];
    u8 special;
    u8 pad3[0x2468 - 0x1A08];
    f32 speed;
} View_00633428;

/* declared by functions of L39_00632888.c, which this file was cut from */
extern void func_0038D328(Vec4 *, Vec4 *);
extern void func_0038D028(Vec4 *out, void *a, void *b);

/* localdecomp:start func_L39_00632C48 */
s32 func_L39_00632C48(void *arg0, f32 fparg0) {
    f32 temp_f1;
    s32 var_v0;

    temp_f1 = *(f32 *)((u8 *)arg0 + 0x628);
    var_v0 = 0;
    if (fparg0 < temp_f1) {
        var_v0 = 1;
        if (!((temp_f1 - fparg0) <= (*(f32 *)((u8 *)arg0 + 0x62C)))) {
            var_v0 = 0;
        }
    }
    return var_v0;
}
/* localdecomp:end func_L39_00632C48 */

/* localdecomp:start func_L39_00632C80 */
extern float func_003C4138(float *, float, float);
void func_L39_00632C80(float *a0, float *a1, float *a2, float f12)
{
    float v[2];
    v[0] = -a0[0x110 / 4];
    v[1] = -a0[0x114 / 4];
    func_003C4138(a2 + 2, v[0], f12);
    if (a2[2] > 1.0f)
        a2[2] = 1.0f;
    if (a2[2] < -1.0f)
        a2[2] = -1.0f;
    a1[0] = a2[2];
    func_003C4138(a2 + 1, v[1], f12);
    if (a2[1] > 1.0f)
        a2[1] = 1.0f;
    if (a2[1] < -1.0f)
        a2[1] = -1.0f;
    a1[1] = a2[1];
}
/* localdecomp:end func_L39_00632C80 */

/* localdecomp:start func_L39_00632D78 */
#include "vu0.h"

typedef struct {
    f32 x, y, z, w;
} V_00632D78 __attribute__((aligned(16)));

typedef union {
    V_00632D78 v;
    u8 b[8];
    u32 w[2];
} Buf_00632D78;

typedef struct {
    u8 pad0[0xB8];
    f32 fB8;
    u8 padBC[0x110 - 0xBC];
    f32 f110;
    f32 f114;
    u8 pad118[0x3E4 - 0x118];
    s16 h3E4;
    u8 b3E6;
    u8 b3E7;
    u8 pad3E8[0xFB0 - 0x3E8];
    f32 fFB0;
    u8 padFB4[0xFC0 - 0xFB4];
    u8 vFC0[0x10];
    f32 fFD0;
    u8 padFD4[0x1310 - 0xFD4];
    s32 s1310;
    u8 pad1314[0x19E4 - 0x1314];
    u8 b19E4;
    u8 pad19E5[0x1A06 - 0x19E5];
    u8 b1A06;
    u8 pad1A07[0x23B8 - 0x1A07];
    f32 f23B8;
    u8 pad23BC[0x23C0 - 0x23BC];
    u8 m23C0[0x2468 - 0x23C0];
    f32 f2468;
    u8 pad246C[0x2524 - 0x246C];
    u8 *p2524;
    u8 pad2528[0x2534 - 0x2528];
    void *p2534;
} S_00632D78;

extern u8 D_L39_004997E0[];
extern f32 func_0038CED8(void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_0038D000(void *, void *, void *);
extern void func_0038CF68(void *, f32);
extern void func_L01_0040E408(void *, void *, f32);
extern s32 func_L01_004606E8(s32, s32, void *, void *);
extern s32 func_L39_006212E8(void *);
extern f32 func_L39_006326C8(void *);
extern void func_L39_00632558(void *, void *, void *, f32);

void func_L39_00632D78(void *arg0, s32 mode, f32 scale) {
    S_00632D78 *s = arg0;
    V_00632D78 v;
    Buf_00632D78 buf;
    f32 len;
    f32 x;
    f32 y;
    f32 zero;

    v.x = s->f110;
    v.y = -s->f114;
    if (mode == 1) {
        if (fabs_asm(v.y) > 0.7f && fabs_asm(v.x) < 0.12f) {
            v.x = 0.0f;
        }
        if (fabs_asm(v.x) > 0.7f && fabs_asm(v.y) < 0.12f) {
            v.y = 0.0f;
        }
    }
    len = func_0038CED8(&v);
    if (len > 1.0f) {
        func_L01_0040E408(&v, &v, len);
    }
    if (v.x == 0.0f && v.y == 0.0f) {
        s->fFB0 = 0.0f;
        if (s->b1A06) {
            s->fFD0 = func_L39_006326C8(s);
        } else {
            s->fFD0 = s->fB8;
        }
        *(u128_t *)&buf.v = 0;
        buf.v.x = 1.0f;
        func_0038D000(s->vFC0, &buf, s->p2524 + 0xC0);
        return;
    }
    s->fFD0 = func_0038D160(-v.y, -v.x);
    if (s->h3E4 != 0 ||
        (s->s1310 == 1 && func_L01_004606E8(0x28, 2, 0, s->p2534) != 0 &&
         func_L39_006212E8(s) != 10)) {
        u8 *q = &s->b19E4;
        u32 dec;
        s32 eq;
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
        eq = dec == 0x10;
        if (!eq) {
            s32 side = 2;
            f32 ang = func_0038D160(v.x, v.y);
            if (func_0038DBA0(ang, 1.5707964f) < 0.78539819f) {
                side = 3;
            } else if (func_0038DBA0(ang, 0.0f) < 0.78539819f) {
                side = 1;
            } else if (func_0038DBA0(ang, 3.1415927f) < 0.78539819f) {
                side = 0;
            }
            s->b3E7 = side;
            if (side == 3 && 0.15f < s->f2468) {
                s->b3E6 = 1;
            } else {
                s->b3E6 = 0;
            }
        }
    }
    zero = 0.0f;
    s->fFD0 = func_0038DAB8(s->fFD0, s->f23B8);
    {
        f32 ox = v.x;
        f32 oy = v.y;
        v.y = -ox;
        v.x = -oy;
        v.w = zero;
        v.z = zero;
    }
    func_0038D000(s->vFC0, &v, s->m23C0);
    func_L39_00632558(s, s->vFC0, s->vFC0, zero);
    ((void (*)(void *, void *, f32))func_0038CF68)(s->vFC0, s->vFC0, 1.0f);
    s->fFB0 = scale * func_0038CED8(&v);
}
/* localdecomp:end func_L39_00632D78 */

/* localdecomp:start func_L39_00633160 */
extern void func_L39_00632D78(void *, s32, f32);


void func_L39_00633160(S_00633160 *p) {
    func_L39_00632D78(p, 0, 1.0f);
    if (0.0f < p->f0FB0) {
        p->f0FB0 = *(f32 *)0x246010 * 0.020000001f * p->f2468;
    }
}
/* localdecomp:end func_L39_00633160 */

/* localdecomp:start func_L39_006331D0 */

extern void func_0038D328(Vec4 *, Vec4 *);
extern void func_0038D640(Vec4 *, Vec4 *, Vec4 *);
extern void func_003C48A8(Vec4 *, Vec4 *);

void func_L39_006331D0(u8 *m, f32 x, f32 y, f32 z) {
    Vec4 v;
    Vec4 m1[4];
    Vec4 m2[4];

    v.f[0] = x;
    v.f[1] = y;
    v.f[2] = z;
    func_0038D328(m1, &v);
    func_0038D328(m2, (Vec4 *)(m + 176));
    func_0038D640(m2, m2, m1);
    func_003C48A8(m2, (Vec4 *)(m + 176));
}
/* localdecomp:end func_L39_006331D0 */

/* localdecomp:start func_L39_00633250 */
extern void func_L39_006331D0(u8 *m, f32 x, f32 y, f32 z);

extern void func_0038D028(Vec4 *out, void *a, void *b);
extern f32 func_0038D160(f32 x, f32 y);
extern f32 func_L01_00448728(f32 *out, void *a, void *b, f32 f0, f32 f1, f32 f2, f32 f3);

void func_L39_00633250(u8 *self, void *arg, f32 a, f32 b, f32 c) {
    Vec4 v;
    f32 out;
    f32 angle;
    f32 zero = 0.0f;
    func_0038D028(&v, self + 4032, self + 96);
    angle = func_0038D160(v.f[0], v.f[1]);
    out = zero;
    *(f32 *)(self + 4056) = func_L01_00448728(&out, self + 4052, arg, angle, a, b, c);
    ((void (*)(void *self, f32 a, f32 b, f32 c))func_L39_006331D0)(self, zero, zero, out);
}
/* localdecomp:end func_L39_00633250 */

/* localdecomp:start func_L39_00633308 */
extern void func_L39_00633250(u8 *self, void *arg, f32 a, f32 b, f32 c);

void func_L39_00633308(View_00633428 *v, s32 arg, f32 a, f32 b, f32 c) {
    u8 *s = (u8 *)v;

    if (*(s32 *)(s + 0x1310) != 0) {
        if (v->special != 0 || func_L01_004606E8(0x28, 2, 0, *(void **)(s + 0x2534)) != 0) {
            if (func_L39_006212E8(v) != 10) {
                if (a < 0.2880000174f) {
                    a = 0.2880000174f;
                }
                if (c < 1.0471977f) {
                    c = 1.0471977f;
                }
            }
        }
    }
    if (s[0x1A06] != 0) {
        ((void (*)(u8 *, f32, f32, f32, void *))func_L39_00633250)(s, a, b, c, (void *)arg);
    } else {
        *(f32 *)(s + 0xFD8) = ((f32 (*)(f32 *, f32, void *, f32, f32, f32, void *))func_L01_00448728)((f32 *)(s + 0xB8), *(f32 *)(s + 0xFD0), s + 0xFD4, a, b, c, (void *)arg);
    }
}
/* localdecomp:end func_L39_00633308 */

/* localdecomp:start func_L39_00633428 */
extern void func_L39_00633308(View_00633428 *, s32, f32, f32, f32);

void func_L39_00633428(View_00633428 *v)
{
    f32 speed = v->speed;
    f32 first;
    f32 second;
    f32 third;
    s32 kind;
    if (speed == 1.0f) {
        first = 0.0316800028f;
    } else {
        first = speed * 0.0288000014f;
        if (first > 0.0316800028f)
            first = 0.0316800028f;
        if (first < 0.0144000007f)
            first = 0.0144000007f;
    }
    if (v->speed == 1.0f) {
        third = 0.1117010787f;
    } else {
        third = speed * 0.0767944902f;
        if (third > 0.1117010787f)
            third = 0.1117010787f;
        if (third < 0.0383972451f)
            third = 0.0383972451f;
    }
    second = 0.3888000250f;
    if (v->alternate) {
        first = 0.0504000038f;
        third = 0.2338741273f;
    }
    kind = -1;
    if (v->mode == 2)
        kind = v->kind;
    if (kind == 1 || kind == 9) {
        if (v->special && !v->alternate) {
            if (speed > 0.95f) {
                first = 0.0244800020f;
                second = 0.2592000067f;
                third = 0.174532935f;
            } else {
                first = speed * 0.0129600000f;
                second = 0.2160000205f;
                third = speed * 0.0942477882f;
            }
        }
    }
    func_L39_00633308(v, 0, first, second, third);
}
/* localdecomp:end func_L39_00633428 */

/* localdecomp:start func_L39_00633620 */
extern f32 func_003C4138(f32 *, f32, f32);
void func_L39_00633620(u8 *a, f32 x, f32 y) {
    f32 t = *(f32 *)(a + 4016);
    if (*(f32 *)(a + 4020) < t) {
        func_003C4138((f32 *)(a + 4020), t, x);
    } else {
        func_003C4138((f32 *)(a + 4020), t, y);
    }
}
/* localdecomp:end func_L39_00633620 */

/* localdecomp:start func_L39_00633670 */
extern void func_0038D028(Vec4 *out, void *a, void *b);

extern f32 func_0038D098(f32 x);
extern f32 func_0038D0B0(f32 x);
extern void func_00382760(Vec4 *out, f32 a, f32 b, f32 c);

void func_L39_00633670(u8 *self, f32 angle) {
    Vec4 v;
    Vec4 t;
    f32 r;
    f32 sel;
    f32 zero;
    sel = *(f32 *)(self + 184);
    if (angle <= 3.1415927f) {
        sel = angle;
    }
    r = *(f32 *)(self + 4020);
    if (*(u8 *)(self + 6662) != 0) {
        zero = 0.0f;
        t.f[0] = func_0038D098(zero) * r;
        t.f[1] = func_0038D0B0(zero) * r;
        t.f[2] = zero;
        ((void (*)(Vec4 *out, Vec4 *a, void *b))func_0038D028)(&t, &t, self + 32);
        v = t;
    } else {
        func_00382760(&v, r, sel, *(f32 *)(self + 692));
    }
    *(u128_t *)(self + 288) = v.q;
}
/* localdecomp:end func_L39_00633670 */

/* localdecomp:start func_L39_00633728 */
extern void func_0038CF68(void *, f32);
void func_L39_00633728(S630 *p) {
    func_0038CF68(p->sub, p->f);
}
/* localdecomp:end func_L39_00633728 */

INCLUDE_ASM("asm/levels", func_L39_00633748);
