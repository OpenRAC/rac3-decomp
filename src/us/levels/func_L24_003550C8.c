#include "common.h"

/* NTSC-U counterpart of func_L24_00356100 (src/levels/24_insomniac_museum/L24_00356100.c): 0.314159 -> 0.261799; 0.349066 -> 0.290888 */
/* localdecomp:start func_L24_003550C8 */
extern void func_L01_00445758(void *, void *, s32, f32, f32, f32, f32);
void func_L24_003550C8(u8 *a0, u8 *a1) {
    if (*(s32 *)(a1 + 0x8E0) > 0) {
        *(f32 *)(a1 + 0x8EC) = 3.1415927f;
    } else {
        *(f32 *)(a1 + 0x8EC) = 0.0f;
    }
    func_L01_00445758(a0 + 0xF8, a1 + 0x8E8, 0, *(f32 *)(a1 + 0x8EC), 0.261799395f, 0.261799395f, 0.29088822f);
}
/* localdecomp:end func_L24_003550C8 */
