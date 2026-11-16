#include "common.h"

/* localdecomp:start func_L30_003455A0 */
typedef struct {
    u8 reserved0[0x1C];
    f32 value1C;
    s32 value20;
} Inner_L30_003455A0;

typedef struct {
    u8 reserved0[0x18];
    f32 value18;
    u8 reserved1C[0x4C];
    Inner_L30_003455A0 *inner;
} State_L30_003455A0;

/* Copies the float at +0x18 of the state into the inner record's +0x1C and sets the inner record's
 * +0x20 to -1. */
void func_L30_003455A0(State_L30_003455A0 *state) {
    Inner_L30_003455A0 *inner = state->inner;
    inner->value1C = state->value18;
    inner->value20 = -1;
}
/* localdecomp:end func_L30_003455A0 */
