#include "common.h"

/* NTSC-U counterpart of func_L11_004719A8 (src/levels/11_obani_moons/L11_004719A8.c) */
/* localdecomp:start func_L11_0046E008 */
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    u32 *fC;
    s32 f10;
    u8 f14;
} E_4719A8;
extern E_4719A8 D_L11_002EEDA8[];
extern s32 D_00142BA0[];
extern u8 D_00142693[];
extern s32 func_L01_00417EA0(void);

/* An inline helper, as retail keeps the mask and the and: written in one expression,
 * gcc folds the test into a shift (srav/andi). */
static __inline__ s32 bit_4719A8(u32 b)
{
    return D_00142BA0[b >> 2] & (1 << (b & 0x1F));
}

void func_L11_0046E008(void)
{
    s32 i;
    s32 j;
    s32 n;

    i = 0;
    while (D_L11_002EEDA8[i].f0 != 0) {
        switch (D_L11_002EEDA8[i].f10) {
        case 0:
            D_L11_002EEDA8[i].f14 = func_L01_00417EA0() || bit_4719A8((u32)D_L11_002EEDA8[i].fC);
            n = i + 1;
            break;
        case 1:
            n = i + 1;
            D_L11_002EEDA8[i].f14 = 1;
            for (j = 0; D_L11_002EEDA8[i].fC[j] != 0; j++) {
                D_L11_002EEDA8[i].f14 = func_L01_00417EA0() || (D_L11_002EEDA8[i].f14 != 0 && bit_4719A8(D_L11_002EEDA8[i].fC[j]));
            }
            break;
        case 2:
            n = i + 1;
            D_L11_002EEDA8[i].f14 = bit_4719A8((u32)D_L11_002EEDA8[i].fC) != 0;
            break;
        case 3:
            n = i + 1;
            D_L11_002EEDA8[i].f14 = D_00142693[0] != 0;
            D_L11_002EEDA8[i].f14 = func_L01_00417EA0();
            break;
        case 4:
        default:
            if (D_L11_002EEDA8[i].f0 == 0x1C3) {
                n = i + 1;
                D_L11_002EEDA8[i].f14 = 1;
            } else {
                n = i + 1;
                D_L11_002EEDA8[i].f14 = D_00142693[0] != 0;
                D_L11_002EEDA8[i].f14 = func_L01_00417EA0();
            }
            break;
        }
        i = n;
    }
}
/* localdecomp:end func_L11_0046E008 */
