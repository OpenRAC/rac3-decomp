#include "common.h"

/* localdecomp:start func_L39_006DA7E0 */
extern s32 func_0017E140(void);
extern s32 func_001962E8(void);
extern void func_001962D8(s32);
extern void *D_001E1FD0_sda;
extern u8 D_001A6135[];

s32 func_L39_006DA7E0(void *object) {
    void *state = D_001E1FD0_sda;
    s32 result = func_0017E140();
    func_001962D8(result);
    result = func_001962E8();
    if (result != -0x10 && result != 0) {
        *(s32 *)((u8 *)state + 0x10) = 0x50;
        if (*(s32 *)((u8 *)state + 0x14) == 0) {
            *(s32 *)((u8 *)state + 0x14) = 0x50;
        }
        return 0;
    }
    D_001A6135[0] = 0;
    *(u8 *)((u8 *)object + 0x9D) = 0;
    return 1;
}
/* localdecomp:end func_L39_006DA7E0 */
