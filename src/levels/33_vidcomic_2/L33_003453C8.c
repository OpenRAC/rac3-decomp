#include "common.h"

/* localdecomp:start func_L33_003453C8 */
#include "vu0.h"
void func_L33_003453C8(s32 *arg0, f32 *arg1) {
    extern f32 func_003824E0(f32, f32);
    s32 a, b, c, d, k;
    s32 t0, t1, t2, t3;
    f32 r;
    if (arg1 != 0) {
        t0 = (s32)arg1[0];
        r = func_003824E0(0.0f, 1.0f);
        k = r < arg1[0] - cvtsw_asm(cvtws_asm(arg1[0]));
        a = k + t0;
        t1 = (s32)arg1[1];
        r = func_003824E0(0.0f, 1.0f);
        k = r < arg1[1] - cvtsw_asm(cvtws_asm(arg1[1]));
        b = k + t1;
        t2 = (s32)arg1[2];
        r = func_003824E0(0.0f, 1.0f);
        k = r < arg1[2] - cvtsw_asm(cvtws_asm(arg1[2]));
        c = k + t2;
        t3 = (s32)arg1[3];
        r = func_003824E0(0.0f, 1.0f);
        k = r < arg1[3] - cvtsw_asm(cvtws_asm(arg1[3]));
        d = k + t3;
        if (a > 128) a = 128; else if (a < 0) a = 0;
        if (b > 128) b = 128; else if (b < 0) b = 0;
        if (c > 128) c = 128; else if (c < 0) c = 0;
        if (d > 128) d = 128; else if (d < 0) d = 0;
        *arg0 = (d << 24) | (c << 16) | (b << 8) | a;
    }
}
/* localdecomp:end func_L33_003453C8 */
