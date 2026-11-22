#include "common.h"
#include "vu0.h"

typedef struct {
    f32 v[4];
} V4_003F5ED8;
typedef int u128_3F6DA0 __attribute__((mode(TI)));
typedef struct {
    f32 x, y, z, w;
} V_003F6ED8;

typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L01_003F7CE0 */
extern s32 func_L01_00439A98(u8 *self, void *a, void *buf, s32 b);
extern void func_L01_004398C8(void *, s32, void *);
extern void func_003C5060(void *, void *, void *, s32);
extern void func_0038CE20(V_003F6ED8 *, V_003F6ED8 *, f32);

void func_L01_003F7CE0(u8 *m, s32 mode, s32 index, vu0_q *a, vu0_q *b, s32 byte, s32 half, f32 f) {
    u8 *d = *(u8 **)(m + 0x68);
    vu0_v4 tmp;
    f *= 0.00040000002f;
    *(s32 *)(m + 0x98) = 0;
    *(u16 *)(m + 0x34) |= 0x100;
    *(vu0_q *)d = *a;
    *(vu0_q *)(d + 0x10) = *b;
    *(f32 *)(d + 0x38) = 0.45f;
    *(f32 *)(d + 0x3C) = 0.040000003f;
    *(f32 *)(d + 0x40) = 0.5f;
    *(f32 *)(d + 0x44) = 0.015707964f;
    *(f32 *)(d + 0x48) = f;
    *(f32 *)(d + 0x4C) = 0.0025132743f;
    *(s16 *)(d + 0x34) = half;
    d[0x5E] = byte;
    d[0x5D] = mode;
    d[0x58] = 0;
    d[0x5C] = 0;
    *(s32 *)(d + 0x30) = 0;
    switch (mode) {
    case 2:
        *(s16 *)(d + 0x36) = index;
        *(u16 *)(m + 0x7C) = (1 << index) | 0x8000;
        d[0x58] = func_L01_00439A98(m, d + 0x20, *(void **)(d + 0x30), index);
        vec_sub_ab(d + 0x20, d + 0x20, m + 0x10);
        func_003C5060(m, d + 0x20, d + 0x20, 0);
        break;
    case 0:
    case 3:
        func_0038CE20((V_003F6ED8 *)(d + 0x20), (V_003F6ED8 *)m, 0.0009765625f);
        *(f32 *)(d + 0x2C) = *(f32 *)(m + 0xC) * 0.0009765625f;
        vec_sub_ab(d + 0x20, d + 0x20, m + 0x10);
        func_003C5060(m, d + 0x20, d + 0x20, 0);
        break;
    case 1:
        *(s16 *)(d + 0x36) = index;
        *(u16 *)(m + 0x7C) = (1 << index) | 0x8000;
        func_L01_004398C8(m, index, &tmp);
        vec_sub_ab(d + 0x20, &tmp, m + 0x10);
        func_003C5060(m, d + 0x20, d + 0x20, 0);
        break;
    }
}
/* localdecomp:end func_L01_003F7CE0 */

/* localdecomp:start func_L01_003F7EE8 */
extern void func_L01_00450F00(u8 *self, void *out);
extern s32 func_L01_003F9080(u8 *m, V_003F6ED8 *out, s32 max);
extern s32 func_L01_00439A98(u8 *self, void *a, void *buf, s32 b);
extern s32 func_L01_003F8080(u8 *self);
extern s32 func_L01_003F8470_003F7EE8();
extern s32 func_L01_003F8478_003F7EE8();
extern s32 func_L01_003F8208(u8 *self);
extern s32 func_0038CB00(void *a);

