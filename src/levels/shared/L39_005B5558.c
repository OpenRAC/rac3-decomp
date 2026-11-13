#include "common.h"

/* localdecomp:start func_L39_005B5558 */
#include "vu0.h"

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_005B5558;

typedef struct {
    u8 pad0[0x18];
    s32 f18;
    s32 f1C;
    V_005B5558 v20;
    V_005B5558 v30;
    V_005B5558 v40;
} S_005B5558;

extern S_005B5558 D_L39_0025F740;

extern void func_L01_004463D0(s32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern f32 func_0038CED8(void *);
extern f32 func_0038D160(f32, f32);
extern void func_0013D528(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CF38(void *, void *);
extern s32 func_L01_003FB640(void *, f32, s32, void *);

s32 func_L39_005B5558(void *ctx, V_005B5558 *pos, V_005B5558 *np, s32 flags, f32 dz, f32 r, f32 maxh, f32 ang) {
    V_005B5558 d;
    V_005B5558 t;
    V_005B5558 a;
    V_005B5558 b;
    V_005B5558 up;
    S_005B5558 *g;
    s32 ok = 1;
    s32 i;
    f32 h;
    f32 z;
    f32 step;
    f32 lift;
    s32 mask = flags & 2;
    s32 down;

    np->z += dz;
    h = ((f32 (*)(void *))func_L01_004463D0)(np);
    np->z -= dz;
    z = pos->z;
    if (fabs_asm(h - z) > maxh) {
        down = !(flags & 1);
        if ((down && h < z) || z < h) {
            *np = *pos;
            ok = 0;
        }
    }

    vec_sub_ba(&d, np, pos);
    func_0038CF68(&t, &d, r * 1.2f);
    *(vu0_q *)&up = 0;
    up.z = dz;
    vec_add_ab(&a, pos, &up);
    vec_add_ab(&b, &a, &t);
    if (ok && func_003D3CB0(&a, &b, mask | 0x24, ctx, 0)) {
        g = &D_L39_0025F740;
        if (g->f1C > 0) {
            if (ang <= func_0038D160(g->v40.z, func_0038CED8(&g->v40))) {
                g->v40.z = 0.0f;
                func_0013D528(&g->v40, &g->v40);
                step = -d.x * g->v40.x - d.y * g->v40.y;
                if (step > 0.0f) {
                    ok = 0;
                    func_0038CE20(&g->v40, &g->v40, step);
                    vec_add_ba(&d, &d, &g->v40);
                }
            }
            vec_add_ab(np, pos, &d);
        }
    }

    if (!(flags & 2)) {
        lift = dz + r;
        for (i = 0; i < 6; i++) {
            V_005B5558 p = *np;
            p.z += lift;
            if (func_L01_003FB640(&p, r, 0x24, ctx)) {
                f32 tilt = func_0038D160(func_0038CF38(np, &D_L39_0025F740.v20), D_L39_0025F740.v20.z - np->z);
                if (D_L39_0025F740.f18 != 0 || ang < tilt) {
                    *np = D_L39_0025F740.v30;
                    ok = 0;
                    np->z -= lift;
                }
            } else {
                break;
            }
        }
    }

    np->z += dz;
    h = ((f32 (*)(void *))func_L01_004463D0)(np);
    np->z -= dz;
    z = pos->z;
    if (fabs_asm(h - z) > maxh) {
        down = !(flags & 1);
        if ((down && h < z) || z < h) {
            *np = *pos;
            ok = 0;
        }
    }
    pos->x = np->x;
    pos->y = np->y;
    return ok;
}
/* localdecomp:end func_L39_005B5558 */
