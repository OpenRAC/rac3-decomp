/* Level 4 (Marcadia), PAL. 13 differences, one cause (the same as func_L02_00473410, whose C this is with level 4's table; the earlier draft of this file, shared `i++` at the end of the switch, gave 28): retail increments `i` in place (`addiu $s2,$s2,1`) before case 1's inner loop and keeps `j` in $s4 and the flag temporary in $s3; gcc emits `addiu $s4,$s2,1` ... `move $s2,$s4` and rotates them. Cause and everything tried: see func_L02_00473410's row. */
#include "common.h"

/* localdecomp:start func_L04_004AC5A0 */typedef struct S_4AC5A0 {
    int a0;
    int a4;
    int a8;
    unsigned c;
    int kind;
    unsigned char flag;
} S_4AC5A0;
extern S_4AC5A0 D_L04_002ECBE8[];
__asm__(".extern D_L04_002ECBE8, 16");
extern unsigned D_00142BA0[];
__asm__(".extern D_00142BA0, 16");
extern unsigned char D_00142693[];
__asm__(".extern D_00142693, 16");
int func_L01_0041A4F0(void);

void func_L04_004AC5A0(void) {
    int i;
    int j;
    i = 0;
    while (D_L04_002ECBE8[i].a0) {
        switch (D_L04_002ECBE8[i].kind) {
        case 0:
            D_L04_002ECBE8[i].flag = (D_00142BA0[D_L04_002ECBE8[i].c >> 2] & (1 << (D_L04_002ECBE8[i].c & 0x1F))) || func_L01_0041A4F0();
            i++;
            break;
        case 1:
            D_L04_002ECBE8[i].flag = 0;
            for (j = 0; ((unsigned *)D_L04_002ECBE8[i].c)[j]; j++) {
                D_L04_002ECBE8[i].flag = D_L04_002ECBE8[i].flag ||
                    (D_00142BA0[((unsigned *)D_L04_002ECBE8[i].c)[j] >> 2] & (1 << (((unsigned *)D_L04_002ECBE8[i].c)[j] & 0x1F))) || func_L01_0041A4F0();
            }
            i++;
            break;
        case 2:
            D_L04_002ECBE8[i].flag = (D_00142BA0[D_L04_002ECBE8[i].c >> 2] & (1 << (D_L04_002ECBE8[i].c & 0x1F))) || func_L01_0041A4F0();
            i++;
            break;
        case 3:
        case 4:
        default:
            D_L04_002ECBE8[i].flag = D_00142693[0] || func_L01_0041A4F0();
            i++;
            break;
        }
    }
}
/* localdecomp:end func_L04_004AC5A0 */
