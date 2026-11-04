#include "common.h"

INCLUDE_ASM("asm/levels", func_L23_004E3428);

/* localdecomp:start func_L23_004E8188 */
extern u8 D_001A71C4[];
extern void func_L23_004E3428(s32, s32);

void func_L23_004E8188(s32 a0) {
    s32 m = 1;
    s32 t = D_001A71C4[0];

    if (a0 != 0) {
        m = 2;
    }
    switch (t) {
    case 0:
        func_L23_004E3428(0, m);
        break;
    case 3:
        func_L23_004E3428(0x51, m);
        break;
    case 1:
        func_L23_004E3428(0x3F, m);
        break;
    case 2:
        func_L23_004E3428(0x5A, m);
        break;
    }
}
/* localdecomp:end func_L23_004E8188 */
