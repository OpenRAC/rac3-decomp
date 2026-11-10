#include "common.h"

typedef struct { u8 before[0xB8]; s32 count; u8 *table; } CallbackGlobals;
typedef struct { u8 active; u8 pad[0x5F]; } Slot;

/* localdecomp:start func_L39_005F3828 */
extern u8 D_001FE020[];
extern Slot D_L39_002B8DA0[12];
extern void func_L39_005F3B18(Slot *p);

void func_L39_005F3828(void) {
    s32 i;
    for (i = 0; i < ((CallbackGlobals *)D_001FE020)->count; i++) {
        u8 *entry = (u8 *)(i * 0x90 + (s32)((CallbackGlobals *)D_001FE020)->table);
        void (*callback)(u8 *) = *(void (**)(u8 *))(entry + 4);
        if (callback) callback(entry);
    }
    for (i = 0; i < 12; i++) {
        if (D_L39_002B8DA0[i].active) func_L39_005F3B18(&D_L39_002B8DA0[i]);
    }
}
/* localdecomp:end func_L39_005F3828 */

/* localdecomp:start func_L39_005F38D0 */
typedef struct {
    unsigned char prefix_00[0x40];
    unsigned char selector_40;
    unsigned char axis_41;
    unsigned char mode_42;
    unsigned char dirty_43;
    unsigned char pad_44[0xB0 - 0x44];
    unsigned int value_B0;
    int value_B4;
} S_5F38D0;

/* from rac2-decomp's func_L00_0035F8D0 */
void func_L39_005F38D0(int value60, int selector68, int value64, int axis69, int mode6A)
{
    S_5F38D0 *state = (S_5F38D0 *)D_001FE020;
    state->value_B0 = value60;
    if (state->selector_40 != selector68) {
        state->selector_40 = selector68;
        state->dirty_43 |= 1;
    }
    if (state->value_B4 != value64) {
        state->value_B4 = value64;
        state->dirty_43 |= 4;
    }
    if (state->axis_41 != axis69 || state->mode_42 != mode6A) {
        state->mode_42 = mode6A;
        state->axis_41 = axis69;
        state->dirty_43 |= 2;
    }
}
/* localdecomp:end func_L39_005F38D0 */

INCLUDE_ASM("asm/levels", func_L39_005F3948);
