#include "common.h"

/* localdecomp:start func_L40_00413200 */
extern s32 func_L39_0066DCC8(s32, s32, s32, s32);
extern void func_L39_00662AA0(s32, void *, s32);

void func_L40_00413200(s32 a0, s32 a1, void *a2, s32 a3, f32 f) {
    s32 h;
    s32 x;
    f32 y;
    s32 z;

    h = func_L39_0066DCC8(a0, a1, 0, -1);
    x = a1;
    func_L39_00662AA0(h, &x, 4);
    func_L39_00662AA0(h, a2, 16);
    y = f;
    func_L39_00662AA0(h, &y, 4);
    z = a3;
    func_L39_00662AA0(h, &z, 4);
}
/* localdecomp:end func_L40_00413200 */
