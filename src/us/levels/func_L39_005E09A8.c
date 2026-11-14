#include "common.h"

/* localdecomp:start func_L39_005E09A8 */
typedef struct {
    u8 reserved0[0x164];
    s32 field164;
    s32 field168;
} State_L39_005E09A8;

extern State_L39_005E09A8 D_001A4560;

void func_L39_005E09A8(void) {
    State_L39_005E09A8 *state = &D_001A4560;
    if (state->field164 < 0) {
        state->field168 = 0;
        state->field164 = 32;
    }
}
/* localdecomp:end func_L39_005E09A8 */
