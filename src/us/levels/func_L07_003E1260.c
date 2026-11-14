#include "common.h"

/* localdecomp:start func_L07_003E1260 */
extern f32 func_00388730(void *, void *);

void func_L07_003E1260(u8 *p, u8 *q, f32 t) {
    f32 g;
    f32 h;
    u8 *st;

    t = t * 6.0f * 0.029999971f;
    st = *(u8 **)(p + 0x68);
    *(f32 *)(p + 0xF0) = *(f32 *)(p + 0xF0) - t;
    if (func_00388730(q, p + 0xD0) / 0.16666667f < 1.0f) {
        g = (func_00388730(q, p + 0xD0) / 0.16666667f) * -0.34906584f;
    } else {
        g = -0.34906584f;
    }
    *(f32 *)(p + 0xF0) = *(f32 *)(p + 0xF0) * 0.97f + g * 0.029999971f;
    if (func_00388730(q, p + 0xC0) / 0.16666667f < 1.0f) {
        h = (func_00388730(q, p + 0xC0) / 0.16666667f) * 0.34906584f;
    } else {
        h = 0.34906584f;
    }
    *(f32 *)(p + 0xF4) = *(f32 *)(p + 0xF4) * 0.97f + h * 0.029999971f;
    *(f32 *)(st + 0x204) = h * 1.5f;
}
/* localdecomp:end func_L07_003E1260 */
