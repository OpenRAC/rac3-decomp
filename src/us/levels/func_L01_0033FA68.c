#include "common.h"

/* localdecomp:start func_L01_0033FA68 */
extern s16 D_L01_001E1950[];
extern s16 D_L01_001E1960[];
extern s16 D_L01_001E1968[];
extern s32 D_L01_001E1970[];
extern s32 D_L01_001E1974[];
extern f32 D_L01_001E1978;
extern s32 D_L01_001DD198;
extern s32 D_L01_001DD19C;

/* Resets a small global table: sets four entries each of two s16 arrays to 2 and a third to 1,
 * copies two globals into a pair of s32 slots, and sets a float global to 1.0. */
void func_L01_0033FA68(void) {
    s32 index;
    s32 two = 2;
    s32 one = 1;
    s16 *third = D_L01_001E1968;
    s16 *second = D_L01_001E1960;
    s16 *first = D_L01_001E1950;
    for (index = 3; index >= 0; index--) {
        *first++ = two;
        *second++ = two;
        *third++ = one;
    }
    D_L01_001E1970[0] = D_L01_001DD198;
    D_L01_001E1974[0] = D_L01_001DD19C;
    D_L01_001E1978 = 1.0f;
}
/* localdecomp:end func_L01_0033FA68 */
