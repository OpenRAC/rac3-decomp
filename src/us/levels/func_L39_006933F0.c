#include "common.h"

/* localdecomp:start func_L39_006933F0 */
typedef struct {
    u8 reserved0[0x2A8];
    s32 count;
    u8 overflow;
} State_L39_006933F0;

void func_L39_006933F0(State_L39_006933F0 *state) {
    s32 next = state->count + 1;
    state->count = next;
    if ((f32)next > 900.0f) {
        state->count = 0;
        state->overflow = 1;
    }
}
/* localdecomp:end func_L39_006933F0 */
