#include "common.h"

/* localdecomp:start func_L14_00487620 */
/* from rac3's func_L11_00472AD8 (same table walk) */
typedef struct { s32 f0; s32 p4; s32 p8; union { u32 bit; u32 *list; } c; s32 mode; u8 flag; u8 pad[3]; } E_487620;
extern E_487620 D_L14_002EE128[];
extern u32 D_00142BA0[];
extern u8 D_00142693[];
extern s32 func_L01_0041A4F0(void);

void func_L14_00487620(void) {
    s32 i;

    i = 0;
    while (D_L14_002EE128[i].f0 != 0) {
        switch (D_L14_002EE128[i].mode) {
        case 0:
            D_L14_002EE128[i].flag = (D_00142BA0[D_L14_002EE128[i].c.bit >> 2] & (1 << (D_L14_002EE128[i].c.bit & 31))) || func_L01_0041A4F0();
            break;
        case 1: {
            s32 k;
            D_L14_002EE128[i].flag = 0;
            for (k = 0; D_L14_002EE128[i].c.list[k] != 0; k++)
                D_L14_002EE128[i].flag = D_L14_002EE128[i].flag || (D_00142BA0[D_L14_002EE128[i].c.list[k] >> 2] & (1 << (D_L14_002EE128[i].c.list[k] & 31))) || func_L01_0041A4F0();
            break;
        }
        case 2:
            D_L14_002EE128[i].flag = (D_00142BA0[D_L14_002EE128[i].c.bit >> 2] & (1 << (D_L14_002EE128[i].c.bit & 31))) || func_L01_0041A4F0();
            /* As in func_L11_00472AD8: the two wraps give gcse's `i + 1` temporary 12 references, so it outranks the inner loop's flag temporary. */
            do { do { goto next; } while (0); } while (0);
        case 3:
        case 4:
        default:
            D_L14_002EE128[i].flag = D_00142693[0] || func_L01_0041A4F0();
        }
    next:
        i++;
    }
}
/* localdecomp:end func_L14_00487620 */
