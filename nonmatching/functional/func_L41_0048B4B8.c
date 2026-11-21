/* functional: high. 57 instructions differ (scheduling/loop shape). */
#include "common.h"
/* localdecomp:start func_L41_0048B4B8 */
extern s32 *D_00241120;
extern u8 *D_L41_002490F4;
extern u8 *D_L41_00249148[];
extern s32 func_L40_00489900(void *, s32);
extern s32 func_L03_0043C438(void *, s32);

void func_L41_0048B4B8(void *a0, s32 a1) {
    s32 idx = func_L40_00489900(a0, a1);
    s32 off;
    s32 j;
    if (idx == -1) {
        idx = func_L03_0043C438(a0, a1);
    }
    off = idx << 5;
    if (idx >= 0) {
        D_L41_002490F4[off + 0x1E] &= 0xFB;
    }
    if (*D_00241120 >= 2) {
        for (j = 1; j < *D_00241120; j++) {
            u8 *src = D_L41_002490F4 + off;
            (D_L41_00249148[j] + off)[0x1E] = src[0x1E];
        }
    }
    *(s16 *)(D_L41_002490F4 + off + 0x10) = 0x7F80;
    if (*D_00241120 >= 2) {
        for (j = 1; j < *D_00241120; j++) {
            *(s16 *)(D_L41_00249148[j] + off + 0x10) = 0x7F80;
        }
    }
}
/* localdecomp:end func_L41_0048B4B8 */
