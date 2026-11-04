#include "common.h"

/* localdecomp:start func_L36_0031D5F0 */
/* Ps2EeAs only uses $gp for this if it knows the size before the use. */
__asm__(".extern D_001DC7C4, 4");
extern f32 D_001DC7C4;
extern f32 func_0038DAB8(f32, f32);
extern void func_L36_0031D768(u8 *);
extern void func_L01_0031FC60(u8 *);

void func_L36_0031D5F0(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x24);
    *(f32 *)(a0 + 0x2C) = *(f32 *)(p + 0x24) * D_001DC7C4;
    if (*(u8 *)(a0 + 0x20) == 0) {
        func_L36_0031D768(a0);
        *(f32 *)(a0 + 0xF0) = func_0038DAB8(*(f32 *)(a0 + 0xF0), 0.0418879058f);
        *(f32 *)(a0 + 0xF4) = func_0038DAB8(*(f32 *)(a0 + 0xF4), 0.15707963f);
        func_L01_0031FC60(a0);
    }
}
/* localdecomp:end func_L36_0031D5F0 */
