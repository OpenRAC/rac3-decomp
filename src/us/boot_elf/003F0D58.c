#include "common.h"

/* localdecomp:start func_U_003F0D58 */
typedef struct {
    u8 reserved[0x2C];
    u8 *state;
} Owner_003F0D58;

void func_U_003F0D58(Owner_003F0D58 *owner, s32 value) {
    *(s16 *)(owner->state + 0x54) = value;
}
/* localdecomp:end func_U_003F0D58 */
