/* Level 02 (Florana), PAL. 13 diff with check.py --target level_02. 13 differences, one cause: retail increments `i` in place (`addiu $s2,$s2,1`) and hoists `&D[i].c` / `&D[i].flag` as loop invariants in `$s0`/`$s1`; this C reproduces the hoisting and the instruction sequence (cases 0-2 as two separate bodies, flag = `bit test || call`) but gcc emits `addiu $s4,$s2,1` followed by `move $s2,$s4`, which shifts `j` to `$s3` and the flag temporary to `$s2` (retail: `j`=`$s4`, temporary=`$s3`). Same family as func_L01_0049BBD8; the `for` and `n = i + 1` shapes gave 28 differences, a `while` with `i++` ending every case gave 13. Delete the INCLUDE_RODATA line (jtbl_002BA8B0, five entries) when landing. */
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
