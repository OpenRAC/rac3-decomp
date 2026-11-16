#include "common.h"

/* localdecomp:start func_L03_003E0F30 */
extern s32 D_L03_001DF180[2];
extern s32 D_L03_001DF140[2];

void func_L03_003E0F30(s32 a0, s32 a1) {
    s32 n = D_L03_001DF180[a0];
    s32 i;
    if (n >= 16) {
        return;
    }
    for (i = 0; i < n; i++) {
        if (a1 == ((s32 (*)[16])D_L03_001DF140)[a0][i]) {
            return;
        }
    }
    *(s32 *)((u8 *)D_L03_001DF140 + (a0 * 64 + D_L03_001DF180[a0] * 4)) = a1;
    D_L03_001DF180[a0]++;
}
/* localdecomp:end func_L03_003E0F30 */
