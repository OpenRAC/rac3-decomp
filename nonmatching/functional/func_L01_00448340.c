/* functional: high. 16 words differ at level_01 (vec_copy emits lqc2/sqc2 where retail copies the quad through a GPR with lq/sq; scheduling). The file prototypes func_L01_00448148 with 2 args, retail passes (rate, dist, a, b, cap), so the call goes through a cast as func_L01_004485E0.c does. */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) Vec_00448340;
f32 func_L01_00448340(Vec_00448340 *position, Vec_00448340 *target, f32 *rate, f32 a, f32 b, f32 cap) {
    extern f32 func_0038CEA8(void *);
    extern void func_0038CF68(void *, void *, f32);
    Vec_00448340 delta;
    f32 distance, left;

    vec_sub_ab(&delta, target, position);
    distance = func_0038CEA8(&delta);
    /* retail passes a, b, cap in f13-f15; the file declares a 2-argument prototype */
    ((void (*)(f32 *, f32, f32, f32, f32))func_L01_00448148)(rate, distance, a, b, cap);
    func_0038CF68(&delta, &delta, *rate);
    vec_add_ba(position, position, &delta);
    left = distance - *rate;
    if (fabs_asm(left) < cap * 0.01f) {
        vec_copy(position, target);
        *rate = 0.0f;
        return *rate;
    }
    return left;
}
