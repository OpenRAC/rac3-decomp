#include "common.h"

/* localdecomp:start func_L39_006DA120 */
extern s32 func_0017DF20(void);
extern void func_001962D8(s32);
extern void *D_001E1FD0_sda;

s32 func_L39_006DA120(void) {
    s32 result;
    void *state = D_001E1FD0_sda;
    result = func_0017DF20();
    func_001962D8(result);
    if (result != 0) {
        *(s32 *)((u8 *)state + 0x10) = 0x4D;
        if (*(s32 *)((u8 *)state + 0x14) == 0) {
            *(s32 *)((u8 *)state + 0x14) = 0x4D;
        }
        return 0;
    }
    return 1;
}
/* localdecomp:end func_L39_006DA120 */
