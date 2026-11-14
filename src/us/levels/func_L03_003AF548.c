#include "common.h"

/* NTSC-U counterpart of func_L03_003B0F10 (src/levels/shared/L03_003B0F10.c): 0.00251327 -> 0.00174533; 0.146608 -> 0.122173; 0.00125664 -> 0.000872665 */
#include "vu0.h"

/* localdecomp:start func_L03_003AF548 */
extern void func_00388BD0(void *, void *);
extern void func_L03_003AF7E0(u8 *a0);
extern void func_L01_00441FB8(void *, s32, s32);
extern f32 func_00388A28(f32, f32);
extern f32 func_L01_00445758(void *, f32, void *, f32, f32, f32, s32);
extern void func_L03_003AF650(u8 *);

void func_L03_003AF548(u8 *a0) {
    u8 *m;
    vu0_v4 d;
    f32 a;

    m = *(u8 **)(a0 + 0x68);
    switch (a0[0x20]) {
    case 0:
        func_00388BD0(a0 + 0xC0, a0 + 0xF0);
        *(vu0_q *)(m + 0x20) = *(vu0_q *)(a0 + 0xC0);
        func_L03_003AF7E0(a0);
        if (*(s16 *)(a0 + 0xAA) == 0x1DD1) {
            *(f32 *)(a0 + 0x2C) = *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24) * 1.25f;
        }
        func_L01_00441FB8(a0, 1, -1);
        break;
    case 1:
        vec_sub_ba(&d, m + 0x10, a0 + 0x10);
        a = func_00388A28(d.x, d.y);
        func_L01_00445758(a0 + 0xF8, a, m, 0.000872664677f, 0.00174532935f, 0.122173056f, 0);
        func_00388BD0(a0 + 0xC0, a0 + 0xF0);
        func_L03_003AF650(a0);
        break;
    }
}
/* localdecomp:end func_L03_003AF548 */
