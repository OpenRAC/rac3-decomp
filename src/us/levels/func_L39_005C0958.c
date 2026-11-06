#include "common.h"

/* localdecomp:start func_L39_005C0958 */
extern s32 func_00194A60(s32, s32, s32, void *);
extern u8 D_L39_002257E0[];

s32 func_L39_005C0958(s32 first, s32 second, s32 count) {
    u8 *state = D_L39_002257E0;
    if (*(s16 *)(state + 4) == 0 && count != 0) {
        *(s32 *)(state + 0x18) = 0;
        *(s32 *)(state + 0x1C) = 0;
        if (func_00194A60(second, count, first, state + 0x40)) {
            *(s32 *)(state + 0x14) = first;
            *(s16 *)(state + 4) = 1;
            *(s32 *)(state + 8) = second;
            *(s32 *)(state + 0x10) = count;
            return count << 11;
        }
    }
    return 0;
}
/* localdecomp:end func_L39_005C0958 */
