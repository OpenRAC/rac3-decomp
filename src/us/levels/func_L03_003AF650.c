#include "common.h"

/* NTSC-U counterpart of func_L03_003B1018 (src/levels/shared/L03_003B0F10.c) */
#include "vu0.h"
extern void func_L03_003AF650(u8 *);

/* localdecomp:start func_L03_003AF650 */
extern u8 D_001A4BE0[];
extern f32 func_00388730(void *, void *);
extern f32 func_L03_00432550(f32 *x, f32 *y, f32 a, f32 b, f32 c);
extern void func_00389158(void *, void *, void *, f32);

void func_L03_003AF650(u8 *a0) {
    u8 *m;
    vu0_v4 d;
    vu0_v4 e;
    f32 x;
    u8 *h;

    h = D_001A4BE0;
    m = *(u8 **)(a0 + 0x68);
    if (*(u8 **)(h + 0x35C) == a0 && *(s32 *)(h + 0x360) != 0) {
        vec_sub_ba(&d, h + 0x80, a0 + 0x10);
        x = func_00388730(&d, a0 + 0xC0) * 0.34906584f;
        if (*(s32 *)(m + 8) != 0 && x < 0.08726646f && -0.08726646f < x) {
            *(s32 *)(m + 8) = 0;
            *(f32 *)(m + 4) = (0.0f < x) ? 0.011635529f : -0.011635529f;
        }
        x = func_L03_00432550((f32 *)(a0 + 0xF4), (f32 *)(m + 4), x, 1.0f, 0.96f);
        vec_sub_ba(&e, D_001A4BE0 + 0x80, a0 + 0x10);
        func_00389158(&e, &e, a0 + 0xD0, x);
        vec_add_ba(D_001A4BE0 + 0x80, &e, a0 + 0x10);
    } else {
        func_L03_00432550((f32 *)(a0 + 0xF4), (f32 *)(m + 4), 0.0f, 1.0f, 0.96f);
        *(s32 *)(m + 8) = 1;
    }
}
/* localdecomp:end func_L03_003AF650 */
