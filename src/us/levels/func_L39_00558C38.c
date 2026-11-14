#include "common.h"

/* localdecomp:start func_L39_00558C38 */
typedef struct {
    u8 reserved0[0x14C];
    u8 active;
    u8 reserved14D;
    u16 counter;
} State_L39_00558C38;

typedef struct {
    u8 reserved0[0x68];
    State_L39_00558C38 *state;
} Owner_L39_00558C38;

/* Counts up state->counter while the state is active, and at 301 clears both the active flag and
 * the counter. */
void func_L39_00558C38(Owner_L39_00558C38 *owner) {
    State_L39_00558C38 *state = owner->state;
    if (state->active == 1) {
        s32 next = state->counter + 1;
        state->counter = next;
        if ((s16)next >= 301) {
            state->active = 0;
            state->counter = 0;
        }
    }
}
/* localdecomp:end func_L39_00558C38 */
