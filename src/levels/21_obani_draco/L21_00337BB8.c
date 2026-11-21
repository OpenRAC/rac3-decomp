#include "common.h"

/* localdecomp:start func_L21_00337BB8 */
void func_L01_004450F0(s32, s32, s32);
s32 func_L21_00337BB8(void *arg0) {
    if ((*(u8 *)((u8 *)arg0 + 0x20)) != 0) {
        return 0;
    }
    *(s8 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x7D) = 0;
    func_L01_004450F0((s32) arg0, 1, -1);
    return 1;
}
/* localdecomp:end func_L21_00337BB8 */
