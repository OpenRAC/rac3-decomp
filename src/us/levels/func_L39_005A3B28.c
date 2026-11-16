#include "common.h"

/* localdecomp:start func_L39_005A3B28 */
typedef struct {
    u8 reserved0[0x15C];
    s32 mode;
    s32 field160;
    s32 selected;
    s32 field168;
} State_L39_005A3B28;

extern State_L39_005A3B28 D_001A4560;
extern s32 D_001D4CEC_sda;

/* If the menu is in mode 2 with nothing selected, selects entry 9, clears bits 2 and 0x10 of the
 * flags word, zeroes field 0x168 and sets the screen state to 0x11. */
void func_L39_005A3B28(void) {
    State_L39_005A3B28 *state = &D_001A4560;
    s32 flags;
    if (state->mode == 2 && state->selected < 0) {
        flags = D_001D4CEC_sda;
        flags &= ~2;
        flags &= ~0x10;
        state->selected = 9;
        *(s32 *)0x0024057C = flags;
        state->field168 = 0;
        *(s32 *)0x00240578 = 0x11;
    }
}
/* localdecomp:end func_L39_005A3B28 */
