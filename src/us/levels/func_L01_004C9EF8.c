#include "common.h"

/* localdecomp:start func_L01_004C9EF8 */
extern s32 func_L01_00410120(void *, s32);
extern s32 func_L01_004100D8_004C9EF8(void *, s32);

void func_L01_004C9EF8(u8 *o, s32 mode, s32 v, f32 x, f32 y) {
    u8 *p = o + 0x88;
    **(f32 **)o = x;
    *(*(f32 **)o + 1) = y;
    *(s32 *)(o + 0x198) = v;
    o[0x187] = 0;
    *(u8 **)(o + 0x1B8) = p;
    *(s32 *)(o + 0x1A4) = mode;
    switch (mode) {
    case 0:
        *(s32 *)(o + 0x1B4) = func_L01_00410120(p, -1);
        break;
    case 1:
        *(s32 *)(o + 0x1B4) = func_L01_004100D8_004C9EF8(p, -1);
        break;
    case 2:
    case 3:
        break;
    }
    *(s32 *)(o + 0x190) = 1;
    **(f32 **)(o + 4) = 1.0f;
}
/* localdecomp:end func_L01_004C9EF8 */
