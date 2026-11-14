#include "common.h"

/* localdecomp:start func_L30_0034D1E8 */
#include "vu0.h"
typedef struct { u8 pad[0x10]; vu0_v4 v; } S2_0034D1E8;
typedef struct { u8 pad[8]; S2_0034D1E8 *p; } S1_0034D1E8;
typedef struct { u8 pad[0x34]; u16 flags; u8 pad2[0x32]; S1_0034D1E8 *x68; } M_0034D1E8;
typedef struct { u8 pad[8]; M_0034D1E8 *moby; u8 pad2[4]; vu0_v4 pos; } H_0034D1E8;
extern f32 func_0038CEA8(void *v);
extern f32 func_0038CE68(void *a, void *b);
extern void func_0038CF68(void *d, void *s, f32 len);
extern s32 func_003D3CB0(void *a, void *b, s32 n, void *o, s32 e);
extern s32 func_L01_003FB640(void *a, s32 n, void *o, f32 r);
extern void func_L02_003BA9F8(void *v, void *n, void *a, void *b);
extern s32 func_L30_003445B8(u8 *a0);
extern void func_L30_0034D808(void *vel, f32 max, f32 damp, f32 drop);
extern H_0034D1E8 D_L30_001E9010;
extern vu0_v4 D_L30_001E11F0 __attribute__((section(".sdata")));
extern vu0_v4 D_L30_001E1200 __attribute__((section(".sdata")));
extern vu0_v4 D_L30_001E1210 __attribute__((section(".sdata")));
extern u8 D_L30_001E1220;
extern u8 D_L30_001E1221;
extern u8 D_L30_001E1222;
extern u8 D_L30_001DD4B4;
extern f32 D_L30_001DD4A8;
__asm__(".extern D_L30_001DD4A8, 4");
__asm__(".extern D_L30_001DD4B4, 1");

s32 func_L30_0034D1E8(void *o, vu0_v4 *pos, vu0_v4 *vel, vu0_v4 *grav, s32 move, s32 down, s32 side,
                      s32 up, f32 radius, f32 fall, f32 maxa, f32 maxb, f32 damp, f32 drop) {
    vu0_v4 start, cur, d, t30, t40, t50, a, b, t80, t90, tA0;
    s32 ret = 0;
    M_0034D1E8 *moby = 0;

    if (0.0f < func_0038CEA8(grav)) {
        func_0038CF68(&t90, grav, -fall);
    } else {
        qzero(&t90);
    }
    vec_add_ab(&start, &t90, pos);
    cur = start;
    if (move) {
        if (0.0f < func_0038CEA8(grav)) {
            func_L02_003BA9F8(vel, grav, &a, &b);
        } else {
            b = *vel;
            qzero(&a);
        }
        func_L30_0034D808(&a, maxa, damp, drop);
        func_L30_0034D808(&b, maxb, damp, drop);
        vec_add_ba(vel, &a, &b);
        vec_add_ab(&cur, &cur, vel);
    }
    qzero(&tA0);
    D_L30_001E1222 = 0;
    D_L30_001DD4B4 = 0;
    if (down) {
        func_0038CF68(&t80, grav, radius + D_L30_001DD4A8);
        vec_add_ab(&t80, &t80, &cur);
        D_L30_001E1222 = func_003D3CB0(&cur, &t80, 2, o, 0) != 0;
        if (D_L30_001E1222) {
            vu0_v4 *hp = &D_L30_001E9010.pos;
            s32 hit;
            D_L30_001E1210 = *hp;
            moby = D_L30_001E9010.moby;
            vec_sub_ba(&t40, &D_L30_001E1210, &cur);
            hit = 0;
            if (func_0038CE68(vel, grav) >= 0.0f || func_0038CEA8(vel) < 0.001f) {
                hit = 1;
            }
            ret = hit;
        } else {
            qzero(&D_L30_001E1210);
        }
    }
    if (!ret && move) {
        vec_add_ab(vel, vel, grav);
    } else {
        func_L02_003BA9F8(vel, grav, &a, &b);
        *vel = b;
        if (moby != 0 && func_L30_003445B8((u8 *)moby) != 0 && (moby->flags & 0x20)) {
            S2_0034D1E8 *p = moby->x68->p;
            if (p != 0 && 0.0f < func_0038CEA8(&p->v)) {
                tA0 = p->v;
            }
            D_L30_001DD4B4 = 1;
        }
    }
    D_L30_001E1221 = 0;
    if (side) {
        if (down) {
            func_L02_003BA9F8(vel, grav, &a, &b);
        } else {
            b = *vel;
        }
        if (0.001f < func_0038CEA8(&b)) {
            func_0038CF68(&t80, &b, radius);
            vec_add_ab(&t80, &t80, &cur);
            D_L30_001E1221 = func_003D3CB0(&cur, &t80, 2, o, 0) != 0;
            if (D_L30_001E1221) {
                vu0_v4 *hp = &D_L30_001E9010.pos;
                D_L30_001E1200 = *hp;
                vec_sub_ba(&t50, &D_L30_001E1200, &cur);
                vec_sub_ab(vel, vel, &b);
            } else {
                qzero(&D_L30_001E1200);
            }
        }
    }
    D_L30_001E1220 = 0;
    if (up) {
        D_L30_001E1220 = func_L01_003FB640(&cur, 2, o, radius + D_L30_001DD4A8) != 0;
        if (D_L30_001E1220) {
            vu0_v4 *hp = &D_L30_001E9010.pos;
            D_L30_001E11F0 = *hp;
            vec_sub_ba(&t30, &D_L30_001E11F0, &cur);
        } else {
            qzero(&D_L30_001E11F0);
        }
    }
    if (D_L30_001E1220) {
        if (func_0038CEA8(&t30) < radius) {
            func_0038CF68(&t90, &t30, func_0038CEA8(&t30) - radius);
            vec_add_ab(&cur, &cur, &t90);
        }
    }
    if (D_L30_001E1221) {
        if (func_0038CEA8(&t50) < radius) {
            func_0038CF68(&t90, &t50, func_0038CEA8(&t50) - radius);
            vec_add_ab(&cur, &cur, &t90);
        }
    }
    if (ret || (D_L30_001E1222 && func_0038CEA8(&t40) < radius)) {
        func_0038CF68(&t90, &t40, func_0038CEA8(&t40) - radius);
        vec_add_ab(&cur, &cur, &t90);
    }
    vec_sub_ba(&d, &cur, &start);
    vec_add_ab(pos, pos, &d);
    return ret;
}
/* localdecomp:end func_L30_0034D1E8 */
