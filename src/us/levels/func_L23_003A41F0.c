#include "common.h"

/* NTSC-U counterpart of func_L23_003A59A8 (src/levels/23_holostar_studios_clank/L23_003A59A8.c): 0.02 -> 0.0166667 */
/* localdecomp:start func_L23_003A41F0 */
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DB48(f32);
void func_L23_003A41F0(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    if (a0[0x20] == 0) {
        *(f32 *)s = *(f32 *)s * 0.017453293f * 0.0166666675f;
        *(f32 *)(a0 + 0xF8) = func_0038DB48(*(f32 *)(s + 4) * 0.017453293f);
        a0[0x20] = 1;
    }
    *(f32 *)(a0 + 0xF8) = func_0038DAB8(*(f32 *)(a0 + 0xF8), *(f32 *)s);
}
/* localdecomp:end func_L23_003A41F0 */
