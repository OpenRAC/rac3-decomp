/* near miss (level 11, Obani Moons): 13 differences: the sibling of func_L11_00473BE0 (same table walk, with func_L01_0041A4F0() where that one reads D_L11_001D9358); every block and the jump table are retail's, but in case 1 retail increments the index in place (addiu $s2, $s2, 1) before the inner loop and keeps the inner index in $s4, while the C computes i + 1 into $s4 and copies it back (the level-2 'in-place i++' class), which renames $s2-$s4 in that case. Tried a for loop with one i++ (28), an i++ per case (13), an entry pointer, i++ before the inner loop, e = &D[i++] (112-118) */
#include "common.h"

/* localdecomp:start func_L11_00472AD8 */
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    u32 *fC;
    s32 f10;
    u8 f14;
} E_472AD8;
extern E_472AD8 D_L11_002EF268[];
extern s32 D_00142BA0[];
extern u8 D_00142693[];
extern s32 func_L01_0041A4F0(void);

/* An inline helper, as retail keeps the mask and the and: written in one expression,
 * gcc folds the test into a shift (srav/andi). */
static __inline__ s32 bit_472AD8(u32 b)
{
    return D_00142BA0[b >> 2] & (1 << (b & 0x1F));
}

void func_L11_00472AD8(void)
{
    s32 i;
    s32 j;

    i = 0;
    while (D_L11_002EF268[i].f0 != 0) {
        switch (D_L11_002EF268[i].f10) {
        case 0:
            D_L11_002EF268[i].f14 = bit_472AD8((u32)D_L11_002EF268[i].fC) || func_L01_0041A4F0();
            i++;
            break;
        case 1:
            D_L11_002EF268[i].f14 = 0;
            for (j = 0; D_L11_002EF268[i].fC[j] != 0; j++) {
                D_L11_002EF268[i].f14 = D_L11_002EF268[i].f14 != 0 || bit_472AD8(D_L11_002EF268[i].fC[j]) || func_L01_0041A4F0();
            }
            i++;
            break;
        case 2:
            D_L11_002EF268[i].f14 = bit_472AD8((u32)D_L11_002EF268[i].fC) || func_L01_0041A4F0();
            i++;
            break;
        case 3:
        case 4:
        default:
            D_L11_002EF268[i].f14 = D_00142693[0] != 0 || func_L01_0041A4F0();
            i++;
            break;
        }
    }
}
/* localdecomp:end func_L11_00472AD8 */
