#include "common.h"

/* localdecomp:start func_L04_003CE660 */
void func_0038CAD0(s32);

void func_L04_003CE660(void *arg0) {
    u16 temp_v1;

    func_0038CAD0((*(s32 *)((u8 *)arg0 + 0x68)) + 0x2F0);
    temp_v1 = *(u16 *)((u8 *)arg0 + 0x96);
    if (temp_v1 <= 0xFFFEU) {
        *(u16 *)((u8 *)arg0 + 0x96) = (u16) (temp_v1 + 1);
    }
}
/* localdecomp:end func_L04_003CE660 */
