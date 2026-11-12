/* Near miss (level 4, Marcadia): 28 differences with the default assembler; remaining counter copies and inner boolean register. */
#include "common.h"

/* localdecomp:start func_L04_004AC5A0 */
typedef struct { s32 f0; s32 p4; s32 p8; union { u32 bit; u32 *list; } c; s32 mode; u8 flag; u8 pad[3]; } E_4AC5A0;
extern E_4AC5A0 D_L04_002ECBE8[];
__asm__(".extern D_L04_002ECBE8, 16");
extern u32 D_00142BA0[];
__asm__(".extern D_00142BA0, 16");
extern u8 D_00142693[];
__asm__(".extern D_00142693, 16");
int func_L01_0041A4F0(void);

void func_L04_004AC5A0(void) {
    s32 i = 0;
    while (D_L04_002ECBE8[i].f0 != 0) {
        switch (D_L04_002ECBE8[i].mode) {
        case 0:
            D_L04_002ECBE8[i].flag = (D_00142BA0[D_L04_002ECBE8[i].c.bit >> 2] & (1 << (D_L04_002ECBE8[i].c.bit & 31))) != 0 || func_L01_0041A4F0();
            break;
        case 1: {
            s32 k;

            D_L04_002ECBE8[i].flag = 0;
            for (k = 0; D_L04_002ECBE8[i].c.list[k] != 0; k++) {
                D_L04_002ECBE8[i].flag = D_L04_002ECBE8[i].flag || (D_00142BA0[D_L04_002ECBE8[i].c.list[k] >> 2] & (1 << (D_L04_002ECBE8[i].c.list[k] & 31))) != 0 || func_L01_0041A4F0();
            }
            break;
        }
        case 2:
            D_L04_002ECBE8[i].flag = (D_00142BA0[D_L04_002ECBE8[i].c.bit >> 2] & (1 << (D_L04_002ECBE8[i].c.bit & 31))) != 0 || func_L01_0041A4F0();
            break;
        case 3:
        case 4:
        default:
            D_L04_002ECBE8[i].flag = D_00142693[0] != 0 || func_L01_0041A4F0();
            break;
        }
        i++;
    }
}
/* localdecomp:end func_L04_004AC5A0 */
