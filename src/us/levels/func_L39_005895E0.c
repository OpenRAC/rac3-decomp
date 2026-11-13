#include "common.h"

/* NTSC-U counterpart of func_L39_0058A750 (src/levels/shared/L39_0058A5D0.c) */
/* localdecomp:start func_L39_005895E0 */
extern s32 D_L39_002405E8_005895E0;
extern s32 D_L39_0025CFF4[];
extern s32 D_L39_002415F0;
extern u8 D_001A5A3D[];
extern f32 func_0038D098_005895E0(f32);
extern s32 func_0038DBD8_005895E0(f32, s32, s32);
extern void func_0038E150_005895E0(s32);
extern s32 func_00381FF0_005895E0(s32);
extern void func_0038E7E8_0058A750(long, f32, s32, f32, s32, f32, f32, s32, s32, unsigned long, f32, f32);

void func_L39_005895E0(void) {
    s32 col;
    f32 colf;
    f32 t;
    s32 save;

    if (D_L39_002405E8_005895E0 == 1) {
        col = 0x5A;
        t = (f32)(D_L39_0025CFF4[0] % 100) / 50.0f - 1.0f;
        if (D_001A5A3D[0] != 0) {
            col = 0x30;
        }
        if (t < -1.0f) t = -1.0f;
        if (t > 1.0f) t = 1.0f;
        colf = (f32)col;
        col = func_0038DBD8_005895E0((func_0038D098_005895E0(t * 3.14159274f) + 1.0f) * 0.5f, 0x7FE0E0E0, 0x5F66CCFF);
        save = D_L39_002415F0;
        func_0038E150_005895E0(0);
        func_0038E7E8_0058A750(col, 480.0f, func_00381FF0_005895E0(0x244), colf, -1, 1.0f, 1.0f, 2, 1, 0x80000000, 1.0f, 1.0f);
        func_0038E150_005895E0(save);
    }
}
/* localdecomp:end func_L39_005895E0 */
