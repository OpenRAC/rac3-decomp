#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* localdecomp:start func_003AA060 */
extern u8 D_001D8064;
void func_003AA060(u8 a) { D_001D8064 = a; }
/* localdecomp:end func_003AA060 */

/* localdecomp:start func_003AA068 */
extern u8 D_001D8064;
u8 func_003AA068(void) {
    return D_001D8064;
}
/* localdecomp:end func_003AA068 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003AA070);
