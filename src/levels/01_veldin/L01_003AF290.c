#include "common.h"

INCLUDE_ASM("asm/levels", func_L01_003AF290);

INCLUDE_ASM("asm/levels", func_L01_003B0498);

INCLUDE_ASM("asm/levels", func_L01_003B08A0);

/* localdecomp:start func_L01_003B0BD8 */
extern void func_L01_00452310(void *m, s32 a, void *b, s32 c, s32 d, f32 x0, f32 x1, f32 x2,
                              f32 x3, f32 x4, u8 e, f32 x5, f32 x6, s32 f, s32 g);
extern void func_L01_004443E8(void *, s32, s32);
extern u8 D_L01_001D66B0[8];

void func_L01_003B0BD8(void *o) {
    func_L01_00452310(o, 0x1FFF, D_L01_001D66B0, 1, 25, 0.8f, 3.0f, 6.0f, 3.0f, 6.0f, 255, -1.0f, -1.0f, 180, 0);
    func_L01_004443E8(o, 0, 3);
}
/* localdecomp:end func_L01_003B0BD8 */

/* localdecomp:start func_L01_003B0C60 */
typedef struct { u8 p0[0x31]; u8 b31; u8 p32[0x36]; u8 *f68; u8 p6C[0x29]; u8 b95; u16 h96; } S_0C60_O;
extern f32 D_L01_001DE53C, D_L01_001DE540, D_L01_001DE544;
__asm__(".extern D_L01_001DE53C, 4");
__asm__(".extern D_L01_001DE540, 4");
__asm__(".extern D_L01_001DE544, 4");
extern s32 D_L01_001D6694_0C60;
__asm__(".extern D_L01_001D6694_0C60, 16");
extern void func_L01_0044E850(void *, void *, s32, f32, f32);
extern void func_L01_0044EBA0(void *, void *, void *, f32, f32, f32);
extern void func_L01_00404808(void *, void *);
extern void func_L01_003B0F18(void *);
void func_L01_003B0C60(S_0C60_O *a0) {
    u8 *d = a0->f68;
    func_L01_0044E850(a0, d + 0x240, 0, 0.0432f, 0.43200004f);
    if (a0->h96 <= 0xFFFE) a0->h96 = a0->h96 + 1;
    func_L01_0044EBA0(a0, d + 0x2D8, d + 0x2DC, D_L01_001DE544 * 0.017453292f, D_L01_001DE53C * 0.017453292f * 0.020000001f, D_L01_001DE540 * 0.017453292f * 0.020000001f);
    if (D_L01_001D6694_0C60 == 0) {
        if (a0->b31 != 0) {
            if (a0->b95 != 0) func_L01_00404808(func_L01_003B0F18, a0);
        }
    }
}
/* localdecomp:end func_L01_003B0C60 */

INCLUDE_ASM("asm/levels", func_L01_003B0D48);

INCLUDE_ASM("asm/levels", func_L01_003B0E00);
