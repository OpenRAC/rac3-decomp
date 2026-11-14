#include "common.h"

/* NTSC-U counterpart of func_L07_003D2B30 (src/levels/07_annihilation_nation/L07_003D2AB8.c): 0.0942478 -> 0.0785398 */
/* localdecomp:start func_L07_003D1040 */
void func_L07_003D10F0(void *arg0);
extern void func_L01_0044EB38(void *, void *, s32, s32, f32);

void func_L07_003D1040(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x68);

    if (*(u8 *)(arg0 + 0x20) == 0) {
        func_L07_003D10F0(arg0);
    }
    func_L01_0044EB38(arg0, p + 8, 0x7FC81414, 0x7FC81460, 0.0785398185f);
}
/* localdecomp:end func_L07_003D1040 */
