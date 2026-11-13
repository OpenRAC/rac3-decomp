#include "common.h"

/* localdecomp:start func_L24_00482FE8 */
typedef struct { s32 f0; s32 p4; s32 p8; union { u32 bit; u32 *list; } c; s32 mode; u8 flag; u8 pad[3]; } E_482FE8;
extern E_482FE8 D_L24_002EA658[];
extern u32 D_00142BA0[];
extern u8 D_00142693[];
extern s32 D_001D9358_sda;
__asm__(".extern D_001D9358_sda, 4");

void func_L24_00482FE8(void) {
    s32 i = 0;
    s32 n;
    while (D_L24_002EA658[i].f0 != 0) {
        switch (D_L24_002EA658[i].mode) {
        case 1: {
            s32 k;
            D_L24_002EA658[i].flag = 1;
            n = i + 1;
            for (k = 0; D_L24_002EA658[i].c.list[k] != 0; k++) {
                u8 v = 0;
                if ((D_L24_002EA658[i].flag && (D_00142BA0[D_L24_002EA658[i].c.list[k] >> 2] & (1 << (D_L24_002EA658[i].c.list[k] & 31)))) || D_001D9358_sda) v = 1;
                D_L24_002EA658[i].flag = v;
            }
            break;
        }
        case 0:
        case 2: {
            E_482FE8 *e = &D_L24_002EA658[i];
            u8 v = 0;
            if ((D_00142BA0[D_L24_002EA658[i].c.bit >> 2] & (1 << (D_L24_002EA658[i].c.bit & 31))) || D_001D9358_sda) v = 1;
            e->flag = v;
            n = i + 1;
            break;
        }
        case 3: {
            E_482FE8 *e = &D_L24_002EA658[i];
            u8 v = 0;
            if (D_00142693[0] || D_001D9358_sda) v = 1;
            e->flag = v;
            n = i + 1;
            break;
        }
        case 4:
        default:
            D_L24_002EA658[i].flag = 1;
            n = i + 1;
            break;
        }
        i = n;
    }
}
/* localdecomp:end func_L24_00482FE8 */
