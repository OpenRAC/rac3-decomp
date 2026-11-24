#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;

/* localdecomp:start func_L05_0035D560 */
extern void func_L05_0035E050(s32);
extern void func_L05_0035DF68(s32);

void func_L05_0035D560(s32 a0) {
    u8 buf[448];
    func_L05_0035E050(a0);
    func_L05_0035DF68(a0);
}
/* localdecomp:end func_L05_0035D560 */

/* localdecomp:start func_L05_0035D590 */
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038D028(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CDF8(void *, void *, void *, f32);
extern void func_003C4098(void *, void *, void *, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_00382538(void);
extern s32 func_003D3CB0(Vec4 *a0, Vec4 *a1, s32 a2, u8 *a3, s32 t0);
extern void func_003D9508(void *, s32, u32, s32, f32, f32, f32);
extern void func_L05_0035DA38(vu0_v4 *, s32, u32, u32, f32, f32);
extern u8 D_L05_001D66B0[8];
__asm__(".extern D_L05_001D66B0, 16");
extern s32 D_L05_001EA6D8[];
extern vu0_v4 D_L05_00285A20[5];
__asm__(".extern D_L05_001DD770, 4");
extern vu0_v4 D_L05_001DD770[] __attribute__((section(".sdata")));
__asm__(".extern D_L05_001DD728, 4");
extern f32 D_L05_001DD728;
__asm__(".extern D_L05_001DD72C, 4");
extern f32 D_L05_001DD72C;
__asm__(".extern D_L05_001DD764, 4");
extern f32 D_L05_001DD764;
__asm__(".extern D_L05_001DD750, 4");
extern f32 D_L05_001DD750;
__asm__(".extern D_L05_001DD754, 4");
extern u32 D_L05_001DD754;
__asm__(".extern D_L05_001DD758, 4");
extern u32 D_L05_001DD758;
__asm__(".extern D_L05_001DD75C, 4");
extern f32 D_L05_001DD75C;

void func_L05_0035D590(u8 *obj) {
    u8 *d;
    s32 i;
    s32 w;
    f32 x;
    f32 r;
    vu0_v4 mat[4];
    vu0_v4 v40;
    vu0_v4 v50;
    vu0_v4 v60;
    vu0_v4 v70;
    vu0_v4 v80;
    vu0_v4 v90;
    vu0_v4 vA0;
    vu0_v4 vB0;
    vu0_v4 vC0;

    d = *(u8 **)(obj + 0x68);
    *(u32 *)(d + 0x3DC) = 0xFFFFFFFF;
    for (i = 0; i < 3; i++) {
        func_003C2EC0(obj, i + 1, mat);
        v90 = mat[3];
        func_0038D028(&vA0, &D_L05_001DD770[i], mat);
        vec_add_ab(&v90, &v90, &vA0);
        if ((*(long *)(obj + 0x40) & 0xFFFF0000) != 0x05050000) {
            return;
        }
        {
            u8 *o2 = *(u8 **)(d + 0x230);
            r = func_0038DBA0(*(f32 *)(obj + 0xF8),
                              func_0038D160(*(f32 *)(o2 + 0x10) - *(f32 *)(obj + 0x10),
                                            *(f32 *)(o2 + 0x14) - *(f32 *)(obj + 0x14)));
        }
        if (r < 0.17453292f) {
            x = ((f32)*(s32 *)(d + 0x2E0) - (D_L05_001DD72C * 5.0f + 2.0f) / 6.0f)
                / ((D_L05_001DD728 * 5.0f + 2.0f) / 6.0f);
            if (x < 0.0f) {
                x = 0.0f;
            }
            vC0 = *(vu0_v4 *)(d + 0x330);
            func_003C4098(&vB0, D_L05_001D66B0, &vC0, x);
            vec_sub_ba(&v80, d + 0x220, &v90);
            func_0038CF68(&v80, &v80, 35.0f);
            vec_add_ba(&v80, &v80, &vB0);
            vec_add_ab(&v70, &v80, &v90);
        } else {
            v90 = mat[3];
            func_0038CF68(&v80, &mat[1], -35.0f);
            vec_add_ab(&v70, &v80, &v90);
        }
        if (func_003D3CB0((Vec4 *)&v90, (Vec4 *)&v70, 0x10, obj, 0) != 0) {
            v70 = *(vu0_v4 *)(D_L05_001EA6D8 + 2);
            w = D_L05_001EA6D8[0];
            if (w != 0) {
                if (*(u32 *)(d + 0x3DC) == 0xFFFFFFFF) {
                    *(s32 *)(d + 0x3DC) = w;
                } else if (w == *(s32 *)(d + 0x3DC)) {
                    *(s32 *)(d + 0x3DC) = w;
                } else {
                    *(s32 *)(d + 0x3DC) = 0;
                }
                func_003D9508(D_L05_001EA6D8 + 2, 0x39, 0x4F2020FF, 1, 0.5f, 0.24f, func_00382538());
                func_003D9508(D_L05_001EA6D8 + 2, 0x31, 0x6F808080, 1, 0.25f, 0.24f, func_00382538());
            } else {
                *(s32 *)(d + 0x3DC) = 0;
                func_003D9508(D_L05_001EA6D8 + 2, 0x39, 0x3F2020FF, 1, 0.3f, 0.24f, func_00382538());
                func_003D9508(D_L05_001EA6D8 + 2, 0x31, 0x4F808080, 1, 0.2f, 0.24f, func_00382538());
            }
        }
        D_L05_00285A20[0] = v90;
        func_003D9508(D_L05_00285A20, 0x31, 0x153064FF, 1, 0.17f, 0.0f, D_L05_001DD764);
        func_0038CDF8(&v40, &v90, &v70, 0.05f);
        D_L05_00285A20[1] = v40;
        r = func_0038DAB8(D_L05_001DD764, 0.020943953f);
        D_L05_001DD764 = r;
        x = (func_0038D0B0(r) * 0.5f + 0.5f) * 0.45000002f + 0.1f;
        func_0038CDF8(&v50, &v90, &v70, x);
        D_L05_00285A20[2] = v50;
        func_0038CDF8(&v60, &v90, &v70, 0.66f);
        D_L05_00285A20[3] = v60;
        D_L05_00285A20[4] = v70;
        func_L05_0035DA38(D_L05_00285A20, 4, D_L05_001DD754, D_L05_001DD758, D_L05_001DD750, D_L05_001DD75C);
    }
    if (*(u32 *)(d + 0x3DC) == 0xFFFFFFFF) {
        *(s32 *)(d + 0x3DC) = 0;
    }
}
/* localdecomp:end func_L05_0035D590 */

/* localdecomp:start func_L05_0035DA38 */
/* The two first-segment colours are named locals of the loop body, declared after a's first call
 * there: loop.c then hoists both and reload spills them above &a.v[3] (0x184/0x188/0x18C($sp)). */
typedef struct { vu0_v4 v[4]; s32 c[4]; f32 uv[8]; long t70, t78, t80, t88; } Q_35DA38;
extern void func_003D93B0(void *, s32, s32, long);
extern void func_003D2DA0(void *, s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D028(void *, void *, void *);
extern vu0_v4 D_L05_001E2680;
extern u8 D_001A4EC0[];
__asm__(".extern D_L05_001DD754, 4");
extern u32 D_L05_001DD754;

void func_L05_0035DA38(vu0_v4 *p, s32 n, u32 col_a, u32 col_b, f32 s, f32 t) {
    Q_35DA38 a;
    Q_35DA38 b;
    vu0_v4 m[4];
    vu0_v4 ha;
    vu0_v4 hb;
    s32 i;

    func_003D93B0(&a, 0x1E, 1, 0x80);
    a.c[0] = a.c[1] = a.c[2] = a.c[3] = col_a;
    a.uv[0] = 0.0f;
    a.uv[1] = 0.0f;
    a.uv[2] = 0.0f;
    a.uv[3] = 1.0f;
    a.uv[4] = 1.0f;
    a.uv[5] = 0.0f;
    a.uv[6] = 1.0f;
    a.uv[7] = 1.0f;
    func_003D93B0(&b, 0x2B, 1, 0x80);
    b.c[0] = b.c[1] = b.c[2] = b.c[3] = col_b;
    b.uv[0] = 0.0f;
    b.uv[1] = 0.0f;
    b.uv[2] = 0.0f;
    b.uv[3] = 1.0f;
    b.uv[4] = 1.0f;
    b.uv[5] = 0.0f;
    b.uv[6] = 1.0f;
    b.uv[7] = 1.0f;
    m[3] = p[0];
    vec_sub_ab(&m[0], &D_L05_001E2680, &m[3]);
    func_0038CF68(&m[0], &m[0], 1.0f);
    func_0038CE90(&m[1], &m[0], D_001A4EC0);
    func_0038CF68(&m[1], &m[1], 1.0f);
    func_0038CE90(&m[2], &m[1], &m[0]);
    *(vu0_q *)&ha = 0;
    *(vu0_q *)&hb = 0;
    ha.w = 1.0f;
    ha.z = s;
    hb.z = s * t;
    hb.w = 1.0f;
    vec_sub_ab(&m[0], &p[1], &p[0]);
    func_0038CF68(&m[0], &m[0], 1.0f);
    vec_sub_ba(&m[1], &D_L05_001E2680, &p[0]);
    func_0038CE90(&m[2], &m[1], &m[0]);
    func_0038CF68(&m[2], &m[2], 1.0f);
    func_0038CE90(&m[1], &m[0], &m[2]);
    m[3] = p[0];
    a.v[0] = ha;
    func_0038CE20(&a.v[1], &a.v[0], -1.0f);
    func_0038D028(&a.v[0], &a.v[0], m);
    func_0038D028(&a.v[1], &a.v[1], m);
    b.v[0] = hb;
    func_0038CE20(&b.v[1], &b.v[0], -1.0f);
    func_0038D028(&b.v[0], &b.v[0], m);
    func_0038D028(&b.v[1], &b.v[1], m);
    for (i = 1; i < n + 1; i++) {
        a.v[2] = ha;
        func_0038CE20(&a.v[3], &a.v[2], -1.0f);
        {
            u32 ca = 0x303064FF;
            u32 cb = 0x0C3064FF;

            vec_sub_ab(&m[0], &p[i + 1], &p[i]);
            func_0038CF68(&m[0], &m[0], 1.0f);
            vec_sub_ab(&m[1], &D_L05_001E2680, &p[i]);
            func_0038CE90(&m[2], &m[1], &m[0]);
            func_0038CF68(&m[2], &m[2], 1.0f);
            func_0038CE90(&m[1], &m[0], &m[2]);
            m[3] = p[i];
            func_0038D028(&a.v[2], &a.v[2], m);
            func_0038D028(&a.v[3], &a.v[3], m);
            if (i == 1) {
                a.c[0] = ca;
                a.c[1] = ca;
            } else if (i == 2) {
                a.c[0] = D_L05_001DD754;
                a.c[1] = D_L05_001DD754;
                a.c[2] = 0x200000FF;
                a.c[3] = 0x200000FF;
            } else if (i == 3) {
                a.c[0] = 0x200000FF;
                a.c[1] = 0x200000FF;
                a.c[2] = 0x200000FF;
                a.c[3] = 0x200000FF;
            } else if (i == 4) {
                a.c[0] = 0x200000FF;
                a.c[1] = 0x200000FF;
                a.c[2] = D_L05_001DD754;
                a.c[3] = D_L05_001DD754;
            }
            func_003D2DA0(&a, 0, 0);
            a.v[0] = a.v[2];
            a.v[1] = a.v[3];
            b.v[2] = hb;
            func_0038CE20(&b.v[3], &b.v[2], -1.0f);
            func_0038D028(&b.v[2], &b.v[2], m);
            func_0038D028(&b.v[3], &b.v[3], m);
            if (i == 1) {
                b.c[0] = cb;
                b.c[1] = cb;
            } else if (i == 2) {
                b.c[0] = 0x0C0000FF;
                b.c[1] = 0x0C0000FF;
                b.c[2] = 0x040000FF;
                b.c[3] = 0x040000FF;
            } else if (i == 3) {
                b.c[0] = 0x040000FF;
                b.c[1] = 0x040000FF;
                b.c[2] = 0x040000FF;
                b.c[3] = 0x040000FF;
            } else if (i == 4) {
                b.c[0] = 0x040000FF;
                b.c[1] = 0x040000FF;
                b.c[2] = 0x0C0000FF;
                b.c[3] = 0x0C0000FF;
            }
            func_003D2DA0(&b, 0, 0);
            b.v[0] = b.v[2];
            b.v[1] = b.v[3];
        }
    }
}
/* localdecomp:end func_L05_0035DA38 */

/* localdecomp:start func_L05_0035DF68 */
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038D028(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern s32 func_L01_00447470_0035DF68(s32, s32, f32);
extern void func_003C5458(void *, s32, f32, f32);
extern vu0_v4 D_L05_001E2680;
__asm__(".extern D_L05_001DD7E0, 8");
extern u8 D_L05_001DD7E0[8];
__asm__(".extern D_L05_001DD7F0, 4");
extern f32 D_L05_001DD7F0;
__asm__(".extern D_L05_001DD7D0, 4");
extern s32 D_L05_001DD7D0;
__asm__(".extern D_L05_001DD7D8, 4");
extern f32 D_L05_001DD7D8;
__asm__(".extern D_L05_001DD7D4, 4");
extern f32 D_L05_001DD7D4;

void func_L05_0035DF68(s32 a0)
{
    vu0_v4 p;
    u8 m[0x40];
    vu0_v4 d;
    vu0_v4 n;
    f32 dot;

    func_003C2EC0((void *)a0, 0, m);
    func_0038D028(&p, D_L05_001DD7E0, m);
    vec_add_ba(&p, &p, m + 0x30);
    vec_sub_ab(&d, &D_L05_001E2680, &p);
    func_0038CF68(&d, &d, 1.0f);
    func_0038CF68(&n, m + 0x10, -1.0f);
    dot = func_0038CE68(&d, &n);
    if (D_L05_001DD7F0 < dot) {
        func_003C5458(&p, func_L01_00447470_0035DF68(D_L05_001DD7D0 & 0xFFFFFF, D_L05_001DD7D0, dot * dot), D_L05_001DD7D8, D_L05_001DD7D4);
    }
}
/* localdecomp:end func_L05_0035DF68 */

/* localdecomp:start func_L05_0035E050 */
extern void func_003C2F58(u8 *a0, s32 a1, u8 *a2);
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038D028(void *, void *, void *);
extern void func_003C5458(void *, s32, f32, f32);
__asm__(".extern D_L05_001DD838, 8");
extern s32 D_L05_001DD838[2];
__asm__(".extern D_L05_001DD810, 8");
extern u8 D_L05_001DD810[8];
__asm__(".extern D_L05_001DD830, 8");
extern s32 D_L05_001DD830[2];
__asm__(".extern D_L05_001DD800, 8");
extern f32 D_L05_001DD800[2];
__asm__(".extern D_L05_001DD7F8, 8");
extern f32 D_L05_001DD7F8[2];

void func_L05_0035E050(s32 a0)
{
    s32 i;
    vu0_v4 p;
    u8 m[0x40];
    vu0_v4 d;

    for (i = 0; i < 2; i++) {
        func_003C2F58((u8 *)a0, D_L05_001DD838[i], (u8 *)&p);
        func_003C2EC0((void *)a0, D_L05_001DD838[i], m);
        func_0038D028(&d, D_L05_001DD810 + i * 0x10, m);
        vec_add_ab(&p, &p, &d);
        func_003C5458(&p, D_L05_001DD830[i], D_L05_001DD800[i], D_L05_001DD7F8[i]);
    }
}
/* localdecomp:end func_L05_0035E050 */

/* localdecomp:start func_L05_0035E148 */
extern s32 D_L05_001EA6C0_0035E148[];
extern Vec4 D_L05_001EA6E0_0035E148;
extern s32 func_003D3CB0(Vec4 *a0, Vec4 *a1, s32 a2, u8 *a3, s32 t0);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CED8(void *);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038CF38(void *, void *);

void func_L05_0035E148(u8 *a0, f32 minLen) {
    Vec4 a;
    Vec4 b;
    Vec4 off;
    Vec4 dir;
    Vec4 tmp;
    u8 *s0;
    f32 ang;
    f32 yaw;
    f32 len;
    f32 r;
    f32 d;

    s0 = *(u8 **)(a0 + 0x68);
    *(u128_t *)(s0 + 0x2F0) = *(u128_t *)(s0 + 0x300);
    a.q = *(u128_t *)(a0 + 0x10);
    b.q = *(u128_t *)(s0 + 0x300);
    a.f[2] += *(f32 *)(s0 + 0x78);
    b.f[2] += *(f32 *)(s0 + 0x78);
    if (!func_003D3CB0(&a, &b, 16, a0, 0)) {
        return;
    }
    if (D_L05_001EA6C0_0035E148[6] != 0 && D_L05_001EA6C0_0035E148[6] == *(s32 *)(s0 + 0x230)) {
        return;
    }
    for (ang = 10.0f; ang <= 100.0f; ang += 10.0f) {
        vec_sub_ab(&dir, &b, &a);
        yaw = func_0038D160(dir.f[0], dir.f[1]);
        len = func_0038CED8(&dir);
        if (len < minLen) {
            len = minLen;
        }
        r = ang * 0.017453292f;
        off.f[0] = func_0038D098(func_0038DAB8(r, yaw)) * len;
        off.f[1] = func_0038D0B0(func_0038DAB8(r, yaw)) * len;
        off.f[2] = 0.0f;
        vec_add_ab(&off, &a, &off);
        if (off.f[0] < 0.0f) {
            off.f[0] = 0.5f;
        }
        if (off.f[1] < 0.0f) {
            off.f[1] = 0.5f;
        }
        if (off.f[2] < 0.0f) {
            off.f[2] = 0.5f;
        }
        if (!func_003D3CB0(&a, &off, 16, a0, 0)) {
            *(u128_t *)(s0 + 0x2F0) = off.q;
            return;
        }
        if (D_L05_001EA6C0_0035E148[6] != 0 && D_L05_001EA6C0_0035E148[6] == *(s32 *)(s0 + 0x230)) {
            *(u128_t *)(s0 + 0x2F0) = off.q;
        } else if (D_L05_001EA6C0_0035E148[6] != 0 && *(s16 *)(D_L05_001EA6C0_0035E148[6] + 0xAA) == *(s16 *)(a0 + 0xAA)) {
            *(u128_t *)(s0 + 0x2F0) = *(u128_t *)(s0 + 0x220);
            return;
        }
        vec_sub_ab(&tmp, a0 + 0x10, &D_L05_001EA6E0_0035E148);
        d = func_0038CED8(&tmp);
        if (*(f32 *)(s0 + 0x2E8) < d && ang < 60.0f) {
            if (func_0038CF38(&D_L05_001EA6E0_0035E148, s0 + 0x300) < func_0038CF38(s0 + 0x320, s0 + 0x300)) {
                *(f32 *)(s0 + 0x2E8) = d;
                *(u128_t *)(s0 + 0x320) = D_L05_001EA6E0_0035E148.q;
            }
        }
        r = -(ang * 0.017453292f);
        off.f[0] = func_0038D098(func_0038DAB8(r, yaw)) * len;
        off.f[1] = func_0038D0B0(func_0038DAB8(r, yaw)) * len;
        off.f[2] = 0.0f;
        vec_add_ab(&off, &a, &off);
        if (off.f[0] < 0.0f) {
            off.f[0] = 0.5f;
        }
        if (off.f[1] < 0.0f) {
            off.f[1] = 0.5f;
        }
        if (off.f[2] < 0.0f) {
            off.f[2] = 0.5f;
        }
        if (!func_003D3CB0(&a, &off, 16, a0, 0)) {
            *(u128_t *)(s0 + 0x2F0) = off.q;
            return;
        }
        if (D_L05_001EA6C0_0035E148[6] != 0 && D_L05_001EA6C0_0035E148[6] == *(s32 *)(s0 + 0x230)) {
            *(u128_t *)(s0 + 0x2F0) = off.q;
        } else if (D_L05_001EA6C0_0035E148[6] != 0 && *(s16 *)(D_L05_001EA6C0_0035E148[6] + 0xAA) == *(s16 *)(a0 + 0xAA)) {
            *(u128_t *)(s0 + 0x2F0) = *(u128_t *)(s0 + 0x220);
            return;
        }
        vec_sub_ab(&tmp, a0 + 0x10, &D_L05_001EA6E0_0035E148);
        d = func_0038CED8(&tmp);
        if (*(f32 *)(s0 + 0x2E8) < d && ang < 60.0f) {
            *(f32 *)(s0 + 0x2E8) = d;
            *(u128_t *)(s0 + 0x320) = D_L05_001EA6E0_0035E148.q;
        }
    }
}
/* localdecomp:end func_L05_0035E148 */

/* localdecomp:start func_L05_0035E5A8 */
extern s32 D_L05_001EA6D8[];
extern s32 func_003D3CB0(Vec4 *a0, Vec4 *a1, s32 a2, u8 *a3, s32 t0);
void func_L05_0035E5A8(u8 *a0) {
    Vec4 a;
    Vec4 b;
    u8 *s0;
    a.q = *(u128_t *)(a0 + 16);
    s0 = *(u8 **)(a0 + 104);
    b.q = *(u128_t *)(s0 + 768);
    a.f[2] += *(f32 *)(s0 + 120);
    b.f[2] += *(f32 *)(s0 + 120);
    if (!func_003D3CB0(&a, &b, 16, a0, 0) || (D_L05_001EA6D8[0] != 0 && D_L05_001EA6D8[0] == *(s32 *)(s0 + 560))) {
        *(u128_t *)(s0 + 784) = *(u128_t *)(s0 + 752) = *(u128_t *)(s0 + 768);
    }
}
/* localdecomp:end func_L05_0035E5A8 */

/* localdecomp:start func_L05_0035E640 */
extern s32 func_003D3CB0(Vec4 *a0, Vec4 *a1, s32 a2, u8 *a3, s32 t0);
extern s32 D_L05_001EA6D8[];
extern void func_003C2F58(u8 *a0, s32 a1, u8 *a2);
s32 func_L05_0035E640(u8 *a0) {
    u8 buf[16];
    u128_t q;
    u8 *s1;
    s32 d;
    s1 = *(u8 **)(a0 + 104);
    func_003C2F58(a0, 6, buf);
    q = *(u128_t *)(s1 + 544);
    if (((s32 (*)(u8 *a0, u128_t *a1, s32 a2, u8 *a3, s32 t0))func_003D3CB0)(buf, &q, 16, a0, 0) == 0) {
        return 1;
    }
    d = D_L05_001EA6D8[0];
    if (d != 0) {
        if (d == *(s32 *)(s1 + 560)) {
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L05_0035E640 */

/* localdecomp:start func_L05_0035E6C8 */
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_003C3D30(void *, s32, s32, f32);

s32 func_L05_0035E6C8(u8 *a0) {
    u8 *m;
    vu0_v4 p;
    vu0_v4 d;
    f32 h;

    p = *(vu0_v4 *)(a0 + 0x10);
    m = *(u8 **)(a0 + 0x68);
    d.x = func_0038D098(*(f32 *)(a0 + 0xF8)) * 0.1f;
    d.y = func_0038D0B0(*(f32 *)(a0 + 0xF8)) * 0.1f;
    d.z = 0.0f;
    vec_add_ab(&p, &p, &d);
    h = func_003C3D30(&p, 0, 0, 0.5f);
    if (h < *(f32 *)(a0 + 0x18)) {
        if (fabs_asm(h - *(f32 *)(a0 + 0x18)) > *(f32 *)(m + 0x7C)) {
            d.x = func_0038D098(*(f32 *)(a0 + 0xF8)) * 3.0f;
            d.y = func_0038D0B0(*(f32 *)(a0 + 0xF8)) * 3.0f;
            d.z = 0.0f;
            vec_add_ab(&p, a0 + 0x10, &d);
            h = func_003C3D30(&p, 0, 0, 1.0f);
            if (*(f32 *)(a0 + 0x18) - 5.0f < h) {
                *(f32 *)(m + 0x3AC) = h;
                return 1;
            }
            return 2;
        }
    }
    return 0;
}
/* localdecomp:end func_L05_0035E6C8 */

/* localdecomp:start func_L05_0035E820 */
extern u8 *D_L05_001DFC80;
extern f32 func_0038CF38(void *, void *);

void func_L05_0035E820(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    s32 *q = (s32 *)(s + 0x3C0);
    s32 *p;
    f32 best;
    s32 i;
    s32 *e = q + *(s32 *)(s + 0x3D4);
    best = func_0038CF38(D_L05_001DFC80 + (*e << 7) + 0x30, s + 0x220);
    for (i = 0, p = q; i < 4; i++) {
        s32 t = *p++;
        if (t != -1) {
            if (best < func_0038CF38(D_L05_001DFC80 + (t << 7) + 0x30, s + 0x220)) {
                *(s32 *)(s + 0x3D4) = i;
            }
        }
    }
}
/* localdecomp:end func_L05_0035E820 */

/* localdecomp:start func_L05_0035E8F0 */
typedef struct { s32 mask; s32 bits; s32 hit; f32 time; } E_0035E8F0;
typedef struct { s32 pad[0x90 / 4]; E_0035E8F0 e[8]; } Q_0035E8F0;
extern void func_L01_004450F0(void *, s32, s32);
extern u8 *func_L01_00447490(void *, s32, s32);
extern f32 func_L01_004474E8(void *, void *);
extern s32 func_L01_003FB640(void *, f32, s32, void *);
extern s32 func_L05_003F88B0(void);
extern void func_003C4A40(void *, void *);
extern void func_L01_0044BB30(void *, void *, s32, f32, f32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00451FE0(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern void func_L04_00325460(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, s32, s32, s32, s32);
extern void func_003C2880(void *);
extern void func_L01_0044ABD0(void *, void *);

void func_L05_0035E8F0(u8 *a0)
{
    u8 *q = *(u8 **)(a0 + 0x68);
    Q_0035E8F0 *s = (Q_0035E8F0 *)q;
    u8 *t;
    f32 f;
    s32 sh;
    s32 i;
    s32 j;
    s32 bit;
    vu0_v4 v;

    switch (a0[0x20]) {
    case 0:
        *(s32 *)(a0 + 0x9C) = 0;
        *(u16 *)(a0 + 0x7C) = 0;
        for (i = 0; i < q[0x80]; i++) {
            if (s->e[i].mask != 0 && 0.0f < s->e[i].time)
                *(u16 *)(a0 + 0x7C) |= 1 << i;
        }
        if (q[0x84] != 0)
            *(u16 *)(a0 + 0x34) |= 0x8000;
        func_L01_004450F0(a0, 1, -1);
        break;
    case 1:
        t = func_L01_00447490(a0, -1, 0);
        f = func_L01_004474E8(a0, t);
        if (t != 0 && f != 0.0f) {
            sh = -1;
            if (func_L01_003FB640(t, 0.1f, 1, *(void **)(t + 0x20)))
                sh = func_L05_003F88B0();
            for (j = 0; j < q[0x80]; j++) {
                if (!((s->e[j].mask >> sh) & 1))
                    continue;
                if (s->e[j].hit & *(u16 *)(a0 + 0x7C))
                    continue;
                func_003C4A40(a0, q + 0x70);
                s->e[j].time -= *(f32 *)(t + 0x2C);
                if (s->e[j].time <= 0.0f) {
                    s->e[j].time = 0.0f;
                    *(s32 *)(a0 + 0x9C) |= s->e[j].bits;
                    func_L01_0044BB30(a0, t, -1, 0.5f, 13.0f);
                    if ((s8)q[0x82] != -1)
                        func_003A52A0((s8)q[0x82], 0, a0);
                    func_0038CF68(&v, t + 0x10, 0.080000006f);
                    bit = 1 << j;
                    func_L01_00451FE0(a0, bit, &v, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
                    *(u16 *)(a0 + 0x7C) &= ~bit;
                    while (q[0x80] != 0 && s->e[q[0x80] - 1].time == 0.0f)
                        q[0x80]--;
                }
                a0[0xA8] = 0xFF;
                break;
            }
        }
        a0[0xA8] = 0xFF;
        if (q[0x80] == 0 && q[0x83] != 0) {
            if ((s8)q[0x81] != -1)
                func_003A52A0((s8)q[0x81], 0, a0);
            func_L04_00325460(a0 + 0x10, 1, 0x19, 0x14, 0x14, 0x14, 0x2D, 1, 1.0f, 20.0f, 1, 1, 0, 0);
            func_003C2880(a0);
            return;
        }
        break;
    case 2:
        break;
    }
    func_L01_0044ABD0(a0, q + 0x70);
}
/* localdecomp:end func_L05_0035E8F0 */
