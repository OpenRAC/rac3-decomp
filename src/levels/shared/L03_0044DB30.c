#include "common.h"

INCLUDE_ASM("asm/levels", func_L03_0044DB30);

/* localdecomp:start func_L03_0044DC40 */
typedef char *va_list_44A4C8;
extern void func_L03_0044DC88(s32, s32, va_list_44A4C8);
void func_L03_0044DC40(s32 a0, s32 a1, ...) {
    va_list_44A4C8 ap;
    ap = (char *)__builtin_next_arg(a1)
         - (__builtin_args_info(2) >= 8 ? 0 : (8 - __builtin_args_info(2)) * 8);
    func_L03_0044DC88(a0, a1, ap);
}
/* localdecomp:end func_L03_0044DC40 */

INCLUDE_ASM("asm/levels", func_L03_0044DC88);

LINKER_REMNANT("asm/levels", func_L03_0044DDC8);