s32 func_L01_003F7EE8(u8 *self) {
    f32 pos[4];
    u8 buf[0x200];
    f32 tmp[4];
    u8 *vars;
    s32 ret;
    f32 f;

    ret = 0;
    vars = *(u8 **)(self + 0x68);
    func_L01_00450F00(self, pos);
    switch (vars[0x5D]) {
    case 0:
    case 2:
        if (vars[0x5D] == 0) {
            vars[0x58] = func_L01_003F9080(self, (V_003F6ED8 *)buf, 0x20);
        } else {
            func_L01_00439A98(self, tmp, buf, *(s16 *)(vars + 0x36));
        }
        *(u8 **)(vars + 0x30) = buf;
        ret = func_L01_003F8080(self);
        if (vars[0x5C] != 0 || func_0038CB00(vars + 0x34) != 0) {
            ret = 1;
        }
        *(u8 **)(vars + 0x30) = 0;
        break;
    case 4:
        ret = func_L01_003F8470_003F7EE8(self);
        break;
    case 5:
        ret = func_L01_003F8478_003F7EE8(self);
        break;
    case 1:
    case 3:
        ret = func_L01_003F8208(self);
        if (func_0038CB00(vars + 0x34) != 0) {
            ret = 1;
        }
        break;
    }
    f = *(f32 *)(self + 0x10);
    if (f < 2.0f || f > 1021.0f) {
        return 1;
    }
    f = *(f32 *)(self + 0x14);
    if (f < 2.0f || f > 1021.0f) {
        return 1;
    }
    f = *(f32 *)(self + 0x18);
    if (f < 2.0f || f > 1021.0f) {
        return 1;
    }
    return ret;
}
/* localdecomp:end func_L01_003F7EE8 */

/* localdecomp:start func_L01_003F8080 */
extern s32 func_L01_003F8F98(f32 *v, f32 *a, f32 *b, f32 scale, f32 min);
extern void func_L01_003F8620(u8 *self);
extern void func_L01_003F8480(u8 *self);
extern s32 func_L01_003F8820(u8 *self);
extern void func_0038CF68(void *a, void *b, f32 s);
extern void func_0038CE90(void *out, void *m, void *v);
extern void func_L01_003F8E78(u8 *self, void *a, void *b);
extern void func_003C5180(void *a, void *b, s32 c);

extern s32 func_003A52A0(s32 a, s32 b, u8 *c);
extern u32 func_L01_003F8B30(u8 *self, s32 a, void *b);
extern void func_L01_004AAFD0(s32 a, void *b);
extern u8 D_L01_001EAA40[];

s32 func_L01_003F8080(u8 *self) {
    V4_003F5ED8 a;
    V4_003F5ED8 b;
    u8 *v;
    u8 st;
    s32 idx;
    s32 h;

    v = *(u8 **)(self + 104);
    st = v[92];
    if (st >= 3) {
        return 1;
    }
    if (st != 0) {
        func_L01_003F8620(self);
    } else {
        func_L01_003F8480(self);
    }
    idx = func_L01_003F8820(self);
    if (idx != -1) {
        h = -1;
        func_0038CF68(D_L01_001EAA40, D_L01_001EAA40, 1.0f);
        func_0038CE90(&a, D_L01_001EAA40, v);
        func_L01_003F8E78(self, v + 16, &a);
        func_003C5180(self + 16, &b, 1);
        if (((s32 (*)(void *a, void *b, void *c, f32 d, f32 e))func_L01_003F8F98)(v, D_L01_001EAA40, &b, *(f32 *)(v + 56), *(f32 *)(v + 60)) == 0) {
            if (v[94] != 255 && v[92] == 0) {
                h = func_003A52A0(v[94], 0, self);
            }
            func_L01_003F8B30(self, idx, &b);
        } else if (v[94] != 255) {
            h = func_003A52A0(v[94], 0, self);
        }
        if (h != -1) {
            func_L01_004AAFD0(h, v + 32);
        }
    }
    return 0;
}
/* localdecomp:end func_L01_003F8080 */

/* localdecomp:start func_L01_003F8208 */
#include "vu0.h"

typedef struct {
    f32 v[4];
} V4_003F5ED8_003F8208;

extern void func_L01_003F8550_003F8208(u8 *a0);
extern s32 func_L01_003F8A90_003F8208(u8 *self);
extern void func_0038CF68(void *a, void *b, f32 s);
extern void func_0038CE90(void *out, void *m, void *v);
extern void func_L01_003F8E78_003F8208(u8 *self, void *a, void *b);
extern void func_003C5180(void *a, void *b, s32 c);
extern f32 func_0038CE68(f32 *, f32 *);
extern f32 func_0038CEA8(f32 *);
extern void func_003C4138(f32 *, f32, f32);
extern void func_003C4CE8(u8 *a0, void *a1, f32 f12);
extern void func_0038D6C8(void *, void *, void *, f32);
extern s32 func_003A52A0(s32 a, s32 b, u8 *c);
extern s32 func_003A5348(s32, s32, s32);
extern void func_L01_004AAFD0_003F8208(s32 a, void *b);
extern void func_L01_0040E790_003F8208(void *, void *, void *);
extern u8 D_L01_001EAA40_003F8208[];

