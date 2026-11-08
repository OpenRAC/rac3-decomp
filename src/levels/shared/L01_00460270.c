#include "common.h"

LINKER_REMNANT("asm/levels", func_L01_00460270);

INCLUDE_ASM("asm/levels", func_L01_004602C0);

INCLUDE_ASM("asm/levels", func_L01_004606A8);

LINKER_REMNANT("asm/levels", func_L01_004606C8);

INCLUDE_ASM("asm/levels", func_L01_004606E8);

/* localdecomp:start func_L01_00460778 */
/* 1 when the two lookups both succeed and their values differ by less than limit (the game's
   integer abs, abs_asm from include/vu0.h). */
#include "vu0.h"
s32 func_L01_004606E8(void *, s32, s32 *, s32);

s32 func_L01_00460778(void *a, void *b, s32 key, s32 limit, s32 arg4) {
    s32 r = 0;
    s32 v[2];

    if (func_L01_004606E8(a, key, &v[0], arg4) && func_L01_004606E8(b, key, &v[1], arg4)) {
        r = abs_asm(v[0] - v[1]) < limit;
    }
    return r;
}
/* localdecomp:end func_L01_00460778 */

LINKER_REMNANT("asm/levels", func_L01_00460810);

INCLUDE_ASM("asm/levels", func_L01_00460818);
