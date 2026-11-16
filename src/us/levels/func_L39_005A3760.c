#include "common.h"

/* localdecomp:start func_L39_005A3760 */
typedef struct {
    u8 reserved0[0x10];
    s32 field10;
    u8 reserved14[0x150];
    s32 field164;
    s32 field168;
} State_L39_005A3760;

extern State_L39_005A3760 D_001A4560;
extern s32 D_001D4CE8_sda;

/* Clears a field of the global state block at D_001A4560, sets two other fields (0 and 3) when the
 * selection field is negative, and sets a menu value D_001D4CE8_sda to 10. */
void func_L39_005A3760(void) {
    State_L39_005A3760 *state = &D_001A4560;
    state->field10 = 0;
    if (state->field164 < 0) {
        state->field168 = 0;
        state->field164 = 3;
    }
    D_001D4CE8_sda = 10;
}
/* localdecomp:end func_L39_005A3760 */
