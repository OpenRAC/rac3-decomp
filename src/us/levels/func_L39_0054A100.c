#include "common.h"

/* NTSC-U counterpart of func_L39_0054AA20 (src/levels/shared/L39_0054A250.c) */
/* localdecomp:start func_L39_0054A100 */
typedef struct {
    u8 pad0[8];
    s32 w8;
    u8 pad0C[0x128 - 0xC];
    s32 w128;
} S_1A5CD0_0054AA20;

extern S_1A5CD0_0054AA20 D_001A5E50_0054A100;
extern s32 D_L39_0024B148_0054A100;
__asm__(".extern D_L39_0024B148_0054A100, 4");
extern s32 D_L39_003BDE20[][24];

s32 func_L39_0054A100(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 24; i++) {
        if (D_L39_003BDE20[D_001A5E50_0054A100.w8][i] == 0) {
            for (j = 0; j < 8; j++) {
                if ((&D_L39_0024B148_0054A100)[j * 2] == i && D_001A5E50_0054A100.w128 - 2000 < (&D_L39_0024B148_0054A100)[j * 2 + 1]) {
                    break;
                }
                if ((&D_L39_0024B148_0054A100)[j * 2] == i) {
                    (&D_L39_0024B148_0054A100)[j * 2] = -1;
                }
            }
            if (j < 8) {
                continue;
            }
            for (j = 0; j < 8; j++) {
                if ((&D_L39_0024B148_0054A100)[j * 2] == -1) {
                    (&D_L39_0024B148_0054A100)[j * 2] = i;
                    (&D_L39_0024B148_0054A100)[j * 2 + 1] = D_001A5E50_0054A100.w128;
                    break;
                }
            }
            return i;
        }
    }
    return -1;
}
/* localdecomp:end func_L39_0054A100 */
