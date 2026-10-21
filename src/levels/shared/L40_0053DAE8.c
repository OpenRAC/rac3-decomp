#include "common.h"

INCLUDE_ASM("asm/levels", func_L40_0053DAE8);

/* localdecomp:start func_L40_0053DC18 */
typedef struct { s32 id; s32 b; s32 c; } S_0053B368;
extern S_0053B368 D_L40_003478D0[];

s32 func_L40_0053DC18(s32 id) {
    s32 i;
    for (i = 0; i < 40; i++) {
        if (D_L40_003478D0[i].id == id) {
            D_L40_003478D0[i].id = 0;
            return 1;
        }
    }
    return -1;
}
/* localdecomp:end func_L40_0053DC18 */
