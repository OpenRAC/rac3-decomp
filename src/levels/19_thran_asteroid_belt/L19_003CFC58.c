#include "common.h"

INCLUDE_ASM("asm/levels", func_L19_003CFC58);

/* localdecomp:start func_L19_003D0108 */
/* m2c3 */
s32 func_L01_0040C948(s32, s32 *);              /* extern */
extern s32 D_001D64E0;

void func_L19_003D0108(void *arg0) {
    func_L01_0040C948((*(s32 *)((u8 *)(arg0) + 0x68)) + 0x90, &D_001D64E0);
}
/* localdecomp:end func_L19_003D0108 */

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
