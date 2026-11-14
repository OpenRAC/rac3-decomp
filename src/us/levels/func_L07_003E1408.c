#include "common.h"

/* localdecomp:start func_L07_003E1408 */
typedef struct {
    u8 reserved0[0xF0];
    f32 speedX;
    f32 speedY;
} State_L07_003E1408;

/* Multiplies the speedX and speedY fields of a state by 0.97 (damping). */
void func_L07_003E1408(State_L07_003E1408 *state) {
    f32 speedX = state->speedX;
    f32 speedY = state->speedY;
    state->speedX = speedX * 0.97f;
    state->speedY = speedY * 0.97f;
}
/* localdecomp:end func_L07_003E1408 */
