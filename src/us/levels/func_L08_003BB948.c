#include "common.h"

/* localdecomp:start func_L08_003BB948 */
#include "vu0.h"

typedef vu0_v4 V_003BB948;
typedef struct { char p0[0x10]; V_003BB948 pos; char p20[4]; char *classdata; float p28, scale; } M_003BB948;
extern s32 func_0037E1D8(s32);
extern void func_003BF6A8(void *, f32);
extern f32 func_0037E250(f32, f32);
extern void *func_L01_00460318(void *, void *, s32, s32, s32, s32, s32, s32);

void func_L08_003BB948(M_003BB948 *m, f32 spread, f32 height) {
    V_003BB948 point, velocity, center;
    f32 scale;
    s32 i = 0;
    s32 random;

    scale = m->scale / *(f32 *)(m->classdata + 0x24);
    qzero(&center);
    center.z += scale * height;
    vec_add_ab(&center, &m->pos, &center);
    do {
        random = func_0037E1D8(50);
        qzero(&point);
        func_003BF6A8(&point, scale * spread);
        vec_add_ab(&point, &center, &point);
        qzero(&velocity);
        func_003BF6A8(&velocity, 0.0033333336f);
        velocity.z += func_0037E250(0.0f, 0.008333334f);
        func_L01_00460318(&point, &velocity, 0x70507080, 0, func_0037E1D8(150) + 150,
                          (s32)(scale * (random + 100)), (s32)(scale * (random + 220)), i < 21);
        i++;
    } while (i < 35);
}
/* localdecomp:end func_L08_003BB948 */
