#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_00424168 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_00424168;
typedef struct { V4_00424168 r[4]; } M4_00424168;

extern void func_003C2EC0(void *, s32, void *);
extern void func_0038CF68(void *dst, void *src, f32 s);
extern void func_003D9508(void *p, s32 a, s32 b, s32 c, f32 d, f32 e, f32 f);

void func_L01_00424168(void *a0) {
    V4_00424168 v;
    M4_00424168 m;
    func_003C2EC0(a0, 2, &m);
    func_0038CF68(&v, &m, 0.01f);
    vec_add_ab(&v, &v, &m.r[3]);
    func_003D9508(&v, 11, 0x15103080, 1, 0.1f, 0.08f, 0.0f);
}
/* localdecomp:end func_L01_00424168 */
