#include "common.h"

/* localdecomp:start func_L22_0041FCC8 */
typedef struct {
    u8 pad0[0x40];
    s32 x40;
    s32 x44;
} D_002E79B0_t;
extern D_002E79B0_t D_L22_002E79F0;

void func_L22_0041FCC8(s32 a, s32 b) {
    D_L22_002E79F0.x44 = b + 1;
    D_L22_002E79F0.x40 = a;
}
/* localdecomp:end func_L22_0041FCC8 */
