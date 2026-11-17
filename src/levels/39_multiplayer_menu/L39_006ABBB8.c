#include "common.h"

/* localdecomp:start func_L39_006ABBB8 */
s32 func_00120884(u8 *);

/* from rac4-decomp's func_L00_0071AC50, renamed, constants adapted */
u8 *func_L39_006ABBB8(u8 *object) {
    u8 *text = object + 0x2c8;
    s32 length = func_00120884(text) - 1;
    if (length > 0 && text[length] == 0x20) {
        do {
            length--;
        } while (length > 0 && text[length] == 0x20);
    }
    text[length + 1] = 0;
    return text;
}
/* localdecomp:end func_L39_006ABBB8 */

LINKER_REMNANT("asm/levels", func_L39_006ABC28);
