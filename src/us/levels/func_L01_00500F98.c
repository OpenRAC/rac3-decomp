#include "common.h"

/* localdecomp:start func_L01_00500F98 */
extern u8 D_001A4BE0[];
extern void func_L01_004E6CB0(void);
extern void func_L01_004FC518(s32, s32);

s32 func_L01_00500F98(void) {
    u8 *state = D_001A4BE0;
    s32 mode = *(s32 *)(state + 0x25C4);
    if (mode != 2 && mode != 3 && mode != 0) {
        return 0;
    }
    if (state[0x25E9] == 0) {
        return 0;
    }
    if (*(s32 *)(state + 0x1D8) >= 6) {
        return 0;
    }
    if (*(f32 *)(state + 0x2838) < 0.7f) {
        if (state[0x25EC] != 0) {
            return 0;
        }
        func_L01_004E6CB0();
        *(s32 *)(state + 0xE84) = 2;
        func_L01_004FC518(0x22, 1);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_00500F98 */
