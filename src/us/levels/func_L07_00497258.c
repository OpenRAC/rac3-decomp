#include "common.h"

/* NTSC-U counterpart of func_L07_0049AA38 (src/levels/07_annihilation_nation/L07_0049AA38.c) */
/* localdecomp:start func_L07_00497258 */
typedef struct S_46FCE0 {
    int a0;
    int a4;
    int a8;
    unsigned c;
    int kind;
    unsigned char flag;
} S_46FCE0;
extern S_46FCE0 D_L07_002EDDF8[];
__asm__(".extern D_L07_002EDDF8, 16");
extern unsigned D_00142BA0[];
__asm__(".extern D_00142BA0, 16");
extern unsigned char D_00142693[];
__asm__(".extern D_00142693, 16");
int func_L01_00417EA0(void);

void func_L07_00497258(void) {
    int i;
    int j;
    for (i = 0; D_L07_002EDDF8[i].a0; i++) {
        switch (D_L07_002EDDF8[i].kind) {
        case 0:
            D_L07_002EDDF8[i].flag = func_L01_00417EA0() ||
                (D_00142BA0[D_L07_002EDDF8[i].c >> 2] & (1 << (D_L07_002EDDF8[i].c & 0x1F)));
            break;
        case 1:
            D_L07_002EDDF8[i].flag = 1;
            for (j = 0; ((unsigned *)D_L07_002EDDF8[i].c)[j]; j++) {
                D_L07_002EDDF8[i].flag = func_L01_00417EA0() ||
                    (D_L07_002EDDF8[i].flag &&
                     (D_00142BA0[((unsigned *)D_L07_002EDDF8[i].c)[j] >> 2] & (1 << (((unsigned *)D_L07_002EDDF8[i].c)[j] & 0x1F))));
            }
            break;
        case 2:
            D_L07_002EDDF8[i].flag = (D_00142BA0[D_L07_002EDDF8[i].c >> 2] & (1 << (D_L07_002EDDF8[i].c & 0x1F))) != 0;
            break;
        case 3:
            D_L07_002EDDF8[i].flag = D_00142693[0] != 0;
            D_L07_002EDDF8[i].flag = func_L01_00417EA0();
            break;
        case 4:
        default:
            if (D_L07_002EDDF8[i].a0 == 0x1C3) D_L07_002EDDF8[i].flag = 1;
            else {
                D_L07_002EDDF8[i].flag = D_00142693[0] != 0;
                D_L07_002EDDF8[i].flag = func_L01_00417EA0();
            }
            break;
        }
    }
}
/* localdecomp:end func_L07_00497258 */
