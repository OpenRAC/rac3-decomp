#include "common.h"

/* localdecomp:start func_L01_004AD7A8 */
extern void func_003A62D0(s32, s32, s32);
extern void func_003A8450(void);
void func_L01_004AD7A8(s32 a0) {
    func_003A62D0(a0, 1, 1);
    func_003A62D0(a0, 2, 1);
    func_003A8450();
}
/* localdecomp:end func_L01_004AD7A8 */

LINKER_REMNANT("asm/levels", func_L01_004AD7F0);

INCLUDE_ASM("asm/levels", func_L01_004AD808);

INCLUDE_ASM("asm/levels", func_L01_004AD9A0);

/* localdecomp:start func_L01_004AF178 */
extern s16 D_0016C5A0[];
extern s32 D_L01_001DF944;
extern void func_L01_00403BB8(void);
extern void func_00388AF8(s32);

void func_L01_004AF178(void) {
    switch (D_0016C5A0[0]) {
    case 0:
    case 3:
        func_L01_00403BB8();
        break;
    case 1:
        D_L01_001DF944 = 127;
        func_00388AF8(0);
        break;
    }
}
/* localdecomp:end func_L01_004AF178 */

LINKER_REMNANT("asm/levels", func_L01_004AF1E0);
