#include "common.h"

/* localdecomp:start func_L39_00554888 */
extern f32 func_0038DAB8(f32, f32);
extern void func_003D9508(void *, s32, u32, s32, f32, f32, f32);
extern f32 func_L39_005B44C8(void);

void func_L39_00554888(u8 *a0) {
    u8 *state;
    u8 *pos;
    if (a0 != 0 && a0[0x20] != 0xFE && a0[0x20] != 0xFD) {
        state = *(u8 **)(a0 + 0x68);
        if (state != 0) {
            *(f32 *)(state + 0x10) = func_0038DAB8(*(f32 *)(state + 0x10), 0.017453292f);
            pos = a0 + 0x10;
            func_003D9508(pos, 0x39, 0x40505050, 1, 0.5f, 0.08f,
                          func_0038DAB8(*(f32 *)(state + 0x10) * 2.5f, 0.0f));
            func_003D9508(pos, 0x2A, 0x207F2040, 1, 0.5f, 0.08f,
                          func_0038DAB8(-*(f32 *)(state + 0x10) * 1.5f, 0.0f));
            func_003D9508(pos, 0x2C, 0x207F2040, 1, 0.5f, 0.08f,
                          func_0038DAB8(*(f32 *)(state + 0x10), 0.0f));
            func_003D9508(pos, 0x31, 0x20FF7F00, 1, 0.36f, 0.08f, *(f32 *)(state + 0x10) * 0.5f);
            func_003D9508(pos, 0x31, 0x20FF7F, 1, 0.36f, 0.08f, *(f32 *)(state + 0x10) * -0.5f);
            func_003D9508(pos, 0x2F, 0x507F7F7F, 1, 0.11f, 0.08f, func_L39_005B44C8());
        }
    }
}
/* localdecomp:end func_L39_00554888 */

INCLUDE_ASM("asm/levels", func_L39_00554A70);
