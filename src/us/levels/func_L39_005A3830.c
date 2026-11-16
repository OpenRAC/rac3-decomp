#include "common.h"

/* localdecomp:start func_L39_005A3830 */
typedef struct {
    u8 reserved0[0x10];
    s32 field10;
    u8 reserved14[0x148];
    s32 mode;
    s32 field160;
    s32 selected;
    s32 field168;
} State_L39_005A3830;

extern State_L39_005A3830 D_001A4560;
extern s32 D_001D4CEC_sda;

/* When the menu state is mode 2 with nothing selected, selects entry 7, resets two fields, stores
 * 13 in a global and clears bit 0x800 in a flags word. */
void func_L39_005A3830(void) {
    State_L39_005A3830 *state = &D_001A4560;
    if (state->mode == 2 && state->selected < 0) {
        state->field10 = 0;
        state->selected = 7;
        state->field168 = 0;
        *(s32 *)0x00240578 = 13;
        *(s32 *)0x0024057C = D_001D4CEC_sda & ~0x800;
    }
}
/* localdecomp:end func_L39_005A3830 */
