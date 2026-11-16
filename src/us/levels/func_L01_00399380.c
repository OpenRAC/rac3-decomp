#include "common.h"

/* NTSC-U counterpart of func_L01_0039A860 (src/levels/shared/L01_00396B78.c) */
#include "vu0.h"

/* localdecomp:start func_L01_00399380 */
extern u8 D_L01_002A1C70[];
void func_L01_00399380(u8 *obj) {
    extern void func_L01_003999D8(u8 *, s32, s32, f32, f32, f32, s32, u32, u32);
    u8 *state = *(u8 **)(obj + 0x68);
    if (*(s32 *)(state + 0x1C)) {
        if (*(s32 *)(state + 0x10) < 5) {
            func_L01_003999D8(D_L01_002A1C70, *(s32 *)(state + 0x10) * 7, *(s32 *)(state + 0x10) * 7, 0.06f, 0.11f, 0.2f, 10, 0x7F7F7F, 0xFF8040);
            func_L01_003999D8(D_L01_002A1C70 + 0xA0, *(s32 *)(state + 0x10) * 3, *(s32 *)(state + 0x10) * 3, 0.05f, 0.095f, 0.2f, 10, 0x7F7F7F, 0xFF1010);
            func_L01_003999D8(D_L01_002A1C70 + 0x140, *(s32 *)(state + 0x10) * 3, *(s32 *)(state + 0x10) * 3, 0.05f, 0.095f, 0.2f, 10, 0x7F7F7F, 0xFF1010);
        } else {
            func_L01_003999D8(D_L01_002A1C70, 70, 70, 0.06f, 0.11f, 0.15f, 10, 0x7F7F7F, 0xFF8040);
            func_L01_003999D8(D_L01_002A1C70 + 0xA0, 32, 32, 0.05f, 0.095f, 0.2f, 10, 0x7F7F7F, 0xFF1010);
            func_L01_003999D8(D_L01_002A1C70 + 0x140, 32, 32, 0.05f, 0.095f, 0.2f, 10, 0x7F7F7F, 0xFF1010);
        }
    } else {
        func_L01_003999D8(D_L01_002A1C70, 50, 50, 0.07f, 0.15f, 0.2f, 10, 0x7F7F7F, 0xFF8040);
        func_L01_003999D8(D_L01_002A1C70 + 0xA0, 15, 15, 0.03f, 0.09f, 0.2f, 10, 0x7F7F7F, 0xFF1010);
        func_L01_003999D8(D_L01_002A1C70 + 0x140, 15, 15, 0.03f, 0.09f, 0.2f, 10, 0x7F7F7F, 0xFF1010);
        func_L01_003999D8(D_L01_002A1C70 + 0x1E0, 15, 15, 0.03f, 0.09f, 0.2f, 10, 0x7F7F7F, 0xFF1010);
    }
}
/* localdecomp:end func_L01_00399380 */
