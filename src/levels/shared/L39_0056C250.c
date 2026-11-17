#include "common.h"

/* localdecomp:start func_L39_0056C250 */
#include "vu0.h"

extern u8 D_L39_0024DFD0[];
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);

s32 func_L39_0056C250(u8 *a0, void *a1, s32 a2, s32 a3) {
    u8 *p = *(u8 **)(a0 + 0x70);
    u8 *e = D_L39_0024DFD0 + *(s32 *)(a0 + 0x94) * 0x460;
    u8 *v = p + 0x180;
    u8 *w = p + 0x210;
    u8 *x = p + 0x60;
    f32 len;
    f32 d;

    len = func_0038CEA8(v);
    vec_sub_ab(p + 0x180, a1, p + 0xB0);
    if (*(s16 *)(w + 0x38) != 0) {
        func_0038CF68(v, v, *(f32 *)(v + 0x2C) - *(f32 *)(w + 0x30));
        return a3;
    }
    d = func_0038CEA8(v);
    if (__builtin_fabsf(*(f32 *)(*(u8 **)(e + 0x134) + 0x100)) > 0.05f && a3 != 0) {
        *(s16 *)(w + 0x34) = 0x719;
        d -= 0.09f;
    }
    if (a2 == 0 && *(s32 *)(e + 0x104) != 2 && len < d) {
        func_0038CE20(v, v, len / d);
        *(f32 *)(w + 0x30) = *(f32 *)(v + 0x2C) - len;
        return a3;
    }
    if (d < 0.2f) {
        if (d <= 0.0001f) {
            func_0038CF68(v, *(u8 **)(x + 0xE0) + 0xC0, -0.2f);
        } else {
            func_0038CE20(v, v, 0.2f / d);
        }
        d = 0.2f;
    }
    *(f32 *)(w + 0x30) = *(f32 *)(v + 0x2C) - d;
    return 1;
}
/* localdecomp:end func_L39_0056C250 */
