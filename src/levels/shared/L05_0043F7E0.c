#include "common.h"

/* localdecomp:start func_L05_0043F7E0 */
#include "vu0.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_43F7E0;

extern f32 func_L01_004464C8_0043F7E0(V4_43F7E0 *, V4_43F7E0 *, V4_43F7E0 *, V4_43F7E0 *);
extern f32 func_0038CF38(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038D0C8(f32);
extern f32 func_0038D098(f32);

s32 func_L05_0043F7E0(V4_43F7E0 *out1, V4_43F7E0 *out2, f32 *t1, f32 *t2, V4_43F7E0 *p0, V4_43F7E0 *p1, V4_43F7E0 c, f32 r) {
    V4_43F7E0 dir;
    V4_43F7E0 dir2;
    V4_43F7E0 pt;
    f32 t;
    f32 d;
    f32 a0;
    f32 len;
    f32 h;
    f32 proj;
    f32 s;
    s32 n;

    n = 0;
    t = func_L01_004464C8_0043F7E0(&pt, p0, p1, &c);
    d = func_0038CF38(&pt, &c);
    if (r < d) {
        *out1 = pt;
        *t1 = t;
        *out2 = pt;
        *t2 = t;
        return 0;
    }
    vec_sub_ab(&dir, p1, p0);
    dir2 = dir;
    dir2.z = 0.0f;
    func_0038CF68(&dir2, &dir2, 1.0f);
    a0 = p0->x * dir2.x + p0->y * dir2.y;
    len = (p1->x * dir2.x + p1->y * dir2.y) - a0;
    if (t < 0.0001f || 0.999f < t) {
        func_0038CE20(&pt, &dir, t);
        vec_add_ab(&pt, &pt, p0);
        d = func_0038CF38(&pt, &c);
    }
    proj = pt.x * dir2.x + pt.y * dir2.y;
    h = func_0038D098(func_0038D0C8(d / r)) * r;
    s = (proj - h) - a0;
    *t1 = s;
    if (s < 0.0f) {
        *out1 = *p0;
    } else {
        if (len < s) {
            return 0;
        }
        func_0038CE20(out1, &dir2, s);
        n = 1;
        vec_add_ab(out1, out1, p0);
    }
    *t1 = *t1 / len;
    out1->z = p0->z + dir.z * *t1;
    s = (proj + h) - a0;
    *t2 = s;
    if (len < s) {
        *out2 = *p1;
    } else {
        if (s < 0.0f) {
            return 0;
        }
        func_0038CE20(out2, &dir2, s);
        n++;
        vec_add_ab(out2, out2, p0);
    }
    *t2 = *t2 / len;
    out2->z = p0->z + dir.z * *t2;
    return n;
}
/* localdecomp:end func_L05_0043F7E0 */
