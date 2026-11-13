#include "common.h"

/* localdecomp:start func_L39_00554D98 */
extern s32 D_L39_002C2840[];

void func_L39_00554D98(s32 arg0, s32 arg1) {
    s32 *p;
    s32 i;
    p = D_L39_002C2840 + arg1 * 4;
    for (i = 0; i < 4; i++) {
        if (*p == 0) {
            *p = arg0;
            return;
        }
        p++;
    }
}
/* localdecomp:end func_L39_00554D98 */

/* localdecomp:start func_L39_00554DD8 */
extern s32 D_L39_002C2840[];

s32 func_L39_00554DD8(s32 arg0) {
    s32 *p;
    s32 i;
    p = D_L39_002C2840 + arg0 * 4;
    for (i = 0; i < 4; i++) {
        if (*p == 0) {
            return 0;
        }
        p++;
    }
    return 1;
}
/* localdecomp:end func_L39_00554DD8 */

/* localdecomp:start func_L39_00554E18 */
extern s32 D_L39_002C2840[];

s32 func_L39_00554E18(s32 arg0, s32 arg1) {
    s32 *p;
    s32 i;
    p = D_L39_002C2840 + arg1 * 4;
    for (i = 0; i < 4; i++) {
        if (*p == arg0) {
            *p = 0;
            return 1;
        }
        p++;
    }
    return 0;
}
/* localdecomp:end func_L39_00554E18 */

INCLUDE_ASM("asm/levels", func_L39_00554E60);

INCLUDE_ASM("asm/levels", func_L39_00555548);

INCLUDE_ASM("asm/levels", func_L39_00556448);

INCLUDE_ASM("asm/levels", func_L39_00556638);
