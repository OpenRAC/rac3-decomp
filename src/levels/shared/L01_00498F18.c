#include "common.h"

/* localdecomp:start func_L01_00498F18 */
extern s32 func_003B9E50(void *, s32, s32);
extern s32 func_003E7F20(s32, s32);

void func_L01_00498F18(u8 *arg0, s32 arg1, s32 arg2)
{
    s32 i;

    for (i = 0; i < *(s32 *)(arg0 + 16) + 2; i++) {
        func_003E7F20(func_003B9E50(arg0, arg1, i), arg2);
    }
}
/* localdecomp:end func_L01_00498F18 */
