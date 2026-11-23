/* func_L01_00497580 (level 01, 256 bytes): near miss, 1 word differs.
 * Everything matches except one extra `nop` after `lui $at,0x3b00; mtc1 $at,$f21` before the
 * second div.s (the default assembler inserts it; retail has none). @ps2as is worse (69 diff).
 * Globals D_L01_001D9210..921C are s32 read as lwc1+cvt.s.w; 91B0/91B4 are f32 as in the neighbours.
 * The file's declaration `func_L01_00497580(void)` (line 39, in func_L01_004974F0's block) must become (s32, f32 *).
 */
#include "common.h"
extern s32 D_L01_001D9210, D_L01_001D9214, D_L01_001D9218, D_L01_001D921C;
extern f32 D_L01_001D91B0, D_L01_001D91B4;
extern s32 func_L01_00518A28(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_L01_00518B60(s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_L01_005180C0(s32, s32, s32);
void func_L01_00497580(s32 a0, f32 *a1) {
    func_L01_00518A28(0x47001C, 0x80808080, 0, a1[0] + D_L01_001D9210 * 0.001953125f, a1[1] + D_L01_001D9214 / 416.0f, a1[2] + D_L01_001D9218 * 0.001953125f, a1[3] + D_L01_001D921C / 416.0f);
    func_L01_00518B60(0x47001B, 0x332299DE, a1[0], a1[1], a1[2], a1[3], D_L01_001D91B0 * 0.001953125f, D_L01_001D91B4 / 416.0f);
    func_L01_005180C0(a0, 0x47001B, 0x47001C);
}
