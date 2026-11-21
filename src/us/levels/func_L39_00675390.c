#include "common.h"

/* NTSC-U counterpart of func_L39_00677D78 (src/levels/shared/L39_00677D78.c) */
/* localdecomp:start func_L39_00675390 */
typedef struct {
    u8 pad0[0x10];
    s32 f10;
} S_00677D78;
extern s32 func_003B8A20(void);
extern s32 func_00388398(void *);
extern void func_003B8B10(f32);
extern s32 D_L39_00240408_00675390;
extern s32 D_L39_0024D128_00675390;
extern f32 D_L39_0024D138_00675390;
extern S_00677D78 D_L39_00352DE0_00675390;

s32 func_L39_00675390(s32 a0) {
    s32 r = 0;
    if (func_003B8A20() != 0) {
        (&D_L39_00240408_00675390)[1] = 0;
    }
    switch (D_L39_0024D128_00675390) {
    case 0:
        if (func_00388398(&(&D_L39_0024D128_00675390)[1]) != 0) {
            D_L39_0024D128_00675390 = 1;
            (&D_L39_0024D128_00675390)[1] = 0x5A;
        } else {
            (&D_L39_0024D138_00675390)[1] = (f32)(&D_L39_0024D128_00675390)[1] / 90.0f;
        }
        break;
    case 1:
        if (func_00388398(&(&D_L39_0024D128_00675390)[1]) != 0) {
            D_L39_0024D128_00675390 = 2;
            (&D_L39_0024D128_00675390)[1] = 0x1E;
        }
        (&D_L39_0024D138_00675390)[1] = 0.0f;
        break;
    case 2:
        if (func_00388398(&(&D_L39_0024D128_00675390)[1]) != 0) {
            r = a0;
        }
        (&D_L39_0024D138_00675390)[1] = 1.0f - (f32)D_L39_00352DE0_00675390.f10 / 30.0f;
        break;
    }
    func_003B8B10(0.0f);
    return r;
}
/* localdecomp:end func_L39_00675390 */
