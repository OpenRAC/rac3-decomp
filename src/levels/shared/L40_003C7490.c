#include "common.h"

/* localdecomp:start func_L40_003C7490 */
extern s32 D_L40_00264E00[];
extern void func_L02_00310428(u8 *);
extern void func_L02_00310838();
extern void func_L01_004048D0(void *, u8 *);

void func_L40_003C7490(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 104);
    if (a0[32] == 0) {
        func_L02_00310428(a0);
    }
    if (D_L40_00264E00[0] == *(s32 *)(v + 80)) {
        func_L01_004048D0(func_L02_00310838, a0);
    }
}
/* localdecomp:end func_L40_003C7490 */
