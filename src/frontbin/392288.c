#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_00392290(void);
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_0038CC88_00391678(void *, void *, s32) __asm__("func_0038CC88");
/* --- end of declarations from other files --- */

LINKER_REMNANT("asm/remnants", func_00392288);

/* localdecomp:start func_00392290 */
extern void func_12C4B0(s32);
extern s32 D_001D4CF8[];

void func_00392290(void) {
    func_12C4B0(D_001D4CF8[0]);
}
/* localdecomp:end func_00392290 */
