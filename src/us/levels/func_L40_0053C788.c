#include "common.h"

/* localdecomp:start func_L40_0053C788 */
typedef struct {
    u8 reserved0[0x30];
    u8 active;
    u8 reserved31[0xB];
    s32 setting3C;
    s32 setting40;
} State_L40_0053C788;

typedef struct {
    u8 reserved0[0x90];
    State_L40_0053C788 *state;
} Owner_L40_0053C788;

extern s32 D_001A5E58[];

s32 func_L40_0053C788(Owner_L40_0053C788 *owner, s32 value) {
    State_L40_0053C788 *state = owner->state;
    if (state != 0) {
        state->active = 1;
        state->setting3C = D_001A5E58[0];
        state->setting40 = value;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L40_0053C788 */
