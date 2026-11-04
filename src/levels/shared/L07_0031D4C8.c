#include "common.h"

/* localdecomp:start func_L07_0031D4C8 */
typedef struct {
    u8 pad00[0x30];
    f32 f30;
    f32 f34;
    u8 pad38[8];
} Ref_0031D4C8;

typedef struct {
    s32 index;
    f32 f4;
    f32 f8;
} State_0031D4C8;

extern Ref_0031D4C8 *D_L07_001DA9F0;

void func_L07_0031D4C8(char *object) {
    State_0031D4C8 *state = *(State_0031D4C8 **)(object + 0x68);

    switch (*(u8 *)(object + 0x20)) {
    case 0:
        *(u8 *)(object + 0x30) = 0xFF;
        *(u8 *)(object + 0x20) = 1;
        break;
    case 1:
        if (state->f4 != 0.0f) {
            D_L07_001DA9F0[state->index].f30 += state->f4 * 0.020000001f;
            while (D_L07_001DA9F0[state->index].f30 > 1.0f)
                D_L07_001DA9F0[state->index].f30 -= 1.0f;
            while (D_L07_001DA9F0[state->index].f30 < -1.0f)
                D_L07_001DA9F0[state->index].f30 += 1.0f;
        }
        if (state->f8 != 0.0f) {
            D_L07_001DA9F0[state->index].f34 += state->f8 * 0.020000001f;
            while (D_L07_001DA9F0[state->index].f34 > 1.0f)
                D_L07_001DA9F0[state->index].f34 -= 1.0f;
            while (D_L07_001DA9F0[state->index].f34 < 1.0f)
                D_L07_001DA9F0[state->index].f34 += 1.0f;
        }
        break;
    }
}
/* localdecomp:end func_L07_0031D4C8 */
