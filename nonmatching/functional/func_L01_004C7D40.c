/* functional: high. pos.xyz -= scale(dir(obj), s); w lane of pos kept as retail's vsub.xyz does. */
#include "common.h"

/* localdecomp:start func_L01_004C7D40 */
extern void func_L01_004C7D98(void *, void *);
extern void func_0038CE20(void *, void *, f32);

void func_L01_004C7D40(void *obj, f32 *pos, f32 s) {
    Vec4_004C4AD8 v;

    func_L01_004C7D98(obj, &v);
    func_0038CE20(&v, &v, s);
    pos[0] = pos[0] - ((f32 *)&v)[0];
    pos[1] = pos[1] - ((f32 *)&v)[1];
    pos[2] = pos[2] - ((f32 *)&v)[2];
}
/* localdecomp:end func_L01_004C7D40 */
