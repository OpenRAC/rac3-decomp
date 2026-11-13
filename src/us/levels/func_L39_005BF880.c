#include "common.h"

/* localdecomp:start func_L39_005BF880 */
extern u8 D_L39_002257E0[];
extern void func_00388550(void *, void *, s32);
extern void func_00388440(void *, s32, s32);
extern void func_00194978(s32);

s32 func_L39_005BF880(void) {
    u8 *state = D_L39_002257E0;
    if (*(s16 *)(state + 0x76) == 0) {
        if (*(s16 *)(state + 0x9E) == 3) {
            if (*(s32 *)(state + 0x94) != 0) {
                func_00388550(state + 0x6C, state + 0x94, 0x28);
                func_00388440(state + 0x94, 0, 0x28);
                *(s16 *)(state + 0x98) = -1;
                *(s32 *)(state + 0xB4) = -1;
                func_00194978(*(s32 *)(state + 0x6C));
                *(s16 *)(state + 0x76) = 4;
                return 1;
            }
        }
    }
    return 0;
}
/* localdecomp:end func_L39_005BF880 */
