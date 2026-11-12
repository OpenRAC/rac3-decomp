#include "common.h"

LINKER_REMNANT("asm/levels", func_L39_005FFD10);

INCLUDE_ASM("asm/levels", func_L39_005FFD20);

INCLUDE_ASM("asm/levels", func_L39_005FFDF8);

/* localdecomp:start func_L39_005FFE78 */
typedef struct S_005FFE78 { u8 pad[0x98]; s32 f98; } S_005FFE78;
extern S_005FFE78 *D_L39_002C2840[8][4];
void func_L39_005FFE78(void)
{
    s32 i, j;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 4; j++) {
            S_005FFE78 *s = D_L39_002C2840[i][j];
            if (s != 0) s->f98 = 0;
        }
    }
}
/* localdecomp:end func_L39_005FFE78 */
