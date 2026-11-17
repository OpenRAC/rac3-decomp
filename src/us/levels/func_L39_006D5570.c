#include "common.h"

/* localdecomp:start func_L39_006D5570 */
extern void func_001962D8(s32);

/* Clears three words at 0x10, 0x14 and 0x18 of the object and calls func_001962D8 with 0. */
void func_L39_006D5570(u8 *object) {
    *(s32 *)(object + 0x10) = 0;
    *(s32 *)(object + 0x14) = 0;
    *(s32 *)(object + 0x18) = 0;
    func_001962D8(0);
}
/* localdecomp:end func_L39_006D5570 */
