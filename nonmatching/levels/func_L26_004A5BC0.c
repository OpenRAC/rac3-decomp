/* near miss (level 26: 28 diff, register allocation of i) */
#include "common.h"

/* localdecomp:start func_L26_004A5BC0 */
typedef struct { s32 f0; s32 p4; s32 p8; union { u32 bit; u32 *list; } c; s32 mode; u8 flag; u8 pad[3]; } E_4A5BC0;
extern E_4A5BC0 D_L26_002EC1A8[];
extern u32 D_00142BA0[];
extern u8 D_00142693[];
extern s32 func_L01_0041A4F0(void);

void func_L26_004A5BC0(void) {
    s32 i = 0;
    s32 n;
    while (D_L26_002EC1A8[i].f0 != 0) {
        switch (D_L26_002EC1A8[i].mode) {
        case 0: {
            E_4A5BC0 *e = &D_L26_002EC1A8[i];
            u8 v = 0;
            if ((D_00142BA0[D_L26_002EC1A8[i].c.bit >> 2] & (1 << (D_L26_002EC1A8[i].c.bit & 31))) || func_L01_0041A4F0()) v = 1;
            e->flag = v;
            n = i + 1;
            break;
        }
        case 1: {
            s32 k;
            D_L26_002EC1A8[i].flag = 0;
            n = i + 1;
            for (k = 0; D_L26_002EC1A8[i].c.list[k] != 0; k++) {
                u8 v = 0;
                if (D_L26_002EC1A8[i].flag || (D_00142BA0[D_L26_002EC1A8[i].c.list[k] >> 2] & (1 << (D_L26_002EC1A8[i].c.list[k] & 31))) || func_L01_0041A4F0()) v = 1;
                D_L26_002EC1A8[i].flag = v;
            }
            break;
        }
        case 2: {
            E_4A5BC0 *e = &D_L26_002EC1A8[i];
            u8 v = 0;
            if ((D_00142BA0[D_L26_002EC1A8[i].c.bit >> 2] & (1 << (D_L26_002EC1A8[i].c.bit & 31))) || func_L01_0041A4F0()) v = 1;
            e->flag = v;
            n = i + 1;
            break;
        }
        case 3:
        case 4:
        default: {
            E_4A5BC0 *e = &D_L26_002EC1A8[i];
            u8 v = 0;
            if (D_00142693[0] || func_L01_0041A4F0()) v = 1;
            e->flag = v;
            n = i + 1;
            break;
        }
        }
        i = n;
    }
}
/* localdecomp:end func_L26_004A5BC0 */
