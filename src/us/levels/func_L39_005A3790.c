#include "common.h"

/* localdecomp:start func_L39_005A3790 */
typedef struct {
    u8 reserved0[0x15C];
    s32 mode;
    u8 reserved160[4];
    s32 selected;
    u8 reserved168[4];
    s32 extra;
} State_L39_005A3790;

extern State_L39_005A3790 D_001A4560;
extern s32 D_001D4CEC_sda;

/* Probably part of the save card menu: when the menu mode is 2 and nothing is selected, sets the
 * next screen to 0x13 (adding flag 0x40 to a global) if extra is set, else to 0x10. */
void func_L39_005A3790(void) {
    State_L39_005A3790 *state = &D_001A4560;
    if (state->mode != 2 || state->selected >= 0) {
        return;
    }
    if (state->extra != 0) {
        *(s32 *)0x00240578 = 0x13;
        D_001D4CEC_sda = *(s32 *)0x0024057C | 0x40;
        return;
    }
    *(s32 *)0x00240578 = 0x10;
}
/* localdecomp:end func_L39_005A3790 */
