/* near miss (level 3, Starship Phoenix): 1 difference: the trailing `addiu $sp,$sp,0x30` in the jr delay slot is cut by the catalogue size (0x118), so the C is one instruction longer; everything else is byte-identical (same body as func_00397EA8 in src/frontbin/397D48.c, a memory-layout struct init); same class as func_L01_00350040 */
#include "common.h"

/* localdecomp:start func_L03_0040FEE8 */
extern u8 D_L03_001E9140[];
extern u8 D_L03_00510717[];
extern u8 D_01FF8000[];
extern u8 D_01FFC000[];
extern u32 D_L03_001E09F0;
__asm__(".extern D_L03_001E09F0, 16");
extern s32 func_0011A264(s32, s32, s32);
void func_L03_0040FEE8(void) {
    u32 *s = (u32 *)D_L03_001E9140;
    u32 c;
    func_0011A264((s32)s, 0, 0xA0);
    c = (u32)D_01FFC000;
    s[0] = 0;
    s[1] = 0x100000;
    s[2] = (u32)D_L03_00510717 & 0xFFFFF000;
    s[3] = s[2];
    s[4] = s[3] + D_L03_001E09F0;
    s[5] = s[4] + D_L03_001E09F0;
    s[6] = s[5] + 0x100000;
    s[0x22] = (u32)D_01FF8000;
    s[0x21] = s[0x22] - 0x40000;
    s[0x20] = s[0x21] - 0x64000;
    s[0x1F] = s[0x20];
    s[0x1E] = s[0x1F] - 0x2C000;
    s[0x1D] = s[0x1E] - 0x8000;
    s[0x1C] = s[0x1D] - 0x14000;
    s[0x1A] = s[6];
    s[0x23] = c;
    s[0x1B] = s[0x1C];
    s[0x24] = 0x7000000;
    s[0x25] = 0x7100000;
    s[0x26] = 0x7180000;
    s[0x27] = 0x7200000;
}
/* localdecomp:end func_L03_0040FEE8 */
