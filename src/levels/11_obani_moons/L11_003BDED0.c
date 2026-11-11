#include "common.h"

INCLUDE_ASM("asm/levels", func_L11_003BDED0);

/* localdecomp:start func_L11_003BE100 */
__asm__(".extern D_L11_001DEA50, 16");
__asm__(".extern D_L11_001DE3D0_003BE100, 16");
extern f32 D_L11_001DEA50[] __attribute__((section(".sdata")));
extern f32 D_L11_001DE3D0;
extern f32 D_L11_001DE3D0_003BE100[] __attribute__((section(".sdata")));
extern void func_L11_003BDED0(void *);
extern void func_L01_00404808(void (*)(void *), s32);

void func_L11_003BE100(u8 *a0)
{
    if (a0[0x30] != 0xFF) {
        a0[0x30] = 0xFF;
    }
    if (D_L11_001DEA50[0] == D_L11_001DE3D0 && D_L11_001DEA50[1] == D_L11_001DE3D0_003BE100[1]) {
        func_L01_00404808(func_L11_003BDED0, 0);
    }
}
/* localdecomp:end func_L11_003BE100 */
