#include "common.h"

/* localdecomp:start func_L40_0041D8F0 */
extern u8 *D_L40_0024845C;
extern s32 *D_L40_0035746C __attribute__((section(".data")));
extern s32 func_L39_005601D0(s32);
extern void func_L40_0041D448(s32, s32, s32);

s32 func_L40_0041D8F0(u8 *a0, s32 a1) {
    u8 *v = *(u8 **)(a0 + 0x68);
    s32 idx;
    u8 *w;
    f32 f;
    s32 on;

    if (a1 != 0) {
        return 0;
    }
    if (*(s32 *)(v + 0x20) != 0) {
        return 0;
    }
    idx = *(s32 *)(v + 0x3C);
    if (idx >= 0) {
        w = *(u8 **)(D_L40_0024845C + (idx << 8) + 0x68);
        f = *(f32 *)w;
        if (f == 1.0f || f == 0.0f) {
            on = 0;
            if (f == 1.0f) {
                on = 1;
            }
            if (*(s32 *)((u8 *)D_L40_0035746C + (*(s32 *)(v + 0x2C) << 2) + 0xA8) == on) {
                return 0;
            }
            if (func_L39_005601D0((s32)a0) != 0) {
                return 0;
            }
            func_L40_0041D448((s32)a0, on, *(s32 *)(w + 0x5C));
        } else {
            return 0;
        }
    }
    return 0;
}
/* localdecomp:end func_L40_0041D8F0 */
