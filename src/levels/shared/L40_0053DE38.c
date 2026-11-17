#include "common.h"

INCLUDE_ASM("asm/levels", func_L40_0053DE38);

/* localdecomp:start func_L40_0053E000 */
extern u16 *D_L40_0028EA20[];
extern s32 D_L40_00248498;
extern u8 *D_L40_0024845C;
extern f32 func_L01_0040E548(void *, void *);
extern s32 func_L39_0061D780(void *);

s32 func_L40_0053E000(f32 radius, s32 a0, u8 *a1, u8 a2) {
    u16 *p;
    u8 *o;
    u8 *best;
    f32 bestd;
    f32 d;
    u32 k;

    best = 0;
    bestd = 99999.0f;
    p = D_L40_0028EA20[a2];
    if (a2 != 0xFF && a2 <= D_L40_00248498 && p != 0) {
        do {
            o = D_L40_0024845C + ((*p & 0x7FFF) << 8);
            if (o == 0) break;
            if (*(s16 *)(o + 0xAA) == 0x1A63) {
                k = (u8)(o[0x20] - 2) < 4;
            } else {
                k = (u8)(o[0x20] - 2) < 3;
            }
            if (k) {
                d = func_L01_0040E548(a1 + 0x10, o + 0x10);
                if (d < bestd) {
                    bestd = d;
                    best = o;
                }
            }
            p++;
            if (a2 == 0xFF || a2 > D_L40_00248498 || p == 0) break;
        } while ((s16)p[-1] >= 0 || p == D_L40_0028EA20[a2]);
    }
    if (best != 0) {
        if (!(radius * 0.75f < bestd)) {
            return func_L39_0061D780(best);
        }
    }
    return -1;
}
/* localdecomp:end func_L40_0053E000 */

INCLUDE_ASM("asm/levels", func_L40_0053E1A8);

INCLUDE_ASM("asm/levels", func_L40_0053E760);
