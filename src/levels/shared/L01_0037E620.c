#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_0037E620 */
extern f32 func_0038DAB8(f32, f32);
extern u8 D_L01_001E1D70[8];
extern u8 D_L01_002B3AC0[];
extern void func_L01_0040B858(void *beam, void *numbers);

void func_L01_0037E620(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);

    *(f32 *)(s + 0x30) = func_0038DAB8(*(f32 *)(s + 0x30), 0.017453292f);
    func_L01_0040B858(D_L01_001E1D70, D_L01_002B3AC0);
}
/* localdecomp:end func_L01_0037E620 */

INCLUDE_ASM("asm/levels", func_L01_0037E670);
