#include "common.h"

/* localdecomp:start func_L19_003AFA68 */
s32 func_L19_003AFA68(void *arg0, void *arg1) {
    s32 var_v1;

    var_v1 = 0;
    if ((*(u8 *)((u8 *)arg0 + 0xBC)) == 0) {
        var_v1 = (*(s32 *)((u8 *)arg1 + 0x38C)) == 0;
    }
    return var_v1;
}
/* localdecomp:end func_L19_003AFA68 */

INCLUDE_ASM("asm/levels", func_L19_003AFA88);
