#include "common.h"

typedef struct Obj_003A2C98 {
    u8 pad00[0x10];
    s32 f10;
    s32 f14;
    u8 pad18[0xC];
    f32 f24;
    f32 f28;
    f32 f2C;
    f32 f30;
    u8 pad34[0x20];
    f32 f54;
    f32 f58;
    u8 pad5C[4];
    f32 f60[1];
} Obj_003A2C98;

/* localdecomp:start func_L02_003A3878 */
s32 func_L02_003A3878(u8 *a0) {
    s32 r = 0;
    if (a0[3] & 0x80) {
        r = *(s32 *)(a0 + 92) == 0;
    }
    return r;
}
/* localdecomp:end func_L02_003A3878 */
