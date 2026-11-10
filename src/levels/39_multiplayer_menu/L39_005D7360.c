#include "common.h"

/* localdecomp:start func_L39_005D7360 */
extern u8 D_001D7EE8_sda[] __attribute__((section(".sdata")));
__asm__(".extern D_001D7EE8_sda, 8");
extern void func_003E82F8(s32);
extern void func_L01_00516AA0(s32, s32, s32);
extern s32 func_L01_00479578(s32);
extern void func_L01_00516010(s32);

s32 func_L39_005D7360(s32 arg0) {
    if (D_001D7EE8_sda[arg0] != 0) {
        func_003E82F8(arg0);
        func_L01_00516AA0(0x90000, 1, 0);
        func_L01_00516010(func_L01_00479578(arg0));
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L39_005D7360 */
