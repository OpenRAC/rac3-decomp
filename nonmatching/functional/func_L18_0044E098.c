/* functional: high. Hand-written VU0 vector-library routine rewritten as plain C: the lqc2 loads are the 4 floats at a and b; the VU0 sqrt/mul sequence is done in float. Not byte-identical (retail uses COP2). */
#include "common.h"
#include "vu0.h"
f32 func_L18_0044E098(f32 *a, f32 *b) {
    f32 dx = a[0] - b[0];
    f32 dy = a[1] - b[1];
    f32 dz = a[2] - b[2];
    f32 scale = 0.0009765625f; /* 0x3A800000 = 2^-10 */
    f32 dist = sqrt_asm(dx * dx + dy * dy + dz * dz);
    return scale * dist - scale * (a[3] + b[3]);
}