s32 func_L01_003F8208(u8 *self) {
    V4_003F5ED8_003F8208 a;
    V4_003F5ED8_003F8208 b;
    V4_003F5ED8_003F8208 c;
    V4_003F5ED8_003F8208 d;
    f32 len;
    u8 *v;
    f32 dist;
    f32 half;
    s32 h;

    v = *(u8 **)(self + 104);
    func_L01_003F8550_003F8208(self);
    if (func_L01_003F8A90_003F8208(self) != 0) {
        func_0038CF68(D_L01_001EAA40_003F8208, D_L01_001EAA40_003F8208, 1.0f);
        func_0038CE90(&a, D_L01_001EAA40_003F8208, v);
        func_L01_003F8E78_003F8208(self, v + 16, &a);
        func_003C5180(self + 16, &b, 1);
        if (func_0038CE68(&b, D_L01_001EAA40_003F8208) > 0.7f) {
            dist = func_0038CE68(v, D_L01_001EAA40_003F8208);
            half = dist * 0.5f;
            if (fabs_asm(half) < 0.040000003f) {
                half = 0.0f;
            }
            func_0038CF68(&c, D_L01_001EAA40_003F8208, dist + half);
            vec_sub_ab(v, v, &c);
            if (half == 0.0f) {
                len = func_0038CEA8(v);
                func_003C4138(&len, 0.040000003f, 0.0028000001f);
                func_0038CF68(v, v, len);
                func_0038CE90(&d, v, D_L01_001EAA40_003F8208);
                func_003C4CE8(&d, &d, (func_0038CEA8(&d) * -0.5f) / *(f32 *)(v + 44));
                func_0038D6C8(v + 16, v + 16, &d, 0.1f);
            }
            if (fabs_asm(dist) >= 0.040000003f) {
                if (v[94] != 255) {
                    h = func_003A52A0(v[94], 0, self);
                } else {
                    h = func_003A5348(8, 0, (s32)self);
                }
                if (h != -1) {
                    func_L01_004AAFD0_003F8208(h, v + 32);
                }
            }
        } else {
            func_L01_0040E790_003F8208(v, v, D_L01_001EAA40_003F8208);
        }
    }
    return 0;
}
/* localdecomp:end func_L01_003F8208 */

/* localdecomp:start func_L01_003F8470 */
s32 func_L01_003F8470(void) {
    return 1;
}
/* localdecomp:end func_L01_003F8470 */

/* localdecomp:start func_L01_003F8478 */
s32 func_L01_003F8478(void) {
    return 1;
}
/* localdecomp:end func_L01_003F8478 */

/* localdecomp:start func_L01_003F8480 */
extern void func_003C5278(void *, void *, void *, f32);
extern void func_0038D000(void *, void *, void *);
extern void func_0038D810(void *, void *);
extern void func_0038D5F0(void *, void *, void *);

void func_L01_003F8480(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 104);
    f32 t[24];
    func_003C5278(a0 + 16, s, s, *(f32 *)(s + 72));
    vec_add_ba(a0 + 16, a0 + 16, s);
    func_0038D000(t, s + 32, a0 + 192);
    func_0038D810(s + 16, t + 12);
    func_0038D5F0(a0 + 192, t + 12, a0 + 192);
    func_0038D000(t + 4, s + 32, a0 + 192);
    vec_sub_ba(t + 8, t + 4, t);
    vec_sub_ab(a0 + 16, a0 + 16, t + 8);
}
/* localdecomp:end func_L01_003F8480 */

/* localdecomp:start func_L01_003F8550 */
extern void func_003C5278(void *, void *, void *, f32);
extern void func_0038D000(void *, void *, void *);
extern void func_0038D810(void *, void *);
extern void func_0038D5F0(void *, void *, void *);

void func_L01_003F8550(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 104);
    f32 t[24];
    func_003C5278(a0 + 16, s, s, *(f32 *)(s + 72));
    vec_add_ba(a0 + 16, a0 + 16, s);
    func_0038D000(t, s + 32, a0 + 192);
    func_0038D810(s + 16, t + 12);
    func_0038D5F0(a0 + 192, t + 12, a0 + 192);
    func_0038D000(t + 4, s + 32, a0 + 192);
    vec_sub_ba(t + 8, t + 4, t);
    vec_sub_ab(a0 + 16, a0 + 16, t + 8);
}
/* localdecomp:end func_L01_003F8550 */

