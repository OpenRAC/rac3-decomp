#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

extern s32 D_00143950[];
extern s32 D_001D5520;
extern void func_12A950(void);
extern void func_12BEE8(s32, s32, s32, s32);
/* localdecomp:start func_00391708 */
void func_00391708(void) {
    func_12A950();
    if (D_00143950[0]) D_001D5520 = 0;
    if (D_001D5520) func_12BEE8(0, 0, 0x50, 1);
    else func_12BEE8(0, 1, D_00143950[0] ? 3 : 2, 0);
}
/* localdecomp:end func_00391708 */
