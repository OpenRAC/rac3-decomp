#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_004DE908);

/* localdecomp:start func_L39_004DE918 */
s32 func_L39_004DE918(void *arg0) {
    s32 var_v0;

    var_v0 = *(s32 *)((u8 *)arg0 + 0x80);
    if (var_v0 == 0) {
        var_v0 = *(s32 *)((u8 *)((*(void **)arg0)) + 8);
    }
    return var_v0;
}
/* localdecomp:end func_L39_004DE918 */

/* localdecomp:start func_L39_004DE938 */
/* from rac4-decomp's func_L00_0051A738 */
long func_L39_004DE938(u8 *object) {
    return *(long *)(object + 0x88);
}
/* localdecomp:end func_L39_004DE938 */

INCLUDE_ASM("asm/levels", func_L39_004DE940);

INCLUDE_ASM("asm/levels", func_L39_004DE9B8);
