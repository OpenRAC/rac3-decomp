#include "common.h"

/* localdecomp:start func_L39_00634F38 */
extern u8 func_L39_00635270[];
extern void func_L01_00404A10(void *a0, s32 a1);
void func_L39_00634F38(u8 *a0) {
    if (a0[6676] && *(s16 *)(a0 + 6626) == 0) {
        *(s16 *)(a0 + 6626) = 1;
        func_L01_00404A10(func_L39_00635270, *(s32 *)(a0 + 9508));
    }
}
/* localdecomp:end func_L39_00634F38 */
