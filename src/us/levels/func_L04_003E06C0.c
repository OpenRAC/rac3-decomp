#include "common.h"

/* localdecomp:start func_L04_003E06C0 */
extern f32 D_L04_001DF08C;
extern f32 D_L04_001DF090;
extern f32 D_L04_001DF094;
extern f32 D_L04_001DF098;
__asm__(".extern D_L04_001DF08C, 4");
__asm__(".extern D_L04_001DF090, 4");
__asm__(".extern D_L04_001DF094, 4");
__asm__(".extern D_L04_001DF098, 4");

extern f32 func_003893C8(f32, f32);
extern void func_L01_0044B5C8(void *, void *, s32, f32, f32);

void func_L04_003E06C0(u8 *o, u8 *p) {
    f32 r;
    f32 r2;
    f32 r3;
    f32 x;
    f32 y;
    f32 x2;
    f32 y2;

    r = func_003893C8(*(f32 *)(p + 0x64), *(f32 *)(o + 0xF8));
    x = D_L04_001DF08C;
    y = D_L04_001DF090;
    *(f32 *)(p + 0xD8) = r;
    func_L01_0044B5C8(o, p + 0x70, 0, x, y);
    r2 = *(f32 *)(p + 0x68);
    x = D_L04_001DF094;
    y = D_L04_001DF098;
    *(f32 *)(p + 0x150) = r2;
    func_L01_0044B5C8(o, p + 0xF0, 2, x, y);
    r3 = *(f32 *)(p + 0x68) * 0.35f;
    x2 = D_L04_001DF094;
    y2 = D_L04_001DF098;
    *(f32 *)(p + 0x1D0) = r3;
    func_L01_0044B5C8(o, p + 0x170, 3, x2, y2);
}
/* localdecomp:end func_L04_003E06C0 */
