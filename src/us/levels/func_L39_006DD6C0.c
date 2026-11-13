#include "common.h"

/* NTSC-U counterpart of func_L39_006E0220 (src/levels/39_multiplayer_menu/L39_006DC228.c) */
/* localdecomp:start func_L39_006DD6C0 */
extern u8 D_001A5F0D[];
extern u8 D_001A6AD0[];

s32 func_L39_006DD6C0(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_a3 = 0;
    f32 *p;

    if (D_001A5F0D[0] != 0) {
        if (arg0 >= 2) {
            temp_a3 = arg1 >= 2;
        }
    }
    arg1 = temp_a3;
    if (arg1 != 0) {
        p = (f32 *)D_001A6AD0;
        if (p[0x110 / 4] <= 0.0f) {
            arg1 = 0;
        } else if (arg2 >= 2) {
            if (p[0x10C / 4] <= 0.0f) {
                arg1 = 0;
            }
        }
    }
    return arg1;
}
/* localdecomp:end func_L39_006DD6C0 */
