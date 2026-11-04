#include "common.h"

typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
} S_func_L33_00344F88;

/* localdecomp:start func_L33_00344F88 */
void func_L33_00344F88(S_func_L33_00344F88 *p, s32 c) {
    u32 t;
    s32 a;
    f32 v0;
    if (p != 0) {
        p->f4 = (f32)((c & 0xFF00) >> 8);
        v0 = (f32)(c & 0xFF);
        p->f8 = (f32)(s32)(((u32)c >> 16) & 0xFF);
        p->f0 = v0;
        t = c & 0xFF000000;
        a = t >> 24;
        if (a >= 0) {
            p->fC = (f32)a;
        } else {
            s32 x = (a & 1) | (t >> 25);
            f32 y = (f32)x;
            p->fC = y + y;
        }
    }
}
/* localdecomp:end func_L33_00344F88 */
