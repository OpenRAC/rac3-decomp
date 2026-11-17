#include "common.h"

INCLUDE_ASM("asm/levels", func_L30_00357570);

/* localdecomp:start func_L30_00357B88 */
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern s32 D_L30_001E1428;
__asm__(".extern D_L30_001E1428, 16");
extern void func_L01_00459C50(s32);

void func_L30_00357B88(void) {
    switch (D_001D545C) {
    case 31:
        if (D_L30_001E1428 <= 8000) {
            func_L01_00459C50(25);
        }
        break;
    case 32:
        if (D_L30_001E1428 <= 14250) {
            func_L01_00459C50(26);
        }
        break;
    case 33:
        if (D_L30_001E1428 <= 6500) {
            func_L01_00459C50(27);
        }
        break;
    case 34:
        if (D_L30_001E1428 <= 5500) {
            func_L01_00459C50(28);
        }
        break;
    case 35:
        if (D_L30_001E1428 <= 6000) {
            func_L01_00459C50(29);
        }
        break;
    }
}
/* localdecomp:end func_L30_00357B88 */
