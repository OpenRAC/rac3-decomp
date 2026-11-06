#include "common.h"

/* localdecomp:start func_L39_0063A9F8 */
extern void func_L39_00674710(u8);

void func_L39_0063A9F8(void *object, s32 enabled) {
    u8 *state = object;
    if ((state[0x1A14] != 0 || enabled != 0) && *(s32 *)(state + 0x251C) != 0) {
        *(s32 *)(state + 0x251C) = 0;
        *(s8 *)(state + 0x24AA) = 1;
        func_L39_00674710(state[0x24C9]);
        if (*(s16 *)(state + 0x24A8) == 0) {
            *(s16 *)(state + 0x24A8) = 0x14;
        }
    }
}
/* localdecomp:end func_L39_0063A9F8 */