/* localdecomp:start func_L01_003F8620 */
#include "vu0.h"


extern void func_0038CDF8(void *, void *, void *, f32);
extern void func_0038D000(void *, void *, void *);
extern void func_003C5180(void *a, void *b, s32 c);
extern void func_0038CF68(void *a, void *b, f32 s);
extern void func_0038CE90(void *out, void *m, void *v);
extern void func_L01_003F8E78_003F8620(u8 *self, void *a, void *b);
extern void func_L01_003F8F48_003F8620(u8 *a0, u8 *a1, u8 *a2);
extern void func_0038D810(void *, void *);
extern void func_0038D5F0(void *, void *, void *);

void func_L01_003F8620(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 104);
    f32 t[44];
    if (s[0x5C] >= 2) {
        func_0038CDF8(t, *(u8 **)(s + 0x30) + s[0x59] * 16, *(u8 **)(s + 0x30) + s[0x5A] * 16, 0.5f);
        vec_sub_ab(t + 16, *(u8 **)(s + 0x30) + s[0x59] * 16, *(u8 **)(s + 0x30) + s[0x5A] * 16);
        func_0038D000(t + 16, t + 16, a0 + 192);
    } else {
        *(u128_t *)t = *(u128_t *)(*(u8 **)(s + 0x30) + s[0x59] * 16);
    }
    func_0038D000(t + 4, t, a0 + 192);
    func_003C5180(a0 + 16, t + 20, 1);
    vec_sub_ab(t + 24, t, s + 32);
    func_0038D000(t + 24, t + 24, a0 + 192);
    func_0038CF68(t + 24, t + 24, 1.0f);
    func_0038CE90(t + 28, t + 24, t + 20);
    func_0038CF68(t + 28, t + 28, *(f32 *)(s + 76));
    func_L01_003F8E78_003F8620(a0, s + 16, t + 28);
    if (s[0x5C] >= 2) {
        func_L01_003F8F48_003F8620(a0, s + 16, (u8 *)(t + 16));
    }
    func_0038D810(s + 16, t + 32);
    func_0038D5F0(a0 + 192, t + 32, a0 + 192);
    func_0038D000(t + 8, t, a0 + 192);
    vec_sub_ba(t + 12, t + 8, t + 4);
    vec_sub_ab(a0 + 16, a0 + 16, t + 12);
}
/* localdecomp:end func_L01_003F8620 */

/* localdecomp:start func_L01_003F8820 */
typedef struct {
    u8 pad0[0x2C];
    f32 f2C;
    u8 pad30[0x24];
    u8 *w54;
    u8 b58;
    u8 b59[3];
    u8 b5C;
} S_003F8820;
extern s32 D_L01_001E1060[];
extern s32 D_L01_001E1068;
extern s32 D_L01_001E1070;
extern s32 D_L01_001E1074;
extern s32 D_L01_001DFC08;
extern s32 D_L01_001D545C;
__asm__(".extern D_L01_001D545C, 16");
extern vu0_v4 D_L01_001EAA20[];
extern void func_003A92F0(s32);
extern s32 func_L01_003FB640(void *, s32, f32, u8 *);
extern s32 func_L01_003FE1E8(void *, void *, s32, s32);

