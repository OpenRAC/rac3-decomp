#include "common.h"

/* localdecomp:start func_L39_0060F298 */
extern s32 func_003E7118();
extern s32 func_003E5BD0();
extern s32 func_003E6518(s32);
extern s32 func_003E6EA0();
s32 func_L39_0060F298(s32 *p, u32 idx) {
    s32 *q;
    s32 i;
    if (idx < 0x23) {
        q = (s32 *)((u8 *)(idx * 4) + *p);
        q += 0x14;
        if (*q) func_003E7118(*q);
        *q = 0;
        for (i = 15; i >= 0; i--) {
            func_003E6EA0(func_003E6518(func_003E5BD0(p)));
        }
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L39_0060F298 */
