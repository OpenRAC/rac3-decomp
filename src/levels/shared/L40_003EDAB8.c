#include "common.h"

/* localdecomp:start func_L40_003EDAB8 */
extern u8 *D_L40_00249450[];

void func_L40_003EDAB8(void) {
    s32 i;
    s32 j;
    for (i = 0; i < 8; i++) {
        u8 *m = D_L40_00249450[i];
        if (m != 0) {
            s32 *v = *(s32 **)(m + 104);
            if (v != 0) {
                for (j = 0; j < v[0]; j++) {
                }
            }
        }
    }
}
/* localdecomp:end func_L40_003EDAB8 */

LINKER_REMNANT("asm/levels", func_L40_003EDB28);
