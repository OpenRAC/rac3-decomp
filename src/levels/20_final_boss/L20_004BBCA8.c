#include "common.h"

typedef struct S_46FCE0 {
    int a0;
    int a4;
    int a8;
    unsigned c;
    int kind;
    unsigned char flag;
} S_46FCE0;

/* localdecomp:start func_L20_004BBCA8 */
/* PAL port of the NTSC-U match src/us/levels/func_L20_004B7E48.c */

extern S_46FCE0 D_L20_002F5B78[];
__asm__(".extern D_L20_002F5B78, 16");
extern unsigned D_142BA0[];
__asm__(".extern D_142BA0, 16");
extern unsigned char D_00142693[];
__asm__(".extern D_00142693, 16");
int func_L01_0041A4F0(void);

void func_L20_004BBCA8(void) {
    int i;
    int j;
    for (i = 0; D_L20_002F5B78[i].a0; i++) {
        switch (D_L20_002F5B78[i].kind) {
        case 0:
            D_L20_002F5B78[i].flag = func_L01_0041A4F0() ||
                (D_142BA0[D_L20_002F5B78[i].c >> 2] & (1 << (D_L20_002F5B78[i].c & 0x1F)));
            break;
        case 1:
            D_L20_002F5B78[i].flag = 1;
            for (j = 0; ((unsigned *)D_L20_002F5B78[i].c)[j]; j++) {
                D_L20_002F5B78[i].flag = func_L01_0041A4F0() ||
                    (D_L20_002F5B78[i].flag &&
                     (D_142BA0[((unsigned *)D_L20_002F5B78[i].c)[j] >> 2] & (1 << (((unsigned *)D_L20_002F5B78[i].c)[j] & 0x1F))));
            }
            break;
        case 2:
            D_L20_002F5B78[i].flag = (D_142BA0[D_L20_002F5B78[i].c >> 2] & (1 << (D_L20_002F5B78[i].c & 0x1F))) != 0;
            break;
        case 3:
            D_L20_002F5B78[i].flag = D_00142693[0] != 0;
            D_L20_002F5B78[i].flag = func_L01_0041A4F0();
            break;
        case 4:
        default:
            if (D_L20_002F5B78[i].a0 == 0x1C3) D_L20_002F5B78[i].flag = 1;
            else {
                D_L20_002F5B78[i].flag = D_00142693[0] != 0;
                D_L20_002F5B78[i].flag = func_L01_0041A4F0();
            }
            break;
        }
    }
}
/* localdecomp:end func_L20_004BBCA8 */
