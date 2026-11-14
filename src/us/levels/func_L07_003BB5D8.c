#include "common.h"

/* NTSC-U counterpart of func_L07_003BCEE8 (src/levels/07_annihilation_nation/L07_003BCDD0.c) */
/* localdecomp:start func_L07_003BB5D8 */
extern f32 func_00388730(void *, void *);

void func_L07_003BB5D8(u8 *obj, void *vec, f32 f)
{
    f32 d;

    f = f * 0.2f * 0.97f;
    *(f32 *)(obj + 0xF0) = *(f32 *)(obj + 0xF0) - f;
    d = (2.0f * func_00388730(vec, obj + 0xD0) < 1.0f ? 2.0f * func_00388730(vec, obj + 0xD0) : 1.0f) * -0.34906584f;
    *(f32 *)(obj + 0xF0) = *(f32 *)(obj + 0xF0) * 0.97f + d * (1.0f - 0.97f);
    d = (2.0f * func_00388730(vec, obj + 0xC0) < 1.0f ? 2.0f * func_00388730(vec, obj + 0xC0) : 1.0f) * 0.34906584f;
    *(f32 *)(obj + 0xF4) = *(f32 *)(obj + 0xF4) * 0.97f + d * (1.0f - 0.97f);
}
/* localdecomp:end func_L07_003BB5D8 */
