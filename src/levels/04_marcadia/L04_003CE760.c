#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L04_003CE760 */
extern void func_003C3A10(u8 *, s32, s32, s32);

void func_L04_003CE760(u8 *a0, s32 a1, s32 a2, s32 a3) {
    u8 *s3 = *(u8 **)(a0 + 0x68);
    if (a0[67] != a1) {
        func_003C3A10(a0, a1, a2, a3);
        func_003C3A10(*(u8 **)(s3 + 0x300), a1, a2, a3);
    }
}
/* localdecomp:end func_L04_003CE760 */

/* localdecomp:start func_L04_003CE7C8 */
typedef struct { u8 pad[0x50]; f32 f50; u8 pad2[0x9C]; } T_3CE7C8;
__asm__(".extern D_L04_001DFD9C, 4");
extern u8 *D_L04_001DFD9C;
extern s32 D_L04_001DF940;
extern u8 D_001425C0[];
extern T_3CE7C8 D_L04_002C5F40[];
extern u8 D_001A4C60[];
extern void func_L01_0044ABD0(void *, void *);
extern u8 *func_L01_00447490(void *, s32, s32);
extern s32 func_0038CB00(void *);
extern f32 func_L01_004474E8(void *, void *);
extern void func_L01_00455E18(void *, void *, void *);
extern f32 func_L01_004510F8(void *, void *, s32);
extern void func_L01_00451048(void *, void *, void *, s32, f32);
extern void func_0038CE20(f32 *, void *, f32);
extern s32 func_L04_003CEC40(void *, void *, void *, s32);
extern void func_L01_004450F0(void *, s32, s32);

