#include "common.h"

/* NTSC-U counterpart of func_L01_0040C7A0 (src/levels/shared/L01_0040C3C0.c): 0.02 -> 0.0166667 */
/* localdecomp:start func_L01_0040A2D0 */
/* m2c3 */
s32 func_L01_00440A88(s32, f32, f32);               /* extern */

void func_L01_0040A2D0(s32 arg0, void *arg1) {
    func_L01_00440A88(arg0 + 0x50, -3.1415927f, 3.1415927f);
    func_L01_00440A88(arg0 + 0x60, -3.1415927f, 3.1415927f);
    func_L01_00440A88(arg0 + 0x70, (*(f32 *)((u8 *)(arg1) + 8)) * 0.017453292f * 0.0166666675f, (*(f32 *)((u8 *)(arg1) + 0xC)) * 0.017453292f * 0.0166666675f);
    func_L01_00440A88(arg0 + 0x80, (*(f32 *)((u8 *)(arg1) + 8)) * 0.017453292f * 0.0166666675f, (*(f32 *)((u8 *)(arg1) + 0xC)) * 0.017453292f * 0.0166666675f);
    func_L01_00440A88(arg0 + 0x90, (*(f32 *)((u8 *)(arg1) + 0x10)), (*(f32 *)((u8 *)(arg1) + 0x14)));
    func_L01_00440A88(arg0 + 0xA0, (*(f32 *)((u8 *)(arg1) + 0x10)), (*(f32 *)((u8 *)(arg1) + 0x14)));
}
/* localdecomp:end func_L01_0040A2D0 */
