#include "common.h"

/* localdecomp:start func_L39_006D5508 */
extern s32 D_L39_0022F400[];
extern void func_0011D534(s32 *, s32, s32);
extern void func_001975C8(s32);
extern void func_L39_006D5DE0(void *);
extern void func_L39_00619718(void *);

void func_L39_006D5508(void *object, s32 flags) {
    func_0011D534(D_L39_0022F400, 0, 0x148);
    func_001975C8(0);
    func_L39_006D5DE0(object);
    if (flags & 1) {
        func_L39_00619718(object);
    }
}
/* localdecomp:end func_L39_006D5508 */
