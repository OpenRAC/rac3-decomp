#include "common.h"

/* NTSC-U counterpart of func_L01_003BDF98 (src/levels/01_veldin/L01_003BDF10.c): 0.02 -> 0.0166667 */
/* localdecomp:start func_L01_003BC750 */
typedef struct { u8 p0[0x31]; u8 b31; u8 p32[0x36]; u8 *f68; u8 p6C[0x29]; u8 b95; u16 h96; } S_DF98_O;
extern f32 D_L01_001DEA8C, D_L01_001DEA90, D_L01_001DEA94, D_L01_001DEA98, D_L01_001DEA9C;
__asm__(".extern D_L01_001DEA8C, 4");
__asm__(".extern D_L01_001DEA90, 4");
__asm__(".extern D_L01_001DEA94, 4");
__asm__(".extern D_L01_001DEA98, 4");
__asm__(".extern D_L01_001DEA9C, 4");
extern void func_L01_0044B5C8(void *, void *, s32, f32, f32);
extern void func_L01_0044B860(void *, void *, void *, f32, f32, f32);
extern void func_L01_0044B920(void *, void *, void *, f32, f32, f32);
extern void func_L01_00402498(void *, void *);
extern void func_L01_003BCB58(void *);
void func_L01_003BC750(S_DF98_O *a0) {
    u8 *d = a0->f68;
    func_L01_0044B5C8(a0, d + 0x270, 0, 1.0f, 0.0f);
    if (a0->h96 <= 0xFFFE) a0->h96 = a0->h96 + 1;
    func_L01_0044B860(a0, d + 0x300, d + 0x304, D_L01_001DEA8C, D_L01_001DEA90 * 0.017453292f * 0.0166666675f, -1.0f);
    func_L01_0044B920(a0, d + 0x308, d + 0x30C, D_L01_001DEA9C * 0.017453292f, D_L01_001DEA94 * 0.017453292f * 0.0166666675f, D_L01_001DEA98 * 0.017453292f * 0.0166666675f);
    if (a0->b31 != 0) {
        if (a0->b95 != 0) func_L01_00402498(func_L01_003BCB58, a0);
    }
}
/* localdecomp:end func_L01_003BC750 */
