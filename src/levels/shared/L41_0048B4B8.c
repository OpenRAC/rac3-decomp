#include "common.h"

/* localdecomp:start func_L41_0048B4B8 */
extern s32 *D_00241120;
extern u8 *D_L41_002490F4;
extern u8 *D_L41_00249148[];
extern s32 func_L40_00489900(void *, s32);
extern s32 func_L03_0043C438(void *, s32);

void func_L41_0048B4B8(void *a0, s32 a1) {
    s32 idx = func_L40_00489900(a0, a1);
    s32 j;
    s32 k;
    if (idx == -1) {
        idx = func_L03_0043C438(a0, a1);
    }
    if (idx >= 0) {
        D_L41_002490F4[(idx << 5) + 0x1E] &= 0xFB;
    }
    if (*D_00241120 >= 2) {
        for (j = 1; j < *D_00241120; j++) {
            D_L41_00249148[j][(idx << 5) + 0x1E] = D_L41_002490F4[(idx << 5) + 0x1E];
        }
    }
    {
    s32 *cnt = D_00241120;
    *(s16 *)&D_L41_002490F4[(idx << 5) + 0x10] = 0x7F80;
    if (*cnt >= 2) {
        for (k = 1; k < *cnt; k++) {
            *(s16 *)&D_L41_00249148[k][(idx << 5) + 0x10] = 0x7F80;
        }
    }
    }
}
/* localdecomp:end func_L41_0048B4B8 */
