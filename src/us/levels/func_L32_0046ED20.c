#include "common.h"

/* localdecomp:start func_L32_0046ED20 */
typedef struct S_46FCE0 {
    int a0;
    int a4;
    int a8;
    unsigned c;
    int kind;
    unsigned char flag;
} S_46FCE0;
extern S_46FCE0 D_L32_002EC668[];
__asm__(".extern D_L32_002EC668, 16");
extern unsigned D_00142BA0[];
__asm__(".extern D_00142BA0, 16");
extern unsigned char D_00142693[];
__asm__(".extern D_00142693, 16");
int func_L01_00417EA0(void);

/* Walks a table of entries ending at a zero first field and sets each entry's flag from the game's
 * bit flags (one bit, all of a list, or a byte); challenge_mode_active forces it on for most kinds. */
void func_L32_0046ED20(void) {
    int i;
    int j;
    for (i = 0; D_L32_002EC668[i].a0; i++) {
        switch (D_L32_002EC668[i].kind) {
        case 0:
            D_L32_002EC668[i].flag = func_L01_00417EA0() ||
                (D_00142BA0[D_L32_002EC668[i].c >> 2] & (1 << (D_L32_002EC668[i].c & 0x1F)));
            break;
        case 1:
            D_L32_002EC668[i].flag = 1;
            for (j = 0; ((unsigned *)D_L32_002EC668[i].c)[j]; j++) {
                D_L32_002EC668[i].flag = func_L01_00417EA0() ||
                    (D_L32_002EC668[i].flag &&
                     (D_00142BA0[((unsigned *)D_L32_002EC668[i].c)[j] >> 2] & (1 << (((unsigned *)D_L32_002EC668[i].c)[j] & 0x1F))));
            }
            break;
        case 2:
            D_L32_002EC668[i].flag = (D_00142BA0[D_L32_002EC668[i].c >> 2] & (1 << (D_L32_002EC668[i].c & 0x1F))) != 0;
            break;
        case 3:
            D_L32_002EC668[i].flag = D_00142693[0] != 0;
            D_L32_002EC668[i].flag = func_L01_00417EA0();
            break;
        case 4:
        default:
            if (D_L32_002EC668[i].a0 == 0x1C3) D_L32_002EC668[i].flag = 1;
            else {
                D_L32_002EC668[i].flag = D_00142693[0] != 0;
                D_L32_002EC668[i].flag = func_L01_00417EA0();
            }
            break;
        }
    }
}
/* localdecomp:end func_L32_0046ED20 */
