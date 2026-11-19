#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_00392670(void);
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 38E518.c's earlier functions */
extern s32 D_001D4CF8[];

LINKER_REMNANT("asm/boot_elf/remnants", func_00392668);

/* localdecomp:start func_00392670 */
extern void func_12C4B0(s32);
extern s32 D_001D4CF8[];

void func_00392670(void) {
    func_12C4B0(D_001D4CF8[0]);
}
/* localdecomp:end func_00392670 */
