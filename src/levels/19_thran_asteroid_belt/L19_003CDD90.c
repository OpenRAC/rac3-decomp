#include "common.h"
#include "vu0.h"

typedef struct Bar_003CF388 {
    u8 pad_000[0x300];
    s32 f300;
    f32 f304;
    f32 f308;
    f32 f30C;
    f32 f310;
    f32 f314;
    f32 f318;
    f32 f31C;
    f32 f320;
    f32 f324;
    f32 f328;
    f32 f32C;
    f32 f330;
    s32 f334;
    s32 f338;
} Bar_003CF388;
typedef struct Foo_003CF388 {
    u8 pad_000[0x68];
    Bar_003CF388 *f68;
} Foo_003CF388;

/* localdecomp:start func_L19_003CDD90 */
f32 func_L19_003CDD90(f32 t, f32 b, f32 c, f32 d, f32 e) {
    f32 t2, t3;
    t2 = t * t;
    t3 = t2 * t;
    return 0.5f * (2.0f * c + (-b + d) * t + (2.0f * b - c * 5.0f + d * 4.0f - e) * t2 + (-b + c * 3.0f - d * 3.0f + e) * t3);
}
/* localdecomp:end func_L19_003CDD90 */

/* localdecomp:start func_L19_003CDE10 */
extern f32 func_L19_003CDD90(f32, f32, f32, f32, f32);

void func_L19_003CDE10(f32 *out, f32 *a, f32 *b, f32 *c, f32 *d, f32 t) {
    out[0] = func_L19_003CDD90(t, a[0], b[0], c[0], d[0]);
    out[1] = func_L19_003CDD90(t, a[1], b[1], c[1], d[1]);
    out[2] = func_L19_003CDD90(t, a[2], b[2], c[2], d[2]);
}
/* localdecomp:end func_L19_003CDE10 */

INCLUDE_ASM("asm/levels", func_L19_003CDEC0);

