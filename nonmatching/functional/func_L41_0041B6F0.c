/* functional: high. Level-slot floats declared as one small-data array; 63 instructions differ (retail builds the direction in a 16-byte local at +0x10 then copies it, stack frame/scheduling only). */
#include "common.h"
/* localdecomp:start func_L41_0041B6F0 */
extern s32 *D_00241120;
extern s32 D_002412DC;
extern s32 D_L41_00247724 __attribute__((section(".sdata")));
extern s32 D_L41_00247728 __attribute__((section(".sdata")));
extern s32 D_L41_0024772C __attribute__((section(".sdata")));
extern s32 D_L41_00247730 __attribute__((section(".sdata")));
extern f32 D_L41_00247734[] __attribute__((section(".sdata")));
extern f32 func_L39_005B4410(f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern void *func_L39_005C5FC8(void *, void *, s32, s32, s32, s32, s32, s32);

void func_L41_0041B6F0(void *obj) {
    s32 skipEven = 0;
    s32 colorA;
    s32 colorB;
    s32 n;
    s32 i;
    if (D_002412DC == 0x2D || D_002412DC == 0x37) {
        colorA = 0x7FE9D09F;
        colorB = 0xE9D09F;
        skipEven = 1;
    } else {
        colorA = 0x7F325C66;
        colorB = 0x4C6C74;
    }
    n = D_L41_00247730;
    if (*D_00241120 >= 3) {
        n = n / 5;
    }
    for (i = 0; i < n; i++) {
        struct { u32 q[4]; } dir;
        f32 *v = (f32 *)&dir;
        if (skipEven && (i & 1) == 0) {
            continue;
        }
        dir.q[0] = dir.q[1] = dir.q[2] = dir.q[3] = 0;
        v[0] = func_L39_005B4410(D_L41_00247734[1], D_L41_00247734[2]);
        v[1] = func_L39_005B4410(D_L41_00247734[1], D_L41_00247734[2]);
        v[2] = func_L39_005B4410(D_L41_00247734[3], D_L41_00247734[4]);
        func_0038CF68(&dir, &dir, D_L41_00247734[0] * 0.020000001f);
        func_L39_005C5FC8(obj, &dir, colorA, colorB, D_L41_00247724, D_L41_00247728, D_L41_0024772C, 0);
    }
}
/* localdecomp:end func_L41_0041B6F0 */
