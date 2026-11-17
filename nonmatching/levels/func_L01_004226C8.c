#include "common.h"
/* localdecomp:start func_L01_004226C8 */
extern u16 D_001D54D8[32] __attribute__((section(".sdata")));
extern u16 D_001D5516;
s32 func_L01_004226C8(void) {
    extern s32 func_L01_00419CC0(s32);
    s32 i, j, n, e;
    s32 ready = 1;
    u16 *p = D_001D54D8;
    for (i = 31; i >= 0; i--, p++) {
        if (*p != 0xFFFF) {
            s32 id = *p & 0x3FFF;
            if (!func_L01_00419CC0(id) || id == 0) {
                *p = 0xFFFF;
                ready = 0;
            }
        }
    }
    i = 0;
    e = 0xFFFF;
    while (i < 32) {
        n = i + 1;
        if (D_001D54D8[i] == 0xFFFF) {
            for (j = n; j < 32; j++) {
                u16 v = D_001D54D8[j];
                if (v != 0xFFFF) ready = 1;
                D_001D54D8[j-1] = v;
            }
            D_001D5516 = e;
        }
        i = n;
    }
    return ready;
}
/* localdecomp:end func_L01_004226C8 */
