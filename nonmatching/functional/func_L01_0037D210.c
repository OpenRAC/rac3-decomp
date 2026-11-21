/* functional: high. 56 words differ (COP2 load order, scheduling); the loop, constants and both branches re-read against the asm. */
/* localdecomp:start func_L01_0037D210 */
#include "vu0.h"
void func_L01_0037D210(void *arg0, u8 *arg1) {
    extern void func_L01_0037C860(vu0_v4 *, vu0_v4 *, vu0_v4 *, vu0_v4 *, vu0_v4 *, f32);
    extern s32 func_00382498(s32, s32);
    extern void func_L01_0037D358(void *, s32, vu0_v4 *, s32);
    vu0_v4 points[9];
    vu0_v4 a, b, c;
    s32 i;
    vu0_q x, y, z;
    for (i = 0; i < 8; i++) {
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(vu0_v4 *)(arg1 + 32)));
        *(vu0_q *)&a = *(vu0_q *)(arg1 + 0);
        __asm__("lqc2 %0, %1" : "=j"(z) : "m"(*(vu0_v4 *)(arg1 + 48)));
        __asm__("sqc2 %1, %0" : "=m"(c) : "j"(z));
        *(vu0_q *)&b = *(vu0_q *)(arg1 + 16);
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(a));
        __asm__("vadd.xyz %0, %0, %1" : "+j"(x) : "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(a) : "j"(x));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(b));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(c));
        __asm__("vadd.xyz %0, %0, %1" : "+j"(x) : "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(b) : "j"(x));
        func_L01_0037C860(&points[i], (vu0_v4 *)(arg1 + 32), (vu0_v4 *)(arg1 + 48), &a, &b, (f32)i / 7.0f);
    }
    if (*(s32 *)(arg1 + 152) >= (*(s32 *)(arg1 + 156) >> 1)) {
        func_L01_0037D358(arg0, func_00382498(16, 32), points, 9);
    } else {
        func_L01_0037D358(arg0, func_00382498(0, 16), points, 9);
    }
}
/* localdecomp:end func_L01_0037D210 */
