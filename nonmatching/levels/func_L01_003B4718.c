/* PAL port (Sonnet b17-p1, 2026-11-18) of the NTSC-U draft of func_L01_003B2F18: PAL names, the 0xFA (50 Hz) limits, and the file's globals
 * (D_L01_001DE630.. are declared by the blocks above it; D_L01_001DFB40 by func_L01_003B42C8's block). 6 words differ with the file's own flags
 * (-mno-split-addresses, default assembler): retail keeps the frame counter's lui/lw result in $v1 and p[4] in $v0, this C the reverse,
 * and loads p[0x10] after the `move $t0` that caches the counter.
 */
#include "common.h"

/* localdecomp:start func_L01_003B4718 */
extern s32 D_L01_001DFB40_003B4718;
extern void func_L01_003B42E8(s32, s32, s32, s32);

static inline s32 Frame(void) {
    return D_L01_001DFB40[0];
}

s32 func_L01_003B4718(void) {
    u8 *p;
    s32 dt;
    s32 x;
    s32 r;

    if (D_L01_001DE630 == 0) {
        if (D_L01_001DE648 != 0) {
            if (D_L01_001DE648 + 1 < D_L01_001DFB40_003B4718) {
                D_L01_001DE638 = 0;
                D_L01_001DE63C = 0;
                D_L01_001DE640 = 0;
                D_L01_001DE644 = 0;
                D_L01_001DE648 = 0;
            } else {
                func_L01_003B42E8(D_L01_001DE638, D_L01_001DE63C, D_L01_001DE640, D_L01_001DE644);
            }
        }
        return 1;
    }
    p = *(u8 **)(D_L01_001DE630 + 0x68);
    { s32 t = Frame(); dt = t - *(s32 *)(p + 4); }
    x = *(s32 *)(p + 0x10);
    if (x == 0 || dt >= 0xFA) {
        r = *(s32 *)(p + 0x14);
        if (r == 0 || *(s32 *)(p + 0x18) >= dt) {
            goto tail;
        }
        dt -= *(s32 *)(p + 0x18);
        x = *(s32 *)(p + 0x1C);
        if (dt % x >= 0xFA) {
            goto tail;
        }
        x = r;
    }
    func_L01_003B42E8(x, 0, 0, 0);
    return 1;
tail:
    if (D_L01_001DE648 != 0) {
        if (D_L01_001DE648 + 1 < Frame()) {
            D_L01_001DE638 = 0;
            D_L01_001DE63C = 0;
            D_L01_001DE640 = 0;
            D_L01_001DE644 = 0;
            D_L01_001DE648 = 0;
        } else {
            func_L01_003B42E8(D_L01_001DE638, D_L01_001DE63C, D_L01_001DE640, D_L01_001DE644);
        }
    }
    return 1;
}
/* localdecomp:end func_L01_003B4718 */
