#include "common.h"

/* localdecomp:start func_L34_00472020 */
/* same code as func_L31 (level 31) / func_L02_00474518 */
typedef struct { s32 f0; s32 p4; s32 p8; union { u32 bit; u32 *list; } c; s32 mode; u8 flag; u8 pad[3]; } E_472020;
extern E_472020 D_L34_002ECB98[];
extern u32 D_00142BA0[];
extern u8 D_00142693[];
extern s32 D_001D9358_sda;
__asm__(".extern D_001D9358_sda, 4");

void func_L34_00472020(void) {
    s32 i = 0;
    s32 n;
    while (D_L34_002ECB98[i].f0 != 0) {
        switch (D_L34_002ECB98[i].mode) {
        case 1: {
            s32 k;
            D_L34_002ECB98[i].flag = 1;
            n = i + 1;
            for (k = 0; D_L34_002ECB98[i].c.list[k] != 0; k++) {
                u8 v = 0;
                if ((D_L34_002ECB98[i].flag && (D_00142BA0[D_L34_002ECB98[i].c.list[k] >> 2] & (1 << (D_L34_002ECB98[i].c.list[k] & 31)))) || D_001D9358_sda) v = 1;
                D_L34_002ECB98[i].flag = v;
            }
            break;
        }
        case 0:
        case 2: {
            E_472020 *e = &D_L34_002ECB98[i];
            u8 v = 0;
            if ((D_00142BA0[D_L34_002ECB98[i].c.bit >> 2] & (1 << (D_L34_002ECB98[i].c.bit & 31))) || D_001D9358_sda) v = 1;
            e->flag = v;
            n = i + 1;
            break;
        }
        case 3: {
            E_472020 *e = &D_L34_002ECB98[i];
            u8 v = 0;
            if (D_00142693[0] || D_001D9358_sda) v = 1;
            e->flag = v;
            n = i + 1;
            break;
        }
        case 4:
        default:
            D_L34_002ECB98[i].flag = 1;
            n = i + 1;
            break;
        }
        i = n;
    }
}
/* localdecomp:end func_L34_00472020 */
