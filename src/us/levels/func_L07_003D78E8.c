#include "common.h"

/* NTSC-U counterpart of func_L07_003D9548 (src/levels/07_annihilation_nation/L07_003D8B18.c) */
typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L07_003D78E8 */
extern u8 *func_L07_003331D8(void *);
extern void func_L07_00333600(void *, void *);
extern void func_L07_00333530(void *, void *);

void func_L07_003D78E8(u8 *obj, u8 *out, s32 a2, u8 idx, f32 f)
{
    u8 *p = *(u8 **)(obj + 0x68);
    u8 *q = func_L07_003331D8(out);

    *(s16 *)(q + 0xE) = 0x4B;
    if (p[0x3C] != 0) {
        *(s16 *)(q + 0xE) = 0xAF;
    }
    q[0x1E] = 0;
    *(u128_t *)(out + 0x10) = *(u128_t *)(obj + 0x10);
    *(f32 *)(out + 0x18) = *(f32 *)(out + 0x18) + 1.5f;
    if (f != 0.0f) {
        *(f32 *)(out + 0x10) = *(f32 *)(out + 0x10) + f * 3.0f;
    }
    func_L07_00333600(*(void **)(q + 4), out);
    *(f32 *)(out + 0xF8) = *(f32 *)(obj + 0xF8);
    func_L07_00333530(*(void **)p, out);
    *(u8 **)(p + (idx << 2) + 0x20) = out;
}
/* localdecomp:end func_L07_003D78E8 */
