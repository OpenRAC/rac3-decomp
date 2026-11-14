#include "common.h"

/* localdecomp:start func_L39_004E2D20 */
extern void *func_L39_004BEED8(s32);
extern u8 D_0046D2B0[];

void *func_L39_004E2D20(void) {
    u8 *object = func_L39_004BEED8(0x10);
    if (object != 0) {
        *(s32 *)(object + 0xC) = 1;
        *(s32 *)object = (s32)D_0046D2B0;
        *(s32 *)(object + 4) = 0;
        *(s32 *)(object + 8) = 0;
        return object;
    }
    return 0;
}
/* localdecomp:end func_L39_004E2D20 */
