#include "common.h"

/* NTSC-U counterpart of func_L07_003C1448 (src/levels/07_annihilation_nation/L07_003C0710.c) */
/* localdecomp:start func_L07_003BFAF8 */
extern u8 D_001426E0[];
extern u8 D_00142CBE[];
extern u16 D_001A8070[];
extern u8 D_001A4C60[];
extern s32 func_0037E0F0(void *, s32, s32);
extern void func_L01_00417F60(s32, s32);
extern s32 func_L07_003A0BC0(s32, s32, s32, s32);

void func_L07_003BFAF8(u8 *a0) {
    u8 *s2;
    u8 *s1;
    u8 s0;

    s0 = 0xFF;
    s2 = *(u8 **)(a0 + 0x68);
    if (D_00142CBE[0] == 0) {
        if (D_001A8070[0] == 0) {
            s0 = func_0037E0F0(D_001A4C60, *(s32 *)(s2 + 0x14), 0);
            if (s0 != 0) {
                func_L01_00417F60(0xB8F, 0x32);
            }
        }
    }
    s1 = D_001426E0;
    if (s1[0x8F] != 0) {
        if ((s1[0xD9] ^ 1) & 1) {
            if (s0 == 0xFF) {
                s0 = func_0037E0F0(D_001A4C60, *(s32 *)(s2 + 0x14), 0);
            }
            if (s0 != 0) {
                func_L07_003A0BC0(0x73, 0, 0, 0x78);
                s1[0xD9] |= 1;
            }
        }
    }
}
/* localdecomp:end func_L07_003BFAF8 */
