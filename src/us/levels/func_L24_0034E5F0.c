#include "common.h"

/* NTSC-U counterpart of func_L24_0034F4E0 (src/levels/24_insomniac_museum/L24_0034F040.c): 0.02 -> 0.0166667 */
#include "vu0.h"
#include "vu0.h"

/* localdecomp:start func_L24_0034E5F0 */
#include "vu0.h"
extern f32 func_00389380(f32, f32);
extern f32 func_00388978(f32);
extern void func_L01_0044B920(void *, void *, void *, f32, f32, f32);
__asm__(".extern D_L24_001DD4B4, 4");
__asm__(".extern D_L24_001DD4B8, 4");
__asm__(".extern D_L24_001DD4BC, 4");
__asm__(".extern D_L24_001DD4C0, 4");
__asm__(".extern D_L24_001DD4C4, 4");
extern f32 D_L24_001DD4B4;
extern f32 D_L24_001DD4B8;
extern f32 D_L24_001DD4BC;
extern f32 D_L24_001DD4C0;
extern f32 D_L24_001DD4C4;

void func_L24_0034E5F0(u8 *obj) {
    u8 *s = *(u8 **)(obj + 0x68);
    f32 v;
    f32 y;
    f32 w;
    f32 u;
    f32 a;
    f32 b;
    f32 c;

    w = D_L24_001DD4B8 * 0.017453292f * 0.0166666675f;
    y = *(f32 *)(obj + 0x18);
    w = w * *(f32 *)(s + 0x154);
    u = *(f32 *)(s + 0x130);
    *(f32 *)(s + 0x150) = y;
    v = func_00389380(u, w);
    *(f32 *)(s + 0x130) = v;
    v = func_00388978(v);
    b = D_L24_001DD4C0 * 0.017453292f * 0.0166666675f;
    c = D_L24_001DD4C4 * 0.017453292f * 0.0166666675f;
    a = D_L24_001DD4BC * 0.017453292f;
    *(f32 *)(s + 0x134) = v * D_L24_001DD4B4 * *(f32 *)(s + 0x154);
    *(f32 *)(obj + 0x18) = *(f32 *)(obj + 0x18) + *(f32 *)(s + 0x134) * *(f32 *)(s + 0x154);
    func_L01_0044B920(obj, s + 0x138, s + 0x13C, a, b * *(f32 *)(s + 0x154), c * *(f32 *)(s + 0x154));
    vec_add_ab(obj + 0xF0, obj + 0xF0, s + 0x120);
}
/* localdecomp:end func_L24_0034E5F0 */
