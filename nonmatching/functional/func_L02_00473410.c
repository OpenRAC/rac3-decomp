/* functional: high. Retail behaviour kept; check.py shows 13 byte differences from loop-index/flag-temp register allocation only. Jump table jtbl_002BA8B0: 0,1,2 own cases, 3 and 4 and out-of-range read byte D_00142693. Delete INCLUDE_RODATA of the table when landing. */
#include "common.h"
typedef struct S_473410 {
    int a0;
    int a4;
    int a8;
    unsigned c;
    int kind;
    unsigned char flag;
} S_473410;
extern S_473410 D_L02_002E9EC8[];
__asm__(".extern D_L02_002E9EC8, 16");
extern unsigned D_00142BA0[];
__asm__(".extern D_00142BA0, 16");
extern unsigned char D_00142693[];
__asm__(".extern D_00142693, 16");
int func_L01_0041A4F0(void);

void func_L02_00473410(void) {
    int i;
    int j;
    i = 0;
    while (D_L02_002E9EC8[i].a0) {
        switch (D_L02_002E9EC8[i].kind) {
        case 0:
            D_L02_002E9EC8[i].flag = (D_00142BA0[D_L02_002E9EC8[i].c >> 2] & (1 << (D_L02_002E9EC8[i].c & 0x1F))) || func_L01_0041A4F0();
            i++;
            break;
        case 1:
            D_L02_002E9EC8[i].flag = 0;
            for (j = 0; ((unsigned *)D_L02_002E9EC8[i].c)[j]; j++) {
                D_L02_002E9EC8[i].flag = D_L02_002E9EC8[i].flag ||
                    (D_00142BA0[((unsigned *)D_L02_002E9EC8[i].c)[j] >> 2] & (1 << (((unsigned *)D_L02_002E9EC8[i].c)[j] & 0x1F))) || func_L01_0041A4F0();
            }
            i++;
            break;
        case 2:
            D_L02_002E9EC8[i].flag = (D_00142BA0[D_L02_002E9EC8[i].c >> 2] & (1 << (D_L02_002E9EC8[i].c & 0x1F))) || func_L01_0041A4F0();
            i++;
            break;
        case 3:
        case 4:
        default:
            D_L02_002E9EC8[i].flag = D_00142693[0] || func_L01_0041A4F0();
            i++;
            break;
        }
    }
}
