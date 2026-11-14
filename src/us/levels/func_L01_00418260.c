#include "common.h"

/* localdecomp:start func_L01_00418260 */
typedef struct {
    s32 value0;
    u8 reserved4[0x34];
    s16 active38;
    u8 reserved3A[2];
    s32 timer3C;
} State_L01_00418260;

extern State_L01_00418260 D_L01_002E5F70;
extern void func_L01_00417ED8(void);

/* Once only: sets the active flag, a 60-frame timer and calls dismiss_help, and defaults value0 to
 * 8 if it was 0. */
void func_L01_00418260(void) {
    State_L01_00418260 *state = &D_L01_002E5F70;
    if (state->active38 == 0) {
        state->active38 = 1;
        state->timer3C = 60;
        func_L01_00417ED8();
        if (state->value0 == 0) {
            state->value0 = 8;
        }
    }
}
/* localdecomp:end func_L01_00418260 */
