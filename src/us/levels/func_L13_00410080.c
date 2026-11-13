#include "common.h"

/* localdecomp:start func_L13_00410080 */
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
} State_L13_00410080;

extern State_L13_00410080 D_00142430;
extern s32 D_001D4CE8;
extern s32 D_001D4CEC;
extern s32 D_001D4CEC_sda_00410080;
__asm__(".extern D_001D4CEC_sda_00410080, 4");

void func_L13_00410080(void) {
    State_L13_00410080 *state = &D_00142430;
    if (state->mode != 2 || state->selected >= 0) {
        return;
    }
    if (state->extra != 0) {
        D_001D4CEC_sda_00410080 = D_001D4CEC | 0x40;
        D_001D4CE8 = 0x14;
    } else {
        state->field148 = 0;
        D_001D4CE8 = 0x1F;
        state->phase = 0;
    }
}
/* localdecomp:end func_L13_00410080 */