s32 func_L04_003CE7C8(u8 *obj, u8 *r, s32 flag) {
    s32 lvl = 0;
    u8 *s;
    u8 *h;
    u8 *t21;
    u8 *hit;
    f32 dmg;
    f32 base;
    f32 hp;
    s32 thr;
    f32 dir[4];

    if (!(*(u16 *)(obj + 0x34) & 0x20)) {
        return 0;
    }
    s = *(u8 **)(obj + 0x68);
    h = *(u8 **)s;
    t21 = *(u8 **)(s + 0x20);
    if (r == 0) {
        return 0;
    }
    if (h == 0) {
        return 0;
    }
    func_L01_0044ABD0(obj, r);
    base = 0.0f;
    hit = func_L01_00447490(obj, 1, 0);
    if (func_0038CB00(h + 6) == 0) {
        hit = 0;
    }
    if (hit != 0) {
        base = *(f32 *)(hit + 0x2C);
        if (*(f32 *)(r + 0xA8) != 0.0f && *(u8 **)(hit + 0x20) != 0
            && *(s16 *)(obj + 0xAA) == *(s16 *)(*(u8 **)(hit + 0x20) + 0xAA)) {
            *(f32 *)(hit + 0x2C) = base * *(f32 *)(r + 0xA8);
        }
        if (flag != 0) {
            *(f32 *)(hit + 0x2C) = *(f32 *)(hit + 0x2C) * *(f32 *)(r + 0xAC);
        }
    }
    dmg = func_L01_004474E8(obj, hit);
    obj[0xA8] = 0xFF;
    *(f32 *)h = *(f32 *)h - dmg;
    if (t21 != 0) {
        func_L01_00455E18(obj, t21, h);
    }
    if (dmg == 0.0f) {
        return 0;
    }
    *(s16 *)(r + 0x70) = -1;
    if (hit != 0 && *(u8 **)(hit + 0x20) != 0) {
        *(s16 *)(r + 0x70) = (*(u8 **)(hit + 0x20) - D_L04_001DFD9C) >> 8;
    }
    {
        s32 ix = h[0x17];
        f32 k = ((T_3CE7C8 *)(D_001425C0[ix] * 0xF0 + (u8 *)D_L04_002C5F40))->f50;
        thr = 300;
        hp = (f32)*(s16 *)(h + 4) * *(f32 *)(r + 0x58);
        if (hp <= dmg * k) {
            thr = 90;
        }
    }
    if (r[0x77] == 0 && (thr * 5 + 2) / 6 < abs_asm(D_L04_001DF940 - *(s32 *)(r + 0x44)) && dmg < hp) {
        dmg = hp;
    }
    if (*(f32 *)h <= 0.0f) {
        lvl = 4;
    } else if ((f32)(s16)*(u16 *)(h + 4) * *(f32 *)(r + 0x5C) <= dmg) {
        lvl = 3;
    } else if ((f32)(s16)*(u16 *)(h + 4) * *(f32 *)(r + 0x58) <= dmg) {
        lvl = 2;
    } else if (dmg != 0.0f && r[0x77] == 0 && hit != 0 && *(u8 **)(hit + 0x20) != 0
               && *(s16 *)(*(u8 **)(hit + 0x20) + 0xAA) == 0x47) {
        lvl = 2;
    } else if (base != 0.0f) {
        lvl = 1;
    }
    if (flag != 0 && (u32)(lvl - 1) <= 2) {
        lvl = 6;
    }
    if (lvl >= 2 && hit != 0 && h[0x17] == 9) {
        f32 f = func_L01_004510F8(obj, hit + 0x10, 0);
        vec_sub_ab(hit + 0x10, obj + 0x10, D_001A4C60);
        func_L01_00451048(obj, hit + 0x10, hit + 0x10, 0, f);
    }
    if (lvl == 0) {
        return 0;
    }
    if (*(u16 *)(r + 0x38) & 3) {
        return 0;
    }
    if (obj[0x95] == r[0x48] && lvl < 4) {
        if (r[0x75] != 0) {
            return 0;
        }
        if (r[0x1A] < 2) {
            return 0;
        }
    }
    if (hit != 0 && (*(s32 *)(hit + 0x30) & 1)) {
        *(vu0_q *)dir = *(vu0_q *)(hit + 0x10);
    } else {
        func_0038CE20(dir, obj + 0xC0, -1.0f);
        dir[2] = 1.0f;
        dir[3] = 5627.925f;
    }
    if (func_L04_003CEC40(obj, r, dir, lvl) != 0) {
        *(s32 *)(r + 0x44) = D_L04_001DF940;
        if (r[0x48] != 0xFF) {
            func_L01_004450F0(obj, r[0x10], r[0x48]);
        } else {
            func_L01_004450F0(obj, r[0x10], -1);
        }
        r[0x1A] = 0;
    }
    return lvl;
}
/* localdecomp:end func_L04_003CE7C8 */

