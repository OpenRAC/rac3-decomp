#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_005BF798);

/* localdecomp:start func_L39_005BF840 */
extern s32 D_L39_00242910;
__asm__(".extern D_L39_00242910, 16");
extern s32 D_L39_0024C130[8] __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024C130, 32");
extern s32 D_001D7D10_sda;
extern s32 D_001D7D14_sda;
extern s32 D_001D7D18_sda;
extern s32 D_001D7D1C_sda;

s32 func_L39_005BF840(s32 a, s32 b) {
    s32 r;

    if (D_L39_00242910 != -2) {
        r = 1;
    } else {
        r = 0;
    }
    if (D_001D7D18_sda == 0) {
        r = 1;
    }
    if (r == 0) {
        D_001D7D10_sda = a;
        D_001D7D14_sda = b;
        D_L39_00242910 = D_L39_0024C130[--D_001D7D18_sda];
        D_001D7D1C_sda = 0;
    }
    return r;
}
/* localdecomp:end func_L39_005BF840 */
