#include "common.h"

typedef struct { u8 p0[0x10]; s16 h10; u8 p12[0xC]; u8 b1E; u8 p1F; } E_004897A8;

/* localdecomp:start func_L40_004897A8 */
extern s32 func_L40_00489900(void *, void *);
extern s32 func_L03_0043C438(void *, void *);
__asm__(".extern D_L40_00241120, 16");
extern s32 *D_L40_00241120;
extern E_004897A8 *D_L40_00248EF4;
extern E_004897A8 *D_L40_00248F48[];

void func_L40_004897A8(void *a, void *b) {
    s32 idx;
    s32 i, j;
    s32 *cnt;

    idx = func_L40_00489900(a, b);
    if (idx == -1) {
        idx = func_L03_0043C438(a, b);
    }
    if (idx >= 0) {
        D_L40_00248EF4[idx].b1E |= 4;
        if (*D_L40_00241120 >= 2) {
            for (i = 1; i < *D_L40_00241120; i++) {
                D_L40_00248F48[i][idx].b1E = D_L40_00248EF4[idx].b1E;
            }
        }
        D_L40_00248EF4[idx].h10 = 0x7F80;
        cnt = D_L40_00241120;
        if (*cnt >= 2) {
            for (j = 1; j < *cnt; j++) {
                D_L40_00248F48[j][idx].h10 = 0x7F80;
            }
        }
    }
}
/* localdecomp:end func_L40_004897A8 */
