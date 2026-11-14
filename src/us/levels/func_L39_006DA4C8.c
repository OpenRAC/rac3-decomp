#include "common.h"

typedef struct {
    u8 pad0[0x1D];
    u8 active;
    u8 pad1[0x50 - 0x1E];
    u8 *object;
} State_L39_006DA4C8;

/* localdecomp:start func_L39_006DA4C8 */
extern u8 D_001A6135[];

/* When the global state at 0x0024D860 is inactive and enabled is nonzero, sets D_001A6135 to 1 and
 * updates two flag bytes on its linked object. */
void func_L39_006DA4C8(s32 enabled) {
    State_L39_006DA4C8 *state = *(State_L39_006DA4C8 **)0x0024D860;
    u8 *object = state->object;
    if (state->active == 0 && enabled != 0) {
        D_001A6135[0] = 1;
        object[0x9D] = 1;
        object[0x9B] = 0;
    }
}
/* localdecomp:end func_L39_006DA4C8 */
