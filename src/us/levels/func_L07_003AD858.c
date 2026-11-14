#include "common.h"

/* localdecomp:start func_L07_003AD858 */
extern f32 func_00388730(u8 *, u8 *);

void func_L07_003AD858(u8 *a0, u8 *a1, f32 f12) {
    u8 *e1;
    u8 *e2;
    f32 k;

    e1 = a0 + 0xD0;
    *(f32 *)(a0 + 0xF0) = *(f32 *)(a0 + 0xF0) - f12 * 6.0f * 0.03f;
    k = (2.0f * func_00388730(a1, e1) < 1.0f ? 2.0f * func_00388730(a1, e1) : 1.0f) * -0.34906584f;
    *(f32 *)(a0 + 0xF0) = *(f32 *)(a0 + 0xF0) * 0.97f + k * 0.03f;
    e2 = a0 + 0xC0;
    k = (2.0f * func_00388730(a1, e2) < 1.0f ? 2.0f * func_00388730(a1, e2) : 1.0f) * 0.34906584f;
    *(f32 *)(a0 + 0xF4) = *(f32 *)(a0 + 0xF4) * 0.97f + k * 0.03f;
}
/* localdecomp:end func_L07_003AD858 */
