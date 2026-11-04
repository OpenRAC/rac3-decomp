#include "common.h"

INCLUDE_ASM("asm/levels", func_L19_003CFC58);

INCLUDE_ASM("asm/levels", func_L19_003D0108);

/* localdecomp:start func_L19_003D0130 */
extern s16 D_001426A0[];

s32 func_L19_003D0130(s32 a) {
    f32 f = 0.0f;

    switch (D_001426A0[0]) {
    case 0:
        f = 0.0f;
        break;
    case 1:
        f = 0.33f;
        break;
    case 2:
        f = 0.5f;
        break;
    case 3:
        f = 0.67f;
        break;
    case 4:
        f = 0.8f;
        break;
    }
    if (f <= 0.0f) {
        return a;
    }
    return (s32)((f32)a / f);
}
/* localdecomp:end func_L19_003D0130 */
