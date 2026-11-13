#include "common.h"

/* localdecomp:start func_L03_003AEC58 */
extern s32 func_L03_0043F5D0(s32, s32, f32);
extern void func_0038AE20(s32, s32, s32, s32);
extern void func_003A9440(s32, unsigned long);
__asm__(".extern D_L03_001DE7E8, 4");
extern s32 D_L03_001DE7E8;
extern s32 D_L03_001DE7EC;

void func_L03_003AEC58(u8 *a0) {
    s32 c = func_L03_0043F5D0(D_L03_001DE7E8, D_L03_001DE7EC, *(f32 *)(*(u8 **)(a0 + 0x68) + 0x10));
    s32 b = (c >> 16) & 0xFF;
    s32 g = (c >> 8) & 0xFF;
    func_0038AE20(c & 0xFF, g, b, (u32)c >> 24);
    func_003A9440(0x47, 0x5360B);
}
/* localdecomp:end func_L03_003AEC58 */

INCLUDE_ASM("asm/levels", func_L03_003AECB0);

/* localdecomp:start func_L03_003AF098 */
extern s32 func_L01_005169C8(s32, f32);
extern s32 func_L01_00516AA0(s32, s32, s32);

void func_L03_003AF098(s32 n) {
    s32 t = n - 1;
    s32 i;
    f32 f;
    if (t > 7) {
        t = 7;
    } else if (t < 0) {
        t = 0;
    }
    f = (f32)t / 7.0f * 0.61f;
    func_L01_005169C8(0x150002, f);
    func_L01_005169C8(0x150004, f);
    for (i = 0; i < 8; i++) {
        func_L01_00516AA0(0x150008 + i, 1, i < n);
    }
}
/* localdecomp:end func_L03_003AF098 */
