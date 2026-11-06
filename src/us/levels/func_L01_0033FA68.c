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
