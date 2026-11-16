#include "common.h"

/* localdecomp:start func_L39_00599130 */
typedef struct {
    s32 value;
    s32 extra;
} Slot_L39_00599130;

typedef struct {
    s32 field0;
    s32 field4;
    Slot_L39_00599130 slots[10];
    s32 read_index;
    s32 write_index;
} Ring_L39_00599130;

extern u32 D_001A4CD0[];

/* Walks a ring buffer of ten slots from the write index to the read index and sets the bit in a
 * global bit array for each non-negative slot value. */
void func_L39_00599130(Ring_L39_00599130 *ring) {
    s32 index = ring->write_index;
    while (index != ring->read_index) {
        u32 value = ring->slots[index].value;
        if ((s32)value >= 0) {
            D_001A4CD0[value >> 2] |= 1u << (value & 0x1F);
        }
        index = (index + 1 == 10) ? 0 : index + 1;
    }
}
/* localdecomp:end func_L39_00599130 */
