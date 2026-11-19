#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations of 392F68.c's earlier functions */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);

extern s32 D_00227600[];
extern s32 D_001D9E98;
extern s32 D_001D9E9C;
/* localdecomp:start func_00393290 */
extern s32 D_001D9E98_00393290[2];
__asm__(".extern D_001D9E98_00393290, 16");
void func_00393290(void) {
    s32 a = D_00227600[0];
    D_001D9E98_00393290[0] = a;
    D_001D9E98_00393290[1] = a + 0x64000;
}
/* localdecomp:end func_00393290 */
