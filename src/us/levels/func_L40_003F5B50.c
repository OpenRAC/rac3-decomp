#include "common.h"

/* localdecomp:start func_L40_003F5B50 */
typedef struct {
    u8 reserved0[0x40];
    s32 active;
    u8 reserved44[0x74];
    s32 rank;
} State_L40_003F5B50;

typedef struct {
    u8 reserved0[0x68];
    State_L40_003F5B50 *state;
    u8 reserved6C[0x3E];
    s16 id;
} Owner_L40_003F5B50;

s32 func_L40_003F5B50(Owner_L40_003F5B50 *owner) {
    s32 result = 1;
    if (owner->id == 0xCBE) {
        State_L40_003F5B50 *state = owner->state;
        if (state->active != 0 || state->rank >= 3) {
            result = 0;
        }
    }
    return result;
}
/* localdecomp:end func_L40_003F5B50 */
