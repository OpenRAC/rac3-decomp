#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 *func_003B4738();
/* --- end of declarations from other files --- */

/* localdecomp:start func_003B4738 */
extern s32 D_001DA12C;
extern s32 D_001DA120;
extern u8 *D_001DA124;
__asm__(".extern D_001DA124, 16");
extern u8 D_001D88B8[] __attribute__((section(".sdata")));
__asm__(".extern D_001D88B8, 16");

s32 *func_003B4738(void) {
    if (D_001DA12C == 0) {
        D_001DA124 = D_001D88B8;
        D_001DA120 = 1;
        D_001DA12C = 1;
    }
    return &D_001DA120;
}
/* localdecomp:end func_003B4738 */
