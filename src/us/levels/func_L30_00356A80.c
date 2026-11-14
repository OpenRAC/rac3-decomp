#include "common.h"

/* NTSC-U counterpart of func_L30_00357B88 (src/levels/shared/L30_00357570.c) */
/* localdecomp:start func_L30_00356A80 */
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern s32 D_L30_001E1428_00356A80;
__asm__(".extern D_L30_001E1428_00356A80, 16");
extern void func_L01_00456960(s32);

void func_L30_00356A80(void) {
    switch (D_001D545C) {
    case 31:
        if (D_L30_001E1428_00356A80 <= 9600) {
            func_L01_00456960(25);
        }
        break;
    case 32:
        if (D_L30_001E1428_00356A80 <= 17100) {
            func_L01_00456960(26);
        }
        break;
    case 33:
        if (D_L30_001E1428_00356A80 <= 7800) {
            func_L01_00456960(27);
        }
        break;
    case 34:
        if (D_L30_001E1428_00356A80 <= 6600) {
            func_L01_00456960(28);
        }
        break;
    case 35:
        if (D_L30_001E1428_00356A80 <= 7200) {
            func_L01_00456960(29);
        }
        break;
    }
}
/* localdecomp:end func_L30_00356A80 */
