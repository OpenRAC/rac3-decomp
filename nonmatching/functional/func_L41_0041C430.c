/* functional: high. Same shape as func_L41_0041B6F0 with its own level slots and only the 0x2D mode; 74 instructions differ (frame, gp addressing, scheduling). */
#include "common.h"
/* localdecomp:start func_L41_0041C430 */
extern s32 D_002412DC;
extern s32 D_L41_00247798 __attribute__((section(".sdata")));
extern s32 D_L41_0024779C __attribute__((section(".sdata")));
extern s32 D_L41_002477A0 __attribute__((section(".sdata")));
extern s32 D_L41_002477A4 __attribute__((section(".sdata")));
extern f32 D_L41_002477A8[5] __attribute__((section(".sdata")));
extern f32 func_L39_005B4410(f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern void *func_L39_005C5FC8(void *, void *, s32, s32, s32, s32, s32, s32);

void func_L41_0041C430(void *obj) {
    s32 skipEven = 0;
    s32 colorA;
    s32 colorB;
    s32 i;
    if (D_002412DC == 0x2D) {
        colorA = 0x7FE9D09F;
        colorB = 0xE9D09F;
        skipEven = 1;
    } else {
        colorA = 0x7F325C66;
        colorB = 0x4C6C74;
    }
    for (i = 0; i < D_L41_002477A4; i++) {
        struct { u32 q[4]; } dir;
        f32 *v = (f32 *)&dir;
        if (skipEven && (i & 1) == 0) {
            continue;
        }
        dir.q[0] = dir.q[1] = dir.q[2] = dir.q[3] = 0;
        v[0] = func_L39_005B4410(D_L41_002477A8[1], D_L41_002477A8[2]);
        v[1] = func_L39_005B4410(D_L41_002477A8[1], D_L41_002477A8[2]);
        v[2] = func_L39_005B4410(D_L41_002477A8[3], D_L41_002477A8[4]);
        func_0038CF68(&dir, &dir, D_L41_002477A8[0] * 0.020000001f);
        func_L39_005C5FC8(obj, &dir, colorA, colorB, D_L41_00247798, D_L41_0024779C, D_L41_002477A0, 0);
    }
}
/* localdecomp:end func_L41_0041C430 */
