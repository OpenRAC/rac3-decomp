/* near miss (level 12, Rilgar): 13 differences, the same one as Florana's func_L02_00473410 (this is its C with level 12's table at 0x2EC348): retail increments i in place in case 1 (addiu $s2,$s2,1) and keeps j in $s4 and the flag temporary in $s3; gcc emits addiu $s4,$s2,1 and a move $s2,$s4 at the end, shifting both. Taking &D[i] (and &D[i].c) before an early i++ in case 1 gives 107 and 118 differences */
#include "common.h"

/* localdecomp:start func_L12_0049E1F0 */
typedef struct S_49E1F0 {
    int a0;
    int a4;
    int a8;
    unsigned c;
    int kind;
    unsigned char flag;
} S_49E1F0;
extern S_49E1F0 D_L12_002EC348[];
__asm__(".extern D_L12_002EC348, 16");
extern unsigned D_00142BA0[];
__asm__(".extern D_00142BA0, 16");
extern unsigned char D_00142693[];
__asm__(".extern D_00142693, 16");
int func_L01_0041A4F0(void);

void func_L12_0049E1F0(void) {
    int i;
    int j;
    i = 0;
    while (D_L12_002EC348[i].a0) {
        switch (D_L12_002EC348[i].kind) {
        case 0:
            D_L12_002EC348[i].flag = (D_00142BA0[D_L12_002EC348[i].c >> 2] & (1 << (D_L12_002EC348[i].c & 0x1F))) || func_L01_0041A4F0();
            i++;
            break;
        case 1:
            D_L12_002EC348[i].flag = 0;
            for (j = 0; ((unsigned *)D_L12_002EC348[i].c)[j]; j++) {
                D_L12_002EC348[i].flag = D_L12_002EC348[i].flag ||
                    (D_00142BA0[((unsigned *)D_L12_002EC348[i].c)[j] >> 2] & (1 << (((unsigned *)D_L12_002EC348[i].c)[j] & 0x1F))) || func_L01_0041A4F0();
            }
            i++;
            break;
        case 2:
            D_L12_002EC348[i].flag = (D_00142BA0[D_L12_002EC348[i].c >> 2] & (1 << (D_L12_002EC348[i].c & 0x1F))) || func_L01_0041A4F0();
            i++;
            break;
        case 3:
        case 4:
        default:
            D_L12_002EC348[i].flag = D_00142693[0] || func_L01_0041A4F0();
            i++;
            break;
        }
    }
}
/* localdecomp:end func_L12_0049E1F0 */
