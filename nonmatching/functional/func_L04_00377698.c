/* functional: high. Plain C; retail compares same globals (10 diff, instruction order only). */
#include "common.h"
extern s32 D_L04_001E1AA4[];
__asm__(".extern D_L04_001E1AA4, 16");
extern s32 D_L04_001E1B80[];
__asm__(".extern D_L04_001E1B80, 16");
extern s32 D_001E1B50_sda __attribute__((section(".sdata")));
__asm__(".extern D_001E1B50_sda, 4");

s32 func_L04_00377698(s32 a0) {
    if (a0 != D_L04_001E1AA4[0]) {
        return 0;
    }
    if (D_L04_001E1B80[0] != 1) {
        return 0;
    }
    return D_001E1B50_sda >= 7;
}
