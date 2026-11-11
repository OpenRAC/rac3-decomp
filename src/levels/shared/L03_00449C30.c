#include "common.h"

/* localdecomp:start func_L03_00449C30 */
extern s32 D_L01_0021F6C0[];
extern s32 func_L03_00449C80(void *a0, s32 a1);
s32 func_L03_00449C30(void *a0, s32 a1) {
    s32 v;
    if (a1 == -1) return 0;
    v = D_L01_0021F6C0[a1];
    if (v == 0) return 0;
    return func_L03_00449C80(a0, v);
}
/* localdecomp:end func_L03_00449C30 */
