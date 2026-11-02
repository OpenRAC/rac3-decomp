#include "common.h"

/* localdecomp:start func_U_003EB578 */
typedef struct {
    u8 reserved[0x2C];
    u8 *state;
} Owner_003EB578;

void func_U_003EB578(Owner_003EB578 *owner, f32 value) {
    *(f32 *)(owner->state + 0x50) = value;
}
/* localdecomp:end func_U_003EB578 */
