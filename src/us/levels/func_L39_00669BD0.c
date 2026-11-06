#include "common.h"

/* localdecomp:start func_L39_00669BD0 */
typedef struct {
    u8 reserved0[8];
    s32 current;
} State_L39_00669BD0;

extern State_L39_00669BD0 D_001A5E50;
extern s32 func_L39_0061A800(s32);

s32 func_L39_00669BD0(s32 selection) {
    s32 index;
    State_L39_00669BD0 *state;
    if (func_L39_0061A800(selection) != 0) {
        return 0;
    }
    index = selection + 1;
    state = &D_001A5E50;
    while (index != selection) {
        if (index >= 8) {
            index = 0;
        }
        if (index == state->current) {
            return 1;
        }
        if (func_L39_0061A800(index) != 0) {
            break;
        }
        index++;
    }
    func_L39_0061A800(index);
    return 0;
}
/* localdecomp:end func_L39_00669BD0 */
