#include "common.h"

/* localdecomp:start func_L01_0050DB10 */
extern u8 D_001A4BE0[];
extern void func_L01_004FC518(s32, s32);

/* Changes the hero's state to 0 when its f170 value is under 0.045 or its mode is 0x69, otherwise
 * to state 3, via hero_change_state. */
void func_L01_0050DB10(void) {
    u8 *state = D_001A4BE0;
    if (*(f32 *)(state + 0x170) < 0.045000001f) {
        func_L01_004FC518(0, 1);
    } else if (*(s32 *)(state + 0x25C4) == 0x69) {
        func_L01_004FC518(0, 1);
    } else {
        func_L01_004FC518(3, 1);
    }
}
/* localdecomp:end func_L01_0050DB10 */
