#include "common.h"

/* localdecomp:start func_L07_003B7490 */
typedef int Q_003B7490 __attribute__((mode(TI)));
extern u8 *D_L07_0021EC98[];
void func_L07_003B7490(u8 *obj) {
    extern void func_003BF6A8(void *, f32);
    extern f32 func_0037E250(f32, f32);
    extern f32 func_0037E2A8(void);
    extern void func_0037E4B8(void *, f32, f32, f32);
    extern s32 func_0037E208(s32, s32);
    extern s32 func_003894A0(s32, s32, f32);
    extern s32 func_0037E1D8(s32);
    extern u8 *func_L01_0046C468(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);
    Q_003B7490 pos, vel;
    f32 speed, angle, pitch, x, y, z;
    s32 time, color;
    s32 i;
    u8 *particle;
    i = 119;
    do {
        pos = *(Q_003B7490 *)(obj + 0x10);
        func_003BF6A8(&pos, 2.0f);
        speed = func_0037E250(0.083333336f, 0.16666667f);
        angle = func_0037E2A8();
        pitch = func_0037E250(0.0f, 0.785398006439209f);
        func_0037E4B8(&vel, speed, angle, pitch);
        func_003BF6A8(&vel, 0.050000004f);
        time = func_0037E208(40, 80);
        color = func_003894A0(0x808080, 0xFFFFFF, func_0037E250(0.0f, 1.0f));
        x = func_0037E250(210000.0f, 315000.0f);
        y = func_0037E250(630000.0f, 1050000.0f);
        z = func_0037E250(0.0013888889f, 0.0027777778f);
        particle = func_L01_0046C468(&pos, &vel, time, color, func_0037E1D8(2) ? 3 : -3, 96, 0, x, y, z, 0);
        if (particle) {
            u8 value = D_L07_0021EC98[0x7C][1];
            particle[3] = 68;
            particle[2] = value;
        }
    } while (--i >= 0);
}
/* localdecomp:end func_L07_003B7490 */
