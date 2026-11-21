#include "vu0.h"
#include "common.h"

/* declared by functions of L06_003506E0.c, which this file was cut from */
extern void func_L06_00350BB8(void *arg0, u8 *arg1);

/* localdecomp:start func_L06_00350D60 */
void func_L06_00350D60(s32 a0, s32 a1, s32 a2, f32 *p) {
    f32 f;
    f32 lim;
    *(s32 *)p = 0;
    f = p[1];
    if (1.0471976f < f) {
        p[1] = 1.0471976f;
    } else if (f < -1.0471976f) {
        p[1] = -1.0471976f;
    }
    f = p[2];
    if (a2 == 0) {
        if (0.4886922f < f) {
            p[2] = 0.4886922f;
        } else if (f < -0.7853982f) {
            p[2] = -0.7853982f;
        }
    } else {
        if (0.7853982f < f) {
            p[2] = 0.7853982f;
        } else if (f < -0.4886922f) {
            p[2] = -0.4886922f;
        }
    }
}
/* localdecomp:end func_L06_00350D60 */
