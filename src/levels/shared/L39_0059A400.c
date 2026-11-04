#include "common.h"

typedef struct Slot_0059A400 {
    s32 value;
    s32 extra;
} Slot_0059A400;
typedef struct Ring_0059A400 {
    s32 f00;
    s32 f04;
    Slot_0059A400 slots[10];
    s32 f58;
    s32 f5C;
} Ring_0059A400;

/* localdecomp:start func_L39_0059A400 */
extern u32 D_1A4B50[];

void func_L39_0059A400(Ring_0059A400 *ring)
{
    s32 i = ring->f5C;

    while (i != ring->f58) {
        u32 value = ring->slots[i].value;

        if ((s32)value >= 0) {
            D_1A4B50[value >> 2] |= 1u << (value & 0x1F);
        }

        i = (i + 1 == 10) ? 0 : i + 1;
    }
}
/* localdecomp:end func_L39_0059A400 */
