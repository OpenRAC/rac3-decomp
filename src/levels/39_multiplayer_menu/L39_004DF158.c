#include "common.h"

/* localdecomp:start func_L39_004DF158 */
typedef struct { u8 b[64]; } S_004DF158_blob;
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    S_004DF158_blob f18;
} S_004DF158_rec;
s32 func_L39_00505120(s32, s32);

s32 func_L39_004DF158(S_004DF158_rec *arg0, S_004DF158_rec *arg1) {
    arg0->f0 = arg1->f0;
    if (func_L39_00505120(arg0->f4, arg1->f4) == 0) {
        return 0;
    }
    if (func_L39_00505120(arg0->f8, arg1->f8) == 0) {
        return 0;
    }
    if (func_L39_00505120(arg0->fC, arg1->fC) == 0) {
        return 0;
    }
    arg0->f10 = arg1->f10;
    arg0->f14 = arg1->f14;
    arg0->f18 = arg1->f18;
    return 1;
}
/* localdecomp:end func_L39_004DF158 */

INCLUDE_ASM("asm/levels", func_L39_004DF260);

INCLUDE_ASM("asm/levels", func_L39_004DF408);

INCLUDE_ASM("asm/levels", func_L39_004DF410);

INCLUDE_ASM("asm/levels", func_L39_004DF668);

INCLUDE_ASM("asm/levels", func_L39_004DF678);

INCLUDE_ASM("asm/levels", func_L39_004DF688);

INCLUDE_ASM("asm/levels", func_L39_004DF698);

INCLUDE_ASM("asm/levels", func_L39_004DF6A8);

INCLUDE_ASM("asm/levels", func_L39_004DF6B8);

INCLUDE_ASM("asm/levels", func_L39_004DF820);

INCLUDE_ASM("asm/levels", func_L39_004DFB38);

INCLUDE_ASM("asm/levels", func_L39_004DFB88);

INCLUDE_ASM("asm/levels", func_L39_004DFD50);

INCLUDE_ASM("asm/levels", func_L39_004E00C8);

INCLUDE_ASM("asm/levels", func_L39_004E0280);

INCLUDE_ASM("asm/levels", func_L39_004E03B8);

INCLUDE_ASM("asm/levels", func_L39_004E0490);

INCLUDE_ASM("asm/levels", func_L39_004E0698);

INCLUDE_ASM("asm/levels", func_L39_004E09E0);

INCLUDE_ASM("asm/levels", func_L39_004E0A58);

INCLUDE_ASM("asm/levels", func_L39_004E0B10);

INCLUDE_ASM("asm/levels", func_L39_004E0BC8);

INCLUDE_ASM("asm/levels", func_L39_004E0C88);

INCLUDE_ASM("asm/levels", func_L39_004E0D60);

INCLUDE_ASM("asm/levels", func_L39_004E0E98);
