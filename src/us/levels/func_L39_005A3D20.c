#include "common.h"

/* NTSC-U counterpart of func_L39_005A5990 (src/levels/shared/L39_005A5238.c) */
extern s32 D_L39_00240578;
extern s32 D_L39_0024057C;
extern s32 D_001A4568[];
extern s32 D_L39_00240578;
extern s32 D_L39_0024057C;
extern s32 D_001A4568[];
extern s32 D_L39_0024057C;
extern s32 D_L39_00240578;
extern s32 D_001D4CEC_sda_005A3D20;
extern int D_001A4568[];
extern int D_001D4CEC_sda_005A3D20;
extern int D_L39_00240578;
extern s32 D_001D4CEC_sda_005A3D20;
extern s32 D_001D4CEC_sda_005A3D20;
extern s32 D_L39_00240578;
extern s32 D_L39_0024057C;
extern s32 D_001D4CEC_sda_005A3D20;
extern s32 D_L39_00240578;
extern s32 D_L39_0024057C;
extern int D_001A4568[];
extern int D_001D4CEC_sda_005A3D20;
extern int D_L39_00240578;
extern s32 D_001A4568[];
extern s32 D_L39_0024057C;
extern s32 D_L39_00240578;
extern s32 D_001D4CEC_sda_005A3D20;
extern s32 D_001D4CEC_sda_005A3D20;
extern s32 D_001D4CEC_sda_005A3D20;
extern s32 D_L39_00240578;

/* localdecomp:start func_L39_005A3D20 */
__asm__(".extern D_001D4CEC_sda_005A3D20, 4");
extern s32 D_001D4CEC_sda_005A3D20;
extern s32 D_L39_00240578;
extern s32 D_L39_0024057C;
extern s32 D_001A4568[];

void func_L39_005A3D20(void) {
    s32 w = D_L39_0024057C;

    if (w & 4) {
        D_L39_00240578 = 0x1E;
    }
    if (w & 2) {
        D_L39_00240578 = 0x1D;
    }
    if (w & 0x800) {
        D_L39_00240578 = 0xC;
    }
    if (w & 0x80) {
        D_L39_00240578 = 0x18;
        D_001D4CEC_sda_005A3D20 = (w ^ 0x80) | 0x40;
    } else if (w & 0x100) {
        D_L39_00240578 = 0x16;
        D_001D4CEC_sda_005A3D20 = (w ^ 0x100) | 0x40;
    } else if (D_001A4568[0] != 2) {
        D_L39_00240578 = 4;
    }
}
/* localdecomp:end func_L39_005A3D20 */
