#include "common.h"

/* NTSC-U counterpart of func_L24_00480DB0 (src/levels/24_insomniac_museum/L24_00480DB0.c) */
/* localdecomp:start func_L24_0047D4D0 */
typedef struct S_480DB0 {
    int a0;
    int a4;
    int a8;
    unsigned c;
    int kind;
    unsigned char flag;
} S_480DB0;
extern S_480DB0 D_L24_002E9DA8[];
__asm__(".extern D_L24_002E9DA8, 16");
extern unsigned D_00142BA0[];
__asm__(".extern D_00142BA0, 16");
extern unsigned char D_00142693[];
__asm__(".extern D_00142693, 16");
int func_L01_00417EA0(void);

void func_L24_0047D4D0(void) {
    int i;
    int j;
    for (i = 0; D_L24_002E9DA8[i].a0; i++) {
        switch (D_L24_002E9DA8[i].kind) {
        case 0:
            D_L24_002E9DA8[i].flag = func_L01_00417EA0() ||
                (D_00142BA0[D_L24_002E9DA8[i].c >> 2] & (1 << (D_L24_002E9DA8[i].c & 0x1F)));
            break;
        case 1:
            D_L24_002E9DA8[i].flag = 1;
            for (j = 0; ((unsigned *)D_L24_002E9DA8[i].c)[j]; j++) {
                D_L24_002E9DA8[i].flag = func_L01_00417EA0() ||
                    (D_L24_002E9DA8[i].flag &&
                     (D_00142BA0[((unsigned *)D_L24_002E9DA8[i].c)[j] >> 2] & (1 << (((unsigned *)D_L24_002E9DA8[i].c)[j] & 0x1F))));
            }
            break;
        case 2:
            D_L24_002E9DA8[i].flag = (D_00142BA0[D_L24_002E9DA8[i].c >> 2] & (1 << (D_L24_002E9DA8[i].c & 0x1F))) != 0;
            break;
        case 3:
            D_L24_002E9DA8[i].flag = D_00142693[0] != 0;
            D_L24_002E9DA8[i].flag = func_L01_00417EA0();
            break;
        case 4:
        default:
            if (D_L24_002E9DA8[i].a0 == 0x1C3) D_L24_002E9DA8[i].flag = 1;
            else {
                D_L24_002E9DA8[i].flag = D_00142693[0] != 0;
                D_L24_002E9DA8[i].flag = func_L01_00417EA0();
            }
            break;
        }
    }
}
/* localdecomp:end func_L24_0047D4D0 */
