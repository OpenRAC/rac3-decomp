#include "common.h"

/* localdecomp:start func_L39_005BF880 */
extern u8 D_L39_002257E0[];
extern void func_00388550(void *, void *, s32);
extern void func_00388440(void *, s32, s32);
extern void func_00194978(s32);

/* If the state's flag at +0x76 is 0, its mode at +0x9E is 3 and a pending entry exists at +0x94,
 * moves that 0x28-byte entry to +0x6C, clears the old one, marks it taken, sets +0x76 to 4 and
 * returns 1; else returns 0. */
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
