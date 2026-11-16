/* PAL near miss (Claude wave S2/pal): flags: byte-exact only with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (its file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as").
 * Worker's note: byte-exact (func_L01_004C7D98(obj, &v); func_0038CE20(&v, &v, s); vec_sub_ab(pos, pos, &v)) only with -mvu0-use-vf0-vf2, which the file line lacks; uses the file's Vec4_004C4AD8 and its func_0038CE20 prototype (line 390: a void * declaration here would ...
 */
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
