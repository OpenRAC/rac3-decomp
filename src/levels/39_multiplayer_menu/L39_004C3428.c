#include "common.h"

/* localdecomp:start func_L39_004C3428 */
s32 func_0011D534();
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);
void *func_L39_004BEED8(s32);

void *func_L39_004C3428(void) {
    void *p;
    p = func_L39_004BEED8(0x70);
    if (p == 0) {
        func_L39_004BC6C8(0x14, 0xA3, 0x21, 0, 0);
        return 0;
    }
    func_0011D534(p, 0, 0x70);
    *(void **)((u8 *)p + 4) = (u8 *)p + 0x40;
    *(s32 *)((u8 *)p + 0x6C) = 1;
    return p;
}
/* localdecomp:end func_L39_004C3428 */

INCLUDE_ASM("asm/levels", func_L39_004C3498);

INCLUDE_ASM("asm/levels", func_L39_004C35C8);

INCLUDE_ASM("asm/levels", func_L39_004C35D8);
