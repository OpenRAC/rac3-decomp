#include "common.h"

/* localdecomp:start func_L39_005D3CA0 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_005D3CA0;
typedef int U128_005D3CA0 __attribute__((mode(TI)));
typedef struct {
    V4_005D3CA0 v;
    s32 cnt;
} T_005D3CA0;
typedef struct {
    u8 pad0[4];
    u32 w4;
    u8 b8;
    u8 pad9[3];
    f32 fC;
    V4_005D3CA0 v10;
    T_005D3CA0 t20;
} S_005D3CA0;

extern void func_L39_005FFB48(U128_005D3CA0 *, U128_005D3CA0 *);
extern void func_0038CE20(void *, void *, f32);
extern void func_L39_005FF198(void *, void *, void *);
extern s32 func_0038DBD8(f32, s32, s32);
extern void func_003CD250(u8 *);

void func_L39_005D3CA0(S_005D3CA0 *o) {
    V4_005D3CA0 tmp;
    s32 k;
    V4_005D3CA0 *p = &o->v10;
    T_005D3CA0 *q = &o->t20;

    func_L39_005FFB48((U128_005D3CA0 *)p, (U128_005D3CA0 *)p);
    if (--q->cnt < 0) {
        q->cnt = 0;
    }
    o->b8++;
    vec_add_ba(p, &q->v, p);
    o->fC += 1575.0f;
    func_0038CE20(q, q, 0.99f);
    func_L39_005FF198(0, p, &tmp);
    k = *(u8 *)&o->w4;
    if (k < 0x20) {
        func_0038CE20(&tmp, &tmp, 0.0015f);
        vec_add_ab(&q->v, &q->v, &tmp);
    } else {
        func_0038CE20(&tmp, &tmp, -0.00075f);
        vec_add_ab(&q->v, &q->v, &tmp);
    }
    o->w4 = func_0038DBD8(0.025f, o->w4 & 0xFFFFFF, 0) | (q->cnt << 24);
    if (q->cnt == 0) {
        func_003CD250((u8 *)o);
    }
}
/* localdecomp:end func_L39_005D3CA0 */
