#include "common.h"

/* localdecomp:start func_L06_0045AFF8 */
#include "vu0.h"
typedef struct { s32 n; s32 pad[3]; vu0_v4 p[1]; } Path_0045AFF8;
extern s32 func_L06_004591F8(void *, void *, u8);
extern f32 func_0038CE68(void *, void *);
extern void func_L01_00476920(void *, void *, void *, void *, f32);

s32 func_L06_0045AFF8(void *out, s32 *path, void *pos) {
    vu0_v4 d;
    vu0_v4 tmp;
    Path_0045AFF8 *pp;
    s32 i;
    s32 n;
    f32 t;

    pp = (Path_0045AFF8 *)path;
    tmp = *(vu0_v4 *)pos;
    i = func_L06_004591F8(&tmp, pp, 1);
    n = pp->n;
    if (i == n - 1) {
        vec_sub_ba(&d, &pp->p[i], &pp->p[i - 1]);
        t = func_0038CE68(pos, &d);
        if (func_0038CE68(&pp->p[i], &d) < t) {
            *(vu0_v4 *)out = pp->p[i];
            return i;
        }
        func_L01_00476920(out, pos, &pp->p[i - 1], &pp->p[i], 0.0f);
        return n - 2;
    }
    if (i == 0) {
        vec_sub_ba(&d, &pp->p[1], &pp->p[0]);
        t = func_0038CE68(pos, &d);
        if (t < func_0038CE68(&pp->p[0], &d)) {
            *(vu0_v4 *)out = pp->p[0];
            return 0;
        }
        func_L01_00476920(out, pos, &pp->p[0], &pp->p[1], 0.0f);
        return 0;
    }
    vec_sub_ba(&d, &pp->p[i + 1], &pp->p[i - 1]);
    t = func_0038CE68(pos, &d);
    if (func_0038CE68(&pp->p[i], &d) < t) {
        func_L01_00476920(out, pos, &pp->p[i], &pp->p[i + 1], 0.0f);
        return i;
    }
    func_L01_00476920(out, pos, &pp->p[i - 1], &pp->p[i], 0.0f);
    return i - 1;
}
/* localdecomp:end func_L06_0045AFF8 */

/* localdecomp:start func_L06_0045B1F8 */
#include "vu0.h"

extern s32 func_L06_0045AFF8(void *out, s32 *path, void *pos);
extern f32 func_0038CEA8(void *v);

void func_L06_0045B1F8(s32 *path, void *pos, s32 *idx, f32 *dist) {
    vu0_v4 near;
    vu0_v4 d;
    s32 i;

    i = func_L06_0045AFF8(&near, path, pos);
    *idx = i;
    if (i == *path - 1) {
        *dist = 0.0f;
        return;
    }
    vec_sub_ab(&d, &near, (u8 *)path + i * 16 + 0x10);
    *dist = func_0038CEA8(&d);
}
/* localdecomp:end func_L06_0045B1F8 */
