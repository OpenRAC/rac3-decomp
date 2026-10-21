#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_008010F8(void);
/* --- end of declarations from other files --- */

/* localdecomp:start func_008010F8 */
extern int func_00801080(void);
extern void func_00801090(void);
extern void func_00801138(void);

void func_008010F8(void) {
    if (func_00801080() == 0x2000000) {
        func_00801138();
    } else {
        func_00801090();
    }
}
/* localdecomp:end func_008010F8 */

ASM_FUNC("asm/i5bootn/handwritten", func_00801138);

ASM_FUNC("asm/i5bootn/handwritten", func_00801340);
