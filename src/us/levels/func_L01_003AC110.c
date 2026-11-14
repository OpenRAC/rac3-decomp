#include "common.h"

/* NTSC-U counterpart of func_L01_003AD898 (src/levels/shared/L01_003AC8C0.c): 0.0432 -> 0.03; 0.432 -> 0.3 */
/* localdecomp:start func_L01_003AC110 */
extern f32 func_00388978(f32);
extern void func_003886E8(void *, void *, f32);
extern void func_L01_0044B5C8(void *, void *, s32, f32, f32);

void func_L01_003AC110(void *a0, u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    s32 i;
    s32 j;
    u8 *g;
    u8 *e;
    u8 *o;
    f32 s;
    switch (*(s32 *)(m + 0xC40)) {
    case 0:
        break;
    case 3:
        *(f32 *)(m + 0xCFC) -= *(f32 *)(v + 0x40);
        if (*(f32 *)(m + 0xCFC) <= 0.0f) {
            *(s32 *)(m + 0xC40) = 0;
        }
        if (*(f32 *)(m + 0xCFC) < 0.0f) {
            *(f32 *)(m + 0xCFC) = 0.0f;
        }
        break;
    case 1:
        *(f32 *)(m + 0xCFC) += *(f32 *)(v + 0x3C);
        if (1.0f <= *(f32 *)(m + 0xCFC)) {
            *(s32 *)(m + 0xC40) = 2;
        }
        if (1.0f < *(f32 *)(m + 0xCFC)) {
            *(f32 *)(m + 0xCFC) = 1.0f;
        }
        break;
    case 2:
        break;
    }
    g = *(u8 **)(v + 0x38);
    for (i = 0; i < *(s32 *)(v + 0x34); i++) {
        if (*(s32 *)(g + 0x24) != 0) {
            e = *(u8 **)(g + 0x28);
            for (j = 0; j < *(s32 *)(g + 0x24); j++) {
                o = m + 0xA0 + (*(s32 *)(e + 4) << 7);
                s = func_00388978(*(f32 *)(m + 0xD00) + *(f32 *)(e + 0x20));
                func_003886E8(o + 0x60, e + 0x10, *(f32 *)(m + 0xCFC) * (s * *(f32 *)(e + 0x24) + 1.0f));
                func_L01_0044B5C8(*(void **)(m + 0x64), o, *(s32 *)e, 0.0299999993f, 0.300000012f);
                e += 0x30;
            }
        }
        g += 0x30;
    }
}
/* localdecomp:end func_L01_003AC110 */
