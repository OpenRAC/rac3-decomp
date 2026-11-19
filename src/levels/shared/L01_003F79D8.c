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

INCLUDE_ASM("asm/levels", func_L01_003F79D8);

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

INCLUDE_ASM("asm/levels", func_L01_003F8208);

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

INCLUDE_ASM("asm/levels", func_L01_003F8620);

INCLUDE_ASM("asm/levels", func_L01_003F8820);

INCLUDE_ASM("asm/levels", func_L01_003F8A90);

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
