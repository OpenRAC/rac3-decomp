#include "common.h"

/* localdecomp:start func_L39_005BA3A0 */
#include "vu0.h"
extern void func_0038CE20(void *, void *, f32);
extern s32 func_0038D058(f32 *);
void func_L39_005BA3A0(vu0_v4 *a, s32 *out) {
    vu0_v4 r;
    vu0_v4 t;

    *(vu0_q *)&t = 0;
    t.x = 3.1415925f;
    t.y = 3.1415925f;
    t.z = 3.1415925f;
    vec_add_ba(&r, a, &t);
    func_0038CE20(&r, &r, 40.58451f);
    *out = func_0038D058(&r.x);
}
/* localdecomp:end func_L39_005BA3A0 */

/* localdecomp:start func_L39_005BA418 */
#include "vu0.h"

extern void func_L01_0040E858(vu0_v4 *, u32);
extern void func_0038CE20(void *, void *, f32);

void func_L39_005BA418(vu0_v4 *a, u32 *b) {
    vu0_v4 v;

    *(vu0_q *)&v = 0;
    v.x = 3.1415925f;
    v.y = 3.1415925f;
    v.z = 3.1415925f;
    func_L01_0040E858(a, *b);
    func_0038CE20(a, a, 0.024639942f);
    vec_sub_ab(a, a, &v);
}
/* localdecomp:end func_L39_005BA418 */
