#include "common.h"

/* localdecomp:start func_L39_00528A88 */
extern s32 D_L39_0024D4DC[];

/* from rac4-decomp's func_004F4E58 */
void func_L39_00528A88(void) {
    s32 i;
    s32 *p;
    i = 15;
    p = D_L39_0024D4DC;
    do {
        *p = 0;
        i--;
        p--;
    } while (i >= 0);
}
/* localdecomp:end func_L39_00528A88 */

/* localdecomp:start func_L39_00528AB8 */
extern s32 D_L39_0024D4A0[];

s32 func_L39_00528AB8(void) {
    s32 i;
    for (i = 0; i < 16; i++) {
        if (D_L39_0024D4A0[i] == 0) {
            return 0;
        }
    }
    return 1;
}
/* localdecomp:end func_L39_00528AB8 */

/* localdecomp:start func_L39_00528AF0 */
extern s32 D_L39_0024D4E0[];
extern s32 D_L39_0024D4A0[];
extern s32 D_L39_0024D4E0_b;
void func_L39_00528AF0(s32 a0) {
    s32 n = D_L39_0024D4E0[0];
    s32 i = 0;
    s32 *p = D_L39_0024D4A0;
    do {
        if (*p == a0) {
            *p = 0;
            n--;
            break;
        }
        i++;
        p++;
    } while (i < 16);
    D_L39_0024D4E0_b = n;
}
/* localdecomp:end func_L39_00528AF0 */

INCLUDE_ASM("asm/levels", func_L39_00528B38);

INCLUDE_ASM("asm/levels", func_L39_00528BF0);
