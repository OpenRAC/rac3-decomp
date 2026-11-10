#include "common.h"

/* localdecomp:start func_U_003F0D48 */
typedef struct {
    u8 reserved[0x2C];
    u8 *state;
} Owner_003F0D48;

void func_U_003F0D48(Owner_003F0D48 *owner, s32 value) {
    *(s16 *)(owner->state + 0x4C) = value;
}
/* localdecomp:end func_U_003F0D48 */
