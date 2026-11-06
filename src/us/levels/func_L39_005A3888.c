#include "common.h"

/* localdecomp:start func_L39_005A3888 */
typedef struct {
    u8 reserved0[8];
    s32 mode08;
    s32 value0C;
    u8 reserved10[8];
    s16 phase18;
    u8 reserved1A[6];
    s32 value20;
    u8 reserved24[0x138];
    s32 mode15C;
    s32 field160;
    s32 selected164;
    s32 field168;
    s32 extra16C;
} State_L39_005A3888;

extern State_L39_005A3888 D_001A4560;
extern s32 D_001D4CE8_sda;

void func_L39_005A3888(void) {
    State_L39_005A3888 *state = &D_001A4560;
    s16 phase;
    if (state->mode15C != 2 || state->selected164 >= 0) {
        return;
    }
    if (state->extra16C != 0) {
        D_001D4CE8_sda = 14;
        return;
    }
    if (state->mode08 != 2) {
        D_001D4CE8_sda = 4;
        return;
    }
    phase = state->phase18;
    if (phase == -2) {
        if (state->value0C + state->value20 < 600) {
            D_001D4CE8_sda = 21;
        } else {
            D_001D4CE8_sda = 14;
        }
        return;
    }
    if (phase >= -1) {
        *(s32 *)0x00240578 = 18;
    }
}
/* localdecomp:end func_L39_005A3888 */
