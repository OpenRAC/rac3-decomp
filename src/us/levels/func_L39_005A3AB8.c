#include "common.h"

/* NTSC-U counterpart of func_L39_005A5728 (src/levels/shared/L39_005A5238.c) */
extern s32 D_L39_00240578;
extern s32 D_L39_0024057C;
extern s32 D_001A4568[];
extern s32 D_001D4CE8_sda_005A3AB8;
extern s32 D_L39_00240578;
extern s32 D_L39_0024057C;
extern s32 D_001A4568[];
extern s32 D_L39_0024057C;
extern s32 D_L39_00240578;
extern u8 D_L39_00242B2C;
extern s32 D_001D4CE8_sda_005A3AB8;
extern s32 D_001D4CE8_sda_005A3AB8;
extern int D_001A4568[];
extern int D_001D4CE8_sda_005A3AB8;
extern int D_L39_00240578;
extern s32 D_001D4CE8_sda_005A3AB8;
extern s32 D_L39_00240578;
extern s32 D_L39_0024057C;
extern s32 D_L39_00240578;
extern s32 D_L39_0024057C;
extern int D_001A4568[];
extern int D_001D4CE8_sda_005A3AB8;
extern int D_L39_00240578;

/* localdecomp:start func_L39_005A3AB8 */
extern s32 D_001A4568[];
extern s32 D_L39_0024057C;
extern s32 D_L39_00240578;
extern u8 D_L39_00242B2C;
extern s32 D_001D4CE8_sda_005A3AB8;

void func_L39_005A3AB8(void) {
    if (D_001A4568[0] != 2) {
        D_001D4CE8_sda_005A3AB8 = 4;
        return;
    }
    if (D_L39_0024057C & 0x20) {
        D_L39_0024057C = D_L39_0024057C ^ 0x20;
        if (D_L39_00242B2C != 0) {
            D_001D4CE8_sda_005A3AB8 = 0x1B;
        } else {
            D_001D4CE8_sda_005A3AB8 = 0xE;
        }
        return;
    }
    if (D_L39_0024057C & 0x2000) {
        D_L39_00240578 = 0x10;
    }
}
/* localdecomp:end func_L39_005A3AB8 */