s32 func_L01_003F8820(u8 *a0) {
    vu0_v4 p;
    vu0_v4 q;
    vu0_v4 v;
    vu0_v4 w;
    S_003F8820 *d = *(S_003F8820 **)(a0 + 0x68);
    s32 flags;
    s32 r;
    s32 i;
    s32 k;
    s32 found;
    f32 t;

    func_0038D000(&p, (u8 *)d + 0x20, a0 + 0xC0);
    vec_add_ab(&p, &p, a0 + 0x10);
    D_L01_001DFC08 = D_L01_001E1060[D_L01_001E1074] + D_L01_001E1070 - 0x8000;
    if (D_L01_001DFC08 < D_L01_001E1068) {
        func_003A92F0(1);
        D_L01_001DFC08 = D_L01_001E1060[1 - D_L01_001E1074] + D_L01_001E1070 - 0x8000;
    }
    switch (D_L01_001D545C) {
    case 0x2A:
    case 0x2D:
        flags = 0xB20;
        break;
    case 0x29:
        flags = 0xD20;
        break;
    default:
        flags = 0x20;
        break;
    }
    r = func_L01_003FB640(&p, flags | 0x42, d->f2C, d->w54);
    if (r != 0) {
        for (i = 0; i < d->b58; i++) {
            found = 0;
            for (k = 0; k < d->b5C; k++) {
                if (d->b59[k] == i) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                func_0038D000(&q, *(u8 **)((u8 *)d + 0x30) + i * 16, a0 + 0xC0);
                vec_add_ab(&q, &q, a0 + 0x10);
                if (func_L01_003FE1E8(&p, &q, r, 0)) {
                    vec_sub_ab(&v, &q, &D_L01_001EAA20[0]);
                    func_0038CF68(&D_L01_001EAA20[2], &D_L01_001EAA20[2], 1.0f);
                    t = func_0038CE68(&v.x, &D_L01_001EAA20[2].x);
                    func_0038CF68(&w, &D_L01_001EAA20[2], -t);
                    vec_add_ab(a0 + 0x10, a0 + 0x10, &w);
                    return i;
                }
            }
        }
    } else {
        d->b5C = 0;
    }
    return -1;
}
/* localdecomp:end func_L01_003F8820 */

/* localdecomp:start func_L01_003F8A90 */
#include "vu0.h"
extern s32 func_L01_003FB640(void *, s32, f32, u8 *);
extern vu0_v4 D_L01_001EAA30;
typedef struct { vu0_q q; } vu0_s_003F8A90;

static __inline__ void gp_add_n_003F8A90(void *d, void *a, void *b) {
    vu0_q qa, qb, qr;
    __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*(vu0_s_003F8A90 *)a));
    __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(vu0_s_003F8A90 *)b));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(qr) : "j"(qa), "j"(qb));
    __asm__("sqc2 %1, %0" : "=m"(*(vu0_s_003F8A90 *)d) : "j"(qr));
}

static __inline__ void gp_copy_003F8A90(void *d, void *s) {
    vu0_q q;
    __asm__("lqc2 %0, %1" : "=j"(q) : "m"(*(vu0_s_003F8A90 *)s));
    __asm__("sqc2 %1, %0" : "=m"(*(vu0_s_003F8A90 *)d) : "j"(q));
}

