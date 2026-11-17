#include "common.h"
#include "vu0.h"

typedef struct {
    u8 pad00[0x7C];
    u16 x7C;
} Obj_003B2B90;

extern void func_L19_003B2968(u8 *a0, s32 a1);
extern s32 func_00382468(s32);
extern s32 func_003A5348(s32, s32, s32);

/* localdecomp:start func_L19_003B1A80 */
typedef int u128_t_3B1A80 __attribute__((mode(TI)));
extern void func_L19_003B1A70();
extern void func_003C2C98(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_0040EE50(void *, void *);
extern void func_0038D000(void *, void *, void *);
extern f32 func_0038CEA8(void *);
extern void func_L01_0040E408(void *, void *, f32);
extern void func_L01_0043A430(void *, s32, void *);
extern void func_0038CE90(void *, void *, void *);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_003C2F58(u8 *a0, s32 a1, u8 *a2);
extern void func_L19_004044B0(void *, void *, void *);
extern s32 func_0038CB00(void *);
extern s32 func_0038CAD0(void *);
extern void func_L01_00404808(void *, void *);
extern void func_L19_003B2EA8(u8 *);
extern void func_L01_00451DF8(void *, void *, s32, s32, f32);
extern void func_003C7C38(void *);

void func_L19_003B1A80(u8 *obj) {
    vu0_v4 a;
    vu0_v4 m[3];
    vu0_v4 u;
    vu0_v4 b;
    vu0_v4 c;
    vu0_v4 d;
    vu0_v4 e;
    u8 *v = *(u8 **)(obj + 0x68);
    u8 *r;
    f32 f;

    *(vu0_v4 *)(*(u8 **)(v + 0x39C) + 0x10) = *(vu0_v4 *)(obj + 0x10);
    if (obj[0x95] == 5) {
        *(f32 *)(*(u8 **)(v + 0x39C) + 0x18) -= 1.29999995f;
        func_L19_003B1A70(obj);
        if (v[0x3D1] != 0)
            func_003C2C98(obj, v + 0x3D0);
        if (v[0x411] != 0)
            func_003C2C98(obj, v + 0x410);
        if (v[0x451] != 0)
            func_003C2C98(obj, v + 0x450);
    } else {
        r = v + 0x110;
        if (*(s16 *)(v + 0x3AE) == 0)
            func_0038CE20(r, r, 0.899999976f);
        func_L01_0040EE50(m, obj + 0xC0);
        func_0038D000(&a, r, m);
        f = func_0038CEA8(&a);
        if (0.001f < fabs_asm(f)) {
            func_L01_0040E408(&a, &a, f);
            if (v[0x3D1] == 0)
                func_L01_0043A430(obj, 0, v + 0x3D0);
            if (v[0x411] == 0)
                func_L01_0043A430(obj, 0xB, v + 0x410);
            if (v[0x451] == 0)
                func_L01_0043A430(obj, 4, v + 0x450);
            f = f * -2.32710552f;
            *(u128_t_3B1A80 *)&u = 0;
            u.z = 1.0f;
            func_0038CE90(&b, &a, &u);
            func_0038CE20(&c, &b, func_0038D0B0(f));
            c.w = func_0038D098(f);
            func_003C2F58(obj, 1, (u8 *)&d);
            func_0038CE20(&e, &d, -1.0f);
            func_L19_004044B0(&e, &e, &c);
            vec_add_ab(&e, &e, &d);
            f = f * -0.449999988f;
            *(vu0_v4 *)(v + 0x3E0) = c;
            *(vu0_v4 *)(v + 0x400) = e;
            func_0038CE20(&c, &b, func_0038D0B0(f));
            c.w = func_0038D098(f);
            *(vu0_v4 *)(v + 0x420) = c;
            *(vu0_v4 *)(v + 0x460) = c;
        } else {
            if (v[0x3D1] != 0)
                func_003C2C98(obj, v + 0x3D0);
            if (v[0x411] != 0)
                func_003C2C98(obj, v + 0x410);
            if (v[0x451] != 0)
                func_003C2C98(obj, v + 0x450);
        }
    }
    func_0038CB00(v + 0x3B0);
    func_0038CAD0(v + 0x38C);
    if (obj[0x95] != 5 && ((obj[0x34] ^ 1) & 1))
        func_L01_00404808(func_L19_003B2EA8, obj);
    if (((obj[0x34] ^ 1) & 1))
        func_L01_00451DF8(obj, v + 0x2C0, 5, 1, 2.5f);
    if (obj[0x95] != 4) {
        *(s32 *)(*(u8 **)(v + 0x39C) + 0x98) = *(s32 *)(*(u8 **)(*(u8 **)(v + 0x39C) + 0x24) + 0x10);
        func_003C7C38(*(u8 **)(v + 0x39C));
    }
    if (*(u16 *)(obj + 0x96) < 0xFFFF)
        *(u16 *)(obj + 0x96) = *(u16 *)(obj + 0x96) + 1;
}
/* localdecomp:end func_L19_003B1A80 */

/* localdecomp:start func_L19_003B1E08 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3B1E08;
extern u8 D_L19_001E2100[];
extern s32 D_L19_001DF758;
extern s32 D_L19_0021C260[];
extern s32 func_L19_003B1730(u8 *);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);
extern s32 func_L01_00452FB0(void *, void *, s32, s32, s32);
extern s32 func_003A52A0(s32, s32, u8 *);
extern void func_L19_003AFB40(u8 *obj, s32 mode);
extern void func_L01_00456230(void *, s32);
extern void func_L03_004330B8(s32, s32);
extern s32 func_L19_003B2C48(u8 *self, f32 a, f32 b, f32 c);
extern s32 func_00382468(s32);
extern s32 func_L19_003B2D00(u8 *obj);
extern void func_003C2880(void *);
extern void func_L01_004443E8(u8 *, s32, s32);
extern s32 func_L01_00452860(void *, void *, s32);
extern void func_L01_00456BD0(void *, s32);
extern void func_003C2F58(u8 *a0, s32 a1, u8 *a2);
extern void func_L01_00456C98(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);

s32 func_L19_003B1E08(u8 *obj) {
    u8 *v = *(u8 **)(obj + 0x68);
    V4_3B1E08 p;
    f32 hp;
    s32 n;
    s32 a;
    s32 k;

    if (obj[0x20] == 0 && func_L19_003B1730(obj) != 0)
        return 1;
    if (obj[0x95] == 5)
        *(f32 *)(v + 0x40) = 0.5f;
    else if (obj[0x42] == 6)
        *(f32 *)(v + 0x40) = 0.75f;
    else
        *(f32 *)(v + 0x40) = 2.0f;
    hp = *(f32 *)(v + 0x30);
    if (obj[0x31] != 0 && func_L01_0040E548(D_L19_001E2100, obj + 0x10) < 576.0f) {
        func_L01_004472C0(obj);
        obj[0x6F] = 0x16;
    }
    n = func_L01_00452FB0(obj, v + 0x160, 0, 0, 0);
    if (hp != *(f32 *)(v + 0x30)) {
        if (0.0f < *(f32 *)(v + 0x30)) {
            if (*(s16 *)(v + 0x3B2) == 0) {
                func_003A52A0(5, 0, obj);
                *(s16 *)(v + 0x3B2) = (*(s16 *)(v + 0x3B0) * 5 + 2) / 6;
            }
            if ((u32)n >= 2)
                func_L19_003AFB40(obj, 0);
        }
        func_L01_00456230(obj, 1);
        k = obj[0x21];
        if (k < D_L19_001DF758 && D_L19_0021C260[k] != 0)
            func_L03_004330B8(k, 1);
        func_L19_003B2C48(obj, hp, *(f32 *)(v + 0x30), *(s16 *)(v + 0x34));
        if (*(f32 *)(v + 0x30) <= 0.0f && obj[0x95] != 5 && func_00382468(100) <= *(s16 *)(v + 0x3A4))
            func_L19_003B2D00(obj);
    }
    if (v[0x60] != 0 || v[0x5E] != 0 || v[0x3E] == 2) {
        func_003C2880(*(void **)(v + 0x39C));
        func_L01_004443E8(obj, 0, 3);
        func_003C2880(obj);
        return 1;
    }
    func_L01_00452860(obj, v + 0x30, 0);
    if (v[0x5F] != 0) {
        a = 5;
        n = 3;
    } else {
        a = 3;
        n = 1;
    }
    if (((*(unsigned long *)(obj + 0x30) & 0x104100000000L) != 0x4100000000L || *(s32 *)(obj + 0x98) != 0)
        && 0.0f < *(f32 *)(v + 0x30))
        func_L01_00456BD0(obj, a);
    func_003C2F58(obj, 4, (u8 *)&p);
    if (obj[0x95] == 0)
        func_L01_00456C98(obj, *(s32 *)(v + 0x350), &p, 0, 0, 0, n, 0, 0, 0, *(f32 *)(v + 0x354), 10.0f, 1.0f);
    else
        func_L01_00456C98(obj, *(s32 *)(v + 0x358), &p, 0, 0, 0, n, 0, 0, 0, *(f32 *)(v + 0x35C), 10.0f, 1.0f);
    return 0;
}
/* localdecomp:end func_L19_003B1E08 */

typedef struct { f32 x, y, z, w; } V_3B2190 __attribute__((aligned(16)));
typedef struct { u8 pad[0x12]; s16 h12; u8 pad2[0x1C]; } E_3B2190;
typedef struct { u8 pad[0x20]; E_3B2190 e[1]; } T_3B2190;
typedef struct { u8 pad[0x30]; V_3B2190 v; u8 pad2[0x40]; } P_3B2190;

/* localdecomp:start func_L19_003B2190 */
extern T_3B2190 *D_L19_001DF34C;
extern P_3B2190 *D_L19_001DF800;
extern void func_L01_004450F0(void *, s32, s32);

void func_L19_003B2190(u8 *obj) {
    u8 *p = *(u8 **)(obj + 0x68);
    s32 st = 0x13;
    s32 a;
    s32 b;

    if (*(s32 *)(p + 0x360) != -1) {
        st = 0xE;
        if (*(s16 *)(p + 0x3AC) != 0)
            st = 0xF;
    } else {
        a = *(s32 *)(p + 0x36C);
        if (a != -1 && D_L19_001DF34C->e[a].h12 != 0) {
            st = 0x12;
        } else {
            b = *(s32 *)(p + 0x368);
            if (b != -1) {
                st = 0x11;
                *(V_3B2190 *)(p + 0x340) = D_L19_001DF800[b].v;
            } else if (*(s32 *)(p + 0x374) != 0) {
                *(V_3B2190 *)(p + 0x340) = *(V_3B2190 *)(obj + 0x10);
                st = 0x11;
            }
        }
    }
    if (*(s32 *)(p + 0x37C) != -1) {
        if (*(long *)(p + 0x360) == -1) {
            if (*(long *)(p + 0x368) == -1)
                st = 0x11;
        }
    }
    func_L01_004450F0(obj, st, 2);
    *(s32 *)(p + 0x398) = st;
}
/* localdecomp:end func_L19_003B2190 */

/* localdecomp:start func_L19_003B2290 */
typedef struct { f32 x, y, z, w; } V_3B2290 __attribute__((aligned(16)));
extern u8 *D_L19_001E8E58[];
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_0038CF68(void *, void *, f32);

s32 func_L19_003B2290(u8 *obj, f32 dz) {
    V_3B2290 a;
    V_3B2290 b;
    u8 *p = *(u8 **)(obj + 0x68);
    u8 *t;
    s32 r;

    a = *(V_3B2290 *)(obj + 0x10);
    a.z = a.z + dz;
    vec_sub_ba(&b, p + 0x220, &a);
    b.z = 0.0f;
    func_0038CF68(&b, &b, 3.0f);
    vec_add_ab(&b, &b, &a);
    if (func_003D3CB0(&a, &b, 0x10, obj, 0) == 0)
        return 1;
    t = D_L19_001E8E58[0];
    r = 0;
    if (t != 0 && (*(s16 *)(t + 0xAA) == 0x1AB8 || t == *(u8 **)(p + 0x230)))
        r = 1;
    return r;
}
/* localdecomp:end func_L19_003B2290 */

/* localdecomp:start func_L19_003B2370 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3B2370;
typedef struct { u8 pad[0x18]; u8 *x18; } H_3B2370;
extern H_3B2370 D_L19_001E8E40;
extern void func_0038CF68(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_003A52A0(s32, s32, u8 *);
extern void func_L01_00451FE0(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern void func_003C2880(void *);

static __inline__ V4_3B2370 vadd_3B2370(void *a, void *b) {
    V4_3B2370 r;
    vec_add_ab(&r, a, b);
    return r;
}

s32 func_L19_003B2370(u8 *obj) {
    V4_3B2370 a;
    V4_3B2370 b;
    V4_3B2370 c;
    V4_3B2370 e;
    V4_3B2370 h;
    u8 *xc0 = obj + 0xC0;
    V4_3B2370 *pa = &a;

    a = *(V4_3B2370 *)(obj + 0x10);
    a.z = a.z + *(f32 *)(*(u8 **)(obj + 0x68) + 0x74);
    b = *(V4_3B2370 *)xc0;
    b.z = 0.0f;
    func_0038CF68(&b, &b, 3.0f);
    vec_add_ab(&b, &b, &a);
    if (func_003D3CB0(pa, &b, 0x10, obj, 0) != 0 && D_L19_001E8E40.x18 != 0
        && *(s16 *)(D_L19_001E8E40.x18 + 0xAA) == 0x1CB7) {
        func_0038CE20(&c, xc0, 0.05f);
        func_0038CE20(&e, obj + 0xE0, 0.02f);
        h = vadd_3B2370(&c, &e);
        c = h;
        h = *(V4_3B2370 *)(D_L19_001E8E40.x18 + 0x10);
        h.z = h.z + 0.5f;
        func_003A52A0(0, 0, D_L19_001E8E40.x18);
        func_L01_00451FE0(D_L19_001E8E40.x18, 0xFF, &c, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
        func_003C2880(D_L19_001E8E40.x18);
    }
    return 1;
}
/* localdecomp:end func_L19_003B2370 */

/* localdecomp:start func_L19_003B2538 */
extern f32 func_L01_004395E0(void *);
extern void func_L01_00443B88(f32 *, f32, f32);
extern s32 func_L19_003B2880(u8 *obj);
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern u8 *func_L19_003D2788(void *, void *, void *, f32, s32);

s32 func_L19_003B2538(u8 *obj) {
    vu0_v4 f;
    vu0_v4 g;
    vu0_v4 e;
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 c[4];
    u8 *v;
    u8 *p;
    s32 t;
    s32 n;

    v = *(u8 **)(obj + 0x68);
    t = (s32)func_L01_004395E0(obj);
    if (*(s16 *)(v + 0x382) == 4) {
        if (t < 4 || t >= 12)
            return 1;
        *(s16 *)(v + 0x382) = 12;
        n = 3;
    } else {
        if (t < 12)
            return 1;
        *(s16 *)(v + 0x382) = 4;
        n = 2;
    }
    a = *(vu0_v4 *)(v + 0x220);
    p = *(u8 **)(v + 0x230);
    if (p != 0 && a.z + 5.0f < *(f32 *)(obj + 0x18))
        a = *(vu0_v4 *)(p + 0x10);
    if (func_00382468(4) == 0) {
        func_L01_00443B88(&b.x, 0.8f, 1.2f);
        if (func_00382468(2))
            b.x = -b.x;
        if (func_00382468(2))
            b.y = -b.y;
        vec_add_ab(&a, &a, &b);
    }
    if (func_L19_003B2880(obj) == 0)
        return 0;
    func_003C2EC0(obj, n, c);
    func_0038CE20(&e, &c[0], 0.1f);
    vec_add_ba(&f, &c[3], &e);
    vec_sub_ba(&g, &a, &f);
    func_0038CF68(&b, &g, 0.3f);
    vec_add_ab(&f, &b, &f);
    func_0038CF68(&g, &g, 0.3f);
    p = func_L19_003D2788(obj, &f, &g, *(u8 *)(v + 0x44), 0);
    if (p != 0)
        *(u8 **)(p + 0xB8) = obj;
    return 1;
}
/* localdecomp:end func_L19_003B2538 */

typedef struct { f32 x, y, z, w; } V_3B2748 __attribute__((aligned(16)));

/* localdecomp:start func_L19_003B2748 */
extern s32 func_L01_003303B8(V_3B2748 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003C2F58(u8 *a0, s32 a1, u8 *a2);
extern s32 func_003A52A0(s32, s32, u8 *);
extern void func_L05_00356018(u8 *);
extern void func_003C2880(void *);
extern void func_L01_004443E8(u8 *, s32, s32);

void func_L19_003B2748(u8 *obj) {
    u8 *p = *(u8 **)(obj + 0x68);
    V_3B2748 v;

    func_003C2F58(obj, 4, (u8 *)&v);
    func_L01_003303B8(&v, 0, 0x19, 0x14, 0x14, 0x14, 0x2D, 0, 1.0f, 0.0f, 0.0f, 0.0f,
        0, 0, 0, 0, 0, 0, 0x10000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
    func_003A52A0(0xB, 0, obj);
    func_L05_00356018(obj);
    func_003C2880(*(void **)(p + 0x39C));
    func_L19_003B2AC8(obj);
    func_L01_004443E8(obj, 0, 3);
}
/* localdecomp:end func_L19_003B2748 */

typedef struct { f32 x, y, z, w; } V_3B2880 __attribute__((aligned(16)));

/* localdecomp:start func_L19_003B2880 */
extern u8 *D_L19_001E8E58[];
extern void func_003C2F58(u8 *a0, s32 a1, u8 *a2);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);

s32 func_L19_003B2880(u8 *obj) {
    u8 *p = *(u8 **)(obj + 0x68);
    V_3B2880 a;
    V_3B2880 b;
    u8 *t;
    u8 *u;

    func_003C2F58(obj, 3, (u8 *)&a);
    func_003C2F58(obj, 2, (u8 *)&b);
    if (func_003D3CB0(&a, p + 0x220, 0, obj, 0) != 0) {
        t = D_L19_001E8E58[0];
        if (t != 0 && *(s16 *)(t + 0xAA) == 0x1AB8 && t != *(u8 **)(p + 0x230))
            return 0;
    }
    if (func_003D3CB0(&b, p + 0x220, 0, obj, 0) != 0) {
        u = D_L19_001E8E58[0];
        if (u != 0 && *(s16 *)(u + 0xAA) == 0x1AB8 && u != *(u8 **)(p + 0x230))
            return 0;
    }
    return 1;
}
/* localdecomp:end func_L19_003B2880 */

/* localdecomp:start func_L19_003B2968 */
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern u8 *func_L01_003F79D8(void *, s32, s32, s32, void *, void *, void *, s32, f32, f32, s32, s32, s32);
extern f32 D_L19_001E2098[];
extern void func_L01_002FFF00(void);

void func_L19_003B2968(u8 *obj, s32 idx) {
    f32 vec[3];
    f32 f20;
    f32 f21;
    u8 *r;
    s32 m = 1 << idx;

    if (*(u16 *)(obj + 0x7C) & m) {
        *(u16 *)(obj + 0x7C) &= ~m;
        f20 = func_0038DAB8(func_L01_00443A18(90.0f, 120.0f) * 0.017453292f, D_L19_001E2098[0]);
        f21 = func_003824E0(2.0f, 4.0f) * 0.020000001f;
        vec[0] = func_0038D098(f20) * f21;
        vec[1] = func_0038D0B0(f20) * f21;
        vec[2] = 0.0f;
        vec[2] = func_003824E0(5.0f, 8.0f) * 0.020000001f;
        r = func_L01_003F79D8(obj, 1, *(s16 *)(obj + 0xAA), idx, obj + 0x10, obj + 0xF0, vec, 0xFF, 90.0f, 15.0f, 0xB4, 0, 0x80);
        if (r != 0)
            *(void (**)(void))(r + 0x64) = func_L01_002FFF00;
    }
}
/* localdecomp:end func_L19_003B2968 */

/* localdecomp:start func_L19_003B2AC8 */
void func_L19_003B2AC8(u8 *a0)
{
    s32 i;
    u16 flags;

    flags = *(u16 *)(a0 + 0x7C);
    if (flags & 2) {
        *(u16 *)(a0 + 0x7C) = flags | 0x100;
    }
    for (i = 0; i < 16; i++) {
        func_L19_003B2968(a0, i);
    }
}
/* localdecomp:end func_L19_003B2AC8 */

/* localdecomp:start func_L19_003B2B28 */
void func_L19_003B2B28(void *a0)
{
    s32 i;
    s32 m = 1;

    for (i = 0; i < 16; i++) {
        if ((m & 0x701) == 0) {
            func_L19_003B2968(a0, i);
        }
        m <<= 1;
    }
}
/* localdecomp:end func_L19_003B2B28 */

/* localdecomp:start func_L19_003B2B90 */
void func_L19_003B2B90(u8 *self, s32 a1) {
    Obj_003B2B90 *o = (Obj_003B2B90 *)self;
    s32 n;
    s32 k;
    s32 bit;
    s32 r;

    r = func_00382468(a1);
    n = 0;
    k = r + 1;
    bit = 1;
    if (k != 0) {
        while (k != 0) {
            s32 t;
            bit <<= 1;
            t = k - 1;
            if (o->x7C & bit) {
                k = t;
            }
            n++;
            if (n == 2) {
                bit <<= 1;
                n = 3;
            }
        }
    }
    func_L19_003B2968(self, n);
    func_003A5348(7, 0, 0);
    if (n == 3) {
        func_L19_003B2968(self, 2);
    }
    if (n == 1) {
        o->x7C |= 0x100;
    }
}
/* localdecomp:end func_L19_003B2B90 */

/* localdecomp:start func_L19_003B2C48 */
extern void func_L19_003B2B90(u8 *, s32);

s32 func_L19_003B2C48(u8 *self, f32 a, f32 b, f32 c)
{
    s32 i;
    f32 k;
    f32 lo;

    if (self[0x95] == 5) {
        return 0;
    }
    k = c * 0.13333300f;
    lo = c - k;
    i = 6;
    do {
        if (lo <= a) {
            if (b < lo) {
                func_L19_003B2B90(self, i);
            }
        }
        i--;
        lo -= k;
    } while (i != 0);
    return 1;
}
/* localdecomp:end func_L19_003B2C48 */

/* localdecomp:start func_L19_003B2D00 */
extern void func_L01_004450F0(void *, s32, s32);

s32 func_L19_003B2D00(u8 *obj) {
    u8 *p = *(u8 **)(obj + 0x68);
    V_3B2748 v;

    func_L19_003B2B28(obj);
    func_L05_00356018(obj);
    *(u16 *)(obj + 0x7C) = 0x701;
    func_003C2F58(obj, 4, (u8 *)&v);
    func_L01_003303B8(&v, 0, 0x19, 0x14, 0x14, 0x14, 0x2D, 0, 1.0f, 0.0f, 0.0f, 0.0f,
        0, 0, 0, 0, 0, 0, 0x10000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
    func_003A52A0(0xB, 0, obj);
    *(s32 *)(p + 0xA8) &= ~0x10;
    *(s32 *)(obj + 0x98) = *(s32 *)(*(u8 **)(obj + 0x24) + 0x10);
    *(u16 *)(obj + 0x34) |= 0x1000;
    *(f32 *)(p + 0x30) = (f32)*(s16 *)(p + 0x34) * 0.1f;
    func_L01_004450F0(obj, 0x1E, 5);
    *(s32 *)(p + 0xA8) |= 1;
    obj[0xBF] = 15;
    *(f32 *)(p + 0x70) = 1.5f;
    return 1;
}
/* localdecomp:end func_L19_003B2D00 */

/* localdecomp:start func_L19_003B2EA8 */
extern void func_003C2F58(u8 *a0, s32 a1, u8 *a2);
extern void func_003D9508(void *p, s32 a, u32 color, s32 b, f32 f0, f32 f1, f32 f2);

void func_L19_003B2EA8(u8 *a0) {
    u8 buf[0x10];
    func_003C2F58(a0, 1, buf);
    func_003D9508(buf, 0x2E, 0x8080FFFF, 1, 0.45f, 0.0f, 0.0f);
    func_003D9508(buf, 0xC, 0x8020F020, 1, 0.45f, 0.0f, 0.0f);
}
/* localdecomp:end func_L19_003B2EA8 */
