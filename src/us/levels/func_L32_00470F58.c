#include "common.h"

/* localdecomp:start func_L32_00470F58 */
typedef struct { s32 f0; s32 p4; s32 p8; union { u32 bit; u32 *list; } c; s32 mode; u8 flag; u8 pad[3]; } E_471F18;
extern E_471F18 D_L32_002ECEE8[];
extern u32 D_00142BA0[];
extern u8 D_00142693[];
extern s32 D_001D9388_sda;
__asm__(".extern D_001D9388_sda, 4");

void func_L32_00470F58(void) {
    s32 i = 0;
    s32 n;
    while (D_L32_002ECEE8[i].f0 != 0) {
        switch (D_L32_002ECEE8[i].mode) {
        case 1: {
            s32 k;
            D_L32_002ECEE8[i].flag = 1;
            n = i + 1;
            for (k = 0; D_L32_002ECEE8[i].c.list[k] != 0; k++) {
                u8 v = 0;
                if ((D_L32_002ECEE8[i].flag && (D_00142BA0[D_L32_002ECEE8[i].c.list[k] >> 2] & (1 << (D_L32_002ECEE8[i].c.list[k] & 31)))) || D_001D9388_sda) v = 1;
                D_L32_002ECEE8[i].flag = v;
            }
            break;
        }
        case 0:
        case 2: {
            E_471F18 *e = &D_L32_002ECEE8[i];
            u8 v = 0;
            if ((D_00142BA0[D_L32_002ECEE8[i].c.bit >> 2] & (1 << (D_L32_002ECEE8[i].c.bit & 31))) || D_001D9388_sda) v = 1;
            e->flag = v;
            n = i + 1;
            break;
        }
        case 3: {
            E_471F18 *e = &D_L32_002ECEE8[i];
            u8 v = 0;
            if (D_00142693[0] || D_001D9388_sda) v = 1;
            e->flag = v;
            n = i + 1;
            break;
        }
        case 4:
        default:
            D_L32_002ECEE8[i].flag = 1;
            n = i + 1;
            break;
        }
        i = n;
    }
}
/* localdecomp:end func_L32_00470F58 */
