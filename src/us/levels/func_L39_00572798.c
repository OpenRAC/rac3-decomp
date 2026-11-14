#include "common.h"

/* localdecomp:start func_L39_00572798 */
typedef struct { u8 pad[0x1C]; u8 *state; } Entry_572798;
extern Entry_572798 *D_L39_0024B950;
extern s32 D_L39_00242A94;
extern f32 D_L39_0024BAD0;
extern s32 D_L39_002412A8;

s32 func_L39_00572798(u8 *self) {
    u8 *p;
    f32 f;
    if (*(s32 *)(self + 0x94) > 0) return -1;
    p = D_L39_0024B950[*(s16 *)(self + 0x84)].state;
    if (!D_L39_00242A94 && (*(s16 *)(p + 0x44)) > 0) {
            f = (*(s16 *)(p + 0x44)) / 30.0f;
            if (f > 1.0f) f = 1.0f;
            if (f < 0.0f) f = 0.0f;
            D_L39_0024BAD0 = f;
            (*(s16 *)(p + 0x44))--;
    }
    return D_L39_002412A8 ? 1 : -1;
}
/* localdecomp:end func_L39_00572798 */