s32 func_L01_003F8A90(u8 *a0) {
    vu0_v4 p;
    vu0_v4 r;
    vu0_v4 o;
    vu0_v4 q;
    u8 *d = *(u8 **)(a0 + 0x68);

    func_0038D000(&p, d + 0x20, a0 + 0xC0);
    gp_add_n_003F8A90(&p, &p, a0 + 0x10);
    if (func_L01_003FB640(&p, 2, *(f32 *)(d + 0x2C), *(u8 **)(d + 0x54))) {
        vu0_q qo, qd, t, x, y;
        gp_copy_003F8A90(&q, &p);
        __asm__("lqc2 %0, %2\n\tlqc2 %1, %3" : "=&j"(qo), "=&j"(qd) : "m"(*(vu0_s_003F8A90 *)(a0 + 0x10)), "m"(D_L01_001EAA30));
        __asm__("sqc2 %1, %0" : "=m"(o) : "j"(qo));
        __asm__("lqc2 %1, %2\n\tvsub.xyz %0, %0, %1" : "+j"(qd), "=&j"(t) : "m"(q));
        __asm__("sqc2 %1, %0" : "=m"(r) : "j"(qd));
        __asm__("lqc2 %0, %2\n\tlqc2 %1, %3" : "=&j"(x), "=&j"(y) : "m"(r), "m"(o));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(y), "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)(a0 + 0x10)) : "j"(x));
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_003F8A90 */

/* localdecomp:start func_L01_003F8B30 */
typedef struct {
    u8 gap0[0x10];
    u8 plane[0x10];
    u8 gap20[0x10];
    vu0_q *points;
    u8 gap34[0x25];
    u8 indices[3];
    u8 count;
} S_003F8B30;
extern void func_L01_003F8BE0(u8 *self, s32 i, void *dir);
extern void func_0038D000(void *, void *, void *);
extern void func_L01_003F8F48(u8 *a0, u8 *a1, u8 *a2);

u32 func_L01_003F8B30(u8 *self, s32 a, void *b) {
    vu0_q diff;
    S_003F8B30 *d = *(S_003F8B30 **)(self + 0x68);
    d->indices[d->count] = a;
    d->count++;
    func_L01_003F8BE0(self, d->count - 1, b);
    if (d->count != 1) {
        vec_sub_ab(&diff, &d->points[d->indices[0]], &d->points[d->indices[1]]);
        func_0038D000(&diff, &diff, self + 0xC0);
        func_L01_003F8F48(self, d->plane, (u8 *)&diff);
    }
    return d->count;
}
/* localdecomp:end func_L01_003F8B30 */

INCLUDE_ASM("asm/levels", func_L01_003F8BE0);

/* localdecomp:start func_L01_003F8E78 */
extern f32 func_0038CEA8(f32 *);
extern void func_003C4CE8(u8 *a0, void *a1, f32 f12);
extern f32 func_0038D0B0(f32);
extern void func_0038D688(void *, void *, void *);

void func_L01_003F8E78(u8 *self, void *a, void *b)
{
    u128_t vec;
    f32 half;
    f32 lo;
    f32 hi;

    vec = *(u128_t *)b;
    half = func_0038CEA8((f32 *)&vec) * 0.5f;
    lo = func_0038D0B0(0.015707964077591896f);
    hi = func_0038D0B0(0.03141592815518379f);
    if (lo < half)
        half = lo;
    func_003C4CE8((u8 *)&vec, &vec, half);
    func_0038D688(a, a, &vec);
    if (hi < func_0038CEA8((f32 *)a))
        func_003C4CE8(a, a, hi);
}
/* localdecomp:end func_L01_003F8E78 */

/* localdecomp:start func_L01_003F8F48 */
extern f32 func_0038CE68(f32 *, f32 *);
extern void func_0038CF68(void *a, void *b, f32 s);
extern void func_003C4CE8(u8 *a0, void *a1, f32 f12);
void func_L01_003F8F48(u8 *a0, u8 *a1, u8 *a2) {
    u128_3F6DA0 tmp;
    ((void (*)(void *a0, u8 *a1, f32 f12))func_0038CF68)(&tmp, a2, 1.0f);
    func_003C4CE8(a1, &tmp, ((f32 (*)(void *a0, u8 *a1))func_0038CE68)(&tmp, a1));
}
/* localdecomp:end func_L01_003F8F48 */

/* localdecomp:start func_L01_003F8F98 */
extern void func_0038CF68(void *a, void *b, f32 s);
extern void func_L01_0040E790(f32 *, f32 *, f32 *);
extern f32 func_0038CEA8(f32 *);
extern f32 func_0038CE68(f32 *, f32 *);
extern void func_003C4138(f32 *, f32, f32);
s32 func_L01_003F8F98(f32 *v, f32 *a, f32 *b, f32 scale, f32 min) {
    f32 len;
    f32 hi;
    func_L01_0040E790(v, v, a);
    len = func_0038CEA8(v);
    if (0.7f < func_0038CE68(b, a)) {
        hi = len * scale;
        if (hi < min) {
            hi = min;
        }
        func_003C4138(&len, 0.0f, hi);
        ((void (*)(f32 *, f32 *, f32))func_0038CF68)(v, v, len);
    }
    return len != 0.0f;
}
/* localdecomp:end func_L01_003F8F98 */

/* localdecomp:start func_L01_003F9080 */
extern void func_0038CE20(V_003F6ED8 *, V_003F6ED8 *, f32);
s32 func_L01_003F9080(u8 *m, V_003F6ED8 *out, s32 max) {
    u8 *p;
    s16 *src;
    s32 n;
    s32 i;
    f32 scale;
    p = *(u8 **)(*(u8 **)(m + 36) + 16);
    if (p == 0) {
        return 0;
    }
    n = *(s32 *)(p + 12) / 8;
    src = (s16 *)(p + *(s32 *)(p + 4) + 16);
    if (max < n) {
        n = max;
    }
    scale = *(f32 *)(m + 44) * 0.0009765625f;
    for (i = 0; i < n; i++) {
        out[i].x = src[0];
        out[i].y = src[1];
        out[i].z = src[2];
        src += 4;
        func_0038CE20(&out[i], &out[i], scale);
        out[i].w = 1.0f;
    }
    return n;
}
/* localdecomp:end func_L01_003F9080 */
