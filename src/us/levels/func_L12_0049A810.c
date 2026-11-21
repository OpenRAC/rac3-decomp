#include "common.h"

/* NTSC-U counterpart of func_L12_0049E1F0 (src/levels/12_rilgar/L12_0049E1F0.c): the same code, the table at its NTSC-U address */
/* localdecomp:start func_L12_0049A810 */
typedef struct { s32 f0; s32 p4; s32 p8; union { u32 bit; u32 *list; } c; s32 mode; u8 flag; u8 pad[3]; } E_0049A810;
extern E_0049A810 D_L12_002EC398[];
extern u32 D_00142BA0[];
extern u8 D_00142693[];
int func_L01_00417EA0(void);

void func_L12_0049A810(void) {
    s32 i;

    i = 0;
    while (D_L12_002EC398[i].f0 != 0) {
        switch (D_L12_002EC398[i].mode) {
        case 0:
            D_L12_002EC398[i].flag = (D_00142BA0[D_L12_002EC398[i].c.bit >> 2] & (1 << (D_L12_002EC398[i].c.bit & 31))) || func_L01_00417EA0();
            break;
        case 1: {
            s32 k;
            D_L12_002EC398[i].flag = 0;
            for (k = 0; D_L12_002EC398[i].c.list[k] != 0; k++)
                D_L12_002EC398[i].flag = D_L12_002EC398[i].flag || (D_00142BA0[D_L12_002EC398[i].c.list[k] >> 2] & (1 << (D_L12_002EC398[i].c.list[k] & 31))) || func_L01_00417EA0();
            break;
        }
        case 2:
            D_L12_002EC398[i].flag = (D_00142BA0[D_L12_002EC398[i].c.bit >> 2] & (1 << (D_L12_002EC398[i].c.bit & 31))) || func_L01_00417EA0();
            break;
        case 3:
            /* Written out apart from the default (cross-jumping merges the two bodies): one more path
               into the shared `i++`, which gives gcse's `i + 1` temporary the weight that keeps it
               in i's register, as in retail. */
            D_L12_002EC398[i].flag = D_00142693[0] || func_L01_00417EA0();
            break;
        case 4:
        default:
            D_L12_002EC398[i].flag = D_00142693[0] || func_L01_00417EA0();
            break;
        }
        i++;
    }
}
/* localdecomp:end func_L12_0049A810 */
