#include "common.h"

/* localdecomp:start func_L39_00556C10 */
extern s32 D_L39_0024D548[];

/* from rac4-decomp's func_004F4E58 */
void func_L39_00556C10(void) {
    s32 i;
    for (i = 15; i >= 0; i--) {
        D_L39_0024D548[i] = 0;
    }
}
/* localdecomp:end func_L39_00556C10 */

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
extern s32 D_L39_0024D588_b;
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
    D_L39_0024D588_b = n;
}
/* localdecomp:end func_L39_00556C78 */

INCLUDE_ASM("asm/levels", func_L39_00556CC0);

INCLUDE_ASM("asm/levels", func_L39_00556D80);
