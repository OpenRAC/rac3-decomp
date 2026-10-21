#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_00677D08);

INCLUDE_ASM("asm/levels", func_L39_00677D78);

/* localdecomp:start func_L39_00677EF0 */
extern void func_L39_00589538(s32);
extern void func_L39_00679630(void);
extern void func_L39_00677F28(void);
extern void func_00389370(void);
void func_L39_00677EF0(void) {
    func_L39_00589538(1);
    func_L39_00679630();
    func_L39_00677F28();
    func_00389370();
}
/* localdecomp:end func_L39_00677EF0 */

INCLUDE_ASM("asm/levels", func_L39_00677F28);

INCLUDE_ASM("asm/levels", func_L39_00677FD8);

INCLUDE_ASM("asm/levels", func_L39_006787B0);

INCLUDE_ASM("asm/levels", func_L39_006788F8);

INCLUDE_ASM("asm/levels", func_L39_00678A50);

INCLUDE_ASM("asm/levels", func_L39_006792F8);

INCLUDE_ASM("asm/levels", func_L39_006793D8);

INCLUDE_ASM("asm/levels", func_L39_00679630);

INCLUDE_ASM("asm/levels", func_L39_00679AE0);

INCLUDE_ASM("asm/levels", func_L39_00679B88);

INCLUDE_ASM("asm/levels", func_L39_00679DA0);

INCLUDE_ASM("asm/levels", func_L39_00679F08);

INCLUDE_ASM("asm/levels", func_L39_0067A4E0);

INCLUDE_ASM("asm/levels", func_L39_0067A6D0);

/* localdecomp:start func_L39_0067A748 */
extern u8 *D_L39_00241640[];
extern s32 func_L39_0067A6D0(void);

s32 func_L39_0067A748(void) {
    u8 *p = D_L39_00241640[0];
    s32 r = 1;
    if (p != 0) {
        s32 b = p[409];
        r = (b >> func_L39_0067A6D0()) & 1;
    }
    return r;
}
/* localdecomp:end func_L39_0067A748 */
