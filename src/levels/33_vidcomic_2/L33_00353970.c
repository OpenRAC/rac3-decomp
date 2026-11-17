#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L33_00353970 */
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DB48(f32);
extern void func_003C2F58(void *, s32, void *);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D890(void *, void *, void *, f32);
extern s32 func_L30_0034DBA0(s32, s32);
extern s32 func_L30_0034D8D8(void *, f32);
extern s32 func_L01_003FB640(void *, s32, u8 *, f32);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038D160(f32, f32);
extern void func_L33_00344F88(void *, s32);
extern void func_L33_003453C8(void *, void *);
extern f32 func_L30_0034CE78(u8 *);
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
extern u8 D_L33_001E2720[];
extern u8 D_L33_001E9600[];
extern s32 D_L33_001DF6C0;
extern u8 *D_L33_0021F76C __attribute__((section(".data")));
extern f32 D_L33_001DDAE0[2];
__asm__(".extern D_L33_001DDAE0, 8");
extern f32 D_L33_001DD964;
__asm__(".extern D_L33_001DD964, 4");
extern f32 D_L33_001DDC14;
__asm__(".extern D_L33_001DDC14, 4");
extern f32 D_L33_001DDC18;
__asm__(".extern D_L33_001DDC18, 4");
extern s32 D_L33_001DDC1C;
__asm__(".extern D_L33_001DDC1C, 4");
extern s32 D_L33_001DDC20;
__asm__(".extern D_L33_001DDC20, 4");
extern f32 D_L33_001DDC28;
__asm__(".extern D_L33_001DDC28, 4");
extern f32 D_L33_001DDC2C;
__asm__(".extern D_L33_001DDC2C, 4");
extern f32 D_L33_001DDC38;
__asm__(".extern D_L33_001DDC38, 4");
extern s32 D_L33_001DDC44;
__asm__(".extern D_L33_001DDC44, 4");
extern f32 D_L33_001DDC50;
__asm__(".extern D_L33_001DDC50, 4");
extern s32 D_L33_001DDC54;
__asm__(".extern D_L33_001DDC54, 4");
extern f32 D_L33_001DDC58;
__asm__(".extern D_L33_001DDC58, 4");
extern f32 D_L33_001DDC5C;
__asm__(".extern D_L33_001DDC5C, 4");
extern f32 D_L33_001DDC60;
__asm__(".extern D_L33_001DDC60, 4");

