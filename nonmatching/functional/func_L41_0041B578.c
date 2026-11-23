/* functional: high. Constants checked against PAL asm; 37 instructions differ (callee-saved float spills and scheduling only). */
#include "common.h"
/* localdecomp:start func_L41_0041B578 */
extern s32 *D_00241120;
extern f32 D_L41_0024824C;
extern f32 func_L39_005B4410(f32, f32);
extern f32 func_L39_005B44C8(void);
extern s32 func_L39_005B43C8(s32, s32);
extern s32 func_L39_005B4398(s32);
extern void func_00382760(void *, f32, f32, f32);
extern u8 *func_L01_003298C8(void *, void *, s32, s32, s32, s32, void *, s32, s32, s32, f32, f32);

void func_L41_0041B578(void *obj, f32 scale, f32 lo, f32 hi) {
    if (*D_00241120 < 3) {
        u32 vec[4];
        s32 flag = 0;
        f32 a;
        f32 b;
        f32 c;
        u8 *e;
        a = func_L39_005B4410(10.0f, 20.0f) * 0.020000001f;
        a *= scale;
        b = func_L39_005B44C8();
        c = func_L39_005B4410(0.43633232f, 0.78539819f);
        func_00382760(vec, a, b, c);
        if (func_L39_005B4398(3) != 0) {
            if (D_L41_0024824C < 0.8f) {
                flag = 1;
            }
        }
        e = func_L01_003298C8(obj, vec, func_L39_005B43C8(100, 120), 3, flag, 0x80808080, 0, 1, 0x32, 0x78, 1.0f, 14.6f);
        if (e != 0) {
            *(f32 *)(e + 0x2C) *= func_L39_005B4410(lo, hi);
        }
    }
}
/* localdecomp:end func_L41_0041B578 */
