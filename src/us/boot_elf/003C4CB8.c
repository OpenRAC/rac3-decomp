#include "common.h"

/* Based on the NTSC decomp's func_003BF4F8; native boot_elf helper interface checked against retail. */
/* localdecomp:start func_U_003C4CB8 */
typedef struct {
    s16 current;
    s16 pending;
    u8 red, green, blue;
    u8 padding[5];
    u16 target;
    s16 divisor;
} State_003C4CB8;

extern void func_U_003C7220(void *, s32 *, s32 *, s32 *);

void func_U_003C4CB8(void *object, State_003C4CB8 *state) {
    s32 red, green, blue;
    s32 previous = state->current;
    if (previous != 0 && state->pending == 0) return;
    state->pending = 0;
    state->current = state->target;
    if (previous != 0) {
        state->current = (f32)(s16)state->target * ((f32)previous / (f32)state->divisor);
        if (state->current <= 0) state->current = 1;
    } else {
        func_U_003C7220(object, &red, &green, &blue);
        state->red = red;
        state->green = green;
        state->blue = blue;
    }
}
/* localdecomp:end func_U_003C4CB8 */
