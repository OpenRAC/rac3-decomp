#include "common.h"

/* localdecomp:start func_L03_0032ED88 */
extern u8 *D_L03_001DF99C;
extern void func_L03_00399CE0(u8 *);

void func_L03_0032ED88(u8 *self) {
    s32 *p = (s32 *)(*(u8 **)(self + 0x68) + 0x60);
    s32 i;

    for (i = 7; i >= 0; i--) {
        func_L03_00399CE0(D_L03_001DF99C + (*p++ << 8));
    }
}
/* localdecomp:end func_L03_0032ED88 */
