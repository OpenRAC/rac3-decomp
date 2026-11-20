#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* localdecomp:start func_003A9CA8 */
extern u8 D_001D8064;
void func_003A9CA8(u8 a) { D_001D8064 = a; }
/* localdecomp:end func_003A9CA8 */

/* localdecomp:start func_003A9CB0 */
extern u8 D_001D8064;
u8 func_003A9CB0(void) {
    return D_001D8064;
}
/* localdecomp:end func_003A9CB0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003A9CB8);
