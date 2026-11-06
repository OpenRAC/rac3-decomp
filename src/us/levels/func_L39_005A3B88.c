#include "common.h"

/* localdecomp:start func_L39_005A3B88 */
typedef struct {
    u8 reserved0[0x18];
    u16 phase;
    u8 reserved1A[0x12E];
    s32 field148;
    u8 reserved14C[0x10];
    s32 mode;
    u8 reserved160[4];
    s32 selected;
    u8 reserved168[4];
    s32 extra;
} State_L39_005A3B88;

extern State_L39_005A3B88 D_001A4560;
extern s32 D_001D4CEC_sda;

void func_L39_005A3B88(void) {
    State_L39_005A3B88 *state = &D_001A4560;
    if (state->mode != 2 || state->selected >= 0) {
        return;
    }
    if (state->extra != 0) {
        D_001D4CEC_sda = *(s32 *)0x0024057C | 0x40;
        *(s32 *)0x00240578 = 0x14;
    } else {
        state->field148 = 0;
        *(s32 *)0x00240578 = 0x1F;
        state->phase = 0;
    }
}
/* localdecomp:end func_L39_005A3B88 */
