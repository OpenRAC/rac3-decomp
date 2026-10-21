#include "common.h"

INCLUDE_ASM("asm/levels", func_L30_0034CE78);

/* localdecomp:start func_L30_0034CF00 */
s32 func_L30_0034CF00(u8 *obj) {
    s32 *p;
    if (!(*(u16 *)(obj + 52) & 0x20)) {
        return 0;
    }
    p = *(s32 **)(obj + 104);
    return *p;
}
/* localdecomp:end func_L30_0034CF00 */

INCLUDE_ASM("asm/levels", func_L30_0034CF28);

LINKER_REMNANT("asm/levels", func_L30_0034D068);

INCLUDE_ASM("asm/levels", func_L30_0034D088);
