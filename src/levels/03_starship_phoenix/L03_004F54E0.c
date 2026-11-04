#include "common.h"

typedef struct {
    u8 pad0[0x10];
    s32 x10[8];
} S_004F54E0;

/* localdecomp:start func_L03_004F54E0 */
extern S_004F54E0 D_00142660;
extern s32 D_001D4C40;

void func_L03_004F54E0(s32 id) {
    s32 i;
    s32 j;
    for (i = 0; i < 8; i++) {
        if (D_00142660.x10[i] == id) {
            for (j = i; j < 8; j++) {
                if (j == 7) {
                    D_00142660.x10[7] = 0;
                } else {
                    D_00142660.x10[j] = D_00142660.x10[j + 1];
                }
            }
        }
    }
    if (D_001D4C40 == id) {
        D_001D4C40 = 0;
    }
}
/* localdecomp:end func_L03_004F54E0 */
