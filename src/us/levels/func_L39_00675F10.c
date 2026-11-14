#include "common.h"

/* NTSC-U counterpart of func_L39_006788F8 (src/levels/shared/L39_00677F28.c) */
/* localdecomp:start func_L39_00675F10 */
typedef struct {
    u8 pad0[0x10];
    s32 f10;
    s32 f14;
} S_006788F8;
extern s32 func_00388398(void *);
extern void func_003B8B10(f32);
extern S_006788F8 D_L39_00352DE0_00675F10;

s32 func_L39_00675F10(s32 a0) {
    S_006788F8 *d = &D_L39_00352DE0_00675F10;
    s32 r = 0;
    switch (d->f14) {
    case 0:
        if (func_00388398(&d->f10)) {
            d->f14 = 1;
            d->f10 = 30;
        }
        func_003B8B10(1.0f);
        break;
    case 1:
        if (func_00388398(&d->f10)) {
            d->f14 = 2;
            d->f10 = 300;
        }
        func_003B8B10((f32)d->f10 / 30.0f);
        break;
    case 2:
        if (func_00388398(&d->f10)) {
            d->f14 = 3;
            d->f10 = 30;
        }
        func_003B8B10(0.0f);
        break;
    case 3:
        if (a0 != 0) {
            if (func_00388398(&d->f10)) {
                r = 1;
            }
        }
        func_003B8B10(1.0f - (f32)d->f10 / 30.0f);
        break;
    }
    return r;
}
/* localdecomp:end func_L39_00675F10 */
