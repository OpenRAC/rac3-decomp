#include "common.h"

/* localdecomp:start func_L39_0065F0B0 */
typedef struct {
    u8 reserved0[0x128];
    s32 value128;
} State_L39_0065F0B0;

extern s32 D_001A5A50[];
extern s32 D_001A5AB0[];
extern s32 D_001A5B10[];
extern State_L39_0065F0B0 D_001A5E50;

/* Copies three sets of 3 values for the selected index from the D_001A5A50, 5AB0 and 5B10 tables
 * into the child object at +0x70.., and raises the child's value at +0x4C to the cutoff when it is
 * more than 0x4B0 below it. */
void func_L39_0065F0B0(u8 *object) {
    s32 selection = *(s32 *)(object + 0x2544);
    s32 *first = &D_001A5A50[selection];
    s32 *second = &D_001A5AB0[selection];
    s32 *third = &D_001A5B10[selection];
    u8 *child = *(u8 **)(*(u8 **)(object + 0x2558) + 4);
    u8 *destination = child + 0x70;
    s32 index;
    s32 cutoff;
    for (index = 0; index < 3; index++) {
        *(s32 *)(destination - 0x18) = first[0];
        *(s32 *)(destination - 0xC) = second[0];
        *(s32 *)destination = third[0];
        first += 8;
        second += 8;
        third += 8;
        destination += 4;
    }
    cutoff = D_001A5E50.value128;
    if (*(s32 *)(child + 0x4C) < cutoff - 0x4B0) {
        *(s32 *)(child + 0x4C) = cutoff;
    }
}
/* localdecomp:end func_L39_0065F0B0 */