void func_L33_00353970(u8 *p, u8 *q) {
    vu0_v4 v;
    vu0_v4 a;
    vu0_v4 b;
    u8 *m;
    u8 *pv;
    u8 *r;
    s32 n;
    s32 on;

    if (q == 0) return;
    m = *(u8 **)(q + 0);
    pv = *(u8 **)(m + 0x68);
    on = *(s32 *)(q + 4);
    if (m == 0) return;
    if (on == 0) return;

    if (*(u16 *)(q + 0xA) & 1) {
        f32 ang;
        f32 s;
        u8 t;

        ang = func_0038DB48(func_003824E0(0.0f, 6.2831855f));
        s = D_L33_001DDC14 * *(f32 *)(m + 0xC) * func_003824E0(0.0f, 1.0f) * 0.0009765625f;
        func_003C2F58(m, 2, p + 0x10);
        v.x = func_0038D098(ang) * s;
        v.z = func_0038D0B0(ang) * s;
        v.y = 0.0f;
        vec_add_ab(p + 0x10, p + 0x10, &v);
        t = m[0x20];
        if (t == 2 || t == 4) {
            qzero(&a);
            a.x = *(f32 *)(pv + 0x60) * D_L33_001DDC18;
            a.z = *(f32 *)(pv + 0x68) * D_L33_001DDC18;
            func_0038CE20(&a, &a, func_003824E0(1.0f - D_L33_001DDC60, D_L33_001DDC60 + 1.0f));
            func_0038D890(&a, &a, D_L33_001E2720, func_003824E0(-D_L33_001DDC5C, D_L33_001DDC5C));
            *(f32 *)(q + 0x10) = a.x;
            *(f32 *)(q + 0x14) = a.z;
        } else if (t == 0x42) {
            f32 k;
            func_0038CF68(&b, &v, D_L33_001DDAE0[0x1761 - *(s16 *)(m + 0xAA)]
                * func_003824E0(1.0f - D_L33_001DDC60, D_L33_001DDC60 + 1.0f));
            k = D_L33_001DD964;
            *(f32 *)(q + 0x10) = b.x + k * *(f32 *)(pv + 0x60);
            *(f32 *)(q + 0x14) = b.z + k * *(f32 *)(pv + 0x68);
        }
        if (*(s32 *)(pv + 0xA8) != 0) {
            *(s32 *)(p + 4) = 0x80000000;
        } else {
            *(s32 *)(p + 4) = func_L30_0034DBA0(D_L33_001DDC1C, D_L33_001DDC20);
        }
        *(f32 *)(p + 0xC) = func_003824E0(D_L33_001DDC2C, D_L33_001DDC28);
        *(s16 *)(q + 0xC) = 0;
    }

    if ((D_L33_001DF6C0 & D_L33_001DDC54) == (((s32)p >> 8) & D_L33_001DDC54)) {
        if (func_L30_0034D8D8(p + 0x10, 1.1f) == 0) {
            *(s16 *)(p + 0xA) = 0;
        }
        v = *(vu0_v4 *)(p + 0x10);
        v.x += *(f32 *)(q + 0x10);
        v.z += *(f32 *)(q + 0x14);
        if (*(s16 *)(q + 0xC) == 0 && func_L01_003FB640(p + 0x10, 0, m, D_L33_001DDC58) != 0) {
            qzero(&b);
            b.x = *(f32 *)(q + 0x10);
            b.z = *(f32 *)(q + 0x14);
            vec_sub_ab(&a, D_L33_001E9600 + 0x20, p + 0x10);
            if (0.0f < func_0038CE68(&a, &b)) {
                u8 *o;
                *(s16 *)(q + 0xC) = 1;
                p[8] = q[0xE];
                p[2] = D_L33_0021F76C[D_L33_001DDC44];
                o = *(u8 **)(D_L33_001E9600 + 0x18);
                *(u8 **)(q + 0x1C) = o;
                if (o != 0) {
                    *(f32 *)(q + 0x10) = *(f32 *)(o + 0x10);
                    *(f32 *)(q + 0x14) = *(f32 *)(o + 0x18);
                }
            }
        }
    }

    if (*(s16 *)(q + 0xC) == 0) {
        *(f32 *)(q + 0x14) += D_L33_001DDC50;
        *(f32 *)(p + 0x10) += *(f32 *)(q + 0x10);
        *(f32 *)(p + 0x18) += *(f32 *)(q + 0x14);
        {
            f32 ang = func_0038D160(*(f32 *)(q + 0x10), *(f32 *)(q + 0x14));
            *(u16 *)(p + 0xA) += 1;
            p[8] = (1.0f - ang / 6.2831855f) * 256.0f;
        }
        return;
    }

    r = *(u8 **)(q + 0x1C);
    if ((*(s32 *)(p + 4) & 0xFFFFFF) == 0) {
        *(s16 *)(p + 0xA) = 0;
    }
    n = *(s16 *)(p + 0xA);
    *(f32 *)(p + 0xC) *= (f32)n / (f32)(n + 1);
    func_L33_00344F88(&v, *(s32 *)(p + 4));
    n = *(s16 *)(p + 0xA);
    func_0038CE20(&v, &v, (f32)n / (f32)(n + 1));
    func_L33_003453C8(p + 4, &v);
    if (r == 0) return;
    *(f32 *)(p + 0x10) += *(f32 *)(r + 0x10) - *(f32 *)(q + 0x10);
    *(f32 *)(q + 0x10) = *(f32 *)(r + 0x10);
    *(f32 *)(p + 0x18) += *(f32 *)(r + 0x18) - *(f32 *)(q + 0x14);
    *(f32 *)(q + 0x14) = *(f32 *)(r + 0x18);
    if (r[0x20] >= 0xFD) {
        *(s16 *)(p + 0xA) = 0;
    }
    a = *(vu0_v4 *)(r + 0x10);
    a.z += func_L30_0034CE78(r);
    vec_sub_ba(&b, &a, p + 0x10);
    if (func_0038CEA8(&b) < D_L33_001DDC38) {
        *(vu0_v4 *)(p + 0x10) = a;
        return;
    }
    func_0038CF68(&b, &b, D_L33_001DDC38);
    vec_add_ab(p + 0x10, p + 0x10, &b);
}
/* localdecomp:end func_L33_00353970 */

/* localdecomp:start func_L33_00353EF0 */
extern f32 func_0038CF00(void *, void *);
extern s32 func_0038DBD8(s32, s32, f32);
extern f32 func_003C4088(f32, f32, f32);

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_00353EF0;

typedef struct {
    u8 pad0[3];
    u8 f3;
    s32 f4;
    u8 pad8[2];
    s16 fA;
    s32 fC;
    V_00353EF0 a;
    V_00353EF0 b;
} B_00353EF0;

typedef struct {
    u8 *moby;
    u8 pad4[4];
    u8 f8;
    u8 flags;
    u8 padA[2];
    f32 fC;
} C_00353EF0;

