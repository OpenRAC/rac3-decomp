#include "common.h"

INCLUDE_ASM("asm/levels", func_L28_0039F2C0);

INCLUDE_ASM("asm/levels", func_L28_003A0708);

INCLUDE_ASM("asm/levels", func_L28_003A0930);

INCLUDE_ASM("asm/levels", func_L28_003A0B60);

INCLUDE_ASM("asm/levels", func_L28_003A0DC0);

/* localdecomp:start func_L28_003A0EC0 */
extern u16 *D_L28_0021B6A0[];
extern u8 *D_L28_001DEC9C;
__asm__(".extern D_L28_001DEC9C, 16");
extern s32 D_L28_001DECD8;

void func_L28_003A0EC0(u8 *a0) {
    u16 *p;
    u8 *e;
    if (a0[0x21] == 0xFF) return;
    p = D_L28_0021B6A0[a0[0x21]];
    while (a0[0x21] != 0xFF && a0[0x21] <= D_L28_001DECD8 && p != 0 &&
           ((s16)p[-1] >= 0 || p == D_L28_0021B6A0[a0[0x21]])) {
        e = D_L28_001DEC9C + ((*p & 0x7FFF) << 8);
        if (e == 0) break;
        p++;
        if (*(s16 *)(e + 0xAA) == *(s16 *)(a0 + 0xAA)) {
            *(s32 *)(*(u8 **)(e + 0x68) + 0x300) = 1;
        }
    }
}
/* localdecomp:end func_L28_003A0EC0 */
