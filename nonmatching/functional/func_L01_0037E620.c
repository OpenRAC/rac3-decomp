/* functional: high. Near-miss: only the lui/swc1 scheduling differs from retail. */
#include "common.h"

extern f32 func_0038DAB8(f32, f32);

/* localdecomp:start func_L01_0037E620 */
extern u8 D_L01_001E1D70[];
extern u8 D_L01_002B3AC0[];
extern void func_L01_0040B858(void *, void *);

void func_L01_0037E620(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    void *b;

    *(f32 *)(s + 0x30) = func_0038DAB8(*(f32 *)(s + 0x30), 0.017453292f);
    b = D_L01_002B3AC0;
    func_L01_0040B858(D_L01_001E1D70, b);
}
/* localdecomp:end func_L01_0037E620 */
