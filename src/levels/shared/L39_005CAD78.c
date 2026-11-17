#include "common.h"

/* localdecomp:start func_L39_005CAD78 */
#include "vu0.h"
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    vu0_v4 vel;
    s32 state;
    s32 timer;
    f32 f18;
    f32 gravity;
} V_005CAD78;
typedef struct {
    u8 pad0[4];
    s32 f4;
    u8 f8;
    u8 pad9[7];
    vu0_v4 pos;
    V_005CAD78 v;
} P_005CAD78;
typedef struct { u8 pad[0x20]; vu0_v4 v; } S_005CAD78;
extern s32 func_003D3CB0(void *, void *, s32, s32, s32);
extern s32 func_003D5630(void);
extern u8 *func_L39_005CCB70(void *, f32, s32, s32, f32);
extern u8 *func_L39_005CEC38(void *, s32, f32, f32);
extern f32 func_003C3EC8(void *, s32);
extern void func_003CD250(void *);
extern u8 D_L39_0025F760[];
extern S_005CAD78 D_L39_0025F740;
extern s32 D_L39_00243264;
extern s32 D_001D7B54_sda;

void func_L39_005CAD78(P_005CAD78 *p) {
    V_005CAD78 *q = &p->v;
    s32 s = q->state;
    vu0_v4 tmp;
    f32 f;

    if (s == 0) {
        vec_add_ab(&p->pos, &p->pos, &p->v.vel);
    } else if (s == 1) {
        vec_add_ab(&tmp, &p->pos, &p->v.vel);
        if (func_003D3CB0(&p->pos, &tmp, 2, 0, 0) != 0) {
            if (func_003D5630() == 0) {
                func_L39_005CCB70(&D_L39_0025F740.v, 0.2f, D_L39_00243264, -1, 5250.0f);
            }
            func_003CD250(p);
            return;
        }
        *(u128_t *)&p->pos = *(u128_t *)&tmp;
    } else if (s == 3) {
        vec_add_ab(&p->pos, &p->pos, &p->v.vel);
        f = func_003C3EC8(&p->pos, 0);
        if (p->pos.z < f) {
            p->pos.z = f;
            func_L39_005CCB70(&p->pos, 0.2f, D_001D7B54_sda, -1, 5250.0f);
            func_003CD250(p);
            return;
        }
    } else {
        vec_add_ab(&tmp, &p->pos, &p->v.vel);
        if (func_003D3CB0(&p->pos, &tmp, 2, 0, 0) != 0) {
            if (func_003D5630() != 0) {
                D_L39_0025F740.v.z += 0.05f;
                func_L39_005CEC38(&D_L39_0025F740.v, -1, 0.25f, 3150.0f);
            }
            func_003CD250(p);
            return;
        }
        *(u128_t *)&p->pos = *(u128_t *)&tmp;
    }
    q->vel.z -= q->gravity;
    p->f8 += 2;
    if (--q->timer <= 0 || p->pos.z < q->f18) {
        p->f4 += 0xF0000000;
        if (p->f4 < 0) {
            func_003CD250(p);
        }
    }
}
/* localdecomp:end func_L39_005CAD78 */
