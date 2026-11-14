#include "common.h"

/* NTSC-U counterpart of func_L20_004BBCA8 (src/levels/20_final_boss/L20_004BBCA8.c) */
/* localdecomp:start func_L20_004B7E48 */
typedef struct S_46FCE0 {
    int a0;
    int a4;
    int a8;
    unsigned c;
    int kind;
    unsigned char flag;
} S_46FCE0;
extern S_46FCE0 D_L20_002F5B48[];
__asm__(".extern D_L20_002F5B48, 16");
extern unsigned D_00142BA0[];
__asm__(".extern D_00142BA0, 16");
extern unsigned char D_00142693[];
__asm__(".extern D_00142693, 16");
int func_L01_00417EA0(void);

/* Walks a table of entries and sets each entry's flag from its kind: a single flag bit, a list of
 * bits that must all be set, or a global condition, each also true when challenge mode is active. */
void func_L20_004B7E48(void) {
    int i;
    int j;
    for (i = 0; D_L20_002F5B48[i].a0; i++) {
        switch (D_L20_002F5B48[i].kind) {
        case 0:
            D_L20_002F5B48[i].flag = func_L01_00417EA0() ||
                (D_00142BA0[D_L20_002F5B48[i].c >> 2] & (1 << (D_L20_002F5B48[i].c & 0x1F)));
            break;
        case 1:
            D_L20_002F5B48[i].flag = 1;
            for (j = 0; ((unsigned *)D_L20_002F5B48[i].c)[j]; j++) {
                D_L20_002F5B48[i].flag = func_L01_00417EA0() ||
                    (D_L20_002F5B48[i].flag &&
                     (D_00142BA0[((unsigned *)D_L20_002F5B48[i].c)[j] >> 2] & (1 << (((unsigned *)D_L20_002F5B48[i].c)[j] & 0x1F))));
            }
            break;
        case 2:
            D_L20_002F5B48[i].flag = (D_00142BA0[D_L20_002F5B48[i].c >> 2] & (1 << (D_L20_002F5B48[i].c & 0x1F))) != 0;
            break;
        case 3:
            D_L20_002F5B48[i].flag = D_00142693[0] != 0;
            D_L20_002F5B48[i].flag = func_L01_00417EA0();
            break;
        case 4:
        default:
            if (D_L20_002F5B48[i].a0 == 0x1C3) D_L20_002F5B48[i].flag = 1;
            else {
                D_L20_002F5B48[i].flag = D_00142693[0] != 0;
                D_L20_002F5B48[i].flag = func_L01_00417EA0();
            }
            break;
        }
    }
}
/* localdecomp:end func_L20_004B7E48 */
