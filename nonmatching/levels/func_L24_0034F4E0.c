/* func_L24_0034F4E0: 26 differences (level 24, file L24_0034F040.c, -mvu0-use-vf0-vf2 @ps2as). Every instruction is
   there, but the scheduling differs: retail loads obj[0x18] and s[0x154] before the first jal and stores s[0x150]
   in that jal's delay slot, and interleaves the three argument products of the final call with the s[0x134] and
   obj[0x18] updates. Two statement orders tried (store before or after the call); not converged. */
#include "common.h"
#include "vu0.h"
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);
extern void func_L01_0044EBA0(void *, void *, void *, f32, f32, f32);
__asm__(".extern D_L24_001DD474, 4");
__asm__(".extern D_L24_001DD478, 4");
__asm__(".extern D_L24_001DD47C, 4");
__asm__(".extern D_L24_001DD480, 4");
__asm__(".extern D_L24_001DD484, 4");
extern f32 D_L24_001DD474;
extern f32 D_L24_001DD478;
extern f32 D_L24_001DD47C;
extern f32 D_L24_001DD480;
extern f32 D_L24_001DD484;

void func_L24_0034F4E0(u8 *obj) {
    u8 *s = *(u8 **)(obj + 0x68);
    f32 v;

    v = func_0038DAB8(*(f32 *)(s + 0x130), D_L24_001DD478 * 0.017453292f * 0.020000001f * *(f32 *)(s + 0x154));
    *(f32 *)(s + 0x150) = *(f32 *)(obj + 0x18);
    *(f32 *)(s + 0x130) = v;
    v = func_0038D0B0(v);
    *(f32 *)(s + 0x134) = v * D_L24_001DD474 * *(f32 *)(s + 0x154);
    *(f32 *)(obj + 0x18) = *(f32 *)(obj + 0x18) + *(f32 *)(s + 0x134) * *(f32 *)(s + 0x154);
    func_L01_0044EBA0(obj, s + 0x138, s + 0x13C, D_L24_001DD47C * 0.017453292f,
                      D_L24_001DD480 * 0.017453292f * 0.020000001f * *(f32 *)(s + 0x154),
                      D_L24_001DD484 * 0.017453292f * 0.020000001f * *(f32 *)(s + 0x154));
    vec_add_ab(obj + 0xF0, obj + 0xF0, s + 0x120);
}
