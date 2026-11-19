/* functional: high. Verified against PAL asm (stochastic rounding of 4 floats per channel, clamp 0..128, pack ABGR); differs from retail only in cvt.w.s/cvt.s.w staying in an FPU register (128 diffs). */
#include "common.h"

extern f32 func_003824E0(f32, f32);

void func_L33_003453C8(s32 *arg0, f32 *arg1) {
    s32 a, b, c, d, t;
    if (arg1 != 0) {
        t = (s32)arg1[0];
        a = t + (func_003824E0(0.0f, 1.0f) < arg1[0] - (f32)(s32)arg1[0]);
        t = (s32)arg1[1];
        b = t + (func_003824E0(0.0f, 1.0f) < arg1[1] - (f32)(s32)arg1[1]);
        t = (s32)arg1[2];
        c = t + (func_003824E0(0.0f, 1.0f) < arg1[2] - (f32)(s32)arg1[2]);
        t = (s32)arg1[3];
        d = t + (func_003824E0(0.0f, 1.0f) < arg1[3] - (f32)(s32)arg1[3]);
        if (a > 128) a = 128; else if (a < 0) a = 0;
        if (b > 128) b = 128; else if (b < 0) b = 0;
        if (c > 128) c = 128; else if (c < 0) c = 0;
        if (d > 128) d = 128; else if (d < 0) d = 0;
        *arg0 = (d << 24) | (c << 16) | (b << 8) | a;
    }
}
