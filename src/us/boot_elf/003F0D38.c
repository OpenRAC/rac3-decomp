#include "common.h"

/* localdecomp:start func_U_003F0D38 */
typedef struct {
    u8 reserved[0x2C];
    u8 *state;
} Owner_003F0D38;

void func_U_003F0D38(Owner_003F0D38 *owner, f32 value) {
    *(f32 *)(owner->state + 0x50) = value;
}
/* localdecomp:end func_U_003F0D38 */