extern u8 D_L33_001E18B8[] __attribute__((section(".sdata")));
extern f32 D_L33_001DDC98[] __attribute__((section(".sdata")));
__asm__(".extern D_L33_001DDC98, 8");
extern s32 D_L33_001DDC64;
__asm__(".extern D_L33_001DDC64, 4");
extern s32 D_L33_001DDC68;
__asm__(".extern D_L33_001DDC68, 4");
extern f32 D_L33_001DDC6C;
__asm__(".extern D_L33_001DDC6C, 4");
extern f32 D_L33_001DDC70;
__asm__(".extern D_L33_001DDC70, 4");
extern f32 D_L33_001DDC78;
__asm__(".extern D_L33_001DDC78, 4");
extern f32 D_L33_001DDC84;
__asm__(".extern D_L33_001DDC84, 4");
extern f32 D_L33_001DDC88;
__asm__(".extern D_L33_001DDC88, 4");
extern f32 D_L33_001DDCA8;
__asm__(".extern D_L33_001DDCA8, 4");
extern f32 D_L33_001DDCAC;
__asm__(".extern D_L33_001DDCAC, 4");
extern u8 D_L33_001DDCB0;
__asm__(".extern D_L33_001DDCB0, 1");

void func_L33_00353EF0(B_00353EF0 *b, C_00353EF0 *c) {
    u8 *m;
    u8 *t;
    s32 col;
    u8 st;

    if (c == 0) {
        return;
    }
    m = c->moby;
    t = D_L33_001E18B8;
    if (m == 0) {
        return;
    }
    if (*(s16 *)(m + 0xAA) < 0x175F) {
        return;
    }
    if (*(s16 *)(m + 0xAA) >= 0x1762) {
        return;
    }
    if (t == 0) {
        return;
    }
    if (c->flags & 1) {
        f32 x;
        f32 h;
        f32 d;
        f32 w;
        s32 n;

        b->a = *(V_00353EF0 *)(m + 0x10);
        h = *(f32 *)(m + 0xC);
        x = b->a.x;
        if (func_L33_003534E0(m)) {
            d = x + h * 0.00024414062f;
        } else {
            d = x + -h * 0.00024414062f;
        }
        b->a.x = d;
        *(vu0_q *)&b->b = *(vu0_q *)&b->a;
        c->fC = *(f32 *)(m + 0x10);
        w = D_L33_001DDC98[0x1761 - *(s16 *)(m + 0xAA)];
        b->a.w = w;
        n = w / D_L33_001DDCA8;
        b->a.z += w * 0.5f;
        b->b.z += w * 0.5f;
        c->f8 = D_L33_001DDCB0 + n / 4;
        b->fA = c->f8 * 4;
        b->f3 = t[0x10];
    }
    col = func_0038DBD8(D_L33_001DDC64, D_L33_001DDC68, 1.0f - (b->fA * 0.25f) / c->f8);
    b->fC = col;
    b->f4 = col;
    b->a.y += D_L33_001DDC84;
    b->b.y += D_L33_001DDC84;
    if (!(c->flags & 2)) {
        f32 dist;

        f32 x = *(f32 *)(m + 0x10);
        if (c->fC < x) {
            b->b.x += x - c->fC;
        } else {
            b->a.x += x - c->fC;
        }
        c->fC = *(f32 *)(m + 0x10);
        dist = func_0038CF00(&b->a, &b->b);
        if (D_L33_001DDC78 * b->a.w < dist) {
            c->fC = 0.0f;
            c->flags |= 2;
        } else {
            st = m[0x20];
            if (st != 1 && st != 5 && st != 6 && st != 12 && st != 13 && st != 14) {
                c->fC = 0.0f;
                c->flags |= 2;
            }
        }
        b->b.w = D_L33_001DDC6C;
    } else {
        f32 a;

        f32 r;
        a = c->fC + D_L33_001DDC88;
        if (1.0f < a) {
            r = 1.0f;
        } else {
            r = a;
        }
        c->fC = r;
        b->b.w = func_003C4088(D_L33_001DDC6C, D_L33_001DDC70, r);
    }
    {
        f32 w;
        f32 t2;
        f32 nw;

        if (b->a.w > D_L33_001DDCAC || b->fA * D_L33_001DDCA8 <= b->a.w) {
            t2 = b->a.w - D_L33_001DDCA8;
            if (t2 < 0.0f) {
                nw = 0.0f;
            } else {
                nw = t2;
            }
            w = (b->a.w - nw) * 0.5f;
            b->a.w = nw;
            b->a.z -= w;
            b->b.z -= w;
        }
    }
}
/* localdecomp:end func_L33_00353EF0 */
