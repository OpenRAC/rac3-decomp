#include "common.h"

/* NTSC-U version of func_003BE7A8 (boot_elf): 250 -> 300; 12 -> 15; 12 -> 15 */
/* localdecomp:start func_U_003BE6B8 */
extern s16 D_0016C5A2[];
extern s32 func_U_0038CDF8(s32 *);
void func_U_003BE228(s16, s32, s32, s32);
extern u8 D_U_001DA340;

s32 func_U_003BE6B8(void) {
    s32 temp_s0;

    temp_s0 = func_U_0038CDF8(&D_U_001DA340) != 0;
    func_U_003BE228(D_0016C5A2[0], 0x12C, 0xF, 0xF);
    return temp_s0;
}
/* localdecomp:end func_U_003BE6B8 */
