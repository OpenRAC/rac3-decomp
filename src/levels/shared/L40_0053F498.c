#include "common.h"

/* localdecomp:start func_L40_0053F498 */
typedef struct { u8 pad[49]; u8 b31; u8 pad2[18]; } S_0053CBE8;
extern S_0053CBE8 D_L40_0033F2E0[];

s32 func_L40_0053F498(void) {
    s32 i;
    for (i = 0; i < 50; i++) {
        if (D_L40_0033F2E0[i].b31 == 0) {
            return i;
        }
    }
    return -1;
}
/* localdecomp:end func_L40_0053F498 */
