#include "common.h"

/* NTSC-U counterpart of func_L01_003B0C60 (src/levels/01_veldin/L01_003AF290.c): 0.0432 -> 0.03; 0.432 -> 0.3; 0.02 -> 0.0166667 */
/* localdecomp:start func_L01_003AF490 */
typedef struct { u8 p0[0x31]; u8 b31; u8 p32[0x36]; u8 *f68; u8 p6C[0x29]; u8 b95; u16 h96; } S_0C60_O;
extern f32 D_L01_001DE57C, D_L01_001DE580, D_L01_001DE584;
__asm__(".extern D_L01_001DE57C, 4");
__asm__(".extern D_L01_001DE580, 4");
__asm__(".extern D_L01_001DE584, 4");
extern s32 D_L01_001D6694_003AF490;
__asm__(".extern D_L01_001D6694_003AF490, 16");
extern void func_L01_0044B5C8(void *, void *, s32, f32, f32);
extern void func_L01_0044B920(void *, void *, void *, f32, f32, f32);
extern void func_L01_00402498(void *, void *);
extern void func_L01_003AF748(void *);
void func_L01_003AF490(S_0C60_O *a0) {
    u8 *d = a0->f68;
    func_L01_0044B5C8(a0, d + 0x240, 0, 0.0299999993f, 0.300000012f);
    if (a0->h96 <= 0xFFFE) a0->h96 = a0->h96 + 1;
    func_L01_0044B920(a0, d + 0x2D8, d + 0x2DC, D_L01_001DE584 * 0.017453292f, D_L01_001DE57C * 0.017453292f * 0.0166666675f, D_L01_001DE580 * 0.017453292f * 0.0166666675f);
    if (D_L01_001D6694_003AF490 == 0) {
        if (a0->b31 != 0) {
            if (a0->b95 != 0) func_L01_00402498(func_L01_003AF748, a0);
        }
    }
}
/* localdecomp:end func_L01_003AF490 */
