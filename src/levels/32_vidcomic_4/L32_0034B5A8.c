#include "common.h"

/* localdecomp:start func_L32_0034B5A8 */
extern s32 D_L32_001DF9C0 __attribute__((section(".data")));
extern s32 D_L32_001E1960[4];
extern s32 D_L32_001E1970[4];

void func_L32_0034B5A8(s32 id) {
    s32 i;

    for (i = 0; i < 4; i++) {
        if (D_L32_001E1970[i] < D_L32_001DF9C0) {
            D_L32_001E1960[i] = 0;
        }
    }
    for (i = 0; i < 4; i++) {
        if (D_L32_001E1960[i] == 0) {
            D_L32_001E1960[i] = id;
            D_L32_001E1970[i] = D_L32_001DF9C0;
            return;
        }
    }
}
/* localdecomp:end func_L32_0034B5A8 */
