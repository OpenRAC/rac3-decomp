#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003AF7C0 */
/* forwards its ten arguments to func_003AC590 with the object at D_001D5C78 + 0x1FCA8 in front.
   Retail saves $s0, $s1 and $ra with sq (config/boot_elf/sq_ra_funcs.txt), which needs a file
   without -fopt-stack. */
extern s32 D_001D5C78;
__asm__(".extern D_001D5C78, 16");
extern void func_003AC590();
void func_003AF7C0(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, s32 a8, u8 a9) {
    if (D_001D5C78 != 0) {
        func_003AC590(D_001D5C78 + 0x1FCA8, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9);
    }
}
/* localdecomp:end func_003AF7C0 */
