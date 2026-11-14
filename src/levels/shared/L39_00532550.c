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

INCLUDE_ASM("asm/levels", func_L39_00532BE0);
