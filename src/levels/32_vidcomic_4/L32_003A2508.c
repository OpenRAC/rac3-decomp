#include "common.h"
#include "vu0.h"

/* declared by functions of L32_003A0BB8.c, which this file was cut from */
void func_L32_003A2508(void *, s32, f32);

/* localdecomp:start func_L32_003A2508 */
extern void func_0038CF68(void *, void *, f32);

void func_L32_003A2508(void *arg0v, s32 arg1, f32 arg2) {
    u8 *arg0 = arg0v;
    s32 i;
    u8 **p;
    u8 *obj;
    u8 *sub;

    p = (u8 **)(*(u8 **)(arg0 + 0x68) + 0x200);
    i = 5;
    do {
        obj = *p;
        i--;
        if (obj != 0) {
            sub = *(u8 **)(obj + 0x68);
            *(s32 *)(sub + 0x4C) = arg1;
            *(f32 *)(sub + 0x5C) = arg2;
            vec_sub_ab(sub + 0x20, arg0 + 0x10, *p + 0x10);
            func_0038CF68(sub + 0x20, sub + 0x20, 1.0f);
        }
        p++;
    } while (i >= 0);
}
/* localdecomp:end func_L32_003A2508 */

INCLUDE_ASM("asm/levels", func_L32_003A25B0);

INCLUDE_ASM("asm/levels", func_L32_003A2830);

