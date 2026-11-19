#include "common.h"

typedef int s128 __attribute__((mode(TI)));

/* localdecomp:start func_L01_00422FE0 */
extern void func_L01_003FE938_00422FE0();

void func_L01_00422FE0(void) {
    func_L01_003FE938_00422FE0();
}
/* localdecomp:end func_L01_00422FE0 */

INCLUDE_ASM("asm/levels", func_L01_00423000);

/* localdecomp:start func_L01_00423020 */
extern void func_L01_003FEA68_00423020();

void func_L01_00423020(void) {
    func_L01_003FEA68_00423020();
}
/* localdecomp:end func_L01_00423020 */

/* localdecomp:start func_L01_00423040 */
extern void func_L01_003FF240_00423040();

void func_L01_00423040(void) {
    func_L01_003FF240_00423040();
}
/* localdecomp:end func_L01_00423040 */

LINKER_REMNANT("asm/levels", func_L01_00423060);

INCLUDE_ASM("asm/levels", func_L01_00423068);

LINKER_REMNANT("asm/levels", func_L01_004234E0);

/* localdecomp:start func_L01_004234E8 */
extern s32 D_L01_001DFE10;
extern s128 D_L01_001DFDD0[];

void func_L01_004234E8(s128 *a0, s32 a1) {
    s32 i;

    D_L01_001DFE10 = a1;
    for (i = 0; i < 4; i++) {
        D_L01_001DFDD0[i] = a0[i];
        ((f32 *)&D_L01_001DFDD0[i])[3] = 1.0f;
    }
}
/* localdecomp:end func_L01_004234E8 */

/* localdecomp:start func_L01_00423530 */
extern s32 D_L01_001DFE60;
extern s128 D_L01_001DFE20[];

void func_L01_00423530(s128 *a0, s32 a1) {
    s32 i;

    D_L01_001DFE60 = a1;
    for (i = 0; i < 4; i++) {
        D_L01_001DFE20[i] = *a0++;
        ((f32 *)&D_L01_001DFE20[i])[3] = 1.0f;
    }
}
/* localdecomp:end func_L01_00423530 */

LINKER_REMNANT("asm/levels", func_L01_00423578);

INCLUDE_ASM("asm/levels", func_L01_00423580);
