/* near miss (level 22): 13 diff with --as ps2as; the 0x260 flag-table update family (see func_L28_00464BF0): with i++ in place in each case it is 13 diff; left: case 1 increments i first in retail and keeps the list index in $s4/$s3 where gcc swaps them; plain default flags */
#include "common.h"

/* localdecomp:start func_L22_004A32D0 */
/* localdecomp:start func_L22_004A32D0 */
typedef struct { s32 f0; s32 p4; s32 p8; union { u32 bit; u32 *list; } c; s32 mode; u8 flag; u8 pad[3]; } E_4A32D0;
extern E_4A32D0 D_L22_002EDDC8[];
extern u32 D_00142BA0[];
extern u8 D_00142693[];
extern s32 func_L01_0041A4F0(void);

void func_L22_004A32D0(void) {
    s32 i = 0;
    while (D_L22_002EDDC8[i].f0 != 0) {
        switch (D_L22_002EDDC8[i].mode) {
        case 0: {
            E_4A32D0 *e = &D_L22_002EDDC8[i];
            u8 v = 0;
            if ((D_00142BA0[D_L22_002EDDC8[i].c.bit >> 2] & (1 << (D_L22_002EDDC8[i].c.bit & 31))) || func_L01_0041A4F0()) v = 1;
            e->flag = v;
            i++;
            break;
        }
        case 1: {
            s32 k;
            D_L22_002EDDC8[i].flag = 0;
            for (k = 0; D_L22_002EDDC8[i].c.list[k] != 0; k++) {
                u8 v = 0;
                if (D_L22_002EDDC8[i].flag || (D_00142BA0[D_L22_002EDDC8[i].c.list[k] >> 2] & (1 << (D_L22_002EDDC8[i].c.list[k] & 31))) || func_L01_0041A4F0()) v = 1;
                D_L22_002EDDC8[i].flag = v;
            }
            i++;
            break;
        }
        case 2: {
            E_4A32D0 *e = &D_L22_002EDDC8[i];
            u8 v = 0;
            if ((D_00142BA0[D_L22_002EDDC8[i].c.bit >> 2] & (1 << (D_L22_002EDDC8[i].c.bit & 31))) || func_L01_0041A4F0()) v = 1;
            e->flag = v;
            i++;
            break;
        }
        case 3:
        case 4:
        default: {
            E_4A32D0 *e = &D_L22_002EDDC8[i];
            u8 v = 0;
            if (D_00142693[0] || func_L01_0041A4F0()) v = 1;
            e->flag = v;
            i++;
            break;
        }
        }
    }
}
/* localdecomp:end func_L22_004A32D0 */
/* localdecomp:end func_L22_004A32D0 */