/* localdecomp:start func_L19_003CE990 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3CE990;
extern u8 *D_L19_001DF71C;
extern s32 D_L19_001DF240;
extern s32 func_L01_0044C108(void *);
extern void func_L19_003CEEF8(u8 *);
extern void func_L19_003CF090(u8 *);
extern void func_L19_003CF280(u8 *);
extern s32 func_L01_004561B8(u8 *);
extern void func_003C3938(void *, s32, s32);
extern s32 func_0038CAD0(void *);
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_003C3A10(u8 *, s32, s32, s32);
extern s32 func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003C2880(u8 *);
extern u8 *func_L01_00447490(u8 *, s32, s32);
extern void func_003C4A40(void *, void *);
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_00382498(s32, s32);
extern void func_L01_00463378(void *, void *, void *, s32, s32, s32, s32, s32, s32);
extern void func_L01_0044ABD0(void *, void *);
extern void func_L01_00456BD0(void *, s32);

void func_L19_003CE990(u8 *obj) {
    u8 *p;
    u8 *h;
    u8 *q;
    u8 *t;
    V4_3CE990 a;
    V4_3CE990 b;
    V4_3CE990 c;
    f32 ang;
    f32 r;
    s32 n;
    s32 k1, k2, k3;
    s32 n24, col;
    V4_3CE990 *pa;

    if (func_L01_0044C108(obj + 0x10) == 0)
        return;
    p = *(u8 **)(obj + 0x68);
    switch (obj[0x20]) {
    case 0:
        func_L19_003CEEF8(obj);
        func_L01_004450F0(obj, 4, -1);
        break;
    case 2:
        if (func_L01_004561B8(obj))
            func_003C3938(obj, 0, 0);
        func_0038CAD0(p + 0x10C);
        if (*(s32 *)(p + 0x10C) == 0) {
            *(f32 *)(p + 0x30) = (f32)*(s16 *)(p + 0x34);
            func_L01_004450F0(obj, 3, -1);
        }
        break;
    case 3:
        if (func_L01_004561B8(obj) && obj[0x43] != 1)
            func_003C3A10(obj, 1, 0, 5);
        func_L19_003CF090(obj);
        if (obj[0x60] & 2) {
            func_003C3938(obj, 2, 0);
            func_L01_004450F0(obj, 4, -1);
        }
        break;
    case 4:
        if (func_L01_004561B8(obj))
            func_003C3938(obj, 2, 0);
        func_L19_003CF090(obj);
        break;
    case 1:
        t = *(u8 **)((*(s32 *)(p + 0x114) << 8) + (s32)D_L19_001DF71C + 0x68);
        if (obj[0x42] == obj[0x43]) {
            if (obj[0x42] != 4 && *(s32 *)(t + 0x18) == 0)
                func_003C3A10(obj, 4, 0, 5);
            if (obj[0x42] == obj[0x43] && obj[0x42] == 4 && (obj[0x60] & 2)) {
                func_003C3938(obj, 0, 0);
                func_L01_004450F0(obj, 2, -1);
            }
        }
        break;
    case 5:
        func_L01_003303B8(obj + 0x10, 0, 0, 0x14, 0, 8, 0x28, 4, 1.0f, 2.0f, 0.0f, 0.0f,
            1, 1, 1, 1, 1, 0, 0, 0, 0xFF4020FF, 0xFF6020C0, 0, 0, 0xFF802040, 0, 0xFFF02060, 0xFF4020FF, 0xFF802040, 0);
        func_003C2880(obj);
        return;
    }
    h = func_L01_00447490(obj, -1, 0);
    q = p + 0x70;
    if (h != 0) {
        if (*(u8 **)(h + 0x20) != D_L19_001DF71C + (*(s32 *)(p + 0x114) << 8)) {
            if ((u32)(obj[0x20] - 3) < 2 && D_L19_001DF240 >= *(s32 *)(p + 0x118)) {
                p[0x77] = 0xFF;
                func_003C4A40(obj, q);
                *(f32 *)(p + 0x30) = *(f32 *)(p + 0x30) - *(f32 *)(h + 0x2C);
                if (*(f32 *)(p + 0x30) <= 0.0f) {
                    *(s32 *)(p + 0x10C) = (*(s32 *)(p + 0x108) * 5 + 2) / 6;
                    func_L01_004450F0(obj, 1, -1);
                }
                if (*(u16 *)(h + 0x2A) == 0x185E)
                    func_L01_004450F0(obj, 5, -1);
            }
        }
        obj[0xA8] = 0xFF;
    }
    if (*(f32 *)(p + 0x30) <= 0.0f) {
        pa = &a;
        qzero(&a);
        a.z = func_003824E0(0.020000001f, 0.030000001f);
        qzero(&b);
        b.w = 0.25f;
        a.w = 0.15f;
        ang = func_00382538();
        r = func_003824E0(-0.25f, 0.25f);
        c.x = func_0038D098(ang) * r;
        c.y = func_0038D0B0(ang) * r;
        c.z = 0.0f;
        vec_add_ba(&c, &c, obj + 0x10);
        n = *(s32 *)(p + 0x10C);
        col = ((n >> 1) << 24) | 0x404040;
        n24 = n << 24;
        k1 = (func_00382498(5, 10) * 5 + 2) / 6;
        k2 = (func_00382498(0x3C, 0x78) * 5 + 2) / 6;
        k3 = (func_00382498(0x1E, 0x3C) * 5 + 2) / 6;
        func_L01_00463378(&c, pa, &b, n24, col, k1, k2, k3, -1);
    }
    func_L19_003CF280(obj);
    func_L01_0044ABD0(obj, q);
    if (0.0f < *(f32 *)(p + 0x30))
        func_L01_00456BD0(obj, 3);
}
/* localdecomp:end func_L19_003CE990 */

/* localdecomp:start func_L19_003CEEF8 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3CEEF8;
extern V4_3CEEF8 D_L19_001E8E60;
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern f32 func_0038CE68(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_003C2F58(void *, s32, void *);
extern void func_L01_0043A430(void *, s32, void *);

void func_L19_003CEEF8(u8 *obj) {
    u8 *p = *(u8 **)(obj + 0x68);
    V4_3CEEF8 a;
    V4_3CEEF8 b;

    p[0x58] = 0xA;
    p[0x5A] = 2;
    *(f32 *)(p + 0x40) = 0.3f;
    p[0x3E] = 3;
    p[0x39] = 0;
    p[0x3F] = 0;
    p[0x64] = 0;
    if (*(s16 *)(p + 0x34) == 0) {
        *(s16 *)(p + 0x34) = 1;
        *(f32 *)(p + 0x30) = 1.0f;
    }
    vec_add_ab(&a, obj + 0x10, obj + 0xE0);
    func_0038CE20(&b, obj + 0xE0, -10.0f);
    vec_add_ab(&b, &b, obj + 0x10);
    if (func_003D3CB0(&a, &b, 0, obj, 0) != 0)
        *(V4_3CEEF8 *)(obj + 0x10) = D_L19_001E8E60;
    *(s32 *)(p + 0x118) = 0;
    *(s32 *)(p + 0x110) = (*(s32 *)(p + 0x110) * 5 + 2) / 6;
    func_003C3938(obj, 2, 0);
    func_003C2F58(obj, 1, p + 0x130);
    vec_sub_ba(p + 0x130, p + 0x130, obj + 0x10);
    func_0038CE20(p + 0x130, obj + 0xE0, func_0038CE68(p + 0x130, obj + 0xE0));
    vec_add_ba(p + 0x130, p + 0x130, obj + 0x10);
    func_L01_0043A430(obj, 2, p + 0x80);
    func_L01_0043A430(obj, 0, p + 0xC0);
}
/* localdecomp:end func_L19_003CEEF8 */

