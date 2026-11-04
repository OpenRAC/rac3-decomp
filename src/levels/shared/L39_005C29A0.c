#include "common.h"

/* localdecomp:start func_L39_005C29A0 */
extern s32 func_194970(s32, s32, s32, void *);
extern u8 D_00225660[];

s32 func_L39_005C29A0(s32 a, s32 b, s32 count)
{
    u8 *state = D_00225660;
    if (*(s16 *)(state + 4) == 0 && count != 0) {
        *(s32 *)(state + 0x18) = 0;
        *(s32 *)(state + 0x1c) = 0;
        if (func_194970(b, count, a, state + 0x40)) {
            *(s32 *)(state + 0x14) = a;
            *(s16 *)(state + 4) = 1;
            *(s32 *)(state + 8) = b;
            *(s32 *)(state + 0x10) = count;
            return count << 11;
        }
    }
    return 0;
}
/* localdecomp:end func_L39_005C29A0 */
