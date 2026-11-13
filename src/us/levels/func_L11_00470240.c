#include "common.h"

/* NTSC-U counterpart of func_L11_00473BE0 (src/levels/11_obani_moons/L11_00473BE0.c) */
/* localdecomp:start func_L11_00470240 */
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    u32 *fC;
    s32 f10;
    u8 f14;
} E_473BE0;
extern E_473BE0 D_L11_002EF628[];
extern s32 D_00142BA0[];
extern u8 D_00142693[];
extern s32 D_L11_001D9388;

/* An inline helper, as retail keeps the mask and the and: written in one expression,
 * gcc folds the test into a shift (srav/andi). */
static __inline__ s32 bit_473BE0(u32 b)
{
    return D_00142BA0[b >> 2] & (1 << (b & 0x1F));
}

void func_L11_00470240(void)
{
    s32 i;
    s32 j;

    for (i = 0; D_L11_002EF628[i].f0 != 0; i++) {
        switch (D_L11_002EF628[i].f10) {
        case 1:
            D_L11_002EF628[i].f14 = 1;
            for (j = 0; D_L11_002EF628[i].fC[j] != 0; j++) {
                D_L11_002EF628[i].f14 = (D_L11_002EF628[i].f14 != 0 && bit_473BE0(D_L11_002EF628[i].fC[j])) || D_L11_001D9388 != 0;
            }
            break;
        case 0:
        case 2:
            D_L11_002EF628[i].f14 = bit_473BE0((u32)D_L11_002EF628[i].fC) || D_L11_001D9388 != 0;
            break;
        case 3:
            D_L11_002EF628[i].f14 = D_00142693[0] != 0 || D_L11_001D9388 != 0;
            break;
        case 4:
        default:
            D_L11_002EF628[i].f14 = 1;
            break;
        }
    }
}
/* localdecomp:end func_L11_00470240 */
