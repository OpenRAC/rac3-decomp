#include "common.h"

/* localdecomp:start func_L01_003F3698 */
typedef struct {
    u8 pad[80];
    u8 *obj;
    u8 pad2[1120 - 84];
} Slot;

extern Slot D_L01_001E2A40[];

void func_L01_003F3698(s32 i) {
    Slot *s = &D_L01_001E2A40[i];
    *(s16 *)(s->obj + 126) = 1;
    *(s->obj + 125) = 0;
}
/* localdecomp:end func_L01_003F3698 */
