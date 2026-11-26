#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_00393670 */
/* the copy of func_00393290 */
extern s32 D_00227600_00393670[] __asm__("D_00227600");
extern s32 D_001D9E98_00393670[2] __asm__("D_001D9E98");
__asm__(".extern D_001D9E98, 16");
void func_00393670(void) {
    s32 a = D_00227600_00393670[0];
    D_001D9E98_00393670[0] = a;
    D_001D9E98_00393670[1] = a + 0x64000;
}
/* localdecomp:end func_00393670 */

extern s32 D_00227600[];
extern s32 D_001D9E98;
extern s32 D_001D9E9C;
