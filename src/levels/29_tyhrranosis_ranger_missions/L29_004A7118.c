#include "common.h"

/* localdecomp:start func_L29_004A7118 */
typedef struct S_4A7118 {
    int a0;
    int a4;
    int a8;
    unsigned c;
    int kind;
    unsigned char flag;
} S_4A7118;
extern S_4A7118 D_L29_002EC018[];
__asm__(".extern D_L29_002EC018, 16");
extern unsigned D_00142BA0[];
__asm__(".extern D_00142BA0, 16");
extern unsigned char D_00142693[];
__asm__(".extern D_00142693, 16");
int func_L01_0041A4F0(void);

void func_L29_004A7118(void) {
    int i;
    int j;
    for (i = 0; D_L29_002EC018[i].a0; i++) {
        switch (D_L29_002EC018[i].kind) {
        case 0:
            D_L29_002EC018[i].flag = func_L01_0041A4F0() ||
                (D_00142BA0[D_L29_002EC018[i].c >> 2] & (1 << (D_L29_002EC018[i].c & 0x1F)));
            break;
        case 1:
            D_L29_002EC018[i].flag = 1;
            for (j = 0; ((unsigned *)D_L29_002EC018[i].c)[j]; j++) {
                D_L29_002EC018[i].flag = func_L01_0041A4F0() ||
                    (D_L29_002EC018[i].flag &&
                     (D_00142BA0[((unsigned *)D_L29_002EC018[i].c)[j] >> 2] & (1 << (((unsigned *)D_L29_002EC018[i].c)[j] & 0x1F))));
            }
            break;
        case 2:
            D_L29_002EC018[i].flag = (D_00142BA0[D_L29_002EC018[i].c >> 2] & (1 << (D_L29_002EC018[i].c & 0x1F))) != 0;
            break;
        case 3:
            D_L29_002EC018[i].flag = D_00142693[0] != 0;
            D_L29_002EC018[i].flag = func_L01_0041A4F0();
            break;
        case 4:
        default:
            if (D_L29_002EC018[i].a0 == 0x1C3) D_L29_002EC018[i].flag = 1;
            else {
                D_L29_002EC018[i].flag = D_00142693[0] != 0;
                D_L29_002EC018[i].flag = func_L01_0041A4F0();
            }
            break;
        }
    }
}
/* localdecomp:end func_L29_004A7118 */
