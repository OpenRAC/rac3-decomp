#include "common.h"

/* localdecomp:start func_L39_00532550 */
#include "vu0.h"

__asm__(".extern D_L39_0024AD10, 8");
extern u8 D_L39_0024AD10[8];
extern f32 D_L39_0024ACE0;
__asm__(".extern D_L39_0024ACE0, 4");
extern vu0_q D_L39_0025F780;
extern vu0_v4 D_L39_00243F20_00532550 __attribute__((section(".sdata")));

extern void func_0038D000(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_0038CF68(void *, void *, f32);

void func_L39_00532550(u8 *a0) {
    u8 *o = *(u8 **)(a0 + 0x68);
    u8 *p = *(u8 **)(o + 0x160);
    vu0_v4 v0;
    vu0_v4 v10;
    vu0_v4 v20;
    vu0_q v30;
    u8 *d = D_L39_0024AD10;
    s32 i;

    qzero(&v20);
    for (i = 3; i >= 0; i--, d += 16) {
        func_0038D000(&v0, d, *(u8 **)(p + 0x2D0) + 0xC0);
        vec_add_ab(&v0, &v0, *(u8 **)(p + 0x2D0) + 0x10);
        func_0038CE20(&v10, *(u8 **)(p + 0x2D0) + 0xE0, -D_L39_0024ACE0);
        vec_add_ab(&v10, &v10, &v0);
        if (func_003D3CB0(&v0, &v10, 4, *(u8 **)(p + 0x2D0), 0) != 0) {
            v30 = D_L39_0025F780;
            func_0038CF68(&v30, &v30, 1.0f);
            vec_add_ab(&v20, &v20, &v30);
        } else {
            vec_add_ab(&v20, &v20, &D_L39_00243F20_00532550);
        }
    }
    func_0038CF68(o + 0x100, &v20, 1.0f);
}
/* localdecomp:end func_L39_00532550 */

/* localdecomp:start func_L39_00532698 */
typedef struct {
    u8 pad0[0xAA];
    s16 hAA;
} M_00532698;

typedef struct {
    u8 pad0[0x18];
    M_00532698 *f18;
    u8 pad1C[0x4];
    vu0_v4 f20;
    u8 pad30[0x10];
    vu0_v4 f40;
} G_00532698;

typedef struct {
    u8 pad0[0x300];
    u8 b300;
    u8 pad301[7];
    f32 f308;
} S_00532698;

extern G_00532698 D_L39_0025F740;
extern s32 D_001A5E3C[];

extern f32 func_0038CEA8(void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_L01_00446E38(void *, void *, f32, s32, void *);
extern s32 func_003D5630(void);
extern void func_L39_00667208(void *, u32, s32, s32);

s32 func_L39_00532698(u8 *a0, S_00532698 *s, vu0_v4 *pos, vu0_v4 *vel, vu0_v4 *out, s32 *hit, f32 max,
                      f32 a, f32 b) {
    vu0_v4 start;
    vu0_v4 v10;
    vu0_v4 dir;
    vu0_v4 p;
    vu0_v4 q;
    vu0_v4 v50;
    vu0_v4 n;
    f32 len;
    f32 t;
    f32 c;
    f32 d;

    c = b * 0.5f + 0.05f;
    p = *pos;
    start = *pos;
    *hit = 0;
    p.z += a + b;
    len = func_0038CEA8(vel);
    if (len <= 0.0f) {
        dir = *(vu0_v4 *)(a0 + 0xD0);
    } else {
        func_0038CE20(&dir, vel, 1.0f / len);
    }
    vec_add_ab(&q, &p, vel);
    t = func_L01_00446E38(&p, &q, b, 4, a0);
    if (t < 1.0f) {
        s32 k = func_003D5630();
        if (D_L39_0025F740.f18 == 0 || D_L39_0025F740.f18->hAA != 0x10C4) {
            if (k == 13 || k == 3 || k == 11) {
                if (s->f308 > 0.0f) {
                    s->f308 = 0.0f;
                    func_L39_00667208(s, 0xFFFFFFFF, 6, D_001A5E3C[0]);
                }
            }
        }
        if (t >= 0.0f) {
            func_0038CE20(&q, vel, t);
            vec_add_ab(&p, &p, &q);
            func_0038CE20(&n, &D_L39_0025F740.f40, 0.01f);
            vec_add_ab(&p, &p, &n);
        }
        *out = *(vu0_v4 *)&D_L39_0025F740.f20;
        if (D_L39_0025F740.f40.z < 0.5f) {
            D_L39_0025F740.f40.z = 0.0f;
            func_0038CF68(&n, &D_L39_0025F740.f40, 1.0f);
        }
        d = func_0038CE68(vel, &n);
        func_0038CE20(&v50, &n, d * -1.01f);
        vec_add_ab(vel, vel, &v50);
        len = func_0038CEA8(vel);
        if (max < len) {
            func_0038CE20(vel, vel, max / len);
        }
        func_0038CE20(&v10, vel, 1.0f - t);
        vec_add_ab(&q, &p, &v10);
        t = func_L01_00446E38(&p, &q, b, 4, a0);
        if (t < 1.0f) {
            if (t >= 0.0f) {
                func_0038CE20(&q, &v10, t);
                vec_add_ba(&p, &p, &q);
                func_0038CE20(&n, &D_L39_0025F740.f40, 0.01f);
                vec_add_ab(&p, &p, &n);
            }
        } else {
            p = q;
        }
    } else if (t >= 1.0f) {
        p = q;
    }
    q = p;
    *pos = p;
    q.z -= a + c;
    t = func_L01_00446E38(&p, &q, c, 4, a0);
    if (t < 1.0f) {
        s32 k = func_003D5630();
        if (D_L39_0025F740.f18 == 0 || D_L39_0025F740.f18->hAA != 0x10C4) {
            if (k == 13 || k == 3 || k == 11) {
                if (s->f308 > 0.0f) {
                    s->f308 = 0.0f;
                    func_L39_00667208(s, 0xFFFFFFFF, 6, D_001A5E3C[0]);
                }
            }
        }
        if (t >= 0.0f) {
            vec_sub_ba(&v10, &q, &p);
            func_0038CE20(&q, &v10, t);
            vec_add_ab(pos, &p, &q);
        }
        func_0038CF68(&n, &D_L39_0025F740.f40, 1.0f);
        if (n.z > 0.5f) {
            s->b300 = 0;
        } else {
            s->b300 = 1;
        }
    } else {
        *pos = q;
        s->b300 = 1;
    }
    pos->z = pos->z + c - b;
    return 0;
}
/* localdecomp:end func_L39_00532698 */

/* localdecomp:start func_L39_00532BE0 */
typedef int u128_00532BE0 __attribute__((mode(TI)));

__asm__(".extern D_L39_0024AC80, 4");
extern f32 D_L39_0024AC80;
__asm__(".extern D_L39_0024AC84, 4");
extern f32 D_L39_0024AC84;
__asm__(".extern D_L39_0024AC8C, 4");
extern f32 D_L39_0024AC8C;
__asm__(".extern D_L39_0024ACA0, 4");
extern f32 D_L39_0024ACA0;
__asm__(".extern D_L39_0024ACA4, 4");
extern f32 D_L39_0024ACA4;
__asm__(".extern D_L39_0024ACA8, 4");
extern f32 D_L39_0024ACA8;
__asm__(".extern D_L39_0024ACAC, 4");
extern f32 D_L39_0024ACAC;
__asm__(".extern D_L39_0024ACB0, 4");
extern f32 D_L39_0024ACB0;
__asm__(".extern D_L39_0024ACB4, 4");
extern f32 D_L39_0024ACB4;
__asm__(".extern D_L39_0024ACB8, 4");
extern f32 D_L39_0024ACB8;
__asm__(".extern D_L39_0024ACC8, 4");
extern f32 D_L39_0024ACC8;
__asm__(".extern D_L39_0024ACCC, 4");
extern f32 D_L39_0024ACCC;
__asm__(".extern D_L39_0024ACD0, 4");
extern f32 D_L39_0024ACD0;
__asm__(".extern D_L39_0024ACD4, 4");
extern f32 D_L39_0024ACD4;
__asm__(".extern D_L39_0024ACD8, 4");
extern f32 D_L39_0024ACD8;
__asm__(".extern D_L39_0024ACDC, 4");
extern f32 D_L39_0024ACDC;
__asm__(".extern D_L39_0024ACE4, 4");
extern f32 D_L39_0024ACE4;
__asm__(".extern D_L39_0024ACE8, 4");
extern f32 D_L39_0024ACE8;
__asm__(".extern D_L39_0024ACEC, 4");
extern f32 D_L39_0024ACEC;

extern void func_L01_004482A0(f32 *, f32 *, f32, f32, f32, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D160(f32, f32);
extern void func_00382760(void *, f32, f32, f32);
extern s32 func_L01_0040E728(void *, void *, f32);
extern void func_L01_0040E6B8(void *, void *, f32);
extern void func_L39_00532550(u8 *);
extern s32 func_L39_00532698(u8 *, S_00532698 *, vu0_v4 *, vu0_v4 *, vu0_v4 *, s32 *, f32, f32, f32);
extern void func_L39_005BC798(void *, void *, void *, void *, f32, f32, f32);
extern void func_L39_0066A398(void *, f32);

void func_L39_00532BE0(u8 *a0) {
    s32 back = 0;
    u8 *p = *(u8 **)(a0 + 0x68);
    u8 *q = *(u8 **)(p + 0x160);
    f32 t0 = *(f32 *)(q + 0x310);
    u8 *g = *(u8 **)(q + 0x2D8);
    vu0_v4 v;
    struct {
        u128_00532BE0 a;
        u128_00532BE0 pos;
    } out;
    s32 k;
    u8 *pp;
    f32 x;
    f32 ang;
    f32 rot;
    f32 roll;

    k = 0;
    if (t0 < -0.0100000007f) {
        back = 1;
    }
    out.pos = *(u128_00532BE0 *)(a0 + 0x10);
    x = D_L39_0024AC80;
    if (g != 0) {
        f32 t = *(f32 *)(*(u8 **)(g + 0x2534) + 0x10C);
        if (t < 0.0f) {
            x *= -t;
        } else {
            x = D_L39_0024AC84 * -t;
        }
        if (x != 0.0f) {
            func_L01_004482A0((f32 *)(q + 0x310), (f32 *)(p + 0x148), x * 0.0200000014f, D_L39_0024ACA8 * 1.44f,
                              D_L39_0024ACAC * 1.44f, D_L39_0024ACA4 * 0.000400000019f);
        } else {
            func_L01_004482A0((f32 *)(q + 0x310), (f32 *)(p + 0x148), 0.0f, D_L39_0024ACB4 * 1.44f,
                              D_L39_0024ACB8 * 1.44f, D_L39_0024ACB0 * 0.000400000019f);
        }
    } else {
        func_L01_004482A0((f32 *)(q + 0x310), (f32 *)(p + 0x148), 0.0f, D_L39_0024ACCC * 1.44f,
                          D_L39_0024ACD0 * 1.44f, D_L39_0024ACC8 * 0.000400000019f);
    }
    {
        f32 t = *(f32 *)(q + 0x310);
        if (t < 0.0f) {
            ang = -t;
        } else {
            ang = t;
        }
    }
    if (g != 0) {
        roll = *(f32 *)(g + 0x110) * D_L39_0024ACA0;
        if (back) {
            *(f32 *)(a0 + 0xF8) = func_0038DB00(*(f32 *)(a0 + 0xF8), roll * 0.017453292f * 0.0200000014f);
        } else {
            *(f32 *)(a0 + 0xF8) = func_0038DAB8(*(f32 *)(a0 + 0xF8), roll * 0.017453292f * 0.0200000014f);
        }
    }
    roll = 0.0f;
    if (q[0x300] != 0) {
        rot = func_0038D160(*(f32 *)(q + 0x270), *(f32 *)(q + 0x274));
    } else {
        roll = -*(f32 *)(a0 + 0xF4);
        if (back) {
            rot = func_0038DAB8(*(f32 *)(a0 + 0xF8), 3.1415927f);
        } else {
            rot = *(f32 *)(a0 + 0xF8);
        }
    }
    func_00382760(&v, ang, rot, roll);
    pp = q + 0x270;
    func_0038CE20(&v, &v, D_L39_0024AC8C);
    vec_add_ab(q + 0x270, q + 0x270, &v);
    if (q[0x300] != 0) {
        *(f32 *)(q + 0x278) = *(f32 *)(p + 0xF8) - D_L39_0024ACD4 * 0.000400000019f;
        func_L01_0040E728(pp, pp, ang);
    } else {
        func_L01_0040E6B8(pp, pp, ang);
    }
    func_L39_00532550(a0);
    if (q[0x300] == 0) {
        func_L39_005BC798(a0 + 0xC0, a0 + 0xF0, q + 0x284, p + 0x100, D_L39_0024ACE4, D_L39_0024ACE8,
                          D_L39_0024ACEC);
    } else {
        *(u128_00532BE0 *)(p + 0x100) = *(u128_00532BE0 *)&D_L39_00243F20_00532550;
        func_L39_005BC798(a0 + 0xC0, a0 + 0xF0, q + 0x284, p + 0x100, D_L39_0024ACE4, D_L39_0024ACE8,
                          D_L39_0024ACEC);
    }
    *(u128_00532BE0 *)(p + 0xF0) = *(u128_00532BE0 *)(q + 0x270);
    if (q[0x300] != 0) {
        (*(u16 *)(q + 0x302))++;
    } else {
        *(u16 *)(q + 0x302) = 0;
        *(f32 *)(p + 0x144) = *(f32 *)(a0 + 0x18);
    }
    func_L39_00532698(a0, (S_00532698 *)q, (vu0_v4 *)(a0 + 0x10), (vu0_v4 *)pp, (vu0_v4 *)&out, &k,
                      fabs_asm(*(f32 *)(q + 0x310)), D_L39_0024ACD8, D_L39_0024ACDC);
    if (g != 0) {
        *(u128_00532BE0 *)(*(u8 **)(g + 0x2524) + 0x10) = *(u128_00532BE0 *)(a0 + 0x10);
        *(u128_00532BE0 *)(*(u8 **)(g + 0x2524) + 0xF0) = *(u128_00532BE0 *)(a0 + 0xF0);
    }
    func_L39_0066A398(q, 50.0f);
    *(u128_00532BE0 *)(q + 0x230) = *(u128_00532BE0 *)(a0 + 0x10);
    *(u128_00532BE0 *)(q + 0x240) = *(u128_00532BE0 *)(a0 + 0xF0);
    *(u128_00532BE0 *)(q + 0x250) = *(u128_00532BE0 *)(a0 + 0x10);
    *(u128_00532BE0 *)(q + 0x260) = *(u128_00532BE0 *)(a0 + 0xF0);
}
/* localdecomp:end func_L39_00532BE0 */
