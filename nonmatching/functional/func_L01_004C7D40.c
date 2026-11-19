/* functional: high. does not compile under file flags; reading matched */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_004C7D40 */
extern void func_L01_004C7D98(void *, void *);
extern void func_0038CE20(Vec4_004C4AD8 *, Vec4_004C4AD8 *, f32);

void func_L01_004C7D40(void *obj, f32 *pos, f32 s) {
    Vec4_004C4AD8 v;

    func_L01_004C7D98(obj, &v);
    func_0038CE20(&v, &v, s);
    vec_sub_ab(pos, pos, &v);
}
/* localdecomp:end func_L01_004C7D40 */
