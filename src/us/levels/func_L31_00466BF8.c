#include "common.h"

/* localdecomp:start func_L31_00466BF8 */
typedef struct { s32 f0; s32 p4; s32 p8; union { u32 bit; u32 *list; } c; s32 mode; u8 flag; u8 pad[3]; } E_47C860;
extern E_47C860 D_L31_002EC2F8[];
extern u32 D_00142BA0[];
extern u8 D_00142693[];
extern s32 func_L01_00417EA0();

void func_L31_00466BF8(void) {
    s32 i = 0;
    s32 n;
    while (D_L31_002EC2F8[i].f0 != 0) {
        switch (D_L31_002EC2F8[i].mode) {
        case 0: {
            E_47C860 *e = &D_L31_002EC2F8[i];
            u8 v = 0;
            if ((D_00142BA0[D_L31_002EC2F8[i].c.bit >> 2] & (1 << (D_L31_002EC2F8[i].c.bit & 31))) || func_L01_00417EA0()) v = 1;
            e->flag = v;
            n = i + 1;
            break;
        }
        case 1: {
            s32 k;
            D_L31_002EC2F8[i].flag = 0;
            n = i + 1;
            for (k = 0; D_L31_002EC2F8[i].c.list[k] != 0; k++) {
                u8 v = 0;
                if (D_L31_002EC2F8[i].flag || (D_00142BA0[D_L31_002EC2F8[i].c.list[k] >> 2] & (1 << (D_L31_002EC2F8[i].c.list[k] & 31))) || func_L01_00417EA0()) v = 1;
                D_L31_002EC2F8[i].flag = v;
            }
            break;
        }
        case 2: {
            E_47C860 *e = &D_L31_002EC2F8[i];
            u8 v = 0;
            if ((D_00142BA0[D_L31_002EC2F8[i].c.bit >> 2] & (1 << (D_L31_002EC2F8[i].c.bit & 31))) || func_L01_00417EA0()) v = 1;
            e->flag = v;
            do { n = i + 1; } while (0);
            break;
        }
        case 3:
        case 4:
        default: {
            E_47C860 *e = &D_L31_002EC2F8[i];
            u8 v = 0;
            if (D_00142693[0] || func_L01_00417EA0()) v = 1;
            e->flag = v;
            do { n = i + 1; } while (0);
            break;
        }
        }
        i = n;
    }
}
/* localdecomp:end func_L31_00466BF8 */
