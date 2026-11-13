#include "common.h"

/* localdecomp:start func_L39_0060C330 */
extern s32 func_0038CAD0(void *);
extern s32 func_003BDF60(s16, s32, s32, s32);
extern s32 D_L39_0024CC70;
extern s16 D_001FC362 __attribute__((section(".data")));

s32 func_L39_0060C330(void)
{
    s32 r = func_0038CAD0(&D_L39_0024CC70) != 0;
    func_003BDF60(D_001FC362, 250, 12, 12);
    return r;
}
/* localdecomp:end func_L39_0060C330 */
