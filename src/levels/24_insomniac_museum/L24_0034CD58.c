#include "common.h"

INCLUDE_ASM("asm/levels", func_L24_0034CD58);

/* localdecomp:start func_L24_0034D110 */
extern f32 func_0038DAB8(f32, f32);
extern void func_003D9508(void *, s32, u32, s32, f32, f32, f32);
extern f32 func_00382538(void);
__asm__(".extern D_L24_001DD3BC, 4");
__asm__(".extern D_L24_001DD3B8, 4");
__asm__(".extern D_L24_001DD3C4, 4");
__asm__(".extern D_L24_001DD3C0, 4");
extern f32 D_L24_001DD3BC;
extern s32 D_L24_001DD3B8;
extern f32 D_L24_001DD3C4;
extern f32 D_L24_001DD3C0;

void func_L24_0034D110(u8 *obj) {
    u8 *p = obj + 0x10;
    u8 *s = *(u8 **)(obj + 0x68);
    f32 r;

    r = func_0038DAB8(*(f32 *)(s + 0x10), D_L24_001DD3BC * 0.017453292f);
    *(f32 *)(s + 0x10) = r;
    func_003D9508(p, D_L24_001DD3B8, 0x457F7F8F, 1, D_L24_001DD3C4, 0.08f, func_0038DAB8(-r * 1.5f, 0.0f));
    func_003D9508(p, D_L24_001DD3B8, 0x450000FF, 1, D_L24_001DD3C4, 0.08f, *(f32 *)(s + 0x10) * 0.5f);
    func_003D9508(p, D_L24_001DD3B8, 0x450000FF, 1, D_L24_001DD3C4, 0.08f, func_0038DAB8(*(f32 *)(s + 0x10) * 2.5f, 0.0f));
    func_003D9508(p, 0x31, 0x20FF2050, 1, 0.36f, 0.08f, *(f32 *)(s + 0x10) * 0.5f);
    func_003D9508(p, 0x31, 0x20FF2050, 1, 0.36f, 0.08f, *(f32 *)(s + 0x10) * -0.5f);
    func_003D9508(p, 0x2F, 0x507F7F7F, 1, D_L24_001DD3C0, 0.08f, func_00382538());
}
/* localdecomp:end func_L24_0034D110 */

INCLUDE_ASM("asm/levels", func_L24_0034D2C8);
