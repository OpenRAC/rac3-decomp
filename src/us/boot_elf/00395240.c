#include "common.h"

/* NTSC-U version of func_00395328 (boot_elf): 25 -> 30 */
/* localdecomp:start func_U_00395240 */
extern s32 D_U_001D9F68[];
extern s32 D_U_001D9F70[];
extern s32 D_U_001D5D38;
extern s32 D_U_001D5CAC;
void func_U_00395240(u8 *p) {
    D_U_001D9F68[0] = 4;
    D_U_001D9F70[0] = (s32)&D_U_001D5D38;
    *(s32 *)(p + 0x58) = 0xD2;
    *(s32 *)(p + 0x5C) = 0xC8;
    *(s32 *)(p + 0x74) = -2;
    *(s16 *)(p + 0x48) = 0;
    *(s16 *)(p + 0x4A) = 0;
    *(s32 *)(p + 0x78) = 0x1E;
    D_U_001D5CAC = 0;
}
/* localdecomp:end func_U_00395240 */
