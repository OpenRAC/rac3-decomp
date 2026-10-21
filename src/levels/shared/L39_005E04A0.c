#include "common.h"

/* localdecomp:start func_L39_005E04A0 */
extern s32 D_L39_001D8248[2];
extern u8 D_L39_001D8258[4];
extern s32 func_L39_005E1ED0(void);
extern s32 func_L39_00610490(s32 a0);
extern void func_L01_00516AA0(s32 a0, s32 a1, s32 a2);

void func_L39_005E04A0(s32 a0, s32 a1) {
    if (func_L39_00610490(func_L39_005E1ED0()) == 1) {
        D_L39_001D8248[a0] = a1;
        D_L39_001D8258[a0] = 0;
        func_L01_00516AA0(0x30000, 1, 1);
    }
}
/* localdecomp:end func_L39_005E04A0 */

INCLUDE_ASM("asm/levels", func_L39_005E0510);

INCLUDE_ASM("asm/levels", func_L39_005E0ED8);

INCLUDE_ASM("asm/levels", func_L39_005E0F00);
