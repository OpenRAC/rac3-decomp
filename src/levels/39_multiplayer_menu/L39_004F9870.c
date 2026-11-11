#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_004F9870);

/* localdecomp:start func_L39_004F9A20 */
extern void func_L39_004BC6C8(s32, s32, s32, s32, s32);
extern void *func_L39_004BEED8(s32);

/* from rac4-decomp's func_L00_00535830, renamed */
void *func_L39_004F9A20(void) {
    u8 *object = func_L39_004BEED8(0x18);
    if (object != 0) {
        *(s32 *)(object + 0x14) = 1;
        *(s32 *)(object + 0xC) = 0;
        *(s32 *)(object + 0x10) = 0;
        *(s32 *)(object + 8) = 0;
        *(s32 *)object = 0;
        *(s32 *)(object + 4) = 0;
        return object;
    }
    func_L39_004BC6C8(0xD, 0x71, 0x21, 0, 0);
    return 0;
}
/* localdecomp:end func_L39_004F9A20 */
