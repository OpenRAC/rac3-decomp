#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L07_003AD7B8 */
extern f32 func_00389380(f32, f32);
extern f32 func_00388978(f32);
extern void func_L07_003AD858(void *, void *, f32);

/* Moves the moby's y-style field at +0x18 by a bobbing offset: removes the old offset, calls the
 * given callback with a copy of the vector, advances a phase by 0.105 rad, sets a new offset 0.2 *
 * sin(phase), and calls func_L07_003AD858. */
void func_L07_003AD7B8(u8 *a0, vu0_v4 *a1, void (*a2)(u8 *, void *)) {
    u8 *s = *(u8 **)(a0 + 0x68);
    vu0_v4 buf;
    f32 t;
    f32 v;

    *(f32 *)(a0 + 0x18) -= *(f32 *)(s + 0x27C);
    buf = *a1;
    a2(a0, &buf);
    t = func_00389380(*(f32 *)(s + 0x278), 0.104719765f);
    *(f32 *)(s + 0x278) = t;
    v = func_00388978(t) * 0.2f;
    *(f32 *)(s + 0x27C) = v;
    *(f32 *)(a0 + 0x18) += v;
    func_L07_003AD858(a0, s + 0xD0, *(f32 *)(s + 0xE4));
}
/* localdecomp:end func_L07_003AD7B8 */
