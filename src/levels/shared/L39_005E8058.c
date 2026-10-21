#include "common.h"

/* localdecomp:start func_L39_005E8058 */
extern u8 *func_L39_005E7FF8(u8 *a0, s32 a1, s32 a2);
void func_L39_005E8058(u8 *a0, s32 a1, s32 a2) {
    s32 i;
    for (i = 0; i < *(s32 *)(a0 + 20); i++) {
        *(s32 *)(func_L39_005E7FF8(a0, i, a1) + 32) = a2;
    }
}
/* localdecomp:end func_L39_005E8058 */