/* localdecomp:start func_L19_003CF090 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3CF090;
typedef struct { u8 pad[0x30]; V4_3CF090 v; u8 pad2[0x40]; } P_3CF090;
extern s32 D_L19_001DF240;
extern P_3CF090 *D_L19_001DF800;
__asm__(".extern D_L19_001DEB30, 4");
extern f32 D_L19_001DEB30;
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D890(void *, void *, void *, f32);
extern f32 func_0038D0B0(f32);
extern void func_003C4098(void *, void *, void *, f32);
extern void func_003C5060(void *, void *, void *, s32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038CED8(void *);
extern void func_0038D750(void *, s32, f32);

void func_L19_003CF090(u8 *obj) {
    u8 *d = *(u8 **)(obj + 0x68);
    V4_3CF090 v;
    V4_3CF090 w;
    f32 a;
    f32 r;

    if (*(s32 *)(d + 0x11C) != 0) {
        u8 *p = d + 0x120;
        a = (f32)(D_L19_001DF240 % *(s32 *)(d + 0x110));
        a = a * 6.2831855f;
        a = a / (f32)*(s32 *)(d + 0x110);
        a = a - 3.1415927f;
        func_0038CE20(p, obj + 0xC0, 128.0f);
        func_0038D890(p, p, obj + 0xE0, a);
        vec_add_ab(d + 0x120, d + 0x120, d + 0x130);
    } else {
        a = (f32)(D_L19_001DF240 % *(s32 *)(d + 0x110)) * 6.2831855f / (f32)*(s32 *)(d + 0x110) - 3.1415927f;
        a = func_0038D0B0(a);
        v = D_L19_001DF800[*(s32 *)(d + 0x100)].v;
        w = D_L19_001DF800[*(s32 *)(d + 0x104)].v;
        func_003C4098(d + 0x120, &v, &w, a * 0.5f + 0.5f);
    }
    vec_sub_ba(&v, d + 0x120, obj + 0x10);
    func_003C5060(obj, &v, &v, 0);
    a = func_0038DAB8(func_0038D160(v.x, v.y), D_L19_001DEB30);
    r = func_0038D160(func_0038CED8(&v), v.z);
    func_0038D750(d + 0x90, 1, -r);
    func_0038D750(d + 0xD0, 2, a);
}
/* localdecomp:end func_L19_003CF090 */

/* localdecomp:start func_L19_003CF280 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3CF280;
extern s32 D_L19_001DEB38;
__asm__(".extern D_L19_001DEB38, 4");
extern f32 D_L19_001DEB34;
__asm__(".extern D_L19_001DEB34, 4");
extern void func_003C2EC0(void *, s32, void *);
extern f32 func_0038CF38(void *, void *);
extern void func_L01_00456230(void *, s32);

void func_L19_003CF280(u8 *obj) {
    u8 *d = *(u8 **)(obj + 0x68);
    u8 *e = D_L19_001DF71C + (*(s32 *)(d + 0x114) << 8);
    V4_3CF280 m[4];
    V4_3CF280 t;
    u8 *p;
    s32 n;

    func_003C2EC0(obj, 1, m);
    func_0038CE20(&t, &m[D_L19_001DEB38], D_L19_001DEB34);
    vec_add_ab(e + 0x10, &t, &m[3]);
    *(f32 *)(e + 0xF8) = func_0038D160(*(f32 *)(d + 0x120) - *(f32 *)(e + 0x10), *(f32 *)(d + 0x124) - *(f32 *)(e + 0x14));
    *(f32 *)(e + 0xF4) = -func_0038D160(func_0038CF38(e + 0x10, d + 0x120), *(f32 *)(d + 0x128) - *(f32 *)(e + 0x18));
    *(s32 *)(e + 0xF0) = 0;
    *(s32 *)(e + 0x98) = 0;
    p = *(u8 **)(e + 0x68);
    n = *(s32 *)(p + 0x2C);
    if (n >= 2)
        n = 1;
    *(s32 *)(p + 0x2C) = n;
    func_L01_00456230(obj, obj[0x20] == 4);
}
/* localdecomp:end func_L19_003CF280 */

