#include "common.h"

/* localdecomp:start func_L23_003D8628 */
typedef struct {
    u8 pad0[0x128];
    f32 f128;
    f32 f12C;
    s32 w130;
    u8 pad134[0x460 - 0x134];
} E_003D8628;

extern E_003D8628 D_L23_001E1A40[];

void func_L23_003D8628(s32 i, s32 a1, f32 t) {
    E_003D8628 *e = &D_L23_001E1A40[i];

    if (e->f12C == 0.0f) {
        e->w130 = a1;
        e->f12C = 1.0f;
        e->f128 = 1.0f / t;
    }
}
/* localdecomp:end func_L23_003D8628 */
