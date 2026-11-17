#include "common.h"

/* localdecomp:start func_L39_00533210 */
extern void func_L39_005FE358(f32, u8 *, u8 *, s32, s32);

void func_L39_00533210(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 104);
    if (*(s32 *)(p + 356) != 0) {
        func_L39_005FE358(1.0f, p + 288, p + 304, 0, 1);
    }
}
/* localdecomp:end func_L39_00533210 */
