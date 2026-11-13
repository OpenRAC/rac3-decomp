#include "common.h"

/* localdecomp:start func_L03_0032ED88 */
extern void func_L03_00399CE0(void *);
extern u8 *D_L03_001DF99C;

void func_L03_0032ED88(u8 *a0) {
    s32 *p = (s32 *)(*(u8 **)(a0 + 0x68) + 0x60);
    s32 i;
    for (i = 0; i < 8; i++) {
        func_L03_00399CE0(D_L03_001DF99C + (p[i] << 8));
    }
}
/* localdecomp:end func_L03_0032ED88 */