/* localdecomp:start func_L04_003CEC40 */
__asm__(".extern D_L04_001D673C, 4");
extern s32 D_L04_001D673C;
extern void func_003C4A40(void *, void *);
extern f32 func_003C50E8(void *, void *, s32);
extern void func_003C5180(void *, void *, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_003C4E80(void *, void *);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038CEA8(void *);
extern void func_0038CE20(f32 *, void *, f32);
extern s32 func_003C6368(void *, f32 *, f32 *, f32, f32, f32);
extern f32 func_0038CED8(void *);
extern void func_0038CFB8(void *, void *, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);

s32 func_L04_003CEC40(void *a0, void *a1, void *a2, s32 lvl) {
    u8 *obj = a0;
    u8 *r = a1;
    f32 *dir = a2;
    vu0_v4 v0;
    vu0_v4 v1;
    vu0_v4 v2;
    f32 m;
    f32 k;
    f32 f;
    f32 neg = -1.0f;
    f32 s24 = *(f32 *)(r + 0x24);
    f32 s28 = *(f32 *)(r + 0x28);
    f32 s1c = *(f32 *)(r + 0x1C);
    f32 s20 = *(f32 *)(r + 0x20);
    f32 s2c = *(f32 *)(r + 0x2C);

    switch (lvl) {
    case 1:
    case 2:
    case 3:
    case 6:
    default:
        r[7] = 0xFF;
        break;
    case 4:
        r[7] = 0xFF;
        *(u16 *)(r + 0x38) |= 1;
        *(s32 *)(obj + 0x98) = 0;
        *(u16 *)(obj + 0x34) &= 0xEFFF;
        break;
    case 5:
        r[7] = 0xFF;
        *(u16 *)(r + 0x38) |= 2;
        *(s32 *)(obj + 0x98) = 0;
        *(u16 *)(obj + 0x34) &= 0xEFFF;
        break;
    }
    func_003C4A40(obj, r);
    if (lvl != 1) {
        if (D_L04_001D673C != 0) {
            k = 1.0f;
            m = func_003C50E8(obj, dir, 0);
            if (m < k)
                m = k;
            func_003C5180(obj + 0x10, &v0, 0);
            func_0038CF68(&v2, dir, -1.0f);
            func_003C4E80(&v2, r + 0x64);
            f = func_0038CE68(&v0, dir);
            func_0038CF68(&v1, &v0, f);
            vec_sub_ab(dir, dir, &v1);
            if (func_0038CEA8(dir) < k)
                func_0038CF68(dir, dir, k);
            func_0038CE20((f32 *)(r + 0x80), dir, s1c);
            func_0038CF68(&v1, &v0, -s20 * m);
            vec_add_ab(r + 0x80, r + 0x80, &v1);
        } else {
            m = 1.0f;
            func_003C6368(obj, dir, dir, 5.0f, 0.7853982f, 4.0f);
            if (func_0038CED8(dir) < m)
                func_0038CFB8(dir, dir, m);
            if (dir[2] < m)
                dir[2] = m;
            *(f32 *)(r + 0x80) = dir[0] * s1c;
            *(f32 *)(r + 0x84) = dir[1] * s1c;
            *(f32 *)(r + 0x88) = dir[2] * s20;
            *(f32 *)(r + 0x64) = func_0038DAB8(func_0038D160(dir[0], dir[1]), 3.14159f);
        }
        if (r[0x76] != 0 && lvl < 4) {
            *(f32 *)(r + 0x4C) = 0.0f;
            *(f32 *)(r + 0x50) = 0.0f;
            *(f32 *)(r + 0x54) = -1.0f;
            *(f32 *)(r + 0x60) = -1.0f;
        } else {
            *(f32 *)(r + 0x54) = neg;
            *(f32 *)(r + 0x60) = neg;
            *(f32 *)(r + 0x4C) = s24;
            *(f32 *)(r + 0x50) = s28;
            *(f32 *)(r + 0x2C) = s2c;
        }
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L04_003CEC40 */

/* localdecomp:start func_L04_003CEF60 */
extern u8 D_001A4BE0[];
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038CED8(void *);
extern void func_003C4360(f32 *, f32, f32, f32, f32);
extern f32 func_003C3D30(void *, s32, void *, f32);

void func_L04_003CEF60(u8 *obj, u8 *q) {
    vu0_v4 t;
    vu0_v4 d;
    vu0_v4 u;
    vu0_v4 n;
    f32 x;
    f32 old;
    f32 l;
    u8 *h;

    t.x = func_0038D098(*(f32 *)(q + 0x318)) * *(f32 *)(q + 0x31C);
    t.y = func_0038D0B0(*(f32 *)(q + 0x318)) * *(f32 *)(q + 0x31C);
    t.z = 0.0f;
    vec_add_ab(&t, &t, q + 0x2D0);
    old = *(f32 *)(q + 0x118);
    vec_sub_ab(&d, &t, obj + 0x10);
    *(f32 *)(q + 0x118) = 0.0f;
    d.z = 0.0f;
    func_0038CF68(&u, &d, 1.0f);
    func_0038CE90(&n, &u, obj + 0xE0);
    func_0038CF68(&n, &n, 1.0f);
    x = func_0038CE68(&n, q + 0x110);
    if (0.0016000001f < x) {
        x = 0.0016000001f;
    } else if (x < -0.0016000001f) {
        x = -0.0016000001f;
    }
    func_0038CF68(&n, &n, x);
    vec_sub_ba(q + 0x110, q + 0x110, &n);
    l = func_0038CED8(&d);
    x = func_0038CED8(q + 0x110);
    func_003C4360(&x, l, 0.0032000002f, 0.0016000001f, 0.14000001f);
    func_0038CF68(&u, &d, 0.0032000002f);
    vec_add_ab(q + 0x110, q + 0x110, &u);
    if (x < func_0038CED8(q + 0x110)) {
        func_0038CF68(q + 0x110, q + 0x110, x);
    }
    if (obj[0x20] == 0x12) {
        *(f32 *)(q + 0x118) = old + 0.040000003f;
        if (-0.10000001f < *(f32 *)(q + 0x118))
            *(f32 *)(q + 0x118) = -0.10000001f;
    } else {
        *(f32 *)(q + 0x118) = old;
        h = D_001A4BE0;
        if (*(s32 *)(h + 0x25C4) == 0xB0 && fabs_asm(*(f32 *)(h + 0x88) - *(f32 *)(obj + 0x18)) < 2.25f) {
            if (*(f32 *)(obj + 0x18) < *(f32 *)(h + 0x88)) {
                *(f32 *)(q + 0x118) = old - 0.020000001f;
                if (*(f32 *)(q + 0x118) < -0.26000002f)
                    *(f32 *)(q + 0x118) = -0.26000002f;
            } else {
                *(f32 *)(q + 0x118) = old + 0.020000001f;
                if (-0.18f < *(f32 *)(q + 0x118))
                    *(f32 *)(q + 0x118) = -0.18f;
            }
        } else {
            *(f32 *)(q + 0x118) = *(f32 *)(q + 0x118) - 0.020000001f;
            if (*(f32 *)(q + 0x118) < -0.22000001f)
                *(f32 *)(q + 0x118) = -0.22000001f;
        }
    }
    vec_add_ba(obj + 0x10, obj + 0x10, q + 0x110);
    *(f32 *)(q + 0x100) = func_003C3D30(obj + 0x10, 0, 0, 0.5f);
}
/* localdecomp:end func_L04_003CEF60 */

/* localdecomp:start func_L04_003CF2B8 */
extern void func_0038CC88(void *, void *, s32);
extern f32 func_00382538(void);
extern void func_0038D328(void *, void *);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_003D9740(void *, s32, f32, s32, s32, s32);
extern void func_003C2F58(void *, s32, void *);
extern f32 func_003824E0(f32, f32);

void func_L04_003CF2B8(u8 *obj) {
    vu0_v4 r;
    vu0_v4 a;
    vu0_v4 p;
    vu0_v4 m1[4];
    vu0_v4 m2[4];
    vu0_v4 m3[4];
    u8 *v = *(u8 **)(obj + 0x68);
    f32 t;
    f32 k0;
    f32 k1;
    s32 i;
    s32 col;

    func_0038CE20((f32 *)&a, obj + 0xC0, -0.1f);
    a.z = a.z - 0.15f;
    qzero(&r);
    r.z = func_00382538();
    func_0038D328(m1, &r);
    func_0038CC88(m2, m1, 0x40);
    func_0038CC88(m3, m1, 0x40);
    if (obj[0x20] == 0x13) {
        if (*(s32 *)(v + 0x2F4) >= 6)
            return;
        t = (f32)*(s32 *)(v + 0x2F4) / 5.0f;
        k1 = 1.0f - t * 0.5f;
        k0 = 1.0f - t * 0.9f;
        func_0038CE20((f32 *)&m1[0], &m1[0], func_003824E0(0.9f, 1.1f) * 0.55f * k0);
        func_0038CE20((f32 *)&m1[1], &m1[1], func_003824E0(0.9f, 1.1f) * 0.55f * k0);
        func_0038CE20((f32 *)&m1[2], &m1[2], func_003824E0(0.8f, 1.2f) * 0.45f * k1);
        func_0038CE20((f32 *)&m2[0], &m2[0], func_003824E0(0.9f, 1.1f) * 0.3f * k0);
        func_0038CE20((f32 *)&m2[1], &m2[1], func_003824E0(0.9f, 1.1f) * 0.3f * k0);
        func_0038CE20((f32 *)&m2[2], &m2[2], func_003824E0(0.8f, 1.2f) * 0.9f * k1);
        func_0038CE20((f32 *)&m3[0], &m3[0], func_003824E0(0.9f, 1.1f) * 0.15f * k0);
        func_0038CE20((f32 *)&m3[1], &m3[1], func_003824E0(0.9f, 1.1f) * 0.15f * k0);
        func_0038CE20((f32 *)&m3[2], &m3[2], func_003824E0(0.8f, 1.2f) * k1);
    } else {
        func_0038CE20((f32 *)&m1[0], &m1[0], func_003824E0(0.9f, 1.1f) * 0.55f);
        func_0038CE20((f32 *)&m1[1], &m1[1], func_003824E0(0.9f, 1.1f) * 0.55f);
        func_0038CE20((f32 *)&m1[2], &m1[2], func_003824E0(0.8f, 1.2f) * 0.45f);
        func_0038CE20((f32 *)&m2[0], &m2[0], func_003824E0(0.9f, 1.1f) * 0.3f);
        func_0038CE20((f32 *)&m2[1], &m2[1], func_003824E0(0.9f, 1.1f) * 0.3f);
        func_0038CE20((f32 *)&m2[2], &m2[2], func_003824E0(0.8f, 1.2f) * 0.9f);
        func_0038CE20((f32 *)&m3[0], &m3[0], func_003824E0(0.9f, 1.1f) * 0.15f);
        func_0038CE20((f32 *)&m3[1], &m3[1], func_003824E0(0.9f, 1.1f) * 0.15f);
        func_0038CE20((f32 *)&m3[2], &m3[2], func_003824E0(0.8f, 1.2f));
    }
    for (i = 0; i < 2; i++) {
        func_003C2F58(obj, i + 1, &p);
        vec_sub_ab(&m1[3], &p, &m1[2]);
        vec_add_ab(&m1[3], &m1[3], &a);
        func_003D9740(m1, 0x1E, 0.0f, 0x7F00307F, 5, 1);
        vec_sub_ab(&m2[3], &p, &m2[2]);
        vec_add_ab(&m2[3], &m2[3], &a);
        func_003D9740(m2, 0x1E, 0.0f, 0x7F00607F, 5, 1);
        vec_sub_ab(&m3[3], &p, &m3[2]);
        vec_add_ab(&m3[3], &m3[3], &a);
        func_003D9740(m3, 0x1E, 0.0f, 0x7F00307F, 6, 1);
    }
    if (obj[0x20] == 0x11) {
        if (*(s32 *)(v + 0x2F4) >= 13)
            return;
        t = (f32)*(s32 *)(v + 0x2F4) / 12.0f;
        k0 = t * -0.70000005f + 1.2f;
        k1 = t * 1.6f + 0.15f;
        func_0038CF68(&m1[0], &m1[0], k0 * func_003824E0(0.95f, 1.05f));
        func_0038CF68(&m1[1], &m1[1], k0 * func_003824E0(0.95f, 1.05f));
        func_0038CF68(&m1[2], &m1[2], k1 * func_003824E0(0.95f, 1.05f));
        if (t < 0.8f)
            col = 0x7F20307F;
        else
            col = func_0038DBD8(0x7F20307F, 0x7F000000, (t - 0.8f) * 5.0f);
        for (i = 0; i < 2; i++) {
            func_003C2F58(obj, i + 1, &p);
            vec_sub_ab(&m1[3], &p, &m1[2]);
            vec_add_ab(&m1[3], &m1[3], &a);
            func_003D9740(m1, 0x1E, 0.0f, col, 4, 1);
        }
    }
}
/* localdecomp:end func_L04_003CF2B8 */