/* localdecomp:start func_L32_003A2A38 */
typedef struct V_003A2A38 {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_003A2A38;

typedef struct M_003A2A38 {
    V_003A2A38 r[4];
} M_003A2A38;

extern f32 D_001E2310;
extern f32 D_001E2310_003A2A38;
__asm__(".extern D_001E2310_003A2A38, 4");
extern s32 D_L32_001DE7C8;
__asm__(".extern D_L32_001DE7C8, 4");
extern s32 D_L32_001DE7CC;
__asm__(".extern D_L32_001DE7CC, 4");
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CED8(void *);
extern f32 func_0038D160(f32, f32);
extern void func_0038D328(void *, void *);
extern void func_003D9740(void *, s32, f32, s32, s32, s32);

void func_L32_003A2A38(void *pos, void *dir, f32 a, f32 b, f32 c, s32 col1, s32 col2, u8 al1, u8 al2,
                       f32 d) {
    M_003A2A38 m;
    V_003A2A38 q;
    V_003A2A38 rot;
    V_003A2A38 t;
    f32 f;
    s32 col;

    rot.x = 0.0f;
    rot.y = -func_0038D160(func_0038CED8(dir), ((V_003A2A38 *)dir)->z) + -1.5707964f;
    rot.z = func_0038D160(((V_003A2A38 *)dir)->x, ((V_003A2A38 *)dir)->y);
    rot.w = 1.0f;
    func_0038D328(&m, &rot);
    q = *(V_003A2A38 *)pos;
    t = *(V_003A2A38 *)dir;
    func_0038CE20(&t, &t, a);
    vec_add_ab(&q, &q, &t);
    m.r[3] = q;
    func_0038CE20(&m.r[0], &m.r[0], b);
    func_0038CE20(&m.r[1], &m.r[1], b);
    func_0038CE20(&m.r[2], &m.r[2], a);
    D_001E2310_003A2A38 = D_001E2310 + 0.2f;
    if (D_001E2310_003A2A38 >= 7.0f) {
        D_001E2310 = D_001E2310_003A2A38 - 7.0f;
    }
    func_003D9740(&m, D_L32_001DE7C8, c, (al1 << 24) | col1, 4, 1);
    f = b * d;
    col = (al2 << 24) | col2;
    func_0038CE20(&m.r[0], &m.r[0], f);
    func_0038CE20(&m.r[1], &m.r[1], f);
    func_003D9740(&m, D_L32_001DE7CC, c, col, 2, 1);
}
/* localdecomp:end func_L32_003A2A38 */

/* localdecomp:start func_L32_003A2C30 */
typedef struct V_003A2C30 {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_003A2C30;

extern f32 D_L32_001DE81C;
__asm__(".extern D_L32_001DE81C, 4");
extern s32 D_L32_001DE820;
__asm__(".extern D_L32_001DE820, 4");
extern s32 D_L32_001DE824;
__asm__(".extern D_L32_001DE824, 4");
extern f32 D_L32_001DE828;
__asm__(".extern D_L32_001DE828, 4");
extern f32 D_L32_001DE82C;
__asm__(".extern D_L32_001DE82C, 4");
extern f32 D_L32_001DE834;
__asm__(".extern D_L32_001DE834, 4");
extern s32 D_L32_001DE838;
__asm__(".extern D_L32_001DE838, 4");
extern f32 D_L32_001DE840;
__asm__(".extern D_L32_001DE840, 4");
extern s32 D_L32_001DE848;
__asm__(".extern D_L32_001DE848, 4");
extern u8 *D_L32_0021F918[];
extern f32 func_003824E0(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_003D8E60(void *, void *, f32, s32, f32, s32, f32, s32, s32, s32, s32);
extern void func_00382580(void *, f32, f32);
extern s32 func_00382498(s32, s32);
extern u8 *func_L01_00475C60(void *, void *, s32, s32, s32, s32, f32, f32, f32, s32);
extern s32 func_00382468(s32);

void func_L32_003A2C30(void *arg0, void *arg1, s32 count, s32 arg3, f32 scale) {
    V_003A2C30 v;
    u8 *p;
    s32 i;
    s32 n;
    s32 r;
    f32 size;

    func_0038CE20(&v, arg1, func_003824E0(D_L32_001DE81C * 0.5f, D_L32_001DE81C) * 0.020000001f);
    func_L01_003D8E60(arg0, &v, -100000.0f, D_L32_001DE824, scale * D_L32_001DE828, 7,
                      D_L32_001DE840, 5, D_L32_001DE820, arg3, 0);
    for (i = 0; i < count; i++) {
        func_00382580(&v, D_L32_001DE82C * 0.5f * 0.020000001f, D_L32_001DE82C * 0.020000001f);
        n = (D_L32_001DE838 * 5 + 2) / 6;
        r = func_00382498(-2, 2);
        size = D_L32_001DE834 * scale * 210000.0f;
        p = func_L01_00475C60(arg0, &v, n, r, 0x7F407FFF, 0x407FFF, size, size,
                              func_003824E0(D_L32_001DE840 * 0.6f, D_L32_001DE840), 0);
        if (p != 0) {
            p[9] = 0xF2;
            p[3] = func_00382468(D_L32_001DE848) ? 0x44 : 0x48;
            p[2] = D_L32_0021F918[97][3];
        }
    }
}
/* localdecomp:end func_L32_003A2C30 */

/* localdecomp:start func_L32_003A2E30 */
extern s32 func_0038DC20(void *, f32);
extern void func_00382580(void *, f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L30_0034CB68(void *, void *, s32, s32, void *, s32, f32, f32);
extern void func_L32_003A2C30(void *arg0, void *arg1, s32 count, s32 arg3, f32 scale);
extern s32 D_L32_001DE854;
__asm__(".extern D_L32_001DE854, 4");
extern s32 D_L32_001DE860;
__asm__(".extern D_L32_001DE860, 4");
extern f32 D_L32_001DE864;
__asm__(".extern D_L32_001DE864, 4");
extern f32 D_L32_001DE868;
__asm__(".extern D_L32_001DE868, 4");
extern f32 D_L32_001DE86C;
__asm__(".extern D_L32_001DE86C, 4");

typedef struct V_003A2E30 {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_003A2E30;

void func_L32_003A2E30(void *obj, void *arg1, void *dir, f32 height, f32 spread, f32 spread2,
                       f32 scale, s32 count, s32 color) {
    V_003A2E30 *pos = (V_003A2E30 *)arg1;
    V_003A2E30 s;
    V_003A2E30 a;
    V_003A2E30 b;
    V_003A2E30 c;
    V_003A2E30 d;
    f32 r;
    s32 i;

    color = (color == 0x1FF) ? 0xFF : color;
    s = *pos;
    s.w = scale + scale;
    r = 128.0f;
    if (color > 0x80) {
        r = color;
    }
    if (func_0038DC20(&s, r) < 0) {
        return;
    }
    func_00382580(&a, spread * 0.8f, spread * 1.2f);
    a.z += height;
    vec_add_ba(&a, &a, pos);
    func_0038CE20(&d, dir, D_L32_001DE868);
    vec_add_ba(&c, &d, pos);
    func_0038CE20(&b, dir, -D_L32_001DE86C);
    func_L30_0034CB68(obj, &b, 1, -1, &c, 0, (f32)D_L32_001DE860, D_L32_001DE864);
    for (i = 0; i < D_L32_001DE854; i++) {
        func_00382580(&d, spread2 * 0.7f, spread2 * 1.3f);
        vec_add_ab(&d, &a, &d);
        func_L32_003A2C30(&d, dir, count, color, scale * 0.75f);
    }
}
/* localdecomp:end func_L32_003A2E30 */

/* localdecomp:start func_L32_003A3038 */
typedef struct V_003A3038 {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_003A3038;

extern s32 D_001DF9C0;
extern f32 D_001E2228;
extern f32 D_001E222C;
extern s32 D_L32_001DE6E0;
__asm__(".extern D_L32_001DE6E0, 4");
extern s32 D_L32_001DE6E4;
__asm__(".extern D_L32_001DE6E4, 4");
extern s32 D_L32_001DE7D8;
__asm__(".extern D_L32_001DE7D8, 4");
extern s32 D_L32_001DE7DC;
__asm__(".extern D_L32_001DE7DC, 4");
extern f32 D_L32_001DE7E0;
__asm__(".extern D_L32_001DE7E0, 4");
extern f32 D_L32_001DE7EC;
__asm__(".extern D_L32_001DE7EC, 4");
extern f32 D_L32_001DE84C;
__asm__(".extern D_L32_001DE84C, 4");
extern f32 D_L32_001DE850;
__asm__(".extern D_L32_001DE850, 4");
extern s32 D_L32_001DE858;
__asm__(".extern D_L32_001DE858, 4");
extern f32 D_L32_001DE85C;
__asm__(".extern D_L32_001DE85C, 4");
extern f32 D_L32_001DE86C;
__asm__(".extern D_L32_001DE86C, 4");
extern s32 D_L32_001DE870;
__asm__(".extern D_L32_001DE870, 4");
extern f32 D_L32_001DE878;
__asm__(".extern D_L32_001DE878, 4");
extern f32 D_L32_001DE87C;
__asm__(".extern D_L32_001DE87C, 4");
extern f32 D_L32_001DE880;
__asm__(".extern D_L32_001DE880, 4");
extern void func_L32_003A2A38(void *, void *, f32, f32, f32, s32, s32, u8, u8, f32);
extern void func_L32_003A2E30(void *, void *, void *, f32, f32, f32, f32, s32, s32);

void func_L32_003A3038(void *arg0) {
    u8 *o = *(u8 **)((u8 *)arg0 + 0x68);
    s32 start = D_L32_001DE870;
    s32 t = D_001DF9C0 - *(s32 *)(o + 0x1EC);
    f32 f = (f32)(t - start) / (f32)(D_L32_001DE6E4 - start);
    f32 ft;
    f32 off;
    u8 a;
    V_003A3038 v;
    V_003A3038 w;

    if (f > 1.0f) {
        f = 1.0f;
    } else if (f < 0.0f) {
        f = 0.0f;
    }
    ft = t;
    a = (1.0f - f) * 127.0f;
    if (t < D_L32_001DE6E0) {
        *(vu0_q *)&v = 0;
        v.z = 1.0f;
        func_L32_003A2A38(o + 0x1C0, &v, 2.0f, 2.0f, ft * 0.2f, 0xBDFDFF, 0x7F7FFF, 0x7F, 0x7F, 0.75f);
    }
    v = *(V_003A3038 *)(o + 0x1C0);
    v.y += 0.2f;
    v.z += D_L32_001DE880;
    off = ft * D_L32_001DE86C;
    if (o[0x1F9] == 1 || o[0x1F9] == 3) {
        v.x = *(f32 *)(o + 0x1C0) + off;
        *(vu0_q *)&w = 0;
        w.x = -1.0f;
        func_L32_003A2E30(arg0, &v, &w, D_L32_001DE85C, D_L32_001DE84C, D_L32_001DE850,
                          D_L32_001DE878, D_L32_001DE858, 0xFF);
        v.x += D_L32_001DE87C;
        func_L32_003A2A38(&v, &w, D_001E2228, D_001E222C, ft * D_L32_001DE7EC,
                          D_L32_001DE7D8, D_L32_001DE7DC, a, a, D_L32_001DE7E0);
    }
    if (o[0x1F9] == 1 || o[0x1F9] == 2) {
        v.x = *(f32 *)(o + 0x1C0) - off;
        *(vu0_q *)&w = 0;
        w.x = 1.0f;
        func_L32_003A2E30(arg0, &v, &w, D_L32_001DE85C, D_L32_001DE84C, D_L32_001DE850,
                          D_L32_001DE878, D_L32_001DE858, 0xFF);
        v.x -= D_L32_001DE87C;
        func_L32_003A2A38(&v, &w, D_001E2228, D_001E222C, ft * D_L32_001DE7EC,
                          D_L32_001DE7D8, D_L32_001DE7DC, a, a, D_L32_001DE7E0);
    }
}
/* localdecomp:end func_L32_003A3038 */

/* localdecomp:start func_L32_003A3310 */
typedef struct {
    u8 pad0[8];
    f32 f8;
    u8 padC[6];
    u8 b12;
    u8 b13;
    u8 b14;
    u8 b15;
    u8 b16;
    u8 b17;
    u8 b18;
    u8 b19;
    u8 b1A;
    u8 b1B;
    u8 b1C;
    u8 b1D;
    u8 b1E;
    u8 b1F;
    f32 f20;
    f32 f24;
    f32 f28;
    f32 f2C;
    f32 f30;
    s32 w34;
    s32 w38;
    u8 b3C;
    u8 pad3D[0xC];
    u8 b49;
    u8 pad4A[6];
} __attribute__((aligned(16))) S_003A3310;

extern f32 D_L32_001DE88C;
__asm__(".extern D_L32_001DE88C, 4");
extern f32 D_L32_001DE890;
__asm__(".extern D_L32_001DE890, 4");
extern f32 D_L32_001DE894;
__asm__(".extern D_L32_001DE894, 4");
extern s32 D_L32_001DE6E0;
__asm__(".extern D_L32_001DE6E0, 4");
extern u8 D_L32_001DE888;
__asm__(".extern D_L32_001DE888, 1");

extern s32 func_0011A264(void *, s32, s32);
typedef int u128_t_003A3310 __attribute__((mode(TI)));
extern u8 *func_L01_003006C0(u8 *, u128_t_003A3310 *, s32, u128_t_003A3310 *);

void func_L32_003A3310(u128_t_003A3310 *arg0) {
    S_003A3310 t;
    S_003A3310 s;

    func_0011A264(&s, 0, sizeof(s));
    s.f8 = 1.0f;
    s.b12 = 0xFF;
    s.b13 = 0x80;
    s.b14 = 0x80;
    s.b15 = 12;
    s.b17 = 100;
    s.b19 = 0x80;
    s.b1A = 12;
    s.b1C = 100;
    s.b1E = 0x80;
    s.b1F = 12;
    s.f20 = D_L32_001DE88C;
    s.f24 = D_L32_001DE890;
    s.f28 = D_L32_001DE894;
    s.f2C = 0.01f;
    s.f30 = 0.01f;
    s.w34 = D_L32_001DE6E0;
    s.w38 = 0x84440;
    s.b3C = 0xFF;
    s.b49 = D_L32_001DE888;
    t = s;
    func_L01_003006C0((u8 *)&t, arg0, 0, 0);
}
/* localdecomp:end func_L32_003A3310 */

INCLUDE_ASM("asm/levels", func_L32_003A3420);

INCLUDE_ASM("asm/levels", func_L32_003A3888);

/* localdecomp:start func_L32_003A3CA8 */
typedef struct V_003A3CA8 {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_003A3CA8;

extern f32 D_L32_001DE898;
__asm__(".extern D_L32_001DE898, 4");
extern f32 D_L32_001DE89C;
__asm__(".extern D_L32_001DE89C, 4");
extern s32 D_L32_001DE8A0;
__asm__(".extern D_L32_001DE8A0, 4");
extern f32 func_00382538(void);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern u8 *func_L01_004713C8(void *, void *, s32, u32, f32, f32, s32, s32, s32, f32, s32);

void func_L32_003A3CA8(void *arg0) {
    u8 *o = *(u8 **)((u8 *)arg0 + 0x68);
    s32 i;
    f32 ang;
    f32 r;
    f32 k;
    s32 n;
    u8 *p;
    V_003A3CA8 v;
    V_003A3CA8 w;

    for (i = 0; i < D_L32_001DE8A0; i++) {
        ang = func_00382538();
        r = func_003824E0(0.0f, D_L32_001DE898);
        qzero(&w);
        k = func_003824E0(D_L32_001DE89C * 0.5f, D_L32_001DE89C) * 0.020000001f;
        qzero(&v);
        w.z = (D_L32_001DE898 - r) * k;
        v.x = r * func_0038D098(ang);
        v.y = fabs_asm(r * func_0038D0B0(ang) * 0.6f) - 0.2f;
        vec_add_ab(&v, &v, o + 0x1C0);
        n = (func_00382498(10, 30) * 5 + 2) / 6;
        p = func_L01_004713C8(&v, &w, n, 0x804020, 210000.0f, 84000.0f, func_00382498(-2, -4), 0x7F,
                              0, 0.0f, 0);
        if (p != 0) {
            p[2] = D_L32_0021F918[23][0];
        }
    }
}
/* localdecomp:end func_L32_003A3CA8 */
