#include "common.h"

/* localdecomp:start func_L39_005B81C0 */
extern u8 *func_L39_0061BF38(s32 a0);
void func_L39_005B81C0(u8 *a0) {
    u8 *p = func_L39_0061BF38(0);
    if (p) {
        u8 *q = *(u8 **)(p + 9508);
        if (q) {
            *(long *)(a0 + 56) = *(long *)(q + 56);
        }
    }
}
/* localdecomp:end func_L39_005B81C0 */