/* localdecomp:start func_L19_003CF388 */
void func_L19_003CF388(Foo_003CF388 *a0) {
    Bar_003CF388 *p = a0->f68;

    p->f300 = 4;
    p->f304 = 0.33f;
    p->f308 = 1200.0f;
    p->f30C = 1500.0f;
    p->f314 = 5.5f;
    p->f318 = 0.1f;
    p->f31C = 0.02f;
    p->f320 = 0.05f;
    p->f310 = 3.0f;
    p->f324 = 3.0f;
    p->f328 = 5.0f;
    p->f32C = 0.2f;
    p->f330 = 1.0f;
    p->f334 = 0;
    p->f338 = 0;
}
/* localdecomp:end func_L19_003CF388 */

INCLUDE_ASM("asm/levels", func_L19_003CF440);

/* localdecomp:start func_L19_003CF7B8 */
typedef int u128_t __attribute__((mode(TI)));
extern s32 func_0038DC20(void *, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern u8 D_L19_001D66F0[8];
extern u8 *func_L01_0046B458(u8 *position, s32 life, f32 size, f32 start_size, s32 colour, s32 roll_kind,
                             s32 spin, void *velocity, f32 unk, s32 delay);

void func_L19_003CF7B8(void *pos, s32 n, s32 b, s32 m, s32 c, f32 x, f32 y) {
    u128_t q[2];
    f32 t;
    f32 z;
    s32 k;
    s32 r;
    q[0] = *(u128_t *)pos;
    q[1] = *(u128_t *)pos;
    ((f32 *)&q[1])[3] = 0.1f;
    if (func_0038DC20(&q[1], 32.0f) > 0) {
        t = func_003824E0(x, y);
        k = func_00382468(2);
        z = 0.0f;
        if (k == 0)
            k--;
        func_L01_0046B458((u8 *)&q[0], (n * 5 + 2) / 6, t * 0.3f, t, b, 0, k, D_L19_001D66F0, z, 0);
        if (m != 0 && c != 0) {
            func_L01_0046B458((u8 *)&q[0], (m * 5 + 2) / 6, t * 0.04f, t * 0.4f, c, 1, -k, D_L19_001D66F0, z, 0);
        }
    }
}
/* localdecomp:end func_L19_003CF7B8 */

INCLUDE_ASM("asm/levels", func_L19_003CF930);

/* localdecomp:start func_L19_003CFB20 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3CFB20;
typedef struct { u8 pad[0x10]; V4_3CFB20 pos; u8 pad2[0x90]; } E_3CFB20;
typedef struct { u8 pad[8]; s32 x8; f32 xC; u8 pad2[0x30]; E_3CFB20 e[4]; } D_3CFB20;
extern void func_0038D308(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);

void func_L19_003CFB20(u8 *obj) {
    V4_3CFB20 saved;
    V4_3CFB20 v;
    D_3CFB20 *d;
    s32 i;

    saved = *(V4_3CFB20 *)(obj + 0xF0);
    d = *(D_3CFB20 **)(obj + 0x68);
    for (i = 0; i < d->x8; i++) {
        *(f32 *)(obj + 0xF4) = func_0038DAB8(*(f32 *)(obj + 0xF4), d->xC * 0.017453292f);
        func_0038D308(obj + 0xC0, obj + 0xF0);
        v = *(V4_3CFB20 *)(obj + 0xC0);
        func_0038CF68(&v, &v, 10.0f);
        vec_add_ab(&v, &v, obj + 0x10);
        if (func_003D3CB0(obj + 0x10, &v, 2, obj, 0) != 0)
            v = *(V4_3CFB20 *)&D_L19_001E8E60;
        d->e[i].pos = v;
    }
    *(V4_3CFB20 *)(obj + 0xF0) = saved;
    func_0038D308(obj + 0xC0, obj + 0xF0);
}
/* localdecomp:end func_L19_003CFB20 */
