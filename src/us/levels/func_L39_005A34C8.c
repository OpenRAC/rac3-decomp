#include "common.h"

extern s32 D_001A4560[];

/* localdecomp:start func_L39_005A34C8 */
void func_L39_005A34C8(void) {
    s32 flags;
    s32 initial_mode;
    s32 button_mode;
    s32 updated_flags;
    if (D_001A4560[2] != 2) {
        initial_mode = 4;
    } else {
        flags = *(s32 *)0x0024057C;
        if (flags & 4) {
            initial_mode = 0x1E;
        } else if (flags & 2) {
            initial_mode = 0x1D;
        } else {
            goto check_buttons;
        }
    }
    *(s32 *)0x00240578 = initial_mode;
    flags = *(s32 *)0x0024057C;
check_buttons:
    if (flags & 0x80) {
        updated_flags = flags ^ 0x80;
        button_mode = 0x18;
    } else if (flags & 0x100) {
        updated_flags = flags ^ 0x100;
        button_mode = 0x16;
    } else {
        return;
    }
    *(s32 *)0x00240578 = button_mode;
    *(s32 *)0x0024057C = updated_flags | 0x40;
}
/* localdecomp:end func_L39_005A34C8 */
