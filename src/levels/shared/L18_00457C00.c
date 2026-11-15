#include "common.h"

LINKER_REMNANT("asm/levels", func_L18_00457C00);

/* localdecomp:start func_L18_00457C10 */
#include "vu0.h"
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038DAB8(f32, f32);

void func_L18_00457C10(f32 *obj, f32 a1, f32 a2, f32 a3, f32 a4, f32 a5) {
    f32 f4;
    f32 r;
    f32 s;

    f4 = func_0038DB00(a2, a1);
    r = f4 / 0.157079637f;
    if (r > 1.0f) {
        r = 1.0f;
    } else if (r < -1.0f) {
        r = -1.0f;
    }
    obj[0] = obj[0] + (a3 * r - a4 * obj[0]);
    if (a5 != 0.0f) {
        if (a5 < obj[0]) {
            obj[0] = a5;
        } else if (obj[0] < -a5) {
            obj[0] = -a5;
        }
    }
    s = fabs_asm(f4);
    if (s < obj[0]) {
        obj[0] = s;
    } else if (obj[0] < -s) {
        obj[0] = -s;
    }
    func_0038DAB8(a1, obj[0]);
}
/* localdecomp:end func_L18_00457C10 */
