#include "common.h"

/* localdecomp:start func_L39_00630918 */
typedef struct {
    u8 reserved0[0xFB0];
    f32 elapsed;
    u8 reservedFB4[0x2468 - 0xFB4];
    f32 speed;
} State_L39_00630918;

extern void func_L39_00630530(State_L39_00630918 *, s32, f32);

/* Calls func_L39_00630530 with 1.0, then if the state's elapsed time is above 0 resets it from a
 * global tick value times 1/60 times the state's speed. */
void func_L39_00630918(State_L39_00630918 *state) {
    func_L39_00630530(state, 0, 1.0f);
    if (0.0f < state->elapsed) {
        state->elapsed = *(f32 *)0x00246190 * 0.016666667535f * state->speed;
    }
}
/* localdecomp:end func_L39_00630918 */
