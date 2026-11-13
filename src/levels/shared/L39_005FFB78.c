#include "common.h"

/* localdecomp:start func_L39_005FFB78 */
#include "vu0.h"
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038D098(f32);
extern void func_0038D890(void *, void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CE20(f32 *, void *, f32);

void func_L39_005FFB78(u8 *o, f32 *out, void *v, f32 x, f32 unused_f13, f32 y) {
    f32 sp[4];
    f32 d;

    vec_sub_ba(out, o + 0x12B0, v);
    func_0038CF68(out, out, 1.0f);
    d = func_0038CE68(out, o + 0x3B0);
    if (d < func_0038D098(y)) {
        func_0038CE90(sp, out, o + 0x3B0);
        func_0038D890(out, o + 0x3B0, sp, y);
        func_0038CF68(out, out, x);
    } else {
        func_0038CE20(out, out, x);
    }
}
/* localdecomp:end func_L39_005FFB78 */
