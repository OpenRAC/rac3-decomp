#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_00554888);

INCLUDE_ASM("asm/levels", func_L39_00554A70);

INCLUDE_ASM("asm/levels", func_L39_00554D98);

INCLUDE_ASM("asm/levels", func_L39_00554DD8);

INCLUDE_ASM("asm/levels", func_L39_00554E18);

INCLUDE_ASM("asm/levels", func_L39_00554E60);

INCLUDE_ASM("asm/levels", func_L39_00555548);

INCLUDE_ASM("asm/levels", func_L39_00556448);

INCLUDE_ASM("asm/levels", func_L39_00556638);

INCLUDE_ASM("asm/levels", func_L39_00556C10);

/* localdecomp:start func_L39_00556C40 */
extern s32 D_L39_0024D548[];

s32 func_L39_00556C40(void) {
    s32 i;
    for (i = 0; i < 16; i++) {
        if (D_L39_0024D548[i] == 0) {
            return 0;
        }
    }
    return 1;
}
/* localdecomp:end func_L39_00556C40 */

/* localdecomp:start func_L39_00556C78 */
extern s32 D_L39_0024D588[];
extern s32 D_L39_0024D548[];
extern s32 D_L39_001E1E78;
void func_L39_00556C78(s32 a0) {
    s32 n = D_L39_0024D588[0];
    s32 i = 0;
    s32 *p = D_L39_0024D548;
    do {
        if (*p == a0) {
            *p = 0;
            n--;
            break;
        }
        i++;
        p++;
    } while (i < 16);
    D_L39_001E1E78 = n;
}
/* localdecomp:end func_L39_00556C78 */

INCLUDE_ASM("asm/levels", func_L39_00556CC0);

INCLUDE_ASM("asm/levels", func_L39_00556D80);

INCLUDE_ASM("asm/levels", func_L39_00557600);

INCLUDE_ASM("asm/levels", func_L39_00557890);

INCLUDE_ASM("asm/levels", func_L39_00557C80);

/* localdecomp:start func_L39_00557CB0 */
extern s32 D_L39_0024D590[];

s32 func_L39_00557CB0(void) {
    s32 i;
    for (i = 0; i < 16; i++) {
        if (D_L39_0024D590[i] == 0) {
            return 0;
        }
    }
    return 1;
}
/* localdecomp:end func_L39_00557CB0 */

INCLUDE_ASM("asm/levels", func_L39_00557CE8);

INCLUDE_ASM("asm/levels", func_L39_00557D20);
