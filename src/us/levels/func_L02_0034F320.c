#include "common.h"

/* localdecomp:start func_L02_0034F320 */
s32 func_0037E1D8(s32);
void func_003BE4F0(void *, s32, s32, s32);

void func_L02_0034F320(void *arg0) {
    s32 temp_s0_2;
    s32 temp_s1;
    u8 temp_s0;
    u8 temp_s0_3;

    if ((*(u8 *)((u8 *)arg0 + 0x20)) == 0) {
        temp_s0 = *(u8 *)((u8 *)arg0 + 0x43);
        if (temp_s0 != func_0037E1D8(4)) {
            temp_s1 = func_0037E1D8(4);
            temp_s0_2 = func_0037E1D8(2);
            func_003BE4F0(arg0, temp_s1, temp_s0_2, func_0037E1D8(0xA));
        }
        *(u8 *)((u8 *)arg0 + 0x20) = 1U;
    }
    if ((*(u8 *)((u8 *)arg0 + 0x20)) == 1) {
        if ((*(u8 *)((u8 *)arg0 + 0x60)) & 2) {
            temp_s0_3 = *(u8 *)((u8 *)arg0 + 0x43);
            if (temp_s0_3 != func_0037E1D8(4)) {
                func_003BE4F0(arg0, func_0037E1D8(4), 0, 0x14);
            }
        }
    }
}
/* localdecomp:end func_L02_0034F320 */
