/* functional: high. 16 words differ at level_01 (vec_copy emits lqc2/sqc2 where retail copies the quad through a GPR with lq/sq; scheduling). The file prototypes func_L01_00448148 with 2 args, retail passes (rate, dist, a, b, cap), so the call goes through a cast as func_L01_004485E0.c does. */
#include "vu0.h"

static void v3sub_00448340(void *d, void *a, void *b) {
    f32 *pd = (f32 *)d, *pa = (f32 *)a, *pb = (f32 *)b;
    f32 x = pa[0] - pb[0], y = pa[1] - pb[1], z = pa[2] - pb[2];
    pd[0] = x; pd[1] = y; pd[2] = z;
}
static void v3add_00448340(void *d, void *a, void *b) {
    f32 *pd = (f32 *)d, *pa = (f32 *)a, *pb = (f32 *)b;
    f32 x = pa[0] + pb[0], y = pa[1] + pb[1], z = pa[2] + pb[2];
    pd[0] = x; pd[1] = y; pd[2] = z;
}
static void v4copy_00448340(void *d, void *s) {
    f32 *pd = (f32 *)d, *ps = (f32 *)s;
    f32 x = ps[0], y = ps[1], z = ps[2], w = ps[3];
    pd[0] = x; pd[1] = y; pd[2] = z; pd[3] = w;
}
static f32 fabs_00448340(f32 x) { return x < 0.0f ? -x : x; }
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) Vec_00448340;
f32 func_L01_00448340(Vec_00448340 *position, Vec_00448340 *target, f32 *rate, f32 a, f32 b, f32 cap) {
    extern f32 func_0038CEA8(void *);
    extern void func_0038CF68(void *, void *, f32);
    Vec_00448340 delta;
    f32 distance, left;

    v3sub_00448340(&delta, target, position);
    distance = func_0038CEA8(&delta);
    /* retail passes a, b, cap in f13-f15; the file declares a 2-argument prototype */
    ((void (*)(f32 *, f32, f32, f32, f32))func_L01_00448148)(rate, distance, a, b, cap);
    func_0038CF68(&delta, &delta, *rate);
    v3add_00448340(position, position, &delta);
    left = distance - *rate;
    if (fabs_00448340(left) < cap * 0.01f) {
        v4copy_00448340(position, target);
        *rate = 0.0f;
        return *rate;
    }
    return left;
}
