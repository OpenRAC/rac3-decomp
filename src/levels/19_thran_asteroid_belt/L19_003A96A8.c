#include "common.h"

typedef struct {
    u8 pad0[68];
    s16 count;
    u8 pad46[346];
    u8 *entries[1];
} G_003A96A8;

/* localdecomp:start func_L19_003A96A8 */
extern s32 D_L19_001D66D4;
extern u8 D_001D5471;
extern G_003A96A8 D_L19_001E6440;
extern u8 D_L19_001E0BA0;
extern u8 D_L19_001E0BA1;
extern f32 D_L19_001E0BC0;
extern f32 D_L19_001E0BC4;
extern f32 D_L19_001E0BC8;
extern void func_L01_0043A430(u8 *m, s32 arg, u8 *e);

void func_L19_003A96A8(u8 *arg) {
    u8 *elem;
    s32 i;

    if (D_L19_001D66D4 == 2) {
        if (D_001D5471 != 0) {
            for (i = 0; i < D_L19_001E6440.count; i++) {
                elem = D_L19_001E6440.entries[i];
                if (*(s16 *)(elem + 0xAA) == *(s16 *)(arg + 0xAA)) {
                    if (D_L19_001E0BA1 == 0) {
                        func_L01_0043A430(elem, 1, &D_L19_001E0BA0);
                        D_L19_001E0BC0 = 2.75f;
                        D_L19_001E0BC4 = 2.75f;
                        D_L19_001E0BC8 = 2.75f;
                    }
                }
            }
        }
    }
}
/* localdecomp:end func_L19_003A96A8 */

INCLUDE_ASM("asm/levels", func_L19_003A9788);
